// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

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

} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoesping
