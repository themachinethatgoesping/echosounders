// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "extradetections.hpp"

#include <fmt/core.h>
#include <stdexcept>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

ExtraDetections ExtraDetections::from_stream(std::istream& is, KongsbergAllDatagram header)
{
    ExtraDetections datagram(std::move(header));

    // auto pos = is.tellg();

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
    // is.read(reinterpret_cast<char*>(&(datagram._spare)), 5 * sizeof(uint8_t));
    is.read(reinterpret_cast<char*>(&(datagram._spare)), 4 * sizeof(uint8_t));

    // TODO: fix reading raw_amplitudes
    // if (datagram._etx != 0x03)
    // {
    //     auto pos_is = is.tellg();
    //     auto pos_should = pos + signed(datagram.get_bytes()) - 15;
    //     throw std::runtime_error(fmt::format(
    //         "ExtraDetections: end identifier is not 0x03, but 0x{:x}"
    //         "Position is {} bytes to far", datagram._etx, pos_is - pos_should));
    // }

    return datagram;
}

ExtraDetections ExtraDetections::from_stream(std::istream& is)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is));
}

ExtraDetections ExtraDetections::from_stream(std::istream& is, t_KongsbergAllDatagramIdentifier datagram_identifier)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is, datagram_identifier));
}

void ExtraDetections::to_stream(std::ostream& os) const
{
    KongsbergAllDatagram::to_stream(os);
    
    // Create modifiable copies for size updates
    auto number_of_detection_classes = static_cast<uint16_t>(_detection_classes.size());
    auto number_of_extra_detections = static_cast<uint16_t>(_extra_detections.size());

    // write first part of the datagram (until the first beam)
    os.write(reinterpret_cast<const char*>(&(_ping_counter)), 16 * sizeof(uint8_t));
    os.write(reinterpret_cast<const char*>(&number_of_detection_classes), sizeof(uint16_t));
    os.write(reinterpret_cast<const char*>(&number_of_extra_detections), sizeof(uint16_t));
    os.write(reinterpret_cast<const char*>(&(_ping_counter)) + 20, 20 * sizeof(uint8_t));

    // write the detection classes
    os.write(reinterpret_cast<const char*>(_detection_classes.data()),
             number_of_detection_classes *
                 sizeof(substructures::ExtraDetectionsDetectionClasses));

    // write the extra detections
    os.write(reinterpret_cast<const char*>(_extra_detections.data()),
             number_of_extra_detections *
                 sizeof(substructures::ExtraDetectionsExtraDetections));

    // write the raw amplitude samples
    _raw_amplitude_samples.to_stream(os);

    // write the rest of the datagram
    os.write(reinterpret_cast<const char*>(&(_spare)), 4 * sizeof(uint8_t));
}

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
