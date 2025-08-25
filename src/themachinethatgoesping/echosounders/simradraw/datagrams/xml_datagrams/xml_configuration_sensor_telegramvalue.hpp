// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/xml_configuration_sensor_telegramvalue.doc.hpp"

// std includes
#include <string>

// pugixml
#include <pugixml.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace xml_datagrams {

/**
 * @brief XML Configuration Sensor Telegram Value (single <Value> node).
 */
struct XML_Configuration_Sensor_TelegramValue
{
    int         Priority = 0;
    std::string Name;

    int32_t unknown_children   = 0;
    int32_t unknown_attributes = 0;

  public:
    // ----- constructors -----
    XML_Configuration_Sensor_TelegramValue() = default;
    explicit XML_Configuration_Sensor_TelegramValue(const pugi::xml_node& node);
    ~XML_Configuration_Sensor_TelegramValue() = default;

    /**
     * @brief Initialize from a <Value> XML node.
     * @throws std::runtime_error if root node is not <Value>.
     */
    void initialize(const pugi::xml_node& root_node);

    /**
     * @brief Returns true if no unknown children/attributes were encountered.
     */
    bool parsed_completely() const;

    // ----- file I/O -----
    static XML_Configuration_Sensor_TelegramValue from_stream(std::istream& is);
    void                                          to_stream(std::ostream& os) const;

    // ----- operators -----
    bool operator==(const XML_Configuration_Sensor_TelegramValue& other) const;
    bool operator!=(const XML_Configuration_Sensor_TelegramValue& other) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(XML_Configuration_Sensor_TelegramValue)
};

} // namespace xml_datagrams
} // namespace datagrams
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping