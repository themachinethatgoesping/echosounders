// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "watercolumninformation.hpp"

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

    std::vector<size_t> hashes(5); // _beam_crosstrack_angles, _start_range_sample_numbers,
                                   // _number_of_samples_per_beam, _transmit_sector_numbers,
                                   // _wci_infos
    std::vector<size_t> sizes(7);  // _beam_crosstrack_angles, _start_range_sample_numbers,
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
    auto beam_crosstrack_angles     = xt::xtensor<float, 1>::from_shape({ sizes[0] });
    auto start_range_sample_numbers = xt::xtensor<uint16_t, 1>::from_shape({ sizes[1] });
    auto number_of_samples_per_beam = xt::xtensor<uint16_t, 1>::from_shape({ sizes[2] });
    dat._detected_range_in_samples  = xt::xtensor<uint16_t, 1>::from_shape({ sizes[3] });
    dat._detected_range_in_samples_high_resolution =
        xt::xtensor<float, 1>::from_shape({ sizes[4] });
    auto transmit_sector_numbers = xt::xtensor<uint8_t, 1>::from_shape({ sizes[5] });
    dat._sample_positions        = xt::xtensor<size_t, 1>::from_shape({ sizes[6] });

    // read detected_range_in_samples from stream
    is.read(reinterpret_cast<char*>(dat._detected_range_in_samples.data()),
            dat._detected_range_in_samples.size() * sizeof(uint16_t));
    is.read(reinterpret_cast<char*>(dat._detected_range_in_samples_high_resolution.data()),
            dat._detected_range_in_samples_high_resolution.size() * sizeof(float));

    // read sample_positions from stream
    is.read(reinterpret_cast<char*>(dat._sample_positions.data()),
            dat._sample_positions.size() * sizeof(size_t));

    // read _beam_crosstrack_angles from hash_cache (hashes[0])
    std::memcpy(beam_crosstrack_angles.data(),
                hash_cache.at(hashes[0]).data(),
                beam_crosstrack_angles.size() * sizeof(float));
    dat._beam_crosstrack_angles = std::move(beam_crosstrack_angles);

    // read _start_range_sample_numbers from hash_cache (hashes[1])
    std::memcpy(start_range_sample_numbers.data(),
                hash_cache.at(hashes[1]).data(),
                start_range_sample_numbers.size() * sizeof(uint16_t));
    dat._start_range_sample_numbers = std::move(start_range_sample_numbers);

    // read _number_of_samples_per_beam from hash_cache (hashes[2])
    std::memcpy(number_of_samples_per_beam.data(),
                hash_cache.at(hashes[2]).data(),
                number_of_samples_per_beam.size() * sizeof(uint16_t));
    dat._number_of_samples_per_beam = std::move(number_of_samples_per_beam);

    // read _transmit_sector_numbers from hash_cache (hashes[3])
    std::memcpy(transmit_sector_numbers.data(),
                hash_cache.at(hashes[3]).data(),
                transmit_sector_numbers.size() * sizeof(uint8_t));
    dat._transmit_sector_numbers = std::move(transmit_sector_numbers);

    // read _wci_infos from hash_cache (hashes[4])
    dat._wci_infos = _WCIInfos::from_binary(hash_cache.at(hashes[4]));

    return dat;
}

} // namespace _sub
} // namespace filedatatypes
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping