//sourcehash: 744d117a27a4de515056edc80e21997c933752c93e3ffc6dc8edd179ce00249e

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


static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_KMALLDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_KMALLDatagram_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_KMALLDatagram_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_KMALLDatagram_4 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_bytes_datagram = R"doc(< Number of bytes in datagram including this field)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_compute_size_content = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_datagram_identifier = R"doc(< Datagram type identifier)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_datagram_version = R"doc(< Datagram version)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_echo_sounder_id =
R"doc(< Echosounder sounder identity (e.g. 124, 304, 712, 2040, 2045 (EM <
2040C) ))doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_get_bytes_datagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_get_datagram_identifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_get_datagram_version = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_get_date_string =
R"doc(Get the time as string

Parameter ``fractionalSecondsDigits``:
    $Parameter ``format``:

Returns:
    std::string)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_get_echo_sounder_id = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_get_system_id = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_get_time_nanosec = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_get_time_sec = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_get_timestamp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_set_bytes_datagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_set_datagram_identifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_set_datagram_version = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_set_echo_sounder_id = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_set_system_id = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_set_time_nanosec = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_set_time_sec = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_skip = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_system_id = R"doc(< Echosounder system id (serial number))doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_time_nanosec = R"doc(< nanoseconds since time_sec)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_time_sec = R"doc(< unixtime (seconds since 1970-01-01 00:00:00 UTC))doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLDatagram_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


