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
#include <xtensor/xio.hpp>
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

    // ----- i_RAW3_Data interface -----
    bool has_power() const final { return false; }
    bool has_angle() const final { return true; }

    xt::xtensor<uint8_t, 2> get_angle() const final
    {
        throw std::runtime_error("get_angle() not yet implemented for " + std::string(get_name()));
    }
    xt::xtensor<uint8_t, 1> get_angle_along() const final
    {
        throw std::runtime_error("get_angle_along() not yet implemented for " +
                                 std::string(get_name()));
    }
    xt::xtensor<uint8_t, 1> get_angle_across() const final
    {
        throw std::runtime_error("get_angle_across() not yet implemented for " +
                                 std::string(get_name()));
    }

    // ----- operator overloads -----
    bool operator==(const RAW3_DataAngle& other) const { return _angle == other._angle; }
    bool operator!=(const RAW3_DataAngle& other) const { return !(operator==(other)); }

    static RAW3_DataAngle from_stream(std::istream& is,
                                      ek60_long     input_count,
                                      ek60_long     output_count)
    {
        using xt_shape = xt::xtensor<uint8_t, 2>::shape_type;
        RAW3_DataAngle data(xt::empty<uint8_t>(xt_shape({ unsigned(output_count), 2 })));

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

    // ----- objectprinter -----
    tools::classhelpers::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelpers::ObjectPrinter printer("Sample binary data (angle)", float_precision);

        std::stringstream ss1, ss2;
        ss1 << xt::col(_angle, 0);
        ss2 << xt::col(_angle, 1);

        // printer.register_container("Angle along", xt::col(_angle,0));
        // printer.register_container("Angle across", xt::col(_angle,1));
        printer.register_string("Angle along", ss1.str());
        printer.register_string("Angle across", ss2.str());

        return printer;
    }
};

}
}
}
}
}