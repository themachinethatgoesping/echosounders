// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace gsf {

std::string datagram_type_to_string(t_GSFDatagramIdentifier value)
{
    // convert to string using magic enum
    return std::string(magic_enum::enum_name(value));
}

t_GSFDatagramIdentifier GSFDatagram_type_from_string(std::string_view value)
{
    // convert to datagram type using magic enum
    return magic_enum::enum_cast<t_GSFDatagramIdentifier>(value).value_or(
        t_GSFDatagramIdentifier::unspecified);
}

} // namespace gsf

// ----- interface functions -----

std::string datagram_identifier_to_string(gsf::t_GSFDatagramIdentifier value)
{
    return gsf::datagram_type_to_string(value);
}

std::string datagram_identifier_info(gsf::t_GSFDatagramIdentifier datagram_type)
{
    return fmt::format("{:x}", uint8_t(datagram_type));
}

} // namespace echosounders
} // namespace themachinethatgoesping
