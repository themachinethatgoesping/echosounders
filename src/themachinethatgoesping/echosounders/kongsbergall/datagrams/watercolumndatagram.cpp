// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "watercolumndatagram.hpp"

#include <fmt/core.h>

#include <algorithm>
#include <istream>
#include <limits>
#include <ostream>
#include <stdexcept>
#include <utility>

#include <xtensor/views/xview.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

WatercolumnDatagram::WatercolumnDatagram(KongsbergAllDatagram header)
    : KongsbergAllDatagram(std::move(header))
{
}

WatercolumnDatagram::WatercolumnDatagram()
{
    _datagram_identifier = t_KongsbergAllDatagramIdentifier::WatercolumnDatagram;
}

size_t WatercolumnDatagram::get_max_number_of_samples() const
{
    size_t max_samples = 0;
    for (const auto& beam : _beams)
    {
        max_samples = std::max<size_t>(max_samples, beam.get_number_of_samples());
    }
    return max_samples;
}

xt::xtensor<int8_t, 2> WatercolumnDatagram::read_samples(std::istream& ifs) const
{
    using xt::placeholders::_;

    xt::xtensor<int8_t, 2> samples = xt::zeros<int8_t>(
        xt::xtensor<int8_t, 2>::shape_type({ _beams.size(), get_max_number_of_samples() }));

    for (std::size_t b = 0; b < _beams.size(); ++b)
    {
        xt::xtensor<float, 1> beamsamples = _beams[b].read_samples(ifs);
        beamsamples *= 0.5f;
        beamsamples -= _tvg_offset_in_db;

        std::copy(beamsamples.cbegin(), beamsamples.cend(), xt::row(samples, b).begin());

        xt::view(samples, b, xt::range(_beams[b].get_number_of_samples(), _)) =
            std::numeric_limits<float>::quiet_NaN();
    }

    return samples;
}

xt::xtensor<float, 2> WatercolumnDatagram::get_samples() const
{
    using xt::placeholders::_;

    xt::xtensor<float, 2> samples = xt::empty<float>(
        xt::xtensor<float, 2>::shape_type({ _beams.size(), get_max_number_of_samples() }));

    for (std::size_t b = 0; b < _beams.size(); ++b)
    {
        xt::xtensor<float, 1> beamsamples = _beams[b].get_samples();
        beamsamples *= 0.5f;
        beamsamples -= _tvg_offset_in_db;

        std::copy(beamsamples.cbegin(), beamsamples.cend(), xt::row(samples, b).begin());

        xt::view(samples, b, xt::range(_beams[b].get_number_of_samples(), _)) =
            std::numeric_limits<float>::quiet_NaN();
    }

    return samples;
}

uint16_t WatercolumnDatagram::get_ping_counter() const
{
    return _ping_counter;
}

uint16_t WatercolumnDatagram::get_system_serial_number() const
{
    return _system_serial_number;
}

uint16_t WatercolumnDatagram::get_number_of_datagrams() const
{
    return _number_of_datagrams;
}

uint16_t WatercolumnDatagram::get_datagram_number() const
{
    return _datagram_number;
}

uint16_t WatercolumnDatagram::get_number_of_transmit_sectors() const
{
    return _number_of_transmit_sectors;
}

uint16_t WatercolumnDatagram::get_total_no_of_receive_beams() const
{
    return _total_no_of_receive_beams;
}

uint16_t WatercolumnDatagram::get_number_of_beams_in_datagram() const
{
    return _number_of_beams_in_datagram;
}

uint16_t WatercolumnDatagram::get_sound_speed() const
{
    return _sound_speed;
}

uint32_t WatercolumnDatagram::get_sampling_frequency() const
{
    return _sampling_frequency;
}

int16_t WatercolumnDatagram::get_tx_time_heave() const
{
    return _tx_time_heave;
}

uint8_t WatercolumnDatagram::get_tvg_function_applied() const
{
    return _tvg_function_applied;
}

int8_t WatercolumnDatagram::get_tvg_offset_in_db() const
{
    return _tvg_offset_in_db;
}

uint8_t WatercolumnDatagram::get_scanning_info() const
{
    return _scanning_info;
}

std::array<uint8_t, 3> WatercolumnDatagram::get_spare() const
{
    return _spare;
}

uint8_t WatercolumnDatagram::get_spare_byte() const
{
    return _spare_byte;
}

uint8_t WatercolumnDatagram::get_etx() const
{
    return _etx;
}

uint16_t WatercolumnDatagram::get_checksum() const
{
    return _checksum;
}

void WatercolumnDatagram::set_ping_counter(uint16_t ping_counter)
{
    _ping_counter = ping_counter;
}

void WatercolumnDatagram::set_system_serial_number(uint16_t system_serial_number)
{
    _system_serial_number = system_serial_number;
}

void WatercolumnDatagram::set_number_of_datagrams(uint16_t number_of_datagrams)
{
    _number_of_datagrams = number_of_datagrams;
}

void WatercolumnDatagram::set_datagram_number(uint16_t datagram_number)
{
    _datagram_number = datagram_number;
}

void WatercolumnDatagram::set_number_of_transmit_sectors(uint16_t number_of_transmit_sectors)
{
    _number_of_transmit_sectors = number_of_transmit_sectors;
}

void WatercolumnDatagram::set_total_no_of_receive_beams(uint16_t total_no_of_receive_beams)
{
    _total_no_of_receive_beams = total_no_of_receive_beams;
}

void WatercolumnDatagram::set_number_of_beams_in_datagram(uint16_t number_of_beams_in_datagram)
{
    _number_of_beams_in_datagram = number_of_beams_in_datagram;
}

void WatercolumnDatagram::set_sound_speed(uint16_t sound_speed)
{
    _sound_speed = sound_speed;
}

void WatercolumnDatagram::set_sampling_frequency(uint32_t sampling_frequency)
{
    _sampling_frequency = sampling_frequency;
}

void WatercolumnDatagram::set_tx_time_heave(int16_t tx_time_heave)
{
    _tx_time_heave = tx_time_heave;
}

void WatercolumnDatagram::set_tvg_function_applied(uint8_t tvg_function_applied)
{
    _tvg_function_applied = tvg_function_applied;
}

void WatercolumnDatagram::set_tvg_offset_in_db(int8_t tvg_offset_in_db)
{
    _tvg_offset_in_db = tvg_offset_in_db;
}

void WatercolumnDatagram::set_scanning_info(uint8_t scanning_info)
{
    _scanning_info = scanning_info;
}

void WatercolumnDatagram::set_spare(std::array<uint8_t, 3> spare)
{
    _spare = spare;
}

void WatercolumnDatagram::set_spare_byte(uint8_t spare_byte)
{
    _spare_byte = spare_byte;
}

void WatercolumnDatagram::set_etx(uint8_t etx)
{
    _etx = etx;
}

void WatercolumnDatagram::set_checksum(uint16_t checksum)
{
    _checksum = checksum;
}

const std::vector<substructures::WatercolumnDatagramTransmitSector>&
WatercolumnDatagram::get_transmit_sectors() const
{
    return _transmit_sectors;
}

std::vector<substructures::WatercolumnDatagramTransmitSector>&
WatercolumnDatagram::transmit_sectors()
{
    return _transmit_sectors;
}

void WatercolumnDatagram::set_transmit_sectors(
    std::vector<substructures::WatercolumnDatagramTransmitSector> transmit_sectors)
{
    _transmit_sectors = std::move(transmit_sectors);
}

const std::vector<substructures::WatercolumnDatagramBeam>& WatercolumnDatagram::get_beams() const
{
    return _beams;
}

std::vector<substructures::WatercolumnDatagramBeam>& WatercolumnDatagram::beams()
{
    return _beams;
}

void WatercolumnDatagram::set_beams(std::vector<substructures::WatercolumnDatagramBeam> beams)
{
    _beams = std::move(beams);
}

float WatercolumnDatagram::get_sound_speed_m_s() const
{
    return _sound_speed * 0.1f;
}

float WatercolumnDatagram::get_sampling_frequency_in_hz() const
{
    return _sampling_frequency * 0.01f;
}

