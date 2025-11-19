// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/mrangeanddepth.doc.hpp"

// std includes
#include <cstdint>
#include <string>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../types.hpp"
#include "kmallmultibeamdatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {

class MRangeAndDepth : public KMALLMultibeamDatagram
{
    // delete unused functions
  private:
    // using KMALLMultibeamDatagram::__read_multibeamdatagram_no_mpart__;
    // using KMALLMultibeamDatagram::__size_no_mpart;
    // using KMALLMultibeamDatagram::to_stream_no_mpart;

  public:
    static constexpr auto DatagramIdentifier = t_KMALLDatagramIdentifier::M_RANGE_AND_DEPTH;

  protected:
#pragma pack(push, 4) // force 4-byte alignment
    struct MRZPingInfo
    {
        uint16_t bytes_content;
        uint16_t padding_0;
        float    ping_rate_hz;
        uint8_t  beam_spacing;
        uint8_t  depth_mode;

        uint8_t sub_depth_mode;
        uint8_t distance_btw_swath;

        uint8_t detection_mode;
        uint8_t pulse_form;
        uint8_t fixed_gain_control;
        uint8_t padding_1;

        float frequency_mode_hz;
        float frequency_range_low_Limit_hz;
        float frequency_range_high_Limit_hz;
        float max_total_tx_pulse_length_sec;
        float max_eff_tx_pulse_length_sec;
        float max_eff_tx_band_width_hz;
        float abs_coeff_db_per_km;

        float   port_sector_edge_deg;
        float   starboard_sector_edge_deg;
        float   port_mean_coverage_deg;
        float   starboard_mean_coverage_deg;
        int16_t port_mean_coverage_m;
        int16_t starboard_mean_coverage_m;

        uint8_t  mode_and_stabilisation;
        uint8_t  runtime_filter_1;
        uint16_t runtime_filter_2;

        uint32_t pipe_tracking_status;
        float    tx_array_size_used_deg;
        float    rx_array_size_used_deg;
        float    tx_power_db;
        uint16_t sl_ramp_up_time_remaining;
        uint16_t padding_2;
        float    yaw_angle_deg;
        uint16_t number_of_tx_sectors;
        uint16_t number_of_bytes_per_tx_Sector;
        float    heading_vessel_deg;
        float    sound_speed_at_tx_depth_m_per_sec;
        float    tx_transducer_depth_m;
        float    z_water_level_re_ref_point_m;
        float    x_kmall_to_all_m;
        float    y_kmall_to_all_m;

        uint8_t  lat_long_info;
        uint8_t  position_sensor_status;
        uint8_t  attitude_sensor_status;
        uint8_t  padding_3;
        double   latitude_deg;
        double   longitude_deg;
        float    ellipsoid_height_re_ref_point_m;
        float    bs_correction_offset_db;
        uint8_t  lamberts_law_applied;
        uint8_t  ice_window;
        uint16_t active_modes;

        bool operator==(const MRZPingInfo& other) const = default;
    } _ping_info;
#pragma pack(pop)

    static constexpr size_t __size = sizeof(MRZPingInfo); // size till _bytes_datagram_check

    uint32_t _bytes_datagram_check; ///< Each datagram ends with the size of the datagram for
                                    ///< integrity check

  public:
    // ----- public constructors -----
    MRangeAndDepth();
    ~MRangeAndDepth() = default;

