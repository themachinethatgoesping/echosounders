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

#include "../../../pingtools/readsamplerange.hpp"

#include "_wciinfos.hpp"

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
    WaterColumnInformation(const datagrams::WatercolumnDatagram& water_column_datagram);

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
    void to_stream(std::ostream& os, std::unordered_map<size_t, std::string>& hash_cache) const;

    static WaterColumnInformation from_stream(
        std::istream&                                  is,
        const std::unordered_map<size_t, std::string>& hash_cache);
};

} // namespace _sub
} // namespace filedatatypes
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping