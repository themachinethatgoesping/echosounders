// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "networkattitudevelocitydatagram.hpp"

#include <fmt/core.h>
#include <stdexcept>
#include <utility>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

NetworkAttitudeVelocityDatagram::NetworkAttitudeVelocityDatagram(KongsbergAllDatagram header)
    : KongsbergAllDatagram(std::move(header))
{
}

NetworkAttitudeVelocityDatagram::NetworkAttitudeVelocityDatagram()
{
    _datagram_identifier = t_KongsbergAllDatagramIdentifier::NetworkAttitudeVelocityDatagram;
}

uint16_t NetworkAttitudeVelocityDatagram::get_network_attitude_counter() const
{
    return _network_attitude_counter;
}

uint16_t NetworkAttitudeVelocityDatagram::get_system_serial_number() const
{
    return _system_serial_number;
}

uint16_t NetworkAttitudeVelocityDatagram::get_number_of_entries() const
{
    return _number_of_entries;
}

uint8_t NetworkAttitudeVelocityDatagram::get_sensor_system_descriptor() const
{
    return _sensor_system_descriptor;
}

uint8_t NetworkAttitudeVelocityDatagram::get_etx() const
{
    return _etx;
}

uint16_t NetworkAttitudeVelocityDatagram::get_checksum() const
{
    return _checksum;
}

uint8_t NetworkAttitudeVelocityDatagram::get_spare() const
{
    return _spare;
}

uint8_t NetworkAttitudeVelocityDatagram::get_spare_align() const
{
    return _spare_align;
}

void NetworkAttitudeVelocityDatagram::set_network_attitude_counter(uint16_t network_attitude_counter)
{
    _network_attitude_counter = network_attitude_counter;
}

void NetworkAttitudeVelocityDatagram::set_system_serial_number(uint16_t system_serial_number)
{
    _system_serial_number = system_serial_number;
}

void NetworkAttitudeVelocityDatagram::set_number_of_entries(uint16_t number_of_entries)
{
    _number_of_entries = number_of_entries;
}

void NetworkAttitudeVelocityDatagram::set_sensor_system_descriptor(uint8_t sensor_system_descriptor)
{
    _sensor_system_descriptor = sensor_system_descriptor;
}

void NetworkAttitudeVelocityDatagram::set_etx(uint8_t etx)
{
    _etx = etx;
}

void NetworkAttitudeVelocityDatagram::set_checksum(uint16_t checksum)
{
    _checksum = checksum;
}

void NetworkAttitudeVelocityDatagram::set_spare(uint8_t spare)
{
    _spare = spare;
}

void NetworkAttitudeVelocityDatagram::set_spare_align(uint8_t spare_align)
{
    _spare_align = spare_align;
}

std::vector<substructures::NetworkAttitudeVelocityDatagramAttitude>&
NetworkAttitudeVelocityDatagram::attitudes()
{
    return _attitudes;
}

const std::vector<substructures::NetworkAttitudeVelocityDatagramAttitude>&
NetworkAttitudeVelocityDatagram::get_attitudes() const
{
    return _attitudes;
}

void NetworkAttitudeVelocityDatagram::set_attitudes(
    std::vector<substructures::NetworkAttitudeVelocityDatagramAttitude> attitudes)
{
    _attitudes = std::move(attitudes);
}

unsigned int NetworkAttitudeVelocityDatagram::get_attitude_velocity_sensor_number() const
{
    if (!get_function_is_used())
        return 0;

    if (_sensor_system_descriptor & 0b00110000)
        return 2;

    return 1;
}

bool NetworkAttitudeVelocityDatagram::get_velocity_sensor_is_active() const
{
    if (!get_function_is_used())
        return false;

    return (_sensor_system_descriptor & 0b01000000) != 0;
}

bool NetworkAttitudeVelocityDatagram::get_heading_sensor_is_active() const
{
    if (!get_function_is_used())
        return false;

    return (_sensor_system_descriptor & 0b00000001) != 0;
}

bool NetworkAttitudeVelocityDatagram::get_roll_sensor_is_active() const
{
    if (!get_function_is_used())
        return false;

    return (_sensor_system_descriptor & 0b00000010) != 0;
}

bool NetworkAttitudeVelocityDatagram::get_pitch_sensor_is_active() const
{
    if (!get_function_is_used())
        return false;

    return (_sensor_system_descriptor & 0b00000100) != 0;
}

bool NetworkAttitudeVelocityDatagram::get_heave_sensor_is_active() const
{
    if (!get_function_is_used())
        return false;

    return (_sensor_system_descriptor & 0b00001000) != 0;
}

bool NetworkAttitudeVelocityDatagram::get_function_is_used() const
{
    return _sensor_system_descriptor != -1;
}

