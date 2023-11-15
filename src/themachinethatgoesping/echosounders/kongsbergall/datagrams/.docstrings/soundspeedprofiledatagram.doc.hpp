//sourcehash: 30e94870ef92a1190203e16525aa22296e3b24cfcb8bd62de573fdef4e2e9da2

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


static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram =
R"doc(This datagram will contain the profile actually used in the real time
raybending calculations to convert range and angle to xyz data. It
will usually be issued together with the installation parameter
datagram.)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_SoundSpeedProfileDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_SoundSpeedProfileDatagram_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_depth_resolution = R"doc(< in cm)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_depths_and_sound_speeds = R"doc(< 2xN array of depth in cm and sound speed in dm/s)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_depths_and_sound_speeds_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_etx = R"doc(< end identifier (always 0x03))doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_from_stream_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_get_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_get_depth_resolution = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_get_depth_resolution_in_meters =
R"doc(return the depths in meters

Returns:
    _depth_resolution * 0.01 (float))doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_get_depths_and_sound_speeds = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_get_depths_in_meters =
R"doc(return the depths in meters by multiplying the depths by 0.01

Returns:
    np.array([_number_of_entries], dtype = np.float64))doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_get_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_get_number_of_entries = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_get_profile_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_get_profile_date = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_get_profile_date_string =
R"doc(Get the profile time as string

Parameter ``fractionalSecondsDigits``:
    $Parameter ``format``:

Returns:
    std::string)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_get_profile_time_since_midnight = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_get_profile_timestamp =
R"doc(convert the profile date and time_since_midnight field to a unix
timestamp

Returns:
    unixtime as double)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_get_sound_speeds_in_meters_per_second =
R"doc(return sound speeds in meter per second by multiplying the
sound_speeds by 0.1

Returns:
    np.array([_number_of_entries], dtype = np.float32))doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_get_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_get_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_number_of_entries = R"doc(< N)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_profile_counter = R"doc(< Sequential Number)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_profile_date = R"doc(< year*10000 + month*100 + day (when profile was taken))doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_profile_time_since_midnight = R"doc(< time since midnight in milliseconds (when profile < was taken))doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_set_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_set_depth_resolution = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_set_depths_and_sound_speeds = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_set_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_set_number_of_entries = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_set_profile_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_set_profile_date = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_set_profile_time_since_midnight = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_set_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_set_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SoundSpeedProfileDatagram_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