    // ----- convenient data access -----
    uint16_t get_bytes_content() const { return _ping_info.bytes_content; }
    uint16_t get_padding_0() const { return _ping_info.padding_0; }
    float    get_ping_rate_hz() const { return _ping_info.ping_rate_hz; }
    uint8_t  get_beam_spacing() const { return _ping_info.beam_spacing; }
    uint8_t  get_depth_mode() const { return _ping_info.depth_mode; }
    uint8_t  get_sub_depth_mode() const { return _ping_info.sub_depth_mode; }
    uint8_t  get_distance_btw_swath() const { return _ping_info.distance_btw_swath; }
    uint8_t  get_detection_mode() const { return _ping_info.detection_mode; }
    uint8_t  get_pulse_form() const { return _ping_info.pulse_form; }
    uint8_t  get_fixed_gain_control() const { return _ping_info.fixed_gain_control; }
    uint8_t  get_padding_1() const { return _ping_info.padding_1; }
    float    get_frequency_mode_hz() const { return _ping_info.frequency_mode_hz; }
    float    get_frequency_range_low_Limit_hz() const
    {
        return _ping_info.frequency_range_low_Limit_hz;
    }
    float get_frequency_range_high_Limit_hz() const
    {
        return _ping_info.frequency_range_high_Limit_hz;
    }
    float get_max_total_tx_pulse_length_sec() const
    {
        return _ping_info.max_total_tx_pulse_length_sec;
    }
    float get_max_eff_tx_pulse_length_sec() const { return _ping_info.max_eff_tx_pulse_length_sec; }
    float get_max_eff_tx_band_width_hz() const { return _ping_info.max_eff_tx_band_width_hz; }
    float get_abs_coeff_db_per_km() const { return _ping_info.abs_coeff_db_per_km; }
    float get_port_sector_edge_deg() const { return _ping_info.port_sector_edge_deg; }
    float get_starboard_sector_edge_deg() const { return _ping_info.starboard_sector_edge_deg; }
    float get_port_mean_coverage_deg() const { return _ping_info.port_mean_coverage_deg; }
    float get_starboard_mean_coverage_deg() const { return _ping_info.starboard_mean_coverage_deg; }
    int16_t  get_port_mean_coverage_m() const { return _ping_info.port_mean_coverage_m; }
    int16_t  get_starboard_mean_coverage_m() const { return _ping_info.starboard_mean_coverage_m; }
    uint8_t  get_mode_and_stabilisation() const { return _ping_info.mode_and_stabilisation; }
    uint8_t  get_runtime_filter_1() const { return _ping_info.runtime_filter_1; }
    uint16_t get_runtime_filter_2() const { return _ping_info.runtime_filter_2; }
    uint32_t get_pipe_tracking_status() const { return _ping_info.pipe_tracking_status; }
    float    get_tx_array_size_used_deg() const { return _ping_info.tx_array_size_used_deg; }
    float    get_rx_array_size_used_deg() const { return _ping_info.rx_array_size_used_deg; }
    float    get_tx_power_db() const { return _ping_info.tx_power_db; }
    uint16_t get_sl_ramp_up_time_remaining() const { return _ping_info.sl_ramp_up_time_remaining; }
    uint16_t get_padding_2() const { return _ping_info.padding_2; }
    float    get_yaw_angle_deg() const { return _ping_info.yaw_angle_deg; }
    uint16_t get_number_of_tx_sectors() const { return _ping_info.number_of_tx_sectors; }
    uint16_t get_number_of_bytes_per_tx_Sector() const
    {
        return _ping_info.number_of_bytes_per_tx_Sector;
    }
    float get_heading_vessel_deg() const { return _ping_info.heading_vessel_deg; }
    float get_sound_speed_at_tx_depth_m_per_sec() const
    {
        return _ping_info.sound_speed_at_tx_depth_m_per_sec;
    }
    float get_tx_transducer_depth_m() const { return _ping_info.tx_transducer_depth_m; }
    float get_z_water_level_re_ref_point_m() const
    {
        return _ping_info.z_water_level_re_ref_point_m;
    }
    float   get_x_kmall_to_all_m() const { return _ping_info.x_kmall_to_all_m; }
    float   get_y_kmall_to_all_m() const { return _ping_info.y_kmall_to_all_m; }
    uint8_t get_lat_long_info() const { return _ping_info.lat_long_info; }
    uint8_t get_position_sensor_status() const { return _ping_info.position_sensor_status; }
    uint8_t get_attitude_sensor_status() const { return _ping_info.attitude_sensor_status; }
    uint8_t get_padding_3() const { return _ping_info.padding_3; }
    double  get_latitude_deg() const { return _ping_info.latitude_deg; }
    double  get_longitude_deg() const { return _ping_info.longitude_deg; }
    float   get_ellipsoid_height_re_ref_point_m() const
    {
        return _ping_info.ellipsoid_height_re_ref_point_m;
    }
    float    get_bs_correction_offset_db() const { return _ping_info.bs_correction_offset_db; }
    uint8_t  get_lamberts_law_applied() const { return _ping_info.lamberts_law_applied; }
    uint8_t  get_ice_window() const { return _ping_info.ice_window; }
    uint16_t get_active_modes() const { return _ping_info.active_modes; }

    uint32_t get_bytes_datagram_check() const { return _bytes_datagram_check; }

