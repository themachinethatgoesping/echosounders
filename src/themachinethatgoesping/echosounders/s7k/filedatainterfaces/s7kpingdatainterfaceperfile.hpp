// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/s7kpingdatainterfaceperfile.doc.hpp"

/* std includes */
#include <algorithm>
#include <map>
#include <memory>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../../filetemplates/datainterfaces/i_pingdatainterface.hpp"
#include "../../filetemplates/datatypes/cache_structures/filepackagecache.hpp"
#include "../../filetemplates/datatypes/filecache.hpp"

#include "s7kconfigurationdatainterface.hpp"

#include "../datagrams.hpp"
#include "../filedatacontainers/s7kpingcontainer.hpp"
#include "../types.hpp"
#include "s7kdatagraminterface.hpp"
#include "s7kenvironmentdatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace filedatainterfaces {

/**
 * @brief Interface that reads the pings (bathymetry, water column) of a single .s7k file.
 *
 * Grouping is done in file order: a new ping is started at every 7000 SonarSettings record (the
 * record that starts a ping cycle in the 7k format); every following ping datagram is added to the
 * current ping. For every ping the lightweight per-ping information is built early (and persisted
 * into the index cache): the water-column information (per-beam sample positions, NOT the samples),
 * the bottom-detection information and the system information. The water-column samples themselves
 * are read on demand per beam and never held in memory.
 *
 * @tparam t_ifstream
 */