float WatercolumnDatagram::get_tx_time_heave_in_m() const
{
    return _tx_time_heave * 0.01f;
}

WatercolumnDatagram WatercolumnDatagram::from_stream(std::istream&        is,
                                                     KongsbergAllDatagram header,
                                                     bool                 skip_data)
{
    WatercolumnDatagram datagram(std::move(header));

    if (datagram._datagram_identifier != t_KongsbergAllDatagramIdentifier::WatercolumnDatagram)
        throw std::runtime_error(fmt::format(
            "WatercolumnDatagram: datagram identifier is not 0x{:02x}, but 0x{:02x}",
            uint8_t(t_KongsbergAllDatagramIdentifier::WatercolumnDatagram),
            uint8_t(datagram._datagram_identifier)));

    // read first part of the datagram (until the first beam)
    is.read(reinterpret_cast<char*>(&(datagram._ping_counter)), 28 * sizeof(uint8_t));

    // read the transmit_sectors
    datagram._transmit_sectors.resize(datagram._number_of_transmit_sectors);
    is.read(reinterpret_cast<char*>(datagram._transmit_sectors.data()),
            datagram._number_of_transmit_sectors *
                sizeof(substructures::WatercolumnDatagramTransmitSector));

    // read the beams
    datagram._beams.reserve(datagram._number_of_beams_in_datagram);
    for (auto i = 0; i < datagram._number_of_beams_in_datagram; ++i)
        datagram._beams.emplace_back(
            substructures::WatercolumnDatagramBeam::from_stream(is, skip_data));

    // read the rest of the datagram
    is.read(reinterpret_cast<char*>(&(datagram._spare_byte)), 4 * sizeof(uint8_t));

    if (datagram._etx != 0x03)
        throw std::runtime_error(fmt::format(
            "WatercolumnDatagram: end identifier is not 0x03, but 0x{:x}", datagram._etx));

    return datagram;
}

WatercolumnDatagram WatercolumnDatagram::from_stream(std::istream& is, bool skip_data)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is), skip_data);
}

WatercolumnDatagram WatercolumnDatagram::from_stream(std::istream&                    is,
                                                     t_KongsbergAllDatagramIdentifier datagram_identifier,
                                                     bool                             skip_data)
{
    return from_stream(
        is, KongsbergAllDatagram::from_stream(is, datagram_identifier), skip_data);
}

void WatercolumnDatagram::append_from_stream(std::istream& is)
{
    bool skip_data = _beams.at(0).get_samples_are_skipped();

    /* skip header + ping_counter - number of datagrams*/
    is.seekg(22, std::ios_base::cur);

    /* read important variables */
    struct
    {
        uint16_t datagram_number;
        uint16_t number_of_transmit_sectors;
        uint16_t total_no_of_receive_beams;
        uint16_t number_of_beams_in_datagram;
    } data;

    is.read(reinterpret_cast<char*>(&data.datagram_number), sizeof(data));

    /* check if number of beams makes sense */
    if (_number_of_beams_in_datagram + data.number_of_beams_in_datagram >
        _total_no_of_receive_beams)
        throw std::runtime_error(
            fmt::format("ERROR[WatercolumnDatagram::append_from_stream]: number of append "
                        "beams [{}] exceeds total number of beams [{}/{}]",
                        data.number_of_beams_in_datagram,
                        _number_of_beams_in_datagram,
                        _total_no_of_receive_beams));

    /* sanity checks */
    if (data.datagram_number > _number_of_datagrams)
        throw std::runtime_error(
            fmt::format("ERROR[WatercolumnDatagram::append_from_stream]: datagram number "
                        "exceeds number of datagrams [{}/{}]",
                        data.datagram_number,
                        _number_of_datagrams));
    if (data.number_of_transmit_sectors != _number_of_transmit_sectors)
        throw std::runtime_error(fmt::format("ERROR[WatercolumnDatagram::append_from_stream]: "
                                             "number_of_transmit_sectors missmatch [{}/{}]",
                                             data.number_of_transmit_sectors,
                                             _number_of_transmit_sectors));
    if (data.total_no_of_receive_beams != _total_no_of_receive_beams)
        throw std::runtime_error(fmt::format("ERROR[WatercolumnDatagram::append_from_stream]: "
                                             "total_no_of_receive_beams missmatch [{}/{}]",
                                             data.total_no_of_receive_beams,
                                             _total_no_of_receive_beams));

    /* skip the rest of the data and the transmit sectors */
    is.seekg(14 + data.number_of_transmit_sectors *
                      sizeof(substructures::WatercolumnDatagramTransmitSector),
             std::ios_base::cur);

    /* update new number of beams in datagram */
    _number_of_beams_in_datagram += data.number_of_beams_in_datagram;

    // read the additional beams
    _beams.reserve(_total_no_of_receive_beams);
    for (auto i = 0; i < data.number_of_beams_in_datagram; ++i)
        _beams.emplace_back(substructures::WatercolumnDatagramBeam::from_stream(is, skip_data));

    // read the rest of the datagram
    is.read(reinterpret_cast<char*>(&(_spare_byte)), 4 * sizeof(uint8_t));

    if (_etx != 0x03)
        throw std::runtime_error(
            fmt::format("WatercolumnDatagram: end identifier is not 0x03, but 0x{:x}", _etx));
}

