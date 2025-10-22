// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "seabedimagedata.hpp"

#include <fmt/format.h>

#include <stdexcept>
#include <utility>

#include <themachinethatgoesping/tools/helper/floatcompare.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

SeabedImageData::SeabedImageData(KongsbergAllDatagram header)
    : KongsbergAllDatagram(std::move(header))
{
}

SeabedImageData::SeabedImageData()
{
    _datagram_identifier = t_KongsbergAllDatagramIdentifier::SeabedImageData;
}

uint16_t SeabedImageData::get_ping_counter() const
{
    return _ping_counter;
}

uint16_t SeabedImageData::get_system_serial_number() const
{
    return _system_serial_number;
}

float SeabedImageData::get_sampling_frequency() const
{
    return _sampling_frequency;
}

uint16_t SeabedImageData::get_range_to_normal_incidence() const
{
    return _range_to_normal_incidence;
}

int16_t SeabedImageData::get_normal_incidence_backscatter() const
{
    return _normal_incidence_backscatter;
}

int16_t SeabedImageData::get_oblique_backscatter() const
{
    return _oblique_backscatter;
}

uint16_t SeabedImageData::get_tx_beamwidth_along() const
{
    return _tx_beamwidth_along;
}

uint16_t SeabedImageData::get_tvg_law_crossover_angle() const
{
    return _tvg_law_crossover_angle;
}

uint16_t SeabedImageData::get_number_of_valid_beams() const
{
    return _number_of_valid_beams;
}

uint8_t SeabedImageData::get_spare_byte() const
{
    return _spare_byte;
}

uint8_t SeabedImageData::get_etx() const
{
    return _etx;
}

uint16_t SeabedImageData::get_checksum() const
{
    return _checksum;
}

void SeabedImageData::set_ping_counter(uint16_t ping_counter)
{
    _ping_counter = ping_counter;
}

void SeabedImageData::set_system_serial_number(uint16_t system_serial_number)
{
    _system_serial_number = system_serial_number;
}

void SeabedImageData::set_sampling_frequency(float sampling_frequency)
{
    _sampling_frequency = sampling_frequency;
}

void SeabedImageData::set_range_to_normal_incidence(uint16_t range_to_normal_incidence)
{
    _range_to_normal_incidence = range_to_normal_incidence;
}

void SeabedImageData::set_normal_incidence_backscatter(int16_t normal_incidence_backscatter)
{
    _normal_incidence_backscatter = normal_incidence_backscatter;
}

void SeabedImageData::set_oblique_backscatter(int16_t oblique_backscatter)
{
    _oblique_backscatter = oblique_backscatter;
}

void SeabedImageData::set_tx_beamwidth_along(uint16_t tx_beamwidth_along)
{
    _tx_beamwidth_along = tx_beamwidth_along;
}

void SeabedImageData::set_tvg_law_crossover_angle(uint16_t tvg_law_crossover_angle)
{
    _tvg_law_crossover_angle = tvg_law_crossover_angle;
}

void SeabedImageData::set_number_of_valid_beams(uint16_t number_of_valid_beams)
{
    _number_of_valid_beams = number_of_valid_beams;
}

void SeabedImageData::set_spare_byte(uint8_t spare_byte)
{
    _spare_byte = spare_byte;
}

void SeabedImageData::set_etx(uint8_t etx)
{
    _etx = etx;
}

void SeabedImageData::set_checksum(uint16_t checksum)
{
    _checksum = checksum;
}

const std::vector<substructures::SeabedImageDataBeam>& SeabedImageData::get_beams() const
{
    return _beams;
}

void SeabedImageData::set_beams(const std::vector<substructures::SeabedImageDataBeam>& beams)
{
    _beams = beams;
}

std::vector<substructures::SeabedImageDataBeam>& SeabedImageData::beams()
{
    return _beams;
}

const substructures::SampleAmplitudesStructure<int16_t>&
SeabedImageData::get_sample_amplitudes() const
{
    return _sample_amplitudes;
}

void SeabedImageData::set_sample_amplitudes(
    const substructures::SampleAmplitudesStructure<int16_t>& sample_amplitudes)
{
    _sample_amplitudes = sample_amplitudes;
}

substructures::SampleAmplitudesStructure<int16_t>& SeabedImageData::sample_amplitudes()
{
    return _sample_amplitudes;
}

float SeabedImageData::get_normal_incidence_backscatter_in_db() const
{
    return _normal_incidence_backscatter * 0.01f;
}

float SeabedImageData::get_oblique_backscatter_in_db() const
{
    return _oblique_backscatter * 0.01f;
}

float SeabedImageData::get_tx_beamwidth_along_in_degrees() const
{
    return _tx_beamwidth_along * 0.1f;
}

float SeabedImageData::get_tvg_law_crossover_angle_in_degrees() const
{
    return _tvg_law_crossover_angle * 0.1f;
}

bool SeabedImageData::operator==(const SeabedImageData& other) const
{
    using tools::helper::float_equals;

    return KongsbergAllDatagram::operator==(other) && _ping_counter == other._ping_counter &&
           _system_serial_number == other._system_serial_number &&
           float_equals(_sampling_frequency, other._sampling_frequency) &&
           _range_to_normal_incidence == other._range_to_normal_incidence &&
           _normal_incidence_backscatter == other._normal_incidence_backscatter &&
           _oblique_backscatter == other._oblique_backscatter &&
           _tx_beamwidth_along == other._tx_beamwidth_along &&
           _tvg_law_crossover_angle == other._tvg_law_crossover_angle &&
           _number_of_valid_beams == other._number_of_valid_beams && _beams == other._beams &&
           _sample_amplitudes == other._sample_amplitudes && _spare_byte == other._spare_byte &&
           _etx == other._etx && _checksum == other._checksum;
}

