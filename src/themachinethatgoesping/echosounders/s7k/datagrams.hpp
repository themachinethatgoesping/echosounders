// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/datagrams.doc.hpp"

#include "datagrams/s7kdatagram.hpp"
#include "datagrams/s7kunknown.hpp"
#include "types.hpp"

#include <variant>

/**
 * @brief Aggregated datagram definitions for the Teledyne RESON .s7k (7k) data format.
 */

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {

namespace datagrams {

// S7KDATAGRAMTYPEAREA
using t_S7KDatagramVariant = std::variant<S7KDatagram, S7KUnknown>;

struct S7KDatagramVariant
{
    t_S7KDatagramVariant _datagram_variant;

  public:
    S7KDatagramVariant() = default;
    S7KDatagramVariant(t_S7KDatagramVariant&& datagram_variant)
        : _datagram_variant(std::move(datagram_variant))
    {
    }

    static t_S7KDatagramVariant from_stream(std::istream&           is,
                                            t_S7KDatagramIdentifier datagram_type,
                                            [[maybe_unused]] bool   skip_data = false);

    template<typename t_Datagram>
    t_Datagram& operator()() const
    {
        return t_Datagram(_datagram_variant);
    }
};

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
