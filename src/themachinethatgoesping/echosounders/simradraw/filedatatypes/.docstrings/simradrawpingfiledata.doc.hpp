//sourcehash: a32d27d16b4b30729e9eff3e8e88b4edfb513a30e6301f90a978eb3baa150a5b

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


static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_SimradRawPingFileData = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_SimradRawPingFileData_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_class_name = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_filter_stages = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_get_environment = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_get_file_numbers = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_get_file_paths = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_get_filter_stages = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_get_parameter = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_get_ping_data = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_get_primary_file_path = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_get_pulse_duration_index =
R"doc(Get the pulse duration index This index is used to look up the correct
sa correction / gain value in the transceiver Is determined by the
index of the used pulse duration in the transceiver configuration

Returns:
    size_t)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_get_transceiver_information = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_get_watercolumn_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_has_angle = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_has_power = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_has_watercolumn_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_init_watercolumn_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_must_have_datagrams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_ping_data = R"doc(when implementing EK60, this must become a variant type (RAW3 or RAW0))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_ping_environment = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_ping_parameter = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_read_sample_data = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_release_watercolumn_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_set_environment = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_set_filter_stages = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_set_parameter = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_set_transceiver_information = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_set_watercolumn_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_transceiver_information = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_watercolumn_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_watercolumn_calibration_loaded = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


