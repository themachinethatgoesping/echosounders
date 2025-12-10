//sourcehash: 76d5a43ab313501174f102dd6768bfb3829a826140ff46d8be570ff90da6684a

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


static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram = R"doc(Depth (pressure) or height datagrams)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_PositionDatagram = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_PositionDatagram_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_checksum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_course = R"doc(over ground in 0.01°)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_etx = R"doc(end identifier (always 0x03))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_from_stream_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_from_stream_3 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_get_checksum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_get_course = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_get_course_in_degrees =
R"doc(Get the course of vessel in degrees

Returns:
    _course * 0.01° (float))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_get_etx = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_get_heading = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_get_heading_in_degrees =
R"doc(Get the heading of vessel in degrees

Returns:
    _heading * 0.01° (float))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_get_input_datagram = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_get_latitude = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_get_latitude_in_degrees =
R"doc(Get the latitude in degrees

Returns:
    _latitude * 0.00000005° (double))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_get_longitude = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_get_longitude_in_degrees =
R"doc(Get the longitude in degrees

Returns:
    _longitude * 0.0000001° (double))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_get_position_counter = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_get_position_fix_quality = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_get_position_fix_quality_in_meters =
R"doc(Get the position fix quality in meters

Returns:
    _position_fix_quality * 0.01m (float))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_get_position_system_SIMRAD90_flag =
R"doc(Evaluate if the position_system_descriptor for the used system number

xxxx 1xxx – the position may have to be derived from the input
datagram which is then in SIMRADRAW 90 format.

Returns:
    true or false (bool))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_get_position_system_descriptor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_get_position_system_number =
R"doc(Evaluate if the position_system_descriptor for the used system number

Returns:
    1, 2 or 3 (uint8_t ))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_get_position_system_system_time_has_been_used =
R"doc(Evaluate the position_system_descriptor for the used time

Returns:
    true: system time has been used
    false: input datagram time has been used)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_get_size_of_input_datagram = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_get_spare = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_get_speed = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_get_speed_in_meters_per_second =
R"doc(Get the speed of vessel in meter per second

Returns:
    _speed * 0.01m/s (float))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_get_system_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_heading = R"doc(in 0.01°)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_input_datagram = R"doc(as received (NMEA 0183);)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_latitude = R"doc(latitude in 0.00000005° negative if southern hemishpere)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_longitude = R"doc(longitude in 0.0000001° negative if western hemishpere)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_position_counter = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_position_fix_quality = R"doc(fix quality in cm;)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_position_system_descriptor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_set_checksum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_set_course = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_set_etx = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_set_heading = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_set_input_datagram = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_set_latitude = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_set_longitude = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_set_position_counter = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_set_position_fix_quality = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_set_position_system_descriptor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_set_size_of_input_datagram = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_set_spare = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_set_speed = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_set_system_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_size_of_input_datagram = R"doc(in input datagram;)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_spare = R"doc(only if required to make the datagram size even)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_speed = R"doc(over ground in cm/s)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_system_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_PositionDatagram_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


