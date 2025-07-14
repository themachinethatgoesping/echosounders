//sourcehash: 798d9d419d9d6f7eed05971fba60adef85a6d7f91a3830d0ec384acdedaf397a

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


static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters = R"doc(Runtime parameters datagrams)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_RuntimeParameters = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_RuntimeParameters_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_absorption_coefficient = R"doc(< in 0.01 dB/km)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_beam_spacing = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_bsp_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_etx = R"doc(< end identifier (always 0x03))doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_filter_identifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_filter_identifier2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_from_stream_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_3d_scanning_enabled =
R"doc(Retrieves the 3D scanning option (On/Off) encoded in the 'source of
sound speed at transducer' variable

Returns:
    True if the 3D scanning option is enabled, false otherwise)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_absorption_coefficient = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_absorption_coefficient_in_db_per_meter =
R"doc(Get the absorption coefficient in db per meter

Returns:
    _absorption_coefficient * 0.00001f (float))doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_beam_spacing = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_beam_spacing_as_string =
R"doc(Retrieves beamspacing mode encoded in the beamspacing variable

The decoding is EM model specific. Currently only outputs sensefull
values for EM2040 and EM2040C. See datagram format specification for
details.

Parameter ``unhandled_message``:
    If provided, this message is used as the return value if the mode
    is not handled for the specific system. Otherwise: 'None' is
    returned

Returns:
    A string representing beamspacing as encoded by 'beamspacing')doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_bsp_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_extra_detections_enabled =
R"doc(Retrieves the Extra detections option (On/Off) encoded in the 'source
of sound speed at transducer' variable

Returns:
    True if the Extra detections option is enabled, false otherwise)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_filter_identifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_filter_identifier2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_filter_identifier2_as_detect_mode =
R"doc(Retrieves detect mode encoded in the filter_identifier2 variable

Returns:
    A string representing the detect mode as encoded by
    'filter_identifier2')doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_filter_identifier2_as_penetration_filter =
R"doc(Retrieves penetration filter setup encoded in the filter_identifier2
variable

Returns:
    A string representing the penetration filter setup as encoded by
    'filter_identifier2')doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_filter_identifier2_as_phase_ramp =
R"doc(Retrieves phase ramp encoded in the filter_identifier2 variable

Parameter ``unhandled_message``:
    If provided, this message is used as the return value if the value
    is not handled by the function. Otherwise: 'None' is returned

Returns:
    A string representing the phase ramp encoded by
    'filter_identifier2')doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_filter_identifier2_as_special_amp_detect =
R"doc(Retrieves the Special amp detect mode encoded in the
filter_identifier2 variable

EM3002 soft sediment detection = special amp detect

Returns:
    A string representing the Special amp detect mode (Normal/Special)
    as encoded by 'filter_identifier2')doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_filter_identifier2_as_special_tvg =
R"doc(Retrieves the Special TVG mode encoded in the filter_identifier2
variable

Returns:
    A string representing the Special TVG mode (Normal/Special) as
    encoded by 'filter_identifier2')doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_filter_identifier_as_aeration_filter =
R"doc(Retrieves the Aearation filter status encoded in the filter_identifier
variable

Returns:
    A string representing the Aeration filter status (On or Off) as
    encoded by 'filter_identifier')doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_filter_identifier_as_interference_filter =
R"doc(Retrieves the Interference filter status encoded in the
filter_identifier variable

Returns:
    A string representing the Interference filter status (On or Off)
    as encoded by 'filter_identifier')doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_filter_identifier_as_range_gates_size =
R"doc(Retrieves Range gates size encoded in the mode variable

Parameter ``unhandled_message``:
    If provided, this message is used as the return value if the range
    gates size is not handled by the function. Otherwise: 'None' is
    returned

Returns:
    A string representing Range gates size as encoded by 'mode')doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_filter_identifier_as_slope_filter =
R"doc(Retrieves slope filter status encoded in the filter_identifier
variable

Returns:
    A string representing the slope filter status (On or Off) as
    encoded by 'filter_identifier')doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_filter_identifier_as_spike_filter =
R"doc(Retrieves spike filter setup encoded in the filter_identifier variable

