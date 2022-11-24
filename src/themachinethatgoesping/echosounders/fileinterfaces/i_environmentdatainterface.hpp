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
template<typename t_NavigationDataInterface>
class I_EnvironmentPerFileDataInterface
    : public I_PerFileDataInterface<typename t_NavigationDataInterface::type_DatagramInterface>
{
    using t_datagraminterface = typename t_NavigationDataInterface::type_DatagramInterface;
    using t_base              = I_PerFileDataInterface<t_datagraminterface>;

  public:
    // member types
    using type_NavigationDataInterface = t_NavigationDataInterface;
    using type_ConfigurationDataInterface =
        typename t_NavigationDataInterface::type_ConfigurationDataInterface;

  protected:
    std::shared_ptr<t_NavigationDataInterface> _navigation_data_interface;

  public:
    I_EnvironmentPerFileDataInterface(std::string_view name = "I_EnvironmentPerFileDataInterface")
        : t_base(name)
    {
        throw std::runtime_error(
            fmt::format("I_EnvironmentPerFileDataInterface({}): cannot be initialized without "
                        "existing configuration_data_interface",
                        this->get_name()));
    }

    I_EnvironmentPerFileDataInterface(
        std::shared_ptr<t_NavigationDataInterface> navigation_data_interface,
        std::string_view                           name = "I_EnvironmentPerFileDataInterface")
        : t_base(name)
        , _navigation_data_interface(navigation_data_interface)
    {
    }
    virtual ~I_EnvironmentPerFileDataInterface() = default;

    type_ConfigurationDataInterface& configuration_data_interface()
    {
        return _navigation_data_interface->configuration_data_interface();
    }
    const type_ConfigurationDataInterface& configuration_data_interface_const() const
    {
        return _navigation_data_interface->configuration_data_interface_const();
    }

    type_NavigationDataInterface& navigation_data_interface()
    {
        return *_navigation_data_interface;
    }
    const type_NavigationDataInterface& navigation_data_interface_const() const
    {
        return *_navigation_data_interface;
    }

    // virtual environment::EnvironmentInterpolatorLatLon read_environment_data() const
    // {
    //     throw std::runtime_error(
    //         fmt::format("I_EnvironmentPerFileDataInterface({}): read_environment_data() not "
    //                     "implemented",
    //                     this->get_name()));
    // }

    void init_from_file() final { return; }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision));

        printer.register_section("EnvironmentPerFileDataInterface");
        return printer;
    }
};
// void add_datagram(DatagramInfo_ptr<t_Datagram

template<typename t_EnvironmentPerFileDataInterface>
class I_EnvironmentDataInterface : public I_FileDataInterface<t_EnvironmentPerFileDataInterface>
{
    using t_base = I_FileDataInterface<t_EnvironmentPerFileDataInterface>;

  public:
    using type_ConfigurationDataInterface =
        typename t_EnvironmentPerFileDataInterface::type_ConfigurationDataInterface;
    using type_NavigationDataInterface =
        typename t_EnvironmentPerFileDataInterface::type_NavigationDataInterface;

  protected:
    // environment::EnvironmentInterpolatorLatLon _environment_interpolator{
    //     environment::SensorConfiguration()
    // };

    std::shared_ptr<type_NavigationDataInterface> _navigation_data_interface;

  public:
    I_EnvironmentDataInterface(
        std::shared_ptr<type_NavigationDataInterface> navigation_data_interface,
        std::string_view                              name = "I_EnvironmentDataInterface")
        : t_base(name)
        , _navigation_data_interface(navigation_data_interface)
    {
    }
    virtual ~I_EnvironmentDataInterface() = default;

    type_ConfigurationDataInterface& configuration_data_interface()
    {
        return _navigation_data_interface->configuration_data_interface();
    }
    const type_ConfigurationDataInterface& configuration_data_interface_const() const
    {
        return _navigation_data_interface->configuration_data_interface_const();
    }

    type_NavigationDataInterface& navigation_data_interface()
    {
        return *_navigation_data_interface;
    }
    const type_NavigationDataInterface& navigation_data_interface_const() const
    {
        return *_navigation_data_interface;
    }

    using I_FileDataInterface<t_EnvironmentPerFileDataInterface>::init_from_file;

    // environment::EnvironmentInterpolatorLatLon& get_environment_data()
    // {
    //     return _environment_interpolator;
    // }

    // ----- old -----

    void add_file_interface(size_t file_nr) final
    {
        if (file_nr >= this->_interface_per_file.size())
        {
            this->_navigation_data_interface->add_file_interface(file_nr);

            this->_interface_per_file.reserve(file_nr + 1);

            for (size_t i = this->_interface_per_file.size(); i <= file_nr; ++i)
            {
                this->_interface_per_file.push_back(
                    std::make_shared<t_EnvironmentPerFileDataInterface>(
                        this->_navigation_data_interface));
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

        printer.register_section("EnvironmentDataInterface");

        return printer;
    }

    // -- class helper function macros --
    // define info_string and print functions (needs the __printer__ function)
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};

} // namespace fileinterfaces
} // namespace echosounders
} // namespace themachinethatgoesping