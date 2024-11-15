// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/types.doc.hpp"

#include <set>

#include <magic_enum/magic_enum.hpp>

#include <themachinethatgoesping/tools/helper.hpp>
#include <themachinethatgoesping/tools/helper/enum.hpp>

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

inline std::string datagram_type_to_string(simradraw_long value)
{
    return tools::helper::int_as_string<simradraw_long>(value);
}

inline std::string datagram_type_to_string(t_SimradRawDatagramIdentifier value)
{
    return tools::helper::int_as_string<simradraw_long>(simradraw_long(value));
}

inline simradraw_long SimradRawDatagram_type_from_string(std::string_view value)
{
    return tools::helper::string_as_int<simradraw_long>(value);
}

} // namespace simradraw

// ----- interface? -----

// IGNORE_DOC:__doc_themachinethatgoesping_echosounders_datagram_identifier_to_string
inline std::string datagram_identifier_to_string(simradraw::t_SimradRawDatagramIdentifier value)
{
    return tools::helper::int_as_string<simradraw::simradraw_long>(
        simradraw::simradraw_long(value));
}

inline std::vector<std::string> datagram_identifiers_to_string(
    const std::vector<simradraw::t_SimradRawDatagramIdentifier>& values)
{
    std::vector<std::string> result;
    for (auto value : values)
    {
        result.push_back(datagram_identifier_to_string(value));
    }
    return result;
}

inline std::vector<std::string> datagram_identifiers_to_string(
    const std::set<simradraw::t_SimradRawDatagramIdentifier>& values)
{
    std::vector<std::string> result;
    for (auto value : values)
    {
        result.push_back(datagram_identifier_to_string(value));
    }
    return result;
}

// IGNORE_DOC:__doc_themachinethatgoesping_echosounders_datagram_identifier_info
inline std::string datagram_identifier_info(simradraw::t_SimradRawDatagramIdentifier datagram_type)
{
    // this should work, but doesn't
    // return magic_enum::enum_contains(datagram_type);
    using simradraw::t_SimradRawDatagramIdentifier;

    switch (datagram_type)
    {
        case t_SimradRawDatagramIdentifier::MRU0:
            return "Motion binary datagram";
        case t_SimradRawDatagramIdentifier::NME0:
            return "NMEA text datagram";
        case t_SimradRawDatagramIdentifier::XML0:
            return "XML0 text datagram";
        case t_SimradRawDatagramIdentifier::TAG0:
            return "Annotation datagram";
        case t_SimradRawDatagramIdentifier::FIL1:
            return "Filter binary datagram";
        case t_SimradRawDatagramIdentifier::RAW3:
            return "Sample binary datagram";
        default:
            return "unknown (" + std::to_string(magic_enum::enum_integer(datagram_type)) + ")";
    }
}

} // namespace echosounders

// t_SimradRawDatagramIdentifier is not compatible with magic enum because the enum value range is
// much to large
namespace tools {
namespace helper {
// IGNORE_DOC: __doc_themachinethatgoesping_tools_helper_is_magic_enum_compatible
template<>
struct is_magic_enum_compatible<echosounders::simradraw::t_SimradRawDatagramIdentifier>
{
    using type = echosounders::simradraw::t_SimradRawDatagramIdentifier; // type is output type
    static constexpr int value =
        false; // not compatible with magic enum because the enum value range is much to large

    // static constexpr bool operator()() { return value; } TODO: add this in c++23
};
}
}

} // namespace themachinethatgoesping

// ----- magic_enum customizations -----
// otherwise min/max range is -128 - 127
// template <>
// struct
// magic_enum::customize::enum_range<themachinethatgoesping::echosounders::simradraw::t_SimradRawDatagramIdentifier>
// {
//   static constexpr int min = 809848142;
//   static constexpr int max = 861356370;
//   // (max - min) must be less than UINT16_MAX.
// };