template<typename t_ifstream>
class S7KPingDataInterfacePerFile
    : public filetemplates::datainterfaces::I_PingDataInterfacePerFile<
          S7KEnvironmentDataInterface<t_ifstream>,
          filedatacontainers::S7KPingContainer<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_PingDataInterfacePerFile<
        S7KEnvironmentDataInterface<t_ifstream>,
        filedatacontainers::S7KPingContainer<t_ifstream>>;

  public:
    S7KPingDataInterfacePerFile()
        : t_base("S7KPingDataInterfacePerFile")
    {
    }
    S7KPingDataInterfacePerFile(
        std::shared_ptr<S7KEnvironmentDataInterface<t_ifstream>> environment_data_interface)
        : t_base(std::move(environment_data_interface), "S7KPingDataInterfacePerFile")
    {
    }
    ~S7KPingDataInterfacePerFile() = default;

    filedatacontainers::S7KPingContainer<t_ifstream> read_pings(
        const std::unordered_map<std::string, std::string>& index_paths =
            std::unordered_map<std::string, std::string>()) override
    {
        using t_pingcontainer = filedatacontainers::S7KPingContainer<t_ifstream>;
        using t_ping          = filedatatypes::S7KPing<t_ifstream>;
        using t_ping_ptr      = std::shared_ptr<t_ping>;

        pingprocessing::datatypes::SensorConfigurationFlyweight base_sensor_configuration(
            this->configuration_data_interface().get_sensor_configuration(this->get_file_nr()));
        auto navigation_interpolator =
            this->navigation_data_interface().get_navigation_interpolator_flyweight(
                base_sensor_configuration.get().binary_hash());
        const bool navigation_is_valid = navigation_interpolator.get().valid();

        // index cache handler for this file (reads cached infos if present, collects new ones)
        S7KPingCacheHandler cache_handler(index_paths, *this);

        // group the datagrams into pings in file order (the datagram infos are indexed in file
        // order, so - like the KMALL interface - no extra sort is needed)
        std::vector<t_ping_ptr> ping_list;
        t_ping_ptr              current_ping = nullptr;

        for (const auto& datagram_info : this->_datagram_infos_all)
        {
            const bool starts_new_ping = datagram_info->get_datagram_identifier() ==
                                         t_S7KDatagramIdentifier::SonarSettings; // 7000

            if (starts_new_ping)
            {
                current_ping = std::make_shared<t_ping>();
                current_ping->set_channel_id("0"); // single channel for now (config not read yet)
                current_ping->file_data().set_primary_file_nr(this->get_file_nr());

                current_ping->set_sensor_configuration_flyweight(base_sensor_configuration);

                if (navigation_is_valid)
                    current_ping->set_navigation_interpolator_latlon(navigation_interpolator);

                ping_list.push_back(current_ping);
            }

            // records before the first SonarSettings record form an incomplete leading ping and
            // are skipped (they cannot be geolocated / calibrated consistently)
            if (current_ping != nullptr)
                current_ping->add_datagram_info(datagram_info);
        }

        // build the lightweight per-ping information early (from the index cache if available,
        // otherwise read the metadata and add it to the cache)
        t_pingcontainer pings;
        for (auto& ping_ptr : ping_list)
        {
            auto& file_data = ping_ptr->file_data();

            if (file_data.has_water_column())
                file_data.set_watercolumninformation(
                    cache_handler.read_or_get_watercolumninformation(*ping_ptr));

            if (file_data.has_raw_detection())
                file_data.set_detectioninformation(
                    cache_handler.read_or_get_detectioninformation(*ping_ptr));

            if (file_data.has_sonar_settings())
                file_data.set_systeminformation(
                    cache_handler.read_or_get_systeminformation(*ping_ptr));

            // build the (flyweighted) calibration and anything not covered above
            ping_ptr->load();

            pings.add_ping_no_reindex(ping_ptr);
        }

        cache_handler.update_index_file();

        pings.reindex();
        return pings;
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents)
    {
        tools::classhelper::ObjectPrinter printer(
            this->class_name(), float_precision, superscript_exponents);

        printer.append(t_base::__printer__(float_precision, superscript_exponents));

        printer.register_section("S7KPingDataInterfacePerFile");

        return printer;
    }

  private:
    /**
     * @brief Reads / writes the per-ping water-column, detection and system information from / to
     * the index cache, mirroring the KMALL ping cache handler. If no index cache is available the
     * information is simply (re)read from the file.
     */
    class S7KPingCacheHandler
    {
        using t_FileCache = filetemplates::datatypes::FileCache;
        using t_cache_WaterColumnInformation =
            filetemplates::datatypes::cache_structures::FilePackageCache<
                filedatatypes::_sub::WaterColumnInformation>;
        using t_cache_DetectionInformation =
            filetemplates::datatypes::cache_structures::FilePackageCache<
                filedatatypes::_sub::DetectionInformation>;
        using t_cache_SystemInformation =
            filetemplates::datatypes::cache_structures::FilePackageCache<
                filedatatypes::_sub::SystemInformation>;

        static constexpr const char* _name_wci = "FilePackageCache<S7KWaterColumnInformation_V3>";
        static constexpr const char* _name_detection =
            "FilePackageCache<S7KDetectionInformation_V2>";
        static constexpr const char* _name_sys = "FilePackageCache<S7KSystemInformation_V4>";

        bool                         _update_index = false;
        std::string                  _index_path;
        std::unique_ptr<t_FileCache> _file_cache;

        t_cache_WaterColumnInformation _buffer_watercolumninformation;
        t_cache_DetectionInformation   _buffer_detectioninformation;
        t_cache_SystemInformation      _buffer_systeminformation;

      public:
        S7KPingCacheHandler() = default;

        template<typename t_FileDataInterface>
        S7KPingCacheHandler(const std::unordered_map<std::string, std::string>& index_paths,
                            const t_FileDataInterface&                          ping_data_interface)
        {
            const auto index_file_it = index_paths.find(ping_data_interface.get_file_path());
            if (index_file_it == index_paths.end())
                return; // leave _file_cache uninitialized (no caching)

            _index_path = index_file_it->second;

            _file_cache = std::make_unique<t_FileCache>(
                t_FileCache(_index_path,
                            ping_data_interface.get_file_path(),
                            ping_data_interface.get_file_size(),
                            { _name_wci, _name_detection, _name_sys }));

            if (_file_cache->has_cache(_name_wci))
                _buffer_watercolumninformation =
                    _file_cache->get_from_cache<t_cache_WaterColumnInformation>(_name_wci);
            if (_file_cache->has_cache(_name_detection))
                _buffer_detectioninformation =
                    _file_cache->get_from_cache<t_cache_DetectionInformation>(_name_detection);
            if (_file_cache->has_cache(_name_sys))
                _buffer_systeminformation =
                    _file_cache->get_from_cache<t_cache_SystemInformation>(_name_sys);
        }

        template<typename t_ping>
        std::unique_ptr<filedatatypes::_sub::WaterColumnInformation>
        read_or_get_watercolumninformation(t_ping& ping)
        {
            const auto& datagram_info =
                ping.file_data()
                    .get_datagram_infos(t_S7KDatagramIdentifier::CompressedWaterColumnData)
                    .at(0);

            if (!_file_cache)
                return std::make_unique<filedatatypes::_sub::WaterColumnInformation>(
                    ping.file_data()
                        .template read_first_datagram<datagrams::CompressedWaterColumn, true>());

            if (_buffer_watercolumninformation.has_package(datagram_info->get_file_pos()))
                return _buffer_watercolumninformation.get_package(datagram_info->get_file_pos(),
                                                                  datagram_info->get_timestamp());

            _update_index = true;
            auto dat      = std::make_unique<filedatatypes::_sub::WaterColumnInformation>(
                ping.file_data()
                    .template read_first_datagram<datagrams::CompressedWaterColumn, true>());

            _buffer_watercolumninformation.add_package(
                datagram_info->get_file_pos(),
                datagram_info->get_timestamp(),
                std::make_unique<filedatatypes::_sub::WaterColumnInformation>(*dat));

            return dat;
        }

        template<typename t_ping>
        std::unique_ptr<filedatatypes::_sub::DetectionInformation> read_or_get_detectioninformation(
            t_ping& ping)
        {
            const auto& datagram_info =
                ping.file_data().get_datagram_infos(t_S7KDatagramIdentifier::RawDetectionData).at(0);

            if (!_file_cache)
                return std::make_unique<filedatatypes::_sub::DetectionInformation>(
                    ping.file_data().template read_first_datagram<datagrams::RawDetection>());

            if (_buffer_detectioninformation.has_package(datagram_info->get_file_pos()))
                return _buffer_detectioninformation.get_package(datagram_info->get_file_pos(),
                                                                datagram_info->get_timestamp());

            _update_index = true;
            auto dat      = std::make_unique<filedatatypes::_sub::DetectionInformation>(
                ping.file_data().template read_first_datagram<datagrams::RawDetection>());

            _buffer_detectioninformation.add_package(
                datagram_info->get_file_pos(),
                datagram_info->get_timestamp(),
                std::make_unique<filedatatypes::_sub::DetectionInformation>(*dat));

            return dat;
        }

        template<typename t_ping>
        std::unique_ptr<filedatatypes::_sub::SystemInformation> read_or_get_systeminformation(
            t_ping& ping)
        {
            const auto& datagram_info =
                ping.file_data().get_datagram_infos(t_S7KDatagramIdentifier::SonarSettings).at(0);

            if (!_file_cache)
                return std::make_unique<filedatatypes::_sub::SystemInformation>(
                    ping.file_data().build_systeminformation());

            if (_buffer_systeminformation.has_package(datagram_info->get_file_pos()))
                return _buffer_systeminformation.get_package(datagram_info->get_file_pos(),
                                                             datagram_info->get_timestamp());

            _update_index = true;
            auto dat      = std::make_unique<filedatatypes::_sub::SystemInformation>(
                ping.file_data().build_systeminformation());

            _buffer_systeminformation.add_package(
                datagram_info->get_file_pos(),
                datagram_info->get_timestamp(),
                std::make_unique<filedatatypes::_sub::SystemInformation>(*dat));

            return dat;
        }

        void update_index_file()
        {
            if (!_file_cache || !_update_index)
                return;

            _file_cache->add_to_cache(_name_wci, _buffer_watercolumninformation);
            _file_cache->add_to_cache(_name_detection, _buffer_detectioninformation);
            _file_cache->add_to_cache(_name_sys, _buffer_systeminformation);
            _file_cache->update_file(_index_path);
        }
    };
};

} // namespace filedatainterfaces
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
