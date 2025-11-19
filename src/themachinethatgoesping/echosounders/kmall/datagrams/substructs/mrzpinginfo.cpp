// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "mrzpinginfo.hpp"

#include <fmt/format.h>

#include <limits>
#include <stdexcept>
#include <utility>

#include <themachinethatgoesping/tools/timeconv.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {
namespace substructs {

// ----- setters -----

// ----- processed data access -----

// ----- to/from stream functions -----

// ----- objectprinter -----

tools::classhelper::ObjectPrinter MRZPingInfo::__printer__(unsigned int float_precision,
                                                           bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "MRZPingInfo", float_precision, superscript_exponents);

    printer.register_value("bytes_content", _bytes_content, "bytes");
    printer.register_value("padding_0", _padding_0);

    printer.register_value("ping_rate_hz", _ping_rate_hz, "Hz");
    printer.register_value("beam_spacing", _beam_spacing);
    printer.register_value("depth_mode", _depth_mode);
    printer.register_value("sub_depth_mode", _sub_depth_mode);
    printer.register_value("distance_btw_swath", _distance_btw_swath);
    printer.register_value("detection_mode", _detection_mode);
    printer.register_value("pulse_form", _pulse_form);
    printer.register_value("fixed_gain_control", _fixed_gain_control);
    printer.register_value("padding_1", _padding_1);

    printer.register_value("frequency_mode_hz", _frequency_mode_hz, "Hz");
    printer.register_value("frequency_range_low_Limit_hz", _frequency_range_low_Limit_hz, "Hz");
    printer.register_value("frequency_range_high_Limit_hz", _frequency_range_high_Limit_hz, "Hz");
    printer.register_value("max_total_tx_pulse_length_sec", _max_total_tx_pulse_length_sec, "s");
    printer.register_value("max_eff_tx_pulse_length_sec", _max_eff_tx_pulse_length_sec, "s");
    printer.register_value("max_eff_tx_band_width_hz", _max_eff_tx_band_width_hz, "Hz");
    printer.register_value("abs_coeff_db_per_km", _abs_coeff_db_per_km, "dB/km");
    printer.register_value("port_sector_edge_deg", _port_sector_edge_deg, "deg");
    printer.register_value("starboard_sector_edge_deg", _starboard_sector_edge_deg, "deg");
    printer.register_value("port_mean_coverage_deg", _port_mean_coverage_deg, "deg");
    printer.register_value("starboard_mean_coverage_deg", _starboard_mean_coverage_deg, "deg");
    printer.register_value("port_mean_coverage_m", _port_mean_coverage_m, "m");
    printer.register_value("starboard_mean_coverage_m", _starboard_mean_coverage_m, "m");
    printer.register_value("mode_and_stabilisation", _mode_and_stabilisation);
    printer.register_value("runtime_filter_1", _runtime_filter_1);
    printer.register_value("runtime_filter_2", _runtime_filter_2);
    printer.register_value("pipe_tracking_status", _pipe_tracking_status);
    printer.register_value("tx_array_size_used_deg", _tx_array_size_used_deg, "deg");
    printer.register_value("rx_array_size_used_deg", _rx_array_size_used_deg, "deg");
    printer.register_value("tx_power_db", _tx_power_db, "dB");
    printer.register_value("sl_ramp_up_time_remaining", _sl_ramp_up_time_remaining, "ms");
    printer.register_value("padding_2", _padding_2);

    printer.register_value("yaw_angle_deg", _yaw_angle_deg, "deg");
    printer.register_value("number_of_tx_sectors", _number_of_tx_sectors);
    printer.register_value("number_of_bytes_per_tx_Sector", _number_of_bytes_per_tx_Sector, "bytes");
    printer.register_value("heading_vessel_deg", _heading_vessel_deg, "deg");
    printer.register_value(
        "sound_speed_at_tx_depth_m_per_sec", _sound_speed_at_tx_depth_m_per_sec, "m/s");
    printer.register_value("tx_transducer_depth_m", _tx_transducer_depth_m, "m");
    printer.register_value("z_water_level_re_ref_point_m", _z_water_level_re_ref_point_m, "m");
    printer.register_value("x_kmall_to_all_m", _x_kmall_to_all_m, "m");
    printer.register_value("y_kmall_to_all_m", _y_kmall_to_all_m, "m");
    printer.register_value("lat_long_info", _lat_long_info);
    printer.register_value("position_sensor_status", _position_sensor_status);
    printer.register_value("attitude_sensor_status", _attitude_sensor_status);
    printer.register_value("padding_3", _padding_3);

    printer.register_value("latitude_deg", _latitude_deg, "deg");
    printer.register_value("longitude_deg", _longitude_deg, "deg");
    printer.register_value("ellipsoid_height_re_ref_point_m", _ellipsoid_height_re_ref_point_m, "m");
    printer.register_value("bs_correction_offset_db", _bs_correction_offset_db, "dB");
    printer.register_value("lamberts_law_applied", _lamberts_law_applied);
    printer.register_value("ice_window", _ice_window);
    printer.register_value("active_modes", _active_modes);

    // printer.register_section("processed");

    return printer;
}

}
} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
