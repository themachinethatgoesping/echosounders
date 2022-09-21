// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

// std includes
#include <variant>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/helper.hpp>

#include "t_RAW3_datatype.hpp"
#include "i_RAW3_data.hpp"
#include "RAW3_dataskipped.hpp"
// #include "RAW3_datatype_power.hpp"
// #include "RAW3_datatype_angle.hpp"
// #include "RAW3_datatype_powerandangle.hpp"
// #include "RAW3_datatype_complexfloat16.hpp"
// #include "RAW3_datatype_complexfloat32.hpp"


namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace datagrams {
namespace RAW3_datatypes {

using RAW3_DataVariant = std::variant<RAW3_DataSkipped>;


}
}
}
}
}