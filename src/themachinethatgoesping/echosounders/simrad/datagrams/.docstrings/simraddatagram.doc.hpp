//sourcehash: fe3f3132dff349b7742e77caf5a53aa0481722aa88a2c747a1d72e55c989c0f1

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


static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_SimradDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_SimradDatagram_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_datagram_type = R"doc(< Raw: Datagram type as)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_get_datagram_identifier = R"doc(Ek60 datagram type (XML0, FIL1, NME0, MRU0, RAW3, ...))doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_get_datagram_type = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_get_date_string = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_get_high_date_time = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_get_length =
R"doc(length of the datagram in bytes (excluding the length fields at the
beginning and end of the datagram))doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_get_low_date_time = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_get_timestamp =
R"doc(unix timestamp in seconds since epoch (1970-01-01). Data is converted
to/from internal windows high/low timestamp representation.)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_high_date_time = R"doc(< Raw: High part of Windows NT FILETIME (100ns ticks since 1601-01-01))doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_length = R"doc(< Raw: Length of the datagram in bytes)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_low_date_time = R"doc(< Raw: Low part of Windows NT FILETIME (100ns ticks since 1601-01-01))doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_set_datagram_identifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_set_datagram_type = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_set_high_date_time = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_set_length = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_set_low_date_time = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_set_timestamp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_skip = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_SimradDatagram_verify_datagram_end =
R"doc(verify the datagram is read correctly by reading the length field at
the end

Parameter ``is``:
    istream. Must be at the end position of the datagram. Pos will be
    incremented by 4 bytes (simrad_long).)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


