// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "extradetections.hpp"

// std includes
#include <iostream>

// external includes
#include <fmt/format.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

// Implementation file for extradetections.hpp
// TODO: Move appropriate implementations from header to this file

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
