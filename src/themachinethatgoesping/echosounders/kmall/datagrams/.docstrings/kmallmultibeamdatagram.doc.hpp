//sourcehash: 13e78883771cf9ee7466c38bbbb7790f74ab2e257732cbec1f13e8f8b85e6aa1

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


static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram = R"doc(Clock datagrams)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_KMALLMultibeamDatagram = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_KMALLMultibeamDatagram_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_SCommon = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_SCommon_algorithm_type = R"doc(Algorithm type used for this ping)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_SCommon_bytes_content = R"doc(bytes of the datagram body (should be __size))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_SCommon_datagram_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_SCommon_number_of_datagrams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_SCommon_number_of_rx_transducers = R"doc(Number of receive transducers)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_SCommon_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_SCommon_ping_count = R"doc(Ping number incremented with each ping)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_SCommon_rx_fan_index = R"doc(Index of this receive fan)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_SCommon_rx_fans_per_ping = R"doc(Number of receive fans per ping)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_SCommon_rx_transducer_ind = R"doc(Receive used in this ping (0 is first))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_SCommon_swath_along_position = R"doc(Swath along position (0 is aftmost swath))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_SCommon_swaths_per_ping = R"doc(Number of swaths per ping)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_SCommon_tx_transducer_ind = R"doc(Transmitter used in this ping (0 is first))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_get_algorithm_type = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_get_bytes_content = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_get_datagram_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_get_number_of_datagrams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_get_number_of_rx_transducers = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_get_ping_count = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_get_rx_fan_index = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_get_rx_fans_per_ping = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_get_rx_transducer_ind = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_get_swath_along_position = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_get_swaths_per_ping = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_get_tx_transducer_ind = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_read_multibeamdatagram = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_read_multibeamdatagram_no_mpart = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_scommon = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_set_algorithm_type = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_set_bytes_content = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_set_datagram_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_set_number_of_datagrams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_set_number_of_rx_transducers = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_set_ping_count = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_set_rx_fan_index = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_set_rx_fans_per_ping = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_set_rx_transducer_ind = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_set_swath_along_position = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_set_swaths_per_ping = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_set_tx_transducer_ind = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_to_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_to_stream_no_mpart = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


