// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "runtimeparameters.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

RuntimeParameters RuntimeParameters::from_stream(std::istream& is, KongsbergAllDatagram header)
{
    RuntimeParameters datagram(std::move(header));

    if (datagram._datagram_identifier != t_KongsbergAllDatagramIdentifier::RuntimeParameters)
        throw std::runtime_error(
            fmt::format("RuntimeParameters: datagram identifier is not 0x{:02x}, but 0x{:02x}",
                        uint8_t(t_KongsbergAllDatagramIdentifier::RuntimeParameters),
                        uint8_t(datagram._datagram_identifier)));

    // read first part of the datagram (until the first beam)
    is.read(reinterpret_cast<char*>(&(datagram._ping_counter)), 40 * sizeof(uint8_t));

    if (datagram._etx != 0x03)
        throw std::runtime_error(fmt::format(
            "RuntimeParameters: end identifier is not 0x03, but 0x{:x}", datagram._etx));

    return datagram;
}

RuntimeParameters RuntimeParameters::from_stream(std::istream& is)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is));
}

RuntimeParameters RuntimeParameters::from_stream(std::istream&                    is,
                                                 t_KongsbergAllDatagramIdentifier datagram_identifier)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is, datagram_identifier));
}

void RuntimeParameters::to_stream(std::ostream& os) const
{
    KongsbergAllDatagram::to_stream(os);

    // write first part of the datagram (until the first beam)
    os.write(reinterpret_cast<const char*>(&(_ping_counter)), 40 * sizeof(uint8_t));
}

