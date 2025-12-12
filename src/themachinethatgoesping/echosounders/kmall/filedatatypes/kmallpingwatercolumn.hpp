// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/kmallpingwatercolumn.doc.hpp"

/* std includes */
#include <filesystem>
#include <fstream>
#include <memory>
#include <unordered_map>
#include <vector>

#include <fmt/core.h>

#include <Eigen/Core>
#include <boost/flyweight.hpp>

// xtensor includes
#include <xtensor/containers/xadapt.hpp>

#include <xtensor/views/xindex_view.hpp>

#include <xtensor/views/xview.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/algorithms/amplitudecorrection/functions.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../../filetemplates/datatypes/i_pingwatercolumn.hpp"

#include "../datagrams.hpp"
#include "../types.hpp"

#include "kmallpingcommon.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace filedatatypes {

template<typename t_ifstream>
class KMALLPingWatercolumn
    : public filetemplates::datatypes::I_PingWatercolumn
    , public KMALLPingCommon<t_ifstream>
{
  public:
    using t_base1 = filetemplates::datatypes::I_PingWatercolumn;
    using t_base2 = KMALLPingCommon<t_ifstream>;

    using t_base2::_file_data;
    using typename t_base2::t_rawdata;

  protected:
    std::string class_name() const override { return "KMALLPingWatercolumn"; }

  public:
    KMALLPingWatercolumn(std::shared_ptr<t_rawdata> file_data)
        : t_base1()
        , t_base2(std::move(file_data))
    {
    }
    virtual ~KMALLPingWatercolumn() = default;

    // --- sector infos ---

    bool has_tx_signal_parameters() const override
    {
        return _file_data->has_any_of_datagram_types({ t_KMALLDatagramIdentifier::M_RANGE_AND_DEPTH,
                                                       t_KMALLDatagramIdentifier::M_WATER_COLUMN });
    }
    bool has_number_of_tx_sectors() const { return has_tx_signal_parameters(); }
    bool has_beam_numbers_per_tx_sector() const { return has_tx_signal_parameters(); }
    bool has_tx_sector_per_beam() const { return has_tx_signal_parameters(); }
    bool has_number_of_beams() const { return has_tx_signal_parameters(); }

    bool has_beam_crosstrack_angles() const override { return has_tx_signal_parameters(); }

    std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>
    get_tx_signal_parameters() const override
    {
        return this->file_data().get_sysinfos_const().get_tx_signal_parameters();
    }

    size_t get_number_of_tx_sectors() const override
    {
        return this->file_data().get_sysinfos_const().get_tx_signal_parameters().size();
    }

    xt::xtensor<size_t, 1> get_tx_sector_per_beam(
        const pingtools::BeamSelection& selection) override
    {
        return xt::index_view(file_data().get_wcinfos().get_transmit_sector_numbers(),
                              selection.get_beam_numbers());
    }

    std::vector<std::vector<size_t>> get_beam_numbers_per_tx_sector(
        const pingtools::BeamSelection& selection) override
    {
        std::vector<std::vector<size_t>> beam_numbers_per_tx_sector;
        beam_numbers_per_tx_sector.resize(get_number_of_tx_sectors());

        auto sector_per_beam = get_tx_sector_per_beam(selection);

        for (unsigned int i = 0; i < sector_per_beam.size(); ++i)
        {
            if (sector_per_beam[i] >= beam_numbers_per_tx_sector.size())
                throw std::runtime_error(
                    fmt::format("Invalid transmit sector number: {}", sector_per_beam[i]));

            beam_numbers_per_tx_sector[sector_per_beam[i]].push_back(i);
        }

        return beam_numbers_per_tx_sector;
    }

    // // ----- I_PingCommon interface -----
    void load(bool force = false) override
    {
        _file_data->load_wci(force);
        _file_data->load_sys(force);
        _file_data->init_watercolumn_calibration(force);
    }
    void release() override
    {
        _file_data->release_wci();
        _file_data->release_sys();
    }
    bool loaded() override
    {
        return _file_data->wci_loaded() && _file_data->sys_loaded() &&
               _file_data->has_watercolumn_calibration();
    }

    uint32_t get_number_of_beams() const override
    {
        if (!has_amplitudes())
            return 0;

        return _file_data->get_wcinfos_const().get_beam_crosstrack_angles().size();
    }

    // // ----- getter/setters -----
    xt::xtensor<float, 1> get_beam_crosstrack_angles(
        const pingtools::BeamSelection& selection) override
    {
        const auto beam_numbers = selection.get_beam_numbers();

        auto beam_crosstrack_angles = xt::xtensor<float, 1>::from_shape({ beam_numbers.size() });
        const auto& wcinfos         = _file_data->get_wcinfos();

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
        const auto& wcinfos         = _file_data->get_wcinfos();
        const auto& transmit_sector_numbers = wcinfos.get_transmit_sector_numbers();

        std::vector<float> transmit_sector_angles;
        for (const auto& ts : wcinfos.get_transmit_sectors())
            transmit_sector_angles.push_back(ts.get_tilt_angle_re_tx_deg());

        for (unsigned int nr = 0; nr < beam_numbers.size(); ++nr)
        {
            auto bn = beam_numbers[nr];
            if (bn >= wcinfos.get_beam_crosstrack_angles().size())
                beam_alongtrack_angles.unchecked(nr) = std::numeric_limits<float>::quiet_NaN();

            beam_alongtrack_angles[nr] = transmit_sector_angles[transmit_sector_numbers[bn]];
        }

        return beam_alongtrack_angles;
    }

    const xt::xtensor<uint32_t, 1>& get_start_range_sample_numbers()
    {
        return _file_data->get_wcinfos().get_start_range_sample_numbers();
    }
    using t_base1::get_number_of_samples_per_beam;
    xt::xtensor<uint32_t, 1> get_number_of_samples_per_beam(
        const pingtools::BeamSelection& bs) override
    {
        xt::xtensor<uint32_t, 1> samples = xt::empty<uint32_t>({ bs.get_number_of_beams() });
        const auto&              number_of_samples_per_beam =
            _file_data->get_wcinfos().get_number_of_samples_per_beam();
        const auto& beam_numbers = bs.get_beam_numbers();

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
    xt::xtensor<uint32_t, 1> get_first_sample_offset_per_beam() override
    {
        return _file_data->get_wcinfos().get_start_range_sample_numbers();
    }
    const xt::xtensor<uint32_t, 1>& get_detected_range_in_samples()
    {
        return _file_data->get_wcinfos().get_detected_range_in_samples();
    }
    const xt::xtensor<float, 1>& get_detected_range_in_samples_high_resolution()
    {
        return _file_data->get_wcinfos().get_detected_range_in_samples_high_resolution();
    }
    const xt::xtensor<uint8_t, 1>& get_transmit_sector_numbers()
    {
        return _file_data->get_wcinfos().get_transmit_sector_numbers();
    }
    const xt::xtensor<size_t, 1>& get_sample_positions()
    {
        return _file_data->get_wcinfos().get_sample_positions();
    }

    float get_sound_speed_at_transducer() override
    {
        return _file_data->get_wcinfos().get_sound_speed_at_transducer();
    }

    float get_sample_interval() override { return _file_data->get_wcinfos().get_sample_interval(); }

    uint8_t get_tvg_factor_applied() const
    {
        return _file_data->get_wcinfos().get_tvg_factor_applied();
    }
    int8_t get_tvg_offset() const { return _file_data->get_wcinfos().get_tvg_offset_in_db(); }

    // ----- I_PingWatercolumn interface -----
    // using t_base1::has_amplitudes;
    using t_base2::file_data;

    bool has_raw_amplitudes() const
    {
        return file_data()
                   .get_datagram_infos_by_type(t_KMALLDatagramIdentifier::M_WATER_COLUMN)
                   .size() > 0;
    }

    bool has_amplitudes() const override { return has_raw_amplitudes(); }

    bool has_bottom_range_samples() const override
    {
        // TODO: this is not true for datagrams in SonarMode!
        return has_amplitudes();
    }

    bool has_watercolumn_calibration() const override
    {
        return _file_data->has_watercolumn_calibration() && get_number_of_tx_sectors() == 1;
    }

    bool has_multisectorwatercolumn_calibration() const override
    {
        // KMALL has water column calibration
        return _file_data->has_watercolumn_calibration();
    }

    template<typename t_value>
    xt::xtensor<t_value, 2> get_raw_amplitudes()
    {
        return get_raw_amplitudes<t_value>(get_beam_sample_selection_all());
    }

    template<typename t_value>
    xt::xtensor<t_value, 2> get_raw_amplitudes(const pingtools::BeamSampleSelection& selection)
    {
        auto& wcinfos = _file_data->get_wcinfos();

        auto amplitudes = xt::xtensor<t_value, 2>::from_shape(
            { selection.get_number_of_beams(), selection.get_number_of_samples_ensemble() });

        if constexpr (std::is_floating_point_v<t_value>)
            amplitudes.fill(std::numeric_limits<t_value>::quiet_NaN());
        else
            amplitudes.fill(std::numeric_limits<t_value>::min());

        size_t ensemble_offset = selection.get_first_sample_number_ensemble();

        size_t output_bn = 0;

        auto& ifs = _file_data->get_ifs(t_KMALLDatagramIdentifier::M_WATER_COLUMN);

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
                xt::view(amplitudes,
                         output_bn,
                         xt::range(rsr.get_first_read_sample_offset() - ensemble_offset,
                                   rsr.get_last_read_sample_offset() + 1 - ensemble_offset)) =
                    wcinfos.read_beam_samples(bn, rsr, ifs);
            }

            ++local_output_bn;
            ++output_bn;
        }

        return amplitudes;
    }

    xt::xtensor<float, 2> get_amplitudes(const pingtools::BeamSampleSelection& bs,
                                         [[maybe_unused]] int mp_cores = 1) override
    {
        // note: use float because we want to return NaN for missing data
        return get_raw_amplitudes<float>(bs) * 0.5f;
    }

    xt::xtensor<uint32_t, 1> get_bottom_range_samples(
        const pingtools::BeamSelection& selection) override
    {
        auto bottom_range_samples =
            xt::xtensor<uint32_t, 1>::from_shape({ selection.get_number_of_beams() });

        auto& range_samples         = _file_data->get_wcinfos().get_detected_range_in_samples();
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

    const calibration::KMALLMultiSectorWaterColumnCalibration&
    get_multisectorwatercolumn_calibration() const override
    {
        return _file_data->get_multisector_calibration();
    }

    const calibration::KMALLWaterColumnCalibration& get_watercolumn_calibration() const
    {
        return _file_data->get_watercolumn_calibration();
    }

    void update_calibration(
        const boost::flyweight<calibration::KMALLMultiSectorWaterColumnCalibration>&
            calibration)
    {
        _file_data->update_calibration(calibration);
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            this->class_name(), float_precision, superscript_exponents);

        printer.append(t_base1::__printer__(float_precision, superscript_exponents));

        auto& wcinfos = _file_data->get_wcinfos();

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
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping