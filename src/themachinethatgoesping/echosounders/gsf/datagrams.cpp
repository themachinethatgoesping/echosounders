// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "datagrams.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace gsf {

namespace datagrams {

t_GSFDatagramVariant GSFDatagramVariant::from_stream(std::istream&           is,
                                                     t_GSFDatagramIdentifier datagram_type,
                                                     [[maybe_unused]] bool   skip_data)
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

} // namespace datagrams

} // namespace gsf
} // namespace echosounders
} // namespace themachinethatgoesping
