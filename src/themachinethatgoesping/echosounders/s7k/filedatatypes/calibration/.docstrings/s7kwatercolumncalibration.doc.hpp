//sourcehash: 0b485eddfd767602cc925ddda6914f30a359ff5df52e1cc2505bedabcd5babaf

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


static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_calibration_S7KWaterColumnCalibration =
R"doc(Water column calibration for Teledyne RESON 7k systems.

This is a first, uncalibrated setup: the power/ap/av calibrations only
carry the volume/point conversion factor derived from the pulse
duration and sound velocity (no system offset, no per-beam/per-range
calibration curves). av is therefore an uncalibrated Sv (a first guess
of Sv); a real Sv calibration (system offset, beam pattern, ...) still
has to be added.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_calibration_S7KWaterColumnCalibration_S7KWaterColumnCalibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_calibration_S7KWaterColumnCalibration_S7KWaterColumnCalibration_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_calibration_S7KWaterColumnCalibration_S7KWaterColumnCalibration_3 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_calibration_S7KWaterColumnCalibration_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_calibration_S7KWaterColumnCalibration_check_initialized = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_calibration_S7KWaterColumnCalibration_check_modifying_base_calibration_allowed = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_calibration_S7KWaterColumnCalibration_effective_pulse_duration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_calibration_S7KWaterColumnCalibration_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_calibration_S7KWaterColumnCalibration_get_effective_pulse_duration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_calibration_S7KWaterColumnCalibration_get_sound_velocity = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_calibration_S7KWaterColumnCalibration_get_system_gain_offset = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_calibration_S7KWaterColumnCalibration_initialized = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_calibration_S7KWaterColumnCalibration_initialized_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_calibration_S7KWaterColumnCalibration_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_calibration_S7KWaterColumnCalibration_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_calibration_S7KWaterColumnCalibration_setup_s7k_calibrations = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_calibration_S7KWaterColumnCalibration_sound_velocity = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_calibration_S7KWaterColumnCalibration_system_gain_offset = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_calibration_S7KWaterColumnCalibration_to_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_calibration_hash_value = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


