// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "positiondatagram.hpp"

#include <fmt/core.h>
#include <stdexcept>
#include <utility>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

PositionDatagram::PositionDatagram(KongsbergAllDatagram header)
    : KongsbergAllDatagram(std::move(header))
{
}

PositionDatagram::PositionDatagram()
{
    _datagram_identifier = t_KongsbergAllDatagramIdentifier::PositionDatagram;
}

uint16_t PositionDatagram::get_position_counter() const
{
    return _position_counter;
}

uint16_t PositionDatagram::get_system_serial_number() const
{
    return _system_serial_number;
}

int32_t PositionDatagram::get_latitude() const
{
    return _latitude;
}

int32_t PositionDatagram::get_longitude() const
{
    return _longitude;
}

uint16_t PositionDatagram::get_position_fix_quality() const
{
    return _position_fix_quality;
}

uint16_t PositionDatagram::get_speed() const
{
    return _speed;
}

uint16_t PositionDatagram::get_course() const
{
    return _course;
}

uint16_t PositionDatagram::get_heading() const
{
    return _heading;
}

uint8_t PositionDatagram::get_position_system_descriptor() const
{
    return _position_system_descriptor;
}

uint8_t PositionDatagram::get_size_of_input_datagram() const
{
    return _size_of_input_datagram;
}

std::string PositionDatagram::get_input_datagram() const
{
    return _input_datagram;
}

uint8_t PositionDatagram::get_spare() const
{
    return _spare;
}

uint8_t PositionDatagram::get_etx() const
{
    return _etx;
}

uint16_t PositionDatagram::get_checksum() const
{
    return _checksum;
}

void PositionDatagram::set_position_counter(uint16_t position_counter)
{
    _position_counter = position_counter;
}

void PositionDatagram::set_system_serial_number(uint16_t system_serial_number)
{
    _system_serial_number = system_serial_number;
}

void PositionDatagram::set_latitude(int32_t latitude)
{
    _latitude = latitude;
}

void PositionDatagram::set_longitude(int32_t longitude)
{
    _longitude = longitude;
}

void PositionDatagram::set_position_fix_quality(uint16_t position_fix_quality)
{
    _position_fix_quality = position_fix_quality;
}

void PositionDatagram::set_speed(uint16_t speed)
{
    _speed = speed;
}

void PositionDatagram::set_course(uint16_t course)
{
    _course = course;
}

void PositionDatagram::set_heading(uint16_t heading)
{
    _heading = heading;
}

void PositionDatagram::set_position_system_descriptor(uint8_t position_system_descriptor)
{
    _position_system_descriptor = position_system_descriptor;
}

void PositionDatagram::set_size_of_input_datagram(uint8_t size_of_input_datagram)
{
    _size_of_input_datagram = size_of_input_datagram;
}

void PositionDatagram::set_input_datagram(std::string input_datagram)
{
    _input_datagram = std::move(input_datagram);
}

void PositionDatagram::set_spare(uint8_t spare)
{
    _spare = spare;
}

void PositionDatagram::set_etx(uint8_t etx)
{
    _etx = etx;
}

void PositionDatagram::set_checksum(uint16_t checksum)
{
    _checksum = checksum;
}

double PositionDatagram::get_latitude_in_degrees() const
{
    return _latitude * 0.00000005;
}

double PositionDatagram::get_longitude_in_degrees() const
{
    return _longitude * 0.0000001;
}

float PositionDatagram::get_position_fix_quality_in_meters() const
{
    return _position_fix_quality * 0.01F;
}

float PositionDatagram::get_speed_in_meters_per_second() const
{
    return _speed * 0.01F;
}

float PositionDatagram::get_course_in_degrees() const
{
    return _course * 0.01F;
}

float PositionDatagram::get_heading_in_degrees() const
{
    return _heading * 0.01F;
}

uint8_t PositionDatagram::get_position_system_number() const
{
    return _position_system_descriptor & 0b00000011;
}

bool PositionDatagram::get_position_system_SIMRAD90_flag() const
{
    return (_position_system_descriptor & 0b00001000) > 0;
}

bool PositionDatagram::get_position_system_system_time_has_been_used() const
{
    return (_position_system_descriptor & 0b11000000) == 0b10000000;
}

PositionDatagram PositionDatagram::from_stream(std::istream& is, KongsbergAllDatagram header)
{
    PositionDatagram datagram(std::move(header));

    if (datagram._datagram_identifier != t_KongsbergAllDatagramIdentifier::PositionDatagram)
        throw std::runtime_error(
            fmt::format("PositionDatagram: datagram identifier is not 0x{:02x}, but 0x{:02x}",
                        uint8_t(t_KongsbergAllDatagramIdentifier::PositionDatagram),
                        uint8_t(datagram._datagram_identifier)));

    // read first part of the datagram (until the first beam)
    is.read(reinterpret_cast<char*>(&(datagram._position_counter)), 22 * sizeof(uint8_t));

    // read the input datagram
    datagram._input_datagram.resize(datagram._size_of_input_datagram);
    is.read(reinterpret_cast<char*>(datagram._input_datagram.data()),
            datagram._size_of_input_datagram * sizeof(uint8_t));

    if (datagram._size_of_input_datagram % 2 == 0)
        is.read(reinterpret_cast<char*>(&(datagram._spare)), 4 * sizeof(uint8_t));
    else
        is.read(reinterpret_cast<char*>(&(datagram._etx)), 3 * sizeof(uint8_t));

    if (datagram._etx != 0x03)
        throw std::runtime_error(fmt::format(
            "PositionDatagram: end identifier is not 0x03, but 0x{:x}", datagram._etx));

    return datagram;
}

PositionDatagram PositionDatagram::from_stream(std::istream& is)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is));
}

PositionDatagram PositionDatagram::from_stream(std::istream&              is,
                                               t_KongsbergAllDatagramIdentifier datagram_identifier)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is, datagram_identifier));
}

void PositionDatagram::to_stream(std::ostream& os) const
{
    if (_input_datagram.size() != _size_of_input_datagram)
        throw std::runtime_error(fmt::format(
            "PositionDatagram::to_stream(): size of input datagram is not {}, but {}",
            _size_of_input_datagram,
            _input_datagram.size()));

    KongsbergAllDatagram::to_stream(os);

    // write first part of the datagram (until the first beam)
    os.write(reinterpret_cast<const char*>(&(_position_counter)), 22 * sizeof(uint8_t));

    // write the input datagram
    os.write(reinterpret_cast<const char*>(_input_datagram.data()),
             _size_of_input_datagram * sizeof(uint8_t));

    // write the last part of the datagram
    if (_size_of_input_datagram % 2 == 0)
        os.write(reinterpret_cast<const char*>(&_spare), 4 * sizeof(uint8_t));
    else
        os.write(reinterpret_cast<const char*>(&_etx), 3 * sizeof(uint8_t));
}

tools::classhelper::ObjectPrinter PositionDatagram::__printer__(unsigned int float_precision, bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer("PositionDatagram", float_precision, superscript_exponents);

    printer.append(KongsbergAllDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("datagram content");
    printer.register_value("position_counter", _position_counter);
    printer.register_value("system_serial_number", _system_serial_number);
    printer.register_value("latitude", _latitude, "°0.00000005°");
    printer.register_value("longitude", _longitude, " 0.0000001°");
    printer.register_value("position_fix_quality", _position_fix_quality, "cm");
    printer.register_value("speed", _speed, "cm/s");
    printer.register_value("course", _course, "0.01°");
    printer.register_value("heading", _heading, "0.01°");
    printer.register_string("position_system_descriptor",
                            fmt::format("0b{:08x}", _position_system_descriptor));
    printer.register_value("size_of_input_datagram", _size_of_input_datagram, "bytes");

    printer.register_section("processed");
    printer.register_value("latitude", get_latitude_in_degrees(), "°");
    printer.register_value("longitude", get_longitude_in_degrees(), "°");
    printer.register_value("position_fix_quality", get_position_fix_quality_in_meters(), "m");
    printer.register_value("speed", get_speed_in_meters_per_second(), "m/s");
    printer.register_value("course", get_course_in_degrees(), "°");
    printer.register_value("heading", get_heading_in_degrees(), "°");
    printer.register_value("position_system_number", get_position_system_number(), "1,2 or 3");
    printer.register_value("position_system_SIMRAD90_flag",
                           get_position_system_SIMRAD90_flag());
    printer.register_value("position_system_system_time_has_been_used",
                           get_position_system_system_time_has_been_used());
    printer.register_value("position_system_input_datagram_time_has_been_used",
                           !get_position_system_system_time_has_been_used());

    printer.register_section("substructures");
    printer.register_string("input_datagram", _input_datagram);

    return printer;
}

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
