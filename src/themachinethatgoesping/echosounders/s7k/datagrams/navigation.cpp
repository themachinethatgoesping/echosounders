// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "navigation.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

Navigation Navigation::from_stream(std::istream& is, S7KDatagram header)
{
    Navigation datagram(std::move(header));
    datagram.__read__(is);
    return datagram;
}

Navigation Navigation::from_stream(std::istream& is)
{
    return from_stream(is, S7KDatagram::from_stream(is));
}

Navigation Navigation::from_stream(std::istream& is, o_S7KDatagramIdentifier datagram_identifier)
{
    return from_stream(is, S7KDatagram::from_stream(is, datagram_identifier));
}

void Navigation::to_stream(std::ostream& os) const
{
    S7KDatagram::to_stream(os);
    os.write(reinterpret_cast<const char*>(&_content), __content_size);
}

tools::classhelper::ObjectPrinter Navigation::__printer__(unsigned int float_precision,
                                                     bool         superscript_exponents) const
{
    const auto& o_datagram_identifier = S7KDatagram::o_DatagramIdentifier(DatagramIdentifier);
    tools::classhelper::ObjectPrinter printer(
        fmt::format("S7K {} ({})", o_datagram_identifier.name(), uint32_t(o_datagram_identifier)),
        float_precision,
        superscript_exponents);

    printer.append(S7KDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("Navigation content");
    printer.register_string("vertical_reference",
                            _content._vertical_reference.name(),
                            _content._vertical_reference.alt_name());
    printer.register_value("latitude", _content._latitude, "rad");
    printer.register_value("longitude", _content._longitude, "rad");
    printer.register_value("position_accuracy", _content._position_accuracy, "m");
    printer.register_value("height", _content._height, "m");
    printer.register_value("height_accuracy", _content._height_accuracy, "m");
    printer.register_value("speed", _content._speed, "m/s");
    printer.register_value("course", _content._course, "rad");
    printer.register_value("heading", _content._heading, "rad");
    printer.register_value("checksum", _content._checksum);

    printer.register_section("processed");
    printer.register_value("latitude_in_degrees", get_latitude_in_degrees(), "°");
    printer.register_value("longitude_in_degrees", get_longitude_in_degrees(), "°");
    printer.register_value("course_in_degrees", get_course_in_degrees(), "°");
    printer.register_value("heading_in_degrees", get_heading_in_degrees(), "°");

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
