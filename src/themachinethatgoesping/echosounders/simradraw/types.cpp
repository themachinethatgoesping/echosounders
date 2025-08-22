// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "types.hpp"

namespace themachinethatgoesping {
namespace echosounders {

namespace simradraw {

std::string datagram_type_to_string(simradraw_long value)
{
    return tools::helper::int_as_string<simradraw_long>(value);
}

std::string datagram_type_to_string(t_SimradRawDatagramIdentifier value)
{
    return tools::helper::int_as_string<simradraw_long>(simradraw_long(value));
}

simradraw_long SimradRawDatagram_type_from_string(std::string_view value)
{
    return tools::helper::string_as_int<simradraw_long>(value);
}

} // namespace simradraw

std::string datagram_identifier_to_string(simradraw::t_SimradRawDatagramIdentifier value)
{
    return tools::helper::int_as_string<simradraw::simradraw_long>(
        simradraw::simradraw_long(value));
}

std::vector<std::string> datagram_identifiers_to_string(
    const std::vector<simradraw::t_SimradRawDatagramIdentifier>& values)
{
    std::vector<std::string> result;
    for (auto value : values)
    {
        result.push_back(datagram_identifier_to_string(value));
    }

    return result;
}

std::vector<std::string> datagram_identifiers_to_string(
    const std::set<simradraw::t_SimradRawDatagramIdentifier>& values)
{
    std::vector<std::string> result;
    for (auto value : values)
    {
        result.push_back(datagram_identifier_to_string(value));
    }

    return result;
}

std::string datagram_identifier_info(simradraw::t_SimradRawDatagramIdentifier datagram_type)
{
    // this should work, but doesn't
    // return magic_enum::enum_contains(datagram_type);
    using simradraw::t_SimradRawDatagramIdentifier;

    switch (datagram_type)
    {
        case t_SimradRawDatagramIdentifier::MRU0:
            return "Motion binary datagram";
        case t_SimradRawDatagramIdentifier::NME0:
            return "NMEA text datagram";
        case t_SimradRawDatagramIdentifier::XML0:
            return "XML0 text datagram";
        case t_SimradRawDatagramIdentifier::TAG0:
            return "Annotation datagram";
        case t_SimradRawDatagramIdentifier::FIL1:
            return "Filter binary datagram";
        case t_SimradRawDatagramIdentifier::RAW3:
            return "Sample binary datagram";
        default:
            return "unknown (" + std::to_string(magic_enum::enum_integer(datagram_type)) + ")";
    }
}

} // namespace echosounders
} // namespace themachinethatgoesping
