//sourcehash: 5e0125503416548f261d22c5442c96bb75d248789d633968242752f649a71b55

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


static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam =
R"doc(The beam data are given re the transmit transducer or sonar head depth
and the horizontal location (x,y) of the active positioning system's
reference point. Heave, roll, pitch, sound speed at the transducer
depth and ray bending through the water column have been applied.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_RawRangeAndAngleBeam = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_beam_crosstrack_angle = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_d_corr = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_detection_info = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_detection_window_length_in_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_get_backscatter_is_compensated =
R"doc(This function evaluates the detection information flag. If the 4th bit
is set to 1, the detection is compensated for beam incident angle. If
the 4th bit is set to 0, the detection is not compensated for beam
incident angle.

Returns:
    true false)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_get_beam_crosstrack_angle = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_get_beam_crosstrack_angle_in_degrees =
R"doc(Get the beam crosstrack angle in °

Returns:
    _beam_crosstrack_angle * 0.01 (float))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_get_d_corr = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_get_detection_info = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_get_detection_is_valid =
R"doc(This function evaluates the detection information flag. If the last
bit is set to 1, the detection is valid. If the last bit is set to 0,
the detection is invalid.

Returns:
    true false)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_get_detection_type =
R"doc(This function evaluates the detection information flag. The first 3
bits indicate the type of detection.

Returns:
    t_DetectionType)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_get_detection_window_length_in_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_get_quality_factor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_get_realtime_cleaning_info = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_get_reflectivity = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_get_reflectivity_in_db =
R"doc(Get the reflectivity in db

Returns:
    _reflectivity * 0.1 (float))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_get_spare = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_get_transmit_sector_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_get_two_way_travel_time = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_quality_factor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_realtime_cleaning_info = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_reflectivity = R"doc(in 0.1 dB resolution)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_set_beam_crosstrack_angle = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_set_d_corr = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_set_detection_info = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_set_detection_window_length_in_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_set_quality_factor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_set_realtime_cleaning_info = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_set_reflectivity = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_set_spare = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_set_transmit_sector_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_set_two_way_travel_time = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_spare = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_transmit_sector_number = R"doc(M relative RX array in 0.01°)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleBeam_two_way_travel_time = R"doc(in s)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


