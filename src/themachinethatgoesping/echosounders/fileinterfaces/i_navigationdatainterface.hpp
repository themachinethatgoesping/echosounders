// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

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

namespace themachinethatgoesping {
namespace echosounders {
namespace fileinterfaces {

// TODO: this should be a c++20 concept
template<typename t_datagraminterface, typename t_ConfigurationPerFileDataInterface>
class I_NavigationPerFileDataInterface : public I_PerFileDataInterface<t_datagraminterface>
{
    using t_base = I_PerFileDataInterface<t_datagraminterface>;

  protected:
    std::shared_ptr<t_ConfigurationPerFileDataInterface> _configuration_data_interface;

    navigation::NavigationInterpolatorLatLon _navigation_interpolator{
        navigation::SensorConfiguration()
    };

  public:
    I_NavigationPerFileDataInterface(std::string_view name = "I_NavigationPerFileDataInterface")
        : t_base(name)
    {
        throw std::runtime_error(
            fmt::format("I_NavigationPerFileDataInterface({}): cannot be initialized without "
                        "existing configuration_data_interface",
                        this->get_name()));
    }

    I_NavigationPerFileDataInterface(
        std::shared_ptr<t_ConfigurationPerFileDataInterface> configuration_data_interface,
        std::string_view name = "I_NavigationPerFileDataInterface")
        : t_base(name)
        , _configuration_data_interface(configuration_data_interface)
    {
    }
    virtual ~I_NavigationPerFileDataInterface() = default;

    t_ConfigurationPerFileDataInterface& get_configuration_data_interface() const
    {
        return *_configuration_data_interface;
    }

    virtual navigation::NavigationInterpolatorLatLon read_navigation_data() const
    {
        throw std::runtime_error(
            fmt::format("I_NavigationPerFileDataInterface({}): read_navigation_data() not "
                        "implemented",
                        this->get_name()));
    }

    void update_configuration()
    {
        _navigation_interpolator.set_sensor_configuration(
            _configuration_data_interface->get_sensor_configuration());
    }

    navigation::NavigationInterpolatorLatLon& get_navigation_data()
    {
        return _navigation_interpolator;
    }
    void set_navigation_data(navigation::NavigationInterpolatorLatLon navigation_interpolator)
    {
        _navigation_interpolator = std::move(navigation_interpolator);
    }

    void init_from_file() final
    {
        try
        {
            _navigation_interpolator = this->read_navigation_data();
        }
        catch (std::exception& e)
        {
            std::cerr << fmt::format(
                             "Warning[init_from_file]: Could not read navigation data from file. "
                             "Error was: {}",
                             e.what())
                      << std::endl;
        }
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision));

        printer.register_section("NavigationPerFileDataInterface");
        return printer;
    }
};
// void add_datagram(DatagramInfo_ptr<t_Datagram

template<typename t_NavigationPerFileDataInterface, typename t_ConfigurationDataInterface>
class I_NavigationDataInterface : public I_FileDataInterface<t_NavigationPerFileDataInterface>
{
    using t_base = I_FileDataInterface<t_NavigationPerFileDataInterface>;

  protected:
    std::shared_ptr<t_ConfigurationDataInterface> _configuration_data_interface;

  public:
    I_NavigationDataInterface(
        std::shared_ptr<t_ConfigurationDataInterface> configuration_data_interface,
        std::string_view                              name = "I_NavigationDataInterface")
        : t_base(name)
        , _configuration_data_interface(configuration_data_interface)
    {
    }
    virtual ~I_NavigationDataInterface() = default;

    t_ConfigurationDataInterface& get_configuration_data_interface() const
    {
        return *_configuration_data_interface;
    }

    void add_file_interface(size_t file_nr) final
    {
        if (file_nr >= this->_interface_per_file.size())
        {
            this->_configuration_data_interface->add_file_interface(file_nr);

            this->_interface_per_file.reserve(file_nr + 1);

            for (size_t i = this->_interface_per_file.size(); i <= file_nr; ++i)
            {
                this->_interface_per_file.push_back(
                    std::make_shared<t_NavigationPerFileDataInterface>(
                        this->_configuration_data_interface->per_file_ptr(i)));
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

} // namespace fileinterfaces
} // namespace echosounders
} // namespace themachinethatgoesping