// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "pustatusoutput.hpp"

#include <fmt/core.h>
#include <stdexcept>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

PUStatusOutput PUStatusOutput::from_stream(std::istream& is, KongsbergAllDatagram header)
{
    PUStatusOutput datagram(std::move(header));

    if (datagram._datagram_identifier != t_KongsbergAllDatagramIdentifier::PUStatusOutput)
        throw std::runtime_error(
            fmt::format("PUStatusOutput: datagram identifier is not 0x{:02x}, but 0x{:02x}",
                        uint8_t(t_KongsbergAllDatagramIdentifier::PUStatusOutput),
                        uint8_t(datagram._datagram_identifier)));

    // read first part of the datagram (until the first beam)
    is.read(reinterpret_cast<char*>(&(datagram._status_datagram_counter)),
            76 * sizeof(uint8_t));

    if (datagram._etx != 0x03)
        throw std::runtime_error(fmt::format(
            "PUStatusOutput: end identifier is not 0x03, but 0x{:x}", datagram._etx));

    return datagram;
}

PUStatusOutput PUStatusOutput::from_stream(std::istream& is)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is));
}

PUStatusOutput PUStatusOutput::from_stream(std::istream&              is,
                                          t_KongsbergAllDatagramIdentifier datagram_identifier)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is, datagram_identifier));
}

void PUStatusOutput::to_stream(std::ostream& os) const
{
    KongsbergAllDatagram::to_stream(os);

    // write first part of the datagram (until the first beam)
    os.write(reinterpret_cast<const char*>(&(_status_datagram_counter)), 76 * sizeof(uint8_t));
}

tools::classhelper::ObjectPrinter PUStatusOutput::__printer__(unsigned int float_precision, bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer("PUStatusOutput", float_precision, superscript_exponents);

    printer.append(KongsbergAllDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("datagram content");
    printer.register_value("status_datagram_counter", _system_serial_number);
    printer.register_value("system_serial_number", _system_serial_number);
    printer.register_value("ping_rate", _ping_rate, "0.01 Hz");
    printer.register_value("ping_counter", _ping_counter);
    printer.register_value("distance_between_swath", _distance_between_swath, "%");
    printer.register_value("sensor_input_status_udp_port_2", _sensor_input_status_udp_port_2);
    printer.register_value("sensor_input_status_serial_port_1",
                           _sensor_input_status_serial_port_1);
    printer.register_value("sensor_input_status_serial_port_2",
                           _sensor_input_status_serial_port_2);
    printer.register_value("sensor_input_status_serial_port_3",
                           _sensor_input_status_serial_port_3);
    printer.register_value("sensor_input_status_serial_port_4",
                           _sensor_input_status_serial_port_4);
    printer.register_value("pps_status", _pps_status);
    printer.register_value("position_status", _position_status);
    printer.register_value("attitude_status", _attitude_status);
    printer.register_value("clock_status", _clock_status);
    printer.register_value("heading_status", _heading_status);
    printer.register_value("pu_status", _pu_status);
    printer.register_value("last_received_heading", _last_received_heading, "0.01°");
    printer.register_value("last_received_roll", _last_received_roll, "0.01°");
    printer.register_value("last_received_pitch", _last_received_pitch, "0.01°");
    printer.register_value(
        "last_received_heave_at_sonar_head", _last_received_heave_at_sonar_head, "cm");
    printer.register_value("sound_speed_at_transducer", _sound_speed_at_transducer, "dm/s");
    printer.register_value("last_received_depth", _last_received_depth, "cm");
    printer.register_value("along_ship_velocity", _along_ship_velocity, "cm/s");
    printer.register_value("attitude_velocity_sensor_status", _attitude_velocity_sensor_status);
    printer.register_value("mammal_protection_ramp", _mammal_protection_ramp);
    printer.register_value(
        "_backscatter_at_oblique_angle", _backscatter_at_oblique_angle, "dB");
    printer.register_value(
        "_backscatter_at_normal_incidence", _backscatter_at_normal_incidence, "dB");
    printer.register_value("fixed_gain", _fixed_gain, "dB");
    printer.register_value("depth_to_normal_incidence", _depth_to_normal_incidence, "m");
    printer.register_value("range_to_normal_incidence", _range_to_normal_incidence, "m");
    printer.register_value("port_coverage", _port_coverage, "°");
    printer.register_value("starboard_coverage", _starboard_coverage, "°");
    printer.register_value("sound_speed_at_transducer_from_profile",
                           _sound_speed_at_transducer_from_profile,
                           "dm/s");
    printer.register_value("yaw_stabilization_angle", _yaw_stabilization_angle, "0.01°");
    printer.register_value("across_ship_velocity", _across_ship_velocity, "cm/s");
    printer.register_value("downward_velocity", _downward_velocity, "cm/s");
    printer.register_value("em2040_cpu_temperature", _em2040_cpu_temperature, "°C");

    printer.register_string("etx", fmt::format("0x{:02x}", _etx));
    printer.register_value("checksum", _checksum);

    printer.register_section("processed");
    printer.register_value("ping_rate", get_ping_rate_hertz(), "Hz");
    printer.register_value(
        "_distance_between_swath", get_distance_between_swath_in_percent(), "%");
    printer.register_value("last_received_roll", get_last_received_roll_in_degrees(), "°");
    printer.register_value("last_received_pitch", get_last_received_pitch_in_degrees(), "°");
    printer.register_value("last_received_heave_at_sonar_head",
                           get_last_received_heave_at_sonar_head_in_meters(),
                           "m");
    printer.register_value("sound_speed_at_transducer",
                           get_sound_speed_at_transducer_in_meters_per_second(),
                           "m/s");
    printer.register_value("last_received_depth", get_last_received_depth_in_meters(), "m");
    printer.register_value(
        "_along_ship_velocity", get_along_ship_velocity_in_meters_per_second(), "m/s");
    printer.register_value("sound_speed_at_transducer_from_profile",
                           get_sound_speed_at_transducer_from_profile_in_meters_per_second(),
                           "m/s");
    printer.register_value(
        "_yaw_stabilization_angle", get_yaw_stabilization_angle_in_degrees(), "°");
    printer.register_value(
        "_across_ship_velocity", get_across_ship_velocity_in_meters_per_second(), "m/s");
    printer.register_value(
        "_downward_velocity", get_downward_velocity_in_meters_per_second(), "m/s");

    return printer;
}

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
