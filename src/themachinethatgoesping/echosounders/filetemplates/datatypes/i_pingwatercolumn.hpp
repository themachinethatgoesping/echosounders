/**
 * @brief Interface for all ping watercolumn functions
 *
 * This interface provides functions for accessing and manipulating ping watercolumn data.
 * It includes methods for retrieving beam selection, beam angles, sample intervals, amplitudes,
 * and bottom range samples.
 */
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/i_pingwatercolumn.doc.hpp"

/* std includes */
#include <cstdint>
#include <functional>
#include <map>
#include <string>
#include <vector>

#include <boost/flyweight.hpp>

// xtensor includes
#include <xtensor/containers/xadapt.hpp>
#include <xtensor/views/xview.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/algorithms/amplitudecorrection/functions.hpp>
#include <themachinethatgoesping/algorithms/signalprocessing/datastructures.hpp>
#include <themachinethatgoesping/navigation/navigationinterpolatorlatlon.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../../pingtools/beamsampleselection.hpp"
#include "i_pingcommon.hpp"

#include "calibration/multisectorwatercolumncalibration.hpp"
#include "calibration/watercolumncalibration.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datatypes {

/**
 * @brief Interface for all ping watercolumn functions
 *
 */
/**
 * @class I_PingWatercolumn
 * @brief Interface for watercolumn ping data.
 *
 * This class represents an interface for accessing watercolumn ping data. It inherits from the
 * I_PingCommon class and provides additional functions and variables specific to watercolumn pings.
 */
class I_PingWatercolumn : public I_PingCommon
{
    bool _beam_sample_selection_all_is_initialized = false;
    boost::flyweight<pingtools::BeamSampleSelection> _beam_sample_selection_all;

  protected:
    std::string class_name() const override;

  public:
    using t_base = I_PingCommon;

    I_PingWatercolumn();
    ~I_PingWatercolumn() override;

    std::map<t_pingfeature, std::function<bool()>> primary_feature_functions() const override;
    std::map<t_pingfeature, std::function<bool()>> secondary_feature_functions() const override;
    std::map<t_pingfeature, std::function<bool()>> feature_group_functions() const override;

    virtual bool has_tx_signal_parameters() const;
    virtual bool has_number_of_tx_sectors() const;
    virtual bool has_beam_numbers_per_tx_sector() const;
    virtual bool has_tx_sector_per_beam() const;

    bool         has_beam_selection_all() const;
    virtual bool has_number_of_beams() const;
    virtual bool has_beam_crosstrack_angles() const;

    virtual bool has_watercolumn_calibration() const;
    virtual bool has_multisectorwatercolumn_calibration() const;
    virtual bool has_bottom_range_samples() const;
    virtual bool has_amplitudes() const;

    bool has_ap() const;
    bool has_av() const;
    bool has_power() const;
    bool has_rp() const;
    bool has_rv() const;
    bool has_pp() const;
    bool has_pv() const;
    bool has_sp() const;
    bool has_sv() const;

    virtual std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>
                   get_tx_signal_parameters() const;
    virtual size_t get_number_of_tx_sectors() const;

    virtual const calibration::WaterColumnCalibration& get_watercolumn_calibration() const;
    const calibration::WaterColumnCalibration& get_watercolumn_calibration(size_t sector_nr) const;
    virtual const calibration::I_MultiSectorCalibration& get_multisectorwatercolumn_calibration()
        const;

    virtual float get_sample_interval();

    xt::xtensor<size_t, 1>         get_tx_sector_per_beam();
    virtual xt::xtensor<size_t, 1> get_tx_sector_per_beam(const pingtools::BeamSelection& bs);

    std::vector<std::vector<size_t>>         get_beam_numbers_per_tx_sector();
    virtual std::vector<std::vector<size_t>> get_beam_numbers_per_tx_sector(
        const pingtools::BeamSelection& bs);

    pingtools::BeamSelection get_beam_selection_all();
    virtual uint32_t         get_number_of_beams() const;