Returns:
    A string representing the spike filter setup as encoded by
    'filter_identifier')doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_maximum_depth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_maximum_port_coverage = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_maximum_port_swath_width = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_maximum_starboard_coverage = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_maximum_starboard_swath_width = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_minimum_depth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_mode = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_mode2_as_pulselength =
R"doc(Retrieves Pulselength encoded in the mode2 variable

The decoding is EM model specific. Currently only outputs sensefull
values for EM2040 and EM2040C. See datagram format specification for
details.

Parameter ``unhandled_message``:
    If provided, this message is used as the return value if the mode
    is not handled for the specific system. Otherwise: 'Sonar head use
    unhandled' is returned

Returns:
    A string representing Pulselength as encoded by 'mode2')doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_mode2_as_receive_fixed_gain_setting_dB =
R"doc(Retrieves receiver fixed gain setting encoded in the mode2 variable

The decoding is EM model specific. This only outputs sensefull values
for EM2000, EM1002, EM3000, EM3002, EM300, EM120. See datagram format
specification for details.

Parameter ``unhandled_value``:
    If provided, this value is used as the return value if the mode is
    not handled for the specific system. Otherwise: 'None' is returned

Returns:
    A uint8_t representing receiver fixed gain setting use as encoded
    by 'mode2')doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_mode2_as_rx_or_sonar_head_use =
R"doc(Retrieves Rx array/ sonar head encoded in the mode2 variable

The decoding is EM model specific. Currently only outputs sensefull
values for EM2040 and EM2040C. See datagram format specification for
details.

Parameter ``unhandled_message``:
    If provided, this message is used as the return value if the mode
    is not handled for the specific system. Otherwise: 'None' is
    returned

Returns:
    A string representing Rx array / Sonar head use as encoded by
    'mode2')doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_mode2_or_receiver_fixed_gain_setting = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_mode_as_dual_swath_mode =
R"doc(Retrieves Dual swath mode encoded in the mode variable

The decoding is EM model specific. See datagram format specification
for details.

Parameter ``unhandled_message``:
    If provided, this message is used as the return value if the mode
    is not handled for the specific system. Otherwise: None is
    returned

Returns:
    A string representing Tx pulse form as encoded by 'mode')doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_mode_as_ping_mode =
R"doc(Retrieves Ping mode decoded in the 'mode' variable.

The decoding is EM model specific. See datagram format specification
for details.

Parameter ``unhandled_message``:
    If provided, this message is used as the return value if the mode
    is not handled for the specific system. Otherwise: None is
    returned

Returns:
    A string representing Ping mode as encoded by 'mode')doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_mode_as_tx_pulse_form =
R"doc(Retrieves Tx pulse form encoded in the mode variable

The decoding is EM model specific. See datagram format specification
for details.

Parameter ``unhandled_message``:
    If provided, this message is used as the return value if the mode
    is not handled for the specific system. Otherwise: None is
    returned.

Returns:
    A string representing Tx pulse form as encoded by 'mode')doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_operator_station_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_passive_mode_enabled =
R"doc(Retrieves the Passive mode option (On/Off) encoded in the 'source of
sound speed at transducer' variable

Returns:
    True if the Passive mode option is enabled, false otherwise)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_ping_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_processing_unit_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_receive_bandwidth_50hz = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_receive_bandwidth_in_hertz =
R"doc(Get the receive bandwidth in Hz

Returns:
    _receive_bandwidth_50hz * 50.f (float))doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_receive_beamwidth_degree = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_receive_beamwidth_in_degrees =
R"doc(Get the receive beamwidth in degrees

Returns:
    _receive_beamwidth_degree * 0.1f (float))doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_sonar_head_or_transceiver_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_sonar_mode_enabled =
R"doc(Retrieves the Sonar mode option (On/Off) encoded in the 'source of
sound speed at transducer' variable

Returns:
    True if the Sonar mode option is enabled, false otherwise)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_source_of_sound_speed_at_transducer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_source_of_sound_speed_at_transducer_as_string =
R"doc(Retrieves the source of sound speed at transducer encoded in the
'source of sound speed at transducer' variable

Parameter ``unhandled_message``:
    If provided, this message is used as the return value if the
    source of sound speed at transducer mode specified is not handled.

