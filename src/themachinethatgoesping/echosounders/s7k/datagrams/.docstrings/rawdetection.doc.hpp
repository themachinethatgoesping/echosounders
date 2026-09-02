//sourcehash: 25804af9002bb5eb92ff70add2fbbc8a62298f08967581f343e2e900d754ecb6

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


static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection =
R"doc(7k record RawDetectionData: raw bottom detections (bathymetry) per
beam.

This is the preferred bathymetry record (replaces the deprecated
7006). It holds, per beam, the detection point (fractional sample
number), the receive steering angle and detection quality.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_Content = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_Content_applied_roll = R"doc(roll applied to the data (rad))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_Content_data_field_size = R"doc(size in bytes of each per-beam detection record)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_Content_detection_algorithm = R"doc(detection algorithm (0-7: G1/G2/G3/IF1/PS1/HS1/HS2))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_Content_flags = R"doc(flags bit field (uncertainty method, multi-detect, ...))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_Content_multi_ping = R"doc(0 = single ping, else multi-ping sequence number)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_Content_number_beams = R"doc(number of detection points (beams))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_Content_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_Content_ping_number = R"doc(sequential ping number)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_Content_reserved = R"doc(reserved)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_Content_sampling_rate = R"doc(sample rate (Hz))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_Content_serial_number = R"doc(sonar serial number)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_Content_tx_angle = R"doc(transmit steering angle (rad))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_RawDetection = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_beams = R"doc(per-beam raw detections)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_beams_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_content = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_from_stream_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_from_stream_3 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_get_applied_roll = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_get_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_get_data_field_size = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_get_detection_algorithm = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_get_flags = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_get_multi_ping = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_get_number_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_get_ping_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_get_sampling_rate = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_get_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_get_tx_angle = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_set_applied_roll = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_set_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_set_data_field_size = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_set_detection_algorithm = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_set_flags = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_set_multi_ping = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_set_number_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_set_ping_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_set_sampling_rate = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_set_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_set_tx_angle = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_RawDetection_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


