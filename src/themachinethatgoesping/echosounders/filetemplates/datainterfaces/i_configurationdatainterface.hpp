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

/* themachinethatgoesping navigation includes */
#include <themachinethatgoesping/navigation/sensorconfiguration.hpp>

#include "i_configurationdatainterface_perfile.hpp"
#include "i_datagraminterface.hpp"
#include "i_filedatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datainterfaces {


template<typename t_configurationdatagraminterface>
class I_ConfigurationDataInterface : public I_FileDataInterface<t_configurationdatagraminterface>
{
    using t_base = I_FileDataInterface<t_configurationdatagraminterface>;

  public:
    I_ConfigurationDataInterface(std::string_view name = "I_ConfigurationDataInterface")
        : t_base(name)
    {
    }
    virtual ~I_ConfigurationDataInterface() = default;

    const navigation::SensorConfiguration& get_sensor_configuration(long pyindex) const
    {
        return this->per_file_const(pyindex).get_sensor_configuration();
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision)
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        printer.register_section("FileData");
        printer.append(t_base::__printer__(float_precision));

        // printer.register_section("ConfigurationData");
        std::unordered_map<navigation::SensorConfiguration, size_t> configurations_with;
        for (auto& config_interface : this->_interface_per_file)
        {
            try
            {
                configurations_with[config_interface->read_sensor_configuration()]++;
            }
            catch (...)
            {
                configurations_with[navigation::SensorConfiguration()]++;
            }
        }
        printer.register_section(
            fmt::format("Unique sensor configurations ({})", configurations_with.size()));

        for (auto& config_with : configurations_with)
        {
            printer.register_value(fmt::format("Files using this configuration"),
                                   config_with.second);
        }

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