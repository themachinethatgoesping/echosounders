// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/i_navigationdatainterface.doc.hpp"

/* std includes */
#include <filesystem>
#include <fstream>
#include <unordered_map>
#include <vector>

#include <fmt/core.h>

// xtensor includes
#include <xtensor/xadapt.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools/pyhelper/pyindexer.hpp>

#include "i_configurationdatainterface.hpp"
#include "i_datagraminterface.hpp"
#include "i_filedatainterface.hpp"
#include "i_navigationdatainterfaceperfile.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datainterfaces {

template<typename t_NavigationDataInterfacePerFile>
class I_NavigationDataInterface : public I_FileDataInterface<t_NavigationDataInterfacePerFile>
{
    using t_base = I_FileDataInterface<t_NavigationDataInterfacePerFile>;

  public:
    using type_ConfigurationDataInterface =
        typename t_NavigationDataInterfacePerFile::type_ConfigurationDataInterface;

  protected:
    std::unordered_map<navigation::SensorConfiguration, navigation::NavigationInterpolatorLatLon>
         _navigation_interpolators;
    bool _is_initialized_navigation_interpolators = false;

    std::shared_ptr<type_ConfigurationDataInterface> _configuration_data_interface;

  public:
    I_NavigationDataInterface(
        std::shared_ptr<type_ConfigurationDataInterface> configuration_data_interface,
        std::string_view                                 name = "I_NavigationDataInterface")
        : t_base(name)
        , _configuration_data_interface(configuration_data_interface)
    {
    }
    virtual ~I_NavigationDataInterface() = default;

    type_ConfigurationDataInterface& configuration_data_interface()
    {
        return *_configuration_data_interface;
    }
    const type_ConfigurationDataInterface& configuration_data_interface_const() const
    {
        return *_configuration_data_interface;
    }

    bool is_initialized_navigation_interpolator() const
    {
        return _is_initialized_navigation_interpolators;
    }
    void deinitialize() override { _is_initialized_navigation_interpolators = false; }
    bool is_initialized() const override { return _is_initialized_navigation_interpolators; }

    std::unordered_map<std::string, navigation::NavigationInterpolatorLatLon> get_navigation_cache(
        bool show_progress = true)
    {
        tools::progressbars::ProgressBarChooser progress_bar(show_progress);
        return this->get_navigation_cache(progress_bar.get());
    }

    std::unordered_map<std::string, navigation::NavigationInterpolatorLatLon> get_navigation_cache(
        tools::progressbars::I_ProgressBar& progress_bar,
        bool                                external_progress_tick = false)
    {
        auto interfaces_per_file        = this->per_file();
        auto config_interfaces_per_file = this->_configuration_data_interface->per_file();
        std::unordered_map<std::string, navigation::NavigationInterpolatorLatLon> cache_per_file;

        bool existing_progressbar = true;

        if (!progress_bar.is_initialized())
        {
            progress_bar.init(
                0.,
                double(interfaces_per_file.size()),
                fmt::format("Creating navigation cache from files", this->class_name()));

            existing_progressbar = false;
        }

        for (size_t i = 0; i < interfaces_per_file.size(); ++i)
        {
            progress_bar.set_postfix(fmt::format("{}/{}", i, interfaces_per_file.size()));

            if (!config_interfaces_per_file[i]->is_initialized())
            {
                config_interfaces_per_file[i]->init_from_file();
            }

            cache_per_file[interfaces_per_file[i]->get_file_path()] =
                interfaces_per_file[i]->read_navigation_data();

            if (!existing_progressbar || external_progress_tick)
                progress_bar.tick();
        }

        if (!existing_progressbar)
            progress_bar.close(std::string("Done"));

        return cache_per_file;
    }

    using I_FileDataInterface<t_NavigationDataInterfacePerFile>::init_from_file;
    void init_from_file(
        const std::unordered_map<std::string, std::string>& cached_paths_per_file_path,
        bool                                                force,
        tools::progressbars::I_ProgressBar&                 progress_bar,
        bool                                                external_progress_tick = false) final
    {
        init_from_file_or_cache(
            cached_paths_per_file_path, {}, force, progress_bar, external_progress_tick);
    }

    void init_from_file_or_cache(
        const std::unordered_map<std::string, std::string>& cached_paths_per_file_path,
        const std::unordered_map<std::string, navigation::NavigationInterpolatorLatLon>& cache = {},
        bool force         = false,
        bool show_progress = true)
    {
        tools::progressbars::ProgressBarChooser progress_bar(show_progress);
        this->init_from_file_or_cache(cached_paths_per_file_path, cache, force, progress_bar.get());
    }

