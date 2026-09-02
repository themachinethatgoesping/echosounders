//sourcehash: b61b54309197221afcc0b85cc037efb20f95509ab4a83cf92fb154beb0ce5d01

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


static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings = R"doc(7k record SonarSettings)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_absorption = R"doc(absorption)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_beamwidth_horizontal = R"doc(transmit -3dB beam width horizontal)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_beamwidth_vertical = R"doc(transmit -3dB beam width vertical)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_control_flags = R"doc(control flags bit field)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_depth_maximum = R"doc(bottom detection maximum depth)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_depth_minimum = R"doc(bottom detection minimum depth)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_focal_point = R"doc(transmit focal point)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_frequency = R"doc(transmit frequency)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_gain_selection = R"doc(gain selection)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_hydrophone_id = R"doc(receiver hydrophone identifier)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_max_ping_rate = R"doc(maximum ping rate)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_multi_ping = R"doc(0 = single ping, else multi-ping sequence number)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_ping_number = R"doc(sequential ping number)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_ping_period = R"doc(time since previous ping)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_power_selection = R"doc(power selection (dB re 1 uPa))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_projector_id = R"doc(transmit projector identifier)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_projector_weighting = R"doc(projector weighting window type (0-2))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_projector_weighting_parameter = R"doc(projector weighting parameter)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_range_maximum = R"doc(bottom detection maximum range)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_range_minimum = R"doc(bottom detection minimum range)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_range_selection = R"doc(range selection)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_receiver_bandwidth = R"doc(receiver bandwidth)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_reserved = R"doc(reserved)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_rx_flags = R"doc(receiver flags bit field)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_rx_weighting = R"doc(receiver weighting window type (0-1))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_rx_weighting_parameter = R"doc(receiver weighting parameter)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_rx_width = R"doc(receiver beam width)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_sample_rate = R"doc(sample rate)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_serial_number = R"doc(sonar serial number)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_sound_velocity = R"doc(sound velocity)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_spreading = R"doc(spreading loss)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_steering_horizontal = R"doc(transmit steering angle horizontal)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_steering_vertical = R"doc(transmit steering angle vertical)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_transmit_flags = R"doc(transmit flags bit field)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_tx_pulse_envelope = R"doc(envelope/window type (0-4))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_tx_pulse_envelope_parameter = R"doc(envelope parameter)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_tx_pulse_mode = R"doc(1-4 (single/multi-ping mode))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_tx_pulse_type = R"doc(0 = CW, 1 = chirp)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_Content_tx_pulse_width = R"doc(transmit pulse length)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_SonarSettings = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_content = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_from_stream_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_from_stream_3 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_absorption = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_beamwidth_horizontal = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_beamwidth_vertical = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_control_flags = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_depth_maximum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_depth_minimum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_focal_point = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_frequency = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_gain_selection = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_hydrophone_id = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_max_ping_rate = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_multi_ping = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_ping_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_ping_period = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_power_selection = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_projector_id = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_projector_weighting = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_projector_weighting_parameter = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_range_maximum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_range_minimum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_range_selection = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_receiver_bandwidth = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_rx_flags = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_rx_weighting = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_rx_weighting_parameter = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_rx_width = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_sample_rate = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_sound_velocity = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_spreading = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_steering_horizontal = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_steering_vertical = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_transmit_flags = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_tx_pulse_envelope = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_tx_pulse_envelope_parameter = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_tx_pulse_mode = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_tx_pulse_type = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_get_tx_pulse_width = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_absorption = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_beamwidth_horizontal = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_beamwidth_vertical = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_control_flags = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_depth_maximum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_depth_minimum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_focal_point = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_frequency = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_gain_selection = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_hydrophone_id = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_max_ping_rate = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_multi_ping = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_ping_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_ping_period = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_power_selection = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_projector_id = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_projector_weighting = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_projector_weighting_parameter = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_range_maximum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_range_minimum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_range_selection = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_receiver_bandwidth = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_rx_flags = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_rx_weighting = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_rx_weighting_parameter = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_rx_width = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_sample_rate = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_sound_velocity = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_spreading = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_steering_horizontal = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_steering_vertical = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_transmit_flags = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_tx_pulse_envelope = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_tx_pulse_envelope_parameter = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_tx_pulse_mode = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_tx_pulse_type = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_set_tx_pulse_width = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SonarSettings_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


