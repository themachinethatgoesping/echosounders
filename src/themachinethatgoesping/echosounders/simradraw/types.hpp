// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
#pragma once

/* generated doc strings */
#include ".docstrings/types.doc.hpp"

#include <complex>
#include <set>
#include <vector>
#include <string>
#include <string_view>

#include <magic_enum/magic_enum.hpp>

#include <themachinethatgoesping/tools/helper/stringconversion.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {

using simradraw_char  = char;
using simradraw_WORD  = uint16_t;
using simradraw_short = int16_t;
using simradraw_Int   = int32_t;
using simradraw_long  = int32_t;
using simradraw_float = float;
using simradraw_complex_float = std::complex<simradraw_float>;
using simradraw_double        = double;
using simradraw_DWORDLON      = int64_t;

/**
 * @brief Datagram identifiers used in Simrad raw (EK60/EK80) files.
 */
enum class t_SimradRawDatagramIdentifier : simradraw_long
{
    XML0 = 810306904, ///< Unspecified (unknown) XML datagram
    TAG0 = 809976148, ///< Annotation datagram
    FIL1 = 827083078, ///< Filter datagram
    NME0 = 809848142, ///< Unspecified (unknown) NMEA datagram
    MRU0 = 810897997, ///< Motion datagram
    RAW3 = 861356370, ///< Raw sample data datagram
};

/**
 * @brief Convert datagram type from simradraw_long to string representation.
 * @param value Datagram type as simradraw_long.
 * @return String representation (decimal) of the datagram type.
 */
inline std::string datagram_type_to_string(simradraw_long value)
{
    return tools::helper::int_as_string<simradraw_long>(value);
}

/**
 * @brief Convert datagram type identifier to string representation.
 * @param value Datagram type identifier enum.
 * @return String representation (decimal) of the datagram type.
 */
inline std::string datagram_type_to_string(t_SimradRawDatagramIdentifier value)
{
    return tools::helper::int_as_string<simradraw_long>(simradraw_long(value));
}

/**
 * @brief Parse datagram type from string representation.
 * @param value String view containing decimal representation.
 * @return Parsed datagram type numeric value.
 */
inline simradraw_long SimradRawDatagram_type_from_string(std::string_view value)
{
    return tools::helper::string_as_int<simradraw_long>(value);
}

} // namespace simradraw

// ----- interface utility functions -----

//IGNORE_DOC:__doc_themachinethatgoesping_echosounders_datagram_identifier_to_string
/**
 * @brief Convert datagram identifier enum to string.
 * @param value Datagram identifier.
 * @return Decimal string representation.
 */
inline std::string datagram_identifier_to_string(
    simradraw::t_SimradRawDatagramIdentifier value)
{
    return tools::helper::int_as_string<simradraw::simradraw_long>(
        simradraw::simradraw_long(value));
}

/**
 * @brief Convert vector of datagram identifiers to vector of strings.
 * @param values Vector of identifiers.
 * @return Vector of decimal string representations.
 */
inline std::vector<std::string> datagram_identifiers_to_string(
    const std::vector<simradraw::t_SimradRawDatagramIdentifier>& values)
{
    std::vector<std::string> result;
    result.reserve(values.size());
    for (auto v : values)
        result.push_back(datagram_identifier_to_string(v));
    return result;
}

/**
 * @brief Convert set of datagram identifiers to vector of strings.
 * @param values Set of identifiers.
 * @return Vector of decimal string representations (in set iteration order).
 */
inline std::vector<std::string> datagram_identifiers_to_string(
    const std::set<simradraw::t_SimradRawDatagramIdentifier>& values)
{
    std::vector<std::string> result;
    result.reserve(values.size());
    for (auto v : values)
        result.push_back(datagram_identifier_to_string(v));
    return result;
}

/**
 * @brief Get descriptive information about a datagram type.
 * @param datagram_type Datagram identifier.
 * @return Human-readable description.
 */
inline std::string datagram_identifier_info(
    simradraw::t_SimradRawDatagramIdentifier datagram_type)
{
    using simradraw::t_SimradRawDatagramIdentifier;
    switch (datagram_type)
    {
        case t_SimradRawDatagramIdentifier::MRU0: return "Motion binary datagram";
        case t_SimradRawDatagramIdentifier::NME0: return "NMEA text datagram";
        case t_SimradRawDatagramIdentifier::XML0: return "XML0 text datagram";
        case t_SimradRawDatagramIdentifier::TAG0: return "Annotation datagram";
        case t_SimradRawDatagramIdentifier::FIL1: return "Filter binary datagram";
        case t_SimradRawDatagramIdentifier::RAW3: return "Sample binary datagram";
        default:
            return "unknown (" +
                   std::to_string(magic_enum::enum_integer(datagram_type)) + ")";
    }
}

} // namespace echosounders
} // namespace themachinethatgoesping
