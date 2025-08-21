// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "raw3datapowerandangle.hpp"

#include <algorithm>
#include <cmath>
#include <sstream>

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace raw3datatypes {

RAW3DataPowerAndAngle::RAW3DataPowerAndAngle(xt::xtensor<simradraw_short, 1> power, xt::xtensor<int8_t, 2> angle)
    : i_RAW3Data("PowerAndAngle")
    , _power(std::move(power))
    , _angle(std::move(angle))
{
}

bool RAW3DataPowerAndAngle::operator==(const RAW3DataPowerAndAngle& other) const
{
    return _power == other._power && _angle == other._angle;
}

xt::xtensor<simradraw_float, 1> RAW3DataPowerAndAngle::get_power(bool dB) const
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

xt::xtensor<simradraw_float, 2> RAW3DataPowerAndAngle::get_angle() const
{
    return xt::xtensor<simradraw_float, 2>(xt::eval(_angle * (180.f / 128.f)));
}

RAW3DataPowerAndAngle RAW3DataPowerAndAngle::from_stream(std::istream& is,
                                                         simradraw_long   input_count,
                                                         simradraw_long   output_count)
{
    using power_shape = xt::xtensor<simradraw_short, 1>::shape_type;
    using angle_shape = xt::xtensor<int8_t, 2>::shape_type;
    
    RAW3DataPowerAndAngle data(xt::empty<simradraw_short>(power_shape({ unsigned(output_count) })),
                               xt::empty<int8_t>(angle_shape({ unsigned(output_count), 2 })));

    if (output_count <= input_count)
    {
        is.read(reinterpret_cast<char*>(data._power.data()),
                output_count * sizeof(simradraw_short));
        is.read(reinterpret_cast<char*>(data._angle.data()),
                output_count * 2 * sizeof(int8_t));
    }
    else
    {
        is.read(reinterpret_cast<char*>(data._power.data()),
                input_count * sizeof(simradraw_short));
        is.read(reinterpret_cast<char*>(data._angle.data()),
                input_count * 2 * sizeof(int8_t));

        std::fill(data._power.begin() + input_count, data._power.end(), 0);
        std::fill(data._angle.begin() + input_count * 2, data._angle.end(), 0);
    }

    return data;
}

void RAW3DataPowerAndAngle::to_stream(std::ostream& os) const
{
    os.write(reinterpret_cast<const char*>(_power.data()),
             _power.size() * sizeof(simradraw_short));
    os.write(reinterpret_cast<const char*>(_angle.data()),
             _angle.size() * sizeof(int8_t));
    return;
}

tools::classhelper::ObjectPrinter RAW3DataPowerAndAngle::__printer__(unsigned int float_precision, bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer("Sample binary data (PowerAndAngle)", float_precision, superscript_exponents);

    std::stringstream ss;
    ss << _power;
    printer.register_string("Power", ss.str());

    std::stringstream ss2;
    ss2 << _angle;
    printer.register_string("Angle", ss2.str());

    return printer;
}

} // namespace raw3datatypes
} // namespace datagrams
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping