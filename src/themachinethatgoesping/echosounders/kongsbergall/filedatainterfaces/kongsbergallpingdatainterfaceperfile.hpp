// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/kongsbergallpingdatainterfaceperfile.doc.hpp"

/* std includes */
#include <map>

/* library includes */
#include <magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../filetemplates/datainterfaces/i_pingdatainterface.hpp"
#include "../../filetemplates/datatypes/cache_structures/filepackagecache.hpp"
#include "../../filetemplates/datatypes/cache_structures/tuplepackage.hpp"
#include "../../filetemplates/datatypes/filecache.hpp"

#include "kongsbergallconfigurationdatainterface.hpp"

#include "../datagrams.hpp"
#include "../filedatacontainers/kongsbergallpingcontainer.hpp"
#include "../types.hpp"
#include "kongsbergalldatagraminterface.hpp"
#include "kongsbergallenvironmentdatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace filedatainterfaces {

template<typename t_ifstream>
class KongsbergAllPingDataInterfacePerFile
    : public filetemplates::datainterfaces::I_PingDataInterfacePerFile<
          KongsbergAllEnvironmentDataInterface<t_ifstream>,
          filedatacontainers::KongsbergAllPingContainer<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_PingDataInterfacePerFile<
        KongsbergAllEnvironmentDataInterface<t_ifstream>,
        filedatacontainers::KongsbergAllPingContainer<t_ifstream>>;

    std::map<std::string, datagrams::RuntimeParameters> _runtime_parameter_buffer;

  public:
    KongsbergAllPingDataInterfacePerFile()
        : t_base("KongsbergAllPingDataInterfacePerFile")
    {
    }
    KongsbergAllPingDataInterfacePerFile(
        std::shared_ptr<KongsbergAllEnvironmentDataInterface<t_ifstream>>
            environment_data_interface)
        : t_base(std::move(environment_data_interface), "KongsbergAllPingDataInterfacePerFile")
    {
    }
    ~KongsbergAllPingDataInterfacePerFile() = default;

    auto get_deduplicated_runtime_parameters() { return _runtime_parameter_buffer; }

    filedatacontainers::KongsbergAllPingContainer<t_ifstream> read_pings(
        const std::string& cache_file_path = "")
    {
        using t_pingcontainer = filedatacontainers::KongsbergAllPingContainer<t_ifstream>;
        using t_ping          = filedatatypes::KongsbergAllPing<t_ifstream>;
        using t_ping_ptr      = std::shared_ptr<t_ping>;

        using t_PingCounterSerialNumber =
            filetemplates::datatypes::cache_structures::TuplePackage<uint16_t, uint16_t>;
        using t_cache_PingCounterSerialNumber =
            filetemplates::datatypes::cache_structures::FilePackageCache<t_PingCounterSerialNumber>;

        using t_FileCache = filetemplates::datatypes::FileCache;

        // -- create package cache_structures --
        bool                            cache_updated = false;
        t_FileCache                     file_cache(this->get_file_path(), this->get_file_size());
        t_cache_PingCounterSerialNumber package_buffer_pingcounterserialnumber;

        if (!cache_file_path.empty())
        {
            file_cache = t_FileCache(cache_file_path,
                                     this->get_file_path(),
                                     this->get_file_size(),
                                     { "PingCounterSerialNumber" });

            if (file_cache.has_cache("PingCounterSerialNumber"))
                package_buffer_pingcounterserialnumber =
                    file_cache.get_from_cache<t_cache_PingCounterSerialNumber>(
                        "PingCounterSerialNumber");
        }

        std::unordered_map<uint16_t, std::unordered_map<uint16_t, t_ping_ptr>>
            pings_by_counter_by_id;

        // read the file installation parameters and build a base ping
        auto param =
            this->configuration_data_interface_for_file_const().get_installation_parameters();

        const auto& base_sensor_configuration =
            this->configuration_data_interface().get_sensor_configuration(this->get_file_nr());

        t_ping base_ping(param);
        base_ping.file_data().set_primary_file_nr(this->get_file_nr());

        for (const auto& [type, datagram_infos] : this->_datagram_infos_by_type)
        {
            switch (type)
            {
                case t_KongsbergAllDatagramIdentifier::RuntimeParameters: {

                    for (const auto& datagram_ptr : datagram_infos)
                    {
                        auto rp =
                            datagram_ptr
                                ->template read_datagram_from_file<datagrams::RuntimeParameters>();
                        _runtime_parameter_buffer[std::to_string(rp.get_system_serial_number())] =
                            rp;

                        // read ping counter from not deduplicated datagram
                        auto ping_counter         = rp.get_ping_counter();
                        auto system_serial_number = rp.get_system_serial_number();

                        // create a new ping if it does not exist
                        auto ping_it =
                            pings_by_counter_by_id[ping_counter].find(system_serial_number);
                        if (ping_it == pings_by_counter_by_id[ping_counter].end())
                        {
                            pings_by_counter_by_id[ping_counter][system_serial_number] =
                                std::make_shared<t_ping>(base_ping.deep_copy());

                            ping_it =
                                pings_by_counter_by_id[ping_counter].find(system_serial_number);

                            // ping_it->second->set_file_ping_counter(ping_counter);
                        }

                        // add deduplicated runtime parameters
                        ping_it->second->set_runtime_parameters(_runtime_parameter_buffer.at(
                            std::to_string(rp.get_system_serial_number())));

                        // add runtime parameters datagram
                        ping_it->second->add_datagram_info(datagram_ptr);
                    }
                    break;
                }
                case t_KongsbergAllDatagramIdentifier::XYZDatagram:
                    [[fallthrough]];
                case t_KongsbergAllDatagramIdentifier::ExtraDetections:
                    [[fallthrough]];
                case t_KongsbergAllDatagramIdentifier::RawRangeAndAngle:
                    [[fallthrough]];
                case t_KongsbergAllDatagramIdentifier::SeabedImageData:
                    [[fallthrough]];
                case t_KongsbergAllDatagramIdentifier::QualityFactorDatagram:
                    [[fallthrough]];
                case t_KongsbergAllDatagramIdentifier::WatercolumnDatagram: {

                    for (const auto& datagram_ptr : datagram_infos)
                    {
                        t_PingCounterSerialNumber counter_snumber;

                        if (!cache_file_path.empty() &&
                            package_buffer_pingcounterserialnumber.has_package(
                                datagram_ptr->get_file_pos()))
                        {
                            counter_snumber = package_buffer_pingcounterserialnumber.get_package(
                                datagram_ptr->get_file_pos(), datagram_ptr->get_timestamp());
                        }
                        else
                        {
                            // read the ping counter
                            auto& ifs = datagram_ptr->get_stream_and_seek(
                                16); // offset=16 bytes (header size)

                            // ifs.seekg(16, std::ios::cur); // skip header
                            ifs.read(reinterpret_cast<char*>(&std::get<0>(counter_snumber)),
                                     sizeof(uint16_t) * 2);

                            // update the cache
                            if (!cache_file_path.empty())
                            {
                                package_buffer_pingcounterserialnumber.add_package(
                                    datagram_ptr->get_file_pos(),
                                    datagram_ptr->get_timestamp(),
                                    counter_snumber);
                                cache_updated = true;
                            }
                        }

                        // create a new ping if it does not exist
                        auto ping_it = pings_by_counter_by_id[std::get<0>(counter_snumber)].find(
                            std::get<1>(counter_snumber));
                        if (ping_it == pings_by_counter_by_id[std::get<0>(counter_snumber)].end())
                        {
                            pings_by_counter_by_id[std::get<0>(counter_snumber)][std::get<1>(
                                counter_snumber)] = std::make_shared<t_ping>(base_ping.deep_copy());

                            ping_it = pings_by_counter_by_id[std::get<0>(counter_snumber)].find(
                                std::get<1>(counter_snumber));

                            ping_it->second->file_data().set_file_ping_counter(
                                std::get<0>(counter_snumber));
                        }

                        ping_it->second->add_datagram_info(datagram_ptr);
                    }
                    break;
                }
                default:
                    throw std::runtime_error(
                        fmt::format("Invalid datagram type {} for KongsbergAllPing",
                                    magic_enum::enum_name(type)));
            }
        }

        // loop through map and copy pings to vector
        t_pingcontainer pings;
        for (auto [ping_counter, pings_by_id] : pings_by_counter_by_id)
        {
            for (auto [id, ping_ptr] : pings_by_id)
            {
                std::string channel_id = fmt::format("TRX-{}", id);

                ping_ptr->set_channel_id(channel_id);

                // load transducer locations from navigation
                try
                {
                    auto sensor_configuration = base_sensor_configuration;
                    sensor_configuration.add_target("Transducer",
                                                    sensor_configuration.get_target(channel_id));
                    ping_ptr->set_sensor_configuration(sensor_configuration);

                    ping_ptr->set_sensor_data_latlon(
                        this->navigation_data_interface().get_sensor_data(
                            base_sensor_configuration, ping_ptr->get_timestamp()));
                }
                catch (std::exception& e)
                {
                    // throw more precise error
                    throw std::runtime_error(fmt::format(
                        "ERROR[KongsbergAllPingDataInterfacePerFile::read_pings]: could not "
                        "set geolocation ping transducer id {} at time {}\n ERROR was: {}",
                        id,
                        ping_ptr->get_timestamp(),
                        e.what()));
                }

                pings.add_ping(std::move(ping_ptr));
            }
        }

        // update cache
        if (cache_updated)
        {
            file_cache.add_to_cache("PingCounterSerialNumber",
                                    package_buffer_pingcounterserialnumber);

            file_cache.update_file(cache_file_path);
        }

        return pings;
    }

    // --------------------- kongsbergall specific functions ---------------------
    /* get infos */

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision)
    {
        tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision));

        printer.register_section("KongsbergAllPingDataInterfacePerFile");

        return printer;
    }
};

}
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
