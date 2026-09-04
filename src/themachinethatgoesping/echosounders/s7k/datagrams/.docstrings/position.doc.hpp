//sourcehash: 1f692f45efe4b8f9b00369ec2e21b5d4291b211a4fd5336976424d2bb2283c85

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


static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position =
R"doc(7k Position Record (1003) used in conjunction with Record Type 1011
(Geodesy).)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_Content = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_Content_checksum = R"doc(record checksum (last 4 bytes; see S7KDatagram, debugging only))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_Content_datum_identifier = R"doc(datum identifier (0 = WGS84, >0 = reserved))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_Content_height = R"doc(height relative to datum in meters)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_Content_latency = R"doc(positioning latency in seconds (0 for 7k sonar / PDS))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_Content_latitude_or_northing = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_Content_longitude_or_easting = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_Content_number_of_satellites = R"doc(number of satellites (optional))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_Content_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_Content_position_method = R"doc(positioning method (GPS/DGPS/RTK/inertial))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_Content_position_type_flag = R"doc(0 = geographical, 1 = grid coordinates)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_Content_quality_flag = R"doc(0 = navigation data, 1 = dead-reckoning)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_Content_utm_zone = R"doc(UTM zone (if grid coordinates))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_Position = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_content = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_from_stream_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_from_stream_3 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_get_checksum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_get_datum_identifier = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_get_height = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_get_latency = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_get_latitude_in_degrees =
R"doc(Get the latitude in degrees (only meaningful for geographical
coordinates).
Returns:
    latitude_or_northing converted from radians to degrees.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_get_latitude_or_northing = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_get_longitude_in_degrees =
R"doc(Get the longitude in degrees (only meaningful for geographical
coordinates).
Returns:
    longitude_or_easting converted from radians to degrees.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_get_longitude_or_easting = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_get_number_of_satellites = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_get_position_method = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_get_position_type_flag = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_get_quality_flag = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_get_utm_zone = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_set_checksum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_set_datum_identifier = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_set_height = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_set_latency = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_set_latitude_or_northing = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_set_longitude_or_easting = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_set_number_of_satellites = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_set_position_method = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_set_position_type_flag = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_set_quality_flag = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_set_utm_zone = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_t_position_method = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_t_position_method_dgps = R"doc(DGPS)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_t_position_method_gps = R"doc(GPS)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_t_position_method_inertial_start_from_bottom_correlation = R"doc(start of inertial from bottom correlation)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_t_position_method_inertial_start_from_bottom_object = R"doc(start of inertial from bottom object)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_t_position_method_inertial_start_from_dgps = R"doc(start of inertial positioning from DGPS)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_t_position_method_inertial_start_from_gps = R"doc(start of inertial positioning from GPS)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_t_position_method_inertial_start_from_inertial = R"doc(start of inertial from inertial positioning)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_t_position_method_inertial_start_from_optional_data = R"doc(start of inertial from optional data)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_t_position_method_inertial_start_to_inertial = R"doc(start of inertial to inertial positioning)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_t_position_method_inertial_start_to_optional_data = R"doc(start of inertial to optional data)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_t_position_method_inertial_stop_to_bottom_correlation = R"doc(stop of inertial to bottom correlation)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_t_position_method_inertial_stop_to_bottom_object = R"doc(stop of inertial to bottom object)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_t_position_method_inertial_stop_to_dgps = R"doc(stop of inertial positioning to DGPS)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_t_position_method_inertial_stop_to_gps = R"doc(stop of inertial positioning to GPS)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_t_position_method_rtk_fixed = R"doc(RTK fixed)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_t_position_method_rtk_float = R"doc(RTK float)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_t_position_method_user_defined = R"doc(user defined)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_t_position_type_flag = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_t_position_type_flag_geographic = R"doc(geographical coordinates (latitude/longitude in radians))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_t_position_type_flag_grid = R"doc(grid coordinates (northing/easting in meters))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_t_quality_flag = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_t_quality_flag_dead_reckoning = R"doc(dead-reckoning)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_t_quality_flag_navigation = R"doc(navigation data)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_Position_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


