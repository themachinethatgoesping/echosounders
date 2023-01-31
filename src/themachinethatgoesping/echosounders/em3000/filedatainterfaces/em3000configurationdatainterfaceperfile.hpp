// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/em3000configurationdatainterfaceperfile.doc.hpp"

/* library includes */
#include <magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../filetemplates/datainterfaces/i_configurationdatainterface.hpp"

#include "../em3000_datagrams.hpp"
#include "../em3000_types.hpp"
#include "em3000datagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace filedatainterfaces {

template<typename t_ifstream>
class EM3000ConfigurationDataInterfacePerFile
    : public filetemplates::datainterfaces::I_ConfigurationDataInterfacePerFile<
          EM3000DatagramInterface<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_ConfigurationDataInterfacePerFile<
        EM3000DatagramInterface<t_ifstream>>;

  public:
    EM3000ConfigurationDataInterfacePerFile()
        : t_base("EM3000ConfigurationDataInterfacePerFile")
    {
    }
    ~EM3000ConfigurationDataInterfacePerFile() = default;

    navigation::SensorConfiguration read_sensor_configuration() final
    {
        navigation::SensorConfiguration config;

        // get the installation parameters datagram
        auto param = this->get_installation_parameters();

        /* get the sensor configuration flag using STC */
        switch (param.get_value_int("STC"))
        {
            case 0: // Single TX + single RX
                config.add_target("TX", param.get_transducer_offsets(1, "TX"));
                config.add_target("RX", param.get_transducer_offsets(2, "RX"));
                break;
            case 1: // Single head
                config.add_target("Head", param.get_transducer_offsets(1, "Head"));
                break;
            case 2: // Dual head
                config.add_target("Head 1", param.get_transducer_offsets(1, "Head 1"));
                config.add_target("Head 2", param.get_transducer_offsets(2, "Head 2"));
                break;
            case 3: // Single TX + dual RX
                config.add_target("TX", param.get_transducer_offsets(1, "TX"));
                config.add_target("RX port", param.get_transducer_offsets(2, "RX port"));
                config.add_target("RX starboard", param.get_transducer_offsets(3, "RX starboard"));
                break;
            case 4: // Dual TX + dual RX
                config.add_target("TX port", param.get_transducer_offsets(0, "TX port"));
                config.add_target("TX starboard", param.get_transducer_offsets(1, "TX starboard"));
                config.add_target("RX port", param.get_transducer_offsets(2, "RX port"));
                config.add_target("RX starboard", param.get_transducer_offsets(3, "RX starboard"));
                break;
            case 5: // Portable single head
                config.add_target("Head 1", param.get_transducer_offsets(1, "Head 1"));
                break;
            case 6: // Modular
                config.add_target("Head 1", param.get_transducer_offsets(1, "Head 1"));
                break;
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

        // add the gyro
        config.set_attitude_source(param.get_motion_sensor_offsets(1));

        // add the position sensor
        config.set_position_source(param.get_position_system_offsets(1));

        return config;
    }

    // ----- em3000 specific functions -----
    /* get infos */
    datagrams::InstallationParameters get_installation_parameters()
    {
        // check that there is only one installation parameters datagram
        if (this->_datagram_infos_by_type
                .at_const(t_EM3000DatagramIdentifier::InstallationParametersStart)
                .size() != 1)
            throw std::runtime_error(fmt::format("get_installation_parameters: There is not "
                                                 "exactly one installation parameters start"
                                                 "datagram in file nr {} [{}]!",
                                                 this->get_file_nr(),
                                                 this->get_file_path()));

        // check that there is only one installation parameters datagram
        if (this->_datagram_infos_by_type
                .at_const(t_EM3000DatagramIdentifier::InstallationParametersStop)
                .size() != 1)
            throw std::runtime_error(fmt::format(
                "get_installation_parameters: There is not exactly one installation parameters stop"
                "datagram in file nr {} [{}]!",
                this->get_file_nr(),
                this->get_file_path()));

        // get installation parameters start/stop and ...
        auto start = this->_datagram_infos_by_type
                         .at_const(t_EM3000DatagramIdentifier::InstallationParametersStart)[0]
                         ->template read_datagram_from_file<datagrams::InstallationParameters>();
        auto stop = this->_datagram_infos_by_type
                        .at_const(t_EM3000DatagramIdentifier::InstallationParametersStop)[0]
                        ->template read_datagram_from_file<datagrams::InstallationParameters>();

        // ... check that they are the same
        if (start.get_installation_parameters() != stop.get_installation_parameters())
            throw std::runtime_error(
                fmt::format("get_installation_parameters: Installation "
                            "parameters start and stop datagrams in file nr {} [{}]"
                            "are not the same!",
                            this->get_file_nr(),
                            this->get_file_path()));

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
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision));

        printer.register_section("EM3000ConfigurationDataInterfacePerFile");
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
} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping
