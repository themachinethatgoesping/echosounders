// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "mrangeanddepth.hpp"

#include <fmt/format.h>

#include <stdexcept>
#include <utility>

#include <themachinethatgoesping/tools/timeconv.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {

MRangeAndDepth::MRangeAndDepth()
{
    _datagram_identifier = DatagramIdentifier;
}

// ----- setters -----

// ----- processed data access -----

// ----- to/from stream functions -----
void MRangeAndDepth::__read_pinginfo__(std::istream& is)
{
    // read first part of the datagram (until the first beam)
    is.read(reinterpret_cast<char*>(&_ping_info), sizeof(MRZPingInfo));
}
void MRangeAndDepth::__write_pinginfo__(std::ostream& os)
{
    // read first part of the datagram (until the first beam)
    os.write(reinterpret_cast<const char*>(&_ping_info), sizeof(MRZPingInfo));
}

MRangeAndDepth MRangeAndDepth::from_stream(std::istream& is, const KMALLDatagram& header)
{
    MRangeAndDepth datagram(header);
    datagram.__read_multibeamdatagram__(is);
    datagram.__read_pinginfo__(is);

    return datagram;
}

MRangeAndDepth MRangeAndDepth::from_stream(std::istream&             is,
                                           o_KMALLDatagramIdentifier datagram_identifier)
{
    MRangeAndDepth datagram;
    datagram.__kmalldatagram_read__(is);
    datagram.__check_datagram_identifier__(datagram_identifier, DatagramIdentifier);
    datagram.__read_multibeamdatagram__(is);
    datagram.__read_pinginfo__(is);
    return datagram;
}

MRangeAndDepth MRangeAndDepth::from_stream(std::istream& is)
{
    MRangeAndDepth datagram;
    datagram.__kmalldatagram_read__(is);
    datagram.__read_multibeamdatagram__(is);
    datagram.__read_pinginfo__(is);
    return datagram;
}

void MRangeAndDepth::to_stream(std::ostream& os)
{
    KMALLDatagram::to_stream(os);
    KMALLMultibeamDatagram::to_stream(os);

    __write_pinginfo__(os);
    os.write(reinterpret_cast<const char*>(&_bytes_datagram_check), sizeof(_bytes_datagram_check));
}

// ----- objectprinter -----

tools::classhelper::ObjectPrinter MRangeAndDepth::__printer__(unsigned int float_precision,
                                                              bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "MRangeAndDepth", float_precision, superscript_exponents);

    // false is mpart skipped
    printer.append(
        KMALLMultibeamDatagram::__printer__(float_precision, superscript_exponents, false));

    printer.register_section("Ping info");
    printer.register_value("bytes_content", _ping_info.bytes_content, "bytes");
    printer.register_value("ping_rate_hz", _ping_info.ping_rate_hz, "Hz");
    printer.register_value("beam_spacing", _ping_info.beam_spacing);
    printer.register_value("depth_mode", _ping_info.depth_mode);
    printer.register_value("sub_depth_mode", _ping_info.sub_depth_mode);
    printer.register_value("distance_btw_swath", _ping_info.distance_btw_swath);
    printer.register_value("detection_mode", _ping_info.detection_mode);
    printer.register_value("pulse_form", _ping_info.pulse_form);
    printer.register_value("fixed_gain_control", _ping_info.fixed_gain_control);
    printer.register_value("frequency_mode_hz", _ping_info.frequency_mode_hz, "Hz");
    printer.register_value(
        "frequency_range_low_Limit_hz", _ping_info.frequency_range_low_Limit_hz, "Hz");
    printer.register_value(
        "frequency_range_high_Limit_hz", _ping_info.frequency_range_high_Limit_hz, "Hz");
    printer.register_value(
        "max_total_tx_pulse_length_sec", _ping_info.max_total_tx_pulse_length_sec, "s");
    printer.register_value(
        "max_eff_tx_pulse_length_sec", _ping_info.max_eff_tx_pulse_length_sec, "s");
    printer.register_value("max_eff_tx_band_width_hz", _ping_info.max_eff_tx_band_width_hz, "Hz");
    printer.register_value("abs_coeff_db_per_km", _ping_info.abs_coeff_db_per_km, "dB/km");
    printer.register_value("port_sector_edge_deg", _ping_info.port_sector_edge_deg, "deg");
    printer.register_value(
        "starboard_sector_edge_deg", _ping_info.starboard_sector_edge_deg, "deg");
    printer.register_value("port_mean_coverage_deg", _ping_info.port_mean_coverage_deg, "deg");
    printer.register_value(
        "starboard_mean_coverage_deg", _ping_info.starboard_mean_coverage_deg, "deg");
    printer.register_value("port_mean_coverage_m", _ping_info.port_mean_coverage_m, "m");
    printer.register_value("starboard_mean_coverage_m", _ping_info.starboard_mean_coverage_m, "m");
    printer.register_value("mode_and_stabilisation", _ping_info.mode_and_stabilisation);
    printer.register_value("runtime_filter_1", _ping_info.runtime_filter_1);
    printer.register_value("runtime_filter_2", _ping_info.runtime_filter_2);
    printer.register_value("pipe_tracking_status", _ping_info.pipe_tracking_status);
    printer.register_value("tx_array_size_used_deg", _ping_info.tx_array_size_used_deg, "deg");
    printer.register_value("rx_array_size_used_deg", _ping_info.rx_array_size_used_deg, "deg");
    printer.register_value("tx_power_db", _ping_info.tx_power_db, "dB");
    printer.register_value("sl_ramp_up_time_remaining", _ping_info.sl_ramp_up_time_remaining, "ms");
    printer.register_value("yaw_angle_deg", _ping_info.yaw_angle_deg, "deg");
    printer.register_value("number_of_tx_sectors", _ping_info.number_of_tx_sectors);
    printer.register_value(
        "number_of_bytes_per_tx_Sector", _ping_info.number_of_bytes_per_tx_Sector, "bytes");
    printer.register_value("heading_vessel_deg", _ping_info.heading_vessel_deg, "deg");
    printer.register_value(
        "sound_speed_at_tx_depth_m_per_sec", _ping_info.sound_speed_at_tx_depth_m_per_sec, "m/s");
    printer.register_value("tx_transducer_depth_m", _ping_info.tx_transducer_depth_m, "m");
    printer.register_value(
        "z_water_level_re_ref_point_m", _ping_info.z_water_level_re_ref_point_m, "m");
    printer.register_value("x_kmall_to_all_m", _ping_info.x_kmall_to_all_m, "m");
    printer.register_value("y_kmall_to_all_m", _ping_info.y_kmall_to_all_m, "m");
    printer.register_value("lat_long_info", _ping_info.lat_long_info);
    printer.register_value("position_sensor_status", _ping_info.position_sensor_status);
    printer.register_value("attitude_sensor_status", _ping_info.attitude_sensor_status);
    printer.register_value("latitude_deg", _ping_info.latitude_deg, "deg");
    printer.register_value("longitude_deg", _ping_info.longitude_deg, "deg");
    printer.register_value(
        "ellipsoid_height_re_ref_point_m", _ping_info.ellipsoid_height_re_ref_point_m, "m");
    printer.register_value("bs_correction_offset_db", _ping_info.bs_correction_offset_db, "dB");
    printer.register_value("lamberts_law_applied", _ping_info.lamberts_law_applied);
    printer.register_value("ice_window", _ping_info.ice_window);
    printer.register_value("active_modes", _ping_info.active_modes);

    printer.register_value("bytes_datagram_check", _bytes_datagram_check, "bytes");

    // printer.register_section("processed");

    return printer;
}

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
