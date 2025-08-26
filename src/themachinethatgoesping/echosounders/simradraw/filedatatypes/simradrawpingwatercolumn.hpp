// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/simradrawpingwatercolumn.doc.hpp"

/* std includes */
#include <memory>
#include <vector>

// xtensor includes  
#include <xtensor/containers/xadapt.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>


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
        const pingtools::BeamSelection& selection) override;

    std::vector<std::vector<size_t>> get_beam_numbers_per_tx_sector(
        const pingtools::BeamSelection& selection) override;

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
    get_tx_signal_parameters() const override;

    size_t get_number_of_tx_sectors() const override { return 1; }

    uint32_t get_number_of_beams() const override { return 1; }

    // ----- getter/setters -----
    xt::xtensor<float, 1> get_beam_crosstrack_angles(
        const pingtools::BeamSelection& selection) override;

    xt::xtensor<float, 1> get_beam_alongtrack_angles(
        const pingtools::BeamSelection& selection) override;

    using t_base1::get_number_of_samples_per_beam;
    xt::xtensor<uint32_t, 1> get_number_of_samples_per_beam(
        const pingtools::BeamSelection& selection) override;
        
    xt::xtensor<uint32_t, 1> get_first_sample_offset_per_beam() override;
    
    const xt::xtensor<uint8_t, 1>& get_transmit_sector_numbers();

    float get_sound_speed_at_transducer() override;

    float get_sample_interval() override;

    // ----- I_PingWatercolumn interface -----
    // using t_base1::has_amplitudes;
    using t_base2::file_data;

    bool has_amplitudes() const override { return file_data().has_power(); }

    bool has_bottom_range_samples() const override { return false; }

    xt::xtensor<float, 2> get_amplitudes(const pingtools::BeamSampleSelection& selection,
                                         [[maybe_unused]] int mp_cores = 1) override;

    void load(bool force = false) override;
    void release() override;
    bool loaded() override;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;
};

}
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping