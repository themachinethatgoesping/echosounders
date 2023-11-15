//sourcehash: b3ebf287c5127165a61496732e7ed3a264aa9f2f7995090b76e7abadbcc285f5

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


static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1 =
R"doc(Filter binary datagram (FIL1) This datagram contains filter
coefficients used by the EK80 to filter the received signal.)doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_FIL1 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_FIL1_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_channel_id = R"doc(< Channel identification (size is always 128))doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_coefficients = R"doc(< Filter coefficients, ...))doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_decimation_factor = R"doc(< Filter decimation factor)doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_from_stream_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_get_channel_id = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_get_coefficients = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_get_decimation_factor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_get_no_of_coefficients = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_get_spare_1 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_get_spare_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_get_stage = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_no_of_coefficients = R"doc(< Number of complex filter coefficients)doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_set_channel_id = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_set_coefficients = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_set_decimation_factor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_set_no_of_coefficients = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_set_spare_1 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_set_spare_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_set_stage = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_spare_1 = R"doc(< For future expansions)doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_spare_2 = R"doc(< For future expansions)doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_stage = R"doc(< Filter stage number)doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_FIL1_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


