//sourcehash: cd580e582f9552dd2de64169a45077db6ab8dd1f2a22587a21a76216c304e7e9

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


static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_detection_information_get_backscatter_is_compensated =
R"doc(This function evaluates the detection information flag. If the 4th bit
is set to 1, the detection is compensated for beam incident angle. If
the 4th bit is set to 0, the detection is not compensated for beam
incident angle.

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_detection_information_get_detection_is_valid =
R"doc(This function evaluates a detection information flag. If the most
significant bit is set to 0, the detection is valid. If the most
significant bit is set to 1, the detection is invalid.

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_detection_information_get_detection_type =
R"doc(This function evaluates the detection information flag. The first 3
bits indicate the type of detection.

Returns:
    t_DetectionType)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_detection_information_t_DetectionType =
R"doc(The detection_info flag (uint8_t) is used in XYZDatagramBeam and
ExtraDectionsExtraDetections to indicate the type of detection.)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_detection_information_t_DetectionType_AmplitudeDetect = R"doc(< Valid, amplitude detection was used)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_detection_information_t_DetectionType_Estimated = R"doc(< Invalid: Therefor estimated)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_detection_information_t_DetectionType_Interpolated = R"doc(< Invalid: Therefor interpolated or extrapolated)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_detection_information_t_DetectionType_Invalid = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_detection_information_t_DetectionType_InvalidNormalDetection = R"doc(< Invalid: Normal detection)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_detection_information_t_DetectionType_NoDetection = R"doc(< Invalid: No detection data is available for this beam)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_detection_information_t_DetectionType_PhaseDetect = R"doc(< Valid, phase detection was used)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_detection_information_t_DetectionType_Rejected = R"doc(< Invalid: Therefor rejected)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


