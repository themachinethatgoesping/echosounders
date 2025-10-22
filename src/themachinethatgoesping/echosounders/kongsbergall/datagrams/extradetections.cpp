// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "extradetections.hpp"

// std includes
#include <iostream>
#include <stdexcept>
#include <utility>

// external includes
#include <fmt/format.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

ExtraDetections::ExtraDetections(KongsbergAllDatagram header)
    : KongsbergAllDatagram(std::move(header))
{
}

ExtraDetections::ExtraDetections()
{
    _datagram_identifier = t_KongsbergAllDatagramIdentifier::ExtraDetections;
}

uint16_t ExtraDetections::get_ping_counter() const
{
    return _ping_counter;
}

uint16_t ExtraDetections::get_system_serial_number() const
{
    return _system_serial_number;
}

uint16_t ExtraDetections::get_datagram_counter() const
{
    return _datagram_counter;
}

uint16_t ExtraDetections::get_datagram_version_id() const
{
    return _datagram_version_id;
}

uint16_t ExtraDetections::get_swath_counter() const
{
    return _swath_counter;
}

uint16_t ExtraDetections::get_swath_index() const
{
    return _swath_index;
}

uint16_t ExtraDetections::get_heading() const
{
    return _heading;
}

uint16_t ExtraDetections::get_sound_speed() const
{
    return _sound_speed;
}

float ExtraDetections::get_depth_of_reference_point() const
{
    return _depth_of_reference_point;
}

float ExtraDetections::get_water_column_sample_rate() const
{
    return _water_column_sample_rate;
}

float ExtraDetections::get_raw_amplitude_sample_rate() const
{
    return _raw_amplitude_sample_rate;
}

uint16_t ExtraDetections::get_rx_transducer_index() const
{
    return _rx_transducer_index;
}

uint16_t ExtraDetections::get_number_of_extra_detections() const
{
    return _number_of_extra_detections;
}

uint16_t ExtraDetections::get_number_of_detection_classes() const
{
    return _number_of_detection_classes;
}

uint16_t ExtraDetections::get_number_of_bytes_per_class() const
{
    return _number_of_bytes_per_class;
}

uint16_t ExtraDetections::get_number_of_alarm_flags() const
{
    return _number_of_alarm_flags;
}

uint16_t ExtraDetections::get_number_of_bytes_per_detection() const
{
    return _number_of_bytes_per_detection;
}

const std::vector<substructures::ExtraDetectionsDetectionClasses>&
ExtraDetections::get_detection_classes() const
{
    return _detection_classes;
}

const std::vector<substructures::ExtraDetectionsExtraDetections>&
ExtraDetections::get_extra_detections() const
{
    return _extra_detections;
}

const substructures::SampleAmplitudesStructure<int16_t>&
ExtraDetections::get_raw_amplitude_samples() const
{
    return _raw_amplitude_samples;
}

uint16_t ExtraDetections::get_spare() const
{
    return _spare;
}

uint8_t ExtraDetections::get_etx() const
{
    return _etx;
}

uint16_t ExtraDetections::get_checksum() const
{
    return _checksum;
}

void ExtraDetections::set_ping_counter(uint16_t ping_counter)
{
    _ping_counter = ping_counter;
}

void ExtraDetections::set_system_serial_number(uint16_t system_serial_number)
{
    _system_serial_number = system_serial_number;
}

void ExtraDetections::set_datagram_counter(uint16_t datagram_counter)
{
    _datagram_counter = datagram_counter;
}

void ExtraDetections::set_datagram_version_id(uint16_t datagram_version_id)
{
    _datagram_version_id = datagram_version_id;
}

void ExtraDetections::set_swath_counter(uint16_t swath_counter)
{
    _swath_counter = swath_counter;
}

void ExtraDetections::set_swath_index(uint16_t swath_index)
{
    _swath_index = swath_index;
}

void ExtraDetections::set_heading(uint16_t heading)
{
    _heading = heading;
}

void ExtraDetections::set_sound_speed(uint16_t sound_speed)
{
    _sound_speed = sound_speed;
}

void ExtraDetections::set_depth_of_reference_point(float depth_of_reference_point)
{
    _depth_of_reference_point = depth_of_reference_point;
}

void ExtraDetections::set_water_column_sample_rate(float water_column_sample_rate)
{
    _water_column_sample_rate = water_column_sample_rate;
}

void ExtraDetections::set_raw_amplitude_sample_rate(float raw_amplitude_sample_rate)
{
    _raw_amplitude_sample_rate = raw_amplitude_sample_rate;
}

void ExtraDetections::set_rx_transducer_index(uint16_t rx_transducer_index)
{
    _rx_transducer_index = rx_transducer_index;
}

void ExtraDetections::set_number_of_extra_detections(uint16_t number_of_extra_detections)
{
    _number_of_extra_detections = number_of_extra_detections;
}

