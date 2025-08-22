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

#include <magic_enum/magic_enum.hpp>

#include <themachinethatgoesping/tools/helper/stringconversion.hpp>

/**
 * @brief Type definitions for Ek60 types according to Ek60 Reference manual
 * see also http://www.simradraw.net/simradraw_ref_english/default.htm
 *
 * Note: these definitions are valid for EK60 and the EK80 files.
 */

/*  */
//
namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {

using simradraw_char  = char;
using simradraw_WORD  = uint16_t;
using simradraw_short = int16_t;
using simradraw_Int   = int32_t;
using simradraw_long  = int32_t; // no error, long is specified as 32bit int in manual
using simradraw_float = float;   // this must be 32bit!
using simradraw_complex_float =
    std::complex<simradraw_float>; // complex real,imaginary (used in FIL1 and RAW3)
using simradraw_double   = double; // this must be 64bit!
using simradraw_DWORDLON = int64_t;

enum class t_SimradRawDatagramIdentifier : simradraw_long
{
    XML0 = 810306904, ///< Unspecified (unknown) XML datagram
    TAG0 = 809976148, ///< ???
    FIL1 = 827083078, ///< Filter datagram
    NME0 = 809848142, ///< Unspecified (unknown) NMEA datagram
    MRU0 = 810897997, ///< Motion datagram
    RAW3 = 861356370, ///< Raw sample data datagram
};

/**
 * @brief Convert datagram type from simradraw_long to string representation
 * 
 * @param value Datagram type as simradraw_long
 * @return std::string String representation of the datagram type
 */
std::string datagram_type_to_string(simradraw_long value);

/**
 * @brief Convert datagram type identifier to string representation
 * 
 * @param value Datagram type identifier
 * @return std::string String representation of the datagram type
 */
std::string datagram_type_to_string(t_SimradRawDatagramIdentifier value);

/**
 * @brief Parse datagram type from string representation
 * 
 * @param value String representation of datagram type
 * @return simradraw_long Parsed datagram type
 */
simradraw_long SimradRawDatagram_type_from_string(std::string_view value);

} // namespace simradraw

// ----- interface? -----

/**
 * @brief Convert datagram identifier to string representation
 * 
 * @param value Datagram identifier to convert
 * @return std::string String representation of the identifier
 */
std::string datagram_identifier_to_string(simradraw::t_SimradRawDatagramIdentifier value);

/**
 * @brief Convert vector of datagram identifiers to vector of strings
 * 
 * @param values Vector of datagram identifiers
 * @return std::vector<std::string> Vector of string representations
 */
std::vector<std::string> datagram_identifiers_to_string(
    const std::vector<simradraw::t_SimradRawDatagramIdentifier>& values);

/**
 * @brief Convert set of datagram identifiers to vector of strings
 * 
 * @param values Set of datagram identifiers
 * @return std::vector<std::string> Vector of string representations
 */
std::vector<std::string> datagram_identifiers_to_string(
    const std::set<simradraw::t_SimradRawDatagramIdentifier>& values);

/**
 * @brief Get descriptive information about a datagram type
 * 
 * @param datagram_type Datagram identifier to describe
 * @return std::string Human-readable description of the datagram type
 */
std::string datagram_identifier_info(simradraw::t_SimradRawDatagramIdentifier datagram_type);

} // namespace echosounders


} // namespace themachinethatgoesping
