// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/i_configurationdatainterface.doc.hpp"

/* std includes */
#include <filesystem>
#include <fstream>
#include <unordered_map>
#include <vector>

#include <boost/flyweight.hpp>
#include <boost/unordered_map.hpp>
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

#include "i_configurationdatainterfaceperfile.hpp"
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

    boost::unordered_map<std::string, boost::flyweight<navigation::SensorConfiguration>>
    get_trx_sensor_configuration_per_channel_id(long             pyindex,
                                                std::string_view target_prefix = "TRX-") const
    {
        boost::unordered_map<std::string, boost::flyweight<navigation::SensorConfiguration>> result;

        const auto& base_sensor_configuration = get_sensor_configuration(pyindex);

        // create a sensor configuration for each target that starts with "TRX-"
        for (const auto& target_id : base_sensor_configuration.get_target_ids())
        {
            // if target id starts with target_prefix ("TRX-", this target is a transducer channel)
            if (target_id.starts_with(target_prefix))
            {
                auto trx_sensor_configuration = base_sensor_configuration;
                trx_sensor_configuration.add_target("Transducer",
                                                    trx_sensor_configuration.get_target(target_id));
                result[target_id] = trx_sensor_configuration;
            }
        }

        return result;
    }

    /**
     * @brief Throw if the sensor configuration of the linked files is not consistent.
     *
     */
    void verify_linked_file_interfaces_are_consistent()
    {
        auto primary_interfaces_per_file = this->per_primary_file();

        for (const auto& primary : primary_interfaces_per_file)
        {
            if (!primary->has_linked_file())
                continue;

            auto secondary = this->_interface_per_file[primary->get_linked_file_nr()];

            auto primary_sensor_configuration   = primary->read_sensor_configuration();
            auto secondary_sensor_configuration = secondary->read_sensor_configuration();

            if (primary_sensor_configuration != secondary_sensor_configuration)
            {
                throw std::runtime_error(fmt::format(
                    "Inconsistent sensor configurations for linked files: \n[{}] {}\nand\n[{}] {}",
                    primary->get_file_nr(),
                    primary->get_file_path(),
                    secondary->get_file_nr(),
                    secondary->get_file_path()));
            }
        }
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision)
    {
        tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision);

        printer.register_section("FileData");
        printer.append(t_base::__printer__(float_precision));

        // printer.register_section("ConfigurationData");
        std::unordered_map<navigation::SensorConfiguration, size_t> configurations_with;
        for (auto& config_interface : this->per_primary_file())
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