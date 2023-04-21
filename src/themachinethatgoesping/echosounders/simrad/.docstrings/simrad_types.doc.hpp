//sourcehash: b4d808c4db54709bbe5415addf1c60ae8e9639cef77b29e38af836f53cb16321

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


static const char *__doc_themachinethatgoesping_echosounders_datagram_identifier_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_datagram_identifier_to_string = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_SimradDatagram_type_from_string = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagram_type_to_string = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagram_type_to_string_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_t_SimradDatagramIdentifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_t_SimradDatagramIdentifier_FIL1 = R"doc(< Filter datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_t_SimradDatagramIdentifier_MRU0 = R"doc(< Motion datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_t_SimradDatagramIdentifier_NME0 = R"doc(< Unspecified (unknown) NMEA datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_t_SimradDatagramIdentifier_RAW3 = R"doc(< Raw sample data datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_t_SimradDatagramIdentifier_TAG0 = R"doc(< ???)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_t_SimradDatagramIdentifier_XML0 = R"doc(< Unspecified (unknown) XML datagram)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


