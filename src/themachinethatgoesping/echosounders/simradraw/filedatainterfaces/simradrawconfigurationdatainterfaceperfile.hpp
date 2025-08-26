// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/simradrawconfigurationdatainterfaceperfile.doc.hpp"

/* library includes */
#include <magic_enum/magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../datagrams.hpp"
#include "../types.hpp"
#include "simradrawdatagraminterface.hpp"

#include "../../filetemplates/datainterfaces/i_configurationdatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace filedatainterfaces {

template<typename t_ifstream>
class SimradRawConfigurationDataInterfacePerFile
    : public filetemplates::datainterfaces::I_ConfigurationDataInterfacePerFile<
          SimradRawDatagramInterface<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_ConfigurationDataInterfacePerFile<
        SimradRawDatagramInterface<t_ifstream>>;

  public:
    SimradRawConfigurationDataInterfacePerFile()
        : t_base("SimradRawConfigurationDataInterfacePerFile")
    {
    }
    ~SimradRawConfigurationDataInterfacePerFile() = default;

    navigation::SensorConfiguration read_sensor_configuration() final
    {
        auto configuration_datagram = this->get_configuration_datagram();
        // get sensor configuration
        return configuration_datagram.get_sensor_configuration();
    }

    // --------------------- simradraw specific functions ---------------------
    /* get infos */
    
    /**
     * @brief Get configuration datagram from file
     * @return XML Configuration datagram
     */
    datagrams::xml_datagrams::XML_Configuration get_configuration_datagram();

    /**
     * @brief Read the fil1 datagrams from the file and return them as a map with the channel ID as
     * key and a pair of stage 1 and stage 2 datagrams. Function will fail if a channel id does not
     * exactly have two stages or if it detects a duplicated channel/stage
     *
     * @return std::map<std::string, std::pair<datagrams::FIL1, datagrams::FIL1>>
     */
    std::map<std::string, std::pair<datagrams::FIL1, datagrams::FIL1>> read_fil1_datagrams();

    /* get other possible sensor sources */
    /**
     * @brief Return all position sources registered in the configuration datagram (sorted by
     * priority)
     *
     * @return std::vector<XML_Configuration_Sensor>
     */
    std::vector<datagrams::xml_datagrams::XML_Configuration_Sensor> get_position_sources()
    {
        auto configuration_datagram = this->get_configuration_datagram();
        // get sensor configuration
        return configuration_datagram.get_sensors_sorted_by_priority({ "Latitude", "Longitude" });
    }

    /**
     * @brief Return all depth sources registered in the configuration datagram (sorted by priority)
     *
     * @return std::vector<XML_Configuration_Sensor>
     */
    std::vector<datagrams::xml_datagrams::XML_Configuration_Sensor> get_depth_sources()
    {
        auto configuration_datagram = this->get_configuration_datagram();
        // get sensor configuration
        return configuration_datagram.get_sensors_sorted_by_priority({ "Heave" });
    }

    /**
     * @brief Return all attitude sources registered in the configuration datagram (sorted by
     * priority)
     *
     * @return std::vector<XML_Configuration_Sensor>
     */
    std::vector<datagrams::xml_datagrams::XML_Configuration_Sensor> get_attitude_sources()
    {
        auto configuration_datagram = this->get_configuration_datagram();
        // get sensor configuration
        return configuration_datagram.get_sensors_sorted_by_priority({ "Roll", "Pitch", "Heave" });
    }

    /**
     * @brief Return all heading sources registered in the configuration datagram (sorted by
     * priority)
     *
     * @return std::vector<XML_Configuration_Sensor>
     */
    std::vector<datagrams::xml_datagrams::XML_Configuration_Sensor> get_heading_sources()
    {
        auto configuration_datagram = this->get_configuration_datagram();
        // get sensor configuration
        return configuration_datagram.get_sensors_sorted_by_priority({ "Heading" });
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents)
    {
        tools::classhelper::ObjectPrinter printer(
            this->class_name(), float_precision, superscript_exponents);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision, superscript_exponents));

        printer.register_section("SimradRawConfigurationDataInterfacePerFile");
        auto position_sources = this->get_position_sources();
        auto heading_sources  = this->get_heading_sources();
        auto attitude_sources = this->get_attitude_sources();
        auto depth_sources    = this->get_depth_sources();

        printer.register_string("Position source",
                                fmt::format("'{}'", position_sources[0].Name),
                                position_sources.size() < 2
                                    ? ""
                                    : fmt::format("Alternatives: {}", position_sources.size() - 1));
        printer.register_string("Heading source",
                                fmt::format("'{}'", heading_sources[0].Name),
                                heading_sources.size() < 2
                                    ? ""
                                    : fmt::format("Alternatives: {}", heading_sources.size() - 1));
        printer.register_string("Attitude source",
                                fmt::format("'{}'", attitude_sources[0].Name),
                                attitude_sources.size() < 2
                                    ? ""
                                    : fmt::format("Alternatives: {}", attitude_sources.size() - 1));
        printer.register_string("Depth source",
                                fmt::format("'{}'", depth_sources[0].Name),
                                depth_sources.size() < 2
                                    ? ""
                                    : fmt::format("Alternatives: {}", depth_sources.size() - 1));

        return printer;
    }
};

}
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
