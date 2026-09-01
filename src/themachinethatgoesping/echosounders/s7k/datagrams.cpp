// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "datagrams.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {

namespace datagrams {

t_S7KDatagramVariant S7KDatagramVariant::from_stream(std::istream&           is,
                                                     t_S7KDatagramIdentifier datagram_type,
                                                     [[maybe_unused]] bool   skip_data)
{
    // S7KDATAGRAMTYPEAREA
    switch (datagram_type)
    {
            // case t_S7KDatagramIdentifier::R7027_RawDetectionData:
            //     return t_S7KDatagramVariant(RawDetectionData::from_stream(is));

        default:
            return t_S7KDatagramVariant(S7KUnknown::from_stream(is, datagram_type));
    }
}

} // namespace datagrams

} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