Returns:
    A string representing the source of sound speed at transducer as
    encoded by the 'source of sound speed at transducer' variable)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_transmit_along_tilt = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_transmit_along_tilt_in_degrees =
R"doc(Get the transmit along tilt in degrees

Returns:
    _transmit_along_tilt * 0.1f (float))doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_transmit_beamwidth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_transmit_beamwidth_in_degrees =
R"doc(Get the transmit beamwidth in degrees

Returns:
    _transmit_beamwidth * 0.1f (float))doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_transmit_power_relative_maximum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_transmit_pulse_length = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_transmit_pulse_length_in_seconds =
R"doc(Get the transmit pulse length in seconds

Returns:
    _transmit_pulse_length * 0.000001f (float))doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_tvg_law_crossover_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_yaw_and_pitch_stabilization_mode = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_yaw_and_pitch_stabilization_mode_as_heading_filter =
R"doc(Retrieves heading filter mode encoded in the
yaw_and_pitch_stabilization_mode variable

Parameter ``unhandled_message``:
    If provided, this message is used as the return value if the mode
    is not handled by the function. Otherwise: 'None' is returned

Returns:
    A string representing heading filter mode as encoded by
    'yaw_and_pitch_stabilization_mode')doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_yaw_and_pitch_stabilization_mode_as_pitch_stibilization =
R"doc(Retrieves pitch stabilization mode (on/off) encoded in the
yaw_and_pitch_stabilization_mode variable

Returns:
    A string representing pitch stabilization mode as encoded by
    'yaw_and_pitch_stabilization_mode')doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_get_yaw_and_pitch_stabilization_mode_as_yaw_stabilization =
R"doc(Retrieves yaw and pitch stabilization mode encoded in the
yaw_and_pitch_stabilization_mode variable

Returns:
    A string representing yaw_and_pitch_stabilization_mode as encoded
    by 'yaw_and_pitch_stabilization_mode')doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_hash_content_only = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_maximum_depth = R"doc(< in meter)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_maximum_port_coverage = R"doc(< in degrees)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_maximum_port_swath_width = R"doc(< in meter)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_maximum_starboard_coverage = R"doc(< in degrees)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_maximum_starboard_swath_width = R"doc(< in meter)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_minimum_depth = R"doc(< in meter)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_mode = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_mode2_or_receiver_fixed_gain_setting = R"doc(< in dB)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_operator_station_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_ping_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_processing_unit_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_receive_bandwidth_50hz = R"doc(< in 50 Hz resolution)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_receive_beamwidth_degree = R"doc(< in 0.1 degrees)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_set_absorption_coefficient = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_set_beam_spacing = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_set_bsp_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_set_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_set_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_set_filter_identifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_set_filter_identifier2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_set_maximum_depth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_set_maximum_port_coverage = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_set_maximum_port_swath_width = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_set_maximum_starboard_coverage = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_set_maximum_starboard_swath_width = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_set_minimum_depth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_set_mode = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_set_mode2_or_receiver_fixed_gain_setting = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_set_operator_station_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_set_ping_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_set_processing_unit_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_set_receive_bandwidth_50hz = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_set_receive_beamwidth_degree = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_set_sonar_head_or_transceiver_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_set_source_of_sound_speed_at_transducer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_set_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_set_transmit_along_tilt = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_set_transmit_beamwidth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_set_transmit_power_relative_maximum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_set_transmit_pulse_length = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_set_tvg_law_crossover_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_set_yaw_and_pitch_stabilization_mode = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_sonar_head_or_transceiver_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_source_of_sound_speed_at_transducer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_transmit_along_tilt = R"doc(< in 0.1 degree)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_transmit_beamwidth = R"doc(< in 0.1 degrees)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_transmit_power_relative_maximum = R"doc(< in dB)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_transmit_pulse_length = R"doc(< in μs)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_tvg_law_crossover_angle = R"doc(< in degrees)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RuntimeParameters_yaw_and_pitch_stabilization_mode = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_hash_value =
R"doc(Provide a boost hash function for RuntimeParameters - Note: this is
needed to use RuntimeParameters as boost::flyweight - IMPORTANT: this
hash function only uses the content of the RuntimeParameters for
hashing (not information from header e.g. timestamp, ping counter
etc.)

Parameter ``data``:
    $Returns:

std::size_t)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