    xt::xtensor<float, 1>         get_beam_crosstrack_angles();
    virtual xt::xtensor<float, 1> get_beam_crosstrack_angles(const pingtools::BeamSelection& bs);

    xt::xtensor<float, 1>         get_beam_alongtrack_angles();
    virtual xt::xtensor<float, 1> get_beam_alongtrack_angles(const pingtools::BeamSelection& bs);

    virtual xt::xtensor<uint32_t, 1> get_first_sample_offset_per_beam();

    xt::xtensor<uint32_t, 1>         get_number_of_samples_per_beam();
    virtual xt::xtensor<uint32_t, 1> get_number_of_samples_per_beam(
        const pingtools::BeamSelection& bs);

    virtual float get_sound_speed_at_transducer();

    xt::xtensor<float, 1> get_approximate_ranges(const pingtools::BeamSampleSelection& selection);
    xt::xtensor<float, 1> get_approximate_ranges();

    const pingtools::BeamSampleSelection& get_beam_sample_selection_all();

    xt::xtensor<float, 2> get_amplitudes(int mp_cores = 1);
    xt::xtensor<float, 2> get_ap(int mp_cores = 1);
    xt::xtensor<float, 2> get_av(int mp_cores = 1);
    xt::xtensor<float, 2> get_rp(int mp_cores = 1);
    xt::xtensor<float, 2> get_rv(int mp_cores = 1);
    xt::xtensor<float, 2> get_pp(int mp_cores = 1);
    xt::xtensor<float, 2> get_pv(int mp_cores = 1);
    xt::xtensor<float, 2> get_power(int mp_cores = 1);
    xt::xtensor<float, 2> get_sp(int mp_cores = 1);
    xt::xtensor<float, 2> get_sv(int mp_cores = 1);

    virtual xt::xtensor<float, 2> get_amplitudes(const pingtools::BeamSampleSelection& selection,
                                                 int mp_cores = 1);
    xt::xtensor<float, 2> get_rp(const pingtools::BeamSampleSelection& selection, int mp_cores = 1);
    virtual xt::xtensor<float, 2> get_rv(const pingtools::BeamSampleSelection& selection,
                                         int                                   mp_cores = 1);
    xt::xtensor<float, 2> get_pp(const pingtools::BeamSampleSelection& selection, int mp_cores = 1);
    virtual xt::xtensor<float, 2> get_pv(const pingtools::BeamSampleSelection& selection,
                                         int                                   mp_cores = 1);
    xt::xtensor<float, 2> get_ap(const pingtools::BeamSampleSelection& selection, int mp_cores = 1);
    virtual xt::xtensor<float, 2> get_av(const pingtools::BeamSampleSelection& selection,
                                         int                                   mp_cores = 1);
    virtual xt::xtensor<float, 2> get_power(const pingtools::BeamSampleSelection& selection,
                                            int                                   mp_cores = 1);
    virtual xt::xtensor<float, 2> get_sp(const pingtools::BeamSampleSelection& selection,
                                         int                                   mp_cores = 1);
    virtual xt::xtensor<float, 2> get_sv(const pingtools::BeamSampleSelection& selection,
                                         int                                   mp_cores = 1);

    int  _test_mode = 0;
    void set_test_mode(int test_test_mode);
    int  get_test_mode();

    xt::xtensor<float, 2> get_wci_correction(
        const calibration::o_calibration_type calibration1,
        const calibration::o_calibration_type calibration_base =
            calibration::t_calibration_type::power,
        int mp_cores = 1);

