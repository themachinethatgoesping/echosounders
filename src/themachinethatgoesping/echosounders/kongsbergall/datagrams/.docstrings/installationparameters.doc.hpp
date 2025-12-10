//sourcehash: 322907e8d232e005c5332db0a403faa61f91ca01c199e8fc7be5412e57001095

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


static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters =
R"doc(This datagram is an ASCII datagram except for the header which is
formatted as in all other output datagrams. The datagram is issued as
a start datagram when logging is switched on and as a stop datagram
when logging is turned off, i.e. at the start and end of a survey
line. It may also be sent to a remote port as an information datagram.
It is usually followed by a sound speed profile datagram. In the
datagram all ASCII fields start with a unique three character
identifier followed by "=". This should be used when searching for a
specific field as the position of a field within the datagram is not
guaranteed. The number or character part following is in a variable
format with a minus sign and decimal point if needed, and with "," as
the field delimiter. The format may at any time later be expanded with
the addition of new fields at any place in the datagram.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_InstallationParameters = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_InstallationParameters_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_build_channel_id = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_checksum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_etx = R"doc(end identifier (always 0x03))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_from_stream_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_from_stream_3 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_get_active_attitude_velocity_sensor =
R"doc(Get the active attitude velocity sensor (not active, 1 or 2)
0: not used
1: Attitude Velocity Sensor 1 (assumed to be physical equal to
   Attitude sensor 1)
2: Attitude Velocity Sensor 2 (assumed to be physical equal to
   Attitude sensor 2)

Returns:
    o_KongsbergAllActiveSensor)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_get_active_heading_sensor =
R"doc(Get the active heading sensor (0-9) here returned as an enum

Returns:
    o_KongsbergAllActiveSensor)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_get_active_heave_sensor =
R"doc(Get the active heave sensor (2, 3, 8 or 9) here returned as an enum

Returns:
    o_KongsbergAllActiveSensor)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_get_active_pitch_roll_sensor =
R"doc(Get the active roll pitch sensor (2, 3, 8 or 9) here returned as an
enum

Returns:
    o_KongsbergAllActiveSensor)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_get_active_position_system_number =
R"doc(Get the active position system number (APS + 1)
Returns:
    uint8_t)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_get_attitude_sensor_offsets =
R"doc(Get the attitude sensor offsets of sensor 1 or 2

Args:
    sensor_number: o_KongsbergAllActiveSensor (enum)

Returns:
    navigation::datastructures::PositionalOffsets)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_get_attitude_sensor_offsets_2 =
R"doc(Get the attitude sensor offsets of sensor 1 or 2

Args:
    sensor_number: must be 1 or 2

Returns:
    navigation::datastructures::PositionalOffsets)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_get_checksum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_get_compass_offsets =
R"doc(Get the compass sensor offsets (Gyrocompass) Includes heading offset
only

Returns:
    navigation::datastructures::PositionalOffsets)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_get_depth_sensor_offsets =
R"doc(Get the depth sensor offsets

Returns:
    navigation::datastructures::PositionalOffsets)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_get_etx = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_get_position_system_offsets =
R"doc(Get the position system offsets of system 1, 2 or 3

Args:
    position_system_number: must be 1, 2 or 3

Returns:
    navigation::datastructures::PositionalOffsets)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_get_rx1_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_get_rx2_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_get_rx_array_size = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_get_secondary_system_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_get_sensor_offsets =
R"doc(Internal function to get the sensor offsets from the installation
parameters. Possible sensor prefixes are:
- MS for attitude sensor 1 - NS for attitude sensor 2 - P1 for
  position system 1 - P2 for position system 2 - P3 for position
  system 3 - S1 for transducer 1 - S2 for transducer 2 - S3 for
  transducer 3 - DS for depth (pressure) sensor

Args:
    sensor_name: e.g. Attitude sensor 1
    sensor_prefix: see above
    has_xyz: sensor has xyz offsets
    has_ypr: sensor has yaw pitch roll offsets

Returns:
    PositionalOffsets)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_get_system_main_head_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_get_system_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_get_system_transducer_configuration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_get_transducer_offsets =
R"doc(Get the transducer offsets of transducer 0, 1, 2 or 3

Args:
    position_system_number: must be 0, 1, 2 or 3

Returns:
    navigation::datastructures::PositionalOffsets)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_get_tx2_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_get_tx_array_size = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_get_tx_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_get_value_float = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_get_value_float_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_get_value_int = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_get_value_int_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_get_value_string = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_get_value_string_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_get_water_line_vertical_location_in_meters = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_installation_parameters = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_installation_parameters_counter = R"doc(Sequential Number)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_is_dual_rx = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_merge =
R"doc(Merge two InstallationParameters datagrams into one If the datagrams
differ because an uncritical key does not exist in one of them, the
uncritical key will be added to the resulting datagram.

Args:
    first: 
    second: 

Returns:
    InstallationParameters)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_parsed_installation_parameters = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_read_installation_parameters = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_read_installation_parameters_counter = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_read_installation_parameters_parsed = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_reparse_installation_parameters =
R"doc(parse the installation parameters string into a map This happens when
the datagram is read from a file, but must be called manually when the
installation parameters string is changed manually.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_secondary_system_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_set_checksum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_set_etx = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_set_installation_parameters = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_set_installation_parameters_counter = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_set_secondary_system_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_set_system_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_system_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_to_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_InstallationParameters_unsupported_option_string = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


