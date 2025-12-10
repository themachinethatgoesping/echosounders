//sourcehash: ce633a9f2cf0c005f587f5f95cc6ef5b708ca8ec277918b96dc406d29e40d464

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


static const char *mkd_doc__unnamed_class_at_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_watercolumncalibration_hpp_454_67 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_WaterColumnCalibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_WaterColumnCalibration_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_WaterColumnCalibration_3 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_absorption_db_m = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_ap_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_apply_beam_sample_correction = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_av_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_check_initialized = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_check_modifying_base_calibration_allowed = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_get_absorption_db_m = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_get_absorption_to_apply = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_get_ap_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_get_av_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_get_power_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_get_sp_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_get_sv_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_get_tvg_absorption_db_m = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_get_tvg_factor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_get_tvg_factor_to_apply = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_has_ap_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_has_av_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_has_power_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_has_sp_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_has_sv_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_has_valid_absorption_db_m = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_inplace_beam_sample_correction = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_operator_assign = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_power_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_set_absorption_db_m = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_set_ap_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_set_av_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_set_power_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_set_sp_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_set_sv_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_sp_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_sv_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_to_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_tvg_absorption_db_m = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_tvg_factor = R"doc()doc";


static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_t_calibration_type = R"doc(Calibration type for water column data processing)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_t_calibration_type_ap = R"doc(amplitude derived point scattering (uncalibrated TS))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_t_calibration_type_av = R"doc(amplitude derived volume scattering (uncalibrated SV))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_t_calibration_type_power =
R"doc(power calibration (Received amplitudes computed to power, no
absorption, no spreading loss))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_t_calibration_type_pp =
R"doc(power derived point scattering (uncalibrated TS without parameter
compensation))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_t_calibration_type_pv =
R"doc(power derived volume scattering (uncalibrated SV without parameter
compensation))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_t_calibration_type_rp =
R"doc(power derived point scattering (uncalibrated TS without parameter and
absorption compensation))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_t_calibration_type_rv =
R"doc(power derived volume scattering (uncalibrated SV without parameter and
absorption compensation))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_t_calibration_type_sp = R"doc(point scattering (uncompensated TS))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_t_calibration_type_sv = R"doc(volume scattering SV)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


