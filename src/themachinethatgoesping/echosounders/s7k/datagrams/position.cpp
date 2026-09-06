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
    printer.register_value("datum_identifier", _content._datum_identifier);
    printer.register_value("latency", _content._latency, "s");
    printer.register_value("latitude_or_northing", _content._latitude_or_northing, "rad|m");
    printer.register_value("longitude_or_easting", _content._longitude_or_easting, "rad|m");
    printer.register_value("height", _content._height, "m");
    printer.register_string("position_type_flag",
                            _content._position_type_flag.name(),
                            _content._position_type_flag.alt_name());
    printer.register_value("utm_zone", _content._utm_zone);
    printer.register_string(
        "quality_flag", _content._quality_flag.name(), _content._quality_flag.alt_name());
    printer.register_string(
        "position_method", _content._position_method.name(), _content._position_method.alt_name());
    printer.register_value("number_of_satellites", _content._number_of_satellites);
    printer.register_value("checksum", _content._checksum);

    printer.register_section("processed");
    printer.register_value("latitude", get_latitude_in_degrees(), "°");
    printer.register_value("longitude", get_longitude_in_degrees(), "°");

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
