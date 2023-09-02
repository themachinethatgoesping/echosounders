//sourcehash: 2744297b6ba7475d3893f9c58e33cb6faa9429c79ea18966ad051eb765e65a9c

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


static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_DepthOrHeightDatagram = R"doc(Depth (pressure) or height datagrams)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_DepthOrHeightDatagram_DepthOrHeightDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_DepthOrHeightDatagram_DepthOrHeightDatagram_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_DepthOrHeightDatagram_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_DepthOrHeightDatagram_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_DepthOrHeightDatagram_etx = R"doc(< end identifier (always 0x03))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_DepthOrHeightDatagram_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_DepthOrHeightDatagram_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_DepthOrHeightDatagram_from_stream_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_DepthOrHeightDatagram_get_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_DepthOrHeightDatagram_get_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_DepthOrHeightDatagram_get_height = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_DepthOrHeightDatagram_get_height_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_DepthOrHeightDatagram_get_height_in_meters =
R"doc(Get the height in meters

Returns:
    _height * 0.01m (float))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_DepthOrHeightDatagram_get_height_type = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_DepthOrHeightDatagram_get_height_type_explained =
R"doc(Get a string description of the height_type

Returns:
    std::string)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_DepthOrHeightDatagram_get_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_DepthOrHeightDatagram_height = R"doc(< in cm)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_DepthOrHeightDatagram_height_counter = R"doc(< Sequential Number)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_DepthOrHeightDatagram_height_type =
R"doc(< 0: derived from GGK or GGA, 1-99 ???, 100 depth is taken from the <
DepthOrheight datagram, 200: Input from depth sensor)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_DepthOrHeightDatagram_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_DepthOrHeightDatagram_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_DepthOrHeightDatagram_set_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_DepthOrHeightDatagram_set_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_DepthOrHeightDatagram_set_height = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_DepthOrHeightDatagram_set_height_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_DepthOrHeightDatagram_set_height_type = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_DepthOrHeightDatagram_set_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_DepthOrHeightDatagram_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_DepthOrHeightDatagram_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


