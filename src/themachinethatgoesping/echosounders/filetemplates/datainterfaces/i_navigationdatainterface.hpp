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

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools/pyhelper/pyindexer.hpp>

#include "../datatypes/filecache.hpp"
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
    std::unordered_map<uint64_t, navigation::NavigationInterpolatorLatLon>
         _navigation_interpolators; // per sensor configuration hash
    bool _is_initialized_navigation_interpolators = false;

    std::weak_ptr<type_ConfigurationDataInterface> _configuration_data_interface;

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
        return *_configuration_data_interface.lock();
    }
    const type_ConfigurationDataInterface& configuration_data_interface_const() const
    {
        return *_configuration_data_interface.lock();
    }

    bool is_initialized_navigation_interpolator() const
    {
        return _is_initialized_navigation_interpolators;
    }
    void deinitialize() override { _is_initialized_navigation_interpolators = false; }
    bool is_initialized() const override { return _is_initialized_navigation_interpolators; }

    using I_FileDataInterface<t_NavigationDataInterfacePerFile>::init_from_file;
    void init_from_file(const std::unordered_map<std::string, std::string>& file_cache_paths,
                        bool                                                force,
                        tools::progressbars::I_ProgressBar&                 progress_bar,
                        bool external_progress_tick = false) final
    {
        // navigation data interface needs configuraiton data interface to be initialized
        if (!this->_configuration_data_interface.lock()->is_initialized())
        {
            this->_configuration_data_interface.lock()->init_from_file(
                file_cache_paths, false, progress_bar);
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
                auto navigation_interpolator = read_navigation_from_file_or_cache(
                    *primary_interfaces_per_file[i], file_cache_paths);

                // Update sensor configuration with configuration data interface
                // this is necessary since the configuration data interface might have been updated
                // since the navigation data was cached
                navigation_interpolator.set_sensor_configuration(
                    this->_configuration_data_interface.lock()->get_sensor_configuration(
                        primary_interfaces_per_file[i]->get_file_nr()));

                auto sensor_configuration_hash =
                    navigation_interpolator.get_sensor_configuration().binary_hash();

                auto it = _navigation_interpolators.find(sensor_configuration_hash);
                if (it == _navigation_interpolators.end())
                {
                    /// TODO: move to avoid copy?
                    _navigation_interpolators[sensor_configuration_hash] = navigation_interpolator;
                }
                else
                {
                    /// TODO: move to avoid copy?
                    it->second.merge(navigation_interpolator);
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

    bool has_navigation_interpolator(uint64_t sensor_configuration_hash) const
    {
        return _navigation_interpolators.contains(sensor_configuration_hash);
    }

    auto& get_navigation_interpolator(uint64_t sensor_configuration_hash)
    {
        auto it = _navigation_interpolators.find(sensor_configuration_hash);

        if (it == _navigation_interpolators.end())
        {
            throw std::runtime_error(
                fmt::format("NavigationInterpolator for sensor configuration {} not found",
                            sensor_configuration_hash));
        }

        return it->second;
    }

    std::vector<std::string> get_channel_ids() const
    {
        std::vector<std::string> channel_ids;

        for (const auto& [sensor_configuration_hash, navigation_interpolator] :
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

    std::vector<std::string> get_channel_ids(uint64_t sensor_configuration_hash) const
    {
        return _navigation_interpolators.at(sensor_configuration_hash)
            .get_sensor_configuration()
            .get_target_ids();
    }

    // ----- old -----

    void add_file_interface(size_t file_nr) final
    {
        if (file_nr >= this->_interface_per_file.size())
        {
            this->_configuration_data_interface.lock()->add_file_interface(file_nr);

            this->_interface_per_file.reserve(file_nr + 1);

            for (size_t i = this->_interface_per_file.size(); i <= file_nr; ++i)
            {
                this->_interface_per_file.push_back(
                    std::make_shared<t_NavigationDataInterfacePerFile>(
                        this->_configuration_data_interface.lock()));
            }
            this->_pyindexer.reset(this->_interface_per_file.size());
        }
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents)
    {
        tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision, superscript_exponents);

        printer.register_section("FileData");
        printer.append(t_base::__printer__(float_precision, superscript_exponents));

        printer.register_section("NavigationDataInterface");

        return printer;
    }

    // -- class helper function macros --
    // define info_string and print functions (needs the __printer__ function)
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__

  private:
    navigation::NavigationInterpolatorLatLon read_navigation_from_file_or_cache(
        t_NavigationDataInterfacePerFile&                   navigation_data_interface_per_file,
        const std::unordered_map<std::string, std::string>& cache_file_paths)
    {
        auto cache_it = cache_file_paths.find(navigation_data_interface_per_file.get_file_path());

        // if file is not in cache, read navigation data from file and return
        if (cache_it == cache_file_paths.end())
            return navigation_data_interface_per_file.read_navigation_data();

        // open file_cache
        datatypes::FileCache file_cache(cache_it->second,
                                        navigation_data_interface_per_file.get_file_path(),
                                        navigation_data_interface_per_file.get_file_size(),
                                        { "NavigationInterpolatorLatLon_packdev3" });

        // if navigation interpolator is in cache, return it
        if (file_cache.has_cache("NavigationInterpolatorLatLon_packdev3"))
            try
            {
                return file_cache.get_from_cache<navigation::NavigationInterpolatorLatLon>(
                    "NavigationInterpolatorLatLon_packdev3");
            }
            catch (std::exception& e)
            {
                fmt::print(
                    std::cerr,
                    "WARNING[{}::read_navigation_from_file_or_cache]: Could not read navigation "
                    "interpolator from cache ({}) because: {}\n",
                    this->class_name(),
                    cache_it->second,
                    e.what());
            }

        // read navigation interpolator from file
        auto navigation_interpolator = navigation_data_interface_per_file.read_navigation_data();

        // cache navigation interpolator
        file_cache.add_to_cache("NavigationInterpolatorLatLon_packdev3", navigation_interpolator);
        file_cache.update_file(cache_it->second);

        return navigation_interpolator;
    }
};

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping