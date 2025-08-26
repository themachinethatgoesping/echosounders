// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/xml_configuration.doc.hpp"

// std includes
#include <map>
#include <string>
#include <vector>

// pugixml
#include <pugixml.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/navigation/sensorconfiguration.hpp>

#include "xml_configuration_sensor.hpp"
#include "xml_configuration_transceiver.hpp"
#include "xml_configuration_transducer.hpp"
#include "xmlconfigurationactivepingmode.hpp"
#include "channelconfiguration.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace xml_datagrams {

/**
 * @brief XML Configuration datagram structure.
 */
struct XML_Configuration
{
    // Header attributes
    std::string FileFormatVersion;
    std::string Version;
    std::string TimeBias;
    std::string ApplicationName;
    std::string Copyright;

    std::vector<XML_Configuration_Sensor>      ConfiguredSensors;
    std::vector<XML_Configuration_Transducer>  Transducers;
    std::vector<XML_Configuration_Transceiver> Transceivers;
    XMLConfigurationActivePingMode             ActivePingMode;

    int32_t unknown_children   = 0;
    int32_t unknown_attributes = 0;

    std::map<std::string, ChannelConfiguration>                  ChannelConfigurations;
    std::map<std::string, std::vector<XML_Configuration_Sensor>> SensorConfigurations = {
        { "fallback", { XML_Configuration_Sensor() } }
    };

  public:
    // ----- constructors -----
    XML_Configuration() = default;
    explicit XML_Configuration(const pugi::xml_node& node);
    ~XML_Configuration() = default;

    const XML_Configuration_Transceiver& get_transceiver(std::string_view channel_id) const;
    std::map<std::string, XML_Configuration_Transceiver> get_transceivers() const;
    const XML_Configuration_Transceiver_Channel& get_transceiver_channel(std::string_view channel_id) const;
    std::map<std::string, XML_Configuration_Transceiver_Channel> get_transceiver_channels() const;

    navigation::SensorConfiguration get_sensor_configuration() const;
    XML_Configuration_Sensor get_prioritized_sensor(const std::vector<std::string_view>& prio_values) const;
    std::vector<XML_Configuration_Sensor> get_sensors_sorted_by_priority(const std::vector<std::string_view>& prio_values) const;

    void initialize_sensorconfigurations();
    void initialize_channelconfigurations();
    void initialize(const pugi::xml_node& root_node);
    bool parsed_completely() const;

    // ----- file I/O -----
    static XML_Configuration from_stream(std::istream& is);
    void to_stream(std::ostream& os) const;

    // ----- operators -----
    bool operator==(const XML_Configuration& other) const;
    bool operator!=(const XML_Configuration& other) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__ 
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(XML_Configuration)
};

} // namespace xml_datagrams
} // namespace datagrams
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping