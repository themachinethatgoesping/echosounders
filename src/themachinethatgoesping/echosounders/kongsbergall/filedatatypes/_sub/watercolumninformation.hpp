// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/watercolumninformation.doc.hpp"

/* boost includes */
#include <boost/flyweight.hpp>

// xtensor includes
#include <xtensor/xadapt.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

#include "../../datagrams.hpp"
#include "../../types.hpp"

#include "../../../pingtools/readsamplerange.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace filedatatypes {
namespace _sub {

struct _WCIInfos
{
    float   sound_speed_at_transducer = 0.0f;
    uint8_t tvg_function_applied      = 0;
    int8_t  tvg_offset_in_db          = 0;
    float sampling_frequency_in_hz = 0.0f;
    std::vector<datagrams::substructures::WatercolumnDatagramTransmitSector> transmit_sectors;

    _WCIInfos() = default;

    _WCIInfos(const datagrams::WatercolumnDatagram& water_column_datagram)
    {
        sound_speed_at_transducer = water_column_datagram.get_sound_speed_m_s();
        tvg_function_applied      = water_column_datagram.get_tvg_function_applied();
        tvg_offset_in_db          = water_column_datagram.get_tvg_offset_in_db();
        sampling_frequency_in_hz          = water_column_datagram.get_sampling_frequency_in_hz();

        transmit_sectors = water_column_datagram.get_transmit_sectors();
    }

    bool operator ==(_WCIInfos const& other) const = default;
};

std::size_t hash_value(const _WCIInfos& data)
{
    xxh::hash3_state_t<64>               hash;
    boost::iostreams::stream<XXHashSink> stream(hash);

    stream.write(reinterpret_cast<const char*>(&data.sound_speed_at_transducer),
                 sizeof(float) + sizeof(uint8_t) + sizeof(int8_t) + sizeof(float));

    for (const auto& ts : data.transmit_sectors)
    {
        stream.write(reinterpret_cast<const char*>(&ts), sizeof(ts));
    }

    stream.flush();
    return hash.digest();
}

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
    const xt::xtensor<size_t, 1>&         get_sample_positions() const { return _sample_positions; }

    float   get_sound_speed_at_transducer() const { return _wci_infos.get().sound_speed_at_transducer; }
    uint8_t get_tvg_function_applied() const { return _wci_infos.get().tvg_function_applied; }
    int8_t  get_tvg_offset_in_db() const { return _wci_infos.get().tvg_offset_in_db; }
    const std::vector<datagrams::substructures::WatercolumnDatagramTransmitSector>& get_transmit_sectors()
        const
    {
        return _wci_infos.get().transmit_sectors;
    }
    float get_sampling_frequency_in_hz() const { return _wci_infos.get().sampling_frequency_in_hz; }
};

} // namespace _sub
} // namespace filedatatypes
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping