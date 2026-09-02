// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "heading.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

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

Heading Heading::from_stream(std::istream& is, t_S7KDatagramIdentifier datagram_identifier)
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
    tools::classhelper::ObjectPrinter printer("Heading", float_precision, superscript_exponents);

    printer.append(S7KDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("Heading content");
    printer.register_value("heading", _content.heading, "rad");

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
