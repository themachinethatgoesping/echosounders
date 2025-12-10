//sourcehash: c75949c2b63de176a17a738fe115ce2785f959395147e6ffeb62fd8c8c1edddb

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


static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_AttitudeDatagramAttitude =
R"doc(The beam data are given re the transmit transducer or sonar head depth
and the horizontal location (x,y) of the active positioning system's
reference point. Heave, roll, pitch, sound speed at the transducer
depth and ray bending through the water column have been applied.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_AttitudeDatagramAttitude_AttitudeDatagramAttitude = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_AttitudeDatagramAttitude_get_heading = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_AttitudeDatagramAttitude_get_heading_in_degrees =
R"doc(Returns the heading in degrees.

Returns:
    _heading * 0.01f (float))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_AttitudeDatagramAttitude_get_heave = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_AttitudeDatagramAttitude_get_heave_in_meters =
R"doc(Returns the heave in meters.

Returns:
    _heave * 0.01f (float))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_AttitudeDatagramAttitude_get_pitch = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_AttitudeDatagramAttitude_get_pitch_in_degrees =
R"doc(Returns the pitch in degrees.

Returns:
    _pitch * 0.01f (float))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_AttitudeDatagramAttitude_get_roll = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_AttitudeDatagramAttitude_get_roll_in_degrees =
R"doc(Returns the roll in degrees.

Returns:
    _roll * 0.01f (float))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_AttitudeDatagramAttitude_get_sensor_status = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_AttitudeDatagramAttitude_get_time = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_AttitudeDatagramAttitude_get_time_in_seconds =
R"doc(Returns the time in seconds since record start.

Returns:
    _time * 0.001f (float))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_AttitudeDatagramAttitude_heading = R"doc(in 0.01°)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_AttitudeDatagramAttitude_heave = R"doc(in cm)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_AttitudeDatagramAttitude_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_AttitudeDatagramAttitude_pitch = R"doc(in 0.01°)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_AttitudeDatagramAttitude_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_AttitudeDatagramAttitude_roll = R"doc(in 0.01°)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_AttitudeDatagramAttitude_sensor_status = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_AttitudeDatagramAttitude_set_heading = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_AttitudeDatagramAttitude_set_heave = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_AttitudeDatagramAttitude_set_pitch = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_AttitudeDatagramAttitude_set_roll = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_AttitudeDatagramAttitude_set_sensor_status = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_AttitudeDatagramAttitude_set_time = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_AttitudeDatagramAttitude_time = R"doc(in_milliseconds_since_record_start)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


