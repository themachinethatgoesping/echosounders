// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "raw3datapower.hpp"

#include <xtensor/io/xio.hpp> 
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iostream>

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace raw3datatypes {

RAW3DataPower::RAW3DataPower(xt::xtensor<simradraw_short, 1> power)
    : i_RAW3Data("Power")
    , _power(std::move(power))
{
}

xt::xtensor<simradraw_float, 1> RAW3DataPower::get_power(bool dB) const
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

RAW3DataPower RAW3DataPower::from_stream(std::istream& is,
                                         simradraw_long   input_count,
                                         simradraw_long   output_count)
{
    using xt_shape = xt::xtensor<simradraw_short, 1>::shape_type;
    RAW3DataPower data(xt::empty<simradraw_short>(xt_shape({ unsigned(output_count) })));

    // initialize data_block using from_shape
    if (output_count < input_count)
    {
        is.read(reinterpret_cast<char*>(data._power.data()),
                output_count * sizeof(simradraw_short));
    }
    else
    {
        is.read(reinterpret_cast<char*>(data._power.data()),
                input_count * sizeof(simradraw_short));

        // fill remaining samples with 0
        std::fill(data._power.begin() + input_count, data._power.end(), 0);
    }

    return data;
}

void RAW3DataPower::to_stream(std::ostream& os) const
{
    os.write(reinterpret_cast<const char*>(_power.data()),
             _power.size() * sizeof(simradraw_short));
    return;
}

tools::classhelper::ObjectPrinter RAW3DataPower::__printer__(unsigned int float_precision, bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer("Sample binary data (Power)", float_precision, superscript_exponents);

    std::stringstream ss;
    ss << _power;
    printer.register_string("Power", ss.str());

    return printer;
}

} // namespace raw3datatypes
} // namespace datagrams
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping