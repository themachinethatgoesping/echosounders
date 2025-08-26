// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/raw3dataangle.doc.hpp"

// std includes
#include <string>

#include <boost/algorithm/string.hpp>

// xtensor includes
#include <xtensor/containers/xadapt.hpp>

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

    xt::xtensor<simradraw_float, 2> get_angle() const final;

    // ----- operator overloads -----
    bool operator==(const RAW3DataAngle& other) const { return _angle == other._angle; }
    bool operator!=(const RAW3DataAngle& other) const { return !(operator==(other)); }

    // ----- to/from stream -----
    static RAW3DataAngle from_stream(std::istream& is,
                                     simradraw_long   input_count,
                                     simradraw_long   output_count);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const;
};

}
}
}
}
}