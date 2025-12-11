// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/kmallconfigurationdatainterfaceperfile.doc.hpp"

/* library includes */
#include <boost/flyweight.hpp>

/* std includes */
#include <fstream>
#include <map>
#include <unordered_map>
#include <vector>

#include <fmt/core.h>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../datagrams.hpp"
#include "../types.hpp"

#include "../../filetemplates/datainterfaces/i_configurationdatainterfaceperfile.hpp"
#include "kmalldatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace filedatainterfaces {

template<typename t_ifstream>
class KMALLConfigurationDataInterfacePerFile
    : public filetemplates::datainterfaces::I_ConfigurationDataInterfacePerFile<
          KMALLDatagramInterface<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_ConfigurationDataInterfacePerFile<
        KMALLDatagramInterface<t_ifstream>>;

    uint8_t _active_position_system_number = 0;
    uint8_t _active_attitude_sensor_number = 0;

    bool _runtime_parameters_initialized = false;
    std::map<int, std::vector<boost::flyweight<datagrams::IOpRuntime>>>
        _runtime_parameters_by_system_serial_number;

  public:
    KMALLConfigurationDataInterfacePerFile()
        : t_base("KMALLConfigurationDataInterfacePerFile")
    {
    }
    ~KMALLConfigurationDataInterfacePerFile() = default;

    // ----- getters -----
    int8_t get_active_position_system_number() const { return _active_position_system_number; }
    int8_t get_active_attitude_sensor_number() const { return _active_attitude_sensor_number; }

    // ----- setters -----
    /**
     * @brief Set the active position system number
     * 0: this will be overwritten by "read_sensor_configuration" / "init_interface"
     * 1-4: position system 1-4
     *
     * @param number
     */
    void set_active_position_system_number(uint8_t number)
    {
        _active_position_system_number = number;
    }

    /**
     * @brief Set the active attitude sensor number
     * 0: this will be overwritten by "read_sensor_configuration" / "init_interface"
     * 1-4: attitude sensor 1-4
     *
     * @param number
     */
    void set_active_attitude_sensor_number(uint8_t number)
    {
        _active_attitude_sensor_number = number;
    }

    auto get_transducer_id() const
    {
        for (const auto& target_id : this->get_sensor_configuration().get_target_ids())
        {
            if (target_id.starts_with("TRX"))
            {
                return target_id;
            }
        }

        throw std::runtime_error(
            fmt::format("get_transducer_id: No transducer found in sensor configuration for file "
                        "nr {} [{}]!",
                        this->get_file_nr(),
                        this->get_file_path()));
    }

    // ----- runtime parameters -----
    /**
     * @brief Read the runtime parameters from the file and save them in the internal map
     * This function is automatically called by get_runtime_parameters
     *
     */
    void init_runtime_parameters()
    {
        // read installation parameters to get the PU serial number
        auto        installation_parameters = this->read_installation_parameters();
        int system_serial_number           = 40;

        // iterate over all I_OP_RUNTIME datagrams
        if (this->_datagram_infos_by_type.contains(t_KMALLDatagramIdentifier::I_OP_RUNTIME))
        {
            for (const auto& datagram_ptr :
                 this->_datagram_infos_by_type[t_KMALLDatagramIdentifier::I_OP_RUNTIME])
            {
                _runtime_parameters_by_system_serial_number[system_serial_number].emplace_back(
                    datagram_ptr->template read_datagram_from_file<datagrams::IOpRuntime>());
            }
        }

        // Throw an error if no runtime parameters were found
        if (!_runtime_parameters_by_system_serial_number.contains(system_serial_number) ||
            _runtime_parameters_by_system_serial_number[system_serial_number].empty())
            throw std::runtime_error(
                fmt::format("init_runtime_parameters: No runtime parameters found for PU serial "
                            "number '{}' in file nr {} [{}]!",
                            system_serial_number,
                            this->get_file_nr(),
                            this->get_file_path()));

        _runtime_parameters_initialized = true;
    }

    /**
     * @brief Get the runtime parameters for a specific ping
     *
     * This function searches for the runtime parameters that were active at the given ping time.
     * It uses last_index as an optimization to avoid searching from the beginning each time.
     *
     * @param system_serial_number The PU serial number to search for
     * @param ping_time The timestamp of the ping
     * @param last_index Shared pointer to the last index used for optimization (will be updated)
     * @return boost::flyweight<datagrams::IOpRuntime> The runtime parameters for the ping
     */
    boost::flyweight<datagrams::IOpRuntime> get_runtime_parameters(
        int                     system_serial_number,
        size_t                  ping_counter,
        double                  ping_time,
        std::shared_ptr<size_t> last_index = std::make_shared<size_t>(0))
    {
        if (!_runtime_parameters_initialized)
            this->init_runtime_parameters();

        // catch uninitialized last_index pointer
        if (!last_index)
            last_index = std::make_shared<size_t>(0);

        auto& runtime_parameter_vector =
            _runtime_parameters_by_system_serial_number[system_serial_number];

        if (runtime_parameter_vector.empty())
            throw std::runtime_error(
                fmt::format("get_runtime_parameters: No runtime parameters found for PU serial "
                            "number '{}' at time {} in ping '{}'",
                            system_serial_number,
                            ping_time,
                            ping_counter));

        if (*last_index >= runtime_parameter_vector.size())
            throw std::runtime_error(
                fmt::format("get_runtime_parameters: last_index '{}' is out of bounds for PU "
                            "serial number '{}' at time {} in ping '{}'",
                            *last_index,
                            system_serial_number,
                            ping_time,
                            ping_counter));

        size_t i = *last_index;
        // search for time
        for (; i < runtime_parameter_vector.size() - 1; ++i)
        {
            double rt_next_time = runtime_parameter_vector[i + 1].get().get_timestamp();

            if (rt_next_time > ping_time)
                break;
        }

        *last_index = i;

        // return the runtime parameter
        return runtime_parameter_vector[i];
    }

    // ----- interface methods -----
    navigation::SensorConfiguration read_sensor_configuration() final
    {
        navigation::SensorConfiguration config;
        using navigation::datastructures::PositionalOffsets;

        /* get the installation parameters datagram */
        auto param = this->read_installation_parameters();

        // set the active systems (if they weren't previously set)
        if (_active_position_system_number == 0)
            _active_position_system_number = param.get_active_position_system_number();

        if (_active_attitude_sensor_number == 0)
            _active_attitude_sensor_number = param.get_active_attitude_sensor_number();

        auto transducer_offsets = param.get_transducer_offsets();
        // std::string system_name = param.get_system_name();
        // int pu_serial = param.get_system_serial_number();

        switch (param.get_system_transducer_configuration().value)
        {
            case t_KMALLSystemTransducerConfiguration::SingleHead:
                [[fallthrough]];
            case t_KMALLSystemTransducerConfiguration::PortableSingleHead: {
                auto trx = transducer_offsets["TRX"];
                config.add_target(trx.name, std::move(trx));
                break;
            }
            case t_KMALLSystemTransducerConfiguration::SingleTxSingleRx: {
                auto tx  = transducer_offsets["TX"];
                auto rx  = transducer_offsets["RX"];
                auto trx = PositionalOffsets::from_txrx(tx, rx, "T" + rx.name);
                config.add_target(tx.name, std::move(tx));
                config.add_target(rx.name, std::move(rx));
                config.add_target(trx.name, std::move(trx));
                break;
            }
            default:

                throw std::runtime_error(
                    fmt::format("read_sensor_configuration \n"
                                "in file nr {} [{}]! unsupported transducer configuration: {}",
                                this->get_file_nr(),
                                this->get_file_path(),
                                param.get_system_transducer_configuration().name()));
        }

        // add the depth sensor (if available)
        try
        {
            config.set_depth_source(param.get_depth_sensor_offsets());
        }
        catch (const std::invalid_argument&)
        {
            // Depth sensor not configured, that's okay
        }

        // add the waterline offset
        config.set_waterline_offset(param.get_water_line_vertical_location_in_meters());

        // add the attitude sensor (if available)
        if (_active_attitude_sensor_number > 0)
        {
            try
            {
                config.set_attitude_source(
                    param.get_attitude_sensor_offsets(_active_attitude_sensor_number));
            }
            catch (const std::invalid_argument&)
            {
                // Attitude sensor not configured, that's okay
            }
        }

        // add the position sensor (if available)
        if (_active_position_system_number > 0)
        {
            try
            {
                config.set_position_source(
                    param.get_position_system_offsets(_active_position_system_number));
            }
            catch (const std::invalid_argument&)
            {
                // Position system not configured, that's okay
            }
        }

        return config;
    }

    // ----- kmall specific functions -----
    /**
     * @brief Read the installation parameters from the file
     *
     * @return datagrams::IInstallationParam
     */
    datagrams::IInstallationParam read_installation_parameters() const
    {
        // check that there is at least one installation parameters datagram
        if (!this->_datagram_infos_by_type.contains(
                t_KMALLDatagramIdentifier::I_INSTALLATION_PARAM))
            throw std::runtime_error(
                fmt::format("read_installation_parameters: There is no "
                            "installation parameters datagram in file nr {} [{}]!",
                            this->get_file_nr(),
                            this->get_file_path()));

        const auto& datagram_infos =
            this->_datagram_infos_by_type.at_const(t_KMALLDatagramIdentifier::I_INSTALLATION_PARAM);

        if (datagram_infos.empty())
            throw std::runtime_error(
                fmt::format("read_installation_parameters: There is no "
                            "installation parameters datagram in file nr {} [{}]!",
                            this->get_file_nr(),
                            this->get_file_path()));

        if (datagram_infos.size() > 1)
            throw std::runtime_error(
                fmt::format("read_installation_parameters: There are multiple "
                            "installation parameters datagrams in file nr {} [{}]!",
                            this->get_file_nr(),
                            this->get_file_path()));

        // Return the first installation parameters datagram
        return datagram_infos[0]->template read_datagram_from_file<datagrams::IInstallationParam>();
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents)
    {
        tools::classhelper::ObjectPrinter printer(
            this->class_name(), float_precision, superscript_exponents);

        printer.append(t_base::__printer__(float_precision, superscript_exponents));

        printer.register_section("KMALLConfigurationDataInterfacePerFile");
        printer.register_value("_active_position_system_number", _active_position_system_number);
        printer.register_value("_active_attitude_sensor_number", _active_attitude_sensor_number);
        printer.register_value("_runtime_parameters_initialized", _runtime_parameters_initialized);
        printer.register_value("Number of PU serial numbers with runtime parameters",
                               _runtime_parameters_by_system_serial_number.size());

        return printer;
    }
};

}
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
