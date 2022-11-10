// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* library includes */
#include <magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/helper.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../fileinterfaces/i_inputfile.hpp"
#include "../fileinterfaces/i_pingcontainer.hpp"

#include "simradnavigationdatainterface.hpp"
#include "simradping.hpp"
#include "simradpingdatainterface.hpp"
#include "simradpackagecontainer.hpp"

#include "simrad_datagrams.hpp"
#include "simrad_types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {

template<typename t_ifstream>
using SimradPingContainer = fileinterfaces::I_PingContainer<SimradPing<t_ifstream>>;

template<typename t_ifstream>
class FileRaw
    : public fileinterfaces::
          I_InputFile<datagrams::SimradDatagram, t_SimradDatagramIdentifier, SimradPackageContainer<t_ifstream>, t_ifstream>
{
    std::shared_ptr<SimradPingDataInterface<t_ifstream>> _ping_data_interface =
        std::make_shared<SimradPingDataInterface<t_ifstream>>(
            this->_package_container.get_package_infos_all());

    std::shared_ptr<SimradNavigationDataInterface<t_ifstream>> _navigation_interface =
        std::make_shared<SimradNavigationDataInterface<t_ifstream>>(
            this->_input_file_manager->get_file_paths());

    SimradPingContainer<t_ifstream> _ping_container;
    tools::helper::DefaultSharedPointerMap<std::string, SimradPingContainer<t_ifstream>>
        _ping_container_by_channel;

  public:
    std::shared_ptr<std::vector<navigation::NavigationInterpolatorLatLon>>
        _navigation_interpolators =
            std::make_shared<std::vector<navigation::NavigationInterpolatorLatLon>>();

    const std::vector<navigation::NavigationInterpolatorLatLon>& get_navigation_interpolators()
        const
    {
        return *_navigation_interpolators;
    }
    // inherit constructors
    // This does not work, because I_InputFile calls append before the callback functions are
    // overwritten Thus inheriting constructors would lead to calling the callback functions of the
    // base class using fileinterfaces::I_InputFile<datagrams::SimradDatagram, t_SimradDatagramIdentifier,
    // t_ifstream>::
    //     I_InputFile;

    FileRaw(const std::string& file_path, bool show_progress = true)
    {
        this->append_file(file_path, show_progress);
    }
    FileRaw(const std::string& file_path, tools::progressbars::I_ProgressBar& progress_bar)
    {
        this->append_file(file_path, progress_bar);
    }

    FileRaw(const std::vector<std::string>& file_paths, bool show_progress)
    {
        this->append_files(file_paths, show_progress);
    }
    FileRaw(const std::vector<std::string>&     file_paths,
            tools::progressbars::I_ProgressBar& progress_bar)
    {
        this->append_files(file_paths, progress_bar);
    }
    ~FileRaw() = default;

    SimradNavigationDataInterface<t_ifstream> navigation() const { return *_navigation_interface; }

    SimradPingContainer<t_ifstream> pings() const { return _ping_container; }
    SimradPingContainer<t_ifstream> pings(long start, long end, long step) const
    {
        return _ping_container(start, end, step);
    }

    SimradPingContainer<t_ifstream> pings(const std::string& channel_id) const
    {
        return *_ping_container_by_channel.at_const(channel_id);
    }
    SimradPingContainer<t_ifstream> pings(const std::string& channel_id,
                                          long               start,
                                          long               end,
                                          long               step) const
    {
        return _ping_container_by_channel.at_const(channel_id)
            ->
            operator()(start, end, step);
    }
    std::vector<std::string> channel_ids() const
    {
        std::vector<std::string> channel_ids;
        for (const auto& [k, v] : _ping_container_by_channel)
        {
            channel_ids.push_back(k);
        }

        return channel_ids;
    }

   

    navigation::NavigationInterpolatorLatLon process_navigation(bool show_progress = true)
    {
        tools::progressbars::ProgressBarChooser progress_bar(show_progress);
        return process_navigation(progress_bar.get());
    }

    navigation::NavigationInterpolatorLatLon process_navigation(
        tools::progressbars::I_ProgressBar& progress_bar)
    {

        auto sensor_configuration = _packet_buffer.configuration.get_sensor_configuration();

        auto navi = navigation::NavigationInterpolatorLatLon(std::move(sensor_configuration));

        progress_bar.init(
            0.,
            double(_packet_buffer.nme0_packets.size() + _packet_buffer.mru0_packets.size()),
            "scanning navigation data");

        progress_bar.set_postfix("scanning navigation data (NME0) ");
        std::vector<double> lats, lons, gps_times, altitudes;

        for (const auto& nme0 : _packet_buffer.nme0_packets)
        {
            if (nme0.get_sentence_type() == "GGA")
            {
                auto nmea_timestamp = nme0.get_timestamp();
                if (!gps_times.empty())
                    if (!(gps_times.back() < nmea_timestamp))
                        continue;

                auto gga = std::get<navigation::nmea_0183::NMEA_GGA>(nme0.decode());
                auto lat = gga.get_latitude();
                auto lon = gga.get_longitude();
                auto alt = gga.get_altitude();

                if (!std::isfinite(lat) || !std::isfinite(lon) || !std::isfinite(alt))
                    continue;

                lats.push_back(lat);
                lons.push_back(lon);
                gps_times.push_back(nmea_timestamp);
                altitudes.push_back(alt);
            }

            progress_bar.tick();
        }

        progress_bar.set_postfix("scanning navigation data (MRU0) ");
        std::vector<double> headings, pitchs, rolls, heaves, mru0_times;

        for (const auto& mru0 : _packet_buffer.mru0_packets)
        {
            auto mru_timestamp = mru0.get_timestamp();
            if (!mru0_times.empty())
                if (!(mru0_times.back() < mru_timestamp))
                    continue;

            auto heading = mru0.get_heading();
            auto pitch   = mru0.get_pitch();
            auto roll    = mru0.get_roll();
            auto heave   = mru0.get_heave();

            if (!std::isfinite(heading) || !std::isfinite(pitch) || !std::isfinite(roll) ||
                !std::isfinite(heave))
                continue;

            headings.push_back(heading);
            pitchs.push_back(pitch);
            rolls.push_back(roll);
            heaves.push_back(heave);
            mru0_times.push_back(mru_timestamp);

            progress_bar.tick();
        }

        progress_bar.set_postfix("initializing navigation interpolator");
        navi.set_data_attitude(mru0_times, pitchs, rolls);
        navi.set_data_heading(mru0_times, headings);
        navi.set_data_heave(mru0_times, heaves);
        navi.set_data_position(gps_times, lats, lons);
        // TODO: ALtitude / depth?

        progress_bar.close(fmt::format("Processed {} NMEA packages and {} MRU0 packages",
                                       _packet_buffer.nme0_packets.size(),
                                       _packet_buffer.mru0_packets.size()));

        return navi;
    }

  protected:
    struct
    {
        datagrams::xml_datagrams::XML_Configuration configuration;
        std::vector<datagrams::NME0>                nme0_packets;
        std::vector<datagrams::MRU0>                mru0_packets;
        // std::map<std::string, datagrams::xml_datagrams::XML_Parameter_Channel>
        // channel_parameters;
        std::map<std::string, std::shared_ptr<datagrams::xml_datagrams::XML_Parameter_Channel>>
            channel_parameters_per_channel_id;
        std::map<datagrams::xml_datagrams::XML_Parameter_Channel,
                 std::shared_ptr<datagrams::xml_datagrams::XML_Parameter_Channel>>
            channel_parameters;

    } _packet_buffer;

    void callback_scan_new_file_begin([[maybe_unused]] const std::string& file_path,
                                      [[maybe_unused]] size_t             file_paths_cnt) final
    {
        _packet_buffer.nme0_packets.clear();
        _packet_buffer.mru0_packets.clear();
    }
    void callback_scan_new_file_end([[maybe_unused]] const std::string& file_path,
                                    [[maybe_unused]] size_t             file_paths_cnt) final
    {
        if (_navigation_interpolators->size() != file_paths_cnt)
            throw std::runtime_error(
                "Internal error: _navigation_interpolators.size() != file_paths_cnt");

        // TODO: this crashed for empty navigation data!
        _navigation_interpolators->push_back(process_navigation(false));
    }

    fileinterfaces::PackageInfo_ptr<t_SimradDatagramIdentifier, t_ifstream> callback_scan_packet(
        t_ifstream&                   ifs,
        typename t_ifstream::pos_type pos,
        size_t                        file_paths_cnt) final
    {
        auto header = datagrams::SimradDatagram::from_stream(ifs);
        auto type   = header.get_datagram_identifier();

        auto package_info =
            std::make_shared<fileinterfaces::PackageInfo<t_SimradDatagramIdentifier, t_ifstream>>(
                file_paths_cnt,
                pos,
                this->_input_file_manager,
                header.get_timestamp(),
                header.get_datagram_identifier());

        // auto package_info =
        // std::make_shared<fileinterfaces::PackageInfo<t_SimradDatagramIdentifier>>();
        // package_info->file_nr             = file_paths_cnt;
        // package_info->file_pos            = pos;
        // package_info->timestamp           = header.get_timestamp();
        // package_info->datagram_identifier = header.get_datagram_identifier();

        switch (type)
        {
            case t_SimradDatagramIdentifier::NME0: {

                auto datagram = datagrams::NME0::from_stream(ifs, header);

                if (!ifs.good())
                    break;

                _packet_buffer.nme0_packets.push_back(datagram);
                _navigation_interface->add_datagram(datagram, package_info);
                break;
            }
            case t_SimradDatagramIdentifier::MRU0: {
                auto datagram = datagrams::MRU0::from_stream(ifs, header);

                if (!ifs.good())
                    break;

                _packet_buffer.mru0_packets.push_back(datagram);
                _navigation_interface->add_datagram(datagram, package_info);
                break;
            }
            case t_SimradDatagramIdentifier::XML0: {

                auto xml = datagrams::XML0::from_stream(ifs, header);

                if (!ifs.good())
                    break;

                _ping_data_interface->add_datagram(xml, file_paths_cnt);

                auto xml_type = xml.get_xml_datagram_type();

                if (xml_type == "Parameter")
                {
                    auto channel =
                        std::get<datagrams::xml_datagrams::XML_Parameter>(xml.decode()).Channels[0];

                    // add channel_ptr if channel is not in in _packet_buffer.channel_parameters
                    // keys
                    if (_packet_buffer.channel_parameters.find(channel) ==
                        _packet_buffer.channel_parameters.end())
                    {
                        auto channel_ptr =
                            std::make_shared<datagrams::xml_datagrams::XML_Parameter_Channel>(
                                channel);
                        _packet_buffer.channel_parameters[channel] = channel_ptr;
                        _packet_buffer.channel_parameters_per_channel_id[channel.ChannelID] =
                            channel_ptr;
                    }
                    else
                    {
                        // update channel_ptr if channel is in in _packet_buffer.channel_parameters
                        // keys
                        auto channel_ptr = _packet_buffer.channel_parameters[channel];
                        _packet_buffer.channel_parameters_per_channel_id[channel.ChannelID] =
                            channel_ptr;
                    }
                }
                else if (xml_type == "InitialParameter")
                {
                    auto channels =
                        std::get<datagrams::xml_datagrams::XML_InitialParameter>(xml.decode())
                            .Channels;

                    for (const auto& channel : channels)
                    {
                        // add channel_ptr if channel is not in in _packet_buffer.channel_parameters
                        // keys
                        if (_packet_buffer.channel_parameters.find(channel) ==
                            _packet_buffer.channel_parameters.end())
                        {
                            auto channel_ptr =
                                std::make_shared<datagrams::xml_datagrams::XML_Parameter_Channel>(
                                    channel);
                            _packet_buffer.channel_parameters[channel] = channel_ptr;
                            _packet_buffer.channel_parameters_per_channel_id[channel.ChannelID] =
                                channel_ptr;
                        }
                        else
                        {
                            // update channel_ptr if channel is in in
                            // _packet_buffer.channel_parameters keys
                            auto channel_ptr = _packet_buffer.channel_parameters[channel];
                            _packet_buffer.channel_parameters_per_channel_id[channel.ChannelID] =
                                channel_ptr;
                        }
                    }

                    // for (const auto& channel : channels)
                    //     _packet_buffer.channel_parameters[channel.ChannelID] =
                    //         std::make_shared<datagrams::xml_datagrams::XML_Parameter_Channel>(
                    //             std::move(channel));
                }
                else if (xml_type == "Configuration")
                {
                    auto xml_datagram =
                        std::get<datagrams::xml_datagrams::XML_Configuration>(xml.decode());

                    //_navigation_interface->add_datagram(xml_datagram, package_info);
                    _packet_buffer.configuration = xml_datagram;
                }

                break;
            }
            case t_SimradDatagramIdentifier::RAW3: {
                auto ping = std::make_shared<SimradPing<t_ifstream>>(
                    _ping_data_interface,
                    package_info,
                    datagrams::RAW3::from_stream(ifs, header, true));

                if (!ifs.good())
                    break;

                ping->raw().add_parameter(
                    _packet_buffer.channel_parameters_per_channel_id[ping->get_channel_id()]);

                _ping_container.add_ping(ping);
                _ping_container_by_channel.at(ping->get_channel_id())->add_ping(ping);

                break;
            }
            case t_SimradDatagramIdentifier::FIL1: {
                auto datagram = datagrams::FIL1::from_stream(ifs, header);

                if (ifs.good())
                    _ping_data_interface->add_datagram(datagram, file_paths_cnt);
                break;
            }
            case t_SimradDatagramIdentifier::TAG0: {
                auto datagram = datagrams::TAG0::from_stream(ifs, header);

                if (ifs.good())
                    _ping_data_interface->add_datagram(datagram, file_paths_cnt);
                break;
            }
            default: {
                header.skip(ifs);
                break;
            }
        }
        return package_info;
    }

  public:
    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("FileSimradRaw", float_precision);

        auto interface_printer =
            fileinterfaces::I_InputFile<datagrams::SimradDatagram,
                                        t_SimradDatagramIdentifier,
                                        SimradPackageContainer<t_ifstream>,
                                        t_ifstream>::__printer__(float_precision);

        printer.append(interface_printer);

        printer.register_section("Pings");
        printer.register_value("Detected Pings", _ping_container.size(), "RAW3");

        return printer;
    }

  public:
    // -- class helper function macros --
    // define info_string and print functions (needs the __printer__ function)
    __CLASShelper_DEFAULT_PRINTING_FUNCTIONS__
};

} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoespingction macros --
