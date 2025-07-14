// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/raw3dataangle.doc.hpp"

// std includes
#include <bitset>
#include <string>
#include <unordered_map>
#include <vector>

#include <boost/algorithm/string.hpp>

// xtensor includes
#include <xtensor/containers/xadapt.hpp>
#include <xtensor/io/xio.hpp>
#include <xtensor/views/xview.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>


#include "i_raw3data.hpp"
#include "t_raw3datatype.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace raw3datatypes {

struct RAW3DataAngle : public i_RAW3Data
{
    xt::xtensor<int8_t, 2> _angle; ///< Sample data

    RAW3DataAngle()
        : i_RAW3Data("Angle")
    {
    }
    RAW3DataAngle(xt::xtensor<int8_t, 2> angle)
        : i_RAW3Data("Angle")
        , _angle(std::move(angle))
    {
    }
    ~RAW3DataAngle() = default;

    // ----- i_RAW3Data interface -----
    bool has_power() const final { return false; }
    bool has_angle() const final { return true; }

    xt::xtensor<simradraw_float, 2> get_angle() const final
    {
        const static float conv_factor = 180.f / 128.f;

        return xt::xtensor<simradraw_float, 2>(xt::eval(_angle * conv_factor));
    }

    // ----- operator overloads -----
    bool operator==(const RAW3DataAngle& other) const { return _angle == other._angle; }
    bool operator!=(const RAW3DataAngle& other) const { return !(operator==(other)); }

    // ----- to/from stream -----
    static RAW3DataAngle from_stream(std::istream& is,
                                     simradraw_long   input_count,
                                     simradraw_long   output_count)
    {
        using xt_shape = xt::xtensor<int8_t, 2>::shape_type;
        RAW3DataAngle data(xt::empty<int8_t>(xt_shape({ unsigned(output_count), 2 })));

        // initialize data_block using from_shape
        if (output_count < input_count)
        {
            is.read(reinterpret_cast<char*>(data._angle.data()), output_count * sizeof(int8_t) * 2);
        }
        else
        {
            is.read(reinterpret_cast<char*>(data._angle.data()), input_count * sizeof(int8_t) * 2);

            // fill remaining samples with 0
            std::fill(data._angle.begin() + input_count * 2, data._angle.end(), 0);
        }
        return data;
    }

    void to_stream(std::ostream& os) const
    {
        os.write(reinterpret_cast<const char*>(_angle.data()),
                 xt::flatten(_angle).size() * sizeof(int8_t));
        return;
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer("Sample binary data (angle)", float_precision, superscript_exponents);

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