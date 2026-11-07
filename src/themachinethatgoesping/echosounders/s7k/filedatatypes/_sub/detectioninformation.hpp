// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/detectioninformation.doc.hpp"

/* std includes */
#include <cstdint>
#include <string>
#include <unordered_map>

/* boost includes */
#include <boost/flyweight.hpp>

// xtensor includes
#include <xtensor/containers/xtensor.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/helper/xtensor_hash.hpp>

#include "../../datagrams/rawdetection.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace filedatatypes {
namespace _sub {

/**
 * @brief Lightweight bottom-detection information of a single s7k ping (7027 RawDetectionData).
 *
 * The 7027 record may hold several detections per beam (multi-detect). This structure reduces it to
 * one value per beam number (the first detection of each beam) for the two quantities the ping
 * interfaces need - the receive steering angle and the detected bottom sample - plus the two
 * record-wide scalars (sample rate and transmit angle). The full record is therefore not retained.
 *
 * The receive angles (fixed by the beamformer geometry, identical across pings of the same mode)
 * are deduplicated with a flyweight; the detection points are unique per ping.
 *
 * Note this is a private substructure and thus not part of the public API or nanobind interface.
 */
class DetectionInformation
{
    // deduplicated (receive geometry is constant across pings of the same mode)
    boost::flyweights::flyweight<xt::xtensor<float, 1>> _rx_angle_in_degrees_per_beam_number;

    // unique per ping
    xt::xtensor<float, 1> _detection_point_per_beam_number;

    float _sampling_rate       = 0.f; ///< sample rate of the detections (Hz)
    float _tx_angle_in_degrees = 0.f; ///< transmit steering angle (degrees)

    DetectionInformation() = default; // for from_stream

  public:
    explicit DetectionInformation(const datagrams::RawDetection& raw_detection);

    bool operator==(const DetectionInformation& other) const = default;

    // ----- accessors -----
    /// receive steering angle (degrees) per beam number, nudged strictly increasing (see ctor)
    const xt::xtensor<float, 1>& get_rx_angle_in_degrees_per_beam_number() const
    {
        return _rx_angle_in_degrees_per_beam_number.get();
    }
    /// detected bottom sample number (fractional) per beam number
    const xt::xtensor<float, 1>& get_detection_point_per_beam_number() const
    {
        return _detection_point_per_beam_number;
    }

    size_t get_number_of_beams() const
    {
        return _rx_angle_in_degrees_per_beam_number.get().size();
    }
    float get_sampling_rate() const { return _sampling_rate; }
    float get_tx_angle_in_degrees() const { return _tx_angle_in_degrees; }

    // ----- functions used for PackageCache -----
    void to_stream(std::ostream& os, std::unordered_map<size_t, std::string>& hash_cache) const;

    static DetectionInformation from_stream(
        std::istream&                                  is,
        const std::unordered_map<size_t, std::string>& hash_cache);
};

} // namespace _sub
} // namespace filedatatypes
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
