// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/raw3datapower.doc.hpp"

// std includes
#include <bitset>
#include <sstream>
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

struct RAW3DataPower : public i_RAW3Data
{
    xt::xtensor<simradraw_short, 1> _power; ///< Sample data

    RAW3DataPower()
        : i_RAW3Data("Power")
    {
    }
    RAW3DataPower(xt::xtensor<simradraw_short, 1> power)
        : i_RAW3Data("Power")
        , _power(std::move(power))
    {
    }
    ~RAW3DataPower() = default;

    // ----- i_RAW3Data interface -----
    bool has_power() const final { return true; }
    bool has_angle() const final { return false; }

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

    // ----- operator overloads -----
    bool operator==(const RAW3DataPower& other) const { return _power == other._power; }
    bool operator!=(const RAW3DataPower& other) const { return !(operator==(other)); }

    // ----- to/from stream -----
    static RAW3DataPower from_stream(std::istream& is,
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

    void to_stream(std::ostream& os) const
    {
        os.write(reinterpret_cast<const char*>(_power.data()),
                 _power.size() * sizeof(simradraw_short));
        return;
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer("Sample binary data (Power)", float_precision, superscript_exponents);

        std::stringstream ss;
        ss << _power;
        printer.register_string("Power", ss.str());

        return printer;
    }
};

}
}
}
}
}