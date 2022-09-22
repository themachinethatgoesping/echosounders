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

#include "i_RAW3_data.hpp"
#include "t_RAW3_datatype.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {
namespace datagrams {
namespace RAW3_datatypes {

struct RAW3_DataAngle : public i_RAW3_Data
{
    xt::xtensor<uint8_t, 2> _angle; ///< Sample data

    RAW3_DataAngle()
        : i_RAW3_Data("Angle")
    {
    }
    RAW3_DataAngle(xt::xtensor<uint8_t, 2> angle)
        : i_RAW3_Data("Angle")
        , _angle(std::move(angle))
    {
    }
    ~RAW3_DataAngle() = default;

    static RAW3_DataAngle from_stream(std::istream& is,
                                      ek60_long     input_count,
                                      ek60_long     output_count)
    {
        using xt_shape = xt::xtensor<uint8_t, 2>::shape_type;
        RAW3_DataAngle data(xt::empty<uint8_t>(xt_shape({ unsigned(output_count),2 })));

        // initialize data_block using from_shape
        if (output_count < input_count)
        {
            is.read(reinterpret_cast<char*>(data._angle.data()),
                    output_count * sizeof(uint8_t) * 2);
        }
        else
        {
            is.read(reinterpret_cast<char*>(data._angle.data()), input_count * sizeof(uint8_t) * 2);

            // fill remaining samples with 0
            std::fill(data._angle.begin() + input_count * 2, data._angle.end(), 0);
        }
        return data;
    }

    void to_stream(std::ostream& os) const
    {
        os.write(reinterpret_cast<const char*>(_angle.data()),
                 xt::flatten(_angle).size() * sizeof(uint8_t));
        return;
    }
};

}
}
}
}
}