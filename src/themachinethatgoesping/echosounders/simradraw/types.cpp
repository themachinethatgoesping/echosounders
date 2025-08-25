// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "types.hpp"

namespace themachinethatgoesping {
namespace echosounders {

std::vector<std::string> datagram_identifiers_to_string(
    const std::vector<simradraw::t_SimradRawDatagramIdentifier>& values)
{
    std::vector<std::string> result;
    result.reserve(values.size());
    for (auto v : values)
        result.push_back(datagram_identifier_to_string(v));
    return result;
}

std::vector<std::string> datagram_identifiers_to_string(
    const std::set<simradraw::t_SimradRawDatagramIdentifier>& values)
{
    std::vector<std::string> result;
    result.reserve(values.size());
    for (auto v : values)
        result.push_back(datagram_identifier_to_string(v));
    return result;
}

std::string datagram_identifier_info(
    simradraw::t_SimradRawDatagramIdentifier datagram_type)
{
    using simradraw::t_SimradRawDatagramIdentifier;
    switch (datagram_type)
    {
        case t_SimradRawDatagramIdentifier::MRU0: return "Motion binary datagram";
        case t_SimradRawDatagramIdentifier::NME0: return "NMEA text datagram";
        case t_SimradRawDatagramIdentifier::XML0: return "XML0 text datagram";
        case t_SimradRawDatagramIdentifier::TAG0: return "Annotation datagram";
        case t_SimradRawDatagramIdentifier::FIL1: return "Filter binary datagram";
        case t_SimradRawDatagramIdentifier::RAW3: return "Sample binary datagram";
        default:
            return "unknown (" +
                   std::to_string(magic_enum::enum_integer(datagram_type)) + ")";
    }
}

} // namespace echosounders
} // namespace themachinethatgoesping