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
    navigation::NavigationInterpolatorLatLon _navigation_interpolator{
        navigation::SensorConfiguration()
    };
    bool _initialized_navigation_interpolator = false;

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

    bool initialized_navigation_interpolator() const
    {
        return _initialized_navigation_interpolator;
    }
    void deinitialize() override { _initialized_navigation_interpolator = false; }
    bool initialized() const override { return _initialized_navigation_interpolator; }

    using I_FileDataInterface<t_NavigationDataInterfacePerFile>::init_from_file;
    void init_from_file(bool                                force,
                        tools::progressbars::I_ProgressBar& progress_bar,
                        bool                                external_progress_tick = false) final
    {
        auto primary_interfaces_per_file = this->per_primary_file();

        if (primary_interfaces_per_file.empty())
        {
            return;
        }

        if (!force && _initialized_navigation_interpolator)
        {
            // note: at this moment, navigation interpolator does not react if the configuration
            // changes ...
            return;
        }

        // sort primary interfaces by first time stamp (to speed up merging)
        std::sort(primary_interfaces_per_file.begin(),
                  primary_interfaces_per_file.end(),
                  [](const auto& a, const auto& b) {
                      return a->get_timestamp_first() < b->get_timestamp_first();
                  });

        // // init configuration interface
        // if (!this->_configuration_data_interface->initialized())
        // {
        //     _configuration_data_interface->init_from_file(false, progress_bar);
        // }
        bool existing_progressbar = true;

        if (!progress_bar.is_initialized())
        {
            progress_bar.init(0.,
                              double(primary_interfaces_per_file.size()),
                              fmt::format("Initializing {} from file data", this->get_name()));

            existing_progressbar = false;
        }

        primary_interfaces_per_file.front()->init_from_file(force);
        _navigation_interpolator = primary_interfaces_per_file.front()->read_navigation_data();

        for (size_t i = 1; i < primary_interfaces_per_file.size(); ++i)
        {
            progress_bar.set_postfix(fmt::format("{}/{}", i, primary_interfaces_per_file.size()));

            try
            {
                primary_interfaces_per_file[i]->init_from_file(force);
                _navigation_interpolator.merge(
                    primary_interfaces_per_file[i]->read_navigation_data());
            }
            catch (std::exception& e)
            {
                // TODO:Use logging
                fmt::print(
                    std::cerr,
                    "WARNING[{}::init_from_file]: Could not merge file navigation ({}): {}\n",
                    this->get_name(),
                    i,
                    e.what());
            }
            if (!existing_progressbar || external_progress_tick)
                progress_bar.tick();
        }

        _initialized_navigation_interpolator = true;
        if (!existing_progressbar)
            progress_bar.close(std::string("Done"));
    }

    navigation::NavigationInterpolatorLatLon& get_navigation_data()
    {
        return _navigation_interpolator;
    }

    navigation::datastructures::GeoLocationLatLon get_geolocation(const std::string& target_id,
                                                                  double             timestamp)
    {
        return _navigation_interpolator(target_id, timestamp);
    }

    navigation::datastructures::SensorDataLatLon get_sensor_data(double timestamp)
    {
        return _navigation_interpolator.get_sensor_data(timestamp);
    }

    void set_sensor_configuration(const navigation::SensorConfiguration& sensor_configuration)
    {
        _navigation_interpolator.set_sensor_configuration(sensor_configuration);
    }

    const navigation::SensorConfiguration& get_sensor_configuration() const
    {
        return _navigation_interpolator.get_sensor_configuration();
    }

    std::vector<std::string_view> channel_ids() const
    {
        return _navigation_interpolator.get_sensor_configuration().get_target_ids();
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
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        printer.register_section("FileData");
        printer.append(t_base::__printer__(float_precision));

        printer.register_section("NavigationDataInterface");

        return printer;
    }

    // -- class helper function macros --
    // define info_string and print functions (needs the __printer__ function)
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping