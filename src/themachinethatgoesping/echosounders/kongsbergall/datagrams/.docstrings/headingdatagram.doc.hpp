//sourcehash: 89af77ef8cbd7e2e6d4a4778cac893f22531fd6f403a151ac09f49c3d130b5d0

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


static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram = R"doc(Heading datagrams)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram_HeadingDatagram = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram_HeadingDatagram_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram_checksum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram_etx = R"doc(end identifier (always 0x03))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram_from_stream_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram_from_stream_3 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram_get_checksum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram_get_etx = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram_get_heading_counter = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram_get_heading_indicator = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram_get_heading_timestamps =
R"doc(return the times converted to unix timestamps

Returns:
    np.array([_number_of_entries], dtype = np.float64))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram_get_headings_in_degrees =
R"doc(return headings in degrees by multiplying the heading by 0.01

Returns:
    np.array([_number_of_entries], dtype = np.float32))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram_get_number_of_entries = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram_get_system_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram_get_times_and_headings = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram_heading_counter = R"doc(Sequential Number)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram_heading_indicator = R"doc(0 = inactive)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram_number_of_entries = R"doc(N)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram_set_checksum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram_set_etx = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram_set_heading_counter = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram_set_heading_indicator = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram_set_number_of_entries = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram_set_system_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram_set_times_and_headings = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram_system_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram_times_and_headings = R"doc(2xN array of time in ms since record start and heading in 0.01°)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram_times_and_headings_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_HeadingDatagram_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


