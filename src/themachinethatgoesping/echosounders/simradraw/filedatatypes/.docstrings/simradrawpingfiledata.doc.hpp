//sourcehash: 4e4640aa393e004dfa68f129e7403d101abfef9f749e3f8fb938b29ebb55d557

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


static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_SimradRawPingFileData = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_SimradRawPingFileData_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_class_name = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_get_environment = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_get_file_numbers = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_get_file_paths = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_get_parameter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_get_ping_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_get_primary_file_path = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_get_pulse_duration_index =
R"doc(Get the pulse duration index This index is used to look up the correct
sa correction / gain value in the transceiver Is determined by the
index of the used pulse duration in the transceiver configuration

Returns:
    size_t)doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_get_transceiver_information = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_get_watercolumn_calibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_has_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_has_power = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_has_watercolumn_calibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_init_watercolumn_calibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_must_have_datagrams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_ping_data =
R"doc(< when implementing EK60, this must become a variant type (RAW3 or
RAW0))doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_ping_environment = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_ping_parameter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_read_sample_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_release_watercolumn_calibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_set_environment = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_set_parameter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_set_transceiver_information = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_set_watercolumn_calibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_transceiver_information = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_watercolumn_calibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_SimradRawPingFileData_watercolumn_calibration_loaded = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


