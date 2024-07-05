// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/i_pingdatainterfaceperfile.doc.hpp"

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

#include "i_datagraminterface.hpp"
#include "i_environmentdatainterface.hpp"
#include "i_filedatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datainterfaces {

// TODO: this should be a c++20 concept
template<typename t_EnvironmentDataInterface, typename t_PingContainer>
class I_PingDataInterfacePerFile
    : public I_FileDataInterfacePerFile<typename t_EnvironmentDataInterface::type_DatagramInterface>
{
    using t_datagraminterface = typename t_EnvironmentDataInterface::type_DatagramInterface;
    using t_base              = I_FileDataInterfacePerFile<t_datagraminterface>;

  public:
    // member types
    using type_EnvironmentDataInterface = t_EnvironmentDataInterface;
    using type_NavigationDataInterface =
        typename t_EnvironmentDataInterface::type_NavigationDataInterface;
    using type_ConfigurationDataInterface =
        typename t_EnvironmentDataInterface::type_ConfigurationDataInterface;
    using type_ConfigurationDataInterfacePerFile = typename t_EnvironmentDataInterface::
        type_ConfigurationDataInterface::type_FileDataInterface_PerFile;
    using type_PingContainer = t_PingContainer;
    using type_Ping          = typename t_PingContainer::type_Ping;

  protected:
    std::weak_ptr<t_EnvironmentDataInterface> _environment_data_interface;

  public:
    I_PingDataInterfacePerFile(std::string_view name = "I_PingDataInterfacePerFile")
        : t_base(name)
    {
        throw std::runtime_error(
            fmt::format("I_PingDataInterfacePerFile({}): cannot be is_initialized without "
                        "existing configuration_data_interface",
                        this->class_name()));
    }

    I_PingDataInterfacePerFile(
        std::shared_ptr<t_EnvironmentDataInterface> environment_data_interface,
        std::string_view                            name = "I_PingDataInterfacePerFile")
        : t_base(name)
        , _environment_data_interface(environment_data_interface)
    {
    }
    virtual ~I_PingDataInterfacePerFile() = default;

    type_ConfigurationDataInterface& configuration_data_interface()
    {
        return _environment_data_interface.lock()->configuration_data_interface();
    }
    const type_ConfigurationDataInterface& configuration_data_interface_const() const
    {
        return _environment_data_interface.lock()->configuration_data_interface_const();
    }
    type_NavigationDataInterface& navigation_data_interface()
    {
        return _environment_data_interface.lock()->navigation_data_interface();
    }
    const type_NavigationDataInterface& navigation_data_interface_Const() const
    {
        return _environment_data_interface.lock()->navigation_data_interface_const();
    }
    type_EnvironmentDataInterface& environment_data_interface()
    {
        return *_environment_data_interface.lock();
    }
    const type_EnvironmentDataInterface& environment_data_interface_const() const
    {
        return *_environment_data_interface.lock();
    }

    type_ConfigurationDataInterfacePerFile& configuration_data_interface_for_file()
    {
        return _environment_data_interface.lock()->configuration_data_interface().per_file(
            this->get_file_nr());
    }
    const type_ConfigurationDataInterfacePerFile& configuration_data_interface_for_file_const()
        const
    {
        return _environment_data_interface.lock()->configuration_data_interface_const().per_file_const(
            this->get_file_nr());
    }

    virtual t_PingContainer read_pings(
        [[maybe_unused]] const std::unordered_map<std::string, std::string>& file_cache_paths =
            std::unordered_map<std::string, std::string>())
    {
        throw std::runtime_error(fmt::format("I_PingDataInterfacePerFile({}): read_ping_data() not "
                                             "implemented",
                                             this->class_name()));
    }

    void init_from_file([[maybe_unused]] const std::string& file_cache_path,
                        [[maybe_unused]] bool               force = false) final
    {
        return;
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision));

        printer.register_section("PingDataInterfacePerFile");
        return printer;
    }
};
// void add_datagram(datatypes::DatagramInfo_ptr<t_Datagram

}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping