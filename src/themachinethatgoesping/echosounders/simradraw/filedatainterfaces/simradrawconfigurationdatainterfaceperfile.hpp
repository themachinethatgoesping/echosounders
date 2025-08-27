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
    datagrams::xml_datagrams::XML_Configuration get_configuration_datagram()
    {
        // get datagram infos for XML0 packets
        const auto& datagram_infos =
            this->_datagram_infos_by_type.at_const(t_SimradRawDatagramIdentifier::XML0);

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

    /**
     * @brief Read the fil1 datagrams from the file and return them as a map with the channel ID as
     * key and a pair of stage 1 and stage 2 datagrams. Function will fail if a channel id does not
     * exactly have two stages or if it detects a duplicated channel/stage
     *
     * @return std::map<std::string, std::pair<datagrams::FIL1, datagrams::FIL1>>
     */
    std::map<std::string, std::pair<datagrams::FIL1, datagrams::FIL1>> read_fil1_datagrams()
    {
        std::map<std::string, std::pair<datagrams::FIL1, datagrams::FIL1>> fil1_datagrams;

        // get datagram infos for FIL1 packets
        const auto& datagram_infos =
            this->_datagram_infos_by_type.at_const(t_SimradRawDatagramIdentifier::FIL1);

        // check that there are filter datagrams
        if (datagram_infos.empty())
            return fil1_datagrams;

        // read all filter datagrams
        for (const auto& datagram_info : datagram_infos)
        {
            auto fil1_datagram = datagram_info->template read_datagram_from_file<datagrams::FIL1>();

            const auto channel_id = std::string(fil1_datagram.get_channel_id_stripped());
            const auto stage      = fil1_datagram.get_stage();

            switch (stage)
            {
                case 1:
                    if (!fil1_datagrams[channel_id].first.get_channel_id_stripped().empty())
                        throw std::runtime_error(fmt::format(
                            "read_fil1_datagrams: Duplicate stage nr {} for channel {} in {}!",
                            stage,
                            channel_id,
                            this->get_file_path()));

                    fil1_datagrams[channel_id].first = fil1_datagram;
                    break;
                case 2:
                    if (!fil1_datagrams[channel_id].second.get_channel_id_stripped().empty())
                        throw std::runtime_error(fmt::format(
                            "read_fil1_datagrams: Duplicate stage nr {} for channel {} in {}!",
                            stage,
                            channel_id,
                            this->get_file_path()));

                    fil1_datagrams[channel_id].second = fil1_datagram;
                    break; // ok
                default:
                    throw std::runtime_error(
                        fmt::format("read_fil1_datagrams: Invalid stage nr {} for channel {} in "
                                    "{}! (only 1 and 2 are allowed)",
                                    stage,
                                    channel_id,
                                    this->get_file_path()));
            }
        }

        // check that both stages are present for each detected channel_id
        for (const auto& [channel_id, stages] : fil1_datagrams)
        {
            if (stages.first.get_channel_id_stripped().empty())
                throw std::runtime_error(
                    fmt::format("read_fil1_datagrams: Missing stage {} for channel {} in {}!",
                                0,
                                channel_id,
                                this->get_file_path()));
            if (stages.second.get_channel_id_stripped().empty())
                throw std::runtime_error(
                    fmt::format("read_fil1_datagrams: Missing stage {} for channel {} in {}!",
                                1,
                                channel_id,
                                this->get_file_path()));
        }

        return fil1_datagrams;
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
                                                  bool         superscript_exponents);
};

}
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
