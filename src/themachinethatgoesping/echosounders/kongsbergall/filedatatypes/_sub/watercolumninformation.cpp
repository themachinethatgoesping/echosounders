// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "watercolumninformation.hpp"

#include <cstring>

#include <xxhash.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace filedatatypes {
namespace _sub {

WaterColumnInformation::WaterColumnInformation(
    const datagrams::WatercolumnDatagram& water_column_datagram)
{
    auto nbeams = water_column_datagram.get_beams().get_beams().size();

    // initialize arrays using from shape function
    auto beam_crosstrack_angles     = xt::xtensor<float, 1>::from_shape({ nbeams });
    auto start_range_sample_numbers = xt::xtensor<uint16_t, 1>::from_shape({ nbeams });
    auto number_of_samples_per_beam = xt::xtensor<uint16_t, 1>::from_shape({ nbeams });
    auto detected_range_in_samples  = xt::xtensor<uint16_t, 1>::from_shape({ nbeams });
    auto transmit_sector_numbers    = xt::xtensor<uint8_t, 1>::from_shape({ nbeams });
    auto sample_positions           = xt::xtensor<size_t, 1>::from_shape({ nbeams });

    size_t bn = 0;
    for (const auto& b : water_column_datagram.get_beams().get_beams())
    {
        sample_positions.unchecked(bn) = b.get_sample_position();

        beam_crosstrack_angles.unchecked(bn)     = b.get_beam_crosstrack_angle_in_degrees();
        detected_range_in_samples.unchecked(bn)  = b.get_detected_range_in_samples();
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
    _transmit_sector_numbers    = std::move(transmit_sector_numbers);

    _wci_infos = _WCIInfos(water_column_datagram);
}

void WaterColumnInformation::to_stream(std::ostream&                            os,
                                       std::unordered_map<size_t, std::string>& hash_cache) const
{
    std::string         buffer;
    std::vector<size_t> hashes, sizes;
    hashes.reserve(5); // all except _detected_range_in_samples and _sample_positions
    sizes.reserve(6);  // all except _wci_infos

    // _beam_crosstrack_angles
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

    // _start_range_sample_numbers
    hashes.push_back(
        xxh::xxhash3<64>(_start_range_sample_numbers.get().data(),
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

    // _number_of_samples_per_beam
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

    // _detected_range_in_samples (write directly to stream, safe size here)
    sizes.push_back(_detected_range_in_samples.size());

    // _transmit_sector_numbers
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

    // _sample_positions (write directly to stream, safe size in 'hashes' array)
    sizes.push_back(_sample_positions.size());

    // _wci_infos
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

    // write sample_positions to stream
    os.write(reinterpret_cast<const char*>(_sample_positions.data()),
             _sample_positions.size() * sizeof(size_t));
}

WaterColumnInformation WaterColumnInformation::from_stream(
    std::istream&                                  is,
    const std::unordered_map<size_t, std::string>& hash_cache)
{
    WaterColumnInformation dat;

    std::vector<size_t> hashes(
        5);                       // all except _detected_range_in_samples and _sample_positions
    std::vector<size_t> sizes(6); // all except _wci_infos

    // read hashes and sizes from stream
    is.read(reinterpret_cast<char*>(hashes.data()), hashes.size() * sizeof(size_t));
    is.read(reinterpret_cast<char*>(sizes.data()), sizes.size() * sizeof(size_t));

    // Read per-ping unique data (always needed, cannot be cached)
    dat._detected_range_in_samples = xt::xtensor<uint16_t, 1>::from_shape({ sizes[3] });
    is.read(reinterpret_cast<char*>(dat._detected_range_in_samples.data()),
            dat._detected_range_in_samples.size() * sizeof(uint16_t));

    dat._sample_positions = xt::xtensor<size_t, 1>::from_shape({ sizes[5] });
    is.read(reinterpret_cast<char*>(dat._sample_positions.data()),
            dat._sample_positions.size() * sizeof(size_t));

    // Flyweight cache: reuse previously constructed flyweight objects by their xxhash key.
    // Most pings within a file share identical beam geometry, so this avoids repeated
    // xtensor allocation + memcpy + flyweight factory lookup for ~99% of pings.
    struct FlyweightCache {
        std::unordered_map<size_t, boost::flyweights::flyweight<xt::xtensor<float, 1>>>    beam_crosstrack;
        std::unordered_map<size_t, boost::flyweights::flyweight<xt::xtensor<uint16_t, 1>>> start_range;
        std::unordered_map<size_t, boost::flyweights::flyweight<xt::xtensor<uint16_t, 1>>> num_samples;
        std::unordered_map<size_t, boost::flyweights::flyweight<xt::xtensor<uint8_t, 1>>>  tx_sectors;
        std::unordered_map<size_t, boost::flyweights::flyweight<_WCIInfos>>                wci_infos;
    };
    static thread_local FlyweightCache fw_cache;

    // _beam_crosstrack_angles
    {
        auto it = fw_cache.beam_crosstrack.find(hashes[0]);
        if (it != fw_cache.beam_crosstrack.end()) {
            dat._beam_crosstrack_angles = it->second;
        } else {
            auto arr = xt::xtensor<float, 1>::from_shape({ sizes[0] });
            std::memcpy(arr.data(), hash_cache.at(hashes[0]).data(), sizes[0] * sizeof(float));
            dat._beam_crosstrack_angles = std::move(arr);
            fw_cache.beam_crosstrack.emplace(hashes[0], dat._beam_crosstrack_angles);
        }
    }

    // _start_range_sample_numbers
    {
        auto it = fw_cache.start_range.find(hashes[1]);
        if (it != fw_cache.start_range.end()) {
            dat._start_range_sample_numbers = it->second;
        } else {
            auto arr = xt::xtensor<uint16_t, 1>::from_shape({ sizes[1] });
            std::memcpy(arr.data(), hash_cache.at(hashes[1]).data(), sizes[1] * sizeof(uint16_t));
            dat._start_range_sample_numbers = std::move(arr);
            fw_cache.start_range.emplace(hashes[1], dat._start_range_sample_numbers);
        }
    }

    // _number_of_samples_per_beam
    {
        auto it = fw_cache.num_samples.find(hashes[2]);
        if (it != fw_cache.num_samples.end()) {
            dat._number_of_samples_per_beam = it->second;
        } else {
            auto arr = xt::xtensor<uint16_t, 1>::from_shape({ sizes[2] });
            std::memcpy(arr.data(), hash_cache.at(hashes[2]).data(), sizes[2] * sizeof(uint16_t));
            dat._number_of_samples_per_beam = std::move(arr);
            fw_cache.num_samples.emplace(hashes[2], dat._number_of_samples_per_beam);
        }
    }

    // _transmit_sector_numbers
    {
        auto it = fw_cache.tx_sectors.find(hashes[3]);
        if (it != fw_cache.tx_sectors.end()) {
            dat._transmit_sector_numbers = it->second;
        } else {
            auto arr = xt::xtensor<uint8_t, 1>::from_shape({ sizes[4] });
            std::memcpy(arr.data(), hash_cache.at(hashes[3]).data(), sizes[4] * sizeof(uint8_t));
            dat._transmit_sector_numbers = std::move(arr);
            fw_cache.tx_sectors.emplace(hashes[3], dat._transmit_sector_numbers);
        }
    }

    // _wci_infos
    {
        auto it = fw_cache.wci_infos.find(hashes[4]);
        if (it != fw_cache.wci_infos.end()) {
            dat._wci_infos = it->second;
        } else {
            dat._wci_infos = _WCIInfos::from_binary(hash_cache.at(hashes[4]));
            fw_cache.wci_infos.emplace(hashes[4], dat._wci_infos);
        }
    }

    return dat;
}

} // namespace _sub
} // namespace filedatatypes
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
