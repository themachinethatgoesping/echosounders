// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/xml_environment.doc.hpp"

// std includes
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

#include <pugixml.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "helper.hpp"
#include "xml_environment_transducer.hpp"

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
struct XML_Environment
{
    double              WaterLevelDraft        = NAN;
    bool                DropKeelOffsetIsManual = false;
    double              DropKeelOffset         = NAN;
    std::vector<double> SoundVelocityProfile;
    bool                WaterLevelDraftIsManual = false;
    double              Latitude                = NAN;
    double              SoundSpeed              = NAN;
    double              Salinity                = NAN;
    std::string         SoundVelocitySource;
    double              Acidity     = NAN;
    double              Temperature = NAN;
    double              Depth       = NAN;

    bool   TowedBodyDepthIsManual = false;
    double TowedBodyDepth         = NAN;

    std::vector<XML_Environment_Transducer> Transducers;

    int32_t unknown_children   = 0;
    int32_t unknown_attributes = 0;

  public:
    // ----- constructors -----
    XML_Environment() = default;
    XML_Environment(const pugi::xml_node& node) { initialize(node); }
    ~XML_Environment() = default;

    void initialize(const pugi::xml_node& root_node);

    bool parsed_completely() const;

    // ----- file I/O -----
    static XML_Environment from_stream(std::istream& is);

    void to_stream(std::ostream& os) const;

    // ----- operators -----
    bool operator==(const XML_Environment& other) const;
    bool operator!=(const XML_Environment& other) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__ __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(
        XML_Environment)
};

/**
 * @brief Provide a boost hash function for XML_Environment
 * - Note: this is needed to use XML_Environment as boost::flyweight
 *
 * @param data
 * @return std::size_t
 */
// IGNORE_DOC:__doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_hash_value
inline size_t hash_value(const XML_Environment& data)
{
    return data.binary_hash();
}

}
}
}
}
}