    void set_bytes_content(uint16_t val) { _ping_info.bytes_content = val; }
    void set_padding_0(uint16_t val) { _ping_info.padding_0 = val; }
    void set_ping_rate_hz(float val) { _ping_info.ping_rate_hz = val; }
    void set_beam_spacing(uint8_t val) { _ping_info.beam_spacing = val; }
    void set_depth_mode(uint8_t val) { _ping_info.depth_mode = val; }
    void set_sub_depth_mode(uint8_t val) { _ping_info.sub_depth_mode = val; }
    void set_distance_btw_swath(uint8_t val) { _ping_info.distance_btw_swath = val; }
    void set_detection_mode(uint8_t val) { _ping_info.detection_mode = val; }
    void set_pulse_form(uint8_t val) { _ping_info.pulse_form = val; }
    void set_fixed_gain_control(uint8_t val) { _ping_info.fixed_gain_control = val; }
    void set_padding_1(uint8_t val) { _ping_info.padding_1 = val; }
    void set_frequency_mode_hz(float val) { _ping_info.frequency_mode_hz = val; }
    void set_frequency_range_low_Limit_hz(float val)
    {
        _ping_info.frequency_range_low_Limit_hz = val;
    }
    void set_frequency_range_high_Limit_hz(float val)
    {
        _ping_info.frequency_range_high_Limit_hz = val;
    }
    void set_max_total_tx_pulse_length_sec(float val)
    {
        _ping_info.max_total_tx_pulse_length_sec = val;
    }
    void set_max_eff_tx_pulse_length_sec(float val)
    {
        _ping_info.max_eff_tx_pulse_length_sec = val;
    }
    void set_max_eff_tx_band_width_hz(float val) { _ping_info.max_eff_tx_band_width_hz = val; }
    void set_abs_coeff_db_per_km(float val) { _ping_info.abs_coeff_db_per_km = val; }
    void set_port_sector_edge_deg(float val) { _ping_info.port_sector_edge_deg = val; }
    void set_starboard_sector_edge_deg(float val) { _ping_info.starboard_sector_edge_deg = val; }
    void set_port_mean_coverage_deg(float val) { _ping_info.port_mean_coverage_deg = val; }
    void set_starboard_mean_coverage_deg(float val)
    {
        _ping_info.starboard_mean_coverage_deg = val;
    }
    void set_port_mean_coverage_m(int16_t val) { _ping_info.port_mean_coverage_m = val; }
    void set_starboard_mean_coverage_m(int16_t val) { _ping_info.starboard_mean_coverage_m = val; }
    void set_mode_and_stabilisation(uint8_t val) { _ping_info.mode_and_stabilisation = val; }
    void set_runtime_filter_1(uint8_t val) { _ping_info.runtime_filter_1 = val; }
    void set_runtime_filter_2(uint16_t val) { _ping_info.runtime_filter_2 = val; }
    void set_pipe_tracking_status(uint32_t val) { _ping_info.pipe_tracking_status = val; }
    void set_tx_array_size_used_deg(float val) { _ping_info.tx_array_size_used_deg = val; }
    void set_rx_array_size_used_deg(float val) { _ping_info.rx_array_size_used_deg = val; }
    void set_tx_power_db(float val) { _ping_info.tx_power_db = val; }
    void set_sl_ramp_up_time_remaining(uint16_t val) { _ping_info.sl_ramp_up_time_remaining = val; }
    void set_padding_2(uint16_t val) { _ping_info.padding_2 = val; }
    void set_yaw_angle_deg(float val) { _ping_info.yaw_angle_deg = val; }
    void set_number_of_tx_sectors(uint16_t val) { _ping_info.number_of_tx_sectors = val; }
    void set_number_of_bytes_per_tx_Sector(uint16_t val)
    {
        _ping_info.number_of_bytes_per_tx_Sector = val;
    }
    void set_heading_vessel_deg(float val) { _ping_info.heading_vessel_deg = val; }
    void set_sound_speed_at_tx_depth_m_per_sec(float val)
    {
        _ping_info.sound_speed_at_tx_depth_m_per_sec = val;
    }
    void set_tx_transducer_depth_m(float val) { _ping_info.tx_transducer_depth_m = val; }
    void set_z_water_level_re_ref_point_m(float val)
    {
        _ping_info.z_water_level_re_ref_point_m = val;
    }
    void set_x_kmall_to_all_m(float val) { _ping_info.x_kmall_to_all_m = val; }
    void set_y_kmall_to_all_m(float val) { _ping_info.y_kmall_to_all_m = val; }
    void set_lat_long_info(uint8_t val) { _ping_info.lat_long_info = val; }
    void set_position_sensor_status(uint8_t val) { _ping_info.position_sensor_status = val; }
    void set_attitude_sensor_status(uint8_t val) { _ping_info.attitude_sensor_status = val; }
    void set_padding_3(uint8_t val) { _ping_info.padding_3 = val; }
    void set_latitude_deg(double val) { _ping_info.latitude_deg = val; }
    void set_longitude_deg(double val) { _ping_info.longitude_deg = val; }
    void set_ellipsoid_height_re_ref_point_m(float val)
    {
        _ping_info.ellipsoid_height_re_ref_point_m = val;
    }
    void set_bs_correction_offset_db(float val) { _ping_info.bs_correction_offset_db = val; }
    void set_lamberts_law_applied(uint8_t val) { _ping_info.lamberts_law_applied = val; }
    void set_ice_window(uint8_t val) { _ping_info.ice_window = val; }
    void set_active_modes(uint16_t val) { _ping_info.active_modes = val; }
    void set_bytes_datagram_check(uint32_t val) { _bytes_datagram_check = val; }

    // ----- operators -----
    bool operator==(const MRangeAndDepth& other) const = default;

    //----- to/from stream functions -----
    static MRangeAndDepth from_stream(std::istream& is, const KMALLDatagram& header);

    static MRangeAndDepth from_stream(std::istream&             is,
                                      o_KMALLDatagramIdentifier datagram_identifier);

    static MRangeAndDepth from_stream(std::istream& is);

    void to_stream(std::ostream& os);

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(MRangeAndDepth)

  private:
    explicit MRangeAndDepth(const KMALLDatagram& header)
        : KMALLMultibeamDatagram(header)
    {
    }
    void __read_pinginfo__(std::istream& is);
    void __write_pinginfo__(std::ostream& os);
};

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
