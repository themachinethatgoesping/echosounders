// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/kmallpingdatainterfaceperfile.doc.hpp"

/* std includes */
#include <map>
#include <memory>

/* library includes */
#include <boost/flyweight.hpp>
#include <magic_enum/magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../../filetemplates/datainterfaces/i_pingdatainterface.hpp"
#include "../../filetemplates/datatypes/cache_structures/filepackagecache.hpp"
#include "../../filetemplates/datatypes/cache_structures/structpackage.hpp"
#include "../../filetemplates/datatypes/filecache.hpp"

#include "kmallconfigurationdatainterface.hpp"

#include "../datagrams.hpp"
#include "../filedatacontainers/kmallpingcontainer.hpp"
#include "../types.hpp"
#include "kmalldatagraminterface.hpp"
#include "kmallenvironmentdatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace filedatainterfaces {

template<typename t_ifstream>
class KMALLPingDataInterfacePerFile
    : public filetemplates::datainterfaces::I_PingDataInterfacePerFile<
          KMALLEnvironmentDataInterface<t_ifstream>,
          filedatacontainers::KMALLPingContainer<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_PingDataInterfacePerFile<
        KMALLEnvironmentDataInterface<t_ifstream>,
        filedatacontainers::KMALLPingContainer<t_ifstream>>;

  public:
    KMALLPingDataInterfacePerFile()
        : t_base("KMALLPingDataInterfacePerFile")
    {
    }
    KMALLPingDataInterfacePerFile(
        std::shared_ptr<KMALLEnvironmentDataInterface<t_ifstream>> environment_data_interface)
        : t_base(std::move(environment_data_interface), "KMALLPingDataInterfacePerFile")
    {
    }
    ~KMALLPingDataInterfacePerFile() = default;

    filedatacontainers::KMALLPingContainer<t_ifstream> read_pings(
        const std::unordered_map<std::string, std::string>& index_paths =
            std::unordered_map<std::string, std::string>()) override
    {
        using t_pingcontainer = filedatacontainers::KMALLPingContainer<t_ifstream>;
        using t_ping          = filedatatypes::KMALLPing<t_ifstream>;
        using t_ping_ptr      = std::shared_ptr<t_ping>;

        // -- get cache file path for primary and secondary file --
        std::map<size_t, KMALLPingCacheHandler> index_path_per_file_nr;

        // -- create package cache_structures --
        index_path_per_file_nr[this->get_file_nr()] = KMALLPingCacheHandler(index_paths, *this);

        if (this->has_linked_file())
            index_path_per_file_nr[this->get_linked_file_nr()] =
                KMALLPingCacheHandler(index_paths, *(this->get_linked_file()));

        // initialize class structure
        std::unordered_map<uint16_t, std::unordered_map<uint16_t, t_ping_ptr>>
            pings_by_counter_by_id;

        // read the file installation parameters and build a base ping
        auto& configuration_data_interface_for_file = this->configuration_data_interface_for_file();
        auto  param = configuration_data_interface_for_file.read_installation_parameters();

        std::map<uint16_t, std::shared_ptr<size_t>> last_runtime_parameter_index_per_serial_number;

        t_ping base_ping;
        base_ping.file_data().set_primary_file_nr(this->get_file_nr());
        base_ping.set_channel_id(configuration_data_interface_for_file.get_transducer_id());

        for (const auto& datagram_ptr : this->_datagram_infos_all)
        {
            auto type = datagram_ptr->get_datagram_identifier();

            switch (type)
            {
                case t_KMALLDatagramIdentifier::M_RANGE_AND_DEPTH:
                    [[fallthrough]];
                case t_KMALLDatagramIdentifier::M_WATER_COLUMN: {
                    {
                        uint16_t ping_counter, serial_number;
                        this->read_extra_infos(datagram_ptr, ping_counter);
                        serial_number = 40;

                        // create a new ping if it does not exist
                        auto ping_it = pings_by_counter_by_id[ping_counter].find(serial_number);
                        if (ping_it == pings_by_counter_by_id[ping_counter].end())
                        {
                            pings_by_counter_by_id[ping_counter][serial_number] =
                                std::make_shared<t_ping>(base_ping.deep_copy());

                            ping_it = pings_by_counter_by_id[ping_counter].find(serial_number);

                            ping_it->second->file_data().set_file_ping_counter(ping_counter);

                            ping_it->second->file_data().set_runtime_parameters(
                                configuration_data_interface_for_file.get_runtime_parameters(
                                    serial_number,
                                    ping_counter,
                                    ping_it->second->get_timestamp(),
                                    last_runtime_parameter_index_per_serial_number[serial_number]));
                        }

                        ping_it->second->add_datagram_info(datagram_ptr);
                    }
                    break;
                }
                default:
                    throw std::runtime_error(fmt::format("Invalid datagram type {} for KMALLPing",
                                                         o_KMALLDatagramIdentifier::to_name(type)));
            }
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

        // loop through map and copy pings to vector
        t_pingcontainer pings;
        for (auto [ping_counter, pings_by_id] : pings_by_counter_by_id)
        {
            for (auto [id, ping_ptr] : pings_by_id)
            {
                // check if runtime parameters are available
                if (!ping_ptr->file_data().has_runtime_parameters())
                    throw std::runtime_error(
                        fmt::format("KMALLPingDataInterfacePerFile::read_pings: "
                                    "RuntimeParameters: No runtime parameters found "
                                    "for ping '{}'",
                                    ping_counter));

                // load transducer locations from navigation
                try
                {
                    if (base_sensor_configuration.has_target(ping_ptr->get_channel_id()))
                        ping_ptr->set_sensor_configuration_flyweight(
                            sensor_configurations_per_trx_channel.at(ping_ptr->get_channel_id()));

                    if (navigation_is_valid)
                        ping_ptr->set_navigation_interpolator_latlon(navigation_data_interpolator);
                }
                catch (std::exception& e)
                {
                    std::string linked_file_path = "None";
                    if (this->has_linked_file())
                        linked_file_path = this->get_linked_file_path();
                    // throw more precise error
                    throw std::runtime_error(fmt::format(
                        "ERROR[KMALLPingDataInterfacePerFile::read_pings]: For "
                        "files\n-Primary:'{}'\n-Secondary'{}'\n could not set geolocation for ping "
                        "nr {} transducer id {} at time {}\n --- ERROR was ---\n{}",
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
                    auto file_nr =
                        ping_ptr->file_data()
                            .get_datagram_infos(t_KMALLDatagramIdentifier::M_WATER_COLUMN)
                            .at(0)
                            ->get_file_nr();

                    // add runtime parameters (will be deduplicated as boost flyweight)
                    ping_ptr->file_data().set_watercolumninformation(
                        index_path_per_file_nr[file_nr].read_or_get_watercoumninformation(
                            *ping_ptr));
                }

                // load system information (if M_RANGE_AND_DEPTH is available)
                if (ping_ptr->file_data()
                        .get_datagram_infos(t_KMALLDatagramIdentifier::M_RANGE_AND_DEPTH)
                        .size() > 0)
                {
                    // this assumes that there is one M_RANGE_AND_DEPTH datagram per ping
                    auto file_nr =
                        ping_ptr->file_data()
                            .get_datagram_infos(t_KMALLDatagramIdentifier::M_RANGE_AND_DEPTH)
                            .at(0)
                            ->get_file_nr();

                    // add runtime parameters (will be deduplicated as boost flyweight)
                    ping_ptr->file_data().set_systeminformation(
                        index_path_per_file_nr[file_nr].read_or_get_systeminformation(*ping_ptr));
                }

                // load information that has not been cached
                ping_ptr->load();

                pings.add_ping(std::move(ping_ptr));
            }
        }

        // update cache
        for (auto& [file_nr, cache_handler] : index_path_per_file_nr)
            cache_handler.update_index_file();

        return pings;
    }

    // --------------------- kmall specific functions ---------------------
    /* get infos */

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents)
    {
        tools::classhelper::ObjectPrinter printer(
            this->class_name(), float_precision, superscript_exponents);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision, superscript_exponents));

        printer.register_section("KMALLPingDataInterfacePerFile");

        return printer;
    }

  private:
    void read_extra_infos(const typename t_base::type_DatagramInfo_ptr& datagram_ptr,
                          uint16_t&                                     ping_counter)
    {
        if (datagram_ptr->get_extra_infos().size() != 2)
            throw std::runtime_error(
                fmt::format("KongsbergAllPingDataInterfacePerFile::read_pings: "
                            "DatagramInfoData: extra info for datagram {} at pos "
                            "{} is not available",
                            datagram_type_to_string(datagram_ptr->get_datagram_identifier()),
                            datagram_ptr->get_file_pos()));

        ping_counter = datagram_ptr->template get_extra_info<uint16_t>(0);
    }

    class KMALLPingCacheHandler
    {
        using t_FileCache = filetemplates::datatypes::FileCache;
        using t_cache_SystemInformation =
            filetemplates::datatypes::cache_structures::FilePackageCache<
                filedatatypes::_sub::SystemInformation>;
        using t_cache_WaterColumnInformation =
            filetemplates::datatypes::cache_structures::FilePackageCache<
                filedatatypes::_sub::WaterColumnInformation>;

        bool                         _update_index = false;
        std::string                  _index_path;
        std::unique_ptr<t_FileCache> _file_cache;

      public:
        // cache_structures
        t_cache_SystemInformation      _buffer_systeminformation;
        t_cache_WaterColumnInformation _buffer_watercolumninformation;

      public:
        KMALLPingCacheHandler() = default;

        template<typename t_FileDataInterface>
        KMALLPingCacheHandler(const std::unordered_map<std::string, std::string>& index_paths,
                              const t_FileDataInterface&                          PingDataInterface)
        {
            const auto index_file_it = index_paths.find(PingDataInterface.get_file_path());
            if (index_file_it == index_paths.end())
                // leave _file_cache uninitialized
                return;

            _index_path = index_file_it->second;

            _file_cache = std::make_unique<t_FileCache>(
                t_FileCache(_index_path,
                            PingDataInterface.get_file_path(),
                            PingDataInterface.get_file_size(),
                            { "FilePackageCache<WaterColumnInformation_V1>",
                              "FilePackageCache<SystemInformation_V2>" }));

            if (_file_cache->has_cache("FilePackageCache<WaterColumnInformation_V1>"))
                _buffer_watercolumninformation =
                    _file_cache->get_from_cache<t_cache_WaterColumnInformation>(
                        "FilePackageCache<WaterColumnInformation_V1>");

            if (_file_cache->has_cache("FilePackageCache<SystemInformation_V2>"))
                _buffer_systeminformation = _file_cache->get_from_cache<t_cache_SystemInformation>(
                    "FilePackageCache<SystemInformation_V2>");
        }

        operator bool() const { return bool(_file_cache); }

        template<typename t_ping>
        std::unique_ptr<filedatatypes::_sub::WaterColumnInformation>
        read_or_get_watercoumninformation(t_ping& ping)
        {
            if (!_file_cache)
                return std::make_unique<filedatatypes::_sub::WaterColumnInformation>(
                    ping.file_data().template read_first_datagram<datagrams::MWaterColumn, true>());

            const auto& datagram_info =
                ping.file_data()
                    .get_datagram_infos(t_KMALLDatagramIdentifier::M_WATER_COLUMN)
                    .at(0);

            if (_buffer_watercolumninformation.has_package(datagram_info->get_file_pos()))
                return _buffer_watercolumninformation.get_package(datagram_info->get_file_pos(),
                                                                  datagram_info->get_timestamp());

            _update_index = true;
            auto dat      = std::make_unique<filedatatypes::_sub::WaterColumnInformation>(
                ping.file_data().template read_first_datagram<datagrams::MWaterColumn, true>());

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
                    ping.file_data().template read_first_datagram<datagrams::MRangeAndDepth>());

            const auto& datagram_info =
                ping.file_data()
                    .get_datagram_infos(t_KMALLDatagramIdentifier::M_RANGE_AND_DEPTH)
                    .at(0);

            if (_buffer_systeminformation.has_package(datagram_info->get_file_pos()))
                return _buffer_systeminformation.get_package(datagram_info->get_file_pos(),
                                                             datagram_info->get_timestamp());

            _update_index = true;
            auto dat      = std::make_unique<filedatatypes::_sub::SystemInformation>(
                ping.file_data().template read_first_datagram<datagrams::MRangeAndDepth>());

            _buffer_systeminformation.add_package(
                datagram_info->get_file_pos(),
                datagram_info->get_timestamp(),
                std::make_unique<filedatatypes::_sub::SystemInformation>(*dat));

            return dat;
        }

        void update_index_file()
        {
            if (!_file_cache)
                return;

            if (_update_index)
            {
                _file_cache->add_to_cache("FilePackageCache<WaterColumnInformation_V1>",
                                          _buffer_watercolumninformation);
                _file_cache->add_to_cache("FilePackageCache<SystemInformation_V2>",
                                          _buffer_systeminformation);
                _file_cache->update_file(_index_path);
            }
        }
    };
};
}
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
