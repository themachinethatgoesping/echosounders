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
    printer.register_value("vertical_reference", _content.vertical_reference);
    printer.register_value("latitude", _content.latitude, "rad");
    printer.register_value("longitude", _content.longitude, "rad");
    printer.register_value("position_accuracy", _content.position_accuracy, "m");
    printer.register_value("height", _content.height, "m");
    printer.register_value("height_accuracy", _content.height_accuracy, "m");
    printer.register_value("speed", _content.speed, "m/s");
    printer.register_value("course", _content.course, "rad");
    printer.register_value("heading", _content.heading, "rad");

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
