// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/simradrawpingdatainterfaceperfile.doc.hpp"

/* std includes */
#include <map>

/* library includes */
#include <boost/flyweight.hpp>
#include <magic_enum/magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../filetemplates/datainterfaces/i_pingdatainterface.hpp"
#include "../../filetemplates/datatypes/cache_structures/filepackagecache.hpp"
#include "../../filetemplates/datatypes/filecache.hpp"
#include "simradrawconfigurationdatainterface.hpp"

#include "../datagrams.hpp"
#include "../filedatatypes/sub/transceiverinformation.hpp"
#include "../types.hpp"
#include "simradrawdatagraminterface.hpp"
#include "simradrawenvironmentdatainterface.hpp"

#include "../filedatacontainers/simradrawfiledatacontainers.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace filedatainterfaces {

template<typename t_ifstream>
class SimradRawPingDataInterfacePerFile
    : public filetemplates::datainterfaces::I_PingDataInterfacePerFile<
          SimradRawEnvironmentDataInterface<t_ifstream>,
          filedatacontainers::SimradRawPingContainer<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_PingDataInterfacePerFile<
        SimradRawEnvironmentDataInterface<t_ifstream>,
        filedatacontainers::SimradRawPingContainer<t_ifstream>>;

    std::map<std::string, boost::flyweight<datagrams::xml_datagrams::XML_Parameter_Channel>>
        _channel_parameter_buffer;

    bool _environment_buffer_initialized = false;
    boost::flyweight<datagrams::xml_datagrams::XML_Environment> _environment_buffer;

  public:
    SimradRawPingDataInterfacePerFile()
        : t_base("SimradRawPingDataInterfacePerFile")
    {
    }
    SimradRawPingDataInterfacePerFile(
        std::shared_ptr<SimradRawEnvironmentDataInterface<t_ifstream>> environment_data_interface)
        : t_base(std::move(environment_data_interface), "SimradRawPingDataInterfacePerFile")
    {
    }
    ~SimradRawPingDataInterfacePerFile() = default;

    filedatacontainers::SimradRawPingContainer<t_ifstream> read_pings(

        const std::unordered_map<std::string, std::string>& file_cache_paths =
            std::unordered_map<std::string, std::string>()) override
    {
        using t_cache_XML_Parameter_Channel =
            filetemplates::datatypes::cache_structures::FilePackageCache<
                datagrams::xml_datagrams::XML_Parameter_Channel>;
        using t_cache_RAW3 =
            filetemplates::datatypes::cache_structures::FilePackageCache<datagrams::RAW3>;

        using t_FileCache = filetemplates::datatypes::FileCache;

        filedatacontainers::SimradRawPingContainer<t_ifstream> pings;

        // -- get cache file path (assumes there is only one file) --
        std::string cache_file_path = tools::helper::get_from_map_with_default(
            file_cache_paths, this->get_file_path(), std::string(""));

        // -- create package cache_structures --
        bool                          cache_updated = false;
        t_FileCache                   file_cache(this->get_file_path(), this->get_file_size());
        t_cache_XML_Parameter_Channel package_buffer_xml;
        t_cache_RAW3                  package_buffer_raw3;

        if (!cache_file_path.empty())
        {
            file_cache = t_FileCache(
                cache_file_path,
                this->get_file_path(),
                this->get_file_size(),
                { "FilePackageCache<XML_Parameter_Channel>", "FilePackageCache<RAW3>" });

            if (file_cache.has_cache("FilePackageCache<XML_Parameter_Channel>"))
                package_buffer_xml = file_cache.get_from_cache<t_cache_XML_Parameter_Channel>(
                    "FilePackageCache<XML_Parameter_Channel>");

            if (file_cache.has_cache("FilePackageCache<RAW3>"))
                package_buffer_raw3 =
                    file_cache.get_from_cache<t_cache_RAW3>("FilePackageCache<RAW3>");
        }

        // get sensor configurations for all channels
        auto sensor_configurations_per_trx_channel =
            this->configuration_data_interface().get_trx_sensor_configuration_per_target_id(
                this->get_file_nr());
        auto base_sensor_configuration =
            this->configuration_data_interface().get_sensor_configuration(this->get_file_nr());

        // get navigation data for this file
        boost::flyweights::flyweight<navigation::NavigationInterpolatorLatLon>
            navigation_data_interpolator =
                this->navigation_data_interface().get_navigation_interpolator_flyweight(
                    base_sensor_configuration.binary_hash());
        bool navigation_is_valid = navigation_data_interpolator.get().valid();

        // transceiver information
        // get configuration datagram
        auto configuration_datagram = this->configuration_data_interface()
                                          .per_file()
                                          .at(this->get_file_nr())
                                          ->get_configuration_datagram();
        auto transceivers         = configuration_datagram.get_transceivers();
        auto transceiver_channels = configuration_datagram.get_transceiver_channels();

        // cache for transceiver information
        std::map<std::string, boost::flyweight<filedatatypes::_sub::TransceiverInformation>>
            transceiver_information_buffer;
        for (const auto& [channel_id, transceiver] : transceivers)
        {
            transceiver_information_buffer[channel_id] =
                filedatatypes::_sub::TransceiverInformation(transceiver,
                                                            transceiver_channels.at(channel_id));
        }

        for (const auto& datagram_ptr : this->_datagram_infos_all)
        {
            auto type = datagram_ptr->get_datagram_identifier();

            switch (type)
            {
                case t_SimradRawDatagramIdentifier::XML0: {
                    // Note: PingDataInterface should only include Parameter or InitialParameter
                    // datagram
                    // Note: Environment is also possible, but is not cached

                    // load from cache if available
                    if (!cache_file_path.empty())
                        if (package_buffer_xml.has_package(datagram_ptr->get_file_pos()))
                        {
                            auto channels = package_buffer_xml.get_packages(
                                datagram_ptr->get_file_pos(), datagram_ptr->get_timestamp());
                            for (const auto& channel : channels)
                            {
                                _channel_parameter_buffer[channel->ChannelID] = *channel;
                            }
                            break;
                        }

                    auto& ifs = datagram_ptr->get_stream_and_seek();
                    auto  xml = datagrams::XML0::from_stream(ifs);

                    if (!ifs.good())
                    {
                        fmt::print(std::cerr, "Error reading XML0 datagram");
                        break;
                    }

                    auto xml_type = xml.get_xml_datagram_type();

                    if (xml_type == "Parameter")
                    {
                        auto param =
                            std::get<datagrams::xml_datagrams::XML_Parameter>(xml.decode());
                        const auto& channels = param.Channels;

                        for (unsigned int i = 0; i < channels.size(); i++)
                        {
                            _channel_parameter_buffer[channels[i].ChannelID] = channels[i];

                            if (!cache_file_path.empty())
                            {
                                cache_updated = true;
                                package_buffer_xml.add_package(
                                    datagram_ptr->get_file_pos(),
                                    datagram_ptr->get_timestamp(),
                                    std::make_unique<
                                        datagrams::xml_datagrams::XML_Parameter_Channel>(
                                        channels[i]),
                                    i);
                            }
                        }
                        break;
                    }
                    else if (xml_type == "InitialParameter")
                    {
                        auto param =
                            std::get<datagrams::xml_datagrams::XML_InitialParameter>(xml.decode());
                        const auto& channels = param.Channels;

                        for (unsigned int i = 0; i < channels.size(); i++)
                        {
                            _channel_parameter_buffer[channels[i].ChannelID] = channels[i];

                            if (!cache_file_path.empty())
                            {
                                cache_updated = true;
                                package_buffer_xml.add_package(
                                    datagram_ptr->get_file_pos(),
                                    datagram_ptr->get_timestamp(),
                                    std::make_unique<
                                        datagrams::xml_datagrams::XML_Parameter_Channel>(
                                        channels[i]),
                                    i);
                            }
                        }
                        break;
                    }
                    else if (xml_type == "Environment")
                    {
                        _environment_buffer =
                            std::get<datagrams::xml_datagrams::XML_Environment>(xml.decode());
                        _environment_buffer_initialized = true;
                        break;
                    }

                    fmt::print(std::cerr, "WARNING: unexpected xml datagram type: {}\n", xml_type);
                    break;
                }
                case t_SimradRawDatagramIdentifier::RAW3: {

                    // load from cache if available
                    datagrams::RAW3 raw3;

                    if (!cache_file_path.empty() &&
                        package_buffer_raw3.has_package(datagram_ptr->get_file_pos()))
                    {
                        raw3 = *package_buffer_raw3.get_package(datagram_ptr->get_file_pos(),
                                                                datagram_ptr->get_timestamp());
                    }
                    else
                    {
                        auto& ifs = datagram_ptr->get_stream_and_seek();
                        raw3      = datagrams::RAW3::from_stream(ifs, true);

                        if (!ifs.good())
                        {
                            fmt::print(std::cerr, "Error reading RAW3 datagram");
                            break;
                        }
                    }

                    if (!cache_file_path.empty() &&
                        !package_buffer_raw3.has_package(datagram_ptr->get_file_pos()))
                    {
                        cache_updated = true;
                        package_buffer_raw3.add_package(datagram_ptr->get_file_pos(),
                                                        datagram_ptr->get_timestamp(),
                                                        std::make_unique<datagrams::RAW3>(raw3));
                    }

                    // create ping from raw3 datagram
                    auto ping_ptr =
                        std::make_shared<filedatatypes::SimradRawPing<t_ifstream>>(raw3);
                    ping_ptr->add_datagram_info(datagram_ptr);

                    // set transceiver information
                    auto it = transceiver_information_buffer.find(ping_ptr->get_channel_id());
                    if (it != transceiver_information_buffer.end())
                    {
                        ping_ptr->file_data().set_transceiver_information(it->second);
                    }

                    // set channel_id
                    // substring of channel_id until the first \x00 character

                    // add parameters
                    ping_ptr->file_data().set_file_ping_counter(pings.size());
                    ping_ptr->file_data().set_primary_file_nr(this->get_file_nr());
                    ping_ptr->file_data().set_parameter(
                        _channel_parameter_buffer.at(ping_ptr->get_channel_id()));

                    if (!_environment_buffer_initialized)
                        throw std::runtime_error(
                            fmt::format("Error no XML environment datagram found prior to ping!"));
                    ping_ptr->file_data().set_environment(_environment_buffer);

                    // set sensor configuration
                    if (base_sensor_configuration.has_target(ping_ptr->get_channel_id()))
                        ping_ptr->set_sensor_configuration_flyweight(
                            sensor_configurations_per_trx_channel.at(ping_ptr->get_channel_id()));

                    if (navigation_is_valid)
                        ping_ptr->set_navigation_interpolator_latlon(navigation_data_interpolator);

                    // load remaining data structures
                    ping_ptr->load();
                    pings.add_ping(std::move(ping_ptr));
                    break;
                }
                case t_SimradRawDatagramIdentifier::FIL1:
                    [[fallthrough]];
                case t_SimradRawDatagramIdentifier::TAG0:
                    [[fallthrough]];
                case t_SimradRawDatagramIdentifier::MRU0:
                    [[fallthrough]];
                case t_SimradRawDatagramIdentifier::NME0:
                    [[fallthrough]];
                default: {
                    fmt::print(std::cerr,
                               "WARNING: unexpected datagram type: {}\n",
                               datagram_type_to_string(type));
                }
            }
        }

        // update cache
        if (!cache_file_path.empty())
        {
            if (cache_updated)
            {
                file_cache.add_to_cache("FilePackageCache<XML_Parameter_Channel>",
                                        package_buffer_xml);

                file_cache.add_to_cache("FilePackageCache<RAW3>", package_buffer_raw3);

                file_cache.update_file(cache_file_path);
            }
        }

        // package_buffer_xml.print(std::cerr);
        // package_buffer_raw3.print(std::cerr);

        return pings;
    }
    // --------------------- simradraw specific functions ---------------------
    /* get infos */

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents)
    {
        tools::classhelper::ObjectPrinter printer(
            this->class_name(), float_precision, superscript_exponents);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision, superscript_exponents));

        printer.register_section("SimradRawPingDataInterfacePerFile");

        return printer;
    }
};

}
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