    void init_from_file_or_cache(
        const std::unordered_map<std::string, std::string>& cached_paths_per_file_path,
        const std::unordered_map<std::string, navigation::NavigationInterpolatorLatLon>& cache,
        bool                                                                             force,
        tools::progressbars::I_ProgressBar& progress_bar,
        bool                                external_progress_tick = false)
    {
        // navigation data interface needs configuraiton data interface to be initialized
        if (!this->_configuration_data_interface->is_initialized())
        {
            this->_configuration_data_interface->init_from_file(
                cached_paths_per_file_path, false, progress_bar);
        }

        auto primary_interfaces_per_file = this->per_primary_file();

        if (primary_interfaces_per_file.empty())
        {
            return;
        }

        if (!force && _is_initialized_navigation_interpolators)
        {
            // note: at this moment, navigation interpolator does not react if the configuration
            // changes ...
            return;
        }

        _navigation_interpolators.clear();

        // sort primary interfaces by first time stamp (to speed up merging)
        std::sort(primary_interfaces_per_file.begin(),
                  primary_interfaces_per_file.end(),
                  [](const auto& a, const auto& b) {
                      return a->get_timestamp_first() < b->get_timestamp_first();
                  });

        // // init configuration interface
        // if (!this->_configuration_data_interface->is_initialized())
        // {
        //     _configuration_data_interface->init_from_file(false, progress_bar);
        // }
        bool existing_progressbar = true;

        if (!progress_bar.is_initialized())
        {
            progress_bar.init(0.,
                              double(primary_interfaces_per_file.size()),
                              fmt::format("Initializing {} from file data", this->class_name()));

            existing_progressbar = false;
        }

        for (size_t i = 0; i < primary_interfaces_per_file.size(); ++i)
        {
            progress_bar.set_postfix(fmt::format("{}/{}", i, primary_interfaces_per_file.size()));

            try
            {
                const auto& sensor_configuration =
                    _configuration_data_interface->get_sensor_configuration(
                        primary_interfaces_per_file[i]->get_file_nr());

                auto it = _navigation_interpolators.find(sensor_configuration);
                if (it == _navigation_interpolators.end())
                {
                    _navigation_interpolators[sensor_configuration] =
                        read_or_from_cache(*primary_interfaces_per_file[i], cache);
                }
                else
                {
                    it->second.merge(read_or_from_cache(*primary_interfaces_per_file[i], cache));
                }
            }
            catch (std::exception& e)
            {
                // TODO: compare files with checksum to avoid loading duplicates

                // TODO:Use logging
                fmt::print(std::cerr,
                           "WARNING[{}::init_from_file]: Could not merge file navigation ({}) "
                           "because: {}\n",
                           this->class_name(),
                           primary_interfaces_per_file[i]->get_file_nr(),
                           e.what());
            }
            if (!existing_progressbar || external_progress_tick)
                progress_bar.tick();
        }

        _is_initialized_navigation_interpolators = true;
        if (!existing_progressbar)
            progress_bar.close(std::string("Done"));
    }

    auto& get_navigation_interpolators() { return _navigation_interpolators; }

    auto& get_navigation_interpolator(const navigation::SensorConfiguration& sensor_configuration)
    {
        return _navigation_interpolators.at(sensor_configuration);
    }

    navigation::datastructures::GeolocationLatLon get_geolocation(
        const navigation::SensorConfiguration& sensor_configuration,
        const std::string&                     target_id,
        double                                 timestamp)
    {
        return _navigation_interpolators.at(sensor_configuration)(target_id, timestamp);
    }

    navigation::datastructures::SensordataLatLon get_sensor_data(
        const navigation::SensorConfiguration& sensor_configuration,
        double                                 timestamp)
    {
        return _navigation_interpolators.at(sensor_configuration).get_sensor_data(timestamp);
    }

    std::vector<std::string> channel_ids() const
    {
        std::vector<std::string> channel_ids;

        for (const auto& [sensor_configuration, navigation_interpolator] :
             _navigation_interpolators)
        {
            for (const auto& target_id :
                 navigation_interpolator.get_sensor_configuration().get_target_ids())
            {
                channel_ids.push_back(target_id);
            }
        }

        return channel_ids;
    }

    std::vector<std::string> channel_ids(
        const navigation::SensorConfiguration& sensor_configuration) const
    {
        return _navigation_interpolators.at(sensor_configuration)
            .get_sensor_configuration()
            .get_target_ids();
    }

    // ----- old -----

    void add_file_interface(size_t file_nr) final
    {
        if (file_nr >= this->_interface_per_file.size())
        {
            this->_configuration_data_interface->add_file_interface(file_nr);

            this->_interface_per_file.reserve(file_nr + 1);

            for (size_t i = this->_interface_per_file.size(); i <= file_nr; ++i)
            {
                this->_interface_per_file.push_back(
                    std::make_shared<t_NavigationDataInterfacePerFile>(
                        this->_configuration_data_interface));
            }
            this->_pyindexer.reset(this->_interface_per_file.size());
        }
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision)
    {
        tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision);

        printer.register_section("FileData");
        printer.append(t_base::__printer__(float_precision));

        printer.register_section("NavigationDataInterface");

        return printer;
    }

    // -- class helper function macros --
    // define info_string and print functions (needs the __printer__ function)
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__

  private:
    navigation::NavigationInterpolatorLatLon read_or_from_cache(
        t_NavigationDataInterfacePerFile& navigation_data_interface_per_file,
        const std::unordered_map<std::string, navigation::NavigationInterpolatorLatLon>& cache)
    {
        auto cache_it = cache.find(navigation_data_interface_per_file.get_file_path());

        if (cache_it == cache.end())
        {
            return navigation_data_interface_per_file.read_navigation_data();
        }
        else
        {
            return cache_it->second;
        }
    }
};

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping