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

struct RAW3_DataPowerAndAngle : public i_RAW3_Data
{
    xt::xarray<ek60_short> _power_and_angle;        ///< Sample data
    // xt::xarray<uint8_t>    _angle_along;  ///< alongship angle
    // xt::xarray<uint8_t>    _angle_across; ///< athwartship angle

    RAW3_DataPowerAndAngle()
        : i_RAW3_Data("PowerAndAngle")
    {
    }
    ~RAW3_DataPowerAndAngle() = default;

    inline static RAW3_DataPowerAndAngle from_stream(std::istream& is,
                                                  ek60_long     input_count,
                                                  ek60_long     output_count)
    {
        // (void)(output_count);
        RAW3_DataPowerAndAngle data;

        data._power_and_angle.resize({ 2, unsigned(output_count) }, 0);

        // initialize data_block using from_shape
        if (output_count < input_count){
        is.read(reinterpret_cast<char*>(data._power_and_angle.data()), output_count * 2 * sizeof(ek60_short));
        }        
        else{
        is.read(reinterpret_cast<char*>(data._power_and_angle.data()), input_count * 2* sizeof(ek60_short));
        }

        // xt::xarray<ek60_short> power = xt::view(data_block, 0, xt::all());
        // auto angle_view = xt::view(data_block, 1, xt::all());

        // //reinterpret 16 bit angle array as two 8 bit arrays
        // xt::xarray<uint8_t> angle_along = xt::view(angle_view, xt::range(0, angle_view.size(), 2));
        // xt::xarray<uint8_t> angle_across = xt::view(angle_view, xt::range(1, angle_view.size(), 2));


        return data;
    }

    inline void to_stream(std::ostream& os) const
    {
        os.write(reinterpret_cast<const char*>(_power_and_angle.data()), _power_and_angle.size() * sizeof(ek60_short));
        return;

        // if (_power.size() != _angle_along.size() || _power.size() != _angle_across.size())
        //     throw std::runtime_error("RAW3_DataPowerAndAngle::to_stream: inconsistent data size");

        // for (size_t i = 0; i < _power.size(); ++i)
        // {
        //     os.write(reinterpret_cast<const char*>(&_power[i]), sizeof(ek60_short));
        //     os.write(reinterpret_cast<const char*>(&_angle_along[i]), sizeof(uint8_t));
        //     os.write(reinterpret_cast<const char*>(&_angle_across[i]), sizeof(uint8_t));
        // }
    }
};

}
}
}
}
}