tools::classhelper::ObjectPrinter RuntimeParameters::__printer__(unsigned int float_precision,
                                                                 bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "RuntimeParameters", float_precision, superscript_exponents);

    printer.append(KongsbergAllDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("datagram content");
    printer.register_value("ping_counter", _ping_counter);
    printer.register_value("system_serial_number", _system_serial_number);
    printer.register_value("operator_station_status", _operator_station_status);
    printer.register_value("processing_unit_status", _processing_unit_status);
    printer.register_value("bsp_status", _bsp_status);
    printer.register_value("sonar_head_or_transceiver_status",
                           _sonar_head_or_transceiver_status);
    printer.register_string("mode", fmt::format("0b{:08b}", _mode) /*, "encoded"*/);
    printer.register_string("filter_identifier",
                            fmt::format("0b{:08b}", _filter_identifier) /*, "encoded"*/);
    printer.register_value("minimum_depth", _minimum_depth, "m");
    printer.register_value("maximum_depth", _maximum_depth, "m");
    printer.register_value("absorption_coefficient", _absorption_coefficient, "0.01 db/km");
    printer.register_value("transmit_pulse_length", _transmit_pulse_length, "μs");
    printer.register_value("transmit_beamwidth", _transmit_beamwidth, "0.1°");
    printer.register_value(
        "transmit_power_relative_maximum", _transmit_power_relative_maximum, "dB");
    printer.register_value("receive_bandwidth_degree", _receive_beamwidth_degree, "0.1°");
    printer.register_value("receive_bandwidth_50hz", _receive_bandwidth_50hz, "50Hz");
    printer.register_string(
        "mode2_or_receiver_fixed_gain_setting",
        fmt::format("0b{:08b}", _mode2_or_receiver_fixed_gain_setting) /*, "encoded"*/);
    printer.register_value("tvg_law_crossover_angle", _tvg_law_crossover_angle, "°");
    printer.register_string(
        "source_of_sound_speed_at_transducer",
        fmt::format("0b{:08b}", _source_of_sound_speed_at_transducer) /*, "encoded"*/);
    printer.register_value("maximum_port_swath_width", _maximum_port_swath_width, "m");
    printer.register_value("beam_spacing",
                           fmt::format("0b{:08b}", _beam_spacing) /*, "encoded"*/);
    printer.register_value("maximum_port_coverage", _maximum_port_coverage, "°");
    printer.register_value(
        "yaw_and_pitch_stabilization_mode",
        fmt::format("0b{:08b}", _yaw_and_pitch_stabilization_mode) /*, "encoded"*/);
    printer.register_value("maximum_starboard_coverage", _maximum_starboard_coverage, "°");
    printer.register_value(
        "maximum_starboard_swath_width", _maximum_starboard_swath_width, "m");
    printer.register_value("transmit_along_tilt", _transmit_along_tilt, "0.1°");
    printer.register_string("filter_identifier2",
                            fmt::format("0b{:08b}", _filter_identifier2) /*, "encoded"*/);
    printer.register_string("etx", fmt::format("0x{:02x}", _etx));
    printer.register_value("checksum", _checksum);

    printer.register_section("processed");
    printer.register_value("absorption_coefficient_in_db_per_meter",
                           get_absorption_coefficient_in_db_per_meter(),
                           "db/m");
    printer.register_value(
        "transmit_pulse_length_in_seconds", get_transmit_pulse_length_in_seconds(), "s");
    printer.register_value(
        "transmit_beamwidth_in_degrees", get_transmit_beamwidth_in_degrees(), "°");
    printer.register_value(
        "receive_bandwidth_in_degrees", get_receive_beamwidth_in_degrees(), "°");
    printer.register_value(
        "receive_bandwidth_in_hertz", get_receive_bandwidth_in_hertz(), "Hz");
    printer.register_value(
        "transmit_along_tilt_in_degrees", get_transmit_along_tilt_in_degrees(), "°");

    printer.register_section(fmt::format("decoded: 'mode' [{:08b}]", _mode));
    printer.register_string(
        "mode_as_ping_mode", get_mode_as_ping_mode().value_or("-None-"), "opt(string)");
    printer.register_string(
        "mode_as_tx_pulse_form", get_mode_as_tx_pulse_form().value_or("-None-"), "opt(string)");
    printer.register_string("mode_as_dual_swath_mode",
                            get_mode_as_dual_swath_mode().value_or("-None-"),
                            "opt(string)");

    printer.register_section(
        fmt::format("decoded: 'mode2' [{:08b}]", _mode2_or_receiver_fixed_gain_setting));
    printer.register_string("mode2_as_rx_or_sonar_head_use",
                            get_mode2_as_rx_or_sonar_head_use().value_or("-None-"),
                            "opt(string)");
    printer.register_string(
        "mode2_as_pulselength", get_mode2_as_pulselength().value_or("-None-"), "opt(string)");
    printer.register_optional_value("mode2_as_receive_fixed_gain_setting_dB",
                                    get_mode2_as_receive_fixed_gain_setting_dB(),
                                    "opt(dB)",
                                    "-None-");

    printer.register_section(
        fmt::format("decoded: 'filter_identifier' [{:08b}]", _filter_identifier));
    printer.register_string(
        "filter_identifier_as_spike_filter", get_filter_identifier_as_spike_filter(), "string");
    printer.register_string(
        "filter_identifier_as_slope_filter", get_filter_identifier_as_slope_filter(), "string");
    printer.register_string("filter_identifier_as_range_gates_size",
                            get_filter_identifier_as_range_gates_size().value_or("-None-"),
                            "opt(string)");
    printer.register_string("filter_identifier_as_aeration_filter",
                            get_filter_identifier_as_aeration_filter(),
                            "string");
    printer.register_string("filter_identifier_as_interference_filter",
                            get_filter_identifier_as_interference_filter(),
                            "string");

    printer.register_section(
        fmt::format("decoded: 'filter_identifier2' [{:08b}]", _filter_identifier2));
    printer.register_string("filter_identifier2_as_penetration_filter",
                            get_filter_identifier2_as_penetration_filter(),
                            "string");
    printer.register_string(
        "filter_identifier2_as_detect_mode", get_filter_identifier2_as_detect_mode(), "string");
    printer.register_string("filter_identifier2_as_phase_ramp",
                            get_filter_identifier2_as_phase_ramp().value_or("-None-"),
                            "opt(string)");
    printer.register_string(
        "filter_identifier2_as_special_tvg", get_filter_identifier2_as_special_tvg(), "string");
    printer.register_string("filter_identifier2_as_special_amp_detect",
                            get_filter_identifier2_as_special_amp_detect(),
                            "string");

    printer.register_section(
        fmt::format("decoded: 'source_of_sound_speed_at_transducer' [{:08b}]",
                    _source_of_sound_speed_at_transducer));
    printer.register_string(
        "source_of_sound_speed_at_transducer_as_string",
        get_source_of_sound_speed_at_transducer_as_string().value_or("-None-"),
        "opt(string)");
    printer.register_value("extra_detections_enabled", get_extra_detections_enabled(), "bool");
    printer.register_value("sonar_mode_enabled", get_sonar_mode_enabled(), "bool");
    printer.register_value("passive_mode_enabled", get_passive_mode_enabled(), "bool");
    printer.register_value("3d_scanning_enabled", get_3d_scanning_enabled(), "bool");

    printer.register_section(fmt::format("decoded: 'beam_spacing' [{:08b}]", _beam_spacing));
    printer.register_string("beam_spacing_as_string",
                            get_beam_spacing_as_string().value_or("-None-"),
                            "opt(string)");

    printer.register_section(fmt::format("decoded: 'yaw_and_pitch_stabilization_mode' [{:08b}]",
                                         _yaw_and_pitch_stabilization_mode));
    printer.register_string("yaw_and_pitch_stabilization_mode_as_yaw_stabilization",
                            get_yaw_and_pitch_stabilization_mode_as_yaw_stabilization(),
                            "string");
    printer.register_string(
        "yaw_and_pitch_stabilization_mode_as_heading_filter",
        get_yaw_and_pitch_stabilization_mode_as_heading_filter().value_or("-None-"),
        "opt(string)");
    printer.register_string("yaw_and_pitch_stabilization_mode_as_pitch_stibilization",
                            get_yaw_and_pitch_stabilization_mode_as_pitch_stibilization(),
                            "string");

    return printer;
}

} // namespace datagrams
} // namespace kongsbergall  
} // namespace echosounders
} // namespace themachinethatgoesping
