// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/i_navigationdatainterfaceperfile.doc.hpp"

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
template<typename t_ConfigurationDataInterface>
class I_NavigationDataInterfacePerFile
    : public I_FileDataInterfacePerFile<
          typename t_ConfigurationDataInterface::type_DatagramInterface>
{
    using t_datagraminterface = typename t_ConfigurationDataInterface::type_DatagramInterface;
    using t_base              = I_FileDataInterfacePerFile<t_datagraminterface>;

  public:
    // member types
    using type_ConfigurationDataInterface = t_ConfigurationDataInterface;

  protected:
    std::shared_ptr<type_ConfigurationDataInterface> _configuration_data_interface;

  public:
    I_NavigationDataInterfacePerFile(std::string_view name = "I_NavigationDataInterfacePerFile")
        : t_base(name)
    {
        throw std::runtime_error(
            fmt::format("I_NavigationDataInterfacePerFile({}): cannot be initialized without "
                        "existing configuration_data_interface",
                        this->get_name()));
    }

    I_NavigationDataInterfacePerFile(
        std::shared_ptr<type_ConfigurationDataInterface> configuration_data_interface,
        std::string_view                                 name = "I_NavigationDataInterfacePerFile")
        : t_base(name)
        , _configuration_data_interface(configuration_data_interface)
    {
    }
    virtual ~I_NavigationDataInterfacePerFile() = default;

    type_ConfigurationDataInterface& configuration_data_interface()
    {
        return *_configuration_data_interface;
    }
    const type_ConfigurationDataInterface& configuration_data_interface_const() const
    {
        return *_configuration_data_interface;
    }

    virtual navigation::NavigationInterpolatorLatLon read_navigation_data() const
    {
        throw std::runtime_error(
            fmt::format("I_NavigationDataInterfacePerFile({}): read_navigation_data() not "
                        "implemented",
                        this->get_name()));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision));

        printer.register_section("NavigationDataInterfacePerFile");
        return printer;
    }
};
// void add_datagram(datatypes::DatagramInfo_ptr<t_Datagram

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping