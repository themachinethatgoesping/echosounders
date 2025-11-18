//sourcehash: 2320dc6782d148410c5155840fd80955e700e5685c56ffa8f5334d4fa0a14c54

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


static const char *__doc__unnamed_class_at_themachinethatgoesping_echosounders_kmall_datagrams_skmbinary_hpp_315_67 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary = R"doc(Clock datagrams)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_Content = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_Content_bytes_content = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_Content_number_of_bytes_per_sample = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_Content_number_of_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_Content_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_Content_sensor_data_contents = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_Content_sensor_format = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_Content_sensor_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_Content_sensor_system = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_bytes_content = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_datagram_identifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_dgm_version = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_down_acceleration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_east_acceleration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_ellipsoid_height_error_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_ellipsoid_height_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_get_acceleration_reduced_performance = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_get_acceleration_valid = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_get_delayed_heave1_reduced_performance = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_get_delayed_heave1_valid = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_get_delayed_heave2_reduced_performance = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_get_delayed_heave2_valid = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_get_heading_reduced_performance = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_get_heading_valid = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_get_heave_reduced_performance = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_get_heave_valid = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_get_horizontal_position_and_velocity_reduced_performance = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_get_horizontal_position_and_velocity_valid = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_get_roll_and_pitch_reduced_performance = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_get_roll_and_pitch_valid = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_get_sensor_date_string = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_get_sensor_timestamp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_get_status_bits = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_heading_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_heading_error_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_heave_error_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_heave_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_latitude_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_latitude_error_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_longitude_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_longitude_error_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_north_acceleration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_pitch_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_pitch_error_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_pitch_rate = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_roll_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_roll_error_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_roll_rate = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_set_acceleration_reduced_performance = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_set_acceleration_valid = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_set_delayed_heave1_reduced_performance = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_set_delayed_heave1_valid = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_set_delayed_heave2_reduced_performance = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_set_delayed_heave2_valid = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_set_heading_reduced_performance = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_set_heading_valid = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_set_heave_reduced_performance = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_set_heave_valid = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_set_horizontal_position_and_velocity_reduced_performance = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_set_horizontal_position_and_velocity_valid = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_set_roll_and_pitch_reduced_performance = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_set_roll_and_pitch_valid = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_set_status_bits = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_time_nanosec = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_time_sec = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_vel_down = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_vel_east = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_vel_north = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMBinary_yaw_rate = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMDelayedHeave = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMDelayedHeave_delayed_heave_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMDelayedHeave_get_sensor_date_string = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMDelayedHeave_get_sensor_timestamp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMDelayedHeave_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMDelayedHeave_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMDelayedHeave_time_nanosec = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_KMDelayedHeave_time_sec = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_SKMBinary = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_SKMSample = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_SKMSample_km_binary = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_SKMSample_km_delayed_heave = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_SKMSample_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_SKMSample_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_bytes_datagram_check =
R"doc(< Each datagram ends with the size of the datagram for < integrity
check)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_content = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_from_stream_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_get_acceleration_active = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_get_bytes_content = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_get_bytes_datagram_check = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_get_delayed_heave1_active = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_get_delayed_heave2_active = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_get_heading_active = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_get_heave_active = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_get_horizontal_position_and_velocity_active = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_get_number_of_bytes_per_sample = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_get_number_of_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_get_roll_and_pitch_active = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_get_sensor_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_get_sensor_data_contents = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_get_sensor_data_contents_bits = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_get_sensor_format = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_get_sensor_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_get_sensor_system = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_sensor_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_set_acceleration_active = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_set_bytes_content = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_set_bytes_datagram_check = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_set_delayed_heave1_active = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_set_delayed_heave2_active = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_set_heading_active = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_set_heave_active = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_set_horizontal_position_and_velocity_active = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_set_number_of_bytes_per_sample = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_set_number_of_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_set_roll_and_pitch_active = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_set_sensor_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_set_sensor_data_contents = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_set_sensor_format = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_set_sensor_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_set_sensor_system = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_t_sensor_format = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_t_sensor_format_EM_3000_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_t_sensor_format_KM_binary_Sensor_Input = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_t_sensor_format_POS_M_V_GRP_102_103 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_t_sensor_format_Sagem = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_t_sensor_format_Seapath_binary_11 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_t_sensor_format_Seapath_binary_23 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_t_sensor_format_Seapath_binary_26 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SKMBinary_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


