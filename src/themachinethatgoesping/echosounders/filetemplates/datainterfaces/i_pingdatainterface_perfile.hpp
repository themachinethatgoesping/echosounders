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

#include "i_datagraminterface.hpp"
#include "i_environmentdatainterface.hpp"
#include "i_filedatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datainterfaces {

// TODO: this should be a c++20 concept
template<typename t_EnvironmentDataInterface, typename t_PingContainer>
class I_PingDataInterface_PerFile
    : public I_FileDataInterface_PerFile<typename t_EnvironmentDataInterface::type_DatagramInterface>
{
    using t_datagraminterface = typename t_EnvironmentDataInterface::type_DatagramInterface;
    using t_base              = I_FileDataInterface_PerFile<t_datagraminterface>;

  public:
    // member types
    using type_EnvironmentDataInterface = t_EnvironmentDataInterface;
    using type_NavigationDataInterface =
        typename t_EnvironmentDataInterface::type_NavigationDataInterface;
    using type_ConfigurationDataInterface =
        typename t_EnvironmentDataInterface::type_ConfigurationDataInterface;
    using type_PingContainer = t_PingContainer;
    using type_Ping          = typename t_PingContainer::type_Ping;

  protected:
    std::shared_ptr<t_EnvironmentDataInterface> _environment_data_interface;

  public:
    I_PingDataInterface_PerFile(std::string_view name = "I_PingDataInterface_PerFile")
        : t_base(name)
    {
        throw std::runtime_error(
            fmt::format("I_PingDataInterface_PerFile({}): cannot be initialized without "
                        "existing configuration_data_interface",
                        this->get_name()));
    }

    I_PingDataInterface_PerFile(
        std::shared_ptr<t_EnvironmentDataInterface> environment_data_interface,
        std::string_view                            name = "I_PingDataInterface_PerFile")
        : t_base(name)
        , _environment_data_interface(environment_data_interface)
    {
    }
    virtual ~I_PingDataInterface_PerFile() = default;

    type_ConfigurationDataInterface& configuration_data_interface()
    {
        return _environment_data_interface->configuration_data_interface();
    }
    const type_ConfigurationDataInterface& configuration_data_interface_const() const
    {
        return _environment_data_interface->configuration_data_interface_const();
    }
    type_NavigationDataInterface& navigation_data_interface()
    {
        return _environment_data_interface->navigation_data_interface();
    }
    const type_NavigationDataInterface& navigation_data_interface_Const() const
    {
        return _environment_data_interface->navigation_data_interface_const();
    }

    type_EnvironmentDataInterface& environment_data_interface()
    {
        return *_environment_data_interface;
    }
    const type_EnvironmentDataInterface& environment_data_interface_const() const
    {
        return *_environment_data_interface;
    }

    virtual t_PingContainer read_pings()
    {
        throw std::runtime_error(fmt::format("I_PingDataInterface_PerFile({}): read_ping_data() not "
                                             "implemented",
                                             this->get_name()));
    }

    void init_from_file([[maybe_unused]] bool force = false) final { return; }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision));

        printer.register_section("PingDataInterface_PerFile");
        return printer;
    }
};
// void add_datagram(datatypes::DatagramInfo_ptr<t_Datagram

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping