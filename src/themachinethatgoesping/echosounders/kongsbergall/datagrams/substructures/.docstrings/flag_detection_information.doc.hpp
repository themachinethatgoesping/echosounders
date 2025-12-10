//sourcehash: f0cd24f90366fa5b88c90d68d5b8317340ab31bbf278911631d339ca94c1cfef

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


static const char *mkd_doc__unnamed_class_at_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_flag_detection_information_hpp_78_67 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_detection_information_get_backscatter_is_compensated =
R"doc(This function evaluates the detection information flag. If the 4th bit
is set to 1, the detection is compensated for beam incident angle. If
the 4th bit is set to 0, the detection is not compensated for beam
incident angle.

Returns:
    true false)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_detection_information_get_detection_is_valid =
R"doc(This function evaluates a detection information flag. If the most
significant bit is set to 0, the detection is valid. If the most
significant bit is set to 1, the detection is invalid.

Returns:
    true false)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_detection_information_get_detection_type =
R"doc(This function evaluates the detection information flag. The first 3
bits indicate the type of detection.

Returns:
    t_DetectionType)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_detection_information_t_DetectionType =
R"doc(The detection_info flag (uint8_t) is used in XYZDatagramBeam and
ExtraDectionsExtraDetections to indicate the type of detection.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_detection_information_t_DetectionType_AmplitudeDetect = R"doc(Valid, amplitude detection was used)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_detection_information_t_DetectionType_Estimated = R"doc(Invalid: Therefor estimated)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_detection_information_t_DetectionType_Interpolated = R"doc(Invalid: Therefor interpolated or extrapolated)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_detection_information_t_DetectionType_Invalid = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_detection_information_t_DetectionType_InvalidNormalDetection = R"doc(Invalid: Normal detection)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_detection_information_t_DetectionType_NoDetection = R"doc(Invalid: No detection data is available for this beam)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_detection_information_t_DetectionType_PhaseDetect = R"doc(Valid, phase detection was used)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_detection_information_t_DetectionType_Rejected = R"doc(Invalid: Therefor rejected)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