SeabedImageData SeabedImageData::from_stream(std::istream& is, KongsbergAllDatagram header)
{
    SeabedImageData datagram(std::move(header));

    if (datagram._datagram_identifier != t_KongsbergAllDatagramIdentifier::SeabedImageData)
        throw std::runtime_error(
            fmt::format("SeabedImageData: datagram identifier is not 0x{:02x}, but 0x{:02x}",
                        uint8_t(t_KongsbergAllDatagramIdentifier::SeabedImageData),
                        uint8_t(datagram._datagram_identifier)));

    // read first part of the datagram (until the first beam)
    is.read(reinterpret_cast<char*>(&(datagram._ping_counter)), 20 * sizeof(uint8_t));

    // read the beams
    datagram._beams.resize(datagram._number_of_valid_beams);
    is.read(reinterpret_cast<char*>(datagram._beams.data()),
            datagram._number_of_valid_beams * sizeof(substructures::SeabedImageDataBeam));

    uint16_t              total_samples = 0;
    std::vector<uint16_t> samples_per_beam;
    std::vector<uint16_t> start_index_per_beam;
    samples_per_beam.reserve(datagram._number_of_valid_beams);

    for (const auto& beam : datagram._beams)
    {
        start_index_per_beam.push_back(total_samples);
        samples_per_beam.push_back(beam.get_number_of_samples());
        total_samples += samples_per_beam.back();
    }

    datagram._sample_amplitudes =
        substructures::SampleAmplitudesStructure<int16_t>::from_stream(
            is, total_samples, std::move(start_index_per_beam), std::move(samples_per_beam));

    // read the rest of the datagram
    is.read(reinterpret_cast<char*>(&(datagram._spare_byte)), 4 * sizeof(uint8_t));

    if (datagram._etx != 0x03)
        throw std::runtime_error(fmt::format(
            "SeabedImageData: end identifier is not 0x03, but 0x{:x}", datagram._etx));

    return datagram;
}

SeabedImageData SeabedImageData::from_stream(std::istream& is)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is));
}

SeabedImageData SeabedImageData::from_stream(std::istream&                    is,
                                   t_KongsbergAllDatagramIdentifier datagram_identifier)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is, datagram_identifier));
}

void SeabedImageData::to_stream(std::ostream& os)
{
    KongsbergAllDatagram::to_stream(os);
    _number_of_valid_beams = _beams.size();

    // write first part of the datagram (until the first beam)
    os.write(reinterpret_cast<const char*>(&(_ping_counter)), 20 * sizeof(uint8_t));

    // write the beams
    os.write(reinterpret_cast<const char*>(_beams.data()),
             _number_of_valid_beams * sizeof(substructures::SeabedImageDataBeam));

    // write the sample amplitudes
    _sample_amplitudes.to_stream(os);
    // _sample_amplitudes.resize(_number_of_valid_beams);
    // for (uint b = 0; b < _number_of_valid_beams; ++b)
    // {
    //     _sample_amplitudes[b].resize(_beams[b].get_number_of_samples());
    //     os.write(reinterpret_cast<const char*>(_sample_amplitudes[b].data()),
    //              _beams[b].get_number_of_samples() * sizeof(int16_t));
    // }

    // write the rest of the datagram
    os.write(reinterpret_cast<const char*>(&(_spare_byte)), 4 * sizeof(uint8_t));
}

tools::classhelper::ObjectPrinter SeabedImageData::__printer__(unsigned int float_precision,
                                              bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "SeabedImageData", float_precision, superscript_exponents);

    printer.append(KongsbergAllDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("datagram content");
    printer.register_value("ping_counter", _ping_counter);
    printer.register_value("system_serial_number", _system_serial_number);
    printer.register_value("sampling_frequency", _sampling_frequency, "Hz");
    printer.register_value("range_to_normal_incidence", _range_to_normal_incidence);
    printer.register_value(
        "normal_incidence_backscatter", _normal_incidence_backscatter, "0.01 dB");
    printer.register_value("oblique_backscatter", _oblique_backscatter, "0.01 dB");
    printer.register_value("tx_beamwidth_along", _tx_beamwidth_along, "0.1°");
    printer.register_value("tvg_law_crossover_angle", _tvg_law_crossover_angle, "0.1°");
    printer.register_value("number_of_valid_beams", _number_of_valid_beams);
    printer.register_value("spare_byte", _spare_byte);
    printer.register_string("etx", fmt::format("0x{:02x}", _etx));
    printer.register_value("checksum", _checksum);

    printer.register_section("processed");
    printer.register_value(
        "normal_incidence_backscatter", get_normal_incidence_backscatter_in_db(), "dB");
    printer.register_value("oblique_backscatter", get_oblique_backscatter_in_db(), "dB");
    printer.register_value("tx_beamwidth_along", get_tx_beamwidth_along_in_degrees(), "°");
    printer.register_value(
        "tvg_law_crossover_angle", get_tvg_law_crossover_angle_in_degrees(), "°");

    printer.register_section("substructures");
    printer.register_value("beams", _beams.size(), "SeabedImageDataBeams");
    printer.register_value(
        "sample_amplitudes", _sample_amplitudes.size(), "SampleAmplitudesStructure");

    return printer;
}

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
