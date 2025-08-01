//sourcehash: 9fef848e3eaee67514b7903be835abd46cf91ac7aa1a3c93aefaa6495a5c24b1

/*
  This file contains docstrings for use in the Python bindings.
  Do not edit! They were automatically extracted by pybind11_mkdoc.

  This is a modified version which allows for more than 8 arguments and includes def-guard
 */

#pragma once

#ifndef __DOCSTRINGS_HPP__

#define __EXPAND(x)                                                  x
#define __COUNT(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, COUNT, ...) COUNT
#define __VA_SIZE(...)                                               __EXPAND(__COUNT(__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1))
#define __CAT1(a, b)                                                 a##b
#define __CAT2(a, b)                                                 __CAT1(a, b)
#define __DOC1(n1)                                                   __doc_##n1
#define __DOC2(n1, n2)                                               __doc_##n1##_##n2
#define __DOC3(n1, n2, n3)                                           __doc_##n1##_##n2##_##n3
#define __DOC4(n1, n2, n3, n4)                                       __doc_##n1##_##n2##_##n3##_##n4
#define __DOC5(n1, n2, n3, n4, n5)                                   __doc_##n1##_##n2##_##n3##_##n4##_##n5
#define __DOC6(n1, n2, n3, n4, n5, n6)                               __doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6
#define __DOC7(n1, n2, n3, n4, n5, n6, n7)                           __doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6##_##n7
#define __DOC8(n1, n2, n3, n4, n5, n6, n7, n8)                                                     \
    __doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6##_##n7##_##n8
#define __DOC9(n1, n2, n3, n4, n5, n6, n7, n8, n9)                                                 \
    __doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6##_##n7##_##n8##_##n9
#define __DOC10(n1, n2, n3, n4, n5, n6, n7, n8, n9, n10)                                           \
    __doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6##_##n7##_##n8##_##n9##_##n10
#define DOC(...) __EXPAND(__EXPAND(__CAT2(__DOC, __VA_SIZE(__VA_ARGS__)))(__VA_ARGS__))

#endif // NEW_DOC_HEADER_HPP
#if defined(__GNUG__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#endif


static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_SimradRawWaterColumnCalibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_SimradRawWaterColumnCalibration_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_SimradRawWaterColumnCalibration_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_acidity_ph = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_check_can_be_initialized = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_check_initialization = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_check_initialized = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_check_modifying_base_calibration_allowed = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_computed_absorption_db_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_computed_sound_velocity_m_s = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_corr_equivalent_beam_angle_db = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_corr_transducer_gain_db = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_effective_pulse_duration_s = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_equivalent_beam_angle_db = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_force_absorption_db_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_force_sound_velocity_m_s = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_forced_absorption_db_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_forced_sound_velocity_m_s = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_frequency_hz = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_frequency_nominal_hz = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_get_absorption_db_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_get_acidity_ph = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_get_computed_absorption_db_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_get_computed_sound_velocity_m_s = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_get_corr_equivalent_beam_angle_db = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_get_corr_transducer_gain_db = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_get_effective_pulse_duration_s = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_get_equivalent_beam_angle_db = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_get_forced_absorption_db_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_get_forced_sound_velocity_m_s = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_get_frequency_hz = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_get_frequency_nominal_hz = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_get_n_complex_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_get_power_conversion_factor_db = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_get_reference_depth_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_get_rounded_latitude_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_get_rounded_longitude_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_get_sa_correction_db = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_get_salinity_psu = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_get_sound_velocity_m_s = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_get_temperature_c = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_get_transducer_gain_db = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_get_transmit_power_w = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_get_wavelength_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_initialized = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_initialized_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_n_complex_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_power_conversion_factor_db =
R"doc(This parameter is NOT optional, if no value is set, the calibration is
not yet valid. Set to 0 when working working with power/angle data. If
>0, this calibration includes a correction for the impedance factor to
translate the complex amplitudes to power applying this calibration to
data which does not match n_complex_samples will result in incorrect
power values)doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_reference_depth_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_rounded_latitude_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_rounded_longitude_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_sa_correction_db = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_salinity_psu = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_set_environment_parameters = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_set_environment_parameters_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_set_environment_parameters_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_set_optional_parameters = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_set_power_calibration_parameters = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_set_runtime_parameters = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_set_runtime_parameters_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_set_transducer_parameters = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_set_transducer_parameters_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_setup_simrad_calibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_temperature_c = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_transducer_gain_db = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_transmit_power_w = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawWaterColumnCalibration_wavelength_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_hash_value = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


