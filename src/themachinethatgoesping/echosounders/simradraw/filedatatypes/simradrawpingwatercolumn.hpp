// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/simradrawpingwatercolumn.doc.hpp"

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

#include "../datagrams.hpp"
#include "../types.hpp"

#include "simradrawpingcommon.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace filedatatypes {

template<typename t_ifstream>
class SimradRawPingWatercolumn
    : public filetemplates::datatypes::I_PingWatercolumn
    , public SimradRawPingCommon<t_ifstream>
{
  public:
    using t_base0 = filetemplates::datatypes::I_PingCommon;
    using t_base1 = filetemplates::datatypes::I_PingWatercolumn;
    using t_base2 = SimradRawPingCommon<t_ifstream>;

    using t_base2::_file_data;
    using typename t_base2::t_rawdata;

  protected:
    std::string class_name() const override { return "SimradRawPingWatercolumn"; }

  public:
    SimradRawPingWatercolumn(std::shared_ptr<t_rawdata> file_data)
        : t_base0() // necessary because of virtual inheritance
        , t_base1()
        , t_base2(std::move(file_data))
    {
    }
    virtual ~SimradRawPingWatercolumn() = default;

    // --- sector infos ---
    xt::xtensor<size_t, 1> get_tx_sector_per_beam() override
    {
        return { 0 };
    }

    std::vector<std::vector<size_t>> get_beam_numbers_per_tx_sector() override
    {
        return { { 0 } };
    }

    // ----- I_PingCommon interface -----

    uint16_t get_number_of_beams() override
    {
        return 1;
    }

    // ----- getter/setters -----
    xt::xtensor<float, 1> get_beam_crosstrack_angles(
        const pingtools::BeamSelection& selection) override
    {
        this->beam_selection_must_be_one(__func__, selection);

        return { 0 };
    }

    xt::xtensor<float, 1> get_beam_alongtrack_angles(
        const pingtools::BeamSelection& selection) override
    {
        this->beam_selection_must_be_one(__func__, selection);

        return { 0 };
    }

    using t_base1::get_number_of_samples_per_beam;
    xt::xtensor<uint16_t, 1> get_number_of_samples_per_beam(
        const pingtools::BeamSelection& selection) override
    {
        this->beam_selection_must_be_one(__func__, selection);

        return { _file_data->get_ping_data().get_count() };
    }
    xt::xtensor<uint16_t, 1> get_first_sample_offset_per_beam() override
    {
        return { _file_data->get_ping_data().get_offset() };
    }
    // const xt::xtensor<uint16_t, 1>& get_detected_range_in_samples()
    // {
    //     return _file_data->get_wcinfos().get_detected_range_in_samples();
    // }
    const xt::xtensor<uint8_t, 1>& get_transmit_sector_numbers() { return { 0 }; }

    float get_sound_speed_at_transducer() override
    {
        return _file_data->get_parameter().SoundVelocity;
    }

    float get_sample_interval() override { return _file_data->get_parameter().SampleInterval; }

    // ----- I_PingWatercolumn interface -----
    // using t_base1::has_amplitudes;
    using t_base2::file_data;

    bool has_amplitudes() const override { return file_data().has_power(); }

    bool has_bottom_range_samples() const override { return false; }

    xt::xtensor<float, 2> get_amplitudes(const pingtools::BeamSampleSelection& selection) override
    {
        this->beam_selection_must_be_one(__func__, selection);

        xt::xtensor<float, 1> sample_data = _file_data->read_sample_data(true);

        size_t ensemble_offset = selection.get_first_sample_number_ensemble();

        auto amplitudes =
            xt::xtensor<float, 2>::from_shape({ 1, selection.get_number_of_samples_ensemble() });

        // read amplitudes
        auto rsr = selection.get_read_sample_range(0 // beam number
                                                   ,
                                                   _file_data->get_ping_data().get_offset(),
                                                   _file_data->get_ping_data().get_count());

        if (rsr.get_number_of_samples_to_read() > 0)
        {
            xt::xtensor<float, 1> beam_amplitudes = _file_data->read_sample_data(true);
            xt::view(amplitudes,
                     0, // beam number
                     xt::range(rsr.get_first_read_sample_offset() - ensemble_offset,
                               rsr.get_last_read_sample_offset() + 1 - ensemble_offset)) =
                xt::cast<float>(beam_amplitudes);
        }

        return amplitudes;
    }

    // NOT yet implementer
    // xt::xtensor<float, 2> get_av(const pingtools::BeamSampleSelection& bs) override
    // {
    //     // get and convert amplitudes to dB
    //     xt::xtensor<float, 2> av         = get_amplitudes(bs) * 0.5f;
    //     auto                  tvg_offset = get_tvg_offset();

    //     // get information
    //     float sound_velocity = get_sound_speed_at_transducer();

    //     // compute range factor (per sample)
    //     float tmp   = get_tvg_factor_applied() - 20.f;
    //     float tmp_2 = sound_velocity * get_sample_interval() * 0.5f;

    //     xt::xtensor<float, 1> range_factor = bs.get_sample_numbers_ensemble_1d() + 0.5f;
    //     range_factor = tmp * xt::eval(xt::log10(xt::eval(range_factor * tmp_2)));

    //     // compute pulse factor (per beam)
    //     xt::xtensor<float, 1> pulse_factor =
    //         xt::xtensor<float, 1>::from_shape({ bs.get_number_of_beams() });
    //     auto        signal_parameters       = get_tx_signal_parameters();
    //     const auto& beam_numbers            = bs.get_beam_numbers();
    //     auto        sector_numbers_per_beam = get_tx_sector_per_beam();

    //     xt::xtensor<float, 1> pulse_factor_per_sector =
    //         xt::empty<float>({ signal_parameters.size() });
    //     for (unsigned int si = 0; si < signal_parameters.size(); ++si)
    //     {
    //         const auto& sigparam        = signal_parameters[si];
    //         pulse_factor_per_sector[si] = tools::helper::visit_variant(
    //             sigparam,
    //             [sound_velocity](
    //                 const algorithms::signalprocessing::datastructures::CWSignalParameters&
    //                 param) { return std::log10(sound_velocity * param.effective_pulse_duration *
    //                 0.5);
    //             },
    //             [sound_velocity](
    //                 const algorithms::signalprocessing::datastructures::FMSignalParameters&
    //                 param) {
    //                 // TODO: correct computation for FM?
    //                 return std::log10(sound_velocity * param.effective_pulse_duration * 0.5);
    //             },
    //             [sound_velocity](
    //                 const algorithms::signalprocessing::datastructures::GenericSignalParameters&
    //                     param) {
    //                 // TODO: throw warning?
    //                 return std::log10(sound_velocity * param.effective_pulse_duration * 0.5);
    //             });
    //     }

    //     // this is the same as substracting tvg_offset from av later but faster
    //     pulse_factor_per_sector += tvg_offset;

    //     for (unsigned int bi = 0; bi < bs.get_number_of_beams(); ++bi)
    //     {
    //         pulse_factor[bi] =
    //         pulse_factor_per_sector[sector_numbers_per_beam[beam_numbers[bi]]];
    //     }

    //     // TODO: speed up using graphics card?
    //     // // apply factors
    //     // range factor (here the broadcasting is faster than the loop)
    //     // for (unsigned int si = 0; si < range_factor.size(); ++si)
    //     //      xt::col(av, si) -= range_factor[si];

    //     av -= xt::view(range_factor, xt::newaxis(), xt::all());

    //     // pulse factor (here the loop is faster than broadcasting)
    //     for (unsigned int bi = 0; bi < bs.get_number_of_beams(); ++bi)
    //         xt::row(av, bi) -= pulse_factor.unchecked(bi);

    //     // av -= xt::view(pulse_factor, xt::all(), xt::newaxis());

    //     // return av - tvg_offset; // this is done earlier for speed
    //     return av;
    // }

    // NOT implementer
    // xt::xtensor<uint16_t, 1> get_bottom_range_samples(
    //     const pingtools::BeamSelection& selection) override
    // {
    //     auto bottom_range_samples =
    //         xt::xtensor<uint16_t, 1>::from_shape({ selection.get_number_of_beams() });

    //     auto& range_samples         = _file_data->get_wcinfos().get_detected_range_in_samples();
    //     auto  number_of_beams       = get_number_of_beams();
    //     auto& selected_beam_numbers = selection.get_beam_numbers();

    //     for (size_t i = 0; i < selected_beam_numbers.size(); ++i)
    //     {
    //         if (selected_beam_numbers[i] < number_of_beams)
    //             bottom_range_samples[i] = range_samples[selected_beam_numbers[i]];
    //         else
    //             bottom_range_samples[i] = 0;
    //     }

    //     return bottom_range_samples;
    // }

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
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping