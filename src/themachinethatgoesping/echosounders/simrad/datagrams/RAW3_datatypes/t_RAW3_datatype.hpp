// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

// std includes
#include <bitset>
#include <string>
#include <unordered_map>
#include <vector>

#include <boost/algorithm/string.hpp>

// xtensor includes
#include <xtensor/xadapt.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xview.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelpers/objectprinter.hpp>
#include <themachinethatgoesping/tools/helper.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../../ek60_types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace datagrams {
namespace RAW3_datatypes {

enum class t_RAW3_DataType : uint8_t
{
    Power          = 0b00000001,
    Angle          = 0b00000010,
    PowerAndAngle  = 0b00000011,
    ComplexFloat16 = 0b00000100,
    ComplexFloat32 = 0b00001000,
};

inline size_t RAW3_DataType_size(t_RAW3_DataType data_type)
{
    switch (data_type)
    {
        case t_RAW3_DataType::PowerAndAngle:
            return sizeof(ek60_short) * 2; // 1 short 2 bytes
        case t_RAW3_DataType::ComplexFloat32:
            return sizeof(ek60_complex_float);
        case t_RAW3_DataType::Power:
            return sizeof(ek60_short);
        case t_RAW3_DataType::Angle: // 2 bytes
            return sizeof(ek60_short);
        case t_RAW3_DataType::ComplexFloat16:
            return sizeof(ek60_float); // 2 times half
        default:
            throw(std::runtime_error("Unknown data type"));
    }
}

}
}
}
}
}