void WatercolumnDatagram::to_stream(std::ostream& os)
{
    KongsbergAllDatagram::to_stream(os);
    _number_of_transmit_sectors  = _transmit_sectors.size();
    _number_of_beams_in_datagram = _beams.size();

    // write first part of the datagram (until the first beam)
    os.write(reinterpret_cast<const char*>(&(_ping_counter)), 28 * sizeof(uint8_t));

    // write the transmit sector
    os.write(reinterpret_cast<const char*>(_transmit_sectors.data()),
             _number_of_transmit_sectors *
                 sizeof(substructures::WatercolumnDatagramTransmitSector));

    // write the beams
    for (auto beam : _beams)
        beam.to_stream(os);

    // write the rest of the datagram
    os.write(reinterpret_cast<const char*>(&(_spare_byte)), 4 * sizeof(uint8_t));
}

tools::classhelper::ObjectPrinter WatercolumnDatagram::__printer__(unsigned int float_precision, bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer("WatercolumnDatagram", float_precision, superscript_exponents);

    printer.append(KongsbergAllDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("datagram content");
    printer.register_value("ping_counter", _ping_counter);
    printer.register_value("system_serial_number", _system_serial_number);
    printer.register_value("number_of_datagrams", _number_of_datagrams);
    printer.register_value("datagram_number", _datagram_number);
    printer.register_value("number_of_transmit_sectors", _number_of_transmit_sectors);
    printer.register_value("total_no_of_receive_beams", _total_no_of_receive_beams);
    printer.register_value("number_of_beams_in_datagram", _number_of_beams_in_datagram);
    printer.register_value("sound_speed", _sound_speed, "0.1 m/s");
    printer.register_value("sampling_frequency", _sampling_frequency, "0.01 Hz");
    printer.register_value("tx_time_heave", _tx_time_heave, "cm");
    printer.register_value("tvg_function_applied", _tvg_function_applied);
    printer.register_value("tvg_offset_in_db", _tvg_offset_in_db);
    printer.register_string("scanning_info", fmt::format("0b{:08b}", _scanning_info));
    printer.register_string("spare",
                            fmt::format("0x{:1x}{:1x}{:1x}", _spare[0], _spare[1], _spare[2]));
    printer.register_value("spare_byte", _spare_byte);

    printer.register_section("processed");
    printer.register_value("sound_speed", get_sound_speed_m_s(), "m/s");
    printer.register_value("sampling_frequency", get_sampling_frequency_in_hz(), "Hz");
    printer.register_value("tx_time_heave", get_tx_time_heave_in_m(), "m");

    printer.register_section("substructures");
    printer.register_value(
        "transmit_sectors", _transmit_sectors.size(), "WatercolumnDatagramTransmitSector");
    printer.register_value("beams", _beams.size(), "WatercolumnDatagramBeams");

    return printer;
}

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
