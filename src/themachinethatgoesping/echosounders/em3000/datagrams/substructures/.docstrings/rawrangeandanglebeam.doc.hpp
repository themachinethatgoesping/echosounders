//sourcehash: 8dc84551342cd893654115e868034e4dc7b707993eb64ec1db6ba482a9c6544e

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


static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam =
R"doc(The beam data are given re the transmit transducer or sonar head depth
and the horizontal location (x,y) of the active positioning system's
reference point. Heave, roll, pitch, sound speed at the transducer
depth and ray bending through the water column have been applied.)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_RawRangeAndAngleBeam = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_beam_pointing_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_d_corr = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_detection_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_detection_window_length_in_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_get_backscatter_is_compensated =
R"doc(This function evaluates the detection information flag. If the 4th bit
is set to 1, the detection is compensated for beam incident angle. If
the 4th bit is set to 0, the detection is not compensated for beam
incident angle.

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_get_beam_pointing_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_get_beam_pointing_angle_in_degrees =
R"doc(Get the beam pointing angle in °

Returns:
    _beam_pointing_angle * 0.01 (float))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_get_d_corr = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_get_detection_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_get_detection_is_valid =
R"doc(This function evaluates the detection information flag. If the last
bit is set to 1, the detection is valid. If the last bit is set to 0,
the detection is invalid.

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_get_detection_type =
R"doc(This function evaluates the detection information flag. The first 3
bits indicate the type of detection.

Returns:
    t_DetectionType)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_get_detection_window_length_in_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_get_quality_factor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_get_realtime_cleaning_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_get_reflectivity = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_get_reflectivity_in_db =
R"doc(Get the reflectivity in db

Returns:
    _reflectivity * 0.1 (float))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_get_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_get_transmit_sector_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_get_two_way_travel_time = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_quality_factor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_realtime_cleaning_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_reflectivity = R"doc(< in 0.1 dB resolution)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_set_beam_pointing_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_set_d_corr = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_set_detection_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_set_detection_window_length_in_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_set_quality_factor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_set_realtime_cleaning_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_set_reflectivity = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_set_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_set_transmit_sector_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_set_two_way_travel_time = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_transmit_sector_number = R"doc(M relative RX array in 0.01°)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_RawRangeAndAngleBeam_two_way_travel_time = R"doc(< in s)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


