// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/i_raw3data.doc.hpp"

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

#include "t_raw3datatype.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {
namespace raw3datatypes {

/**
 * @brief Interface class for all RAW3 datatypes
 * The RAW3 datagram contains a number of different data types.
 *  - power
 *  - angle
 *  - power and angle
 *  - complex float 32
 *  - ...
 *
 */
class i_RAW3Data
{
    std::string_view _name; ///< name of the subclass (for error messages)

  public:
    // ----- constructors -----
    i_RAW3Data(std::string_view name)
        : _name(name)
    {
    }
    virtual ~i_RAW3Data() = default;

    // ----- class interface -----
    std::string_view class_name() const { return _name; }

    virtual bool has_power() const { return false; }
    virtual bool has_angle() const { return false; }

    virtual xt::xtensor<simradraw_float, 1> get_power([[maybe_unused]] bool dB = false) const
    {
        throw std::runtime_error("get_power() not implemented for " + std::string(_name));
    }
    virtual xt::xtensor<simradraw_float, 2> get_angle() const
    {
        throw std::runtime_error("get_angle() not implemented for " + std::string(_name));
    }
};

}
}
}
}
}