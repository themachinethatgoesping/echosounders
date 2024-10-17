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

#include <Eigen/Core>
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
    using t_base1 = filetemplates::datatypes::I_PingWatercolumn;
    using t_base2 = SimradRawPingCommon<t_ifstream>;

    using t_base2::_file_data;
    using typename t_base2::t_rawdata;

  protected:
    std::string class_name() const override { return "SimradRawPingWatercolumn"; }

  public:
    SimradRawPingWatercolumn(std::shared_ptr<t_rawdata> file_data)
        : t_base1()
        , t_base2(std::move(file_data))
    {
    }
    virtual ~SimradRawPingWatercolumn() = default;

    // --- sector infos ---
    xt::xtensor<size_t, 1> get_tx_sector_per_beam(
        const pingtools::BeamSelection& selection) override
    {
        this->beam_selection_must_be_one(__func__, selection);
        return { 0 };
    }

    std::vector<std::vector<size_t>> get_beam_numbers_per_tx_sector(
        const pingtools::BeamSelection& selection) override
    {
        this->beam_selection_must_be_one(__func__, selection);
        std::vector<std::vector<size_t>> beam_numbers_per_tx_sector(1);
        // beam_numbers_per_tx_sector[0].resize(1);
        // beam_numbers_per_tx_sector[0][0] = 0;
        return beam_numbers_per_tx_sector;
    }

    // ----- calibration -----
    bool has_watercolumn_calibration() const override
    {
        return _file_data->has_watercolumn_calibration();
    }

    const calibration::SimradRawWaterColumnCalibration& get_watercolumn_calibration() const
    {
        return _file_data->get_watercolumn_calibration();
    }

    // ----- I_PingWaterColumn interface -----
    bool has_tx_signal_parameters() const override { return true; }
    bool has_beam_crosstrack_angles() const override { return has_tx_signal_parameters(); }

    std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>
    get_tx_signal_parameters() const override
    {
        return { file_data().get_parameter().get_tx_signal_parameters() };
    }

    size_t get_number_of_tx_sectors() const override { return 1; }

    uint32_t get_number_of_beams() const override { return 1; }

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
    xt::xtensor<uint32_t, 1> get_number_of_samples_per_beam(
        const pingtools::BeamSelection& selection) override
    {
        this->beam_selection_must_be_one(__func__, selection);

        return { uint32_t(_file_data->get_ping_data().get_count()) };
    }
    xt::xtensor<uint32_t, 1> get_first_sample_offset_per_beam() override
    {
        return { uint32_t(_file_data->get_ping_data().get_offset()) };
    }
    // const xt::xtensor<uint32_t, 1>& get_detected_range_in_samples()
    // {
    //     return _file_data->get_wcinfos().get_detected_range_in_samples();
    // }
    const xt::xtensor<uint8_t, 1>& get_transmit_sector_numbers() { return { 0 }; }

    float get_sound_speed_at_transducer() override
    {
        // TODO: check if sound speed is available in the file
        //  if not, use the environment sound speed
        //  is environment sound speed always available? Is it a good replacement? Or better search
        //  for Soundvelocity profile?
        auto sound_speed = _file_data->get_parameter().SoundVelocity;
        if (sound_speed > 0)
            return sound_speed;
        return _file_data->get_environment().SoundSpeed;
    }

    float get_sample_interval() override { return _file_data->get_parameter().SampleInterval; }

    // ----- I_PingWatercolumn interface -----
    // using t_base1::has_amplitudes;
    using t_base2::file_data;

    bool has_amplitudes() const override { return file_data().has_power(); }

    bool has_bottom_range_samples() const override { return false; }

    xt::xtensor<float, 2> get_amplitudes(const pingtools::BeamSampleSelection& selection,
                                         [[maybe_unused]] int mp_cores = 1) override
    {
        this->beam_selection_must_be_one(__func__, selection);

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
            xt::view(amplitudes,
                     0, // beam number
                     xt::range(rsr.get_first_read_sample_offset() - ensemble_offset,
                               rsr.get_last_read_sample_offset() + 1 - ensemble_offset)) =
                xt::cast<float>(_file_data->read_sample_data(true));
        }

        return amplitudes;
    }

    void load(bool force = false) override
    {
        // load watercolumn calibration
        _file_data->init_watercolumn_calibration(force);
    }
    void release() override { _file_data->release_watercolumn_calibration(); }
    bool loaded() override
    {
        if (!_file_data->watercolumn_calibration_loaded())
            return false;

        return true;
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
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping