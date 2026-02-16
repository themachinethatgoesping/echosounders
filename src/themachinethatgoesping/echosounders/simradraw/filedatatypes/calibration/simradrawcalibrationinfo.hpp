// SPDX-FileCopyrightText: 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/simradrawcalibrationinfo.doc.hpp"

#include <cmath>
#include <cstddef>
#include <cstdint>
#include <numbers>
#include <optional>
#include <string>

#include <fmt/core.h>

#include "../../../filetemplates/datatypes/calibration/calibrationinfo.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace filedatatypes {
namespace calibration {

/**
 * @brief CalibrationInfo specialization for SimradRaw (EK60/EK80) water column calibration.
 *
 * Provides `on_*` methods that mirror the set_* methods of
 * SimradRawWaterColumnCalibration.  Each method generates a Python script
 * snippet documenting how the parameter was set and registers it as a
 * setup step (or formula).
 *
 * Usage in SimradRawWaterColumnCalibration:
 *   - Call `_cal_info.on_<method_name>(args)` at the top of each set_* method.
 *   - Wrap inner set_* calls with `auto guard = _cal_info.suppress();` so
 *     only the outer (user-facing) registration is kept.
 */
class SimradRawCalibrationInfo
    : public filetemplates::datatypes::calibration::CalibrationInfo
{
  public:
    SimradRawCalibrationInfo() = default;

    // =================================================================
    // set_transducer_parameters
    // =================================================================

    /**
     * @brief Register transducer parameters obtained from the XML configuration
     *        transducer object + pulse duration index.
     */
    void on_set_transducer_from_object(float  gain,
                                       float  sa_correction,
                                       float  equivalent_beam_angle,
                                       float  frequency_nominal,
                                       size_t pulse_duration_index)
    {
        register_step(
            "set_transducer_parameters",
            fmt::format(
                "# from TransceiverChannelTransducer (pulse_duration_index = {})\n"
                "transducer = ping.file_data.get_transducer()\n"
                "transducer_gain_db         = transducer.Gain[{}]           # = {:.6g}\n"
                "sa_correction_db           = transducer.SaCorrection[{}]   # = {:.6g}\n"
                "equivalent_beam_angle_db   = transducer.EquivalentBeamAngle  # = {:.6g}\n"
                "frequency_nominal_hz       = transducer.Frequency            # = {:.6g}",
                pulse_duration_index,
                pulse_duration_index,
                gain,
                pulse_duration_index,
                sa_correction,
                equivalent_beam_angle,
                frequency_nominal));
    }

    /**
     * @brief Register transducer parameters set manually (value-based overload).
     */
    void on_set_transducer_from_values(float gain,
                                       float sa_correction,
                                       float equivalent_beam_angle,
                                       float frequency_nominal)
    {
        register_step("set_transducer_parameters",
                      fmt::format("# manually set\n"
                                  "transducer_gain_db         = {:.6g}\n"
                                  "sa_correction_db           = {:.6g}\n"
                                  "equivalent_beam_angle_db   = {:.6g}\n"
                                  "frequency_nominal_hz       = {:.6g}",
                                  gain,
                                  sa_correction,
                                  equivalent_beam_angle,
                                  frequency_nominal));
    }

    // =================================================================
    // set_environment_parameters
    // =================================================================

    /**
     * @brief Register environment parameters obtained from XML_Environment datagram.
     */
    void on_set_environment_from_xml(float depth, float temperature, float salinity, float acidity)
    {
        register_step(
            "set_environment_parameters",
            fmt::format("# from XML_Environment datagram\n"
                        "env = ping.file_data.get_environment()\n"
                        "reference_depth_m = env.Depth        # = {:.6g}\n"
                        "temperature_c     = env.Temperature  # = {:.6g}\n"
                        "salinity_psu      = env.Salinity     # = {:.6g}\n"
                        "acidity_ph        = env.Acidity      # = {:.6g}",
                        depth,
                        temperature,
                        salinity,
                        acidity));
    }

    /**
     * @brief Register environment parameters set manually (value-based overload).
     */
    void on_set_environment_from_values(float depth,
                                        float temperature,
                                        float salinity,
                                        float acidity)
    {
        register_step("set_environment_parameters",
                      fmt::format("# manually set\n"
                                  "reference_depth_m = {:.6g}\n"
                                  "temperature_c     = {:.6g}\n"
                                  "salinity_psu      = {:.6g}\n"
                                  "acidity_ph        = {:.6g}",
                                  depth,
                                  temperature,
                                  salinity,
                                  acidity));
    }

    /**
     * @brief Register forced sound velocity / absorption (2-parameter overload).
     */
    void on_set_environment_forced(float forced_sound_velocity_m_s, float forced_absorption_db_m)
    {
        register_step("set_environment_parameters_forced",
                      fmt::format("# forced sound velocity and absorption\n"
                                  "forced_sound_velocity_m_s = {:.6g}\n"
                                  "forced_absorption_db_m    = {:.6g}",
                                  forced_sound_velocity_m_s,
                                  forced_absorption_db_m));
    }

    // =================================================================
    // set_runtime_parameters
    // =================================================================

    /**
     * @brief Register runtime parameters from XML_Parameter_Channel datagram.
     */
    void on_set_runtime_from_xml(float frequency,
                                 float transmit_power,
                                 float pulse_duration,
                                 float slope,
                                 float sample_interval)
    {
        register_step(
            "set_runtime_parameters",
            fmt::format(
                "# from XML_Parameter_Channel datagram\n"
                "params = ping.file_data.get_parameter_channel()\n"
                "frequency_hz             = params.Frequency            # = {:.6g}\n"
                "transmit_power_w         = params.TransmitPower        # = {:.6g}\n"
                "nominal_pulse_duration_s = params.get_pulse_duration() # = {:.6g}\n"
                "slope_factor             = params.Slope                # = {:.6g}\n"
                "sample_interval_s        = params.SampleInterval       # = {:.6g}",
                frequency,
                transmit_power,
                pulse_duration,
                slope,
                sample_interval));
    }

    /**
     * @brief Register runtime parameters set manually (value-based overload).
     */
    void on_set_runtime_from_values(float frequency,
                                    float transmit_power,
                                    float pulse_duration,
                                    float slope,
                                    float sample_interval)
    {
        register_step("set_runtime_parameters",
                      fmt::format("# manually set\n"
                                  "frequency_hz             = {:.6g}\n"
                                  "transmit_power_w         = {:.6g}\n"
                                  "nominal_pulse_duration_s = {:.6g}\n"
                                  "slope_factor             = {:.6g}\n"
                                  "sample_interval_s        = {:.6g}",
                                  frequency,
                                  transmit_power,
                                  pulse_duration,
                                  slope,
                                  sample_interval));
    }

    // =================================================================
    // set_filter_parameters
    // =================================================================

    /**
     * @brief Register filter parameters from FIL1 datagrams.
     */
    void on_set_filter_from_object(int16_t stage1_decimation,
                                   size_t  stage1_n_coefficients,
                                   int16_t stage2_decimation,
                                   size_t  stage2_n_coefficients)
    {
        register_step(
            "set_filter_parameters",
            fmt::format(
                "# from FIL1 datagrams\n"
                "filter_stages = ping.file_data.get_filter_stages()\n"
                "stage1_decimation_factor = filter_stages[0].get_decimation_factor()  # = {}\n"
                "stage1_coefficients      = filter_stages[0].get_coefficients()       # {} "
                "complex coefficients\n"
                "stage2_decimation_factor = filter_stages[1].get_decimation_factor()  # = {}\n"
                "stage2_coefficients      = filter_stages[1].get_coefficients()       # {} "
                "complex coefficients",
                stage1_decimation,
                stage1_n_coefficients,
                stage2_decimation,
                stage2_n_coefficients));
    }

    /**
     * @brief Register filter parameters set manually.
     */
    void on_set_filter_from_values(int16_t stage1_decimation,
                                   size_t  stage1_n_coefficients,
                                   int16_t stage2_decimation,
                                   size_t  stage2_n_coefficients)
    {
        register_step(
            "set_filter_parameters",
            fmt::format("# manually set\n"
                        "stage1_decimation_factor = {}\n"
                        "stage1_coefficients      = ...  # {} complex coefficients\n"
                        "stage2_decimation_factor = {}\n"
                        "stage2_coefficients      = ...  # {} complex coefficients",
                        stage1_decimation,
                        stage1_n_coefficients,
                        stage2_decimation,
                        stage2_n_coefficients));
    }

    // =================================================================
    // set_power_calibration_parameters
    // =================================================================

    void on_set_power_calibration_parameters(size_t               n_complex_samples,
                                             std::optional<float> impedance_factor)
    {
        if (n_complex_samples == 0)
        {
            register_step("set_power_calibration_parameters",
                          "# power / angle data (no impedance correction)\n"
                          "n_complex_samples          = 0\n"
                          "power_conversion_factor_db = 0  # not applicable");
        }
        else
        {
            float pcf = impedance_factor.has_value()
                            ? 10.f * std::log10(impedance_factor.value() / n_complex_samples)
                            : std::numeric_limits<float>::quiet_NaN();
            register_step(
                "set_power_calibration_parameters",
                fmt::format("# complex data (impedance correction applied)\n"
                            "n_complex_samples          = {}\n"
                            "impedance_factor           = {:.6g}\n"
                            "power_conversion_factor_db = 10 * log10(impedance_factor / "
                            "n_complex_samples)  # = {:.6g}",
                            n_complex_samples,
                            impedance_factor.value_or(std::numeric_limits<float>::quiet_NaN()),
                            pcf));
        }
    }

    // =================================================================
    // set_optional_parameters
    // =================================================================

    void on_set_optional_parameters(std::optional<float> latitude, std::optional<float> longitude)
    {
        register_step("set_optional_parameters",
                      fmt::format("# optional positioning parameters\n"
                                  "rounded_latitude_deg  = {}  # or None\n"
                                  "rounded_longitude_deg = {}  # or None",
                                  latitude.has_value()
                                      ? fmt::format("{:.6g}", latitude.value())
                                      : std::string("None"),
                                  longitude.has_value()
                                      ? fmt::format("{:.6g}", longitude.value())
                                      : std::string("None")));
    }

    // =================================================================
    // force_* methods
    // =================================================================

    void on_force_sound_velocity(std::optional<float> forced_sv)
    {
        register_step("force_sound_velocity",
                      fmt::format("forced_sound_velocity_m_s = {}",
                                  forced_sv.has_value()
                                      ? fmt::format("{:.6g}", forced_sv.value())
                                      : std::string("None")));
    }

    void on_force_absorption(std::optional<float> forced_abs)
    {
        register_step("force_absorption",
                      fmt::format("forced_absorption_db_m = {}",
                                  forced_abs.has_value()
                                      ? fmt::format("{:.6g}", forced_abs.value())
                                      : std::string("None")));
    }

    void on_force_effective_pulse_duration(std::optional<float> forced_epd)
    {
        register_step("force_effective_pulse_duration",
                      fmt::format("forced_effective_pulse_duration_s = {}",
                                  forced_epd.has_value()
                                      ? fmt::format("{:.6g}", forced_epd.value())
                                      : std::string("None")));
    }

    // =================================================================
    // setup_simrad_calibration — formula registration
    // =================================================================

    /**
     * @brief Register the formulas computed in setup_simrad_calibration.
     *
     * Call this at the end of setup_simrad_calibration() to document the
     * exact calibration offsets that were computed from the input parameters.
     *
     * @param pcf  power conversion factor in dB (0 for power data)
     * @param sound_velocity_m_s   effective sound velocity used
     * @param absorption_db_m      effective absorption used
     * @param wavelength_m         computed wavelength
     * @param freq_corr            frequency correction: 20*log10(f/f_nominal)
     * @param corr_gain            corrected transducer gain (gain + freq_corr)
     * @param corr_eba             corrected equiv beam angle (eba + freq_corr)
     * @param transmit_power_w     transmit power
     * @param sa_correction_db     Sa correction
     * @param effective_pulse_dur  effective pulse duration
     * @param sp_offset            computed Sp offset
     * @param sv_offset            computed Sv offset
     * @param has_power            was power calibration set?
     * @param has_ap               was Ap calibration set?
     * @param has_av               was Av calibration set?
     */
    void on_setup_simrad_calibration(float pcf,
                                     float sound_velocity_m_s,
                                     float absorption_db_m,
                                     float wavelength_m,
                                     float freq_corr,
                                     float corr_gain,
                                     float corr_eba,
                                     float transmit_power_w,
                                     float sa_correction_db,
                                     float effective_pulse_dur,
                                     float sp_offset,
                                     float sv_offset,
                                     bool  has_power,
                                     bool  has_ap,
                                     bool  has_av)
    {
        // --- power formula ---
        if (has_power)
        {
            register_formula(
                "power",
                fmt::format(
                    "# Power calibration\n"
                    "# power_offset = power_conversion_factor_db\n"
                    "power_conversion_factor_db = {:.6g}  # 10*log10(Z/n) or 0 for power data\n"
                    "power_offset = {:.6g}",
                    pcf,
                    pcf));
        }

        // --- ap (point scattering) formula ---
        if (has_ap)
        {
            static const float pi_factor =
                -10.f * std::log10(16.f * std::numbers::pi_v<float> * std::numbers::pi_v<float>);

            register_formula(
                "ap",
                fmt::format(
                    "# Ap (point scattering) calibration\n"
                    "import numpy as np\n"
                    "\n"
                    "wavelength_m        = sound_velocity_m_s / frequency_hz  # = {:.6g}\n"
                    "freq_corr           = 20 * np.log10(frequency_hz / frequency_nominal_hz)  "
                    "# = {:.6g}\n"
                    "corr_gain           = transducer_gain_db + freq_corr     # = {:.6g}\n"
                    "pi_factor           = -10 * np.log10(16 * np.pi**2)      # = {:.6g}\n"
                    "sp_offset           = -2 * corr_gain - pi_factor "
                    "- 10 * np.log10(transmit_power_w * wavelength_m**2)  # = {:.6g}\n"
                    "\n"
                    "ap_offset = power_conversion_factor_db + sp_offset  # = {:.6g}",
                    wavelength_m,
                    freq_corr,
                    corr_gain,
                    pi_factor,
                    sp_offset,
                    pcf + sp_offset));
        }

        // --- av (volume scattering) formula ---
        if (has_av)
        {
            register_formula(
                "av",
                fmt::format(
                    "# Av (volume backscattering) calibration\n"
                    "import numpy as np\n"
                    "\n"
                    "corr_eba              = equivalent_beam_angle_db + freq_corr  # = {:.6g}\n"
                    "effective_pulse_dur_s = {:.6g}  # from filtered transmit pulse\n"
                    "sv_offset             = -2 * sa_correction_db - corr_eba "
                    "- 10 * np.log10(sound_velocity_m_s * effective_pulse_dur_s * 0.5)  "
                    "# = {:.6g}\n"
                    "\n"
                    "av_offset = power_conversion_factor_db + sp_offset + sv_offset  # = {:.6g}\n"
                    "\n"
                    "# --- get_av formula (applied per sample) ---\n"
                    "# absorption_db_m   = {:.6g}\n"
                    "# tvg_factor_target = 20  (volume scattering)\n"
                    "# tvg_factor_raw    = 0   (no TVG in raw SimradRaw data)\n"
                    "#\n"
                    "# AV[beam, sample] = raw_amplitude_dB[sample]\n"
                    "#                  + av_offset\n"
                    "#                  + 2 * absorption_db_m * range_m[sample]\n"
                    "#                  + 20 * log10(range_m[sample])",
                    corr_eba,
                    effective_pulse_dur,
                    sv_offset,
                    pcf + sp_offset + sv_offset,
                    absorption_db_m));
        }

        // --- summary ---
        register_formula(
            "summary",
            fmt::format(
                "# Calibration summary\n"
                "sound_velocity_m_s = {:.6g}\n"
                "absorption_db_m    = {:.6g}\n"
                "has_power          = {}\n"
                "has_ap             = {}\n"
                "has_av             = {}",
                sound_velocity_m_s,
                absorption_db_m,
                has_power ? "True" : "False",
                has_ap ? "True" : "False",
                has_av ? "True" : "False"));
    }
};

} // namespace calibration
} // namespace filedatatypes
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
