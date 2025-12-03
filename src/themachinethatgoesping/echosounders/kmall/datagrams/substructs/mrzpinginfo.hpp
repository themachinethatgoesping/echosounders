// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/mrzpinginfo.doc.hpp"

// std includes
#include <cstdint>
#include <string>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../../types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {
namespace substructs {

#pragma pack(push, 4) // force 4-byte alignment
class MRZPingInfo
{
    uint16_t _bytes_content;
    uint16_t _padding_0;
    float    _ping_rate_hz;
    uint8_t  _beam_spacing;
    uint8_t  _depth_mode;

    uint8_t _sub_depth_mode;
    uint8_t _distance_btw_swath;

    uint8_t _detection_mode;
    uint8_t _pulse_form;
    uint8_t _fixed_gain_control;
    uint8_t _padding_1;

    float _frequency_mode_hz;
    float _frequency_range_low_Limit_hz;
    float _frequency_range_high_Limit_hz;
    float _max_total_tx_pulse_length_sec;
    float _max_eff_tx_pulse_length_sec;
    float _max_eff_tx_band_width_hz;
    float _abs_coeff_db_per_km;

    float   _port_sector_edge_deg;
    float   _starboard_sector_edge_deg;
    float   _port_mean_coverage_deg;
    float   _starboard_mean_coverage_deg;
    int16_t _port_mean_coverage_m;
    int16_t _starboard_mean_coverage_m;

    uint8_t  _mode_and_stabilisation;
    uint8_t  _runtime_filter_1;
    uint16_t _runtime_filter_2;

    uint32_t _pipe_tracking_status;
    float    _tx_array_size_used_deg;
    float    _rx_array_size_used_deg;
    float    _tx_power_db;
    uint16_t _sl_ramp_up_time_remaining;
    uint16_t _padding_2;

    float    _yaw_angle_deg;
    uint16_t _number_of_tx_sectors;
    uint16_t _number_of_bytes_per_tx_Sector;
    float    _heading_vessel_deg;
    float    _sound_speed_at_tx_depth_m_per_sec;
    float    _tx_transducer_depth_m;
    float    _z_water_level_re_ref_point_m;
    float    _x_kmall_to_all_m;
    float    _y_kmall_to_all_m;

    uint8_t _lat_long_info;
    uint8_t _position_sensor_status;
    uint8_t _attitude_sensor_status;
    uint8_t _padding_3;

    double   _latitude_deg;
    double   _longitude_deg;
    float    _ellipsoid_height_re_ref_point_m;
    float    _bs_correction_offset_db;
    uint8_t  _lamberts_law_applied;
    uint8_t  _ice_window;
    uint16_t _active_modes;

  public:
    MRZPingInfo()  = default;
    ~MRZPingInfo() = default;

    // ----- convenient data access -----
    uint16_t get_bytes_content() const { return _bytes_content; }
    uint16_t get_padding_0() const { return _padding_0; }
    float    get_ping_rate_hz() const { return _ping_rate_hz; }
    uint8_t  get_beam_spacing() const { return _beam_spacing; }
    uint8_t  get_depth_mode() const { return _depth_mode; }
    uint8_t  get_sub_depth_mode() const { return _sub_depth_mode; }
    uint8_t  get_distance_btw_swath() const { return _distance_btw_swath; }
    uint8_t  get_detection_mode() const { return _detection_mode; }
    uint8_t  get_pulse_form() const { return _pulse_form; }
    uint8_t  get_fixed_gain_control() const { return _fixed_gain_control; }
    uint8_t  get_padding_1() const { return _padding_1; }
    float    get_frequency_mode_hz() const { return _frequency_mode_hz; }
    float    get_frequency_range_low_Limit_hz() const { return _frequency_range_low_Limit_hz; }
    float    get_frequency_range_high_Limit_hz() const { return _frequency_range_high_Limit_hz; }
    float    get_max_total_tx_pulse_length_sec() const { return _max_total_tx_pulse_length_sec; }
    float    get_max_eff_tx_pulse_length_sec() const { return _max_eff_tx_pulse_length_sec; }
    float    get_max_eff_tx_band_width_hz() const { return _max_eff_tx_band_width_hz; }
    float    get_abs_coeff_db_per_km() const { return _abs_coeff_db_per_km; }
    float    get_port_sector_edge_deg() const { return _port_sector_edge_deg; }
    float    get_starboard_sector_edge_deg() const { return _starboard_sector_edge_deg; }
    float    get_port_mean_coverage_deg() const { return _port_mean_coverage_deg; }
    float    get_starboard_mean_coverage_deg() const { return _starboard_mean_coverage_deg; }
    int16_t  get_port_mean_coverage_m() const { return _port_mean_coverage_m; }
    int16_t  get_starboard_mean_coverage_m() const { return _starboard_mean_coverage_m; }
    uint8_t  get_mode_and_stabilisation() const { return _mode_and_stabilisation; }
    uint8_t  get_runtime_filter_1() const { return _runtime_filter_1; }
    uint16_t get_runtime_filter_2() const { return _runtime_filter_2; }
    uint32_t get_pipe_tracking_status() const { return _pipe_tracking_status; }
    float    get_tx_array_size_used_deg() const { return _tx_array_size_used_deg; }
    float    get_rx_array_size_used_deg() const { return _rx_array_size_used_deg; }
    float    get_tx_power_db() const { return _tx_power_db; }
    uint16_t get_sl_ramp_up_time_remaining() const { return _sl_ramp_up_time_remaining; }
    uint16_t get_padding_2() const { return _padding_2; }
    float    get_yaw_angle_deg() const { return _yaw_angle_deg; }
    uint16_t get_number_of_tx_sectors() const { return _number_of_tx_sectors; }
    uint16_t get_number_of_bytes_per_tx_Sector() const { return _number_of_bytes_per_tx_Sector; }
    float    get_heading_vessel_deg() const { return _heading_vessel_deg; }
    float    get_sound_speed_at_tx_depth_m_per_sec() const
    {
        return _sound_speed_at_tx_depth_m_per_sec;
    }
    float   get_tx_transducer_depth_m() const { return _tx_transducer_depth_m; }
    float   get_z_water_level_re_ref_point_m() const { return _z_water_level_re_ref_point_m; }
    float   get_x_kmall_to_all_m() const { return _x_kmall_to_all_m; }
    float   get_y_kmall_to_all_m() const { return _y_kmall_to_all_m; }
    uint8_t get_lat_long_info() const { return _lat_long_info; }
    uint8_t get_position_sensor_status() const { return _position_sensor_status; }
    uint8_t get_attitude_sensor_status() const { return _attitude_sensor_status; }
    uint8_t get_padding_3() const { return _padding_3; }
    double  get_latitude_deg() const { return _latitude_deg; }
    double  get_longitude_deg() const { return _longitude_deg; }
    float   get_ellipsoid_height_re_ref_point_m() const { return _ellipsoid_height_re_ref_point_m; }
    float   get_bs_correction_offset_db() const { return _bs_correction_offset_db; }
    uint8_t get_lamberts_law_applied() const { return _lamberts_law_applied; }
    uint8_t get_ice_window() const { return _ice_window; }
    uint16_t get_active_modes() const { return _active_modes; }

    void set_bytes_content(uint16_t val) { _bytes_content = val; }
    void set_padding_0(uint16_t val) { _padding_0 = val; }
    void set_ping_rate_hz(float val) { _ping_rate_hz = val; }
    void set_beam_spacing(uint8_t val) { _beam_spacing = val; }
    void set_depth_mode(uint8_t val) { _depth_mode = val; }
    void set_sub_depth_mode(uint8_t val) { _sub_depth_mode = val; }
    void set_distance_btw_swath(uint8_t val) { _distance_btw_swath = val; }
    void set_detection_mode(uint8_t val) { _detection_mode = val; }
    void set_pulse_form(uint8_t val) { _pulse_form = val; }
    void set_fixed_gain_control(uint8_t val) { _fixed_gain_control = val; }
    void set_padding_1(uint8_t val) { _padding_1 = val; }
    void set_frequency_mode_hz(float val) { _frequency_mode_hz = val; }
    void set_frequency_range_low_Limit_hz(float val) { _frequency_range_low_Limit_hz = val; }
    void set_frequency_range_high_Limit_hz(float val) { _frequency_range_high_Limit_hz = val; }
    void set_max_total_tx_pulse_length_sec(float val) { _max_total_tx_pulse_length_sec = val; }
    void set_max_eff_tx_pulse_length_sec(float val) { _max_eff_tx_pulse_length_sec = val; }
    void set_max_eff_tx_band_width_hz(float val) { _max_eff_tx_band_width_hz = val; }
    void set_abs_coeff_db_per_km(float val) { _abs_coeff_db_per_km = val; }
    void set_port_sector_edge_deg(float val) { _port_sector_edge_deg = val; }
    void set_starboard_sector_edge_deg(float val) { _starboard_sector_edge_deg = val; }
    void set_port_mean_coverage_deg(float val) { _port_mean_coverage_deg = val; }
    void set_starboard_mean_coverage_deg(float val) { _starboard_mean_coverage_deg = val; }
    void set_port_mean_coverage_m(int16_t val) { _port_mean_coverage_m = val; }
    void set_starboard_mean_coverage_m(int16_t val) { _starboard_mean_coverage_m = val; }
    void set_mode_and_stabilisation(uint8_t val) { _mode_and_stabilisation = val; }
    void set_runtime_filter_1(uint8_t val) { _runtime_filter_1 = val; }
    void set_runtime_filter_2(uint16_t val) { _runtime_filter_2 = val; }
    void set_pipe_tracking_status(uint32_t val) { _pipe_tracking_status = val; }
    void set_tx_array_size_used_deg(float val) { _tx_array_size_used_deg = val; }
    void set_rx_array_size_used_deg(float val) { _rx_array_size_used_deg = val; }
    void set_tx_power_db(float val) { _tx_power_db = val; }
    void set_sl_ramp_up_time_remaining(uint16_t val) { _sl_ramp_up_time_remaining = val; }
    void set_padding_2(uint16_t val) { _padding_2 = val; }
    void set_yaw_angle_deg(float val) { _yaw_angle_deg = val; }
    void set_number_of_tx_sectors(uint16_t val) { _number_of_tx_sectors = val; }
    void set_number_of_bytes_per_tx_Sector(uint16_t val) { _number_of_bytes_per_tx_Sector = val; }
    void set_heading_vessel_deg(float val) { _heading_vessel_deg = val; }
    void set_sound_speed_at_tx_depth_m_per_sec(float val)
    {
        _sound_speed_at_tx_depth_m_per_sec = val;
    }
    void set_tx_transducer_depth_m(float val) { _tx_transducer_depth_m = val; }
    void set_z_water_level_re_ref_point_m(float val) { _z_water_level_re_ref_point_m = val; }
    void set_x_kmall_to_all_m(float val) { _x_kmall_to_all_m = val; }
    void set_y_kmall_to_all_m(float val) { _y_kmall_to_all_m = val; }
    void set_lat_long_info(uint8_t val) { _lat_long_info = val; }
    void set_position_sensor_status(uint8_t val) { _position_sensor_status = val; }
    void set_attitude_sensor_status(uint8_t val) { _attitude_sensor_status = val; }
    void set_padding_3(uint8_t val) { _padding_3 = val; }
    void set_latitude_deg(double val) { _latitude_deg = val; }
    void set_longitude_deg(double val) { _longitude_deg = val; }
    void set_ellipsoid_height_re_ref_point_m(float val) { _ellipsoid_height_re_ref_point_m = val; }
    void set_bs_correction_offset_db(float val) { _bs_correction_offset_db = val; }
    void set_lamberts_law_applied(uint8_t val) { _lamberts_law_applied = val; }
    void set_ice_window(uint8_t val) { _ice_window = val; }
    void set_active_modes(uint16_t val) { _active_modes = val; }

    // ----- operators -----
    bool operator==(const MRZPingInfo& other) const;

    //----- to/from stream functions -----

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int _float_precision,
                                                  bool         _superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};
#pragma pack(pop)

} // namespace substructs
} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
