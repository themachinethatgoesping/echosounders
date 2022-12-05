// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include "datagrams/FIL1.hpp"
#include "datagrams/MRU0.hpp"
#include "datagrams/NME0.hpp"
#include "datagrams/RAW3.hpp"
#include "datagrams/TAG0.hpp"
#include "datagrams/XML0.hpp"
#include "datagrams/em3000datagram.hpp"
#include "datagrams/em3000unknown.hpp"
#include "em3000_types.hpp"

#include <pybind11/pybind11.h>

/**
 * @brief Type definitions for Ek60 types according to Ek60 Reference manual
 * see also http://www.em3000.net/em3000_ref_english/default.htm
 *
 * Note: these definitions are valid for EK60 and the EK80 files.
 */

/*  */
//
namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {

namespace datagrams {

using t_EM3000DatagramVariant =
    std::variant<EM3000Datagram, NME0, XML0, MRU0, RAW3, FIL1, TAG0, EM3000Unknown>;

struct EM3000DatagramVariant
{
    t_EM3000DatagramVariant _datagram_variant;

  public:
    EM3000DatagramVariant() = default;
    EM3000DatagramVariant(t_EM3000DatagramVariant&& datagram_variant)
        : _datagram_variant(std::move(datagram_variant))
    {
    }

    static t_EM3000DatagramVariant from_stream(std::istream&              is,
                                               t_EM3000DatagramIdentifier datagram_type)
    {
        switch (datagram_type)
        {
            case t_EM3000DatagramIdentifier::MRU0:
                return t_EM3000DatagramVariant(MRU0::from_stream(is));
            case t_EM3000DatagramIdentifier::NME0:
                return t_EM3000DatagramVariant(NME0::from_stream(is));
            case t_EM3000DatagramIdentifier::XML0:
                return t_EM3000DatagramVariant(XML0::from_stream(is));
            case t_EM3000DatagramIdentifier::TAG0:
                return t_EM3000DatagramVariant(TAG0::from_stream(is));
            case t_EM3000DatagramIdentifier::FIL1:
                return t_EM3000DatagramVariant(FIL1::from_stream(is));
            case t_EM3000DatagramIdentifier::RAW3:
                return t_EM3000DatagramVariant(RAW3::from_stream(is));
            default:
                return t_EM3000DatagramVariant(EM3000Unknown::from_stream(is, datagram_type));
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
} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping
