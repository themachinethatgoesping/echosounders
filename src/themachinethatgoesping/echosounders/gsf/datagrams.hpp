// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/datagrams.doc.hpp"

#include "datagrams/gsfdatagram.hpp"
#include "datagrams/gsfunknown.hpp"
#include "types.hpp"

#include <variant>

/**
 * @brief Type definitions for EM datagram format specifications
 *
 * Note: these definitions are valid for kongsberg .all and .wcd files
 */

/*  */
//
namespace themachinethatgoesping {
namespace echosounders {
namespace gsf {

namespace datagrams {

// GSFDATAGRAMTYPEAREA
using t_GSFDatagramVariant = std::variant<GSFDatagram, GSFUnknown
                                          // XYZDatagram,
                                          >;

struct GSFDatagramVariant
{
    t_GSFDatagramVariant _datagram_variant;

  public:
    GSFDatagramVariant() = default;
    GSFDatagramVariant(t_GSFDatagramVariant&& datagram_variant)
        : _datagram_variant(std::move(datagram_variant))
    {
    }

    static t_GSFDatagramVariant from_stream(std::istream&           is,
                                            t_GSFDatagramIdentifier datagram_type,
                                            [[maybe_unused]] bool   skip_data = false)
    {
        // GSFDATAGRAMTYPEAREA
        switch (datagram_type)
        {
                // case t_GSFDatagramIdentifier::XYZDatagram:
                //     return t_GSFDatagramVariant(XYZDatagram::from_stream(is));

            default:
                return t_GSFDatagramVariant(GSFUnknown::from_stream(is, datagram_type));
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
struct GSFSkipDataFactory
{
    static t_datagram from_stream(std::istream& is) { return t_datagram::from_stream(is, true); }

    static t_datagram from_stream(std::istream& is, t_GSFDatagramIdentifier type)
    {
        return t_datagram::from_stream(is, type, true);
    }
};

struct GSFSkipDataVariantFactory
{
    static t_GSFDatagramVariant from_stream(std::istream& is, t_GSFDatagramIdentifier type)
    {
        return GSFDatagramVariant::from_stream(is, type, true);
    }
};

} // namespace datagrams
} // namespace gsf
} // namespace echosounders
} // namespace themachinethatgoesping
