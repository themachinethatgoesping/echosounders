// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "datagrams.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {

// Implementation file for datagrams.hpp

namespace datagrams {

t_SimradRawDatagramVariant SimradRawDatagramVariant::from_stream(std::istream&              is,
                                                                t_SimradRawDatagramIdentifier datagram_type,
                                                                bool                       skipped)
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

} // namespace datagrams

} // namespace themachinethatgoesping
} // namespace echosounders
} // namespace simradraw
