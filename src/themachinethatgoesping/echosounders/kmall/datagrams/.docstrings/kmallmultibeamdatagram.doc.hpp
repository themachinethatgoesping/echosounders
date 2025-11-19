//sourcehash: 06d1c76e490c73e1d5feeb45df2ff6522527c5b3eed86fa133785d8cd6831e63

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


static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram = R"doc(Clock datagrams)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_KMALLMultibeamDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_KMALLMultibeamDatagram_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_SCommon = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_SCommon_algorithm_type = R"doc(< Algorithm type used for this ping)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_SCommon_bytes_content = R"doc(< bytes of the datagram body (should be __size))doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_SCommon_number_of_rx_transducers = R"doc(< Number of receive transducers)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_SCommon_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_SCommon_ping_count = R"doc(< Ping number incremented with each ping)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_SCommon_rx_fan_index = R"doc(< Index of this receive fan)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_SCommon_rx_fans_per_ping = R"doc(< Number of receive fans per ping)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_SCommon_rx_transducer_ind = R"doc(< Receive used in this ping (0 is first))doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_SCommon_swath_along_position = R"doc(< Swath along position (0 is aftmost swath))doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_SCommon_swaths_per_ping = R"doc(< Number of swaths per ping)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_SCommon_tx_transducer_ind = R"doc(< Transmitter used in this ping (0 is first))doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_get_algorithm_type = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_get_bytes_content = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_get_number_of_rx_transducers = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_get_ping_count = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_get_rx_fan_index = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_get_rx_fans_per_ping = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_get_rx_transducer_ind = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_get_swath_along_position = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_get_swaths_per_ping = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_get_tx_transducer_ind = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_read_multibeamdatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_scommon = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_set_algorithm_type = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_set_bytes_content = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_set_number_of_rx_transducers = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_set_ping_count = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_set_rx_fan_index = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_set_rx_fans_per_ping = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_set_rx_transducer_ind = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_set_swath_along_position = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_set_swaths_per_ping = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_set_tx_transducer_ind = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_KMALLMultibeamDatagram_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


