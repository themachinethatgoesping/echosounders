// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "position.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

Position Position::from_stream(std::istream& is, S7KDatagram header)
{
    Position datagram(std::move(header));
    datagram.__read__(is);
    return datagram;
}

Position Position::from_stream(std::istream& is)
{
    return from_stream(is, S7KDatagram::from_stream(is));
}

Position Position::from_stream(std::istream& is, o_S7KDatagramIdentifier datagram_identifier)
{
    return from_stream(is, S7KDatagram::from_stream(is, datagram_identifier));
}

void Position::to_stream(std::ostream& os) const
{
    S7KDatagram::to_stream(os);
    os.write(reinterpret_cast<const char*>(&_content), __content_size);
}

tools::classhelper::ObjectPrinter Position::__printer__(unsigned int float_precision,
                                                     bool         superscript_exponents) const
{
    const auto& o_datagram_identifier = S7KDatagram::o_DatagramIdentifier(DatagramIdentifier);
    tools::classhelper::ObjectPrinter printer(
        fmt::format("S7K {} ({})", o_datagram_identifier.name(), uint32_t(o_datagram_identifier)),
        float_precision,
        superscript_exponents);

    printer.append(S7KDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("Position content");
    printer.register_value("datum", _content.datum);
    printer.register_value("latency", _content.latency, "s");
    printer.register_value("latitude_northing", _content.latitude_northing, "rad|m");
    printer.register_value("longitude_easting", _content.longitude_easting, "rad|m");
    printer.register_value("height", _content.height, "m");
    printer.register_value("position_type", _content.position_type);
    printer.register_value("utm_zone", _content.utm_zone);
    printer.register_value("quality", _content.quality);
    printer.register_value("position_method", _content.position_method);

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
