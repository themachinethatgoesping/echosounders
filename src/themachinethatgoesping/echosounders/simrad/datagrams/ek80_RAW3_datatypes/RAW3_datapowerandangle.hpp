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
#include <xtensor/xio.hpp>

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
    xt::xtensor<ek60_short, 2> _power_and_angle; ///< Sample data
    // xt::xtensor<uint8_t>    _angle_along;  ///< alongship angle
    // xt::xtensor<uint8_t>    _angle_across; ///< athwartship angle

    RAW3_DataPowerAndAngle()
        : i_RAW3_Data("PowerAndAngle")
    {
    }
    RAW3_DataPowerAndAngle(xt::xtensor<ek60_short, 2> power_and_angle)
        : i_RAW3_Data("PowerAndAngle")
        , _power_and_angle(std::move(power_and_angle))
    {
    }
    ~RAW3_DataPowerAndAngle() = default;

    // ----- operator overloads -----
    bool operator==(const RAW3_DataPowerAndAngle& other) const { return _power_and_angle == other._power_and_angle; }
    bool operator!=(const RAW3_DataPowerAndAngle& other) const { return !(operator==(other)); }

    static RAW3_DataPowerAndAngle from_stream(std::istream& is,
                                              ek60_long     input_count,
                                              ek60_long     output_count)
    {
        using xt_shape = xt::xtensor<ek60_short, 2>::shape_type;
        RAW3_DataPowerAndAngle data(xt::empty<ek60_short>(xt_shape({ unsigned(output_count), 2 })));

        // initialize data_block using from_shape
        if (output_count <= input_count)
        {
            is.read(reinterpret_cast<char*>(data._power_and_angle.data()),
                    output_count * 2 * sizeof(ek60_short));
        }
        else
        {
            is.read(reinterpret_cast<char*>(data._power_and_angle.data()),
                    input_count * 2 * sizeof(ek60_short));

            // fill remaining samples with quiet NaN
            std::fill(data._power_and_angle.begin() + input_count * 2,
                      data._power_and_angle.end(),
                      0);
        }

       
        return data;
    }

    void to_stream(std::ostream& os) const
    {
        os.write(reinterpret_cast<const char*>(_power_and_angle.data()),
                 xt::flatten(_power_and_angle).size() * sizeof(ek60_short));
      
    }


    // ----- objectprinter -----
    tools::classhelpers::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelpers::ObjectPrinter printer("Sample binary data (Power and Angle)", float_precision);

        std::stringstream ss1,ss2;
        ss1 << xt::col(_power_and_angle,0) * 10 * log10(2.0) / 256;
        ss2 << xt::col(_power_and_angle,1);


        printer.register_string("Power", ss1.str());
        printer.register_string("Angle", ss2.str());

        return printer;
    }
};

}
}
}
}
}