void ExtraDetections::set_number_of_detection_classes(uint16_t number_of_detection_classes)
{
    _number_of_detection_classes = number_of_detection_classes;
}

void ExtraDetections::set_number_of_bytes_per_class(uint16_t number_of_bytes_per_class)
{
    _number_of_bytes_per_class = number_of_bytes_per_class;
}

void ExtraDetections::set_number_of_alarm_flags(uint16_t number_of_alarm_flags)
{
    _number_of_alarm_flags = number_of_alarm_flags;
}

void ExtraDetections::set_number_of_bytes_per_detection(uint16_t number_of_bytes_per_detection)
{
    _number_of_bytes_per_detection = number_of_bytes_per_detection;
}

void ExtraDetections::set_detection_classes(
    const std::vector<substructures::ExtraDetectionsDetectionClasses>& detection_classes)
{
    _detection_classes = detection_classes;
}

void ExtraDetections::set_extra_detections(
    const std::vector<substructures::ExtraDetectionsExtraDetections>& extra_detections)
{
    _extra_detections = extra_detections;
}

void ExtraDetections::set_raw_amplitude_samples(
    const substructures::SampleAmplitudesStructure<int16_t>& raw_amplitude_samples)
{
    _raw_amplitude_samples = raw_amplitude_samples;
}

void ExtraDetections::set_spare(uint16_t spare_bytes)
{
    _spare = static_cast<uint8_t>(spare_bytes);
}

void ExtraDetections::set_etx(uint8_t etx)
{
    _etx = etx;
}

void ExtraDetections::set_checksum(uint16_t checksum)
{
    _checksum = checksum;
}

std::vector<substructures::ExtraDetectionsDetectionClasses>& ExtraDetections::detection_classes()
{
    return _detection_classes;
}

std::vector<substructures::ExtraDetectionsExtraDetections>& ExtraDetections::extra_detections()
{
    return _extra_detections;
}

substructures::SampleAmplitudesStructure<int16_t>& ExtraDetections::raw_amplitude_samples()
{
    return _raw_amplitude_samples;
}

double ExtraDetections::get_heading_in_degrees() const
{
    return static_cast<double>(_heading) * 0.01;
}

double ExtraDetections::get_sound_speed_in_m_per_s() const
{
    return static_cast<double>(_sound_speed) * 0.1;
}

// ----- operators -----
bool ExtraDetections::operator==(const ExtraDetections& other) const
{
    return KongsbergAllDatagram::operator==(other) && _ping_counter == other._ping_counter &&
           _system_serial_number == other._system_serial_number &&
           _datagram_counter == other._datagram_counter &&
           _datagram_version_id == other._datagram_version_id &&
           _swath_counter == other._swath_counter && _swath_index == other._swath_index &&
           _heading == other._heading && _sound_speed == other._sound_speed &&
           tools::helper::float_equals(_depth_of_reference_point,
                                       other._depth_of_reference_point) &&
           tools::helper::float_equals(_water_column_sample_rate,
                                       other._water_column_sample_rate) &&
           tools::helper::float_equals(_raw_amplitude_sample_rate,
                                       other._raw_amplitude_sample_rate) &&
           _rx_transducer_index == other._rx_transducer_index &&
           _number_of_extra_detections == other._number_of_extra_detections &&
           _number_of_detection_classes == other._number_of_detection_classes &&
           _number_of_bytes_per_class == other._number_of_bytes_per_class &&
           _number_of_alarm_flags == other._number_of_alarm_flags &&
           _number_of_bytes_per_detection == other._number_of_bytes_per_detection &&
           _detection_classes == other._detection_classes &&
           _extra_detections == other._extra_detections &&
           _raw_amplitude_samples == other._raw_amplitude_samples && _spare == other._spare &&
           _etx == other._etx && _checksum == other._checksum;
}

//----- to/from stream functions -----
ExtraDetections ExtraDetections::from_stream(std::istream& is, KongsbergAllDatagram header)
{
    ExtraDetections datagram(std::move(header));

    if (datagram._datagram_identifier != t_KongsbergAllDatagramIdentifier::ExtraDetections)
        throw std::runtime_error(
            fmt::format("ExtraDetections: datagram identifier is not 0x{:02x}, but 0x{:02x}",
                        uint8_t(t_KongsbergAllDatagramIdentifier::ExtraDetections),
                        uint8_t(datagram._datagram_identifier)));

    // read first part of the datagram (until the first beam)
    is.read(reinterpret_cast<char*>(&(datagram._ping_counter)), 40 * sizeof(uint8_t));

    // read detection classes
    datagram._detection_classes.resize(datagram._number_of_detection_classes);
    is.read(reinterpret_cast<char*>(datagram._detection_classes.data()),
            datagram._number_of_detection_classes *
                sizeof(substructures::ExtraDetectionsDetectionClasses));

    // read extra detections
    datagram._extra_detections.resize(datagram._number_of_extra_detections);
    is.read(reinterpret_cast<char*>(datagram._extra_detections.data()),
            datagram._number_of_extra_detections *
                sizeof(substructures::ExtraDetectionsExtraDetections));

    // read raw amplitude samples
    uint16_t              total_samples = 0;
    std::vector<uint16_t> samples_per_beam;
    std::vector<uint16_t> start_index_per_beam;
    samples_per_beam.reserve(datagram._number_of_extra_detections);

    for (const auto& beam : datagram._extra_detections)
    {
        start_index_per_beam.push_back(total_samples);
        samples_per_beam.push_back(beam.get_number_of_raw_amplitude_samples());
        total_samples += samples_per_beam.back();
    }

    datagram._raw_amplitude_samples =
        substructures::SampleAmplitudesStructure<int16_t>::from_stream(
            is, total_samples, std::move(start_index_per_beam), std::move(samples_per_beam));

    // read the rest of the datagram
    is.read(reinterpret_cast<char*>(&(datagram._spare)), 4 * sizeof(uint8_t));

    return datagram;
}

ExtraDetections ExtraDetections::from_stream(std::istream& is)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is));
}

ExtraDetections ExtraDetections::from_stream(std::istream&                    is,
                                           t_KongsbergAllDatagramIdentifier datagram_identifier)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is, datagram_identifier));
}

void ExtraDetections::to_stream(std::ostream& os)
{
    KongsbergAllDatagram::to_stream(os);
    _number_of_detection_classes = _detection_classes.size();
    _number_of_extra_detections  = _extra_detections.size();

    // write first part of the datagram (until the first beam)
    os.write(reinterpret_cast<const char*>(&(_ping_counter)), 40 * sizeof(uint8_t));

    // write the detection classes
    os.write(reinterpret_cast<const char*>(_detection_classes.data()),
             _number_of_detection_classes *
                 sizeof(substructures::ExtraDetectionsDetectionClasses));

    // write the extra detections
    os.write(reinterpret_cast<const char*>(_extra_detections.data()),
             _number_of_extra_detections *
                 sizeof(substructures::ExtraDetectionsExtraDetections));

    // write the raw amplitude samples
    _raw_amplitude_samples.to_stream(os);

    // write the rest of the datagram
    os.write(reinterpret_cast<const char*>(&(_spare)), 4 * sizeof(uint8_t));
}

// ----- objectprinter -----
tools::classhelper::ObjectPrinter ExtraDetections::__printer__(unsigned int float_precision,
                                                               bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer("ExtraDetections", float_precision, superscript_exponents);

    printer.append(KongsbergAllDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("datagram content");
    printer.register_value("ping_counter", _ping_counter);
    printer.register_value("system_serial_number", _system_serial_number);
    printer.register_value("datagram_counter", _datagram_counter);
    printer.register_value("datagram_version_id", _datagram_version_id);
    printer.register_value("swath_counter", _swath_counter);
    printer.register_value("swath_index", _swath_index);
    printer.register_value("heading", _heading, "0.01° steps");
    printer.register_value("sound_speed", _sound_speed, "0.1 m/s steps");
    printer.register_value("depth_of_reference_point", _depth_of_reference_point, "m");
    printer.register_value("water_column_sample_rate", _water_column_sample_rate, "(WCsr)");
    printer.register_value("raw_amplitude_sample_rate", _raw_amplitude_sample_rate, "(SIsr)");
    printer.register_value("rx_transducer_index", _rx_transducer_index);
    printer.register_value("number_of_extra_detections", _number_of_extra_detections);
    printer.register_value("number_of_detection_classes", _number_of_detection_classes);
    printer.register_value("number_of_bytes_per_class", _number_of_bytes_per_class);
    printer.register_value("number_of_alarm_flags", _number_of_alarm_flags);
    printer.register_value("number_of_bytes_per_detection", _number_of_bytes_per_detection);
    printer.register_string("spare_bytes", fmt::format("0x{:02x}", _spare));
    printer.register_string("etx", fmt::format("0x{:02x}", _etx));
    printer.register_value("checksum", _checksum);

    printer.register_section("processed");
    printer.register_value("heading", get_heading_in_degrees(), "°");
    printer.register_value("sound_speed", get_sound_speed_in_m_per_s(), "m/s");

    printer.register_section("substructures");
    printer.register_value(
        "detection_classes", _detection_classes.size(), "ExtraDetectionsDetectionClasses");
    printer.register_value(
        "extra_detections", _extra_detections.size(), "ExtraDetectionsExtraDetections");
    printer.register_value(
        "raw_amplitude_samples", _raw_amplitude_samples.size(), "SampleAmplitudesStructure");

    return printer;
}

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
