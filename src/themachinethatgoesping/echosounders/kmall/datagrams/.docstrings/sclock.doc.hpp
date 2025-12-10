//sourcehash: c31bbcd9691f344a691bf3a725f034207c2d0e0a335ee1da2c563e3d2a4dcc33

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


static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SClock = R"doc(Clock datagrams)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SClock_Content = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SClock_Content_clock_dev_pu_microsec = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SClock_Content_offset_sec = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SClock_Content_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SClock_SClock = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SClock_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SClock_bytes_datagram_check = R"doc(Each datagram ends with the size of the datagram for integrity check)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SClock_clock_data_from_sensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SClock_content = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SClock_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SClock_from_stream_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SClock_from_stream_3 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SClock_get_bytes_datagram_check = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SClock_get_clock_data_from_sensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SClock_get_clock_dev_pu_microsec = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SClock_get_offset_sec = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SClock_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SClock_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SClock_set_bytes_datagram_check = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SClock_set_clock_data_from_sensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SClock_set_clock_dev_pu_microsec = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SClock_set_offset_sec = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SClock_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


