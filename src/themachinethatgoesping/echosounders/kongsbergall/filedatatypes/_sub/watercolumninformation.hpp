// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/watercolumninformation.doc.hpp"

/* boost includes */
#include <boost/flyweight.hpp>

// xtensor includes
#include <xtensor/containers/xadapt.hpp>

#include <xtensor/views/xview.hpp>

#include "../../datagrams.hpp"
#include "../../types.hpp"

#include "../../../pingtools/readsamplerange.hpp"

#include "_wciinfos.hpp"
#include <themachinethatgoesping/tools/classhelper/classversion.hpp>
#include <themachinethatgoesping/tools/helper/xtensor_hash.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace filedatatypes {
namespace _sub {

/**
 * @brief This is a substructure of the KongsbergAllPingWaterColumn class. It is used to store
 * information necessary to efficiently read water column data from the file. It does not hold the
 * actual water column samples
 *
 * Note this is a private substructure and is thus not part of the public API or pybind11 interface.
 *
 */
class WaterColumnInformation
{
    boost::flyweights::flyweight<xt::xtensor<float, 1>>    _beam_crosstrack_angles;
    boost::flyweights::flyweight<xt::xtensor<uint16_t, 1>> _start_range_sample_numbers;
    boost::flyweights::flyweight<xt::xtensor<uint16_t, 1>> _number_of_samples_per_beam;
    xt::xtensor<uint16_t, 1>                               _detected_range_in_samples;
    boost::flyweights::flyweight<xt::xtensor<uint8_t, 1>>  _transmit_sector_numbers;
    xt::xtensor<size_t, 1>                                 _sample_positions;

    boost::flyweights::flyweight<_WCIInfos> _wci_infos;
    // datagrams::WatercolumnDatagram
    //     _water_column_datagram; // note, this will be saved without beams()

    WaterColumnInformation() = default; // for to/from stream

