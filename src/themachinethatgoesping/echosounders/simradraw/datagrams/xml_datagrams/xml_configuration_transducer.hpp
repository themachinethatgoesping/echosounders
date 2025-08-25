// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/xml_configuration_transducer.doc.hpp"

// std includes
#include <string>
#include <unordered_map>
#include <vector>

#include <pugixml.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/navigation/datastructures/positionaloffsets.hpp>

#include "helper.hpp"
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
struct XML_Configuration_Transducer
{
    double      TransducerAlphaX        = 0.;
    double      TransducerAlphaY        = 0.;
    double      TransducerAlphaZ        = 0.;
    double      TransducerOffsetX       = 0.;
    double      TransducerOffsetY       = 0.;
    double      TransducerOffsetZ       = 0.;
    double      HeadingQuickCalibration = 0.; ///< Seems to be used seldomly?
    int         TransducerSerialNumber  = -1;
    std::string TransducerMounting;
    std::string TransducerOrientation;
    std::string TransducerName;
    std::string TransducerCustomName;

    int32_t unknown_children   = 0;
    int32_t unknown_attributes = 0;

  public:
    // ----- constructors -----
    XML_Configuration_Transducer() = default;
    XML_Configuration_Transducer(const pugi::xml_node& node) { initialize(node); }
    ~XML_Configuration_Transducer() = default;

    // ----- methods -----
    /**
     * @brief Return the offsets as navigation::datastructures::PositionalOffsets structure
     *
     * @return navigation::datastructures::PositionalOffsets
     */
    navigation::datastructures::PositionalOffsets get_sensor_offsets() const;

    // ----- xml parsing -----

    void initialize(const pugi::xml_node& root_node);

    bool parsed_completely() const;

    // ----- file I/O -----
    static XML_Configuration_Transducer from_stream(std::istream& is);

    void to_stream(std::ostream& os) const;

    // ----- operators -----
    bool operator==(const XML_Configuration_Transducer& other) const;
    bool operator!=(const XML_Configuration_Transducer& other) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__ __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(
        XML_Configuration_Transducer)
};

}
}
}
}
}