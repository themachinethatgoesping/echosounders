// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include "datagrams/ek60_datagram.hpp"
#include "datagrams/ek60_unknown.hpp"
#include "ek60_types.hpp"

#include <pybind11/pybind11.h>

/**
 * @brief Type definitions for Ek60 types according to Ek60 Reference manual
 * see also http://www.simrad.net/ek60_ref_english/default.htm
 *
 * Note: these definitions are valid for EK60 and the EK80 files.
 */

/*  */
//
namespace themachinethatgoesping {
namespace echosounders {
namespace simrad {

namespace datagrams {

using t_EK60_DatagramVariant = std::variant<EK60_Datagram, EK60_Unknown>;

struct EK60_DatagramVariant
{
    t_EK60_DatagramVariant _datagram_variant;

  public:
    EK60_DatagramVariant() = default;
    EK60_DatagramVariant(t_EK60_DatagramVariant&& datagram_variant)
        : _datagram_variant(std::move(datagram_variant))
    {
    }

    static t_EK60_DatagramVariant from_stream(std::istream& is, t_EK60_DatagramType datagram_type)
    {
        switch (datagram_type)
        {
            case t_EK60_DatagramType::FIL1:
                [[fallthrough]];
            case t_EK60_DatagramType::MRU0:
                [[fallthrough]];
            case t_EK60_DatagramType::NME0:
                [[fallthrough]];
            case t_EK60_DatagramType::RAW3:
                [[fallthrough]];
            case t_EK60_DatagramType::XML0:
                [[fallthrough]];
            case t_EK60_DatagramType::TAG0:
                [[fallthrough]];
            default:
                return t_EK60_DatagramVariant(EK60_Unknown::from_stream(is, datagram_type));
        }
    }

    /**
     * @brief This is the visitor function that  tries to convert the internal variant to the
     * specified type.
     *
     * @tparam t_ProgressBar
     * @param progress_bar ProgressBar class that is derived from I_ProgressBar
     * @return I_ProgressBar&
     */
    template<typename t_Datagram>
    t_Datagram& operator()() const
    {
        return t_Datagram(_datagram_variant);
    }
};

} // namespace datagrams
} // namespace simrad
} // namespace echosounders
} // namespace themachinethatgoesping
