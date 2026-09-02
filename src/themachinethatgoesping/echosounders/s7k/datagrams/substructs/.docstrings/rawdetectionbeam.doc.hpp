//sourcehash: 08644244403e11c9459b5cb29ffaa7f453e75779cc3b9e584f202948b0955e90

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


static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_RawDetectionBeam = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_RawDetectionBeam_RawDetectionBeam = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_RawDetectionBeam_beam_descriptor = R"doc(beam number)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_RawDetectionBeam_detection_point = R"doc(detection point (fractional sample number))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_RawDetectionBeam_flags = R"doc(per-beam flags (magnitude/phase detection, quality type, ...))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_RawDetectionBeam_get_beam_descriptor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_RawDetectionBeam_get_detection_point = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_RawDetectionBeam_get_flags = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_RawDetectionBeam_get_max_limit = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_RawDetectionBeam_get_min_limit = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_RawDetectionBeam_get_quality = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_RawDetectionBeam_get_rx_angle = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_RawDetectionBeam_get_signal_strength = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_RawDetectionBeam_get_uncertainty = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_RawDetectionBeam_max_limit = R"doc(detection gate maximum sample)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_RawDetectionBeam_min_limit = R"doc(detection gate minimum sample)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_RawDetectionBeam_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_RawDetectionBeam_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_RawDetectionBeam_quality = R"doc(per-beam quality (brightness/colinearity filter passed))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_RawDetectionBeam_rx_angle = R"doc(receive steering angle (rad))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_RawDetectionBeam_set_beam_descriptor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_RawDetectionBeam_set_detection_point = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_RawDetectionBeam_set_flags = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_RawDetectionBeam_set_max_limit = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_RawDetectionBeam_set_min_limit = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_RawDetectionBeam_set_quality = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_RawDetectionBeam_set_rx_angle = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_RawDetectionBeam_set_signal_strength = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_RawDetectionBeam_set_uncertainty = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_RawDetectionBeam_signal_strength = R"doc(detection signal strength)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_RawDetectionBeam_uncertainty = R"doc(detection uncertainty (normalized to detection point))doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


