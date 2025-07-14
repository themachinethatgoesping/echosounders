//sourcehash: e2cc386d2f95073eaf66e4dd068738d2d7777df7640229e6b0b96847bacb7242

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


static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth = R"doc(Single beam echo sounder depth datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_SingleBeamEchoSounderDepth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_SingleBeamEchoSounderDepth_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_echo_sounder_counter = R"doc(< Sequential Number)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_echo_sounder_depth = R"doc(< from waterline in cm)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_etx = R"doc(< end identifier (always 0x03))doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_from_stream_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_get_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_get_echo_sounder_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_get_echo_sounder_depth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_get_echo_sounder_depth_in_meters =
R"doc(Get the echo sounder depth in meters

Returns:
    _echo_sounder_depth * 0.01f (float))doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_get_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_get_input_date = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_get_input_date_string =
R"doc(Get the time as string

Parameter ``fractionalSecondsDigits``:
    $Parameter ``format``:

Returns:
    std::string)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_get_input_time_since_midnight = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_get_input_timestamp =
R"doc(convert the date and time_since_midnight field to a unix timestamp

Returns:
    unixtime as double)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_get_source_identifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_get_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_input_date = R"doc(< year*10000 + month*100 + day (from input datagram if available))doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_input_time_since_midnight =
R"doc(< time since midnight in milliseconds (from input < datagram if
available))doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_set_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_set_echo_sounder_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_set_echo_sounder_depth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_set_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_set_input_date = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_set_input_time_since_midnight = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_set_source_identifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_set_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_source_identifier = R"doc(< 'S', 'T', '1', '2' or '3')doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


