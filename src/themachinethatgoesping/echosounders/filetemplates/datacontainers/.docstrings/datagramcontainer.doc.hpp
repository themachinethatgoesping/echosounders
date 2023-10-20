//sourcehash: b349498910750e674c0957f1fec489ce3774caa683c52bcd9a9fab9b147f5dd5

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


static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_DatagramContainer = R"doc(Construct a new empty DatagramContainer object)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_DatagramContainer_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_add_datagram_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_add_datagram_infos = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_at = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_count_datagrams_per_type = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_datagram_infos = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_find_datagram_types = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_get_datagram_infos = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_get_sorted_by_time = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_name = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_operator_call = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_operator_call_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_operator_call_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_pyindexer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_reversed = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_set_datagram_infos = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_size = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_split_by_time_diff =
R"doc(Split the data if the time difference between two subsequent datagrams
is larger than arg Note: for this function to make sense the data
should be sorted_in_time

Parameter ``max_time_diff_seconds:``:
    maximum time difference between two subsequent datagrams in
    seconds

Returns:
    std::vector<DatagramContainer>)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_DatagramContainer_timeinfo =
R"doc(Compute some time statistics for the datagram_infos in the container
The is_sorted variable is interpreted as follos: - 1: the
datagram_infos are sorted by time (ascending) - 0: the datagram_infos
are not sorted by time - -1: the datagram_infos are sorted by time
(descending)

Returns:
    std::tuple<min_timestamp, max_timestamp, is_sorted()>)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


