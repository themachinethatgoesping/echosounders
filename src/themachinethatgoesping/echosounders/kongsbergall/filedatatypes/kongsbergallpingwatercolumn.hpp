// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/kongsbergallpingwatercolumn.doc.hpp"

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
#include <xtensor/xadapt.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/algorithms/amplitudecorrection/functions.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>

#include "../../filetemplates/datatypes/i_pingwatercolumn.hpp"

#include "../datagrams.hpp"
#include "../types.hpp"

#include "kongsbergallpingcommon.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace filedatatypes {

template<typename t_ifstream>
class KongsbergAllPingWatercolumn
    : public filetemplates::datatypes::I_PingWatercolumn
    , public KongsbergAllPingCommon<t_ifstream>
{
  public:
    using t_base1 = filetemplates::datatypes::I_PingWatercolumn;
    using t_base2 = KongsbergAllPingCommon<t_ifstream>;

    using t_base2::_file_data;
    using typename t_base2::t_rawdata;

  protected:
    std::string class_name() const override { return "KongsbergAllPingWatercolumn"; }

  public:
    KongsbergAllPingWatercolumn(std::shared_ptr<t_rawdata> file_data)
        : t_base1()
        , t_base2(std::move(file_data))
    {
    }
    virtual ~KongsbergAllPingWatercolumn() = default;

    // --- sector infos ---

    bool has_tx_signal_parameters() const override
    {
        return _file_data->has_any_of_datagram_types(
            { t_KongsbergAllDatagramIdentifier::RawRangeAndAngle,
              t_KongsbergAllDatagramIdentifier::WatercolumnDatagram });
    }
    bool has_tx_sector_information() const override { return has_tx_signal_parameters(); }

    bool has_beam_crosstrack_angles() const override { return has_tx_signal_parameters(); }

    std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>
    get_tx_signal_parameters() override
    {
        return file_data().get_sysinfos().get_tx_signal_parameters();
    }

    size_t get_number_of_tx_sectors() override
    {
        return file_data().get_sysinfos().get_tx_signal_parameters().size();
    }

    xt::xtensor<size_t, 1> get_tx_sector_per_beam() override
    {
        return file_data().get_wcinfos().get_transmit_sector_numbers();
    }

    std::vector<std::vector<size_t>> get_beam_numbers_per_tx_sector() override
    {
        std::vector<std::vector<size_t>> beam_numbers_per_tx_sector;

        auto sector_per_beam = get_tx_sector_per_beam();

        for (unsigned int i = 0; i < sector_per_beam.size(); ++i)
        {
            if (sector_per_beam[i] >= beam_numbers_per_tx_sector.size())
                beam_numbers_per_tx_sector.resize(sector_per_beam[i] + 1);

            beam_numbers_per_tx_sector[sector_per_beam[i]].push_back(i);
        }

        return beam_numbers_per_tx_sector;
    }

    // ----- I_PingCommon interface -----
    void load(bool force = false) override
    {
        _file_data->load_wci(force);
        _file_data->load_sys(force);
    }
    void release() override
    {
        _file_data->release_wci();
        _file_data->release_sys();
    }
    bool loaded() override { return _file_data->wci_loaded() && _file_data->sys_loaded(); }

    uint32_t get_number_of_beams() override
    {
        if (!has_amplitudes())
            return 0;

        return _file_data->get_wcinfos().get_beam_crosstrack_angles().size();
    }

    // ----- getter/setters -----
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

    bool has_amplitudes() const override
    {
        return file_data()
                   .get_datagram_infos_by_type(
                       t_KongsbergAllDatagramIdentifier::WatercolumnDatagram)
                   .size() > 0;
    }

    bool has_bottom_range_samples() const override
    {
        // TODO: this is not true for datagrams in SonarMode!
        return has_amplitudes();
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

        // samples.fill(std::numeric_limits<float>::quiet_NaN());
        size_t ensemble_offset = selection.get_first_sample_number_ensemble();

        size_t output_bn = 0;

        auto& ifs = _file_data->get_ifs(t_KongsbergAllDatagramIdentifier::WatercolumnDatagram);

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
                    xt::cast<t_value>(beam_amplitudes);
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

    xt::xtensor<float, 2> get_amplitudes2() { return get_raw_amplitudes<float>() * 0.5f; }
    xt::xtensor<float, 2> get_amplitudes3() { return get_raw_amplitudes<int8_t>() * 0.5f; }
    xt::xtensor<float, 2> get_amplitudes4()
    {
        auto  selection = get_beam_sample_selection_all();
        auto& wcinfos   = _file_data->get_wcinfos();

        auto amplitudes = xt::xtensor<float, 2>::from_shape(
            { selection.get_number_of_beams(), selection.get_number_of_samples_ensemble() });

        // samples.fill(std::numeric_limits<float>::quiet_NaN());
        size_t ensemble_offset = selection.get_first_sample_number_ensemble();

        size_t output_bn = 0;

        auto& ifs = _file_data->get_ifs(t_KongsbergAllDatagramIdentifier::WatercolumnDatagram);

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
                    xt::cast<float>(beam_amplitudes) * 0.5f;
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
    xt::xtensor<float, 2> get_amplitudes5()
    {
        auto  selection = get_beam_sample_selection_all();
        auto& wcinfos   = _file_data->get_wcinfos();

        auto amplitudes = xt::xtensor<float, 2>::from_shape(
            { selection.get_number_of_beams(), selection.get_number_of_samples_ensemble() });

        // samples.fill(std::numeric_limits<float>::quiet_NaN());
        size_t ensemble_offset = selection.get_first_sample_number_ensemble();

        size_t output_bn = 0;

        auto& ifs = _file_data->get_ifs(t_KongsbergAllDatagramIdentifier::WatercolumnDatagram);

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
                    beam_amplitudes * 0.5f;
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
    xt::xtensor<float, 2> get_amplitudes(const pingtools::BeamSampleSelection& selection) override
    {
        auto& wcinfos = _file_data->get_wcinfos();

        auto amplitudes = xt::xtensor<float, 2>::from_shape(
            { selection.get_number_of_beams(), selection.get_number_of_samples_ensemble() });

        // samples.fill(std::numeric_limits<float>::quiet_NaN());
        size_t ensemble_offset = selection.get_first_sample_number_ensemble();

        size_t output_bn = 0;

        auto& ifs = _file_data->get_ifs(t_KongsbergAllDatagramIdentifier::WatercolumnDatagram);

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

    // xt::xtensor<float, 1> get_sample_correction(const pingtools::BeamSampleSelection& bs,
    //                                             bool apply_calibration)
    // {
    //     // get information
    //     float sound_velocity = get_sound_speed_at_transducer();

    //     // compute range factor (per sample)
    //     float tmp   = 20.f - get_tvg_factor_applied();
    //     float tmp_2 = sound_velocity * get_sample_interval() * 0.5f;

    //     xt::xtensor<float, 1> ranges = bs.get_sample_numbers_ensemble_1d() + 0.5f;
    //     ranges *= tmp_2; // here range factor ~ range

    //     xt::xtensor<float, 1> range_correction = xt::log10(ranges);
    //     range_correction *= tmp;

    //     if (apply_calibration)
    //         if (get_sv_calibration().has_offset_per_range())
    //         {
    //             // TODO: this copies the interpolator, maybe we can speed this up
    //             auto interpolator = get_sv_calibration().get_interpolator_offset_per_range();
    //             for (unsigned int r = 0; r < range_correction.size(); ++r)
    //                 range_correction[r] += interpolator(ranges[r]);
    //         }

    //     return range_correction;
    // }

    // xt::xtensor<float, 1> get_sector_correction(
    //     [[maybe_unused]] const pingtools::BeamSampleSelection& bs)
    // {
    //     // compute pulse factor (per sector)

    //     // get information
    //     // auto        tvg_offset        = get_tvg_offset();
    //     float       sound_velocity    = get_sound_speed_at_transducer();
    //     const auto& signal_parameters = file_data().get_sysinfos().get_tx_signal_parameters();

    //     xt::xtensor<float, 1> sector_correction = xt::empty<float>({ signal_parameters.size() });
    //     for (unsigned int si = 0; si < signal_parameters.size(); ++si)
    //     {
    //         const auto& sigparam  = signal_parameters[si];
    //         sector_correction[si] = tools::helper::visit_variant(
    //             sigparam,
    //             [sound_velocity](
    //                 const algorithms::signalprocessing::datastructures::CWSignalParameters&
    //                 param) { return std::log10(sound_velocity *
    //                 param.get_effective_pulse_duration() * 0.5f);
    //             },
    //             [sound_velocity]([[maybe_unused]] const algorithms::signalprocessing::
    //                                  datastructures::FMSignalParameters& param) {
    //                 // TODO: correct computation for FM?
    //                 return 0.f;
    //             },
    //             [sound_velocity]([[maybe_unused]] const algorithms::signalprocessing::
    //                                  datastructures::GenericSignalParameters& param) {
    //                 // TODO: throw warning?
    //                 // We cannot really compute this because we do not know if this is a CW or FM
    //                 // signal Furthermore, this usually happens if no rawrangeandanlges datagram
    //                 is
    //                 // present in this case also the effective_pulse_duration is not known for
    //                 each
    //                 // sector Here we thus do not correct for pulse length at all, but the user
    //                 // should be aware of this (TODO: warning?)
    //                 return 0.f;
    //             });
    //     }

    //     // adding tvg offset to the sector correction
    //     return sector_correction;
    // }

    // float get_system_correction() const { return -get_tvg_offset(); }

    // xt::xtensor<float, 2> get_corrected_amp(const pingtools::BeamSampleSelection& bs,
    //                                         bool apply_calibration)
    // {
    //     if (apply_calibration)
    //         if (!has_sv_calibration())
    //             throw std::runtime_error(
    //                 fmt::format("ERROR[{}]: No calibration available.", __func__));

    //     auto                  system_correction = get_system_correction();
    //     xt::xtensor<float, 1> sector_correction = get_sector_correction(bs);
    //     xt::xtensor<float, 1> sample_correction = get_sample_correction(
    //         bs, apply_calibration); // apply inside the function because range is needed

    //     if (apply_calibration)
    //         if (get_sv_calibration().has_system_offset())
    //             system_correction += get_sv_calibration().get_system_offset();

    //     // this is the same as adding system_correction to av later but faster
    //     sector_correction += system_correction;

    //     // compute beam correction (sector correction per beam)
    //     xt::xtensor<float, 1> beam_correction =
    //         xt::xtensor<float, 1>::from_shape({ bs.get_number_of_beams() });
    //     const auto& beam_numbers            = bs.get_beam_numbers();
    //     auto        sector_numbers_per_beam = get_tx_sector_per_beam();

    //     for (unsigned int bi = 0; bi < bs.get_number_of_beams(); ++bi)
    //     {
    //         beam_correction[bi] =
    //             sector_correction.at(sector_numbers_per_beam.at(beam_numbers[bi]));
    //     }

    //     if (apply_calibration)
    //         if (get_sv_calibration().has_offset_per_beamangle())
    //         {
    //             // TODO: this copies the interpolator, maybe we can speed this up
    //             auto interpolator = get_sv_calibration().get_interpolator_offset_per_beamangle();
    //             auto beam_angles  = get_beam_crosstrack_angles(bs);
    //             for (unsigned int bi = 0; bi < bs.get_number_of_beams(); ++bi)
    //             {
    //                 beam_correction[bi] += interpolator(beam_angles[bi]);
    //             }
    //         }

    //     return
    //     algorithms::amplitudecorrection::functions::apply_beam_sample_correction<xt::xtensor<float,2>,xt::xtensor<float,1>>(
    //         get_amplitudes(bs) * 0.5f, beam_correction, sample_correction);
    // }

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

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer(this->class_name(), float_precision);

        printer.append(t_base1::__printer__(float_precision));

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
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping