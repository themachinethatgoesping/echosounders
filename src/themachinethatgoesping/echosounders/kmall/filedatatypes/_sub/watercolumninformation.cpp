// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "watercolumninformation.hpp"

#include <array>
#include <cstring>

#include <xxhash.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace filedatatypes {
namespace _sub {

WaterColumnInformation::WaterColumnInformation(const datagrams::MWaterColumn& water_column_datagram)
{
    auto nbeams = water_column_datagram.get_beam_data().get_number_of_beams();

    // initialize arrays using from shape function
    auto beam_crosstrack_angles     = xt::xtensor<float, 1>::from_shape({ nbeams });
    auto start_range_sample_numbers = xt::xtensor<uint16_t, 1>::from_shape({ nbeams });
    auto number_of_samples_per_beam = xt::xtensor<uint16_t, 1>::from_shape({ nbeams });
    auto detected_range_in_samples  = xt::xtensor<uint16_t, 1>::from_shape({ nbeams });
    auto detected_range_in_samples_high_resolution = xt::xtensor<float, 1>::from_shape({ nbeams });
    auto transmit_sector_numbers = xt::xtensor<uint8_t, 1>::from_shape({ nbeams });
    auto sample_positions        = xt::xtensor<size_t, 1>::from_shape({ nbeams });

    size_t bn = 0;
    for (const auto& b : water_column_datagram.get_beam_data().get_beams())
    {
        sample_positions.unchecked(bn) = b.get_sample_position();

        beam_crosstrack_angles.unchecked(bn)    = b.get_beam_pointing_angle_re_vertical_deg();
        detected_range_in_samples.unchecked(bn) = b.get_detected_range_in_samples();
        detected_range_in_samples_high_resolution.unchecked(bn) =
            b.get_detected_range_in_samples_high_resolution();
        start_range_sample_numbers.unchecked(bn) = b.get_start_range_sample_number();
        number_of_samples_per_beam.unchecked(bn) = b.get_number_of_samples();
        transmit_sector_numbers.unchecked(bn)    = b.get_transmit_sector_number();

        ++bn;
    }

    _sample_positions           = std::move(sample_positions);
    _beam_crosstrack_angles     = std::move(beam_crosstrack_angles);
    _start_range_sample_numbers = std::move(start_range_sample_numbers);
    _number_of_samples_per_beam = std::move(number_of_samples_per_beam);
    _detected_range_in_samples  = std::move(detected_range_in_samples);
    _detected_range_in_samples_high_resolution =
        std::move(detected_range_in_samples_high_resolution);
    _transmit_sector_numbers = std::move(transmit_sector_numbers);

    _wci_infos = _WCIInfos(water_column_datagram);
}

void WaterColumnInformation::to_stream(std::ostream&                            os,
                                       std::unordered_map<size_t, std::string>& hash_cache) const
{
    std::string         buffer;
    std::vector<size_t> hashes, sizes;
    hashes.reserve(5); // _beam_crosstrack_angles, _start_range_sample_numbers,
                       // _number_of_samples_per_beam, _transmit_sector_numbers, _wci_infos
    sizes.reserve(7);  // _beam_crosstrack_angles, _start_range_sample_numbers,
                       // _number_of_samples_per_beam, _detected_range_in_samples,
                       // _detected_range_in_samples_high_resolution, _transmit_sector_numbers,
                       // _sample_positions

    // hashes[0], sizes[0]: _beam_crosstrack_angles
    hashes.push_back(xxh::xxhash3<64>(_beam_crosstrack_angles.get().data(),
                                      _beam_crosstrack_angles.get().size() * sizeof(float)));
    sizes.push_back(_beam_crosstrack_angles.get().size());

    if (!hash_cache.contains(hashes.back()))
    {
        auto& buffer = hash_cache[hashes.back()];
        buffer.resize(_beam_crosstrack_angles.get().size() * sizeof(float));

        std::memcpy(buffer.data(),
                    _beam_crosstrack_angles.get().data(),
                    _beam_crosstrack_angles.get().size() * sizeof(float));
    }

    // hashes[1], sizes[1]: _start_range_sample_numbers
    hashes.push_back(xxh::xxhash3<64>(_start_range_sample_numbers.get().data(),
                                      _start_range_sample_numbers.get().size() * sizeof(uint16_t)));
    sizes.push_back(_start_range_sample_numbers.get().size());

    if (!hash_cache.contains(hashes.back()))
    {
        auto& buffer = hash_cache[hashes.back()];
        buffer.resize(_start_range_sample_numbers.get().size() * sizeof(uint16_t));

        std::memcpy(hash_cache[hashes.back()].data(),
                    _start_range_sample_numbers.get().data(),
                    _start_range_sample_numbers.get().size() * sizeof(uint16_t));
    }

    // hashes[2], sizes[2]: _number_of_samples_per_beam
    hashes.push_back(xxh::xxhash3<64>(_number_of_samples_per_beam.get().data(),
                                      _number_of_samples_per_beam.get().size() * sizeof(uint16_t)));
    sizes.push_back(_number_of_samples_per_beam.get().size());

    if (!hash_cache.contains(hashes.back()))
    {
        auto& buffer = hash_cache[hashes.back()];
        buffer.resize(_number_of_samples_per_beam.get().size() * sizeof(uint16_t));

        std::memcpy(hash_cache[hashes.back()].data(),
                    _number_of_samples_per_beam.get().data(),
                    _number_of_samples_per_beam.get().size() * sizeof(uint16_t));
    }

    // sizes[3], sizes[4]: _detected_range_in_samples (written directly to stream, not hashed)
    sizes.push_back(_detected_range_in_samples.size());
    sizes.push_back(_detected_range_in_samples_high_resolution.size());

    // hashes[3], sizes[5]: _transmit_sector_numbers
    hashes.push_back(xxh::xxhash3<64>(_transmit_sector_numbers.get().data(),
                                      _transmit_sector_numbers.get().size() * sizeof(uint8_t)));
    sizes.push_back(_transmit_sector_numbers.get().size());

    if (!hash_cache.contains(hashes.back()))
    {
        auto& buffer = hash_cache[hashes.back()];
        buffer.resize(_transmit_sector_numbers.get().size() * sizeof(uint8_t));

        std::memcpy(hash_cache[hashes.back()].data(),
                    _transmit_sector_numbers.get().data(),
                    _transmit_sector_numbers.get().size() * sizeof(uint8_t));
    }

    // sizes[6]: _sample_positions (written directly to stream, not hashed)
    sizes.push_back(_sample_positions.size());

    // hashes[4]: _wci_infos
    hashes.push_back(hash_value(_wci_infos.get()));

    if (!hash_cache.contains(hashes.back()))
    {
        hash_cache[hashes.back()] = _wci_infos.get().to_binary();
    }

    // write hashes to stream
    os.write(reinterpret_cast<const char*>(hashes.data()), hashes.size() * sizeof(size_t));
    os.write(reinterpret_cast<const char*>(sizes.data()), sizes.size() * sizeof(size_t));

    // write detected_range_in_samples to stream
    os.write(reinterpret_cast<const char*>(_detected_range_in_samples.data()),
             _detected_range_in_samples.size() * sizeof(uint16_t));
    os.write(reinterpret_cast<const char*>(_detected_range_in_samples_high_resolution.data()),
             _detected_range_in_samples_high_resolution.size() * sizeof(float));

    // write sample_positions to stream
    os.write(reinterpret_cast<const char*>(_sample_positions.data()),
             _sample_positions.size() * sizeof(size_t));
}

WaterColumnInformation WaterColumnInformation::from_stream(
    std::istream&                                  is,
    const std::unordered_map<size_t, std::string>& hash_cache)
{
    // create WaterColumnInformation
    WaterColumnInformation dat;

    std::array<size_t, 5> hashes; // _beam_crosstrack_angles, _start_range_sample_numbers,
                                   // _number_of_samples_per_beam, _transmit_sector_numbers,
                                   // _wci_infos
    std::array<size_t, 7> sizes;   // _beam_crosstrack_angles, _start_range_sample_numbers,
                                   // _number_of_samples_per_beam, _detected_range_in_samples,
                                   // _detected_range_in_samples_high_resolution,
                                   // _transmit_sector_numbers, _sample_positions

    // read hashes and sizes from stream
    is.read(reinterpret_cast<char*>(hashes.data()), hashes.size() * sizeof(size_t));
    is.read(reinterpret_cast<char*>(sizes.data()), sizes.size() * sizeof(size_t));

    // resize arrays using correct size indices
    // sizes[0] = _beam_crosstrack_angles
    // sizes[1] = _start_range_sample_numbers
    // sizes[2] = _number_of_samples_per_beam
    // sizes[3] = _detected_range_in_samples
    // sizes[4] = _detected_range_in_samples_high_resolution
    // sizes[5] = _transmit_sector_numbers
    // sizes[6] = _sample_positions

    // Per-ping data (unique per ping, always read from stream)
    dat._detected_range_in_samples = xt::xtensor<uint16_t, 1>::from_shape({ sizes[3] });
    dat._detected_range_in_samples_high_resolution =
        xt::xtensor<float, 1>::from_shape({ sizes[4] });
    dat._sample_positions = xt::xtensor<size_t, 1>::from_shape({ sizes[6] });

    // read detected_range_in_samples from stream
    is.read(reinterpret_cast<char*>(dat._detected_range_in_samples.data()),
            dat._detected_range_in_samples.size() * sizeof(uint16_t));
    is.read(reinterpret_cast<char*>(dat._detected_range_in_samples_high_resolution.data()),
            dat._detected_range_in_samples_high_resolution.size() * sizeof(float));

    // read sample_positions from stream
    is.read(reinterpret_cast<char*>(dat._sample_positions.data()),
            dat._sample_positions.size() * sizeof(size_t));

    // Flyweight cache: reuse previously constructed flyweights by xxhash key.
    // For repeated beam configurations (the common case), this avoids:
    //   - xtensor heap allocation
    //   - memcpy from hash_cache
    //   - boost::hash computation over full array
    //   - flyweight factory set lookup + potential discard
    // Cost is just an unordered_map lookup (size_t key) + flyweight copy (refcount increment).
    static thread_local std::unordered_map<size_t,
                                           boost::flyweights::flyweight<xt::xtensor<float, 1>>>
        fw_cache_float;
    static thread_local std::unordered_map<size_t,
                                           boost::flyweights::flyweight<xt::xtensor<uint16_t, 1>>>
        fw_cache_uint16;
    static thread_local std::unordered_map<size_t,
                                           boost::flyweights::flyweight<xt::xtensor<uint8_t, 1>>>
        fw_cache_uint8;
    static thread_local std::unordered_map<size_t, boost::flyweights::flyweight<_WCIInfos>>
        fw_cache_wciinfos;

    // _beam_crosstrack_angles (hashes[0])
    if (auto it = fw_cache_float.find(hashes[0]); it != fw_cache_float.end())
    {
        dat._beam_crosstrack_angles = it->second;
    }
    else
    {
        auto beam_crosstrack_angles = xt::xtensor<float, 1>::from_shape({ sizes[0] });
        std::memcpy(beam_crosstrack_angles.data(),
                    hash_cache.at(hashes[0]).data(),
                    beam_crosstrack_angles.size() * sizeof(float));
        dat._beam_crosstrack_angles = std::move(beam_crosstrack_angles);
        fw_cache_float.emplace(hashes[0], dat._beam_crosstrack_angles);
    }

    // _start_range_sample_numbers (hashes[1])
    if (auto it = fw_cache_uint16.find(hashes[1]); it != fw_cache_uint16.end())
    {
        dat._start_range_sample_numbers = it->second;
    }
    else
    {
        auto start_range_sample_numbers = xt::xtensor<uint16_t, 1>::from_shape({ sizes[1] });
        std::memcpy(start_range_sample_numbers.data(),
                    hash_cache.at(hashes[1]).data(),
                    start_range_sample_numbers.size() * sizeof(uint16_t));
        dat._start_range_sample_numbers = std::move(start_range_sample_numbers);
        fw_cache_uint16.emplace(hashes[1], dat._start_range_sample_numbers);
    }

    // _number_of_samples_per_beam (hashes[2])
    if (auto it = fw_cache_uint16.find(hashes[2]); it != fw_cache_uint16.end())
    {
        dat._number_of_samples_per_beam = it->second;
    }
    else
    {
        auto number_of_samples_per_beam = xt::xtensor<uint16_t, 1>::from_shape({ sizes[2] });
        std::memcpy(number_of_samples_per_beam.data(),
                    hash_cache.at(hashes[2]).data(),
                    number_of_samples_per_beam.size() * sizeof(uint16_t));
        dat._number_of_samples_per_beam = std::move(number_of_samples_per_beam);
        fw_cache_uint16.emplace(hashes[2], dat._number_of_samples_per_beam);
    }

    // _transmit_sector_numbers (hashes[3])
    if (auto it = fw_cache_uint8.find(hashes[3]); it != fw_cache_uint8.end())
    {
        dat._transmit_sector_numbers = it->second;
    }
    else
    {
        auto transmit_sector_numbers = xt::xtensor<uint8_t, 1>::from_shape({ sizes[5] });
        std::memcpy(transmit_sector_numbers.data(),
                    hash_cache.at(hashes[3]).data(),
                    transmit_sector_numbers.size() * sizeof(uint8_t));
        dat._transmit_sector_numbers = std::move(transmit_sector_numbers);
        fw_cache_uint8.emplace(hashes[3], dat._transmit_sector_numbers);
    }

    // _wci_infos (hashes[4])
    if (auto it = fw_cache_wciinfos.find(hashes[4]); it != fw_cache_wciinfos.end())
    {
        dat._wci_infos = it->second;
    }
    else
    {
        dat._wci_infos = _WCIInfos::from_binary(hash_cache.at(hashes[4]));
        fw_cache_wciinfos.emplace(hashes[4], dat._wci_infos);
    }

    return dat;
}

} // namespace _sub
} // namespace filedatatypes
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping