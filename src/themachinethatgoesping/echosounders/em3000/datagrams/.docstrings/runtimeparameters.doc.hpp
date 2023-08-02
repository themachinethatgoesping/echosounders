//sourcehash: 732f95df0b520c8dafde3f0e3e88170baf4695fe66d32ce9084c5f1c8a004de1

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


static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters = R"doc(Runtime parameters datagrams)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_RuntimeParameters = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_RuntimeParameters_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_absorption_coefficient = R"doc(< in 0.01 dB/km)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_beam_spacing = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_bsp_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_etx = R"doc(< end identifier (always 0x03))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_filter_identifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_filter_identifier2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_from_stream_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_absorption_coefficient = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_absorption_coefficient_in_db_per_meter =
R"doc(Get the absorption coefficient in db per meter

Returns:
    _absorption_coefficient * 0.00001f (float))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_beam_spacing = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_bsp_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_filter_identifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_filter_identifier2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_maximum_depth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_maximum_port_coverage = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_maximum_port_swath_width = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_maximum_starboard_coverage = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_maximum_starboard_swath_width = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_minimum_depth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_mode = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_mode2_or_receiver_fixed_gain_setting = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_operator_station_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_ping_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_processing_unit_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_receive_bandwidth_50hz = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_receive_bandwidth_in_hertz =
R"doc(Get the receive bandwidth in Hz

Returns:
    _receive_bandwidth_50hz * 50.f (float))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_receive_beamwidth_degree = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_receive_beamwidth_in_degrees =
R"doc(Get the receive beamwidth in degrees

Returns:
    _receive_beamwidth_degree * 0.1f (float))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_sonar_head_or_transceiver_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_source_of_sound_speed_at_transducer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_transmit_along_tilt = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_transmit_along_tilt_in_degrees =
R"doc(Get the transmit along tilt in degrees

Returns:
    _transmit_along_tilt * 0.1f (float))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_transmit_beamwidth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_transmit_beamwidth_in_degrees =
R"doc(Get the transmit beamwidth in degrees

Returns:
    _transmit_beamwidth * 0.1f (float))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_transmit_power_relative_maximum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_transmit_pulse_length = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_transmit_pulse_length_in_seconds =
R"doc(Get the transmit pulse length in seconds

Returns:
    _transmit_pulse_length * 0.000001f (float))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_tvg_law_crossover_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_get_yaw_and_pitch_stabilization_mode = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_hash_content_only = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_maximum_depth = R"doc(< in meter)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_maximum_port_coverage = R"doc(< in degrees)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_maximum_port_swath_width = R"doc(< in meter)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_maximum_starboard_coverage = R"doc(< in degrees)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_maximum_starboard_swath_width = R"doc(< in meter)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_minimum_depth = R"doc(< in meter)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_mode = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_mode2_or_receiver_fixed_gain_setting = R"doc(< in dB)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_operator_station_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_ping_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_processing_unit_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_receive_bandwidth_50hz = R"doc(< in 50 Hz resolution)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_receive_beamwidth_degree = R"doc(< in 0.1 degrees)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_set_absorption_coefficient = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_set_beam_spacing = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_set_bsp_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_set_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_set_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_set_filter_identifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_set_filter_identifier2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_set_maximum_depth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_set_maximum_port_coverage = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_set_maximum_port_swath_width = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_set_maximum_starboard_coverage = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_set_maximum_starboard_swath_width = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_set_minimum_depth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_set_mode = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_set_mode2_or_receiver_fixed_gain_setting = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_set_operator_station_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_set_ping_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_set_processing_unit_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_set_receive_bandwidth_50hz = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_set_receive_beamwidth_degree = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_set_sonar_head_or_transceiver_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_set_source_of_sound_speed_at_transducer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_set_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_set_transmit_along_tilt = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_set_transmit_beamwidth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_set_transmit_power_relative_maximum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_set_transmit_pulse_length = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_set_tvg_law_crossover_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_set_yaw_and_pitch_stabilization_mode = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_sonar_head_or_transceiver_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_source_of_sound_speed_at_transducer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_transmit_along_tilt = R"doc(< in 0.1 degree)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_transmit_beamwidth = R"doc(< in 0.1 degrees)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_transmit_power_relative_maximum = R"doc(< in dB)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_transmit_pulse_length = R"doc(< in μs)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_tvg_law_crossover_angle = R"doc(< in degrees)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RuntimeParameters_yaw_and_pitch_stabilization_mode = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


