//sourcehash: e04b5c7a4cc32019af3afa082fb946f892c581f11faf2f49f9201e6f08529f56

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


static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_GSFDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_GSFDatagram_GSFDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_GSFDatagram_GSFDatagram_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_GSFDatagram_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_GSFDatagram_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_GSFDatagram_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_GSFDatagram_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_GSFDatagram_get_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_GSFDatagram_get_datagram_identifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_GSFDatagram_get_date_string =
R"doc(Get the time as string

Parameter ``fractionalSecondsDigits``:
    $Parameter ``format``:

Returns:
    std::string)doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_GSFDatagram_get_record_identifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_GSFDatagram_get_size_of_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_GSFDatagram_get_timestamp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_GSFDatagram_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_GSFDatagram_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_GSFDatagram_record_identifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_GSFDatagram_set_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_GSFDatagram_set_record_identifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_GSFDatagram_set_size_of_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_GSFDatagram_size_of_data =
R"doc(< number of bytes of the data portion of the datagram (excluding the <
header/checksum))doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_GSFDatagram_skip = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_gsf_datagrams_GSFDatagram_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


