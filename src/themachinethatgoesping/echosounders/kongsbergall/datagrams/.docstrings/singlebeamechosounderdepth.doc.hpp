//sourcehash: 4d353d448aa56dbeca3a93f7969d1a34fd6d25a4720256f6b2ed259c1d961bed

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


static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth = R"doc(Single beam echo sounder depth datagram)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_SingleBeamEchoSounderDepth = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_SingleBeamEchoSounderDepth_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_checksum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_echo_sounder_counter = R"doc(Sequential Number)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_echo_sounder_depth = R"doc(from waterline in cm)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_etx = R"doc(end identifier (always 0x03))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_from_stream_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_from_stream_3 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_get_checksum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_get_echo_sounder_counter = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_get_echo_sounder_depth = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_get_echo_sounder_depth_in_meters =
R"doc(Get the echo sounder depth in meters

Returns:
    _echo_sounder_depth * 0.01f (float))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_get_etx = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_get_input_date = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_get_input_date_string =
R"doc(Get the time as string

Args:
    fractionalSecondsDigits: 
    format: 

Returns:
    std::string)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_get_input_time_since_midnight = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_get_input_timestamp =
R"doc(convert the date and time_since_midnight field to a unix timestamp

Returns:
    unixtime as double)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_get_source_identifier = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_get_system_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_input_date = R"doc(year*10000 + month*100 + day (from input datagram if available))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_input_time_since_midnight = R"doc(time since midnight in milliseconds (from input datagram if available))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_set_checksum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_set_echo_sounder_counter = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_set_echo_sounder_depth = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_set_etx = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_set_input_date = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_set_input_time_since_midnight = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_set_source_identifier = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_set_system_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_source_identifier = R"doc('S', 'T', '1', '2' or '3')doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_system_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SingleBeamEchoSounderDepth_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


