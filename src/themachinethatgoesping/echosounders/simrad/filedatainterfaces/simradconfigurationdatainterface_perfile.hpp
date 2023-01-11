// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/simradconfigurationdatainterface_perfile.doc.hpp"

/* library includes */
#include <magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../filetemplates/datainterfaces/i_configurationdatainterface.hpp"

#include "../simrad_datagrams.hpp"
#include "../simrad_types.hpp"
#include "simraddatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace filedatainterfaces {

template<typename t_ifstream>
class SimradConfigurationDataInterface_PerFile
    : public filetemplates::datainterfaces::I_ConfigurationDataInterface_PerFile<
          SimradDatagramInterface<t_ifstream>>
{
    using t_base = filetemplates::datainterfaces::I_ConfigurationDataInterface_PerFile<
        SimradDatagramInterface<t_ifstream>>;

  public:
    SimradConfigurationDataInterface_PerFile()
        : t_base("SimradConfigurationDataInterface_PerFile")
    {
    }
    ~SimradConfigurationDataInterface_PerFile() = default;

    navigation::SensorConfiguration read_sensor_configuration() final
    {
        auto configuration_datagram = this->get_configuration_datagram();
        // get sensor configuration
        return configuration_datagram.get_sensor_configuration();
    }

    // --------------------- simrad specific functions ---------------------
    /* get infos */
    datagrams::xml_datagrams::XML_Configuration get_configuration_datagram()
    {
        // get datagram infos for XML0 packets
        const auto& datagram_infos =
            this->_datagram_infos_by_type.at_const(t_SimradDatagramIdentifier::XML0);

        // check that there is a configuration datagram
        if (datagram_infos.empty())
            throw std::runtime_error(fmt::format(
                "read_sensor_configuration: No XML0 datagram found in {}!", this->get_file_path()));

        // read first xml datagram (this should be the configuration datagram))
        auto xml0_datagram = datagram_infos[0]->template read_datagram_from_file<datagrams::XML0>();

        // check that this datagram is a configuration datagram
        if (xml0_datagram.get_xml_datagram_type() != "Configuration")
            throw std::runtime_error(
                fmt::format("read_sensor_configuration: First XML0 datagram in {} is not a "
                            "configuration datagram! ['{}' != 'Configuration']",
                            this->get_file_path(),
                            xml0_datagram.get_xml_datagram_type()));

        // decode configuration datagram
        return std::get<datagrams::xml_datagrams::XML_Configuration>(xml0_datagram.decode());
    }

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
        return configuration_datagram.get_sensors_sorted_by_priority({ "Latitude", "Longitude" });
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
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision)
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        // printer.register_section("DatagramInterface");
        printer.append(t_base::__printer__(float_precision));

        printer.register_section("SimradConfigurationDataInterface_PerFile");
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
} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoesping
