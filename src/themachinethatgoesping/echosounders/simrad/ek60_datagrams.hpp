// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include "datagrams/ek60_datagram.hpp"
#include "datagrams/ek60_unknown.hpp"

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


using t_EK60_DatagramVariant = std::variant
<
datagrams::EK60_Unknown
>;

} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoesping


