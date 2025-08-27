// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "xyzdatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

XYZDatagram XYZDatagram::from_stream(std::istream& is, KongsbergAllDatagram header)
{
    XYZDatagram datagram(std::move(header));

    if (datagram._datagram_identifier != t_KongsbergAllDatagramIdentifier::XYZDatagram)
        throw std::runtime_error(
            fmt::format("XYZDatagram: datagram identifier is not 0x{:02x}, but 0x{:02x}",
                        uint8_t(t_KongsbergAllDatagramIdentifier::XYZDatagram),
                        uint8_t(datagram._datagram_identifier)));

    // read first part of the datagram (until the first beam)
    is.read(reinterpret_cast<char*>(&(datagram._ping_counter)), 24 * sizeof(uint8_t));

    // read the beams
    datagram._beams.resize(datagram._number_of_beams);
    is.read(reinterpret_cast<char*>(datagram._beams.data()),
            datagram._number_of_beams * sizeof(substructures::XYZDatagramBeam));

    // read the rest of the datagram
    is.read(reinterpret_cast<char*>(&(datagram._spare_byte)), 4 * sizeof(uint8_t));

    if (datagram._etx != 0x03)
        throw std::runtime_error(
            fmt::format("XYZDatagram: end identifier is not 0x03, but 0x{:x}", datagram._etx));

    return datagram;
}

XYZDatagram XYZDatagram::from_stream(std::istream& is)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is));
}

XYZDatagram XYZDatagram::from_stream(std::istream&                    is,
                               t_KongsbergAllDatagramIdentifier datagram_identifier)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is, datagram_identifier));
}

void XYZDatagram::to_stream(std::ostream& os)
{
    KongsbergAllDatagram::to_stream(os);
    _number_of_beams = _beams.size();

    // write first part of the datagram (until the first beam)
    os.write(reinterpret_cast<const char*>(&(_ping_counter)), 24 * sizeof(uint8_t));

    // write the beams
    os.write(reinterpret_cast<const char*>(_beams.data()),
             _number_of_beams * sizeof(substructures::XYZDatagramBeam));

    // write the rest of the datagram
    os.write(reinterpret_cast<const char*>(&(_spare_byte)), 4 * sizeof(uint8_t));
}

tools::classhelper::ObjectPrinter XYZDatagram::__printer__(unsigned int float_precision,
                                              bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "XYZDatagram", float_precision, superscript_exponents);

    printer.append(KongsbergAllDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("datagram content");
    printer.register_value("ping_counter", _ping_counter);
    printer.register_value("system_serial_number", _system_serial_number);
    printer.register_value("heading", _heading, "0.01° steps");
    printer.register_value("sound_speed", _sound_speed, "0.1 m/s steps");
    printer.register_value("transmit_transducer_depth", _transmit_transducer_depth, "m");
    printer.register_value("number_of_beams", _number_of_beams);
    printer.register_value("number_of_valid_detections", _number_of_valid_detections);
    printer.register_value("sampling_frequency", _sampling_frequency, "Hz");
    printer.register_value("scanning_info", _scanning_info);
    printer.register_string("etx", fmt::format("0x{:02x}", _etx));
    printer.register_value("checksum", _checksum);

    printer.register_section("processed");
    printer.register_value("heading", get_heading_in_degrees(), "°");
    printer.register_value("sound_speed", get_sound_speed_in_m_per_s(), "m/s");

    printer.register_section("substructures");
    printer.register_value("beams", _beams.size(), "XYZDatagramBeams");

    return printer;
}

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
