//sourcehash: c892d6101b9d582dd991535b14b1d3fe81d3aca74b0cb409ca7d29161cef7df6

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


static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1 =
R"doc(Filter binary datagram (FIL1) This datagram contains filter
coefficients used by the EK80 to filter the received signal.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_FIL1 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_FIL1_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_channel_id = R"doc(Channel identification (size is always 128))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_coefficients = R"doc(Filter coefficients)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_decimation_factor = R"doc(Filter decimation factor)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_from_stream_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_from_stream_3 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_get_channel_id = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_get_channel_id_stripped = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_get_coefficients = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_get_decimation_factor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_get_no_of_coefficients = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_get_spare_1 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_get_spare_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_get_stage = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_no_of_coefficients = R"doc(Number of complex filter coefficients)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_operator_ne = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_set_channel_id = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_set_coefficients = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_set_decimation_factor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_set_no_of_coefficients = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_set_spare_1 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_set_spare_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_set_stage = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_spare_1 = R"doc(For future expansions)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_spare_2 = R"doc(For future expansions)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_stage = R"doc(Filter stage number)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_to_stream = R"doc()doc";


#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


