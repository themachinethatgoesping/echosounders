//sourcehash: db2623aeed1f2746cf352be3b81d22a44e219c7b2458ba0460f6fa9690a9e39c

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


static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram =
R"doc(This datagram will contain the profile actually used in the real time
raybending calculations to convert range and angle to xyz data. It
will usually be issued together with the installation parameter
datagram.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_SoundSpeedProfileDatagram = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_SoundSpeedProfileDatagram_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_checksum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_depth_resolution = R"doc(in cm)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_depths_and_sound_speeds = R"doc(2xN array of depth in cm and sound speed in dm/s)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_depths_and_sound_speeds_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_etx = R"doc(end identifier (always 0x03))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_from_stream_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_from_stream_3 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_get_checksum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_get_depth_resolution = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_get_depth_resolution_in_meters =
R"doc(return the depths in meters

Returns:
    _depth_resolution * 0.01 (float))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_get_depths_and_sound_speeds = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_get_depths_in_meters =
R"doc(return the depths in meters by multiplying the depths by 0.01

Returns:
    np.array([_number_of_entries], dtype = np.float64))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_get_etx = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_get_number_of_entries = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_get_profile_counter = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_get_profile_date = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_get_profile_date_string =
R"doc(Get the profile time as string

Args:
    fractionalSecondsDigits: 
    format: 

Returns:
    std::string)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_get_profile_time_since_midnight = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_get_profile_timestamp =
R"doc(convert the profile date and time_since_midnight field to a unix
timestamp

Returns:
    unixtime as double)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_get_sound_speeds_in_meters_per_second =
R"doc(return sound speeds in meter per second by multiplying the
sound_speeds by 0.1

Returns:
    np.array([_number_of_entries], dtype = np.float32))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_get_spare = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_get_system_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_number_of_entries = R"doc(N)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_profile_counter = R"doc(Sequential Number)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_profile_date = R"doc(year*10000 + month*100 + day (when profile was taken))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_profile_time_since_midnight = R"doc(time since midnight in milliseconds (when profile was taken))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_set_checksum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_set_depth_resolution = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_set_depths_and_sound_speeds = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_set_etx = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_set_number_of_entries = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_set_profile_counter = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_set_profile_date = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_set_profile_time_since_midnight = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_set_spare = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_set_system_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_spare = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_system_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


