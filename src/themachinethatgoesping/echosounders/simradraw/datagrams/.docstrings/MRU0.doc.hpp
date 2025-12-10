//sourcehash: 8059764c357b5d05284080efd414910f9142816218a0fcc3f0be9417faae167f

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


static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_MRU0 =
R"doc(Motion binary datagram (MRU0) This datagram contains heave, roll,
pitch and heading as float values. Conveniently, these values can be
used directly in themachinethatgoesping navigation processing because
they are defined in the default coordinate system / value range.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_MRU0_MRU0 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_MRU0_MRU0_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_MRU0_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_MRU0_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_MRU0_from_stream_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_MRU0_from_stream_3 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_MRU0_get_heading = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_MRU0_get_heave = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_MRU0_get_pitch = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_MRU0_get_roll = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_MRU0_heading = R"doc(Heading in degrees, 0° north, 90° east)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_MRU0_heave = R"doc(Heave in m, positive up)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_MRU0_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_MRU0_operator_ne = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_MRU0_pitch = R"doc(Pitch in degrees, positive nose up)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_MRU0_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_MRU0_roll = R"doc(Roll in degrees, positive port up)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_MRU0_set_heading = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_MRU0_set_heave = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_MRU0_set_pitch = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_MRU0_set_roll = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_MRU0_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


