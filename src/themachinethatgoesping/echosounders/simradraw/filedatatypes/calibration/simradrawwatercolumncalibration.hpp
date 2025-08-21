// SPDX-FileCopyrightText: 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/simradrawwatercolumncalibration.doc.hpp"

#include <fmt/core.h>
#include <xtensor/containers/xtensor.hpp> // for xt::xtensor<float, 1>

#include <themachinethatgoesping/algorithms/amplitudecorrection/functions.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/helper/floatcompare.hpp>

#include "../../../filetemplates/datatypes/calibration/multisectorwatercolumncalibration.hpp"
#include "../../../filetemplates/datatypes/calibration/watercolumncalibration.hpp"
#include "../../datagrams.hpp"
#include "../sub/transceiverinformation.hpp"
#include "functions.hpp"

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace filedatatypes {
namespace calibration {

/** TODO: Check the range correction
 * - implement correct sound speed / sound velocity profile
 * - check range computation (beginning or middle of sample?)
 * - chack TVG range correction
 *     - Echopype implements the following (mod is substracted from the range)
 *          - mod_ek60 = float(2 * beam["sample_interval"] * ds_Sv['sound_speed'] / 2)
 *          - mod_ek80 = float(ds_Sv['sound_speed'] * beam["transmit_duration_nominal"] / 4)
 *          - mod_ek80_gpt = mod_ek60 + mod_ek80
 */

/** TODO: check effective pulse length
 * - for power/angle data, do I only use the nominal pulse length?
 */

class SimradRawWaterColumnCalibration
    : public filetemplates::datatypes::calibration::WaterColumnCalibration
{
    using AmplitudeCalibration = filetemplates::datatypes::calibration::AmplitudeCalibration;
    using t_base               = filetemplates::datatypes::calibration::WaterColumnCalibration;

  protected:
    using WaterColumnCalibration::set_absorption_db_m;

  protected:
    // transducer parameters
    float _transducer_gain_db       = std::numeric_limits<float>::quiet_NaN();
    float _sa_correction_db         = std::numeric_limits<float>::quiet_NaN();
    float _equivalent_beam_angle_db = std::numeric_limits<float>::quiet_NaN();
    float _frequency_nominal_hz     = std::numeric_limits<float>::quiet_NaN();

    // derived from environment
    float _reference_depth_m = std::numeric_limits<float>::quiet_NaN();
    float _temperature_c     = std::numeric_limits<float>::quiet_NaN();
    float _salinity_psu      = std::numeric_limits<float>::quiet_NaN();
    float _acidity_ph        = std::numeric_limits<float>::quiet_NaN();

    // derived from parameters
    float _frequency_hz             = std::numeric_limits<float>::quiet_NaN();
    float _transmit_power_w         = std::numeric_limits<float>::quiet_NaN();
    float _nominal_pulse_duration_s = std::numeric_limits<float>::quiet_NaN();
    float _slope_factor             = std::numeric_limits<float>::quiet_NaN();
    float _sample_interval_s        = std::numeric_limits<float>::quiet_NaN();

    // computed
    float _computed_sound_velocity_m_s            = std::numeric_limits<float>::quiet_NaN();
    float _computed_absorption_db_m               = std::numeric_limits<float>::quiet_NaN();
    float _wavelength_m                           = std::numeric_limits<float>::quiet_NaN();
    float _corr_transducer_gain_db                = std::numeric_limits<float>::quiet_NaN();
    float _corr_equivalent_beam_angle_db          = std::numeric_limits<float>::quiet_NaN();
    float _computed_effective_pulse_duration_s    = std::numeric_limits<float>::quiet_NaN();
    float _computed_internal_sampling_interval_hz = 1.5e6; // fixed / in seconds

    // filter parameters
    int16_t _filter_stage_1_decimation_factor = -1; ///< decimation factor of stage 1 filter
    int16_t _filter_stage_2_decimation_factor = -1; ///< decimation
    xt::xtensor<std::complex<float>, 1>
        _filter_stage_1_coefficients; ///< filter coefficients of stage 1 filter
    xt::xtensor<std::complex<float>, 1>
        _filter_stage_2_coefficients; ///< filter coefficients of stage 2 filter

    // power calibration parameters
    std::optional<size_t>
        _n_complex_samples; /// This parameter is NOT optional, if no value is set, the calibration
                            /// is not yet valid. Set to 0 when working working with power/angle
                            /// data. If >0, this calibration includes a correction for the
                            /// impedance factor to translate the complex amplitudes to power
                            /// applying this calibration to data which does not match
                            /// n_complex_samples will result in incorrect power values
    std::optional<float> _power_conversion_factor_db =
        std::nullopt; // used for computing power from complex 32 bit samples

    // optional paramters
    std::optional<float> _rounded_latitude_deg =
        std::nullopt; // derived from position, used for computing sound velocity
    std::optional<float> _rounded_longitude_deg =
        std::nullopt; // derived from position, used for computing sound velocity

    std::optional<float> _forced_sound_velocity_m_s         = std::nullopt;
    std::optional<float> _forced_absorption_db_m            = std::nullopt;
    std::optional<float> _forced_effective_pulse_duration_s = std::nullopt;

    bool _initialized = false;

  public:
    SimradRawWaterColumnCalibration();
    SimradRawWaterColumnCalibration(const t_base& other);
    SimradRawWaterColumnCalibration(
        const datagrams::xml_datagrams::XML_Environment&       environment,
        const datagrams::xml_datagrams::XML_Parameter_Channel& parameters,
        const _sub::TransceiverInformation&                    transceiver_information,
        const std::pair<datagrams::FIL1, datagrams::FIL1>&     filter_stages,
        size_t                                                 n_complex_samples);

    void set_transducer_parameters(
        const datagrams::xml_datagrams::XMLConfigurationTransceiverChannelTransducer& transducer,
        size_t pulse_duration_index);
    void set_transducer_parameters(float transducer_gain_db,
                                   float sa_correction_db,
                                   float equivalent_beam_angle_db,
                                   float frequency_nominal_hz);

    void set_environment_parameters(const datagrams::xml_datagrams::XML_Environment& environment);
    void set_environment_parameters(float reference_depth_m,
                                    float temperature_c,
                                    float salinity_psu,
                                    float acidity_ph = 8.06f);
    void set_environment_parameters(float forced_sound_velocity_m_s, float forced_absorption_db_m);

    void set_runtime_parameters(const datagrams::xml_datagrams::XML_Parameter_Channel& parameters);
    void set_runtime_parameters(float frequency_hz,
                                float transmit_power_w,
                                float nominal_pulse_duration_s,
                                float slope_factor,
                                float sample_interval_s);

    void set_filter_parameters(const std::pair<datagrams::FIL1, datagrams::FIL1>& filter_stages);
    void set_filter_parameters(int16_t                                    stage1_decimation_factor,
                               const xt::xtensor<std::complex<float>, 1>& stage1_coefficients,
                               int16_t                                    stage2_decimation_factor,
                               const xt::xtensor<std::complex<float>, 1>& stage2_coefficients);

    void set_power_calibration_parameters(size_t               n_complex_samples,
                                          std::optional<float> impedance_factor = std::nullopt);

    void set_optional_parameters(std::optional<float> rounded_latitude_deg  = std::nullopt,
                                 std::optional<float> rounded_longitude_deg = std::nullopt);

    void force_sound_velocity_m_s(std::optional<float> forced_sound_velocity_m_s);
    void force_absorption_db_m(std::optional<float> forced_absorption_db_m);
    void force_effective_pulse_duration_s(std::optional<float> forced_effective_pulse_duration_s);

    // trivial getters remain inline
    float get_transducer_gain_db() const { return _transducer_gain_db; }
    float get_sa_correction_db() const { return _sa_correction_db; }
    float get_equivalent_beam_angle_db() const { return _equivalent_beam_angle_db; }
    float get_frequency_nominal_hz() const { return _frequency_nominal_hz; }

    float get_reference_depth_m() const { return _reference_depth_m; }
    float get_temperature_c() const { return _temperature_c; }
    float get_salinity_psu() const { return _salinity_psu; }
    float get_acidity_ph() const { return _acidity_ph; }

    float get_frequency_hz() const { return _frequency_hz; }
    float get_transmit_power_w() const { return _transmit_power_w; }
    float get_nominal_pulse_duration_s() const { return _nominal_pulse_duration_s; }
    float get_slope_factor() const { return _slope_factor; }
    float get_sample_interval_s() const { return _sample_interval_s; }

    float get_computed_sound_velocity_m_s() const { return _computed_sound_velocity_m_s; }
    auto  get_forced_sound_velocity_m_s() const { return _forced_sound_velocity_m_s; }
    float get_sound_velocity_m_s() const
    {
        return _forced_sound_velocity_m_s.value_or(_computed_sound_velocity_m_s);
    }

    float get_computed_absorption_db_m() const { return _computed_absorption_db_m; }
    auto  get_forced_absorption_db_m() const { return _forced_absorption_db_m; }
    float get_absorption_db_m() const
    {
        return _forced_absorption_db_m.value_or(_computed_absorption_db_m);
    }

    int16_t get_filter_stage_1_decimation_factor() const
    {
        return _filter_stage_1_decimation_factor;
    }
    int16_t get_filter_stage_2_decimation_factor() const
    {
        return _filter_stage_2_decimation_factor;
    }
    const auto& get_filter_stage_1_coefficients() const { return _filter_stage_1_coefficients; }
    const auto& get_filter_stage_2_coefficients() const { return _filter_stage_2_coefficients; }
    float       get_computed_internal_sampling_interval_hz() const
    {
        return _computed_internal_sampling_interval_hz;
    }
    float get_computed_effective_pulse_duration_s() const
    {
        return _computed_effective_pulse_duration_s;
    }
    auto get_forced_effective_pulse_duration_s() const
    {
        return _forced_effective_pulse_duration_s;
    }
    float get_effective_pulse_duration_s() const
    {
        return _forced_effective_pulse_duration_s.value_or(_computed_effective_pulse_duration_s);
    }

    float get_wavelength_m() const { return _wavelength_m; }
    float get_corr_transducer_gain_db() const { return _corr_transducer_gain_db; }
    float get_corr_equivalent_beam_angle_db() const { return _corr_equivalent_beam_angle_db; }

    std::optional<size_t> get_n_complex_samples() const { return _n_complex_samples; }
    std::optional<float>  get_power_conversion_factor_db() const
    {
        return _power_conversion_factor_db;
    }

    std::optional<float> get_rounded_latitude_deg() const { return _rounded_latitude_deg; }
    std::optional<float> get_rounded_longitude_deg() const { return _rounded_longitude_deg; }

    // ----- effective pulse duration -----
    /**
     * @brief Compute the interal sampling interval in Hz based on the filter stages (decimation
     * factors) and the resulting final sample interval
     *
     * @return float
     */
    float compute_internal_sampling_interval_hz() const;

    /**
     * @brief This function computes the raw, unfiltered transmit signal from the parameters set in
     * this calibration. It is used as input for the filter/decimation function that generate the
     * theoretical transmit pulse when calling 'compute_filtered_transmit_pulse'.
     *
     * Note: The transmit pulse is generated with the nominal pulse duration and slope factor as a
     * linear cosine chirp.
     *
     * Note: This function assumes the _computed_internal_sampling_interval_hz to be set, e.g.
     * during initialization.
     *
     * @tparam t_xtensor_float
     * @param start_phase_degrees start phase of the transmit pulse in degrees (default 0)
     * @return auto
     */
    template<tools::helper::c_xtensor_1d t_xtensor_float>
    auto compute_raw_transmit_pulse(float start_phase_degrees = 0) const
    {
        return functions::generate_transmit_pulse<t_xtensor_float>(
            _frequency_hz,
            _frequency_hz,
            _nominal_pulse_duration_s,
            _slope_factor,
            _computed_internal_sampling_interval_hz,
            start_phase_degrees);
    }

    /**
     * @brief This function computes the filtered transmit signal from the parameters set in this
     * calibration. It is used to generate the theoretical transmit pulse that is then used to
     * compute the effective pulse duration when calling compute_effective_pulse_duration_s.
     *
     * Note the transmit pulse is generated with the nominal pulse duration and slope factor as a
     * linear cosine chirp.
     *
     * Note: This function assumes the _computed_internal_sampling_interval_hz to be set, e.g.
     * during initialization.
     *
     * @tparam t_xtensor_float
     * @param start_phase_degrees start_phase_degrees start phase of the transmit pulse in degrees
     * (default 0)
     * @return auto
     */
    template<tools::helper::c_xtensor_1d t_xtensor_float>
    auto compute_filtered_transmit_pulse(float start_phase_degrees = 0) const
    {
        const auto [pulse_times, pulse_amplitudes] =
            compute_raw_transmit_pulse<t_xtensor_float>(start_phase_degrees);

        return functions::filter_and_decimate_pulse(pulse_amplitudes,
                                                    _filter_stage_1_decimation_factor,
                                                    _filter_stage_1_coefficients,
                                                    _filter_stage_2_decimation_factor,
                                                    _filter_stage_2_coefficients,
                                                    _computed_internal_sampling_interval_hz);
    }

    /**
     * @brief Compute the effective pulse duration by integrating the filtered transmit pulse.
     *
     * Note: This function assumes the _computed_internal_sampling_interval_hz to be set, e.g.
     * during initialization.
     *
     * @param round_to_full_samples Round energy to full samples (default true).
     *                              This matches ESP3s implementation.
     * @param start_phase_degrees Start phase of the transmit pulse in degrees (default 0).
     *                            For testing only, should not affect the result.
     * @return float
     */
    float compute_effective_pulse_duration_s(bool  round_to_full_samples = true,
                                             float start_phase_degrees   = 0) const;

    // moved impls
    void setup_simrad_calibration();

    bool operator==(const SimradRawWaterColumnCalibration& other) const;

    bool initialized() const { return _initialized; }

    void check_initialized() const override;
    void check_modifying_base_calibration_allowed() const override;
    void check_initialization() const;
    void check_can_be_initialized() const;

    static SimradRawWaterColumnCalibration from_stream(std::istream& is);
    void                                   to_stream(std::ostream& os) const;

    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(SimradRawWaterColumnCalibration)

  private:
    static void throw_because_value_is_note_finite(std::string_view value_name, float value);
};

// boost hash
// IGNORE_DOC:__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_hash_value
inline std::size_t hash_value(const SimradRawWaterColumnCalibration& arg)
{
    return arg.binary_hash();
}
}
}
}
}
}