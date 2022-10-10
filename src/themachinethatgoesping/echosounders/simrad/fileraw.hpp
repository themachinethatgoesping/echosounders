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
#include <themachinethatgoesping/tools/classhelpers/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../fileinterfaces/i_inputfile.hpp"
#include "../fileinterfaces/i_pingiterator.hpp"
#include "simradping.hpp"
#include "simradpinginterface.hpp"
#include "simradpingiterator.hpp"

#include "simrad_datagrams.hpp"
#include "simrad_types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {

template<typename t_ifstream >
class FileRaw
    : public fileinterfaces::
          I_InputFile<datagrams::SimradDatagram, t_SimradDatagramType, t_ifstream>
{
    const std::shared_ptr<SimradPingInterface<t_ifstream>> _ping_interface =
        std::make_shared<SimradPingInterface<t_ifstream>>(this->_file_paths,
                                                          this->_package_infos_all);
    const std::shared_ptr<std::vector<SimradPing<t_ifstream>>> _pings =
        std::make_shared<std::vector<SimradPing<t_ifstream>>>();

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
    // base class using fileinterfaces::I_InputFile<datagrams::SimradDatagram, t_SimradDatagramType,
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

    SimradPingIterator<t_ifstream> pings() const
    {
        return SimradPingIterator<t_ifstream>(this->_file_paths, _pings);
    }
    SimradPingIterator<t_ifstream> pings(long index_min, long index_max, long index_step) const
    {
        return SimradPingIterator<t_ifstream>(this->_file_paths, _pings, index_min, index_max, index_step);
    }

    // void print_fileinfo(std::ostream& os) const;
    std::string datagram_identifier_to_string(t_SimradDatagramType datagram_type) const final
    {
        return datagram_type_to_string(simrad_long(datagram_type));
        // return std::string(magic_enum::enum_name(datagram_type));
    }

    std::string datagram_identifier_info(t_SimradDatagramType datagram_type) const final
    {
        // this should work, but doesn't
        // return magic_enum::enum_contains(datagram_type);

        switch (datagram_type)
        {
            case t_SimradDatagramType::MRU0:
                return "Motion binary datagram";
            case t_SimradDatagramType::NME0:
                return "NMEA text datagram";
            case t_SimradDatagramType::XML0:
                return "XML0 text datagram";
            case t_SimradDatagramType::TAG0:
                return "Annotation datagram";
            case t_SimradDatagramType::FIL1:
                return "Filter binary datagram";
            case t_SimradDatagramType::RAW3:
                return "Sample binary datagram";
            default:
                return "unknown (" + std::to_string(magic_enum::enum_integer(datagram_type)) + ")";
        }
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

        //TODO: this crashed for empty navigation data!
        _navigation_interpolators->push_back(process_navigation(false));
    }

    fileinterfaces::PackageInfo<t_SimradDatagramType> callback_scan_packet(
        t_ifstream&                   ifs,
        typename t_ifstream::pos_type pos,
        size_t                        file_paths_cnt) final
    {
        auto header = datagrams::SimradDatagram::from_stream(ifs);
        auto type   = header.get_datagram_identifier();

        fileinterfaces::PackageInfo<t_SimradDatagramType> package_info;
        package_info.file_nr             = file_paths_cnt;
        package_info.file_pos            = pos;
        package_info.timestamp           = header.get_timestamp();
        package_info.datagram_identifier = header.get_datagram_identifier();

        switch (type)
        {
            case t_SimradDatagramType::NME0: {
                _packet_buffer.nme0_packets.emplace_back(datagrams::NME0::from_stream(ifs, header));

                if (!ifs.good())
                    _packet_buffer.nme0_packets.pop_back();
                break;
            }
            case t_SimradDatagramType::MRU0: {
                _packet_buffer.mru0_packets.emplace_back(datagrams::MRU0::from_stream(ifs, header));

                if (!ifs.good())
                    _packet_buffer.mru0_packets.pop_back();
                break;
            }
            case t_SimradDatagramType::XML0: {
                auto xml = datagrams::XML0::from_stream(ifs, header);

                if (!ifs.good())
                    break;

                auto xml_type = xml.get_xml_datagram_type();

                if (xml_type == "Configuration")
                    _packet_buffer.configuration =
                        std::get<datagrams::xml_datagrams::XML_Configuration>(xml.decode());

                break;
            }
            case t_SimradDatagramType::RAW3: {
                _pings->emplace_back(
                    _ping_interface, package_info, datagrams::RAW3::from_stream(ifs, header, true));

                if (!ifs.good())
                    _pings->pop_back();

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
    tools::classhelpers::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelpers::ObjectPrinter printer("FileSimradRaw", float_precision);

        auto interface_printer =
            fileinterfaces::I_InputFile<datagrams::SimradDatagram,
                                        t_SimradDatagramType,
                                        t_ifstream>::__printer__(float_precision);

        printer.append(interface_printer);

        return printer;
    }

  public:
    // -- class helper function macros --
    // define info_string and print functions (needs the __printer__ function)
    __CLASSHELPERS_DEFAULT_PRINTING_FUNCTIONS__
};

} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoespingction macros --
