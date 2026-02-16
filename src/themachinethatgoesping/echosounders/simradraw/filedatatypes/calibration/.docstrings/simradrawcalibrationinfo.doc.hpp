//sourcehash: 38c8fdb5ba2c3a0e0d5f255e40dabc9e1ef663161e2a9ac7d5bd93056fcf8ed7

/*
  This file contains docstrings for use in the Python bindings.
  Do not edit! They were automatically extracted by pybind11_mkdoc.

  This is a modified version which allows for more than 8 arguments and includes def-guard
 */

#pragma once

#ifndef __DOCSTRINGS_HPP__
#define __DOCSTRINGS_HPP__

#define MKD_EXPAND(x)                                      x
#define MKD_COUNT(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, COUNT, ...)  COUNT
#define MKD_VA_SIZE(...)                                   MKD_EXPAND(MKD_COUNT(__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0))
#define MKD_CAT1(a, b)                                     a ## b
#define MKD_CAT2(a, b)                                     MKD_CAT1(a, b)
#define MKD_DOC1(n1)                                       mkd_doc_##n1
#define MKD_DOC2(n1, n2)                                   mkd_doc_##n1##_##n2
#define MKD_DOC3(n1, n2, n3)                               mkd_doc_##n1##_##n2##_##n3
#define MKD_DOC4(n1, n2, n3, n4)                           mkd_doc_##n1##_##n2##_##n3##_##n4
#define MKD_DOC5(n1, n2, n3, n4, n5)                       mkd_doc_##n1##_##n2##_##n3##_##n4##_##n5
#define MKD_DOC6(n1, n2, n3, n4, n5, n6)                   mkd_doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6
#define MKD_DOC7(n1, n2, n3, n4, n5, n6, n7)               mkd_doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6##_##n7
#define MKD_DOC8(n1, n2, n3, n4, n5, n6, n7, n8)           mkd_doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6##_##n7##_##n8
#define MKD_DOC9(n1, n2, n3, n4, n5, n6, n7, n8, n9)       mkd_doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6##_##n7##_##n8##_##n9
#define MKD_DOC10(n1, n2, n3, n4, n5, n6, n7, n8, n9, n10) mkd_doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6##_##n7##_##n8##_##n9##_##n10
#define DOC(...)                                           MKD_EXPAND(MKD_EXPAND(MKD_CAT2(MKD_DOC, MKD_VA_SIZE(__VA_ARGS__)))(__VA_ARGS__))

#if defined(__GNUG__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#endif

#endif // __DOCSTRINGS_HPP__
#if defined(__GNUG__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#endif


static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawCalibrationInfo =
R"doc(CalibrationInfo specialization for SimradRaw (EK60/EK80) water column
calibration.

Provides `on_*` methods that mirror the set_* methods of
SimradRawWaterColumnCalibration.  Each method generates a Python
script snippet documenting how the parameter was set and registers it
as a setup step (or formula).

Usage in SimradRawWaterColumnCalibration:
  - Call `_cal_info.on_<method_name>(args)` at the top of each set_*
    method. - Wrap inner set_* calls with `auto guard =
    _cal_info.suppress();` so only the outer (user-facing)
    registration is kept.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawCalibrationInfo_SimradRawCalibrationInfo = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawCalibrationInfo_on_force_absorption = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawCalibrationInfo_on_force_effective_pulse_duration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawCalibrationInfo_on_force_sound_velocity = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawCalibrationInfo_on_set_environment_forced = R"doc(Register forced sound velocity / absorption (2-parameter overload).)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawCalibrationInfo_on_set_environment_from_values = R"doc(Register environment parameters set manually (value-based overload).)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawCalibrationInfo_on_set_environment_from_xml =
R"doc(Register environment parameters obtained from XML_Environment
datagram.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawCalibrationInfo_on_set_filter_from_object = R"doc(Register filter parameters from FIL1 datagrams.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawCalibrationInfo_on_set_filter_from_values = R"doc(Register filter parameters set manually.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawCalibrationInfo_on_set_optional_parameters = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawCalibrationInfo_on_set_power_calibration_parameters = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawCalibrationInfo_on_set_runtime_from_values = R"doc(Register runtime parameters set manually (value-based overload).)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawCalibrationInfo_on_set_runtime_from_xml = R"doc(Register runtime parameters from XML_Parameter_Channel datagram.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawCalibrationInfo_on_set_transducer_from_object =
R"doc(Register transducer parameters obtained from the XML configuration
       transducer object + pulse duration index.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawCalibrationInfo_on_set_transducer_from_values = R"doc(Register transducer parameters set manually (value-based overload).)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_SimradRawCalibrationInfo_on_setup_simrad_calibration =
R"doc(Register the formulas computed in setup_simrad_calibration.

Call this at the end of setup_simrad_calibration() to document the
exact calibration offsets that were computed from the input
parameters.

Args:
    pcf: power conversion factor in dB (0 for power data)
    sound_velocity_m_s: effective sound velocity used
    absorption_db_m: effective absorption used
    wavelength_m: computed wavelength
    freq_corr: frequency correction: 20*log10(f/f_nominal)
    corr_gain: corrected transducer gain (gain + freq_corr)
    corr_eba: corrected equiv beam angle (eba + freq_corr)
    transmit_power_w: transmit power
    sa_correction_db: Sa correction
    effective_pulse_dur: effective pulse duration
    sp_offset: computed Sp offset
    sv_offset: computed Sv offset
    has_power: was power calibration set?
    has_ap: was Ap calibration set?
    has_av: was Av calibration set?)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


