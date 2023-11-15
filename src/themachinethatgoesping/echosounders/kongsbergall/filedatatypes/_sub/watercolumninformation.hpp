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

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace filedatatypes {
namespace _sub {

/**
 * @brief This is a substructure of the KongsbergAllPingWaterColumn class. It is used to store information
 * necessary to efficiently read water column data from the file.
 * It does not hold the actual water column samples
 *
 * Note this is a private substructure and is thus not part of the public API or pybind11 interface.
 *
 * @tparam t_rawdata
 */
template<typename t_rawdata>
class WaterColumnInformation
{
    boost::flyweights::flyweight<xt::xtensor<float, 1>>    _beam_crosstrack_angles;
    boost::flyweights::flyweight<xt::xtensor<uint16_t, 1>> _start_range_sample_numbers;
    boost::flyweights::flyweight<xt::xtensor<uint16_t, 1>> _number_of_samples_per_beam;
    xt::xtensor<uint16_t, 1>                               _detected_range_in_samples;
    boost::flyweights::flyweight<xt::xtensor<uint8_t, 1>>  _transmit_sector_numbers;
    xt::xtensor<size_t, 1>                                 _sample_positions;

    datagrams::WatercolumnDatagram
        _water_column_datagram; // note, this will be safed without beams()

  public:
    WaterColumnInformation(std::shared_ptr<t_rawdata> raw_data)
    {
        auto water_column_datagram = raw_data->read_merged_watercolumndatagram(true);
        auto nbeams                = water_column_datagram.beams().size();

        // initialize arrays using from shape function
        auto beam_crosstrack_angles       = xt::xtensor<float, 1>::from_shape({ nbeams });
        auto start_range_sample_numbers = xt::xtensor<uint16_t, 1>::from_shape({ nbeams });
        auto number_of_samples_per_beam = xt::xtensor<uint16_t, 1>::from_shape({ nbeams });
        auto detected_range_in_samples  = xt::xtensor<uint16_t, 1>::from_shape({ nbeams });
        auto transmit_sector_numbers    = xt::xtensor<uint8_t, 1>::from_shape({ nbeams });
        auto sample_positions           = xt::xtensor<size_t, 1>::from_shape({ nbeams });

        size_t bn = 0;
        for (const auto& b : water_column_datagram.beams())
        {
            sample_positions.unchecked(bn) = b.get_sample_position();

            beam_crosstrack_angles.unchecked(bn)       = b.get_beam_crosstrack_angle_in_degrees();
            detected_range_in_samples.unchecked(bn)  = b.get_detected_range_in_samples();
            start_range_sample_numbers.unchecked(bn) = b.get_start_range_sample_number();
            number_of_samples_per_beam.unchecked(bn) = b.get_number_of_samples();
            transmit_sector_numbers.unchecked(bn)    = b.get_transmit_sector_number();

            ++bn;
        }

        _sample_positions           = std::move(sample_positions);
        _beam_crosstrack_angles       = std::move(beam_crosstrack_angles);
        _start_range_sample_numbers = std::move(start_range_sample_numbers);
        _number_of_samples_per_beam = std::move(number_of_samples_per_beam);
        _detected_range_in_samples  = std::move(detected_range_in_samples);
        _transmit_sector_numbers    = std::move(transmit_sector_numbers);

        _water_column_datagram = water_column_datagram.without_beams();
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
    const datagrams::WatercolumnDatagram& get_water_column_datagram() const
    {
        return _water_column_datagram;
    }
};

} // namespace substructures
} // namespace filedatatypes
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping