// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/bind_vector.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/datetime.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/substructs/mrzpinginfo.hpp>

#include "../module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::substructs::MRZPingInfo;

#define DOC_MRZPingInfo(ARG)                                                                       \
    DOC(themachinethatgoesping, echosounders, kmall, datagrams, substructs, MRZPingInfo, ARG)

void init_c_mrzpinginfo(nanobind::module_& m)
{

    nb::class_<MRZPingInfo>(
        m,
        "MRZPingInfo",
        DOC(themachinethatgoesping, echosounders, kmall, datagrams, substructs, MRZPingInfo))
        .def(nb::init<>(), DOC_MRZPingInfo(MRZPingInfo))

        // --- convenient data access ---
        .def("get_bytes_content",
             &MRZPingInfo::get_bytes_content,
             DOC_MRZPingInfo(get_bytes_content))
        .def("get_padding_0", &MRZPingInfo::get_padding_0, DOC_MRZPingInfo(get_padding_0))
        .def("get_ping_rate_hz", &MRZPingInfo::get_ping_rate_hz, DOC_MRZPingInfo(get_ping_rate_hz))
        .def("get_beam_spacing", &MRZPingInfo::get_beam_spacing, DOC_MRZPingInfo(get_beam_spacing))
        .def("get_depth_mode", &MRZPingInfo::get_depth_mode, DOC_MRZPingInfo(get_depth_mode))
        .def("get_sub_depth_mode",
             &MRZPingInfo::get_sub_depth_mode,
             DOC_MRZPingInfo(get_sub_depth_mode))
        .def("get_distance_btw_swath",
             &MRZPingInfo::get_distance_btw_swath,
             DOC_MRZPingInfo(get_distance_btw_swath))
        .def("get_detection_mode",
             &MRZPingInfo::get_detection_mode,
             DOC_MRZPingInfo(get_detection_mode))
        .def("get_pulse_form", &MRZPingInfo::get_pulse_form, DOC_MRZPingInfo(get_pulse_form))
        .def("get_fixed_gain_control",
             &MRZPingInfo::get_fixed_gain_control,
             DOC_MRZPingInfo(get_fixed_gain_control))
        .def("get_padding_1", &MRZPingInfo::get_padding_1, DOC_MRZPingInfo(get_padding_1))
        .def("get_frequency_mode_hz",
             &MRZPingInfo::get_frequency_mode_hz,
             DOC_MRZPingInfo(get_frequency_mode_hz))
        .def("get_frequency_range_low_Limit_hz",
             &MRZPingInfo::get_frequency_range_low_Limit_hz,
             DOC_MRZPingInfo(get_frequency_range_low_Limit_hz))
        .def("get_frequency_range_high_Limit_hz",
             &MRZPingInfo::get_frequency_range_high_Limit_hz,
             DOC_MRZPingInfo(get_frequency_range_high_Limit_hz))
        .def("get_max_total_tx_pulse_length_sec",
             &MRZPingInfo::get_max_total_tx_pulse_length_sec,
             DOC_MRZPingInfo(get_max_total_tx_pulse_length_sec))
        .def("get_max_eff_tx_pulse_length_sec",
             &MRZPingInfo::get_max_eff_tx_pulse_length_sec,
             DOC_MRZPingInfo(get_max_eff_tx_pulse_length_sec))
        .def("get_max_eff_tx_band_width_hz",
             &MRZPingInfo::get_max_eff_tx_band_width_hz,
             DOC_MRZPingInfo(get_max_eff_tx_band_width_hz))
        .def("get_abs_coeff_db_per_km",
             &MRZPingInfo::get_abs_coeff_db_per_km,
             DOC_MRZPingInfo(get_abs_coeff_db_per_km))
        .def("get_port_sector_edge_deg",
             &MRZPingInfo::get_port_sector_edge_deg,
             DOC_MRZPingInfo(get_port_sector_edge_deg))
        .def("get_starboard_sector_edge_deg",
             &MRZPingInfo::get_starboard_sector_edge_deg,
             DOC_MRZPingInfo(get_starboard_sector_edge_deg))
        .def("get_port_mean_coverage_deg",
             &MRZPingInfo::get_port_mean_coverage_deg,
             DOC_MRZPingInfo(get_port_mean_coverage_deg))
        .def("get_starboard_mean_coverage_deg",
             &MRZPingInfo::get_starboard_mean_coverage_deg,
             DOC_MRZPingInfo(get_starboard_mean_coverage_deg))
        .def("get_port_mean_coverage_m",
             &MRZPingInfo::get_port_mean_coverage_m,
             DOC_MRZPingInfo(get_port_mean_coverage_m))
        .def("get_starboard_mean_coverage_m",
             &MRZPingInfo::get_starboard_mean_coverage_m,
             DOC_MRZPingInfo(get_starboard_mean_coverage_m))
        .def("get_mode_and_stabilisation",
             &MRZPingInfo::get_mode_and_stabilisation,
             DOC_MRZPingInfo(get_mode_and_stabilisation))
        .def("get_runtime_filter_1",
             &MRZPingInfo::get_runtime_filter_1,
             DOC_MRZPingInfo(get_runtime_filter_1))
        .def("get_runtime_filter_2",
             &MRZPingInfo::get_runtime_filter_2,
             DOC_MRZPingInfo(get_runtime_filter_2))
        .def("get_pipe_tracking_status",
             &MRZPingInfo::get_pipe_tracking_status,
             DOC_MRZPingInfo(get_pipe_tracking_status))
        .def("get_tx_array_size_used_deg",
             &MRZPingInfo::get_tx_array_size_used_deg,
             DOC_MRZPingInfo(get_tx_array_size_used_deg))
        .def("get_rx_array_size_used_deg",
             &MRZPingInfo::get_rx_array_size_used_deg,
             DOC_MRZPingInfo(get_rx_array_size_used_deg))
        .def("get_tx_power_db", &MRZPingInfo::get_tx_power_db, DOC_MRZPingInfo(get_tx_power_db))
        .def("get_sl_ramp_up_time_remaining",
             &MRZPingInfo::get_sl_ramp_up_time_remaining,
             DOC_MRZPingInfo(get_sl_ramp_up_time_remaining))
        .def("get_padding_2", &MRZPingInfo::get_padding_2, DOC_MRZPingInfo(get_padding_2))
        .def("get_yaw_angle_deg",
             &MRZPingInfo::get_yaw_angle_deg,
             DOC_MRZPingInfo(get_yaw_angle_deg))
        .def("get_number_of_tx_sectors",
             &MRZPingInfo::get_number_of_tx_sectors,
             DOC_MRZPingInfo(get_number_of_tx_sectors))
        .def("get_number_of_bytes_per_tx_Sector",
             &MRZPingInfo::get_number_of_bytes_per_tx_Sector,
             DOC_MRZPingInfo(get_number_of_bytes_per_tx_Sector))
        .def("get_heading_vessel_deg",
             &MRZPingInfo::get_heading_vessel_deg,
             DOC_MRZPingInfo(get_heading_vessel_deg))
        .def("get_sound_speed_at_tx_depth_m_per_sec",
             &MRZPingInfo::get_sound_speed_at_tx_depth_m_per_sec,
             DOC_MRZPingInfo(get_sound_speed_at_tx_depth_m_per_sec))
        .def("get_tx_transducer_depth_m",
             &MRZPingInfo::get_tx_transducer_depth_m,
             DOC_MRZPingInfo(get_tx_transducer_depth_m))
        .def("get_z_water_level_re_ref_point_m",
             &MRZPingInfo::get_z_water_level_re_ref_point_m,
             DOC_MRZPingInfo(get_z_water_level_re_ref_point_m))
        .def("get_x_kmall_to_all_m",
             &MRZPingInfo::get_x_kmall_to_all_m,
             DOC_MRZPingInfo(get_x_kmall_to_all_m))
        .def("get_y_kmall_to_all_m",
             &MRZPingInfo::get_y_kmall_to_all_m,
             DOC_MRZPingInfo(get_y_kmall_to_all_m))
        .def("get_lat_long_info",
             &MRZPingInfo::get_lat_long_info,
             DOC_MRZPingInfo(get_lat_long_info))
        .def("get_position_sensor_status",
             &MRZPingInfo::get_position_sensor_status,
             DOC_MRZPingInfo(get_position_sensor_status))
        .def("get_attitude_sensor_status",
             &MRZPingInfo::get_attitude_sensor_status,
             DOC_MRZPingInfo(get_attitude_sensor_status))
        .def("get_padding_3", &MRZPingInfo::get_padding_3, DOC_MRZPingInfo(get_padding_3))
        .def("get_latitude_deg", &MRZPingInfo::get_latitude_deg, DOC_MRZPingInfo(get_latitude_deg))
        .def("get_longitude_deg",
             &MRZPingInfo::get_longitude_deg,
             DOC_MRZPingInfo(get_longitude_deg))
        .def("get_ellipsoid_height_re_ref_point_m",
             &MRZPingInfo::get_ellipsoid_height_re_ref_point_m,
             DOC_MRZPingInfo(get_ellipsoid_height_re_ref_point_m))
        .def("get_bs_correction_offset_db",
             &MRZPingInfo::get_bs_correction_offset_db,
             DOC_MRZPingInfo(get_bs_correction_offset_db))
        .def("get_lamberts_law_applied",
             &MRZPingInfo::get_lamberts_law_applied,
             DOC_MRZPingInfo(get_lamberts_law_applied))
        .def("get_ice_window", &MRZPingInfo::get_ice_window, DOC_MRZPingInfo(get_ice_window))
        .def("get_active_modes", &MRZPingInfo::get_active_modes, DOC_MRZPingInfo(get_active_modes))

        .def("set_bytes_content",
             &MRZPingInfo::set_bytes_content,
             DOC_MRZPingInfo(set_bytes_content),
             nb::arg("val"))
        .def("set_padding_0",
             &MRZPingInfo::set_padding_0,
             DOC_MRZPingInfo(set_padding_0),
             nb::arg("val"))
        .def("set_ping_rate_hz",
             &MRZPingInfo::set_ping_rate_hz,
             DOC_MRZPingInfo(set_ping_rate_hz),
             nb::arg("val"))
        .def("set_beam_spacing",
             &MRZPingInfo::set_beam_spacing,
             DOC_MRZPingInfo(set_beam_spacing),
             nb::arg("val"))
        .def("set_depth_mode",
             &MRZPingInfo::set_depth_mode,
             DOC_MRZPingInfo(set_depth_mode),
             nb::arg("val"))
        .def("set_sub_depth_mode",
             &MRZPingInfo::set_sub_depth_mode,
             DOC_MRZPingInfo(set_sub_depth_mode),
             nb::arg("val"))
        .def("set_distance_btw_swath",
             &MRZPingInfo::set_distance_btw_swath,
             DOC_MRZPingInfo(set_distance_btw_swath),
             nb::arg("val"))
        .def("set_detection_mode",
             &MRZPingInfo::set_detection_mode,
             DOC_MRZPingInfo(set_detection_mode),
             nb::arg("val"))
        .def("set_pulse_form",
             &MRZPingInfo::set_pulse_form,
             DOC_MRZPingInfo(set_pulse_form),
             nb::arg("val"))
        .def("set_fixed_gain_control",
             &MRZPingInfo::set_fixed_gain_control,
             DOC_MRZPingInfo(set_fixed_gain_control),
             nb::arg("val"))
        .def("set_padding_1",
             &MRZPingInfo::set_padding_1,
             DOC_MRZPingInfo(set_padding_1),
             nb::arg("val"))
        .def("set_frequency_mode_hz",
             &MRZPingInfo::set_frequency_mode_hz,
             DOC_MRZPingInfo(set_frequency_mode_hz),
             nb::arg("val"))
        .def("set_frequency_range_low_Limit_hz",
             &MRZPingInfo::set_frequency_range_low_Limit_hz,
             DOC_MRZPingInfo(set_frequency_range_low_Limit_hz),
             nb::arg("val"))
        .def("set_frequency_range_high_Limit_hz",
             &MRZPingInfo::set_frequency_range_high_Limit_hz,
             DOC_MRZPingInfo(set_frequency_range_high_Limit_hz),
             nb::arg("val"))
        .def("set_max_total_tx_pulse_length_sec",
             &MRZPingInfo::set_max_total_tx_pulse_length_sec,
             DOC_MRZPingInfo(set_max_total_tx_pulse_length_sec),
             nb::arg("val"))
        .def("set_max_eff_tx_pulse_length_sec",
             &MRZPingInfo::set_max_eff_tx_pulse_length_sec,
             DOC_MRZPingInfo(set_max_eff_tx_pulse_length_sec),
             nb::arg("val"))
        .def("set_max_eff_tx_band_width_hz",
             &MRZPingInfo::set_max_eff_tx_band_width_hz,
             DOC_MRZPingInfo(set_max_eff_tx_band_width_hz),
             nb::arg("val"))
        .def("set_abs_coeff_db_per_km",
             &MRZPingInfo::set_abs_coeff_db_per_km,
             DOC_MRZPingInfo(set_abs_coeff_db_per_km),
             nb::arg("val"))
        .def("set_port_sector_edge_deg",
             &MRZPingInfo::set_port_sector_edge_deg,
             DOC_MRZPingInfo(set_port_sector_edge_deg),
             nb::arg("val"))
        .def("set_starboard_sector_edge_deg",
             &MRZPingInfo::set_starboard_sector_edge_deg,
             DOC_MRZPingInfo(set_starboard_sector_edge_deg),
             nb::arg("val"))
        .def("set_port_mean_coverage_deg",
             &MRZPingInfo::set_port_mean_coverage_deg,
             DOC_MRZPingInfo(set_port_mean_coverage_deg),
             nb::arg("val"))
        .def("set_starboard_mean_coverage_deg",
             &MRZPingInfo::set_starboard_mean_coverage_deg,
             DOC_MRZPingInfo(set_starboard_mean_coverage_deg),
             nb::arg("val"))
        .def("set_port_mean_coverage_m",
             &MRZPingInfo::set_port_mean_coverage_m,
             DOC_MRZPingInfo(set_port_mean_coverage_m),
             nb::arg("val"))
        .def("set_starboard_mean_coverage_m",
             &MRZPingInfo::set_starboard_mean_coverage_m,
             DOC_MRZPingInfo(set_starboard_mean_coverage_m),
             nb::arg("val"))
        .def("set_mode_and_stabilisation",
             &MRZPingInfo::set_mode_and_stabilisation,
             DOC_MRZPingInfo(set_mode_and_stabilisation),
             nb::arg("val"))
        .def("set_runtime_filter_1",
             &MRZPingInfo::set_runtime_filter_1,
             DOC_MRZPingInfo(set_runtime_filter_1),
             nb::arg("val"))
        .def("set_runtime_filter_2",
             &MRZPingInfo::set_runtime_filter_2,
             DOC_MRZPingInfo(set_runtime_filter_2),
             nb::arg("val"))
        .def("set_pipe_tracking_status",
             &MRZPingInfo::set_pipe_tracking_status,
             DOC_MRZPingInfo(set_pipe_tracking_status),
             nb::arg("val"))
        .def("set_tx_array_size_used_deg",
             &MRZPingInfo::set_tx_array_size_used_deg,
             DOC_MRZPingInfo(set_tx_array_size_used_deg),
             nb::arg("val"))
        .def("set_rx_array_size_used_deg",
             &MRZPingInfo::set_rx_array_size_used_deg,
             DOC_MRZPingInfo(set_rx_array_size_used_deg),
             nb::arg("val"))
        .def("set_tx_power_db",
             &MRZPingInfo::set_tx_power_db,
             DOC_MRZPingInfo(set_tx_power_db),
             nb::arg("val"))
        .def("set_sl_ramp_up_time_remaining",
             &MRZPingInfo::set_sl_ramp_up_time_remaining,
             DOC_MRZPingInfo(set_sl_ramp_up_time_remaining),
             nb::arg("val"))
        .def("set_padding_2",
             &MRZPingInfo::set_padding_2,
             DOC_MRZPingInfo(set_padding_2),
             nb::arg("val"))
        .def("set_yaw_angle_deg",
             &MRZPingInfo::set_yaw_angle_deg,
             DOC_MRZPingInfo(set_yaw_angle_deg),
             nb::arg("val"))
        .def("set_number_of_tx_sectors",
             &MRZPingInfo::set_number_of_tx_sectors,
             DOC_MRZPingInfo(set_number_of_tx_sectors),
             nb::arg("val"))
        .def("set_number_of_bytes_per_tx_Sector",
             &MRZPingInfo::set_number_of_bytes_per_tx_Sector,
             DOC_MRZPingInfo(set_number_of_bytes_per_tx_Sector),
             nb::arg("val"))
        .def("set_heading_vessel_deg",
             &MRZPingInfo::set_heading_vessel_deg,
             DOC_MRZPingInfo(set_heading_vessel_deg),
             nb::arg("val"))
        .def("set_sound_speed_at_tx_depth_m_per_sec",
             &MRZPingInfo::set_sound_speed_at_tx_depth_m_per_sec,
             DOC_MRZPingInfo(set_sound_speed_at_tx_depth_m_per_sec),
             nb::arg("val"))
        .def("set_tx_transducer_depth_m",
             &MRZPingInfo::set_tx_transducer_depth_m,
             DOC_MRZPingInfo(set_tx_transducer_depth_m),
             nb::arg("val"))
        .def("set_z_water_level_re_ref_point_m",
             &MRZPingInfo::set_z_water_level_re_ref_point_m,
             DOC_MRZPingInfo(set_z_water_level_re_ref_point_m),
             nb::arg("val"))
        .def("set_x_kmall_to_all_m",
             &MRZPingInfo::set_x_kmall_to_all_m,
             DOC_MRZPingInfo(set_x_kmall_to_all_m),
             nb::arg("val"))
        .def("set_y_kmall_to_all_m",
             &MRZPingInfo::set_y_kmall_to_all_m,
             DOC_MRZPingInfo(set_y_kmall_to_all_m),
             nb::arg("val"))
        .def("set_lat_long_info",
             &MRZPingInfo::set_lat_long_info,
             DOC_MRZPingInfo(set_lat_long_info),
             nb::arg("val"))
        .def("set_position_sensor_status",
             &MRZPingInfo::set_position_sensor_status,
             DOC_MRZPingInfo(set_position_sensor_status),
             nb::arg("val"))
        .def("set_attitude_sensor_status",
             &MRZPingInfo::set_attitude_sensor_status,
             DOC_MRZPingInfo(set_attitude_sensor_status),
             nb::arg("val"))
        .def("set_padding_3",
             &MRZPingInfo::set_padding_3,
             DOC_MRZPingInfo(set_padding_3),
             nb::arg("val"))
        .def("set_latitude_deg",
             &MRZPingInfo::set_latitude_deg,
             DOC_MRZPingInfo(set_latitude_deg),
             nb::arg("val"))
        .def("set_longitude_deg",
             &MRZPingInfo::set_longitude_deg,
             DOC_MRZPingInfo(set_longitude_deg),
             nb::arg("val"))
        .def("set_ellipsoid_height_re_ref_point_m",
             &MRZPingInfo::set_ellipsoid_height_re_ref_point_m,
             DOC_MRZPingInfo(set_ellipsoid_height_re_ref_point_m),
             nb::arg("val"))
        .def("set_bs_correction_offset_db",
             &MRZPingInfo::set_bs_correction_offset_db,
             DOC_MRZPingInfo(set_bs_correction_offset_db),
             nb::arg("val"))
        .def("set_lamberts_law_applied",
             &MRZPingInfo::set_lamberts_law_applied,
             DOC_MRZPingInfo(set_lamberts_law_applied),
             nb::arg("val"))
        .def("set_ice_window",
             &MRZPingInfo::set_ice_window,
             DOC_MRZPingInfo(set_ice_window),
             nb::arg("val"))
        .def("set_active_modes",
             &MRZPingInfo::set_active_modes,
             DOC_MRZPingInfo(set_active_modes),
             nb::arg("val"))

        // ----- processed -----

        // ----- operators -----
        .def("__eq__", &MRZPingInfo::operator==, DOC_MRZPingInfo(operator_eq), nb::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(MRZPingInfo)
        // default binary functions
        //__PYCLASS_DEFAULT_BINARY__(MRZPingInfo)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(MRZPingInfo)
        // end LinearInterpolator
        ;
}
}
}
}
}
}