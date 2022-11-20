// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* library includes */
#include <magic_enum.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../fileinterfaces/i_configurationdatainterface.hpp"

#include "simrad_datagrams.hpp"
#include "simrad_types.hpp"
#include "simraddatagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {

template<typename t_ifstream>
class SimradConfigurationDataCollection
    : public fileinterfaces::I_ConfigurationDataCollection<SimradDatagramInterface<t_ifstream>>
{
    using t_base =
        fileinterfaces::I_ConfigurationDataCollection<SimradDatagramInterface<t_ifstream>>;

  public:
    SimradConfigurationDataCollection()
        : t_base("SimradConfigurationDataCollection")
    {
    }
    ~SimradConfigurationDataCollection() = default;

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
};

template<typename t_ifstream>
class SimradConfigurationDataInterface
    : public fileinterfaces::I_ConfigurationDataInterface<
          SimradConfigurationDataCollection<t_ifstream>>
{
    using t_base =
        fileinterfaces::I_ConfigurationDataInterface<SimradConfigurationDataCollection<t_ifstream>>;

  public:
    SimradConfigurationDataInterface()
        : t_base("SimradConfigurationDataInterface")
    {
    }
    ~SimradConfigurationDataInterface() = default;
};

} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoesping
