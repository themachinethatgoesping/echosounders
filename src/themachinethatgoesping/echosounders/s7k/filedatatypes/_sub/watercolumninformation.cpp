// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "watercolumninformation.hpp"

#include <array>
#include <cstring>
#include <ostream>

#include <xxhash.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace filedatatypes {
namespace _sub {

WaterColumnInformation::WaterColumnInformation(
    const datagrams::CompressedWaterColumn& water_column_datagram)
{
    const auto&  beams = water_column_datagram.get_beams().get_beams();
    const size_t nbeams = beams.size();

    auto beam_numbers     = xt::xtensor<uint16_t, 1>::from_shape({ nbeams });
    auto sample_counts    = xt::xtensor<uint32_t, 1>::from_shape({ nbeams });
    auto sample_positions = xt::xtensor<int64_t, 1>::from_shape({ nbeams });

    for (size_t bn = 0; bn < nbeams; ++bn)
    {
        beam_numbers.unchecked(bn)     = beams[bn].get_beam_number();
        sample_counts.unchecked(bn)    = beams[bn].get_sample_count();
        sample_positions.unchecked(bn) = beams[bn].get_sample_position();
    }

    _beam_numbers     = std::move(beam_numbers);
    _sample_counts    = std::move(sample_counts);
    _sample_positions = std::move(sample_positions);
    _wci_infos        = _WCIInfos(water_column_datagram);
}

void WaterColumnInformation::to_stream(std::ostream&                            os,
                                       std::unordered_map<size_t, std::string>& hash_cache) const
{
    std::vector<size_t> hashes; // _beam_numbers, _sample_counts, _wci_infos
    std::vector<size_t> sizes;  // _beam_numbers, _sample_counts, _sample_positions
    hashes.reserve(3);
    sizes.reserve(3);

    // hashes[0], sizes[0]: _beam_numbers (deduplicated)
    hashes.push_back(xxh::xxhash3<64>(_beam_numbers.get().data(),
                                      _beam_numbers.get().size() * sizeof(uint16_t)));
    sizes.push_back(_beam_numbers.get().size());
    if (!hash_cache.contains(hashes.back()))
    {
        auto& buffer = hash_cache[hashes.back()];
        buffer.resize(_beam_numbers.get().size() * sizeof(uint16_t));
        std::memcpy(buffer.data(),
                    _beam_numbers.get().data(),
                    _beam_numbers.get().size() * sizeof(uint16_t));
    }

    // hashes[1], sizes[1]: _sample_counts (deduplicated)
    hashes.push_back(xxh::xxhash3<64>(_sample_counts.get().data(),
                                      _sample_counts.get().size() * sizeof(uint32_t)));
    sizes.push_back(_sample_counts.get().size());
    if (!hash_cache.contains(hashes.back()))
    {
        auto& buffer = hash_cache[hashes.back()];
        buffer.resize(_sample_counts.get().size() * sizeof(uint32_t));
        std::memcpy(buffer.data(),
                    _sample_counts.get().data(),
                    _sample_counts.get().size() * sizeof(uint32_t));
    }

    // hashes[2]: _wci_infos (deduplicated)
    hashes.push_back(hash_value(_wci_infos.get()));
    if (!hash_cache.contains(hashes.back()))
        hash_cache[hashes.back()] = _wci_infos.get().to_binary();

    // sizes[2]: _sample_positions (written directly, unique per ping)
    sizes.push_back(_sample_positions.size());

    // write hashes and sizes
    os.write(reinterpret_cast<const char*>(hashes.data()), hashes.size() * sizeof(size_t));
    os.write(reinterpret_cast<const char*>(sizes.data()), sizes.size() * sizeof(size_t));

    // write sample_positions directly
    os.write(reinterpret_cast<const char*>(_sample_positions.data()),
             _sample_positions.size() * sizeof(int64_t));
}

WaterColumnInformation WaterColumnInformation::from_stream(
    std::istream&                                  is,
    const std::unordered_map<size_t, std::string>& hash_cache)
{
    WaterColumnInformation dat;

    std::array<size_t, 3> hashes; // _beam_numbers, _sample_counts, _wci_infos
    std::array<size_t, 3> sizes;  // _beam_numbers, _sample_counts, _sample_positions

    is.read(reinterpret_cast<char*>(hashes.data()), hashes.size() * sizeof(size_t));
    is.read(reinterpret_cast<char*>(sizes.data()), sizes.size() * sizeof(size_t));

    // _sample_positions (unique per ping, always read from stream)
    dat._sample_positions = xt::xtensor<int64_t, 1>::from_shape({ sizes[2] });
    is.read(reinterpret_cast<char*>(dat._sample_positions.data()),
            dat._sample_positions.size() * sizeof(int64_t));

    // Flyweight cache: reuse previously constructed flyweights by xxhash key (avoids re-allocating
    // and re-hashing the full array for repeated beam configurations - the common case).
    static thread_local std::unordered_map<size_t,
                                           boost::flyweights::flyweight<xt::xtensor<uint16_t, 1>>>
        fw_cache_uint16;
    static thread_local std::unordered_map<size_t,
                                           boost::flyweights::flyweight<xt::xtensor<uint32_t, 1>>>
        fw_cache_uint32;
    static thread_local std::unordered_map<size_t, boost::flyweights::flyweight<_WCIInfos>>
        fw_cache_wciinfos;

    // _beam_numbers (hashes[0])
    if (auto it = fw_cache_uint16.find(hashes[0]); it != fw_cache_uint16.end())
    {
        dat._beam_numbers = it->second;
    }
    else
    {
        auto beam_numbers = xt::xtensor<uint16_t, 1>::from_shape({ sizes[0] });
        std::memcpy(beam_numbers.data(),
                    hash_cache.at(hashes[0]).data(),
                    beam_numbers.size() * sizeof(uint16_t));
        dat._beam_numbers = std::move(beam_numbers);
        fw_cache_uint16.emplace(hashes[0], dat._beam_numbers);
    }

    // _sample_counts (hashes[1])
    if (auto it = fw_cache_uint32.find(hashes[1]); it != fw_cache_uint32.end())
    {
        dat._sample_counts = it->second;
    }
    else
    {
        auto sample_counts = xt::xtensor<uint32_t, 1>::from_shape({ sizes[1] });
        std::memcpy(sample_counts.data(),
                    hash_cache.at(hashes[1]).data(),
                    sample_counts.size() * sizeof(uint32_t));
        dat._sample_counts = std::move(sample_counts);
        fw_cache_uint32.emplace(hashes[1], dat._sample_counts);
    }

    // _wci_infos (hashes[2])
    if (auto it = fw_cache_wciinfos.find(hashes[2]); it != fw_cache_wciinfos.end())
    {
        dat._wci_infos = it->second;
    }
    else
    {
        dat._wci_infos = _WCIInfos::from_binary(hash_cache.at(hashes[2]));
        fw_cache_wciinfos.emplace(hashes[2], dat._wci_infos);
    }

    return dat;
}

} // namespace _sub
} // namespace filedatatypes
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
