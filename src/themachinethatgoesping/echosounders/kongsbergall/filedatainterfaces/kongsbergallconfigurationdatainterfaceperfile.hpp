// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/kongsbergallconfigurationdatainterfaceperfile.doc.hpp"

/* library includes */
#include <magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../filetemplates/datainterfaces/i_configurationdatainterface.hpp"

#include "../types.hpp"
#include "../datagrams.hpp"
#include "kongsbergalldatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace filedatainterfaces {

template<typename t_ifstream>
class KongsbergAllConfigurationDataInterfacePerFile
    : public filetemplates::datainterfaces::I_ConfigurationDataInterfacePerFile<
          KongsbergAllDatagramInterface<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_ConfigurationDataInterfacePerFile<
        KongsbergAllDatagramInterface<t_ifstream>>;

    uint8_t              _active_position_system_number = 0;
    t_KongsbergAllActiveSensor _active_pitch_roll_sensor      = t_KongsbergAllActiveSensor::NotSet;
    t_KongsbergAllActiveSensor _active_heave_sensor           = t_KongsbergAllActiveSensor::NotSet;
    t_KongsbergAllActiveSensor _active_heading_sensor         = t_KongsbergAllActiveSensor::NotSet;

  public:
    KongsbergAllConfigurationDataInterfacePerFile()
        : t_base("KongsbergAllConfigurationDataInterfacePerFile")
    {
    }
    ~KongsbergAllConfigurationDataInterfacePerFile() = default;

    // ----- getters -----
    uint8_t get_active_position_system_number() const { return _active_position_system_number; }
    auto    get_active_pitch_roll_sensor() const { return _active_pitch_roll_sensor; }
    auto    get_active_heave_sensor() const { return _active_heave_sensor; }
    auto    get_active_heading_sensor() const { return _active_heading_sensor; }

    // ----- setters -----
    /**
     * @brief Set the active position system number
     * 0: this will be overwritten by "read_sensor_configuration" / "init_interface"
     * 1-3: position system 1-3
     *
     * @param number
     */
    void set_active_position_system_number(uint8_t number)
    {
        _active_position_system_number = number;
    }

    /**
     * @brief Set the active roll pitch sensor
     * "NotSet": this will be overwritten by "read_sensor_configuration" / "init_interface"
     * All other values: see t_KongsbergAllActiveSensor
     *
     * @param sensor
     */
    void set_active_pitch_roll_sensor(t_KongsbergAllActiveSensor sensor)
    {
        _active_pitch_roll_sensor = sensor;
    }

    /**
     * @brief Set the active heave sensor
     * "NotSet": this will be overwritten by "read_sensor_configuration" / "init_interface"
     * All other values: see t_KongsbergAllActiveSensor
     *
     * @param sensor
     */
    void set_active_heave_sensor(t_KongsbergAllActiveSensor sensor) { _active_heave_sensor = sensor; }

    /**
     * @brief Set the active heading sensor
     * "NotSet": this will be overwritten by "read_sensor_configuration" / "init_interface"
     * All other values: see t_KongsbergAllActiveSensor
     *
     * @param sensor
     */
    void set_active_heading_sensor(t_KongsbergAllActiveSensor sensor) { _active_heading_sensor = sensor; }

    // ----- interface methods -----
    navigation::SensorConfiguration read_sensor_configuration() final
    {
        navigation::SensorConfiguration config;
        using navigation::datastructures::PositionalOffsets;

        /* get the installation parameters datagram */
        auto param = this->get_installation_parameters();

        // set the active systems (if they weren't previously set)
        if (_active_position_system_number == 0)
            _active_position_system_number = param.get_active_position_system_number();

        if (_active_pitch_roll_sensor == t_KongsbergAllActiveSensor::NotSet)
            _active_pitch_roll_sensor = param.get_active_pitch_roll_sensor();

        if (_active_heave_sensor == t_KongsbergAllActiveSensor::NotSet)
            _active_heave_sensor = param.get_active_heave_sensor();

        if (_active_heading_sensor == t_KongsbergAllActiveSensor::NotSet)
            _active_heading_sensor = param.get_active_heading_sensor();

        /* get the sensor configuration flag using STC */
        switch (param.get_value_int("STC", 0)) // if STC is not found: assume single tx + single rx
        {
            case 0: // Single TX + single RX
            {
                auto tx = param.get_transducer_offsets(1, "TX");
                auto rx = param.get_transducer_offsets(2, "RX");

                auto trx = PositionalOffsets::from_txrx(
                    tx, rx, fmt::format("TRX-{}", param.get_system_main_head_serial_number()));

                config.add_target(tx.name, std::move(tx));
                config.add_target(rx.name, std::move(rx));
                config.add_target(trx.name, std::move(trx));
                break;
            }
            case 5: // Portable single head
                [[fallthrough]];
            case 6: // Modular
                [[fallthrough]];
            case 1: // Single head
            {
                auto trx = param.get_transducer_offsets(
                    1, "TRX-" + std::to_string(param.get_system_main_head_serial_number()));

                config.add_target(trx.name, std::move(trx));
                break;
            }
            case 2: // Dual head
            {

                auto trx1 = param.get_transducer_offsets(
                    1, "TRX-" + std::to_string(param.get_system_main_head_serial_number()));
                auto trx2 = param.get_transducer_offsets(
                    2, "TRX-" + std::to_string(param.get_secondary_system_serial_number()));

                config.add_target(trx1.name, std::move(trx1));
                config.add_target(trx2.name, std::move(trx2));
                break;
            }
            case 3: // Single TX + dual RX
            {
                auto tx = param.get_transducer_offsets(
                    1, "TX-" + std::to_string(param.get_tx_serial_number()));
                auto rx1 = param.get_transducer_offsets(
                    2, "RX-" + std::to_string(param.get_rx1_serial_number()));
                auto rx2 = param.get_transducer_offsets(
                    3, "RX-" + std::to_string(param.get_rx2_serial_number()));

                auto trx1 = PositionalOffsets::from_txrx(
                    tx, rx1, fmt::format("TRX-{}", param.get_system_main_head_serial_number()));
                auto trx2 = PositionalOffsets::from_txrx(
                    tx, rx2, fmt::format("TRX-{}", param.get_secondary_system_serial_number()));

                config.add_target(tx.name, std::move(tx));
                config.add_target(rx1.name, std::move(rx1));
                config.add_target(rx2.name, std::move(rx2));
                config.add_target(trx1.name, std::move(trx1));
                config.add_target(trx2.name, std::move(trx2));

                break;
            }
            case 4: // Dual TX + dual RX
            {
                auto tx1 = param.get_transducer_offsets(
                    0, "TX-" + std::to_string(param.get_tx_serial_number()));
                auto tx2 = param.get_transducer_offsets(
                    1, "TX-" + std::to_string(param.get_tx2_serial_number()));
                auto rx1 = param.get_transducer_offsets(
                    2, "RX-" + std::to_string(param.get_rx1_serial_number()));
                auto rx2 = param.get_transducer_offsets(
                    3, "RX-" + std::to_string(param.get_rx2_serial_number()));

                auto trx1 = PositionalOffsets::from_txrx(
                    tx1, rx1, fmt::format("TRX-{}", param.get_system_main_head_serial_number()));
                auto trx2 = PositionalOffsets::from_txrx(
                    tx2, rx2, fmt::format("TRX-{}", param.get_secondary_system_serial_number()));

                config.add_target(tx1.name, std::move(tx1));
                config.add_target(tx2.name, std::move(tx2));
                config.add_target(rx1.name, std::move(rx1));
                config.add_target(rx2.name, std::move(rx2));
                config.add_target(trx1.name, std::move(trx1));
                config.add_target(trx2.name, std::move(trx2));
                break;
            }
            default:
                throw std::runtime_error(
                    fmt::format("read_sensor_configuration: Unknown STC "
                                "value {} in file nr {} [{}] installation parameters!",
                                param.get_value_int("STC"),
                                this->get_file_nr(),
                                this->get_file_path()));
        }

        // add the compass
        config.set_heading_source(param.get_compass_offsets());

        // add the depth sensor
        config.set_depth_source(param.get_depth_sensor_offsets());

        // add the waterline offset
        config.set_waterline_offset(param.get_water_line_vertical_location_in_meters());

        // add the gyro
        config.set_attitude_source(param.get_attitude_sensor_offsets(_active_pitch_roll_sensor));

        // add the position sensor
        config.set_position_source(
            param.get_position_system_offsets(_active_position_system_number));

        return config;
    }

    // ----- kongsbergall specific functions -----
    /* get infos */
    datagrams::InstallationParameters get_installation_parameters() const
    {
        // check that there is only one installation parameters datagram
        if (this->_datagram_infos_by_type
                .at_const(t_KongsbergAllDatagramIdentifier::InstallationParametersStart)
                .empty())
            throw std::runtime_error(fmt::format("get_installation_parameters: There is no "
                                                 "installation parameters start"
                                                 "datagram in file nr {} [{}]!",
                                                 this->get_file_nr(),
                                                 this->get_file_path()));

        // get the first installation parameters start paragram ...
        auto start = this->_datagram_infos_by_type
                         .at_const(t_KongsbergAllDatagramIdentifier::InstallationParametersStart)[0]
                         ->template read_datagram_from_file<datagrams::InstallationParameters>();

        // check that all installation parameter datagrams are the same within the file
        for (unsigned int i = 1;
             i < this->_datagram_infos_by_type
                     .at_const(t_KongsbergAllDatagramIdentifier::InstallationParametersStart)
                     .size();
             ++i)
        {
            auto compare =
                this->_datagram_infos_by_type
                    .at_const(t_KongsbergAllDatagramIdentifier::InstallationParametersStart)[i]
                    ->template read_datagram_from_file<datagrams::InstallationParameters>();

            try
            {
                start =
                    datagrams::InstallationParameters::merge(std::move(start), std::move(compare));
            }
            catch (std::exception& e)
            {
                throw std::runtime_error(
                    fmt::format("get_installation_parameters: Installation "
                                "parameters start change within file nr {} [{}]"
                                "are not the same! Error: {}",
                                this->get_file_nr(),
                                this->get_file_path(),
                                e.what()));
            }
        }

        // check that all installation parameter datagrams are the same within the file
        for (unsigned int i = 0;
             i < this->_datagram_infos_by_type
                     .at_const(t_KongsbergAllDatagramIdentifier::InstallationParametersStop)
                     .size();
             ++i)
        {
            auto compare =
                this->_datagram_infos_by_type
                    .at_const(t_KongsbergAllDatagramIdentifier::InstallationParametersStop)[i]
                    ->template read_datagram_from_file<datagrams::InstallationParameters>();

            try
            {
                start =
                    datagrams::InstallationParameters::merge(std::move(start), std::move(compare));
            }
            catch (std::exception& e)
            {
                throw std::runtime_error(
                    fmt::format("get_installation_parameters: Installation "
                                "parameters start change within file nr {} [{}]"
                                "are not the same! Error: {}",
                                this->get_file_nr(),
                                this->get_file_path(),
                                e.what()));
            }
        }

        // return the installation parameters
        return start;
    }

    // /* get other possible sensor sources */
    // /**
    //  * @brief Return all position sources registered in the configuration datagram (sorted by
    //  * priority)
    //  *
    //  * @return std::vector<XML_Configuration_Sensor>
    //  */
    // std::vector<datagrams::xml_datagrams::XML_Configuration_Sensor> get_position_sources()
    // {
    //     auto configuration_datagram = this->get_configuration_datagram();
    //     // get sensor configuration
    //     return configuration_datagram.get_sensors_sorted_by_priority({ "Latitude", "Longitude"
    //     });
    // }

    // /**
    //  * @brief Return all depth sources registered in the configuration datagram (sorted by
    //  priority)
    //  *
    //  * @return std::vector<XML_Configuration_Sensor>
    //  */
    // std::vector<datagrams::xml_datagrams::XML_Configuration_Sensor> get_depth_sources()
    // {
    //     auto configuration_datagram = this->get_configuration_datagram();
    //     // get sensor configuration
    //     return configuration_datagram.get_sensors_sorted_by_priority({ "Latitude", "Longitude"
    //     });
    // }

    // /**
    //  * @brief Return all attitude sources registered in the configuration datagram (sorted by
    //  * priority)
    //  *
    //  * @return std::vector<XML_Configuration_Sensor>
    //  */
    // std::vector<datagrams::xml_datagrams::XML_Configuration_Sensor> get_attitude_sources()
    // {
    //     auto configuration_datagram = this->get_configuration_datagram();
    //     // get sensor configuration
    //     return configuration_datagram.get_sensors_sorted_by_priority({ "Roll", "Pitch", "Heave"
    //     });
    // }

    // /**
    //  * @brief Return all heading sources registered in the configuration datagram (sorted by
    //  * priority)
    //  *
    //  * @return std::vector<XML_Configuration_Sensor>
    //  */
    // std::vector<datagrams::xml_datagrams::XML_Configuration_Sensor> get_heading_sources()
    // {
    //     auto configuration_datagram = this->get_configuration_datagram();
    //     // get sensor configuration
    //     return configuration_datagram.get_sensors_sorted_by_priority({ "Heading" });
    // }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision)
    {
        tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision));

        printer.register_section("KongsbergAllConfigurationDataInterfacePerFile");
        printer.register_value("_active_position_system_number", _active_position_system_number);
        printer.register_enum("_active_pitch_roll_sensor", _active_pitch_roll_sensor);
        printer.register_enum("_active_heave_sensor", _active_heave_sensor);
        printer.register_enum("_active_heading_sensor", _active_heading_sensor);
        // auto position_sources = this->get_position_sources();
        // auto heading_sources  = this->get_heading_sources();
        // auto attitude_sources = this->get_attitude_sources();
        // auto depth_sources    = this->get_depth_sources();

        // printer.register_string("Position source",
        //                         fmt::format("'{}'", position_sources[0].Name),
        //                         position_sources.size() < 2
        //                             ? ""
        //                             : fmt::format("Alternatives: {}", position_sources.size() -
        //                             1));
        // printer.register_string("Heading source",
        //                         fmt::format("'{}'", heading_sources[0].Name),
        //                         heading_sources.size() < 2
        //                             ? ""
        //                             : fmt::format("Alternatives: {}", heading_sources.size() -
        //                             1));
        // printer.register_string("Attitude source",
        //                         fmt::format("'{}'", attitude_sources[0].Name),
        //                         attitude_sources.size() < 2
        //                             ? ""
        //                             : fmt::format("Alternatives: {}", attitude_sources.size() -
        //                             1));
        // printer.register_string("Depth source",
        //                         fmt::format("'{}'", depth_sources[0].Name),
        //                         depth_sources.size() < 2
        //                             ? ""
        //                             : fmt::format("Alternatives: {}", depth_sources.size() - 1));

        return printer;
    }
};

}
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
