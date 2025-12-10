//sourcehash: cb78782d5a47a9e085190ff3c346b605b83e2567392d690b959ca45b2016a7fd

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


static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_PingContainer = R"doc(Construct a new empty PingContainer object)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_PingVector =
R"doc(Construct a new PingContainer object from a vector of pings

Args:
    pings:: vector of pings)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_add_ping = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_add_pings = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_at = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_count_pings_per_channel_id = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_find_channel_ids = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_get_pings = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_get_sorted_by_time = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_max_number_of_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_name = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_operator_call = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_operator_call_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_operator_call_3 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_pings = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_pings_2 =
R"doc(Construct a new PingContainer object from a vector of pings

Args:
    pings:: vector of pings)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_pyindexer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_pyindexer_2 =
R"doc(Construct a new PingContainer object from a vector of pings

Args:
    pings:: vector of pings)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_reversed = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_set_pings = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_size = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_split_by_time_diff =
R"doc(Split the data if the time difference between two subsequent datagrams
is larger than arg Note: for this function to make sense the data
should be sorted_in_time

Args:
    max_time_diff_seconds:: maximum time difference between two
                          subsequent datagrams in seconds

Returns:
    std::vector<PingContainer<type_Ping>>)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datacontainers_PingContainer_timeinfo =
R"doc(Compute some time statistics for the pings in the container The
is_sorted variable is interpreted as follows:
 - 1: the pings are sorted by time (ascending) - 0: the pings are not
   sorted by time
- -1: the pings are sorted by time (descending)

Returns:
    std::tuple<min_timestamp, max_timestamp, is_sorted()>)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


