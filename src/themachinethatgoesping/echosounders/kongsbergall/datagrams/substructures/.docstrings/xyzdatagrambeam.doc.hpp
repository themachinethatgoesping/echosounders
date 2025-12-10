//sourcehash: 8c4c553f0df58af82cffa53257d71cae7bc3f03cea67ca07690f625954ba3a3a

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


static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam =
R"doc(The beam data are given re the transmit transducer or sonar head depth
and the horizontal location (x,y) of the active positioning system's
reference point. Heave, roll, pitch, sound speed at the transducer
depth and ray bending through the water column have been applied.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_XYZDatagramBeam = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_acrosstrack_distance = R"doc(distance (y) in meter)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_alongtrack_distance = R"doc(distance (x) in meter)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_beam_incidence_angle_adjustment = R"doc((IBA) in 0.1 degree)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_depth = R"doc((Z) from transmit transducer in meter)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_detection_info = R"doc(Flag that indicates the type and validity of detection)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_detection_window_length = R"doc(in samples)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_get_acrosstrack_distance = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_get_alongtrack_distance = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_get_backscatter =
R"doc(convert reflectivity to backscatter (_reflectivity * 0.1 dB)

Returns:
    double)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_get_backscatter_is_compensated =
R"doc(This function evaluates the detection information flag. If the 4th bit
is set to 1, the detection is compensated for beam incident angle. If
the 4th bit is set to 0, the detection is not compensated for beam
incident angle.

Returns:
    true false)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_get_beam_incidence_angle_adjustment = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_get_beam_incidence_angle_adjustment_in_degrees =
R"doc(Returns the beam incidence angle adjustment in degrees. (IBA * 0.1
degree)

Returns:
    double)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_get_depth = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_get_detection_info = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_get_detection_is_valid =
R"doc(This function evaluates the detection information flag. If the last
bit is set to 1, the detection is valid. If the last bit is set to 0,
the detection is invalid.

Returns:
    true false)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_get_detection_type =
R"doc(This function evaluates the detection information flag. The first 3
bits indicate the type of detection.

Returns:
    t_DetectionType)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_get_detection_window_length = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_get_quality_factor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_get_realtime_cleaning_information = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_get_reflectivity = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_quality_factor =
R"doc(0-254 Scaled standard deviation (sd) of the range detection divided by
the detected range (dr) (qf = 250*sd/sr))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_realtime_cleaning_information =
R"doc(Flag that indicates if the beam was flagged by real time cleaning
(negative values indicate that this beam is flagged out))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_reflectivity = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_set_acrosstrack_distance = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_set_alongtrack_distance = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_set_beam_incidence_angle_adjustment = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_set_depth = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_set_detection_info = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_set_detection_window_length = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_set_quality_factor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_set_realtime_cleaning_information = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_XYZDatagramBeam_set_reflectivity = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


