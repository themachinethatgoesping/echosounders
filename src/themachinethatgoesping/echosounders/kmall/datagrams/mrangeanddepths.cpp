// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "mrangeanddepth.hpp"

#include <fmt/format.h>

#include <limits>
#include <stdexcept>
#include <utility>

#include <themachinethatgoesping/tools/timeconv.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {

tools::classhelper::ObjectPrinter MRangeAndDepth::MRZSectorInfo::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "MRZSectorInfo", float_precision, superscript_exponents);

    printer.register_section(fmt::format("Content (struct) sector -{}-", tx_sector_number));
    printer.register_value("tx_sector_number", tx_sector_number);
    printer.register_value("tx_arrary_number", tx_arrary_number);
    printer.register_value("tx_sub_array", tx_sub_array);
    printer.register_value("padding_0", padding_0);
    printer.register_value("sector_transmit_delay_sec", sector_transmit_delay_sec, "s");
    printer.register_value("tilt_angle_re_tx_deg", tilt_angle_re_tx_deg, "deg");
    printer.register_value("tx_nominal_source_level_db", tx_nominal_source_level_db, "dB");
    printer.register_value("tx_focus_range_m", tx_focus_range_m, "m");
    printer.register_value("centre_frequency_hz", centre_frequency_hz, "Hz");
    printer.register_value("signal_band_width_hz", signal_band_width_hz, "Hz");
    printer.register_value("total_signal_length_sec", total_signal_length_sec, "s");
    printer.register_value("pulse_shading", pulse_shading);
    printer.register_value("signal_wave_form", signal_wave_form);
    printer.register_value("padding_1", padding_1);

    return printer;
}

MRangeAndDepth::MRZSectorInfo MRangeAndDepth::MRZSectorInfo::__read_version_0__(std::istream& is)
{
    static constexpr size_t size_v0 =
        4 * sizeof(uint8_t) + 7 * sizeof(float) + 2 * sizeof(uint8_t) + sizeof(uint16_t);
    MRZSectorInfo info;
    is.read(reinterpret_cast<char*>(&info.tx_sector_number), size_v0);
    info.high_voltage_level_db       = std::numeric_limits<float>::quiet_NaN();
    info.sector_tracking_corr_db     = std::numeric_limits<float>::quiet_NaN();
    info.effective_signal_length_sec = std::numeric_limits<float>::quiet_NaN();
    return info;
}

void MRangeAndDepth::MRZSectorInfo::__write_version_0__(std::ostream& os) const
{
    static constexpr size_t size_v0 =
        4 * sizeof(uint8_t) + 7 * sizeof(float) + 2 * sizeof(uint8_t) + sizeof(uint16_t);
    os.write(reinterpret_cast<const char*>(&tx_sector_number), size_v0);
}

MRangeAndDepth::MRangeAndDepth(const KMALLDatagram& header)
    : KMALLMultibeamDatagram(header)
{
}

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
void MRangeAndDepth::__write_pinginfo__(std::ostream& os) const
{
    // read first part of the datagram (until the first beam)
    os.write(reinterpret_cast<const char*>(&_ping_info), sizeof(MRZPingInfo));
}

void MRangeAndDepth::__read_sectors__(std::istream& is)
{
    const auto n_sectors = get_number_of_tx_sectors();
    const auto version   = get_datagram_version();
    _tx_sectors.resize(n_sectors);

    // if old version read one by one
    if (version < 1)
    {
        for (auto& sector : _tx_sectors)
            sector = sector.__read_version_0__(is);
    }
    else
    {
        // if latest version read as block
        is.read(reinterpret_cast<char*>(_tx_sectors.data()), sizeof(MRZSectorInfo) * n_sectors);
    }
}

void MRangeAndDepth::__write_sectors__(std::ostream& os) const
{
    // const auto n_sectors = get_number_of_tx_sectors();
    const auto version = get_datagram_version();

    // if old version read one by one
    if (version < 1)
    {
        for (const auto& sector : _tx_sectors)
            sector.__write_version_0__(os);
    }
    else
    {
        // if latest version read as block
        os.write(reinterpret_cast<const char*>(_tx_sectors.data()),
                 sizeof(MRZSectorInfo) * _tx_sectors.size());
    }
}

MRangeAndDepth MRangeAndDepth::from_stream(std::istream& is, const KMALLDatagram& header)
{
    MRangeAndDepth datagram(header);
    datagram.__read_multibeamdatagram__(is);
    datagram.__read_pinginfo__(is);
    datagram.__read_sectors__(is);

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
    datagram.__read_sectors__(is);
    return datagram;
}

MRangeAndDepth MRangeAndDepth::from_stream(std::istream& is)
{
    MRangeAndDepth datagram;
    datagram.__kmalldatagram_read__(is);
    datagram.__read_multibeamdatagram__(is);
    datagram.__read_pinginfo__(is);
    datagram.__read_sectors__(is);
    return datagram;
}

void MRangeAndDepth::to_stream(std::ostream& os)
{
    KMALLDatagram::to_stream(os);
    KMALLMultibeamDatagram::to_stream(os);

    __write_pinginfo__(os);
    __write_sectors__(os);
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
    printer.register_value("padding_0", _ping_info.padding_0);

    printer.register_value("ping_rate_hz", _ping_info.ping_rate_hz, "Hz");
    printer.register_value("beam_spacing", _ping_info.beam_spacing);
    printer.register_value("depth_mode", _ping_info.depth_mode);
    printer.register_value("sub_depth_mode", _ping_info.sub_depth_mode);
    printer.register_value("distance_btw_swath", _ping_info.distance_btw_swath);
    printer.register_value("detection_mode", _ping_info.detection_mode);
    printer.register_value("pulse_form", _ping_info.pulse_form);
    printer.register_value("fixed_gain_control", _ping_info.fixed_gain_control);
    printer.register_value("padding_1", _ping_info.padding_1);

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
    printer.register_value("padding_2", _ping_info.padding_2);

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
    printer.register_value("padding_3", _ping_info.padding_3);

    printer.register_value("latitude_deg", _ping_info.latitude_deg, "deg");
    printer.register_value("longitude_deg", _ping_info.longitude_deg, "deg");
    printer.register_value(
        "ellipsoid_height_re_ref_point_m", _ping_info.ellipsoid_height_re_ref_point_m, "m");
    printer.register_value("bs_correction_offset_db", _ping_info.bs_correction_offset_db, "dB");
    printer.register_value("lamberts_law_applied", _ping_info.lamberts_law_applied);
    printer.register_value("ice_window", _ping_info.ice_window);
    printer.register_value("active_modes", _ping_info.active_modes);

    printer.register_section(fmt::format("Sector infos ({} sectors)", _tx_sectors.size()));
    for (const auto& sector : _tx_sectors)
    {
        printer.append(sector.__printer__(float_precision, superscript_exponents));
    }

    printer.register_value("bytes_datagram_check", _bytes_datagram_check, "bytes");

    // printer.register_section("processed");

    return printer;
}

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
