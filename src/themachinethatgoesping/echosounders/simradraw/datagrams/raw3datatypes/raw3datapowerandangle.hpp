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
#include <cmath> // for std::log10
#include <string>
#include <unordered_map>
#include <vector>

#include <boost/algorithm/string.hpp>

// xtensor includes
#include <xtensor/containers/xadapt.hpp>
#include <xtensor/views/xview.hpp>
#include <xtensor/io/xio.hpp>

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
    xt::xtensor<int8_t, 2>          _angle; ///< [along, athwart] 180/128 electrical degrees
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
    bool operator==(const RAW3DataPowerAndAngle& other) const;
    bool operator!=(const RAW3DataPowerAndAngle& other) const { return !(operator==(other)); }

    // ----- i_RAW3Data interface -----
    bool has_power() const final { return true; }
    bool has_angle() const final { return true; }

    xt::xtensor<simradraw_float, 1> get_power(bool dB = false) const final;
    xt::xtensor<simradraw_float, 2> get_angle() const final;

    // ----- to/from stream -----
    static RAW3DataPowerAndAngle from_stream(std::istream&  is,
                                             simradraw_long input_count,
                                             simradraw_long output_count);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;
};

}
}
}
}
}