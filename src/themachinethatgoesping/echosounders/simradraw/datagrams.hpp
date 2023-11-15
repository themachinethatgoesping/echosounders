// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/datagrams.doc.hpp"

#include "datagrams/FIL1.hpp"
#include "datagrams/MRU0.hpp"
#include "datagrams/NME0.hpp"
#include "datagrams/RAW3.hpp"
#include "datagrams/TAG0.hpp"
#include "datagrams/XML0.hpp"
#include "datagrams/simradrawdatagram.hpp"
#include "datagrams/simradrawunknown.hpp"
#include "types.hpp"

#include <pybind11/pybind11.h>

/**
 * @brief Type definitions for Ek60 types according to Ek60 Reference manual
 * see also http://www.simradraw.net/simradraw_ref_english/default.htm
 *
 * Note: these definitions are valid for EK60 and the EK80 files.
 */

/*  */
//
namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {

namespace datagrams {

using t_SimradRawDatagramVariant =
    std::variant<SimradRawDatagram, NME0, XML0, MRU0, RAW3, FIL1, TAG0, SimradRawUnknown>;

struct SimradRawDatagramVariant
{
    t_SimradRawDatagramVariant _datagram_variant;

  public:
    SimradRawDatagramVariant() = default;
    SimradRawDatagramVariant(t_SimradRawDatagramVariant&& datagram_variant)
        : _datagram_variant(std::move(datagram_variant))
    {
    }

    static t_SimradRawDatagramVariant from_stream(std::istream&              is,
                                               t_SimradRawDatagramIdentifier datagram_type,
                                               bool                       skipped = false)
    {
        switch (datagram_type)
        {
            case t_SimradRawDatagramIdentifier::MRU0:
                return t_SimradRawDatagramVariant(MRU0::from_stream(is));
            case t_SimradRawDatagramIdentifier::NME0:
                return t_SimradRawDatagramVariant(NME0::from_stream(is));
            case t_SimradRawDatagramIdentifier::XML0:
                return t_SimradRawDatagramVariant(XML0::from_stream(is));
            case t_SimradRawDatagramIdentifier::TAG0:
                return t_SimradRawDatagramVariant(TAG0::from_stream(is));
            case t_SimradRawDatagramIdentifier::FIL1:
                return t_SimradRawDatagramVariant(FIL1::from_stream(is));
            case t_SimradRawDatagramIdentifier::RAW3:
                return t_SimradRawDatagramVariant(RAW3::from_stream(is, skipped));
            default:
                return t_SimradRawDatagramVariant(SimradRawUnknown::from_stream(is, datagram_type));
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

template<typename t_datagram>
struct SimradRawSkipDataFactory
{
    static t_datagram from_stream(std::istream& is) { return t_datagram::from_stream(is, true); }

    static t_datagram from_stream(std::istream& is, t_SimradRawDatagramIdentifier type)
    {
        return t_datagram::from_stream(is, type, true);
    }
};

struct SimradRawSkipDataVariantFactory
{
    static t_SimradRawDatagramVariant from_stream(std::istream& is, t_SimradRawDatagramIdentifier type)
    {
        return SimradRawDatagramVariant::from_stream(is, type, true);
    }
};

} // namespace datagrams
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
