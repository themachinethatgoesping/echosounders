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

#include <boost/flyweight.hpp>

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

#include "_sub/watercolumninformation.hpp"
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

    using WaterColumnInformation = _sub::WaterColumnInformation<t_rawdata>;

  private:
    std::shared_ptr<WaterColumnInformation> _watercolumninformation;

    const WaterColumnInformation& get_wcinfos()
    {
        load();

        return *_watercolumninformation;
    }

  public:
    EM3000PingWatercolumn(std::shared_ptr<t_rawdata> raw_data)
        : t_base0("EM3000PingWatercolumn") // necessary because of virtual inheritance
        , t_base1()
        , t_base2(std::move(raw_data))
    {
    }
    virtual ~EM3000PingWatercolumn() = default;

    // ----- I_PingCommon interface -----
    void load(bool force = false) override
    {
        if (loaded() && !force)
            return;

        _watercolumninformation = std::make_shared<WaterColumnInformation>(_raw_data);
    }
    void release() override { _watercolumninformation.reset(); }
    bool loaded() override { return _watercolumninformation != nullptr; }

    uint16_t get_number_of_beams() override
    {
        if (!has_amplitudes())
            return 0;

        return get_wcinfos().get_beam_crosstrack_angles().size();
    }

    // common variable access
    float get_sample_interval() override
    {
        return 1 / get_wcinfos().get_water_column_datagram().get_sampling_frequency_in_hz();
    }

    // ----- getter/setters -----
    xt::xtensor<float, 1> get_beam_crosstrack_angles(
        const pingtools::BeamSelection& selection) override
    {
        const auto beam_numbers = selection.get_beam_numbers();

        auto beam_crosstrack_angles = xt::xtensor<float, 1>::from_shape({ beam_numbers.size() });
        const auto& wcinfos         = get_wcinfos();

        for (unsigned int nr = 0; nr < beam_numbers.size(); ++nr)
        {
            if (beam_numbers[nr] >= wcinfos.get_beam_crosstrack_angles().size())
                beam_crosstrack_angles.unchecked(nr) = std::numeric_limits<float>::quiet_NaN();
            else
                beam_crosstrack_angles.unchecked(nr) =
                    wcinfos.get_beam_crosstrack_angles().unchecked(beam_numbers[nr]);
        }

        return beam_crosstrack_angles;
    }

    xt::xtensor<float, 1> get_beam_alongtrack_angles(
        const pingtools::BeamSelection& selection) override
    {
        const auto beam_numbers = selection.get_beam_numbers();

        auto beam_alongtrack_angles = xt::xtensor<float, 1>::from_shape({ beam_numbers.size() });
        const auto& wcinfos         = get_wcinfos();
        const auto& wcidata         = wcinfos.get_water_column_datagram();
        const auto& transmit_sector_numbers = wcinfos.get_transmit_sector_numbers();

        std::vector<float> transmit_sector_angles;
        for (const auto& ts : wcidata.get_transmit_sectors())
            transmit_sector_angles.push_back(ts.get_tilt_angle_in_degrees());

        for (unsigned int nr = 0; nr < beam_numbers.size(); ++nr)
        {
            auto bn = beam_numbers[nr];
            if (bn >= wcinfos.get_beam_crosstrack_angles().size())
                beam_alongtrack_angles.unchecked(nr) = std::numeric_limits<float>::quiet_NaN();

            beam_alongtrack_angles[nr] = transmit_sector_angles[transmit_sector_numbers[bn]];
        }

        return beam_alongtrack_angles;
    }

    const xt::xtensor<uint16_t, 1>& get_start_range_sample_numbers()
    {
        return get_wcinfos().get_start_range_sample_numbers();
    }
    using t_base1::get_number_of_samples_per_beam;
    xt::xtensor<uint16_t, 1> get_number_of_samples_per_beam(
        const pingtools::BeamSelection& bs) override
    {
        xt::xtensor<uint16_t, 1> samples       = xt::empty<uint16_t>({ bs.get_number_of_beams() });
        const auto& number_of_samples_per_beam = get_wcinfos().get_number_of_samples_per_beam();
        const auto& beam_numbers               = bs.get_beam_numbers();

        for (unsigned int nr = 0; nr < beam_numbers.size(); ++nr)
        {
            auto bn = beam_numbers[nr];

            if (bn >= number_of_samples_per_beam.size())
                samples.unchecked(nr) = 0;
            else
                samples.unchecked(nr) = number_of_samples_per_beam.unchecked(bn);
        }
        return samples;
    }
    xt::xtensor<uint16_t, 1> get_first_sample_offset_per_beam() override
    {
        return get_wcinfos().get_start_range_sample_numbers();
    }
    const xt::xtensor<uint16_t, 1>& get_detected_range_in_samples()
    {
        return get_wcinfos().get_detected_range_in_samples();
    }
    const xt::xtensor<uint8_t, 1>& get_transmit_sector_numbers()
    {
        return get_wcinfos().get_transmit_sector_numbers();
    }
    const xt::xtensor<size_t, 1>& get_sample_positions()
    {
        return get_wcinfos().get_sample_positions();
    }

    // ----- I_PingWatercolumn interface -----
    // using t_base1::has_amplitudes;
    using t_base2::raw_data;

    bool has_amplitudes() const override
    {
        return raw_data()
                   .get_datagram_infos_by_type(t_EM3000DatagramIdentifier::WatercolumnDatagram)
                   .size() > 0;
    }

    bool has_bottom_range_samples() const override
    {
        // TODO: this is not true for datagrams in SonarMode!
        return has_amplitudes();
    }

    xt::xtensor<float, 2> get_amplitudes(const pingtools::BeamSampleSelection& selection) override
    {
        auto& wcinfos = get_wcinfos();

        auto amplitudes = xt::xtensor<float, 2>::from_shape(
            { selection.get_number_of_beams(), selection.get_number_of_samples_ensemble() });

        // samples.fill(std::numeric_limits<float>::quiet_NaN());
        size_t ensemble_offset = selection.get_first_sample_number_ensemble();

        size_t output_bn = 0;

        auto& ifs = _raw_data->get_ifs(t_EM3000DatagramIdentifier::WatercolumnDatagram);

        size_t local_output_bn = 0;
        for (const auto& bn : selection.get_beam_numbers())
        {
            // read amplitudes
            auto rsr = selection.get_read_sample_range(
                local_output_bn,
                wcinfos.get_start_range_sample_numbers().unchecked(bn),
                wcinfos.get_number_of_samples_per_beam().unchecked(bn));

            if (rsr.get_number_of_samples_to_read() > 0)
            {
                xt::xtensor<int8_t, 1> beam_amplitudes = wcinfos.read_beam_samples(bn, rsr, ifs);
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

    xt::xtensor<uint16_t, 1> get_bottom_range_samples(
        const pingtools::BeamSelection& selection) override
    {
        auto bottom_range_samples =
            xt::xtensor<uint16_t, 1>::from_shape({ selection.get_number_of_beams() });

        auto& range_samples         = get_wcinfos().get_detected_range_in_samples();
        auto  number_of_beams       = get_number_of_beams();
        auto& selected_beam_numbers = selection.get_beam_numbers();

        for (size_t i = 0; i < selected_beam_numbers.size(); ++i)
        {
            if (selected_beam_numbers[i] < number_of_beams)
                bottom_range_samples[i] = range_samples[selected_beam_numbers[i]];
            else
                bottom_range_samples[i] = 0;
        }

        return bottom_range_samples;
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->get_name(), float_precision);

        printer.append(t_base1::__printer__(float_precision));

        auto& wcinfos = get_wcinfos();

        printer.register_container("beam_crosstrack_angles", wcinfos.get_beam_crosstrack_angles());
        printer.register_container("start_range_sample_numbers",
                                   wcinfos.get_start_range_sample_numbers());
        printer.register_container("number_of_samples_per_bean",
                                   wcinfos.get_number_of_samples_per_beam());
        printer.register_container("detected_range_in_samples",
                                   wcinfos.get_detected_range_in_samples());
        printer.register_container("transmit_sector_numbers",
                                   wcinfos.get_transmit_sector_numbers());

        return printer;
    }
};

}
} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping