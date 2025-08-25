// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/xml_configuration_sensor.doc.hpp"

// std includes
#include <string>
#include <vector>

#include <pugixml.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include <themachinethatgoesping/navigation/datastructures/positionaloffsets.hpp>

#include "helper.hpp"
#include "xml_configuration_sensor_telegram.hpp"
#include "xml_node.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace xml_datagrams {

/**
 * @brief XML base datagram
 *
 */
struct XML_Configuration_Sensor
{
    double      Timeout = 20;
    int         Unique  = 0; // TODO: value type?
    double      AngleZ  = 0.;
    double      AngleY  = 0.;
    double      AngleX  = 0.;
    double      Y       = 0.;
    double      X       = 0.;
    double      Z       = 0.;
    std::string Port;
    std::string Type;
    std::string Name;
    std::string TalkerID;

    std::vector<XML_Configuration_Sensor_Telegram> Telegrams;

    int32_t unknown_children   = 0;
    int32_t unknown_attributes = 0;

  public:
    // ----- constructors -----
    XML_Configuration_Sensor() = default;
    XML_Configuration_Sensor(const pugi::xml_node& node) { initialize(node); }
    ~XML_Configuration_Sensor() = default;

    // ----- methods -----
    /**
     * @brief Return the sensor offsets as navigation::datastructures::PositionalOffsets structure
     *
     * @return navigation::datastructures::PositionalOffsets
     */
    navigation::datastructures::PositionalOffsets get_sensor_offsets() const
    {
        // TODO: check angle directions
        return navigation::datastructures::PositionalOffsets(Name, X, Y, Z, AngleZ, AngleY, AngleX);
    }

    // ----- xml decode methods -----

    void initialize(const pugi::xml_node& root_node);

    bool parsed_completely() const { return unknown_children == 0 && unknown_attributes == 0; }

    // ----- file I/O -----
    static XML_Configuration_Sensor from_stream(std::istream& is);
    void to_stream(std::ostream& os) const;

    // ----- operators -----
    bool operator==(const XML_Configuration_Sensor& other) const;
    bool operator!=(const XML_Configuration_Sensor& other) const { return !operator==(other); }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__ __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(
        XML_Configuration_Sensor)
};

}
}
}
}
}