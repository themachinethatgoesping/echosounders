// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/i_environmentdatainterface_perfile.doc.hpp"

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
namespace filetemplates {
namespace datainterfaces {

// TODO: this should be a c++20 concept
template<typename t_NavigationDataInterface>
class I_EnvironmentDataInterface_PerFile
    : public I_FileDataInterface_PerFile<typename t_NavigationDataInterface::type_DatagramInterface>
{
    using t_datagraminterface = typename t_NavigationDataInterface::type_DatagramInterface;
    using t_base              = I_FileDataInterface_PerFile<t_datagraminterface>;

  public:
    // member types
    using type_NavigationDataInterface = t_NavigationDataInterface;
    using type_ConfigurationDataInterface =
        typename t_NavigationDataInterface::type_ConfigurationDataInterface;

  protected:
    std::shared_ptr<t_NavigationDataInterface> _navigation_data_interface;

  public:
    I_EnvironmentDataInterface_PerFile(std::string_view name = "I_EnvironmentDataInterface_PerFile")
        : t_base(name)
    {
        throw std::runtime_error(
            fmt::format("I_EnvironmentDataInterface_PerFile({}): cannot be initialized without "
                        "existing configuration_data_interface",
                        this->get_name()));
    }

    I_EnvironmentDataInterface_PerFile(
        std::shared_ptr<t_NavigationDataInterface> navigation_data_interface,
        std::string_view                           name = "I_EnvironmentDataInterface_PerFile")
        : t_base(name)
        , _navigation_data_interface(navigation_data_interface)
    {
    }
    virtual ~I_EnvironmentDataInterface_PerFile() = default;

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
    //         fmt::format("I_EnvironmentDataInterface_PerFile({}): read_environment_data() not "
    //                     "implemented",
    //                     this->get_name()));
    // }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision));

        printer.register_section("EnvironmentDataInterface_PerFile");
        return printer;
    }
};
// void add_datagram(datatypes::DatagramInfo_ptr<t_Datagram

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping