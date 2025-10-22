// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "xyzdatagram.hpp"

#include <fmt/core.h>

#include <limits>
#include <stdexcept>
#include <utility>

#include <themachinethatgoesping/tools/helper/floatcompare.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

XYZDatagram::XYZDatagram(KongsbergAllDatagram header)
    : KongsbergAllDatagram(std::move(header))
{
}

XYZDatagram::XYZDatagram()
{
    _datagram_identifier = t_KongsbergAllDatagramIdentifier::XYZDatagram;
}

XYZDatagram::t_XYZ XYZDatagram::get_xyz() const
{
    t_XYZ xyz({ _beams.size() });

    for (unsigned int bn = 0; bn < _beams.size(); ++bn)
    {
        xyz.x.unchecked(bn) = _beams[bn].get_alongtrack_distance();
        xyz.y.unchecked(bn) = _beams[bn].get_acrosstrack_distance();
        xyz.z.unchecked(bn) = _beams[bn].get_depth();
    }

    return xyz;
}

XYZDatagram::t_XYZ XYZDatagram::get_xyz(const std::vector<uint32_t>& beam_numbers) const
{
    t_XYZ xyz({ beam_numbers.size() });

    for (unsigned int bi = 0; bi < beam_numbers.size(); ++bi)
    {
        auto bn = beam_numbers[bi];
        if (bn >= _beams.size())
        {
            xyz.x.unchecked(bi) = std::numeric_limits<float>::quiet_NaN();
            xyz.y.unchecked(bi) = std::numeric_limits<float>::quiet_NaN();
            xyz.z.unchecked(bi) = std::numeric_limits<float>::quiet_NaN();
        }
        else
        {
            xyz.x.unchecked(bi) = _beams[bn].get_alongtrack_distance();
            xyz.y.unchecked(bi) = _beams[bn].get_acrosstrack_distance();
            xyz.z.unchecked(bi) = _beams[bn].get_depth();
        }
    }

    return xyz;
}

uint16_t XYZDatagram::get_ping_counter() const
{
    return _ping_counter;
}

uint16_t XYZDatagram::get_system_serial_number() const
{
    return _system_serial_number;
}

uint16_t XYZDatagram::get_heading() const
{
    return _heading;
}

uint16_t XYZDatagram::get_sound_speed() const
{
    return _sound_speed;
}

float XYZDatagram::get_transmit_transducer_depth() const
{
    return _transmit_transducer_depth;
}

uint16_t XYZDatagram::get_number_of_beams() const
{
    return _number_of_beams;
}

uint16_t XYZDatagram::get_number_of_valid_detections() const
{
    return _number_of_valid_detections;
}

float XYZDatagram::get_sampling_frequency() const
{
    return _sampling_frequency;
}

uint8_t XYZDatagram::get_scanning_info() const
{
    return _scanning_info;
}

const std::array<uint8_t, 3>& XYZDatagram::get_spare_bytes() const
{
    return _spare_bytes;
}

uint8_t XYZDatagram::get_spare_byte() const
{
    return _spare_byte;
}

uint8_t XYZDatagram::get_etx() const
{
    return _etx;
}

uint16_t XYZDatagram::get_checksum() const
{
    return _checksum;
}

void XYZDatagram::set_ping_counter(uint16_t ping_counter)
{
    _ping_counter = ping_counter;
}

void XYZDatagram::set_system_serial_number(uint16_t system_serial_number)
{
    _system_serial_number = system_serial_number;
}

void XYZDatagram::set_heading(uint16_t heading)
{
    _heading = heading;
}

void XYZDatagram::set_sound_speed(uint16_t sound_speed)
{
    _sound_speed = sound_speed;
}

void XYZDatagram::set_transmit_transducer_depth(float transmit_transducer_depth)
{
    _transmit_transducer_depth = transmit_transducer_depth;
}

void XYZDatagram::set_number_of_beams(uint16_t number_of_beams)
{
    _number_of_beams = number_of_beams;
}

void XYZDatagram::set_number_of_valid_detections(uint16_t number_of_valid_detections)
{
    _number_of_valid_detections = number_of_valid_detections;
}

void XYZDatagram::set_sampling_frequency(float sampling_frequency)
{
    _sampling_frequency = sampling_frequency;
}

void XYZDatagram::set_scanning_info(uint8_t scanning_info)
{
    _scanning_info = scanning_info;
}

void XYZDatagram::set_spare_bytes(std::array<uint8_t, 3> spare_bytes)
{
    _spare_bytes = spare_bytes;
}

void XYZDatagram::set_spare_byte(uint8_t spare_byte)
{
    _spare_byte = spare_byte;
}

void XYZDatagram::set_etx(uint8_t etx)
{
    _etx = etx;
}

void XYZDatagram::set_checksum(uint16_t checksum)
{
    _checksum = checksum;
}

std::vector<substructures::XYZDatagramBeam>& XYZDatagram::beams()
{
    return _beams;
}

const std::vector<substructures::XYZDatagramBeam>& XYZDatagram::get_beams() const
{
    return _beams;
}

void XYZDatagram::set_beams(std::vector<substructures::XYZDatagramBeam> beams)
{
    _beams = std::move(beams);
}

double XYZDatagram::get_heading_in_degrees() const
{
    return _heading * 0.01;
}

double XYZDatagram::get_sound_speed_in_m_per_s() const
{
    return _sound_speed * 0.1;
}

bool XYZDatagram::operator==(const XYZDatagram& other) const
{
    using tools::helper::float_equals;

    return KongsbergAllDatagram::operator==(other) && _ping_counter == other._ping_counter &&
           _system_serial_number == other._system_serial_number && _heading == other._heading &&
           _sound_speed == other._sound_speed &&
           float_equals(_transmit_transducer_depth, other._transmit_transducer_depth) &&
           _number_of_beams == other._number_of_beams &&
           _number_of_valid_detections == other._number_of_valid_detections &&
           float_equals(_sampling_frequency, other._sampling_frequency) &&
           _scanning_info == other._scanning_info && _spare_bytes == other._spare_bytes &&
           _beams == other._beams && _spare_byte == other._spare_byte && _etx == other._etx &&
           _checksum == other._checksum;
}

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
