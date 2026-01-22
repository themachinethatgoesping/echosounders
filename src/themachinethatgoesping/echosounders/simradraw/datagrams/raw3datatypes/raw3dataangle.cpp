// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "raw3dataangle.hpp"

#include <algorithm>
#include <sstream>
#include <iostream>

// xtensor includes  
#include <xtensor/io/xio.hpp>
#include <xtensor/views/xview.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace raw3datatypes {

xt::xtensor<simradraw_float, 2> RAW3DataAngle::get_angle() const
{
    const static float conv_factor = 180.f / 128.f;

    return xt::xtensor<simradraw_float, 2>(xt::eval(_angle * conv_factor));
}

RAW3DataAngle RAW3DataAngle::from_stream(std::istream& is,
                                         simradraw_long   input_count,
                                         simradraw_long   output_count)
{
    // Debug logging for Linux CI issues
    std::cerr << "RAW3DataAngle::from_stream: input_count=" << input_count 
              << ", output_count=" << output_count << "\n";
    std::cerr.flush();
    
    if (output_count < 0) {
        std::cerr << "ERROR: RAW3DataAngle::from_stream: Invalid output_count: " << output_count << "\n";
        std::cerr.flush();
        throw std::runtime_error("RAW3DataAngle::from_stream: Invalid negative output_count");
    }
    
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

void RAW3DataAngle::to_stream(std::ostream& os) const
{
    os.write(reinterpret_cast<const char*>(_angle.data()),
             xt::flatten(_angle).size() * sizeof(int8_t));
    return;
}

tools::classhelper::ObjectPrinter RAW3DataAngle::__printer__(unsigned int float_precision, bool superscript_exponents) const
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

} // namespace raw3datatypes
} // namespace datagrams
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