NetworkAttitudeVelocityDatagram NetworkAttitudeVelocityDatagram::from_stream(std::istream& is, KongsbergAllDatagram header)
{
    auto start_pos = is.tellg();

    NetworkAttitudeVelocityDatagram datagram(std::move(header));

    if (datagram._datagram_identifier !=
        t_KongsbergAllDatagramIdentifier::NetworkAttitudeVelocityDatagram)
        throw std::runtime_error(
            fmt::format("NetworkAttitudeVelocityDatagram: datagram identifier is not 0x{:02x}, "
                        "but 0x{:02x}",
                        uint8_t(t_KongsbergAllDatagramIdentifier::NetworkAttitudeVelocityDatagram),
                        uint8_t(datagram._datagram_identifier)));

    // read first part of the datagram (until the first beam)
    is.read(reinterpret_cast<char*>(&(datagram._network_attitude_counter)),
            8 * sizeof(uint8_t));

    // read the attitude entries
    datagram._attitudes.reserve(datagram._number_of_entries);
    for (size_t i = 0; i < datagram._number_of_entries; ++i)
    {
        datagram._attitudes.emplace_back(
            substructures::NetworkAttitudeVelocityDatagramAttitude::from_stream(is));
    }

    // check if alignment is necessary
    // if pos difference is even, read the _spar_align field
    if ((is.tellg() - start_pos) % 2 != 1)
        is.read(reinterpret_cast<char*>(&(datagram._spare_align)), 4 * sizeof(uint8_t));

    else
    {
        is.read(reinterpret_cast<char*>(&(datagram._etx)), 3 * sizeof(uint8_t));
        // is.read(reinterpret_cast<char*>(&(datagram._etx)), sizeof(uint8_t));
        // is.read(reinterpret_cast<char*>(&(datagram._checksum)), sizeof(uint16_t));
    }

    if (datagram._etx != 0x03)
        throw std::runtime_error(fmt::format(
            "NetworkAttitudeVelocityDatagram: end identifier is not 0x03, but 0x{:x}",
            datagram._etx));

    return datagram;
}

NetworkAttitudeVelocityDatagram NetworkAttitudeVelocityDatagram::from_stream(std::istream& is)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is));
}

NetworkAttitudeVelocityDatagram NetworkAttitudeVelocityDatagram::from_stream(
    std::istream&              is,
    t_KongsbergAllDatagramIdentifier datagram_identifier)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is, datagram_identifier));
}

void NetworkAttitudeVelocityDatagram::to_stream(std::ostream& os)
{
    auto start_pos = os.tellp();

    KongsbergAllDatagram::to_stream(os);
    _number_of_entries = _attitudes.size();

    // write first part of the datagram (until the first beam)
    os.write(reinterpret_cast<const char*>(&(_network_attitude_counter)), 8 * sizeof(uint8_t));

    // write the attitude entries
    for (auto& attitude : _attitudes)
        attitude.to_stream(os);

    // check if alignment is necessary
    // if pos difference is even, write the _spar_align field (0)
    if ((os.tellp() - start_pos) % 2 != 1)
        os.write(reinterpret_cast<const char*>(&(_spare_align)), 4 * sizeof(uint8_t));

    else
    {
        os.write(reinterpret_cast<const char*>(&(_etx)), sizeof(uint8_t));
        os.write(reinterpret_cast<const char*>(&(_checksum)), sizeof(uint16_t));
    }
}

tools::classhelper::ObjectPrinter NetworkAttitudeVelocityDatagram::__printer__(unsigned int float_precision, bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer("NetworkAttitudeVelocityDatagram",
                                              float_precision, superscript_exponents);

    printer.append(KongsbergAllDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("datagram content");
    printer.register_value("network_attitude_counter", _network_attitude_counter);
    printer.register_value("system_serial_number", _system_serial_number);
    printer.register_value("number_of_entries", _number_of_entries);
    printer.register_string("sensor_system_descriptor",
                            fmt::format("0b{:08b}", _sensor_system_descriptor));
    printer.register_value("spare", _spare);
    printer.register_value("spare_align", _spare_align);
    printer.register_string("etx", fmt::format("0x{:02x}", _etx));
    printer.register_value("checksum", _checksum);

    printer.register_section("processed");
    printer.register_value(
        "attitude_velocity_sensor_number", get_attitude_velocity_sensor_number(), "1,2");
    printer.register_value("velocity_sensor_is_active", get_velocity_sensor_is_active());
    printer.register_value("heading_sensor_is_active", get_heading_sensor_is_active());
    printer.register_value("roll_sensor_is_active", get_roll_sensor_is_active());
    printer.register_value("pitch_sensor_is_active", get_pitch_sensor_is_active());
    printer.register_value("heave_sensor_is_active", get_heave_sensor_is_active());
    printer.register_value("function_is_used", get_function_is_used());

    printer.register_section("substructures");
    printer.register_value(
        "attitudes", _attitudes.size(), "NetworkAttitudeVelocityDatagramAttitude");

    return printer;
}

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
