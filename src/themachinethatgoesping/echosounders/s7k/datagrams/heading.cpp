// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "heading.hpp"

#include <numbers>
#include <utility>

#include <fmt/format.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

// ----- constructors -----
Heading::Heading()
    : _content{}
{
    set_datagram_identifier(DatagramIdentifier);
}

Heading::Heading(S7KDatagram header)
    : S7KDatagram(std::move(header))
{
}

// ----- convenient member access -----
float Heading::get_heading() const
{
    return _content._heading;
}
uint32_t Heading::get_checksum() const
{
    return _content._checksum;
}

void Heading::set_heading(float val)
{
    _content._heading = val;
}
void Heading::set_checksum(uint32_t val)
{
    _content._checksum = val;
}

// ----- processed data access -----
float Heading::get_heading_in_degrees() const
{
    return _content._heading * 180.f / float(std::numbers::pi);
}

// ----- to/from stream functions -----
void Heading::__read__(std::istream& is)
{
    is.read(reinterpret_cast<char*>(&_content), __content_size);
}

Heading Heading::from_stream(std::istream& is, S7KDatagram header)
{
    Heading datagram(std::move(header));
    datagram.__read__(is);
    return datagram;
}

Heading Heading::from_stream(std::istream& is)
{
    return from_stream(is, S7KDatagram::from_stream(is));
}

Heading Heading::from_stream(std::istream& is, o_S7KDatagramIdentifier datagram_identifier)
{
    return from_stream(is, S7KDatagram::from_stream(is, datagram_identifier));
}

void Heading::to_stream(std::ostream& os) const
{
    S7KDatagram::to_stream(os);
    os.write(reinterpret_cast<const char*>(&_content), __content_size);
}

tools::classhelper::ObjectPrinter Heading::__printer__(unsigned int float_precision,
                                                     bool         superscript_exponents) const
{
    const auto& o_datagram_identifier = S7KDatagram::o_DatagramIdentifier(DatagramIdentifier);
    tools::classhelper::ObjectPrinter printer(
        fmt::format("S7K {} ({})", o_datagram_identifier.name(), uint32_t(o_datagram_identifier)),
        float_precision,
        superscript_exponents);

    printer.append(S7KDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("Heading content");
    printer.register_value("heading", _content._heading, "rad");
    printer.register_value("checksum", _content._checksum);

    printer.register_section("processed");
    printer.register_value("heading_in_degrees", get_heading_in_degrees(), "°");

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
