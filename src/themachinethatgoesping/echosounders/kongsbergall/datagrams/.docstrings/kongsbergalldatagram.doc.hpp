//sourcehash: 44d9a8baa987d72ab2ffb6b7fdc3298128077b0d8a0ecfd23be677e68b793680

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


static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_KongsbergAllDatagram = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_KongsbergAllDatagram_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_bytes =
R"doc(number of bytes in the datagram (not including the _bytes field
itself))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_datagram_identifier = R"doc(KongsbergAll datagram identifier)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_date = R"doc(year*1000 + month*100 + day(Example:Jun 27, 2020 = 20200627))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_from_stream_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_get_bytes = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_get_datagram_identifier = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_get_date = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_get_date_string =
R"doc(Get the time as string

Args:
    fractionalSecondsDigits: 
    format: 

Returns:
    std::string)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_get_model_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_get_model_number_as_string =
R"doc(Get the model number as string EM+model_number, except 2045 which is
EM2040C

Returns:
    std::string)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_get_stx = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_get_time_since_midnight = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_get_timestamp =
R"doc(convert the date and time_since_midnight field to a unix timestamp

Returns:
    unixtime as double)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_model_number = R"doc(KongsbergAll model number (example: EM 3002 = 3002))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_set_bytes = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_set_datagram_identifier = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_set_date = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_set_model_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_set_stx = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_set_time_since_midnight = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_skip = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_skip_and_verify_header =
R"doc(This verifies that stream_pos describes the thought datagram and skips
to the beginning of the datagram (without header) This is used to read
some variables from a datagram directly (e.g. read_xyz from
XYZDatagram)

Args:
    is: istream
    stream_pos: position of the datagram header
    identifier: datagram identifier

Returns:
    size_t position of the datagram without header)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_stx = R"doc((start identifier))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_time_since_midnight = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_to_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_verify_datagram_end =
R"doc(verify the datagram is read correctly by reading the ETX (end
identifier) field and the checksum at the end of the datagram Note:
the checksum is not verified. (describes sum of bytes between STX and
ETX)

Args:
    is: istream. Must be at the end position of the datagram header.
        Pos will be incremented by 3 bytes (ETX and checksum).)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


