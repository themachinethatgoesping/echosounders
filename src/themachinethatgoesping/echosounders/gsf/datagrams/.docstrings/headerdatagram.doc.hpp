//sourcehash: 095ddb34293eee60079ec30add05bc243e650814fefcb58e12752150506d4993

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


static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram = R"doc(Header datagrams)doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram_HeaderDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram_HeaderDatagram_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram_date_external =
R"doc(< from external header input year*1000 + month*100 + day(Example:Jun <
27, 2020 = 20200627))doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram_etx = R"doc(< end identifier (always 0x03))doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram_from_stream_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram_get_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram_get_date_external = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram_get_date_string_external_header = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram_get_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram_get_header_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram_get_pps_active = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram_get_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram_get_time_since_midnight_external = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram_get_timestamp_external =
R"doc(convert the date and time_since_midnight field to a unix timestamp

Returns:
    unixtime as double)doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram_get_timestamp_offset =
R"doc(difference between timestamp and timestamp_external

Returns:
    timestamp_external - timestamp)doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram_header_counter = R"doc(< sequential number)doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram_pps_active =
R"doc(< 0 = inactive (Shows if the system header is synchronized to an
external < PPS signal or not))doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram_set_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram_set_date_external = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram_set_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram_set_header_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram_set_pps_active = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram_set_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram_set_time_since_midnight_external = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram_time_since_midnight_external = R"doc(< in ms from external header datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_HeaderDatagram_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


