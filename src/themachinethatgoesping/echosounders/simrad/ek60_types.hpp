// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <themachinethatgoesping/tools/helper.hpp>
/**
 * @brief Type definitions for Ek60 types according to Ek60 Reference manual
 * see also http://www.simrad.net/ek60_ref_english/default.htm
 *
 * Note: these definitions are valid for EK60 and the EK80 files.
 */

/*  */
//
namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {

using ek60_char     = char;
using ek60_WORD     = uint16_t;
using ek60_short    = int16_t;
using ek60_Int      = int32_t;
using ek60_long     = int32_t; // no error, long is specified as 32bit int in manual
using ek60_float    = float;   // this must be 32bit!
using ek60_double   = double;  // this must be 64bit!
using ek60_DWORDLON = int64_t;

enum class t_EK60_DatagramType : ek60_long
{
    XML0 = 810306904, ///< Unspecified (unknown) XML datagram
    TAG0 = 809976148, ///< ???
    FIL1 = 827083078, ///< Filter datagram
    NME0 = 809848142, ///< Unspecified (unknown) NMEA datagram
    MRU0 = 810897997, ///< Motion datagram
    RAW3 = 861356370  ///< Raw sample data datagram
};

inline std::string datagram_type_to_string(ek60_long value)
{
    return tools::helper::int_as_string<ek60_long>(value);
}

inline ek60_long ek60_datagram_type_from_string(std::string_view value)
{
    return tools::helper::string_as_int<ek60_long>(value);
}


} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoesping

