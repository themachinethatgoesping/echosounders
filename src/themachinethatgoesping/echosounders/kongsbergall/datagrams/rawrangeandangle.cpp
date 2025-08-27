// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "rawrangeandangle.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

RawRangeAndAngle RawRangeAndAngle::from_stream(std::istream& is, KongsbergAllDatagram header)
{
    RawRangeAndAngle datagram(std::move(header));

    if (datagram._datagram_identifier != t_KongsbergAllDatagramIdentifier::RawRangeAndAngle)
        throw std::runtime_error(
            fmt::format("RawRangeAndAngle: datagram identifier is not 0x{:02x}, but 0x{:02x}",
                        uint8_t(t_KongsbergAllDatagramIdentifier::RawRangeAndAngle),
                        uint8_t(datagram._datagram_identifier)));

    // read first part of the datagram (until the first transmit sector)
    is.read(reinterpret_cast<char*>(&(datagram._ping_counter)), 20 * sizeof(uint8_t));

    // read the transmit sectors
    datagram._transmit_sectors.resize(datagram._number_of_transmit_sectors);
    is.read(reinterpret_cast<char*>(datagram._transmit_sectors.data()),
            datagram._number_of_transmit_sectors *
                sizeof(substructures::RawRangeAndAngleTransmitSector));

    // read the beams
    datagram._beams.resize(datagram._number_of_receiver_beams);
    is.read(reinterpret_cast<char*>(datagram._beams.data()),
            datagram._number_of_receiver_beams * sizeof(substructures::RawRangeAndAngleBeam));

    // read the rest of the datagram
    is.read(reinterpret_cast<char*>(&(datagram._spare)), 4 * sizeof(uint8_t));

    if (datagram._etx != 0x03)
        throw std::runtime_error(fmt::format(
            "RawRangeAndAngle: end identifier is not 0x03, but 0x{:x}", datagram._etx));

    return datagram;
}

RawRangeAndAngle RawRangeAndAngle::from_stream(std::istream& is)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is));
}

RawRangeAndAngle RawRangeAndAngle::from_stream(std::istream&                    is,
                                               t_KongsbergAllDatagramIdentifier datagram_identifier)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is, datagram_identifier));
}

void RawRangeAndAngle::to_stream(std::ostream& os)
{
    KongsbergAllDatagram::to_stream(os);
    _number_of_transmit_sectors = _transmit_sectors.size();
    _number_of_receiver_beams   = _beams.size();

    // write first part of the datagram (until the first beam)
    os.write(reinterpret_cast<const char*>(&(_ping_counter)), 20 * sizeof(uint8_t));

    // write the transmit sectors
    os.write(reinterpret_cast<const char*>(_transmit_sectors.data()),
             _number_of_transmit_sectors *
                 sizeof(substructures::RawRangeAndAngleTransmitSector));

    // write the beams
    os.write(reinterpret_cast<const char*>(_beams.data()),
             _number_of_receiver_beams * sizeof(substructures::RawRangeAndAngleBeam));

    // write the rest of the datagram
    os.write(reinterpret_cast<const char*>(&(_spare)), 4 * sizeof(uint8_t));
}

tools::classhelper::ObjectPrinter RawRangeAndAngle::__printer__(unsigned int float_precision,
                                                                bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "RawRangeAndAngle", float_precision, superscript_exponents);

    printer.append(KongsbergAllDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("datagram content");
    printer.register_value("ping_counter", _ping_counter);
    printer.register_value("system_serial_number", _system_serial_number);
    printer.register_value("sound_speed_at_transducer", _sound_speed_at_transducer, "0.1 m/s");
    printer.register_value("number_of_transmit_sectors", _number_of_transmit_sectors, "ntx");
    printer.register_value("number_of_receiver_beams", _number_of_receiver_beams, "nrx");
    printer.register_value("number_of_valid_detections", _number_of_valid_detections);
    printer.register_value("sampling_frequency", _sampling_frequency);
    printer.register_value("d_scale", _d_scale);
    printer.register_string("etx", fmt::format("0x{:02x}", _etx));
    printer.register_value("checksum", _checksum);

    printer.register_section("processed");
    printer.register_value(
        "sound_speed_at_transducer", get_sound_speed_at_transducer_in_m_per_s(), "m/s");

    printer.register_section("substructures");
    printer.register_value("beams", _beams.size(), "RawRangeAndAngleBeams");
    printer.register_value(
        "transmit_sectors", _transmit_sectors.size(), "RawRangeAndAngleTransmitSectors");

    return printer;
}

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
