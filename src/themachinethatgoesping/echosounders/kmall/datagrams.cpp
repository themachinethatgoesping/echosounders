// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "datagrams.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {

namespace datagrams {

t_KMALLDatagramVariant KMALLDatagramVariant::from_stream(std::istream&           is,
                                                     t_KMALLDatagramIdentifier datagram_type,
                                                     [[maybe_unused]] bool   skip_data)
{
    // KMALLDATAGRAMTYPEAREA
    switch (datagram_type)
    {
            // case t_KMALLDatagramIdentifier::XYZDatagram:
            //     return t_KMALLDatagramVariant(XYZDatagram::from_stream(is));

        default:
            return t_KMALLDatagramVariant(KMALLUnknown::from_stream(is, datagram_type));
    }
}

} // namespace datagrams

} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
