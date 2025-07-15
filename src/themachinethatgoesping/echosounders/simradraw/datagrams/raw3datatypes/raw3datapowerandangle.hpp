// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/raw3datapowerandangle.doc.hpp"

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


#include "i_raw3data.hpp"
#include "t_raw3datatype.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace raw3datatypes {

struct RAW3DataPowerAndAngle : public i_RAW3Data
{
    xt::xtensor<simradraw_short, 1> _power; ///< Sample data
    xt::xtensor<int8_t, 2>       _angle; ///< [along, athwart] 180/128 electrical degrees
    // xt::xtensor<int8_t>    _angle_along;  ///< alongship angle
    // xt::xtensor<int8_t>    _angle_across; ///< athwartship angle

    RAW3DataPowerAndAngle()
        : i_RAW3Data("PowerAndAngle")
    {
    }
    RAW3DataPowerAndAngle(xt::xtensor<simradraw_short, 1> power, xt::xtensor<int8_t, 2> angle)
        : i_RAW3Data("PowerAndAngle")
        , _power(std::move(power))
        , _angle(std::move(angle))
    {
    }
    ~RAW3DataPowerAndAngle() = default;

    // ----- operator overloads -----
    bool operator==(const RAW3DataPowerAndAngle& other) const
    {
        return _power == other._power && _angle == other._angle;
    }
    bool operator!=(const RAW3DataPowerAndAngle& other) const { return !(operator==(other)); }

    // ----- i_RAW3Data interface -----
    bool has_power() const final { return true; }
    bool has_angle() const final { return true; }

    xt::xtensor<simradraw_float, 1> get_power(bool dB = false) const final
    {
        static const float conv_factor = 10.f * std::log10(2.0f) / 256.f;

        if (dB)
        {
            return xt::xtensor<simradraw_float, 1>(xt::eval(_power * conv_factor));
        }
        else
        {
            auto r1 = xt::eval(_power * conv_factor);
            return xt::xtensor<simradraw_float, 1>(xt::eval(xt::pow(10.f, r1 / 10.f)));
        }
    }
    xt::xtensor<simradraw_float, 2> get_angle() const final
    {
        const static float conv_factor = 180.f / 128.f;

        return xt::xtensor<simradraw_float, 2>(xt::eval(_angle * conv_factor));
    }

    // ----- to/from stream -----
    static RAW3DataPowerAndAngle from_stream(std::istream& is,
                                             simradraw_long   input_count,
                                             simradraw_long   output_count)
    {
        using power_shape = xt::xtensor<simradraw_short, 1>::shape_type;
        using angle_shape = xt::xtensor<int8_t, 2>::shape_type;
        RAW3DataPowerAndAngle data(xt::empty<simradraw_short>(power_shape({ unsigned(output_count) })),
                                   xt::empty<int8_t>(angle_shape({ unsigned(output_count), 2 })));

        // initialize data_block using from_shape
        if (output_count <= input_count)
        {
            is.read(reinterpret_cast<char*>(data._power.data()),
                    output_count * sizeof(simradraw_short));
            is.read(reinterpret_cast<char*>(data._angle.data()),
                    output_count * sizeof(simradraw_short));
        }
        else
        {
            is.read(reinterpret_cast<char*>(data._power.data()),
                    input_count * sizeof(simradraw_short));
            is.seekg((output_count - input_count) * sizeof(simradraw_short), std::ios_base::cur);
            is.read(reinterpret_cast<char*>(data._angle.data()),
                    input_count * sizeof(simradraw_short));
            is.seekg((output_count - input_count) * sizeof(simradraw_short), std::ios_base::cur);

            // fill remaining samples with quiet zeros
            std::fill(data._power.begin() + input_count, data._power.end(), 0);

            // fill remaining samples with quiet zeros
            std::fill(data._angle.begin() + input_count, data._angle.end(), 0);
        }

        return data;
    }

    void to_stream(std::ostream& os) const
    {
        os.write(reinterpret_cast<const char*>(_power.data()),
                 _power.size() * sizeof(simradraw_short));
        os.write(reinterpret_cast<const char*>(_angle.data()), _angle.size() * sizeof(int8_t));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer("Sample binary data (Power and Angle)",
                                                  float_precision, superscript_exponents);

        std::stringstream ss1, ss2, ss3;
        ss1 << _power * 10 * log10(2.0) / 256;
        ss2 << xt::col(_angle, 0);
        ss3 << xt::col(_angle, 1);

        printer.register_string("Power", ss1.str());
        printer.register_string("Angle [:,0]", ss2.str());
        printer.register_string("Angle [:,1]", ss3.str());

        return printer;
    }
};

}
}
}
}
}