  public:
    WaterColumnInformation(const datagrams::WatercolumnDatagram& water_column_datagram)
    {
        auto nbeams = water_column_datagram.get_beams().size();

        // initialize arrays using from shape function
        auto beam_crosstrack_angles     = xt::xtensor<float, 1>::from_shape({ nbeams });
        auto start_range_sample_numbers = xt::xtensor<uint16_t, 1>::from_shape({ nbeams });
        auto number_of_samples_per_beam = xt::xtensor<uint16_t, 1>::from_shape({ nbeams });
        auto detected_range_in_samples  = xt::xtensor<uint16_t, 1>::from_shape({ nbeams });
        auto transmit_sector_numbers    = xt::xtensor<uint8_t, 1>::from_shape({ nbeams });
        auto sample_positions           = xt::xtensor<size_t, 1>::from_shape({ nbeams });

        size_t bn = 0;
        for (const auto& b : water_column_datagram.get_beams())
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

    bool operator==(const WaterColumnInformation& other) const = default;

    template<typename t_ifstream>
    auto read_beam_samples(uint16_t                          bn,
                           const pingtools::ReadSampleRange& rsr,
                           t_ifstream&                       ifs) const
    {
        return datagrams::substructures::WatercolumnDatagramBeam::read_samples(
            ifs,
            _sample_positions.unchecked(bn),
            rsr.get_first_sample_to_read(),
            rsr.get_number_of_samples_to_read(),
            get_number_of_samples_per_beam().unchecked(bn));
    }

    // accessors
    const xt::xtensor<float, 1>& get_beam_crosstrack_angles() const
    {
        return _beam_crosstrack_angles.get();
    }
    const xt::xtensor<uint16_t, 1>& get_start_range_sample_numbers() const
    {
        return _start_range_sample_numbers.get();
    }
    const xt::xtensor<uint16_t, 1>& get_number_of_samples_per_beam() const
    {
        return _number_of_samples_per_beam.get();
    }
    const xt::xtensor<uint16_t, 1>& get_detected_range_in_samples() const
    {
        return _detected_range_in_samples;
    }
    const xt::xtensor<uint8_t, 1>& get_transmit_sector_numbers() const
    {
        return _transmit_sector_numbers.get();
    }
    const xt::xtensor<size_t, 1>& get_sample_positions() const { return _sample_positions; }

    float get_sound_speed_at_transducer() const
    {
        return _wci_infos.get().get_sound_speed_at_transducer();
    }
    uint8_t get_tvg_factor_applied() const { return _wci_infos.get().get_tvg_function_applied(); }
    int8_t  get_tvg_offset_in_db() const { return _wci_infos.get().get_tvg_offset_in_db(); }
    const std::vector<datagrams::substructures::WatercolumnDatagramTransmitSector>&
    get_transmit_sectors() const
    {
        return _wci_infos.get().get_transmit_sectors();
    }
    float get_sample_interval() const { return _wci_infos.get().get_sampling_interval(); }

    // ----- functions used for PackageCache -----
    void to_stream(std::ostream& os, std::unordered_map<size_t, std::string>& hash_cache) const
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
        hashes.push_back(
            xxh::xxhash3<64>(_number_of_samples_per_beam.get().data(),
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

        // _number_of_samples_per_beam
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

    static WaterColumnInformation from_stream(
        std::istream&                                  is,
        const std::unordered_map<size_t, std::string>& hash_cache)
    {
        // create WaterColumnInformation
        WaterColumnInformation dat;

        std::vector<size_t> hashes(
            5);                       // all except _detected_range_in_samples and _sample_positions
        std::vector<size_t> sizes(6); // all except _wci_infos

        // read hashes and sizes from stream
        is.read(reinterpret_cast<char*>(hashes.data()), hashes.size() * sizeof(size_t));
        is.read(reinterpret_cast<char*>(sizes.data()), sizes.size() * sizeof(size_t));

        // resize arrays
        auto beam_crosstrack_angles     = xt::xtensor<float, 1>::from_shape({ sizes[0] });
        auto start_range_sample_numbers = xt::xtensor<uint16_t, 1>::from_shape({ sizes[1] });
        auto number_of_samples_per_beam = xt::xtensor<uint16_t, 1>::from_shape({ sizes[2] });
        dat._detected_range_in_samples  = xt::xtensor<uint16_t, 1>::from_shape({ sizes[3] });
        auto transmit_sector_numbers    = xt::xtensor<uint8_t, 1>::from_shape({ sizes[4] });
        dat._sample_positions           = xt::xtensor<size_t, 1>::from_shape({ sizes[5] });

        // read detected_range_in_samples from stream
        is.read(reinterpret_cast<char*>(dat._detected_range_in_samples.data()),
                dat._detected_range_in_samples.size() * sizeof(uint16_t));

        // read sample_positions from stream
        is.read(reinterpret_cast<char*>(dat._sample_positions.data()),
                dat._sample_positions.size() * sizeof(size_t));

        // read _beam_crosstrack_angles from hash_cache
        std::memcpy(beam_crosstrack_angles.data(),
                    hash_cache.at(hashes[0]).data(),
                    beam_crosstrack_angles.size() * sizeof(float));
        dat._beam_crosstrack_angles = std::move(beam_crosstrack_angles);

        // read _start_range_sample_numbers from hash_cache
        std::memcpy(start_range_sample_numbers.data(),
                    hash_cache.at(hashes[1]).data(),
                    start_range_sample_numbers.size() * sizeof(uint16_t));
        dat._start_range_sample_numbers = std::move(start_range_sample_numbers);

        // read _number_of_samples_per_beam from hash_cache
        std::memcpy(number_of_samples_per_beam.data(),
                    hash_cache.at(hashes[2]).data(),
                    number_of_samples_per_beam.size() * sizeof(uint16_t));
        dat._number_of_samples_per_beam = std::move(number_of_samples_per_beam);

        // read _transmit_sector_numbers from hash_cache
        std::memcpy(transmit_sector_numbers.data(),
                    hash_cache.at(hashes[3]).data(),
                    transmit_sector_numbers.size() * sizeof(uint8_t));
        dat._transmit_sector_numbers = std::move(transmit_sector_numbers);

        // read _wci_infos from hash_cache
        dat._wci_infos = _WCIInfos::from_binary(hash_cache.at(hashes[4]));

        return dat;
    }
};

} // namespace _sub
} // namespace filedatatypes
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping