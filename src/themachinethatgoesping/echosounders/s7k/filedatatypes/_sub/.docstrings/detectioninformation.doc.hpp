//sourcehash: 27c4c1a73d7dfcec33256b24e78befb44de0ac2a5cf69305b2e47af2971d55bd

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


static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_DetectionInformation =
R"doc(Lightweight bottom-detection information of a single s7k ping (7027
RawDetectionData).

The 7027 record may hold several detections per beam (multi-detect).
This structure reduces it to one value per beam number (the first
detection of each beam) for the two quantities the ping interfaces
need - the receive steering angle and the detected bottom sample -
plus the two record-wide scalars (sample rate and transmit angle). The
full record is therefore not retained.

The receive angles (fixed by the beamformer geometry, identical across
pings of the same mode) are deduplicated with a flyweight; the
detection points are unique per ping.

Note this is a private substructure and thus not part of the public
API or nanobind interface.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_DetectionInformation_DetectionInformation = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_DetectionInformation_DetectionInformation_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_DetectionInformation_detection_point_per_beam_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_DetectionInformation_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_DetectionInformation_get_detection_point_per_beam_number = R"doc(detected bottom sample number (fractional) per beam number)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_DetectionInformation_get_number_of_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_DetectionInformation_get_rx_angle_in_degrees_per_beam_number =
R"doc(receive steering angle (degrees) per beam number, nudged strictly
increasing (see ctor)

)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_DetectionInformation_get_sampling_rate = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_DetectionInformation_get_tx_angle_in_degrees = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_DetectionInformation_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_DetectionInformation_rx_angle_in_degrees_per_beam_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_DetectionInformation_sampling_rate = R"doc(sample rate of the detections (Hz))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_DetectionInformation_to_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_DetectionInformation_tx_angle_in_degrees = R"doc(transmit steering angle (degrees))doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


