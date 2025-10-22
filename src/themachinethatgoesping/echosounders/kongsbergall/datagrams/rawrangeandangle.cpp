// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "rawrangeandangle.hpp"

/* std includes */
#include <cstddef>
#include <fmt/core.h>
#include <limits>
#include <stdexcept>
#include <utility>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

RawRangeAndAngle::RawRangeAndAngle(KongsbergAllDatagram header)
    : KongsbergAllDatagram(std::move(header))
{
}

RawRangeAndAngle::RawRangeAndAngle()
{
    _datagram_identifier = t_KongsbergAllDatagramIdentifier::RawRangeAndAngle;
}

xt::xtensor<float, 1> RawRangeAndAngle::get_two_way_travel_times() const
{
    auto twtt = xt::xtensor<float, 1>::from_shape({ _beams.size() });

    for (std::size_t bn = 0; bn < _beams.size(); ++bn)
    {
        twtt.unchecked(bn) = _beams[bn].get_two_way_travel_time();
    }

    return twtt;
}

xt::xtensor<float, 1> RawRangeAndAngle::get_two_way_travel_times(
    const std::vector<uint32_t>& beam_numbers) const
{
    auto twtt = xt::xtensor<float, 1>::from_shape({ beam_numbers.size() });

    for (const auto bn : beam_numbers)
    {
        if (bn >= _beams.size())
            twtt.unchecked(bn) = std::numeric_limits<float>::quiet_NaN();
        else
            twtt.unchecked(bn) = _beams[bn].get_two_way_travel_time();
    }

    return twtt;
}

xt::xtensor<float, 1> RawRangeAndAngle::get_beam_crosstrack_angles() const
{
    auto bpa = xt::xtensor<float, 1>::from_shape({ _beams.size() });

    for (std::size_t bn = 0; bn < _beams.size(); ++bn)
    {
        bpa.unchecked(bn) = _beams[bn].get_beam_crosstrack_angle();
    }

    return bpa;
}

xt::xtensor<float, 1> RawRangeAndAngle::get_beam_crosstrack_angles(
    const std::vector<uint32_t>& beam_numbers) const
{
    auto angles = xt::xtensor<float, 1>::from_shape({ beam_numbers.size() });

    for (std::size_t i = 0; i < beam_numbers.size(); ++i)
    {
        if (beam_numbers[i] >= _beams.size())
            angles.unchecked(i) = std::numeric_limits<float>::quiet_NaN();
        else
            angles.unchecked(i) =
                _beams[beam_numbers[i]].get_beam_crosstrack_angle_in_degrees();
    }

    return angles;
}

uint16_t RawRangeAndAngle::get_ping_counter() const { return _ping_counter; }

uint16_t RawRangeAndAngle::get_system_serial_number() const { return _system_serial_number; }

uint16_t RawRangeAndAngle::get_sound_speed_at_transducer() const
{
    return _sound_speed_at_transducer;
}

uint16_t RawRangeAndAngle::get_number_of_transmit_sectors() const
{
    return _number_of_transmit_sectors;
}

uint16_t RawRangeAndAngle::get_number_of_receiver_beams() const
{
    return _number_of_receiver_beams;
}

uint16_t RawRangeAndAngle::get_number_of_valid_detections() const
{
    return _number_of_valid_detections;
}

float RawRangeAndAngle::get_sampling_frequency() const { return _sampling_frequency; }

uint32_t RawRangeAndAngle::get_d_scale() const { return _d_scale; }

const std::vector<substructures::RawRangeAndAngleTransmitSector>&
RawRangeAndAngle::get_transmit_sectors() const
{
    return _transmit_sectors;
}

const std::vector<substructures::RawRangeAndAngleBeam>& RawRangeAndAngle::get_beams() const
{
    return _beams;
}

uint8_t RawRangeAndAngle::get_spare() const { return _spare; }

uint8_t RawRangeAndAngle::get_etx() const { return _etx; }

uint16_t RawRangeAndAngle::get_checksum() const { return _checksum; }

std::vector<substructures::RawRangeAndAngleTransmitSector>& RawRangeAndAngle::transmit_sectors()
{
    return _transmit_sectors;
}

std::vector<substructures::RawRangeAndAngleBeam>& RawRangeAndAngle::beams()
{
    return _beams;
}

void RawRangeAndAngle::set_ping_counter(uint16_t ping_counter)
{
    _ping_counter = ping_counter;
}

void RawRangeAndAngle::set_system_serial_number(uint16_t system_serial_number)
{
    _system_serial_number = system_serial_number;
}

void RawRangeAndAngle::set_sound_speed_at_transducer(uint16_t sound_speed_at_transducer)
{
    _sound_speed_at_transducer = sound_speed_at_transducer;
}

void RawRangeAndAngle::set_number_of_transmit_sectors(uint16_t number_of_transmit_sectors)
{
    _number_of_transmit_sectors = number_of_transmit_sectors;
}

void RawRangeAndAngle::set_number_of_receiver_beams(uint16_t number_of_receiver_beams)
{
    _number_of_receiver_beams = number_of_receiver_beams;
}

void RawRangeAndAngle::set_number_of_valid_detections(uint16_t number_of_valid_detections)
{
    _number_of_valid_detections = number_of_valid_detections;
}

void RawRangeAndAngle::set_sampling_frequency(float sampling_frequency)
{
    _sampling_frequency = sampling_frequency;
}

void RawRangeAndAngle::set_d_scale(uint32_t d_scale) { _d_scale = d_scale; }

void RawRangeAndAngle::set_transmit_sectors(
    const std::vector<substructures::RawRangeAndAngleTransmitSector>& transmit_sector)
{
    _transmit_sectors = transmit_sector;
}

void RawRangeAndAngle::set_beams(const std::vector<substructures::RawRangeAndAngleBeam>& beams)
{
    _beams = beams;
}

void RawRangeAndAngle::set_spare(uint8_t spare) { _spare = spare; }

void RawRangeAndAngle::set_etx(uint8_t etx) { _etx = etx; }

void RawRangeAndAngle::set_checksum(uint16_t checksum) { _checksum = checksum; }

float RawRangeAndAngle::get_sound_speed_at_transducer_in_m_per_s() const
{
    return _sound_speed_at_transducer * 0.1F;
}

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
