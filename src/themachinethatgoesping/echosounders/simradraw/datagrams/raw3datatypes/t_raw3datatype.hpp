// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/t_raw3datatype.doc.hpp"

// std includes
#include <bitset>
#include <string>
#include <unordered_map>
#include <vector>

#include <boost/algorithm/string.hpp>

// xtensor includes
#include <xtensor/containers/xadapt.hpp>

#include <xtensor/views/xview.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/helper.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../../types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace raw3datatypes {

/**
 * @brief This flag is used in the RAW3 datagram to indicate the type of data
 *
 */
enum class t_RAW3DataType : uint8_t
{
    Power          = 0b00000001,
    Angle          = 0b00000010,
    PowerAndAngle  = 0b00000011,
    ComplexFloat16 = 0b00000100,
    ComplexFloat32 = 0b00001000,
};

/**
 * @brief Get the size of the RAW3DataType elements in bytes
 * @param data_type
 * @return size_t
 */
inline size_t get_raw3datatype_size(t_RAW3DataType data_type)
{
    switch (data_type)
    {
        case t_RAW3DataType::PowerAndAngle:
            return sizeof(simradraw_short) * 2; // 1 short 2 bytes
        case t_RAW3DataType::ComplexFloat32:
            return sizeof(simradraw_complex_float);
        case t_RAW3DataType::Power:
            return sizeof(simradraw_short);
        case t_RAW3DataType::Angle: // 2 bytes
            return sizeof(simradraw_short);
        case t_RAW3DataType::ComplexFloat16:
            return sizeof(simradraw_float); // 2 times half
        default:
            throw(std::runtime_error("Unknown data type"));
    }
}

}
}
}
}
}