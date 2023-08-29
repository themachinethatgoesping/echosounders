// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/em3000pingwatercolumn.doc.hpp"

/* std includes */
#include <filesystem>
#include <fstream>
#include <memory>
#include <unordered_map>
#include <vector>

#include <fmt/core.h>

// xtensor includes
#include <xtensor/xadapt.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../filetemplates/datatypes/i_pingwatercolumn.hpp"

#include "../em3000_datagrams.hpp"
#include "../em3000_types.hpp"

#include "em3000pingcommon.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace filedatatypes {

template<typename t_ifstream>
class EM3000PingWatercolumn
    : public filetemplates::datatypes::I_PingWatercolumn
    , public EM3000PingCommon<t_ifstream>
{
  public:
    using t_base0 = filetemplates::datatypes::I_PingCommon;
    using t_base1 = filetemplates::datatypes::I_PingWatercolumn;
    using t_base2 = EM3000PingCommon<t_ifstream>;

    using t_base2::_raw_data;
    using typename t_base2::t_rawdata;

    struct WaterColumnInformation
    {
        boost::flyweights::flyweight<xt::xtensor<float, 1>>    _beam_pointing_angles;
        boost::flyweights::flyweight<xt::xtensor<uint16_t, 1>> _start_range_sample_numbers;
        boost::flyweights::flyweight<xt::xtensor<uint16_t, 1>> _number_of_samples_per_beam;
        xt::xtensor<uint16_t, 1>                               _detected_range_in_samples;
        boost::flyweights::flyweight<xt::xtensor<uint8_t, 1>>  _transmit_sector_numbers;
        xt::xtensor<size_t, 1>                                 _sample_positions;

        datagrams::WatercolumnDatagram _water_column_datagram; //note, this will be safe without beams()

        WaterColumnInformation(std::shared_ptr<t_rawdata> raw_data)
        {
            auto water_column_datagram = raw_data->read_merged_watercolumndatagram(true);
            auto nbeams                = water_column_datagram.beams().size();

            // initialize arrays using from shape function
            auto beam_pointing_angles       = xt::xtensor<float, 1>::from_shape({ nbeams });
            auto start_range_sample_numbers = xt::xtensor<uint16_t, 1>::from_shape({ nbeams });
            auto number_of_samples_per_beam = xt::xtensor<uint16_t, 1>::from_shape({ nbeams });
            auto detected_range_in_samples  = xt::xtensor<uint16_t, 1>::from_shape({ nbeams });
            auto transmit_sector_numbers    = xt::xtensor<uint8_t, 1>::from_shape({ nbeams });
            auto sample_positions           = xt::xtensor<size_t, 1>::from_shape({ nbeams });

            size_t bn = 0;
            for (const auto& b : water_column_datagram.beams())
            {
                sample_positions.unchecked(bn) = b.get_sample_position();

                beam_pointing_angles.unchecked(bn)       = b.get_beam_pointing_angle_in_degrees();
                detected_range_in_samples.unchecked(bn)  = b.get_detected_range_in_samples();
                start_range_sample_numbers.unchecked(bn) = b.get_start_range_sample_number();
                number_of_samples_per_beam.unchecked(bn) = b.get_number_of_samples();
                transmit_sector_numbers.unchecked(bn)    = b.get_transmit_sector_number();

                ++bn;
            }

            _sample_positions           = std::move(sample_positions);
            _beam_pointing_angles       = std::move(beam_pointing_angles);
            _start_range_sample_numbers = std::move(start_range_sample_numbers);
            _number_of_samples_per_beam = std::move(number_of_samples_per_beam);
            _detected_range_in_samples  = std::move(detected_range_in_samples);
            _transmit_sector_numbers    = std::move(transmit_sector_numbers);

            _water_column_datagram = water_column_datagram.without_beams();
        }
    };

    std::optional<WaterColumnInformation> _watercolumninformation;

  public:
    EM3000PingWatercolumn(std::shared_ptr<t_rawdata> raw_data)
        : t_base0("EM3000PingWatercolumn") // necessary because of virtual inheritance
        //, t_base1("EM3000PingWatercolumn"),
        , t_base2(std::move(raw_data))
    {
    }
    virtual ~EM3000PingWatercolumn() = default;

    // ----- I_PingCommon interface -----
    void load() override { _watercolumninformation = WaterColumnInformation(_raw_data); }
    void release() override { _watercolumninformation.reset(); }
    bool loaded() override { return _watercolumninformation.has_value(); }

    // ----- I_PingWatercolumn interface -----
    using t_base1::check_feature;
    using t_base1::has_amplitudes;
    using t_base2::raw_data;

    bool has_amplitudes() const override
    {
        return raw_data()
                   .get_datagram_infos_by_type(t_EM3000DatagramIdentifier::WatercolumnDatagram)
                   .size() > 0;
    }

    xt::xtensor<float, 2> get_amplitudes() const override
    {
        return get_amplitudes(_raw_data->get_beam_sample_selection_all());
    }

    xt::xtensor<float, 2> get_amplitudes(const pingtools::BeamSampleSelection& selection) const override
    {
        check_feature(has_amplitudes(), "amplitudes", "get_amplitudes");

        auto amplitudes = xt::xtensor<float, 2>::from_shape(
            { selection.get_number_of_beams(), selection.get_number_of_samples_ensemble() });

        // samples.fill(std::numeric_limits<float>::quiet_NaN());
        size_t ensemble_offset = selection.get_first_sample_number_ensemble();

        size_t output_bn = 0;

        auto& ifs = _raw_data->get_wci_ifs();

        size_t local_output_bn = 0;
        for (const auto& bn : selection.get_beam_numbers())
        {
            // read amplitudes
            auto rsr = selection.get_read_sample_range(
                local_output_bn,
                _raw_data->get_start_range_sample_numbers().unchecked(bn),
                _raw_data->get_number_of_samples_per_beam().unchecked(bn));

            if (rsr.get_number_of_samples_to_read() > 0)
            {
                xt::xtensor<int8_t, 1> beam_amplitudes = _raw_data->read_beam_samples(bn, rsr, ifs);
                xt::view(amplitudes,
                         output_bn,
                         xt::range(rsr.get_first_read_sample_offset() - ensemble_offset,
                                   rsr.get_last_read_sample_offset() + 1 - ensemble_offset)) =
                    xt::cast<float>(beam_amplitudes);
            }

            // assign nan to amplitudes that were not read
            xt::view(amplitudes,
                     output_bn,
                     xt::range(0, rsr.get_first_read_sample_offset() - ensemble_offset))
                .fill(std::numeric_limits<float>::quiet_NaN());

            using namespace xt::placeholders;
            xt::view(amplitudes,
                     output_bn,
                     xt::range(rsr.get_last_read_sample_offset() + 1 - ensemble_offset, _))
                .fill(std::numeric_limits<float>::quiet_NaN());

            ++local_output_bn;
            ++output_bn;
        }

        return amplitudes;
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        printer.append(t_base1::__printer__(float_precision));

        return printer;
    }
};

}
} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping