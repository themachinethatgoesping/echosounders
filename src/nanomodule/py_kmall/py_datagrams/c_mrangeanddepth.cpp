// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/datetime.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/mrangeanddepth.hpp>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::MRangeAndDepth;

#define DOC_MRangeAndDepth(ARG)                                                                    \
    DOC(themachinethatgoesping, echosounders, kmall, datagrams, MRangeAndDepth, ARG)

void init_c_mrangeanddepth(nanobind::module_& m)
{
    nb::class_<MRangeAndDepth, datagrams::KMALLMultibeamDatagram>(
        m,
        "MRangeAndDepth",
        DOC(themachinethatgoesping, echosounders, kmall, datagrams, MRangeAndDepth))
        .def(nb::init<>(), DOC_MRangeAndDepth(MRangeAndDepth))

        // --- convenient data access ---
        .def("get_bytes_content",
             &MRangeAndDepth::get_bytes_content,
             DOC_MRangeAndDepth(get_bytes_content))
        .def("get_padding_0", &MRangeAndDepth::get_padding_0, DOC_MRangeAndDepth(get_padding_0))
        .def("get_ping_rate_hz",
             &MRangeAndDepth::get_ping_rate_hz,
             DOC_MRangeAndDepth(get_ping_rate_hz))
        .def("get_beam_spacing",
             &MRangeAndDepth::get_beam_spacing,
             DOC_MRangeAndDepth(get_beam_spacing))
        .def("get_depth_mode", &MRangeAndDepth::get_depth_mode, DOC_MRangeAndDepth(get_depth_mode))
        .def("get_sub_depth_mode",
             &MRangeAndDepth::get_sub_depth_mode,
             DOC_MRangeAndDepth(get_sub_depth_mode))
        .def("get_distance_btw_swath",
             &MRangeAndDepth::get_distance_btw_swath,
             DOC_MRangeAndDepth(get_distance_btw_swath))
        .def("get_detection_mode",
             &MRangeAndDepth::get_detection_mode,
             DOC_MRangeAndDepth(get_detection_mode))
        .def("get_pulse_form", &MRangeAndDepth::get_pulse_form, DOC_MRangeAndDepth(get_pulse_form))
        .def("get_fixed_gain_control",
             &MRangeAndDepth::get_fixed_gain_control,
             DOC_MRangeAndDepth(get_fixed_gain_control))
        .def("get_padding_1", &MRangeAndDepth::get_padding_1, DOC_MRangeAndDepth(get_padding_1))
        .def("get_frequency_mode_hz",
             &MRangeAndDepth::get_frequency_mode_hz,
             DOC_MRangeAndDepth(get_frequency_mode_hz))
        .def("get_frequency_range_low_Limit_hz",
             &MRangeAndDepth::get_frequency_range_low_Limit_hz,
             DOC_MRangeAndDepth(get_frequency_range_low_Limit_hz))
        .def("get_frequency_range_high_Limit_hz",
             &MRangeAndDepth::get_frequency_range_high_Limit_hz,
             DOC_MRangeAndDepth(get_frequency_range_high_Limit_hz))
        .def("get_max_total_tx_pulse_length_sec",
             &MRangeAndDepth::get_max_total_tx_pulse_length_sec,
             DOC_MRangeAndDepth(get_max_total_tx_pulse_length_sec))
        .def("get_max_eff_tx_pulse_length_sec",
             &MRangeAndDepth::get_max_eff_tx_pulse_length_sec,
             DOC_MRangeAndDepth(get_max_eff_tx_pulse_length_sec))
        .def("get_max_eff_tx_band_width_hz",
             &MRangeAndDepth::get_max_eff_tx_band_width_hz,
             DOC_MRangeAndDepth(get_max_eff_tx_band_width_hz))
        .def("get_abs_coeff_db_per_km",
             &MRangeAndDepth::get_abs_coeff_db_per_km,
             DOC_MRangeAndDepth(get_abs_coeff_db_per_km))
        .def("get_port_sector_edge_deg",
             &MRangeAndDepth::get_port_sector_edge_deg,
             DOC_MRangeAndDepth(get_port_sector_edge_deg))
        .def("get_starboard_sector_edge_deg",
             &MRangeAndDepth::get_starboard_sector_edge_deg,
             DOC_MRangeAndDepth(get_starboard_sector_edge_deg))
        .def("get_port_mean_coverage_deg",
             &MRangeAndDepth::get_port_mean_coverage_deg,
             DOC_MRangeAndDepth(get_port_mean_coverage_deg))
        .def("get_starboard_mean_coverage_deg",
             &MRangeAndDepth::get_starboard_mean_coverage_deg,
             DOC_MRangeAndDepth(get_starboard_mean_coverage_deg))
        .def("get_port_mean_coverage_m",
             &MRangeAndDepth::get_port_mean_coverage_m,
             DOC_MRangeAndDepth(get_port_mean_coverage_m))
        .def("get_starboard_mean_coverage_m",
             &MRangeAndDepth::get_starboard_mean_coverage_m,
             DOC_MRangeAndDepth(get_starboard_mean_coverage_m))
        .def("get_mode_and_stabilisation",
             &MRangeAndDepth::get_mode_and_stabilisation,
             DOC_MRangeAndDepth(get_mode_and_stabilisation))
        .def("get_runtime_filter_1",
             &MRangeAndDepth::get_runtime_filter_1,
             DOC_MRangeAndDepth(get_runtime_filter_1))
        .def("get_runtime_filter_2",
             &MRangeAndDepth::get_runtime_filter_2,
             DOC_MRangeAndDepth(get_runtime_filter_2))
        .def("get_pipe_tracking_status",
             &MRangeAndDepth::get_pipe_tracking_status,
             DOC_MRangeAndDepth(get_pipe_tracking_status))
        .def("get_tx_array_size_used_deg",
             &MRangeAndDepth::get_tx_array_size_used_deg,
             DOC_MRangeAndDepth(get_tx_array_size_used_deg))
        .def("get_rx_array_size_used_deg",
             &MRangeAndDepth::get_rx_array_size_used_deg,
             DOC_MRangeAndDepth(get_rx_array_size_used_deg))
        .def("get_tx_power_db",
             &MRangeAndDepth::get_tx_power_db,
             DOC_MRangeAndDepth(get_tx_power_db))
        .def("get_sl_ramp_up_time_remaining",
             &MRangeAndDepth::get_sl_ramp_up_time_remaining,
             DOC_MRangeAndDepth(get_sl_ramp_up_time_remaining))
        .def("get_padding_2", &MRangeAndDepth::get_padding_2, DOC_MRangeAndDepth(get_padding_2))
        .def("get_yaw_angle_deg",
             &MRangeAndDepth::get_yaw_angle_deg,
             DOC_MRangeAndDepth(get_yaw_angle_deg))
        .def("get_number_of_tx_sectors",
             &MRangeAndDepth::get_number_of_tx_sectors,
             DOC_MRangeAndDepth(get_number_of_tx_sectors))
        .def("get_number_of_bytes_per_tx_Sector",
             &MRangeAndDepth::get_number_of_bytes_per_tx_Sector,
             DOC_MRangeAndDepth(get_number_of_bytes_per_tx_Sector))
        .def("get_heading_vessel_deg",
             &MRangeAndDepth::get_heading_vessel_deg,
             DOC_MRangeAndDepth(get_heading_vessel_deg))
        .def("get_sound_speed_at_tx_depth_m_per_sec",
             &MRangeAndDepth::get_sound_speed_at_tx_depth_m_per_sec,
             DOC_MRangeAndDepth(get_sound_speed_at_tx_depth_m_per_sec))
        .def("get_tx_transducer_depth_m",
             &MRangeAndDepth::get_tx_transducer_depth_m,
             DOC_MRangeAndDepth(get_tx_transducer_depth_m))
        .def("get_z_water_level_re_ref_point_m",
             &MRangeAndDepth::get_z_water_level_re_ref_point_m,
             DOC_MRangeAndDepth(get_z_water_level_re_ref_point_m))
        .def("get_x_kmall_to_all_m",
             &MRangeAndDepth::get_x_kmall_to_all_m,
             DOC_MRangeAndDepth(get_x_kmall_to_all_m))
        .def("get_y_kmall_to_all_m",
             &MRangeAndDepth::get_y_kmall_to_all_m,
             DOC_MRangeAndDepth(get_y_kmall_to_all_m))
        .def("get_lat_long_info",
             &MRangeAndDepth::get_lat_long_info,
             DOC_MRangeAndDepth(get_lat_long_info))
        .def("get_position_sensor_status",
             &MRangeAndDepth::get_position_sensor_status,
             DOC_MRangeAndDepth(get_position_sensor_status))
        .def("get_attitude_sensor_status",
             &MRangeAndDepth::get_attitude_sensor_status,
             DOC_MRangeAndDepth(get_attitude_sensor_status))
        .def("get_padding_3", &MRangeAndDepth::get_padding_3, DOC_MRangeAndDepth(get_padding_3))
        .def("get_latitude_deg",
             &MRangeAndDepth::get_latitude_deg,
             DOC_MRangeAndDepth(get_latitude_deg))
        .def("get_longitude_deg",
             &MRangeAndDepth::get_longitude_deg,
             DOC_MRangeAndDepth(get_longitude_deg))
        .def("get_ellipsoid_height_re_ref_point_m",
             &MRangeAndDepth::get_ellipsoid_height_re_ref_point_m,
             DOC_MRangeAndDepth(get_ellipsoid_height_re_ref_point_m))
        .def("get_bs_correction_offset_db",
             &MRangeAndDepth::get_bs_correction_offset_db,
             DOC_MRangeAndDepth(get_bs_correction_offset_db))
        .def("get_lamberts_law_applied",
             &MRangeAndDepth::get_lamberts_law_applied,
             DOC_MRangeAndDepth(get_lamberts_law_applied))
        .def("get_ice_window", &MRangeAndDepth::get_ice_window, DOC_MRangeAndDepth(get_ice_window))
        .def("get_active_modes",
             &MRangeAndDepth::get_active_modes,
             DOC_MRangeAndDepth(get_active_modes))
        .def("get_bytes_datagram_check",
             &MRangeAndDepth::get_bytes_datagram_check,
             DOC_MRangeAndDepth(get_bytes_datagram_check))

        .def("set_bytes_content",
             &MRangeAndDepth::set_bytes_content,
             DOC_MRangeAndDepth(set_bytes_content),
             nb::arg("val"))
        .def("set_padding_0",
             &MRangeAndDepth::set_padding_0,
             DOC_MRangeAndDepth(set_padding_0),
             nb::arg("val"))
        .def("set_ping_rate_hz",
             &MRangeAndDepth::set_ping_rate_hz,
             DOC_MRangeAndDepth(set_ping_rate_hz),
             nb::arg("val"))
        .def("set_beam_spacing",
             &MRangeAndDepth::set_beam_spacing,
             DOC_MRangeAndDepth(set_beam_spacing),
             nb::arg("val"))
        .def("set_depth_mode",
             &MRangeAndDepth::set_depth_mode,
             DOC_MRangeAndDepth(set_depth_mode),
             nb::arg("val"))
        .def("set_sub_depth_mode",
             &MRangeAndDepth::set_sub_depth_mode,
             DOC_MRangeAndDepth(set_sub_depth_mode),
             nb::arg("val"))
        .def("set_distance_btw_swath",
             &MRangeAndDepth::set_distance_btw_swath,
             DOC_MRangeAndDepth(set_distance_btw_swath),
             nb::arg("val"))
        .def("set_detection_mode",
             &MRangeAndDepth::set_detection_mode,
             DOC_MRangeAndDepth(set_detection_mode),
             nb::arg("val"))
        .def("set_pulse_form",
             &MRangeAndDepth::set_pulse_form,
             DOC_MRangeAndDepth(set_pulse_form),
             nb::arg("val"))
        .def("set_fixed_gain_control",
             &MRangeAndDepth::set_fixed_gain_control,
             DOC_MRangeAndDepth(set_fixed_gain_control),
             nb::arg("val"))
        .def("set_padding_1",
             &MRangeAndDepth::set_padding_1,
             DOC_MRangeAndDepth(set_padding_1),
             nb::arg("val"))
        .def("set_frequency_mode_hz",
             &MRangeAndDepth::set_frequency_mode_hz,
             DOC_MRangeAndDepth(set_frequency_mode_hz),
             nb::arg("val"))
        .def("set_frequency_range_low_Limit_hz",
             &MRangeAndDepth::set_frequency_range_low_Limit_hz,
             DOC_MRangeAndDepth(set_frequency_range_low_Limit_hz),
             nb::arg("val"))
        .def("set_frequency_range_high_Limit_hz",
             &MRangeAndDepth::set_frequency_range_high_Limit_hz,
             DOC_MRangeAndDepth(set_frequency_range_high_Limit_hz),
             nb::arg("val"))
        .def("set_max_total_tx_pulse_length_sec",
             &MRangeAndDepth::set_max_total_tx_pulse_length_sec,
             DOC_MRangeAndDepth(set_max_total_tx_pulse_length_sec),
             nb::arg("val"))
        .def("set_max_eff_tx_pulse_length_sec",
             &MRangeAndDepth::set_max_eff_tx_pulse_length_sec,
             DOC_MRangeAndDepth(set_max_eff_tx_pulse_length_sec),
             nb::arg("val"))
        .def("set_max_eff_tx_band_width_hz",
             &MRangeAndDepth::set_max_eff_tx_band_width_hz,
             DOC_MRangeAndDepth(set_max_eff_tx_band_width_hz),
             nb::arg("val"))
        .def("set_abs_coeff_db_per_km",
             &MRangeAndDepth::set_abs_coeff_db_per_km,
             DOC_MRangeAndDepth(set_abs_coeff_db_per_km),
             nb::arg("val"))
        .def("set_port_sector_edge_deg",
             &MRangeAndDepth::set_port_sector_edge_deg,
             DOC_MRangeAndDepth(set_port_sector_edge_deg),
             nb::arg("val"))
        .def("set_starboard_sector_edge_deg",
             &MRangeAndDepth::set_starboard_sector_edge_deg,
             DOC_MRangeAndDepth(set_starboard_sector_edge_deg),
             nb::arg("val"))
        .def("set_port_mean_coverage_deg",
             &MRangeAndDepth::set_port_mean_coverage_deg,
             DOC_MRangeAndDepth(set_port_mean_coverage_deg),
             nb::arg("val"))
        .def("set_starboard_mean_coverage_deg",
             &MRangeAndDepth::set_starboard_mean_coverage_deg,
             DOC_MRangeAndDepth(set_starboard_mean_coverage_deg),
             nb::arg("val"))
        .def("set_port_mean_coverage_m",
             &MRangeAndDepth::set_port_mean_coverage_m,
             DOC_MRangeAndDepth(set_port_mean_coverage_m),
             nb::arg("val"))
        .def("set_starboard_mean_coverage_m",
             &MRangeAndDepth::set_starboard_mean_coverage_m,
             DOC_MRangeAndDepth(set_starboard_mean_coverage_m),
             nb::arg("val"))
        .def("set_mode_and_stabilisation",
             &MRangeAndDepth::set_mode_and_stabilisation,
             DOC_MRangeAndDepth(set_mode_and_stabilisation),
             nb::arg("val"))
        .def("set_runtime_filter_1",
             &MRangeAndDepth::set_runtime_filter_1,
             DOC_MRangeAndDepth(set_runtime_filter_1),
             nb::arg("val"))
        .def("set_runtime_filter_2",
             &MRangeAndDepth::set_runtime_filter_2,
             DOC_MRangeAndDepth(set_runtime_filter_2),
             nb::arg("val"))
        .def("set_pipe_tracking_status",
             &MRangeAndDepth::set_pipe_tracking_status,
             DOC_MRangeAndDepth(set_pipe_tracking_status),
             nb::arg("val"))
        .def("set_tx_array_size_used_deg",
             &MRangeAndDepth::set_tx_array_size_used_deg,
             DOC_MRangeAndDepth(set_tx_array_size_used_deg),
             nb::arg("val"))
        .def("set_rx_array_size_used_deg",
             &MRangeAndDepth::set_rx_array_size_used_deg,
             DOC_MRangeAndDepth(set_rx_array_size_used_deg),
             nb::arg("val"))
        .def("set_tx_power_db",
             &MRangeAndDepth::set_tx_power_db,
             DOC_MRangeAndDepth(set_tx_power_db),
             nb::arg("val"))
        .def("set_sl_ramp_up_time_remaining",
             &MRangeAndDepth::set_sl_ramp_up_time_remaining,
             DOC_MRangeAndDepth(set_sl_ramp_up_time_remaining),
             nb::arg("val"))
        .def("set_padding_2",
             &MRangeAndDepth::set_padding_2,
             DOC_MRangeAndDepth(set_padding_2),
             nb::arg("val"))
        .def("set_yaw_angle_deg",
             &MRangeAndDepth::set_yaw_angle_deg,
             DOC_MRangeAndDepth(set_yaw_angle_deg),
             nb::arg("val"))
        .def("set_number_of_tx_sectors",
             &MRangeAndDepth::set_number_of_tx_sectors,
             DOC_MRangeAndDepth(set_number_of_tx_sectors),
             nb::arg("val"))
        .def("set_number_of_bytes_per_tx_Sector",
             &MRangeAndDepth::set_number_of_bytes_per_tx_Sector,
             DOC_MRangeAndDepth(set_number_of_bytes_per_tx_Sector),
             nb::arg("val"))
        .def("set_heading_vessel_deg",
             &MRangeAndDepth::set_heading_vessel_deg,
             DOC_MRangeAndDepth(set_heading_vessel_deg),
             nb::arg("val"))
        .def("set_sound_speed_at_tx_depth_m_per_sec",
             &MRangeAndDepth::set_sound_speed_at_tx_depth_m_per_sec,
             DOC_MRangeAndDepth(set_sound_speed_at_tx_depth_m_per_sec),
             nb::arg("val"))
        .def("set_tx_transducer_depth_m",
             &MRangeAndDepth::set_tx_transducer_depth_m,
             DOC_MRangeAndDepth(set_tx_transducer_depth_m),
             nb::arg("val"))
        .def("set_z_water_level_re_ref_point_m",
             &MRangeAndDepth::set_z_water_level_re_ref_point_m,
             DOC_MRangeAndDepth(set_z_water_level_re_ref_point_m),
             nb::arg("val"))
        .def("set_x_kmall_to_all_m",
             &MRangeAndDepth::set_x_kmall_to_all_m,
             DOC_MRangeAndDepth(set_x_kmall_to_all_m),
             nb::arg("val"))
        .def("set_y_kmall_to_all_m",
             &MRangeAndDepth::set_y_kmall_to_all_m,
             DOC_MRangeAndDepth(set_y_kmall_to_all_m),
             nb::arg("val"))
        .def("set_lat_long_info",
             &MRangeAndDepth::set_lat_long_info,
             DOC_MRangeAndDepth(set_lat_long_info),
             nb::arg("val"))
        .def("set_position_sensor_status",
             &MRangeAndDepth::set_position_sensor_status,
             DOC_MRangeAndDepth(set_position_sensor_status),
             nb::arg("val"))
        .def("set_attitude_sensor_status",
             &MRangeAndDepth::set_attitude_sensor_status,
             DOC_MRangeAndDepth(set_attitude_sensor_status),
             nb::arg("val"))
        .def("set_padding_3",
             &MRangeAndDepth::set_padding_3,
             DOC_MRangeAndDepth(set_padding_3),
             nb::arg("val"))
        .def("set_latitude_deg",
             &MRangeAndDepth::set_latitude_deg,
             DOC_MRangeAndDepth(set_latitude_deg),
             nb::arg("val"))
        .def("set_longitude_deg",
             &MRangeAndDepth::set_longitude_deg,
             DOC_MRangeAndDepth(set_longitude_deg),
             nb::arg("val"))
        .def("set_ellipsoid_height_re_ref_point_m",
             &MRangeAndDepth::set_ellipsoid_height_re_ref_point_m,
             DOC_MRangeAndDepth(set_ellipsoid_height_re_ref_point_m),
             nb::arg("val"))
        .def("set_bs_correction_offset_db",
             &MRangeAndDepth::set_bs_correction_offset_db,
             DOC_MRangeAndDepth(set_bs_correction_offset_db),
             nb::arg("val"))
        .def("set_lamberts_law_applied",
             &MRangeAndDepth::set_lamberts_law_applied,
             DOC_MRangeAndDepth(set_lamberts_law_applied),
             nb::arg("val"))
        .def("set_ice_window",
             &MRangeAndDepth::set_ice_window,
             DOC_MRangeAndDepth(set_ice_window),
             nb::arg("val"))
        .def("set_active_modes",
             &MRangeAndDepth::set_active_modes,
             DOC_MRangeAndDepth(set_active_modes),
             nb::arg("val"))
        .def("set_bytes_datagram_check",
             &MRangeAndDepth::set_bytes_datagram_check,
             DOC_MRangeAndDepth(set_bytes_datagram_check),
             nb::arg("val"))

        // ----- processed -----

        // ----- operators -----
        .def("__eq__",
             &MRangeAndDepth::operator==,
             DOC_MRangeAndDepth(operator_eq),
             nb::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(MRangeAndDepth)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(MRangeAndDepth)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(MRangeAndDepth)
        // end LinearInterpolator
        ;
}
}
}
}
}
}