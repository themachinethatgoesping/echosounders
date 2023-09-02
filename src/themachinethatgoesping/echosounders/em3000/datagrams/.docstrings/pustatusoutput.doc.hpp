//sourcehash: c4945ac616380199735591920b940c7f1357efc3003627b9f273da406ce81563

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


static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput =
R"doc(The PU Status datagram is sent out every second if requested by the
host processor. It has two functions, to indicate that the system is
alive and receiving sensor data, and to give sensor data regularly for
a potential screen update.)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_PUStatusOutput = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_PUStatusOutput_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_across_ship_velocity = R"doc(< in cm/s (or port coverage or spare))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_along_ship_velocity = R"doc(< in cm/s)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_attitude_status = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_attitude_velocity_sensor_status = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_backscatter_at_normal_incidence = R"doc(< in dB)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_backscatter_at_oblique_angle = R"doc(< in dB)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_clock_status = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_depth_to_normal_incidence = R"doc(< in m)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_distance_between_swath = R"doc(< in 10%)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_downward_velocity = R"doc(< in cm/s (or starboard coverage or spare))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_em2040_cpu_temperature = R"doc(< in degree Celsius (or spare))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_etx = R"doc(< end identifier (always 0x03))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_fixed_gain = R"doc(< in dB)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_from_stream_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_across_ship_velocity = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_across_ship_velocity_in_meters_per_second =
R"doc(Get the across ship velocity in m/s

Returns:
    _across_ship_velocity * 0.01f (float ))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_along_ship_velocity = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_along_ship_velocity_in_meters_per_second =
R"doc(Get the along ship velocity in m/s

Returns:
    _along_ship_velocity * 0.01f (float ))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_attitude_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_attitude_velocity_sensor_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_backscatter_at_normal_incidence = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_backscatter_at_oblique_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_clock_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_depth_to_normal_incidence = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_distance_between_swath = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_distance_between_swath_in_percent =
R"doc(Get the distance between swath in percent

Returns:
    _distance_between_swath * 0.1f (float ))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_downward_velocity = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_downward_velocity_in_meters_per_second =
R"doc(Get the downward velocity in m/s

Returns:
    _downward_velocity * 0.01f (float ))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_em2040_cpu_temperature = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_fixed_gain = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_heading_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_last_received_depth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_last_received_depth_in_meters =
R"doc(Get the last received depth in meters

Returns:
    _last_received_depth * 0.01f (float ))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_last_received_heading = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_last_received_heading_in_degrees =
R"doc(Get the last received heading in degrees

Returns:
    _last_received_heading * 0.01f (float ))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_last_received_heave_at_sonar_head = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_last_received_heave_at_sonar_head_in_meters =
R"doc(Get the last received heave at sonar head in m

Returns:
    _last_received_heave_at_sonar_head * 0.01f (float ))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_last_received_pitch = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_last_received_pitch_in_degrees =
R"doc(Get the last received pitch in degrees

Returns:
    _last_received_pitch * 0.01f (float ))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_last_received_roll = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_last_received_roll_in_degrees =
R"doc(Get the last received roll in degrees

Returns:
    _last_received_roll * 0.01f (float ))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_mammal_protection_ramp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_ping_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_ping_rate = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_ping_rate_hertz =
R"doc(Get the ping rate in Hz

Returns:
    _ping_rate * 0.01 Hz (float))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_port_coverage = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_position_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_pps_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_pu_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_range_to_normal_incidence = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_sensor_input_status_serial_port_1 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_sensor_input_status_serial_port_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_sensor_input_status_serial_port_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_sensor_input_status_serial_port_4 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_sensor_input_status_udp_port_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_sound_speed_at_transducer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_sound_speed_at_transducer_from_profile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_sound_speed_at_transducer_from_profile_in_meters_per_second =
R"doc(Get the sound speed at transducer (derived from profile) in m/s

Returns:
    _sound_speed_at_transducer_from_profile * 0.1f (float ))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_sound_speed_at_transducer_in_meters_per_second =
R"doc(Get the last received heave at sonar head in meters per second

Returns:
    _sound_speed_at_transducer * 0.1f (float ))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_starboard_coverage = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_status_datagram_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_yaw_stabilization_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_get_yaw_stabilization_angle_in_degrees =
R"doc(Get the yaw stabilization angle in degrees

Returns:
    _yaw_stabilization_angle * 0.01f (float ))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_heading_status = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_last_received_depth = R"doc(< in cm)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_last_received_heading = R"doc(< in 0.01 degree)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_last_received_heave_at_sonar_head = R"doc(< in cm)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_last_received_pitch = R"doc(< in 0.01 degree)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_last_received_roll = R"doc(< in 0.01 degree)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_mammal_protection_ramp = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_ping_counter = R"doc(< of latest ping)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_ping_rate = R"doc(< in 0.01 Hz)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_port_coverage = R"doc(< in degrees)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_position_status = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_pps_status = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_pu_status = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_range_to_normal_incidence = R"doc(< in m)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_sensor_input_status_serial_port_1 = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_sensor_input_status_serial_port_2 = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_sensor_input_status_serial_port_3 = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_sensor_input_status_serial_port_4 = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_sensor_input_status_udp_port_2 = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_across_ship_velocity = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_along_ship_velocity = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_attitude_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_attitude_velocity_sensor_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_backscatter_at_normal_incidence = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_backscatter_at_oblique_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_clock_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_depth_to_normal_incidence = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_distance_between_swath = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_downward_velocity = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_em2040_cpu_temperature = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_fixed_gain = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_heading_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_last_received_depth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_last_received_heading = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_last_received_heave_at_sonar_head = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_last_received_pitch = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_last_received_roll = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_mammal_protection_ramp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_ping_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_ping_rate = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_port_coverage = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_position_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_pps_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_pu_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_range_to_normal_incidence = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_sensor_input_status_serial_port_1 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_sensor_input_status_serial_port_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_sensor_input_status_serial_port_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_sensor_input_status_serial_port_4 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_sensor_input_status_udp_port_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_sound_speed_at_transducer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_sound_speed_at_transducer_from_profile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_starboard_coverage = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_status_datagram_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_set_yaw_stabilization_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_sound_speed_at_transducer = R"doc(< in dm/s)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_sound_speed_at_transducer_from_profile = R"doc(< in dm/s)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_starboard_coverage = R"doc(< in degrees)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_status_datagram_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_PUStatusOutput_yaw_stabilization_angle = R"doc(< in 0.01 degree, or tilt used at 3D scanning)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


