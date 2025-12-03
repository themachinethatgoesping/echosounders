//sourcehash: d1f5ee885f8d815fdaba70075826dd62f306438208bc23514a4fc851c62536aa

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


static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_MRZPingInfo = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_abs_coeff_db_per_km = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_active_modes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_attitude_sensor_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_beam_spacing = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_bs_correction_offset_db = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_bytes_content = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_depth_mode = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_detection_mode = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_distance_btw_swath = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_ellipsoid_height_re_ref_point_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_fixed_gain_control = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_frequency_mode_hz = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_frequency_range_high_Limit_hz = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_frequency_range_low_Limit_hz = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_abs_coeff_db_per_km = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_active_modes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_attitude_sensor_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_beam_spacing = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_bs_correction_offset_db = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_bytes_content = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_depth_mode = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_detection_mode = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_distance_btw_swath = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_ellipsoid_height_re_ref_point_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_fixed_gain_control = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_frequency_mode_hz = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_frequency_range_high_Limit_hz = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_frequency_range_low_Limit_hz = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_heading_vessel_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_ice_window = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_lamberts_law_applied = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_lat_long_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_latitude_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_longitude_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_max_eff_tx_band_width_hz = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_max_eff_tx_pulse_length_sec = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_max_total_tx_pulse_length_sec = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_mode_and_stabilisation = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_number_of_bytes_per_tx_Sector = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_number_of_tx_sectors = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_padding_0 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_padding_1 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_padding_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_padding_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_ping_rate_hz = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_pipe_tracking_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_port_mean_coverage_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_port_mean_coverage_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_port_sector_edge_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_position_sensor_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_pulse_form = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_runtime_filter_1 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_runtime_filter_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_rx_array_size_used_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_sl_ramp_up_time_remaining = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_sound_speed_at_tx_depth_m_per_sec = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_starboard_mean_coverage_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_starboard_mean_coverage_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_starboard_sector_edge_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_sub_depth_mode = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_tx_array_size_used_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_tx_power_db = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_tx_transducer_depth_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_x_kmall_to_all_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_y_kmall_to_all_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_yaw_angle_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_get_z_water_level_re_ref_point_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_heading_vessel_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_ice_window = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_lamberts_law_applied = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_lat_long_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_latitude_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_longitude_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_max_eff_tx_band_width_hz = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_max_eff_tx_pulse_length_sec = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_max_total_tx_pulse_length_sec = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_mode_and_stabilisation = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_number_of_bytes_per_tx_Sector = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_number_of_tx_sectors = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_padding_0 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_padding_1 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_padding_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_padding_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_ping_rate_hz = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_pipe_tracking_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_port_mean_coverage_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_port_mean_coverage_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_port_sector_edge_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_position_sensor_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_pulse_form = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_runtime_filter_1 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_runtime_filter_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_rx_array_size_used_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_abs_coeff_db_per_km = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_active_modes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_attitude_sensor_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_beam_spacing = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_bs_correction_offset_db = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_bytes_content = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_depth_mode = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_detection_mode = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_distance_btw_swath = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_ellipsoid_height_re_ref_point_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_fixed_gain_control = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_frequency_mode_hz = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_frequency_range_high_Limit_hz = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_frequency_range_low_Limit_hz = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_heading_vessel_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_ice_window = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_lamberts_law_applied = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_lat_long_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_latitude_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_longitude_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_max_eff_tx_band_width_hz = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_max_eff_tx_pulse_length_sec = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_max_total_tx_pulse_length_sec = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_mode_and_stabilisation = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_number_of_bytes_per_tx_Sector = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_number_of_tx_sectors = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_padding_0 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_padding_1 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_padding_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_padding_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_ping_rate_hz = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_pipe_tracking_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_port_mean_coverage_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_port_mean_coverage_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_port_sector_edge_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_position_sensor_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_pulse_form = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_runtime_filter_1 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_runtime_filter_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_rx_array_size_used_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_sl_ramp_up_time_remaining = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_sound_speed_at_tx_depth_m_per_sec = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_starboard_mean_coverage_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_starboard_mean_coverage_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_starboard_sector_edge_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_sub_depth_mode = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_tx_array_size_used_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_tx_power_db = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_tx_transducer_depth_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_x_kmall_to_all_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_y_kmall_to_all_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_yaw_angle_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_set_z_water_level_re_ref_point_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_sl_ramp_up_time_remaining = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_sound_speed_at_tx_depth_m_per_sec = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_starboard_mean_coverage_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_starboard_mean_coverage_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_starboard_sector_edge_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_sub_depth_mode = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_tx_array_size_used_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_tx_power_db = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_tx_transducer_depth_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_x_kmall_to_all_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_y_kmall_to_all_m = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_yaw_angle_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZPingInfo_z_water_level_re_ref_point_m = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


