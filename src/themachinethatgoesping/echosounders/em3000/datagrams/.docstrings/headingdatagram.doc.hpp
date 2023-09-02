//sourcehash: 2fd93eb0082f39ed8212756d6735d03413c823f5749b10cfe23bfa9e293373fc

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


static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram = R"doc(Heading datagrams)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram_HeadingDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram_HeadingDatagram_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram_etx = R"doc(< end identifier (always 0x03))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram_from_stream_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram_get_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram_get_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram_get_heading_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram_get_heading_indicator = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram_get_heading_timestamps =
R"doc(return the times converted to unix timestamps

Returns:
    np.array([_number_of_entries], dtype = np.float64))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram_get_headings_in_degrees =
R"doc(return headings in degrees by multiplying the heading by 0.01

Returns:
    np.array([_number_of_entries], dtype = np.float32))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram_get_number_of_entries = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram_get_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram_get_times_and_headings = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram_heading_counter = R"doc(< Sequential Number)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram_heading_indicator = R"doc(< 0 = inactive)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram_number_of_entries = R"doc(< N)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram_set_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram_set_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram_set_heading_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram_set_heading_indicator = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram_set_number_of_entries = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram_set_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram_set_times_and_headings = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram_times_and_headings = R"doc(< 2xN array of time in ms since record start and heading in 0.01°)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram_times_and_headings_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_HeadingDatagram_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


