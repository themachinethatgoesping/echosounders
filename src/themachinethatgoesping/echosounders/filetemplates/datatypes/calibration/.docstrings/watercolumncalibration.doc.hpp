//sourcehash: ce27948d76cb05ec8de6c7e758bc0347d2ce994992c4486ca7af4aab9e78227f

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


static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NO_HASH = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_WaterColumnCalibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_WaterColumnCalibration_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_WaterColumnCalibration_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_absorption_db_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_add_hash = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_ap_calibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_apply_beam_sample_correction = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_av_calibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_binary_hash = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_get_absorption_db_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_get_absorption_to_apply = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_get_ap_calibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_get_av_calibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_get_power_calibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_get_sp_calibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_get_sv_calibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_get_tvg_absorption_db_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_get_tvg_factor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_get_tvg_factor_to_apply = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_has_ap_calibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_has_av_calibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_has_power_calibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_has_sp_calibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_has_sv_calibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_inplace_beam_sample_correction = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_operator_assign = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_power_calibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_set_ap_calibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_set_av_calibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_set_power_calibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_set_sp_calibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_set_sv_calibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_sp_calibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_sv_calibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_t_calibration_type = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_t_calibration_type_ap = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_t_calibration_type_av = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_t_calibration_type_power = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_t_calibration_type_sp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_t_calibration_type_sv = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_tvg_absorption_db_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_WaterColumnCalibration_tvg_factor = R"doc()doc";


#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


