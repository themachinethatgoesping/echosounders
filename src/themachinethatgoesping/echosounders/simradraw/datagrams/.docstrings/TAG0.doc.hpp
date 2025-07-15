//sourcehash: 3f7e0dc6e9e7fda9067abba6b4a1fb3bd7e970d7978c5babc0cdfc4b30f56f84

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


static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_TAG0 =
R"doc(Motion binary datagram (TAG0) This datagram contains heave, roll,
pitch and heading as float values. Conveniently, these values can be
used directly in themachinethatgoesping navigation processing because
they are defined in the default coordinate system / value range.)doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_TAG0_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_TAG0_TAG0 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_TAG0_TAG0_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_TAG0_TAG0_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_TAG0_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_TAG0_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_TAG0_from_stream_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_TAG0_get_text = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_TAG0_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_TAG0_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_TAG0_set_text = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_TAG0_text = R"doc(< _text annotation string (e.g. interesting fish shoal in echogram))doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_datagrams_TAG0_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


