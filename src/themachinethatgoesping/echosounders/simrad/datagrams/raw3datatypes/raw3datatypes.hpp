// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/raw3datatypes.doc.hpp"

// std includes
#include <variant>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/helper.hpp>

#include "raw3dataangle.hpp"
#include "raw3datapower.hpp"
#include "raw3datapowerandangle.hpp"
#include "i_raw3data.hpp"
#include "raw3dataskipped.hpp"
#include "t_raw3datatype.hpp"
// #include "raw3datacomplexfloat16.hpp" // not implemented
#include "raw3datacomplexfloat32.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace datagrams {
namespace raw3datatypes {

/**
 * @brief This variant is used within the RAW3 datagram to store the different data types.
 *
 */
using RAW3DataVariant = std::variant<RAW3DataSkipped,
                                     RAW3DataComplexFloat32,
                                     RAW3DataPowerAndAngle,
                                     RAW3DataPower,
                                     RAW3DataAngle>;

}
}
}
}
}