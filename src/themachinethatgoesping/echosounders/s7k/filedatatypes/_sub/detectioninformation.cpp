// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "detectioninformation.hpp"

#include <algorithm>
#include <array>
#include <cmath>
#include <cstring>
#include <limits>
#include <ostream>

#include <xxhash.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace filedatatypes {
namespace _sub {

DetectionInformation::DetectionInformation(const datagrams::RawDetection& raw_detection)
{
    const auto& detection_beams  = raw_detection.get_beams();
    const auto  descriptors      = detection_beams.get_beam_descriptor_tensor();
    const auto  rx_angles        = detection_beams.get_rx_angle_in_degrees_tensor();
    const auto  detection_points = detection_beams.get_detection_point_tensor();

    uint16_t max_beam_number = 0;
    for (size_t row = 0; row < descriptors.size(); ++row)
        max_beam_number = std::max<uint16_t>(max_beam_number, descriptors.unchecked(row));

    const size_t nbeams = descriptors.size() == 0 ? 0 : size_t(max_beam_number) + 1;

    auto rx_angle_per_beam_number        = xt::xtensor<float, 1>::from_shape({ nbeams });
    auto detection_point_per_beam_number = xt::xtensor<float, 1>::from_shape({ nbeams });
    rx_angle_per_beam_number.fill(std::numeric_limits<float>::quiet_NaN());
    detection_point_per_beam_number.fill(std::numeric_limits<float>::quiet_NaN());

    // reduce the (possibly multi-detect) rows to the first detection of each beam number
    for (size_t row = 0; row < descriptors.size(); ++row)
    {
        const auto bn = descriptors.unchecked(row);
        if (std::isnan(rx_angle_per_beam_number.unchecked(bn)))
            rx_angle_per_beam_number.unchecked(bn) = rx_angles.unchecked(row);
        if (std::isnan(detection_point_per_beam_number.unchecked(bn)))
            detection_point_per_beam_number.unchecked(bn) = detection_points.unchecked(row);
    }

    // the recorded receive angles are quantized and repeat for adjacent (outer) beams; nudge the
    // duplicates so the per-beam angles are strictly increasing (the water-column image
    // interpolator requires strictly ascending beam angles). The drift is < 0.1 deg.
    constexpr float epsilon = 1e-3f;
    for (size_t bn = 1; bn < rx_angle_per_beam_number.size(); ++bn)
        if (std::isfinite(rx_angle_per_beam_number.unchecked(bn)) &&
            std::isfinite(rx_angle_per_beam_number.unchecked(bn - 1)) &&
            rx_angle_per_beam_number.unchecked(bn) <= rx_angle_per_beam_number.unchecked(bn - 1))
            rx_angle_per_beam_number.unchecked(bn) =
                rx_angle_per_beam_number.unchecked(bn - 1) + epsilon;

    _rx_angle_in_degrees_per_beam_number = std::move(rx_angle_per_beam_number);
    _detection_point_per_beam_number     = std::move(detection_point_per_beam_number);
    _sampling_rate                       = raw_detection.get_sampling_rate();
    _tx_angle_in_degrees                 = raw_detection.get_tx_angle_in_degrees();
}

void DetectionInformation::to_stream(std::ostream&                            os,
                                     std::unordered_map<size_t, std::string>& hash_cache) const
{
    const auto& rx_angle = _rx_angle_in_degrees_per_beam_number.get();

    std::vector<size_t> hashes; // rx_angle_in_degrees_per_beam_number
    std::vector<size_t> sizes;  // rx_angle..., detection_point_per_beam_number
    hashes.reserve(1);
    sizes.reserve(2);

    // hashes[0], sizes[0]: receive angles (deduplicated)
    hashes.push_back(xxh::xxhash3<64>(rx_angle.data(), rx_angle.size() * sizeof(float)));
    sizes.push_back(rx_angle.size());
    if (!hash_cache.contains(hashes.back()))
    {
        auto& buffer = hash_cache[hashes.back()];
        buffer.resize(rx_angle.size() * sizeof(float));
        std::memcpy(buffer.data(), rx_angle.data(), rx_angle.size() * sizeof(float));
    }

    // sizes[1]: detection points (written directly, unique per ping)
    sizes.push_back(_detection_point_per_beam_number.size());

    os.write(reinterpret_cast<const char*>(hashes.data()), hashes.size() * sizeof(size_t));
    os.write(reinterpret_cast<const char*>(sizes.data()), sizes.size() * sizeof(size_t));

    os.write(reinterpret_cast<const char*>(_detection_point_per_beam_number.data()),
             _detection_point_per_beam_number.size() * sizeof(float));

    os.write(reinterpret_cast<const char*>(&_sampling_rate), sizeof(float));
    os.write(reinterpret_cast<const char*>(&_tx_angle_in_degrees), sizeof(float));
}

DetectionInformation DetectionInformation::from_stream(
    std::istream&                                  is,
    const std::unordered_map<size_t, std::string>& hash_cache)
{
    DetectionInformation dat;

    std::array<size_t, 1> hashes; // rx_angle_in_degrees_per_beam_number
    std::array<size_t, 2> sizes;  // rx_angle..., detection_point_per_beam_number

    is.read(reinterpret_cast<char*>(hashes.data()), hashes.size() * sizeof(size_t));
    is.read(reinterpret_cast<char*>(sizes.data()), sizes.size() * sizeof(size_t));

    // detection points (unique per ping)
    dat._detection_point_per_beam_number = xt::xtensor<float, 1>::from_shape({ sizes[1] });
    is.read(reinterpret_cast<char*>(dat._detection_point_per_beam_number.data()),
            dat._detection_point_per_beam_number.size() * sizeof(float));

    is.read(reinterpret_cast<char*>(&dat._sampling_rate), sizeof(float));
    is.read(reinterpret_cast<char*>(&dat._tx_angle_in_degrees), sizeof(float));

    static thread_local std::unordered_map<size_t,
                                           boost::flyweights::flyweight<xt::xtensor<float, 1>>>
        fw_cache_float;

    // rx_angle_in_degrees_per_beam_number (hashes[0])
    if (auto it = fw_cache_float.find(hashes[0]); it != fw_cache_float.end())
    {
        dat._rx_angle_in_degrees_per_beam_number = it->second;
    }
    else
    {
        auto rx_angle = xt::xtensor<float, 1>::from_shape({ sizes[0] });
        std::memcpy(
            rx_angle.data(), hash_cache.at(hashes[0]).data(), rx_angle.size() * sizeof(float));
        dat._rx_angle_in_degrees_per_beam_number = std::move(rx_angle);
        fw_cache_float.emplace(hashes[0], dat._rx_angle_in_degrees_per_beam_number);
    }

    return dat;
}

} // namespace _sub
} // namespace filedatatypes
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
