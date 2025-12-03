// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/kmallconfigurationdatainterfaceperfile.doc.hpp"

/* std includes */
#include <fstream>
#include <unordered_map>
#include <vector>

#include <fmt/core.h>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

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

    // uint8_t                    _active_position_system_number = 0;
    // t_KMALLActiveSensor _active_pitch_roll_sensor      = t_KMALLActiveSensor::NotSet;
    // t_KMALLActiveSensor _active_heave_sensor           = t_KMALLActiveSensor::NotSet;
    // t_KMALLActiveSensor _active_heading_sensor         = t_KMALLActiveSensor::NotSet;

    // bool _runtime_parameters_initialized = false;
    // std::map<uint16_t, std::vector<boost::flyweight<datagrams::RuntimeParameters>>>
    //     _runtime_parameters_by_system_serial_number;

  public:
    KMALLConfigurationDataInterfacePerFile()
        : t_base("KMALLConfigurationDataInterfacePerFile")
    {
    }
    ~KMALLConfigurationDataInterfacePerFile() = default;

    // ----- getters -----
    // uint8_t get_active_position_system_number() const { return _active_position_system_number; }
    // auto    get_active_pitch_roll_sensor() const { return _active_pitch_roll_sensor; }
    // auto    get_active_heave_sensor() const { return _active_heave_sensor; }
    // auto    get_active_heading_sensor() const { return _active_heading_sensor; }

    // ----- setters -----
    // /**
    //  * @brief Set the active position system number
    //  * 0: this will be overwritten by "read_sensor_configuration" / "init_interface"
    //  * 1-3: position system 1-3
    //  *
    //  * @param number
    //  */
    // void set_active_position_system_number(uint8_t number)
    // {
    //     _active_position_system_number = number;
    // }

    // /**
    //  * @brief Set the active roll pitch sensor
    //  * "NotSet": this will be overwritten by "read_sensor_configuration" / "init_interface"
    //  * All other values: see o_KMALLActiveSensor
    //  *
    //  * @param sensor
    //  */
    // void set_active_pitch_roll_sensor(o_KMALLActiveSensor sensor)
    // {
    //     _active_pitch_roll_sensor = sensor.value;
    // }

    // /**
    //  * @brief Set the active heave sensor
    //  * "NotSet": this will be overwritten by "read_sensor_configuration" / "init_interface"
    //  * All other values: see o_KMALLActiveSensor
    //  *
    //  * @param sensor
    //  */
    // void set_active_heave_sensor(o_KMALLActiveSensor sensor)
    // {
    //     _active_heave_sensor = sensor.value;
    // }

    // /**
    //  * @brief Set the active heading sensor
    //  * "NotSet": this will be overwritten by "read_sensor_configuration" / "init_interface"
    //  * All other values: see o_KMALLActiveSensor
    //  *
    //  * @param sensor
    //  */
    // void set_active_heading_sensor(o_KMALLActiveSensor sensor)
    // {
    //     _active_heading_sensor = sensor.value;
    // }

    // // ----- interface methods -----
    // /**
    //  * @brief read the runtime parameters from the file and save them in the internal map
    //  * This function is automatically called by get_runtime_parameters
    //  *
    //  */
    // void init_runtime_parameters()
    // {
    //     // read installation parameters to get the system configuration system serial number(s)
    //     auto installation_parameters = this->read_installation_parameters();

    //     for (const auto& datagram_ptr :
    //          this->_datagram_infos_by_type[t_KMALLDatagramIdentifier::RuntimeParameters])
    //     {
    //         // read ping counter from not deduplicated datagram
    //         uint16_t system_serial_number = this->read_extra_info_serial_number(datagram_ptr);

    //         _runtime_parameters_by_system_serial_number[system_serial_number].emplace_back(
    //             datagram_ptr->template read_datagram_from_file<datagrams::RuntimeParameters>());
    //     }

    //     // Throw an error if no runtime parameters were found for the existing system serial numbers
    //     // primary system
    //     if (!_runtime_parameters_by_system_serial_number.contains(
    //             installation_parameters.get_system_serial_number()))
    //         throw std::runtime_error(fmt::format(
    //             "init_runtime_parameters: No runtime parameters found for primary system serial "
    //             "number '{}' in file nr {} [{}]!",
    //             installation_parameters.get_system_serial_number(),
    //             this->get_file_nr(),
    //             this->get_file_path()));

    //     switch (installation_parameters.get_system_transducer_configuration().value)
    //     {
    //         case t_KMALLSystemTransducerConfiguration::SingleTXDualRX:
    //             // singleTxDualRx seems to create only one runtime parameter for both systems
    //             // (probably because there is only one TX unit). We thus add copy the runtime
    //             // parameters of the primary system for the secondary system
    //             if (installation_parameters.get_system_transducer_configuration() ==
    //                 t_KMALLSystemTransducerConfiguration::SingleTXDualRX)
    //                 if (!_runtime_parameters_by_system_serial_number.contains(
    //                         installation_parameters.get_secondary_system_serial_number()))
    //                     _runtime_parameters_by_system_serial_number
    //                         [installation_parameters.get_secondary_system_serial_number()] =
    //                             _runtime_parameters_by_system_serial_number
    //                                 [installation_parameters.get_system_serial_number()];
    //             break;

    //             // dual head should have runtime parameters for both systems
    //         case t_KMALLSystemTransducerConfiguration::DualHead:
    //             [[fallthrough]];
    //         case t_KMALLSystemTransducerConfiguration::DualTXDualRX:
    //             if (!_runtime_parameters_by_system_serial_number.contains(
    //                     installation_parameters.get_secondary_system_serial_number()))
    //                 throw std::runtime_error(
    //                     fmt::format("init_runtime_parameters: No runtime parameters found for "
    //                                 "secondary system serial "
    //                                 "number '{}' in file nr {} [{}]!",
    //                                 installation_parameters.get_secondary_system_serial_number(),
    //                                 this->get_file_nr(),
    //                                 this->get_file_path()));
    //         default:

    //             // case t_KMALLSystemTransducerConfiguration::SingleTXSingleRX:
    //             // case t_KMALLSystemTransducerConfiguration::SingleHead:
    //             // case t_KMALLSystemTransducerConfiguration::PortableSingleHead:
    //             // case t_KMALLSystemTransducerConfiguration::Modular:
    //             break;
    //     }

    //     _runtime_parameters_initialized = true;
    // }

    // // TODO: this needs some carefull testing ..
    // boost::flyweight<datagrams::RuntimeParameters> get_runtime_parameters(
    //     uint16_t                system_serial_number,
    //     size_t                  ping_counter,
    //     double                  ping_time,
    //     std::shared_ptr<size_t> last_index = std::make_shared<size_t>(0))
    // {
    //     if (!_runtime_parameters_initialized)
    //         this->init_runtime_parameters();

    //     // catch uninitialized last_index pointer
    //     if (!last_index)
    //         last_index = std::make_shared<size_t>(0);

    //     auto& runtime_parameter_vector =
    //         _runtime_parameters_by_system_serial_number[system_serial_number];

    //     if (runtime_parameter_vector.empty())
    //         throw std::runtime_error(
    //             fmt::format("get_runtime_parameters: No runtime parameters found for system "
    //                         "serial number '{}' in ping '{}'",
    //                         system_serial_number,
    //                         ping_counter));

    //     if (*last_index >= runtime_parameter_vector.size())
    //         throw std::runtime_error(
    //             fmt::format("get_runtime_parameters: last_index '{}' is out of bounds for system "
    //                         "serial number '{}' in ping '{}'",
    //                         *last_index,
    //                         system_serial_number,
    //                         ping_counter));

    //     size_t i = *last_index;
    //     // search for time first
    //     for (; i < runtime_parameter_vector.size() - 1; ++i)
    //     {
    //         // double rt_time      = runtime_parameter_vector[i].get().get_timestamp();
    //         double rt_next_time = runtime_parameter_vector[i + 1].get().get_timestamp();

    //         if (rt_next_time > ping_time)
    //             break;
    //     }

    //     // find the runtime parameter with the closest ping counter
    //     // Note: the counter is overflowing at 65535
    //     for (; i < runtime_parameter_vector.size() - 1; ++i)
    //     {
    //         size_t rt_ping_counter      = runtime_parameter_vector[i].get().get_ping_counter();
    //         size_t rt_next_ping_counter = runtime_parameter_vector[i + 1].get().get_ping_counter();
    //         // search for time first

    //         // the rt_counter is overflown:
    //         if (rt_next_ping_counter < rt_ping_counter)
    //             rt_next_ping_counter += 65536;

    //         // ping counter is overflown:
    //         if (ping_counter < rt_ping_counter)
    //             ping_counter += 65536;

    //         // if ping_counter is smaller than the current counter, it is probably overflown
    //         if (rt_ping_counter == ping_counter)
    //             break;

    //         if (rt_next_ping_counter > ping_counter)
    //             break;
    //     }

    //     *last_index = i;

    //     // if the last runtime parameter is the closest
    //     return runtime_parameter_vector[i];
    // }

    navigation::SensorConfiguration read_sensor_configuration() final
    {
        return navigation::SensorConfiguration();
    }

    //     navigation::SensorConfiguration config;
    //     using navigation::datastructures::PositionalOffsets;

    //     /* get the installation parameters datagram */
    //     auto param = this->read_installation_parameters();

    //     // set the active systems (if they weren't previously set)
    //     if (_active_position_system_number == 0)
    //         _active_position_system_number = param.get_active_position_system_number();

    //     if (_active_pitch_roll_sensor == t_KMALLActiveSensor::NotSet)
    //         _active_pitch_roll_sensor = param.get_active_pitch_roll_sensor();

    //     if (_active_heave_sensor == t_KMALLActiveSensor::NotSet)
    //         _active_heave_sensor = param.get_active_heave_sensor();

    //     if (_active_heading_sensor == t_KMALLActiveSensor::NotSet)
    //         _active_heading_sensor = param.get_active_heading_sensor();

    //     /* get the sensor configuration flag using STC */
    //     switch (param.get_value_int("STC", 0)) // if STC is not found: assume single tx + single rx
    //     {
    //         case 0: // Single TX + single RX
    //         {
    //             auto tx = param.get_transducer_offsets(1, "TX");
    //             auto rx = param.get_transducer_offsets(2, "RX");

    //             auto trx = PositionalOffsets::from_txrx(
    //                 tx, rx, fmt::format("TRX-{}", param.get_system_main_head_serial_number()));

    //             config.add_target(tx.name, std::move(tx));
    //             config.add_target(rx.name, std::move(rx));
    //             config.add_target(trx.name, std::move(trx));
    //             break;
    //         }
    //         case 5: // Portable single head
    //             [[fallthrough]];
    //         case 6: // Modular
    //             [[fallthrough]];
    //         case 1: // Single head
    //         {
    //             auto trx = param.get_transducer_offsets(
    //                 1, "TRX-" + std::to_string(param.get_system_main_head_serial_number()));

    //             config.add_target(trx.name, std::move(trx));
    //             break;
    //         }
    //         case 2: // Dual head
    //         {

    //             auto trx1 = param.get_transducer_offsets(
    //                 1, "TRX-" + std::to_string(param.get_system_main_head_serial_number()));
    //             auto trx2 = param.get_transducer_offsets(
    //                 2, "TRX-" + std::to_string(param.get_secondary_system_serial_number()));

    //             config.add_target(trx1.name, std::move(trx1));
    //             config.add_target(trx2.name, std::move(trx2));
    //             break;
    //         }
    //         case 3: // Single TX + dual RX
    //         {
    //             auto tx = param.get_transducer_offsets(
    //                 1, "TX-" + std::to_string(param.get_tx_serial_number()));
    //             auto rx1 = param.get_transducer_offsets(
    //                 2, "RX-" + std::to_string(param.get_rx1_serial_number()));
    //             auto rx2 = param.get_transducer_offsets(
    //                 3, "RX-" + std::to_string(param.get_rx2_serial_number()));

    //             auto trx1 = PositionalOffsets::from_txrx(
    //                 tx, rx1, fmt::format("TRX-{}", param.get_system_main_head_serial_number()));
    //             auto trx2 = PositionalOffsets::from_txrx(
    //                 tx, rx2, fmt::format("TRX-{}", param.get_secondary_system_serial_number()));

    //             config.add_target(tx.name, std::move(tx));
    //             config.add_target(rx1.name, std::move(rx1));
    //             config.add_target(rx2.name, std::move(rx2));
    //             config.add_target(trx1.name, std::move(trx1));
    //             config.add_target(trx2.name, std::move(trx2));

    //             break;
    //         }
    //         case 4: // Dual TX + dual RX
    //         {
    //             auto tx1 = param.get_transducer_offsets(
    //                 0, "TX-" + std::to_string(param.get_tx_serial_number()));
    //             auto tx2 = param.get_transducer_offsets(
    //                 1, "TX-" + std::to_string(param.get_tx2_serial_number()));
    //             auto rx1 = param.get_transducer_offsets(
    //                 2, "RX-" + std::to_string(param.get_rx1_serial_number()));
    //             auto rx2 = param.get_transducer_offsets(
    //                 3, "RX-" + std::to_string(param.get_rx2_serial_number()));

    //             auto trx1 = PositionalOffsets::from_txrx(
    //                 tx1, rx1, fmt::format("TRX-{}", param.get_system_main_head_serial_number()));
    //             auto trx2 = PositionalOffsets::from_txrx(
    //                 tx2, rx2, fmt::format("TRX-{}", param.get_secondary_system_serial_number()));

    //             config.add_target(tx1.name, std::move(tx1));
    //             config.add_target(tx2.name, std::move(tx2));
    //             config.add_target(rx1.name, std::move(rx1));
    //             config.add_target(rx2.name, std::move(rx2));
    //             config.add_target(trx1.name, std::move(trx1));
    //             config.add_target(trx2.name, std::move(trx2));
    //             break;
    //         }
    //         default:
    //             throw std::runtime_error(
    //                 fmt::format("read_sensor_configuration: Unknown STC "
    //                             "value {} in file nr {} [{}] installation parameters!",
    //                             param.get_value_int("STC"),
    //                             this->get_file_nr(),
    //                             this->get_file_path()));
    //     }

    //     // add the compass
    //     config.set_heading_source(param.get_compass_offsets());

    //     // add the depth sensor
    //     config.set_depth_source(param.get_depth_sensor_offsets());

    //     // add the waterline offset
    //     config.set_waterline_offset(param.get_water_line_vertical_location_in_meters());

    //     // add the gyro
    //     config.set_attitude_source(param.get_attitude_sensor_offsets(_active_pitch_roll_sensor));

    //     // add the position sensor
    //     config.set_position_source(
    //         param.get_position_system_offsets(_active_position_system_number));

    //     return config;
    // }

    // // ----- kmall specific functions -----
    // /**
    //  * @brief Read the installation parameters from the file, this function also checks if the start
    //  * and end parameters are the same
    //  *
    //  * @return datagrams::InstallationParameters
    //  */
    // datagrams::InstallationParameters read_installation_parameters() const
    // {
    //     // check that there is only one installation parameters datagram
    //     if (this->_datagram_infos_by_type
    //             .at_const(t_KMALLDatagramIdentifier::InstallationParametersStart)
    //             .empty())
    //         throw std::runtime_error(fmt::format("read_installation_parameters: There is no "
    //                                              "installation parameters start"
    //                                              "datagram in file nr {} [{}]!",
    //                                              this->get_file_nr(),
    //                                              this->get_file_path()));

    //     // get the first installation parameters start paragram ...
    //     auto start = this->_datagram_infos_by_type
    //                      .at_const(t_KMALLDatagramIdentifier::InstallationParametersStart)[0]
    //                      ->template read_datagram_from_file<datagrams::InstallationParameters>();

    //     // check that all installation parameter datagrams are the same within the file
    //     for (unsigned int i = 1;
    //          i < this->_datagram_infos_by_type
    //                  .at_const(t_KMALLDatagramIdentifier::InstallationParametersStart)
    //                  .size();
    //          ++i)
    //     {
    //         auto compare =
    //             this->_datagram_infos_by_type
    //                 .at_const(t_KMALLDatagramIdentifier::InstallationParametersStart)[i]
    //                 ->template read_datagram_from_file<datagrams::InstallationParameters>();

    //         try
    //         {
    //             start =
    //                 datagrams::InstallationParameters::merge(std::move(start), std::move(compare));
    //         }
    //         catch (std::exception& e)
    //         {
    //             throw std::runtime_error(
    //                 fmt::format("read_installation_parameters: Installation "
    //                             "parameters start change within file nr {} [{}]"
    //                             "are not the same! Error: {}",
    //                             this->get_file_nr(),
    //                             this->get_file_path(),
    //                             e.what()));
    //         }
    //     }

    //     // check that all installation parameter datagrams are the same within the file
    //     for (unsigned int i = 0;
    //          i < this->_datagram_infos_by_type
    //                  .at_const(t_KMALLDatagramIdentifier::InstallationParametersStop)
    //                  .size();
    //          ++i)
    //     {
    //         auto compare =
    //             this->_datagram_infos_by_type
    //                 .at_const(t_KMALLDatagramIdentifier::InstallationParametersStop)[i]
    //                 ->template read_datagram_from_file<datagrams::InstallationParameters>();

    //         try
    //         {
    //             start =
    //                 datagrams::InstallationParameters::merge(std::move(start), std::move(compare));
    //         }
    //         catch (std::exception& e)
    //         {
    //             throw std::runtime_error(
    //                 fmt::format("read_installation_parameters: Installation "
    //                             "parameters start change within file nr {} [{}]"
    //                             "are not the same! Error: {}",
    //                             this->get_file_nr(),
    //                             this->get_file_path(),
    //                             e.what()));
    //         }
    //     }

    //     // return the installation parameters
    //     return start;
    // }


    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents)
    {
        tools::classhelper::ObjectPrinter printer(
            this->class_name(), float_precision, superscript_exponents);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision, superscript_exponents));

        // printer.register_section("KMALLConfigurationDataInterfacePerFile");
        // printer.register_value("_active_position_system_number", _active_position_system_number);
        // printer.register_enum("_active_pitch_roll_sensor", _active_pitch_roll_sensor);
        // printer.register_enum("_active_heave_sensor", _active_heave_sensor);
        // printer.register_enum("_active_heading_sensor", _active_heading_sensor);
        

        return printer;
    }

  private:
    // uint16_t read_extra_info_serial_number(
    //     const typename t_base::type_DatagramInfo_ptr& datagram_ptr)
    // {
    //     if (datagram_ptr->get_extra_infos().size() != 4)
    //         throw std::runtime_error(fmt::format(
    //             "KMALLPingConfigurationDataInterfacePerFile::read_extra_info_serial_number: "
    //             "DatagramInfoData: extra info for datagram {} at pos "
    //             "{} is not available",
    //             datagram_type_to_string(datagram_ptr->get_datagram_identifier()),
    //             datagram_ptr->get_file_pos()));

    //     // ping_counter  = datagram_ptr->template get_extra_info<uint16_t>(0);
    //     return datagram_ptr->template get_extra_info<uint16_t>(sizeof(uint16_t));
    // }
};

}
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
