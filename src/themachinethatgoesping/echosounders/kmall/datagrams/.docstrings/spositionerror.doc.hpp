//sourcehash: 8c3b9706af53c482ecf8c540c63efa514d50f1d26dc579711c7c62fd2a07f4ca

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


static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError = R"doc(Clock datagrams)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_Content = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_Content_ellipse_erientation_error_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_Content_ellipse_semi_major_axis_error_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_Content_ellipse_semi_minor_axis_error_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_Content_height_error_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_Content_latitude_error_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_Content_longitude_error_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_Content_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_Content_range_input_rms = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_Content_time_from_sensor_nanosec = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_Content_time_from_sensor_sec = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_SPositionError = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_bytes_datagram_check =
R"doc(< Each datagram ends with the size of the datagram for < integrity
check)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_content = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_from_stream_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_get_bytes_datagram_check = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_get_ellipse_erientation_error_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_get_ellipse_semi_major_axis_error_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_get_ellipse_semi_minor_axis_error_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_get_height_error_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_get_latitude_error_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_get_longitude_error_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_get_pos_error_data_from_sensor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_get_range_input_rms = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_get_sensor_date_string =
R"doc(Get the time as string

Parameter ``fractionalSecondsDigits``:
    $Parameter ``format``:

Returns:
    std::string)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_get_sensor_timestamp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_get_time_from_sensor_nanosec = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_get_time_from_sensor_sec = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_pos_error_data_from_sensor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_set_bytes_datagram_check = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_set_ellipse_erientation_error_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_set_ellipse_semi_major_axis_error_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_set_ellipse_semi_minor_axis_error_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_set_height_error_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_set_latitude_error_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_set_longitude_error_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_set_pos_error_data_from_sensor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_set_range_input_rms = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_set_time_from_sensor_nanosec = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_set_time_from_sensor_sec = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SPositionError_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


