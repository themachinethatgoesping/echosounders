//sourcehash: f5f7fcaaca3d07bf2cdd91f9f08fcf4be5e0917c789d9095d241add78f56bfbe

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


static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_KongsbergAllDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_KongsbergAllDatagram_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_bytes =
R"doc(< number of bytes in the datagram (not including the _bytes field
itself))doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_datagram_identifier = R"doc(< KongsbergAll datagram identifier)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_date = R"doc(< year*1000 + month*100 + day(Example:Jun 27, 2020 = 20200627))doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_get_bytes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_get_datagram_identifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_get_date = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_get_date_string =
R"doc(Get the time as string

Parameter ``fractionalSecondsDigits``:
    $Parameter ``format``:

Returns:
    std::string)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_get_model_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_get_stx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_get_time_since_midnight = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_get_timestamp =
R"doc(convert the date and time_since_midnight field to a unix timestamp

Returns:
    unixtime as double)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_model_number = R"doc(< KongsbergAll model number (example: EM 3002 = 3002))doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_set_bytes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_set_datagram_identifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_set_date = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_set_model_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_set_stx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_set_time_since_midnight = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_skip = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_skip_and_verify_header =
R"doc(This verifies that stream_pos describes the thought datagram and skips
to the beginning of the datagram (without header) This is used to read
some variables from a datagram directly (e.g. read_xyz from
XYZDatagram)

Parameter ``is``:
    istream

Parameter ``stream_pos``:
    position of the datagram header

Parameter ``identifier``:
    datagram identifier

Returns:
    size_t position of the datagram without header)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_stx = R"doc(< (start identifier))doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_time_since_midnight = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_KongsbergAllDatagram_verify_datagram_end =
R"doc(verify the datagram is read correctly by reading the ETX (end
identifier) field and the checksum at the end of the datagram Note:
the checksum is not verified. (describes sum of bytes between STX and
ETX)

Parameter ``is``:
    istream. Must be at the end position of the datagram header. Pos
    will be incremented by 3 bytes (ETX and checksum).)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


