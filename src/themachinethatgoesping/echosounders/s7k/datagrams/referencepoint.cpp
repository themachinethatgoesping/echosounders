// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "referencepoint.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

ReferencePoint ReferencePoint::from_stream(std::istream& is, S7KDatagram header)
{
    ReferencePoint datagram(std::move(header));
    datagram.__read__(is);
    return datagram;
}

ReferencePoint ReferencePoint::from_stream(std::istream& is)
{
    return from_stream(is, S7KDatagram::from_stream(is));
}

ReferencePoint ReferencePoint::from_stream(std::istream& is, o_S7KDatagramIdentifier datagram_identifier)
{
    return from_stream(is, S7KDatagram::from_stream(is, datagram_identifier));
}

void ReferencePoint::to_stream(std::ostream& os) const
{
    S7KDatagram::to_stream(os);
    os.write(reinterpret_cast<const char*>(&_content), __content_size);
}

tools::classhelper::ObjectPrinter ReferencePoint::__printer__(unsigned int float_precision,
                                                     bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer("ReferencePoint", float_precision, superscript_exponents);

    printer.append(S7KDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("ReferencePoint content");
    printer.register_value("offset_x", _content.offset_x, "m");
    printer.register_value("offset_y", _content.offset_y, "m");
    printer.register_value("offset_z", _content.offset_z, "m");
    printer.register_value("water_z", _content.water_z, "m");

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
