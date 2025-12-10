//sourcehash: 788615fb0d1dd89b0a933476e35228023eb9fa4dc7583565a7a13e560811e24f

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


static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_SimradRawDatagram = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_SimradRawDatagram_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_SimradRawDatagram_SimradRawDatagram = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_SimradRawDatagram_SimradRawDatagram_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_SimradRawDatagram_datagram_type = R"doc(Raw: Datagram type as)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_SimradRawDatagram_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_SimradRawDatagram_from_stream_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_SimradRawDatagram_get_datagram_identifier = R"doc(Ek60 datagram type (XML0, FIL1, NME0, MRU0, RAW3, ...))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_SimradRawDatagram_get_datagram_type = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_SimradRawDatagram_get_date_string = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_SimradRawDatagram_get_high_date_time = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_SimradRawDatagram_get_length =
R"doc(length of the datagram in bytes (excluding the length fields at the
beginning and end of the datagram))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_SimradRawDatagram_get_low_date_time = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_SimradRawDatagram_get_timestamp =
R"doc(unix timestamp in seconds since epoch (1970-01-01). Data is converted
to/from internal windows high/low timestamp representation.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_SimradRawDatagram_high_date_time = R"doc(Raw: High part of Windows NT FILETIME (100ns ticks since 1601-01-01))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_SimradRawDatagram_length = R"doc(Raw: Length of the datagram in bytes)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_SimradRawDatagram_low_date_time = R"doc(Raw: Low part of Windows NT FILETIME (100ns ticks since 1601-01-01))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_SimradRawDatagram_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_SimradRawDatagram_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_SimradRawDatagram_set_datagram_identifier = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_SimradRawDatagram_set_datagram_type = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_SimradRawDatagram_set_high_date_time = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_SimradRawDatagram_set_length = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_SimradRawDatagram_set_low_date_time = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_SimradRawDatagram_set_timestamp = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_SimradRawDatagram_skip = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_SimradRawDatagram_to_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_SimradRawDatagram_verify_datagram_end =
R"doc(verify the datagram is read correctly by reading the length field at
the end

Args:
    is: istream. Must be at the end position of the datagram. Pos will
        be incremented by 4 bytes (simradraw_long).)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


