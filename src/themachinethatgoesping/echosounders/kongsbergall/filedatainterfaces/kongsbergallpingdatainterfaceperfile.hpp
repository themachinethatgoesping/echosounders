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
#include <memory>

/* library includes */
#include <magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../filetemplates/datainterfaces/i_pingdatainterface.hpp"
#include "../../filetemplates/datatypes/cache_structures/filepackagecache.hpp"
#include "../../filetemplates/datatypes/cache_structures/structpackage.hpp"
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

    filedatacontainers::KongsbergAllPingContainer<t_ifstream> read_pings(
        const std::unordered_map<std::string, std::string>& file_cache_paths =
            std::unordered_map<std::string, std::string>()) override
    {
        using t_pingcontainer = filedatacontainers::KongsbergAllPingContainer<t_ifstream>;
        using t_ping          = filedatatypes::KongsbergAllPing<t_ifstream>;
        using t_ping_ptr      = std::shared_ptr<t_ping>;

        // -- get cache file path for primary and secondary file --
        std::map<size_t, KongsbergPingCacheHandler> file_cache_path_per_file_nr;

        // -- create package cache_structures --
        file_cache_path_per_file_nr[this->get_file_nr()] =
            KongsbergPingCacheHandler(file_cache_paths, *this);

        if (this->has_linked_file())
            file_cache_path_per_file_nr[this->get_linked_file_nr()] =
                KongsbergPingCacheHandler(file_cache_paths, *(this->get_linked_file()));

        // initialize class structure
        std::unordered_map<uint16_t, std::unordered_map<uint16_t, t_ping_ptr>>
            pings_by_counter_by_id;

        // read the file installation parameters and build a base ping
        auto param =
            this->configuration_data_interface_for_file_const().get_installation_parameters();

        t_ping base_ping(param);
        base_ping.file_data().set_primary_file_nr(this->get_file_nr());

        for (const auto& [type, datagram_infos] : this->_datagram_infos_by_type)
        {
            switch (type)
            {
                case t_KongsbergAllDatagramIdentifier::RuntimeParameters: {

                    for (const auto& datagram_ptr : datagram_infos)
                    {
                        // read ping counter from not deduplicated datagram
                        if (datagram_ptr->get_extra_infos().size() != 4)
                            throw std::runtime_error(fmt::format(
                                "KongsbergAllPingDataInterfacePerFile::read_pings: "
                                "DatagramInfoData: extra info for datagram {} at pos "
                                "{} is not available",
                                datagram_type_to_string(datagram_ptr->get_datagram_identifier()),
                                datagram_ptr->get_file_pos()));

                        uint16_t ping_counter = datagram_ptr->template get_extra_info<uint16_t>(0);
                        uint16_t system_serial_number =
                            datagram_ptr->template get_extra_info<uint16_t>(sizeof(uint16_t));

                        // create a new ping if it does not exist
                        auto ping_it =
                            pings_by_counter_by_id[ping_counter].find(system_serial_number);
                        if (ping_it == pings_by_counter_by_id[ping_counter].end())
                        {
                            pings_by_counter_by_id[ping_counter][system_serial_number] =
                                std::make_shared<t_ping>(base_ping.deep_copy());

                            ping_it =
                                pings_by_counter_by_id[ping_counter].find(system_serial_number);
                        }

                        // add runtime parameters (will be deduplicated as boost flyweight)
                        ping_it->second->set_runtime_parameters(
                            file_cache_path_per_file_nr[datagram_ptr->get_file_nr()]
                                .read_or_get_runtimeparameters(datagram_ptr));

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
                        if (datagram_ptr->get_extra_infos().size() != 4)
                            throw std::runtime_error(fmt::format(
                                "KongsbergAllPingDataInterfacePerFile::read_pings: "
                                "DatagramInfoData: extra info for datagram {} at pos "
                                "{} is not available",
                                datagram_type_to_string(datagram_ptr->get_datagram_identifier()),
                                datagram_ptr->get_file_pos()));

                        uint16_t ping_counter = datagram_ptr->template get_extra_info<uint16_t>(0);
                        uint16_t serial_number =
                            datagram_ptr->template get_extra_info<uint16_t>(sizeof(uint16_t));

                        // create a new ping if it does not exist
                        auto ping_it = pings_by_counter_by_id[ping_counter].find(serial_number);
                        if (ping_it == pings_by_counter_by_id[ping_counter].end())
                        {
                            pings_by_counter_by_id[ping_counter][serial_number] =
                                std::make_shared<t_ping>(base_ping.deep_copy());

                            ping_it = pings_by_counter_by_id[ping_counter].find(serial_number);

                            ping_it->second->file_data().set_file_ping_counter(ping_counter);
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

        // get sensor configurations for all channels
        auto sensor_configurations_per_trx_channel =
            this->configuration_data_interface().get_trx_sensor_configuration_per_target_id(
                this->get_file_nr());
        auto base_sensor_configuration =
            this->configuration_data_interface().get_sensor_configuration(this->get_file_nr());

        // get navigation data for this file
        auto& navigation_data_interpolator =
            this->navigation_data_interface().get_navigation_interpolator(
                base_sensor_configuration.binary_hash());
        bool navigation_is_valid = navigation_data_interpolator.valid();

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
                    if (base_sensor_configuration.has_target(channel_id))
                        ping_ptr->set_sensor_configuration_flyweight(
                            sensor_configurations_per_trx_channel.at(channel_id));

                    if (navigation_is_valid)
                        ping_ptr->set_sensor_data_latlon(
                            navigation_data_interpolator.get_sensor_data(
                                ping_ptr->get_timestamp()));
                }
                catch (std::exception& e)
                {
                    std::string linked_file_path = "None";
                    if (this->has_linked_file())
                        linked_file_path = this->get_linked_file_path();
                    // throw more precise error
                    throw std::runtime_error(
                        fmt::format("ERROR[KongsbergAllPingDataInterfacePerFile::read_pings]: For "
                                    "files\n-Primary:'{}'\n-Secondary'{}'\n could not "
                                    "set geolocation for ping nr {} transducer id {} at time {}\n"
                                    "--- ERROR was ---\n{}",
                                    this->get_file_path(),
                                    linked_file_path,
                                    ping_counter,
                                    id,
                                    ping_ptr->get_timestamp(),
                                    e.what()));
                }

                // load water column data
                if (ping_ptr->has_watercolumn())
                {
                    // this assumes that all watercolumndatagrams are from the same file
                    auto file_nr = ping_ptr->file_data()
                                       .get_datagram_infos(
                                           t_KongsbergAllDatagramIdentifier::WatercolumnDatagram)
                                       .at(0)
                                       ->get_file_nr();

                    // add runtime parameters (will be deduplicated as boost flyweight)
                    ping_ptr->file_data().set_watercolumninformation(
                        file_cache_path_per_file_nr[file_nr].read_or_get_watercoumninformation(
                            *ping_ptr));
                }

                // load system information (if RawRangeAndAngle is available)
                if (ping_ptr->has_bottom())
                    if (ping_ptr->bottom().has_two_way_travel_times())
                    {
                        // this assumes that there is one RawRangeAndAngle datagram per ping
                        auto file_nr = ping_ptr->file_data()
                                           .get_datagram_infos(
                                               t_KongsbergAllDatagramIdentifier::RawRangeAndAngle)
                                           .at(0)
                                           ->get_file_nr();

                        // add runtime parameters (will be deduplicated as boost flyweight)
                        ping_ptr->file_data().set_systeminformation(
                            file_cache_path_per_file_nr[file_nr].read_or_get_systeminformation(
                                *ping_ptr));
                    }

                // load information that has not been cached
                ping_ptr->load();

                pings.add_ping(std::move(ping_ptr));
            }
        }

        // update cache
        for (auto& [file_nr, cache_handler] : file_cache_path_per_file_nr)
            cache_handler.update_cache_file();

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

  private:
    class KongsbergPingCacheHandler
    {
        using t_FileCache = filetemplates::datatypes::FileCache;
        using t_cache_RuntimeParameters =
            filetemplates::datatypes::cache_structures::FilePackageCache<
                datagrams::RuntimeParameters>;
        using t_cache_SystemInformation =
            filetemplates::datatypes::cache_structures::FilePackageCache<
                filedatatypes::_sub::SystemInformation>;
        using t_cache_WaterColumnInformation =
            filetemplates::datatypes::cache_structures::FilePackageCache<
                filedatatypes::_sub::WaterColumnInformation>;

        bool                         _update_cache = false;
        std::string                  _cache_file_path;
        std::unique_ptr<t_FileCache> _file_cache;

      public:
        // cache_structures
        t_cache_RuntimeParameters      _buffer_runtimeparameters;
        t_cache_SystemInformation      _buffer_systeminformation;
        t_cache_WaterColumnInformation _buffer_watercolumninformation;

      public:
        KongsbergPingCacheHandler() = default;

        template<typename t_FileDataInterface>
        KongsbergPingCacheHandler(
            const std::unordered_map<std::string, std::string>& file_cache_paths,
            const t_FileDataInterface&                          PingDataInterface)
        {
            const auto cache_file_it = file_cache_paths.find(PingDataInterface.get_file_path());
            if (cache_file_it == file_cache_paths.end())
                // leave _file_cache uninitialized
                return;

            _cache_file_path = cache_file_it->second;

            _file_cache = std::make_unique<t_FileCache>(
                t_FileCache(_cache_file_path,
                            PingDataInterface.get_file_path(),
                            PingDataInterface.get_file_size(),
                            { "FilePackageCache<RuntimeParameters>",
                              "FilePackageCache<WaterColumnInformation>",
                              "FilePackageCache<SystemInformation>" }));

            if (_file_cache->has_cache("FilePackageCache<RuntimeParameters>"))
                _buffer_runtimeparameters = _file_cache->get_from_cache<t_cache_RuntimeParameters>(
                    "FilePackageCache<RuntimeParameters>");

            if (_file_cache->has_cache("FilePackageCache<WaterColumnInformation>"))
                _buffer_watercolumninformation =
                    _file_cache->get_from_cache<t_cache_WaterColumnInformation>(
                        "FilePackageCache<WaterColumnInformation>");

            if (_file_cache->has_cache("FilePackageCache<SystemInformation>"))
                _buffer_systeminformation = _file_cache->get_from_cache<t_cache_SystemInformation>(
                    "FilePackageCache<SystemInformation>");
        }

        operator bool() const { return bool(_file_cache); }

        template<typename t_datagram_ptr>
        datagrams::RuntimeParameters read_or_get_runtimeparameters(
            const t_datagram_ptr& datagram_ptr)
        {
            if (!_file_cache)
                return datagram_ptr
                    ->template read_datagram_from_file<datagrams::RuntimeParameters>();

            if (_buffer_runtimeparameters.has_package(datagram_ptr->get_file_pos()))
                return *_buffer_runtimeparameters.get_package(datagram_ptr->get_file_pos(),
                                                              datagram_ptr->get_timestamp());

            _update_cache = true;
            auto rp =
                datagram_ptr->template read_datagram_from_file<datagrams::RuntimeParameters>();

            _buffer_runtimeparameters.add_package(
                datagram_ptr->get_file_pos(),
                datagram_ptr->get_timestamp(),
                std::make_unique<datagrams::RuntimeParameters>(rp));

            return rp;
        }

        template<typename t_ping>
        std::unique_ptr<filedatatypes::_sub::WaterColumnInformation>
        read_or_get_watercoumninformation(t_ping& ping)
        {
            if (!_file_cache)
                return std::make_unique<filedatatypes::_sub::WaterColumnInformation>(
                    ping.file_data().read_merged_watercolumndatagram(true));

            const auto& datagram_info =
                ping.file_data()
                    .get_datagram_infos(t_KongsbergAllDatagramIdentifier::WatercolumnDatagram)
                    .at(0);

            if (_buffer_watercolumninformation.has_package(datagram_info->get_file_pos()))
                return _buffer_watercolumninformation.get_package(datagram_info->get_file_pos(),
                                                                  datagram_info->get_timestamp());

            _update_cache = true;
            auto dat      = std::make_unique<filedatatypes::_sub::WaterColumnInformation>(
                ping.file_data().read_merged_watercolumndatagram(true));

            _buffer_watercolumninformation.add_package(
                datagram_info->get_file_pos(),
                datagram_info->get_timestamp(),
                std::make_unique<filedatatypes::_sub::WaterColumnInformation>(*dat));

            return dat;
        }

        template<typename t_ping>
        std::unique_ptr<filedatatypes::_sub::SystemInformation> read_or_get_systeminformation(
            t_ping& ping)
        {
            if (!_file_cache)
                return std::make_unique<filedatatypes::_sub::SystemInformation>(
                    ping.file_data().template read_first_datagram<datagrams::RawRangeAndAngle>());

            const auto& datagram_info =
                ping.file_data()
                    .get_datagram_infos(t_KongsbergAllDatagramIdentifier::RawRangeAndAngle)
                    .at(0);

            if (_buffer_systeminformation.has_package(datagram_info->get_file_pos()))
                return _buffer_systeminformation.get_package(datagram_info->get_file_pos(),
                                                             datagram_info->get_timestamp());

            _update_cache = true;
            auto dat      = std::make_unique<filedatatypes::_sub::SystemInformation>(
                ping.file_data().template read_first_datagram<datagrams::RawRangeAndAngle>());

            _buffer_systeminformation.add_package(
                datagram_info->get_file_pos(),
                datagram_info->get_timestamp(),
                std::make_unique<filedatatypes::_sub::SystemInformation>(*dat));

            return dat;
        }

        void update_cache_file()
        {
            if (!_file_cache)
                return;

            if (_update_cache)
            {
                _file_cache->add_to_cache("FilePackageCache<RuntimeParameters>",
                                          _buffer_runtimeparameters);
                _file_cache->add_to_cache("FilePackageCache<WaterColumnInformation>",
                                          _buffer_watercolumninformation);
                _file_cache->add_to_cache("FilePackageCache<SystemInformation>",
                                          _buffer_systeminformation);
                _file_cache->update_file(_cache_file_path);
            }
        }
    };
};
}
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