    template<calibration::WaterColumnCalibration::t_calibration_type calibration_type>
    xt::xtensor<float, 2> get_wci_correction(const pingtools::BeamSampleSelection& selection,
                                             int                                   mp_cores = 1)
    {
        auto amplitudes = xt::xtensor<float, 2>::from_shape(
            { selection.get_number_of_beams(),
              size_t(selection.get_number_of_samples_ensemble()) });
        amplitudes.fill(0.0f);

        if (this->get_number_of_tx_sectors() == 1)
        {
            get_watercolumn_calibration().template inplace_beam_sample_correction<calibration_type>(
                amplitudes,
                get_beam_crosstrack_angles(selection),
                get_approximate_ranges(selection),
                mp_cores);
        }
        else
        {
            get_multisectorwatercolumn_calibration()
                .template inplace_beam_sample_correction<calibration_type>(
                    amplitudes,
                    get_beam_crosstrack_angles(selection),
                    get_approximate_ranges(selection),
                    get_beam_numbers_per_tx_sector(selection),
                    mp_cores);
        }

        return amplitudes;
    }

    xt::xtensor<float, 2> get_wci_correction(
        const pingtools::BeamSampleSelection& selection,
        const calibration::o_calibration_type calibration1,
        const calibration::o_calibration_type calibration_base =
            calibration::t_calibration_type::power,
        int mp_cores = 1);

    xt::xtensor<float, 2> get_wci(const calibration::o_calibration_type calibration_type,
                                  int                                   mp_cores = 1);

    xt::xtensor<float, 2> get_wci(const pingtools::BeamSampleSelection& selection,
                                  const calibration::o_calibration_type calibration_type,
                                  int                                   mp_cores = 1);

    template<calibration::WaterColumnCalibration::t_calibration_type calibration_type>
    xt::xtensor<float, 2> get_calibrated_wci(const pingtools::BeamSampleSelection& selection,
                                             int                                   mp_cores = 1)
    {
        if (this->get_number_of_tx_sectors() == 1)
            switch (_test_mode)
            {
                case 1: {
                    auto amp = get_amplitudes(selection);
                    get_watercolumn_calibration()
                        .template inplace_beam_sample_correction<calibration_type>(
                            amp,
                            get_beam_crosstrack_angles(selection),
                            get_approximate_ranges(selection),
                            mp_cores);
                    return amp;
                }
                default:
                    return get_watercolumn_calibration()
                        .template apply_beam_sample_correction<calibration_type>(
                            get_amplitudes(selection),
                            get_beam_crosstrack_angles(selection),
                            get_approximate_ranges(selection),
                            mp_cores);
            }

        switch (_test_mode)
        {
            case 1:
                return get_multisectorwatercolumn_calibration()
                    .template apply_beam_sample_correction<calibration_type>(
                        get_amplitudes(selection),
                        get_beam_crosstrack_angles(selection),
                        get_approximate_ranges(selection),
                        get_beam_numbers_per_tx_sector(selection),
                        mp_cores);
            case 2:
                return get_watercolumn_calibration(0)
                    .template apply_beam_sample_correction<calibration_type>(
                        get_amplitudes(selection),
                        get_beam_crosstrack_angles(selection),
                        get_approximate_ranges(selection),
                        mp_cores);
            case 3: {
                auto amp = get_amplitudes(selection);
                get_watercolumn_calibration(0)
                    .template inplace_beam_sample_correction<calibration_type>(
                        amp,
                        get_beam_crosstrack_angles(selection),
                        get_approximate_ranges(selection),
                        mp_cores);
                return amp;
            }
            default: {
                auto amp = get_amplitudes(selection);
                get_multisectorwatercolumn_calibration()
                    .template inplace_beam_sample_correction<calibration_type>(
                        amp,
                        get_beam_crosstrack_angles(selection),
                        get_approximate_ranges(selection),
                        get_beam_numbers_per_tx_sector(selection),
                        mp_cores);
                return amp;
            }
        }
    }

    virtual xt::xtensor<uint32_t, 1> get_bottom_range_samples();
    virtual xt::xtensor<uint32_t, 1> get_bottom_range_samples(
        const pingtools::BeamSelection& selection);

    uint32_t get_minslant_sample_nr();
    uint32_t get_minslant_sample_nr(const pingtools::BeamSelection& selection);

    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};
}
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping