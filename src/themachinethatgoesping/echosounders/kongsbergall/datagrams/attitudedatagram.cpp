// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "attitudedatagram.hpp"

#include <stdexcept>
#include <fmt/format.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

// ----- processed data access -----

int AttitudeDatagram::get_attitude_sensor_number() const
{
    if (_sensor_system_descriptor & 0b00110000)
        return 2;
    else
        return 1;
}

bool AttitudeDatagram::get_heading_sensor_is_active() const
{
    if (_sensor_system_descriptor & 0b00000001)
        return true;
    else
        return false;
}

bool AttitudeDatagram::get_roll_sensor_is_active() const
{
    if (_sensor_system_descriptor & 0b00000010)
        return true;
    else
        return false;
}

bool AttitudeDatagram::get_pitch_sensor_is_active() const
{
    if (_sensor_system_descriptor & 0b00000100)
        return true;
    else
        return false;
}

bool AttitudeDatagram::get_heave_sensor_is_active() const
{
    if (_sensor_system_descriptor & 0b00001000)
        return true;
    else
        return false;
}

// ----- to/from stream functions -----

AttitudeDatagram AttitudeDatagram::from_stream(std::istream& is, KongsbergAllDatagram header)
{
    AttitudeDatagram datagram(std::move(header));

    if (datagram._datagram_identifier != t_KongsbergAllDatagramIdentifier::AttitudeDatagram)
        throw std::runtime_error(
            fmt::format("AttitudeDatagram: datagram identifier is not 0x{:02x}, but 0x{:02x}",
                        uint8_t(t_KongsbergAllDatagramIdentifier::AttitudeDatagram),
                        uint8_t(datagram._datagram_identifier)));

    // read first part of the datagram (until the first beam)
    is.read(reinterpret_cast<char*>(&(datagram._attitude_counter)), 6 * sizeof(uint8_t));

    // read the attitude data
    datagram._attitudes.resize(datagram._number_of_entries);
    is.read(reinterpret_cast<char*>(datagram._attitudes.data()),
            datagram._number_of_entries * sizeof(substructures::AttitudeDatagramAttitude));

    // read the rest of the datagram
    is.read(reinterpret_cast<char*>(&(datagram._sensor_system_descriptor)),
            4 * sizeof(uint8_t));

    if (datagram._etx != 0x03)
        throw std::runtime_error(fmt::format(
            "AttitudeDatagram: end identifier is not 0x03, but 0x{:x}", datagram._etx));

    return datagram;
}

AttitudeDatagram AttitudeDatagram::from_stream(std::istream& is)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is));
}

AttitudeDatagram AttitudeDatagram::from_stream(std::istream&              is,
                                    t_KongsbergAllDatagramIdentifier datagram_identifier)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is, datagram_identifier));
}

void AttitudeDatagram::to_stream(std::ostream& os)
{
    KongsbergAllDatagram::to_stream(os);
    _number_of_entries = _attitudes.size();

    // write first part of the datagram (until the first beam)
    os.write(reinterpret_cast<const char*>(&(_attitude_counter)), 6 * sizeof(uint8_t));

    // write the beams
    os.write(reinterpret_cast<const char*>(_attitudes.data()),
             _number_of_entries * sizeof(substructures::AttitudeDatagramAttitude));

    // write the rest of the datagram
    os.write(reinterpret_cast<const char*>(&(_sensor_system_descriptor)), 4 * sizeof(uint8_t));
}

// ----- objectprinter -----

tools::classhelper::ObjectPrinter AttitudeDatagram::__printer__(unsigned int float_precision, bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer("AttitudeDatagram", float_precision, superscript_exponents);

    printer.append(KongsbergAllDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("datagram content");
    printer.register_value("attitude_counter", _attitude_counter);
    printer.register_value("system_serial_number", _system_serial_number);
    printer.register_value("number_of_entries", _number_of_entries);
    printer.register_string("sensor_system_descriptor",
                            fmt::format("0b{:08b}", _sensor_system_descriptor));
    printer.register_string("etx", fmt::format("0x{:02x}", _etx));
    printer.register_value("checksum", _checksum);

    printer.register_section("processed");
    printer.register_value("attitude_sensor_number", get_attitude_sensor_number(), "1,2");
    printer.register_value("heading_sensor_is_active", get_heading_sensor_is_active());
    printer.register_value("roll_sensor_is_active", get_roll_sensor_is_active());
    printer.register_value("pitch_sensor_is_active", get_pitch_sensor_is_active());
    printer.register_value("heave_sensor_is_active", get_heave_sensor_is_active());

    printer.register_section("substructures");
    printer.register_value("attitudes", _attitudes.size(), "AttitudeDatagramAttitude");

    return printer;
}

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
