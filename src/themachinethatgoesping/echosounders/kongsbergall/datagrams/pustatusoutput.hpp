// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/pustatusoutput.doc.hpp"

// std includes
#include <string>
#include <vector>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../kongsbergall_types.hpp"
#include "kongsbergalldatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

/**
 * @brief The PU Status datagram is sent out every second if requested by the host processor. It has
 * two functions, to indicate that the system is alive and receiving sensor data, and to give sensor
 * data regularly for a potential screen update.
 */
class PUStatusOutput : public KongsbergAllDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_KongsbergAllDatagramIdentifier::PUStatusOutput;

  protected:
    uint16_t _status_datagram_counter;
    uint16_t _system_serial_number;
    uint16_t _ping_rate;                              ///< in 0.01 Hz
    uint16_t _ping_counter;                           ///< of latest ping
    uint32_t _distance_between_swath;                 ///< in 10%
    uint32_t _sensor_input_status_udp_port_2;         ///<
    uint32_t _sensor_input_status_serial_port_1;      ///<
    uint32_t _sensor_input_status_serial_port_2;      ///<
    uint32_t _sensor_input_status_serial_port_3;      ///<
    uint32_t _sensor_input_status_serial_port_4;      ///<
    int8_t   _pps_status;                             ///<
    int8_t   _position_status;                        ///<
    int8_t   _attitude_status;                        ///<
    int8_t   _clock_status;                           ///<
    int8_t   _heading_status;                         ///<
    uint8_t  _pu_status;                              ///<
    uint16_t _last_received_heading;                  ///< in 0.01 degree
    int16_t  _last_received_roll;                     ///< in 0.01 degree
    int16_t  _last_received_pitch;                    ///< in 0.01 degree
    int16_t  _last_received_heave_at_sonar_head;      ///< in cm
    uint16_t _sound_speed_at_transducer;              ///< in dm/s
    uint32_t _last_received_depth;                    ///< in cm
    int16_t  _along_ship_velocity;                    ///< in cm/s
    uint8_t  _attitude_velocity_sensor_status;        ///<
    uint8_t  _mammal_protection_ramp;                 ///<
    int8_t   _backscatter_at_oblique_angle;           ///< in dB
    int8_t   _backscatter_at_normal_incidence;        ///< in dB
    int8_t   _fixed_gain;                             ///< in dB
    uint8_t  _depth_to_normal_incidence;              ///< in m
    uint16_t _range_to_normal_incidence;              ///< in m
    uint8_t  _port_coverage;                          ///< in degrees
    uint8_t  _starboard_coverage;                     ///< in degrees
    uint16_t _sound_speed_at_transducer_from_profile; ///< in dm/s
    int16_t  _yaw_stabilization_angle; ///< in 0.01 degree, or tilt used at 3D scanning
    int16_t  _across_ship_velocity;    ///< in cm/s (or port coverage or spare)
    int16_t  _downward_velocity;       ///< in cm/s (or starboard coverage or spare)
    int8_t   _em2040_cpu_temperature;  ///< in degree Celsius (or spare)

    uint8_t  _etx = 0x03; ///< end identifier (always 0x03)
    uint16_t _checksum;

  private:
    // ----- private constructors -----
    explicit PUStatusOutput(KongsbergAllDatagram header)
        : KongsbergAllDatagram(std::move(header))
    {
    }

  public:
    // ----- public constructors -----
    PUStatusOutput() { _datagram_identifier = t_KongsbergAllDatagramIdentifier::PUStatusOutput; }
    ~PUStatusOutput() = default;

    // ----- convenient data access -----
    // getters
    uint16_t get_status_datagram_counter() const { return _status_datagram_counter; }
    uint16_t get_system_serial_number() const { return _system_serial_number; }
    uint16_t get_ping_rate() const { return _ping_rate; }
    uint16_t get_ping_counter() const { return _ping_counter; }
    uint32_t get_distance_between_swath() const { return _distance_between_swath; }
    uint32_t get_sensor_input_status_udp_port_2() const { return _sensor_input_status_udp_port_2; }
    uint32_t get_sensor_input_status_serial_port_1() const
    {
        return _sensor_input_status_serial_port_1;
    }
    uint32_t get_sensor_input_status_serial_port_2() const
    {
        return _sensor_input_status_serial_port_2;
    }
    uint32_t get_sensor_input_status_serial_port_3() const
    {
        return _sensor_input_status_serial_port_3;
    }
    uint32_t get_sensor_input_status_serial_port_4() const
    {
        return _sensor_input_status_serial_port_4;
    }
    int8_t   get_pps_status() const { return _pps_status; }
    int8_t   get_position_status() const { return _position_status; }
    int8_t   get_attitude_status() const { return _attitude_status; }
    int8_t   get_clock_status() const { return _clock_status; }
    int8_t   get_heading_status() const { return _heading_status; }
    uint8_t  get_pu_status() const { return _pu_status; }
    uint16_t get_last_received_heading() const { return _last_received_heading; }
    int16_t  get_last_received_roll() const { return _last_received_roll; }
    int16_t  get_last_received_pitch() const { return _last_received_pitch; }
    int16_t  get_last_received_heave_at_sonar_head() const
    {
        return _last_received_heave_at_sonar_head;
    }
    uint16_t get_sound_speed_at_transducer() const { return _sound_speed_at_transducer; }
    uint32_t get_last_received_depth() const { return _last_received_depth; }
    int16_t  get_along_ship_velocity() const { return _along_ship_velocity; }
    uint8_t get_attitude_velocity_sensor_status() const { return _attitude_velocity_sensor_status; }
    uint8_t get_mammal_protection_ramp() const { return _mammal_protection_ramp; }
    int8_t  get_backscatter_at_oblique_angle() const { return _backscatter_at_oblique_angle; }
    int8_t  get_backscatter_at_normal_incidence() const { return _backscatter_at_normal_incidence; }
    int8_t  get_fixed_gain() const { return _fixed_gain; }
    uint8_t get_depth_to_normal_incidence() const { return _depth_to_normal_incidence; }
    uint16_t get_range_to_normal_incidence() const { return _range_to_normal_incidence; }
    uint8_t  get_port_coverage() const { return _port_coverage; }
    uint8_t  get_starboard_coverage() const { return _starboard_coverage; }
    uint16_t get_sound_speed_at_transducer_from_profile() const
    {
        return _sound_speed_at_transducer_from_profile;
    }
    int16_t get_yaw_stabilization_angle() const { return _yaw_stabilization_angle; }
    int16_t get_across_ship_velocity() const { return _across_ship_velocity; }
    int16_t get_downward_velocity() const { return _downward_velocity; }
    int8_t  get_em2040_cpu_temperature() const { return _em2040_cpu_temperature; }

    uint8_t  get_etx() const { return _etx; }
    uint16_t get_checksum() const { return _checksum; }

    // setters
    void set_status_datagram_counter(uint16_t status_datagram_counter)
    {
        _status_datagram_counter = status_datagram_counter;
    }
    void set_system_serial_number(uint16_t system_serial_number)
    {
        _system_serial_number = system_serial_number;
    }
    void set_ping_rate(uint16_t ping_rate) { _ping_rate = ping_rate; }
    void set_ping_counter(uint16_t ping_counter) { _ping_counter = ping_counter; }
    void set_distance_between_swath(uint32_t distance_between_swath)
    {
        _distance_between_swath = distance_between_swath;
    }
    void set_sensor_input_status_udp_port_2(uint32_t sensor_input_status_udp_port_2)
    {
        _sensor_input_status_udp_port_2 = sensor_input_status_udp_port_2;
    }
    void set_sensor_input_status_serial_port_1(uint32_t sensor_input_status_serial_port_1)
    {
        _sensor_input_status_serial_port_1 = sensor_input_status_serial_port_1;
    }
    void set_sensor_input_status_serial_port_2(uint32_t sensor_input_status_serial_port_2)
    {
        _sensor_input_status_serial_port_2 = sensor_input_status_serial_port_2;
    }
    void set_sensor_input_status_serial_port_3(uint32_t sensor_input_status_serial_port_3)
    {
        _sensor_input_status_serial_port_3 = sensor_input_status_serial_port_3;
    }
    void set_sensor_input_status_serial_port_4(uint32_t sensor_input_status_serial_port_4)
    {
        _sensor_input_status_serial_port_4 = sensor_input_status_serial_port_4;
    }
    void set_pps_status(int8_t pps_status) { _pps_status = pps_status; }
    void set_position_status(int8_t position_status) { _position_status = position_status; }
    void set_attitude_status(int8_t attitude_status) { _attitude_status = attitude_status; }
    void set_clock_status(int8_t clock_status) { _clock_status = clock_status; }
    void set_heading_status(int8_t heading_status) { _heading_status = heading_status; }
    void set_pu_status(int8_t pu_status) { _pu_status = pu_status; }
    void set_last_received_heading(uint16_t last_received_heading)
    {
        _last_received_heading = last_received_heading;
    }
    void set_last_received_roll(int16_t last_received_roll)
    {
        _last_received_roll = last_received_roll;
    }
    void set_last_received_pitch(int16_t last_received_pitch)
    {
        _last_received_pitch = last_received_pitch;
    }
    void set_last_received_heave_at_sonar_head(int16_t last_received_heave_at_sonar_head)
    {
        _last_received_heave_at_sonar_head = last_received_heave_at_sonar_head;
    }
    void set_sound_speed_at_transducer(uint16_t sound_speed_at_transducer)
    {
        _sound_speed_at_transducer = sound_speed_at_transducer;
    }
    void set_last_received_depth(uint32_t last_received_depth)
    {
        _last_received_depth = last_received_depth;
    }
    void set_along_ship_velocity(int16_t along_ship_velocity)
    {
        _along_ship_velocity = along_ship_velocity;
    }
    void set_attitude_velocity_sensor_status(uint8_t attitude_velocity_sensor_status)
    {
        _attitude_velocity_sensor_status = attitude_velocity_sensor_status;
    }
    void set_mammal_protection_ramp(uint8_t mammal_protection_ramp)
    {
        _mammal_protection_ramp = mammal_protection_ramp;
    }
    void set_backscatter_at_oblique_angle(int8_t backscatter_at_oblique_angle)
    {
        _backscatter_at_oblique_angle = backscatter_at_oblique_angle;
    }
    void set_backscatter_at_normal_incidence(int8_t backscatter_at_normal_incidence)
    {
        _backscatter_at_normal_incidence = backscatter_at_normal_incidence;
    }
    void set_fixed_gain(int8_t fixed_gain) { _fixed_gain = fixed_gain; }
    void set_depth_to_normal_incidence(uint8_t depth_to_normal_incidence)
    {
        _depth_to_normal_incidence = depth_to_normal_incidence;
    }
    void set_range_to_normal_incidence(uint16_t range_to_normal_incidence)
    {
        _range_to_normal_incidence = range_to_normal_incidence;
    }
    void set_port_coverage(uint8_t port_coverage) { _port_coverage = port_coverage; }
    void set_starboard_coverage(uint8_t starboard_coverage)
    {
        _starboard_coverage = starboard_coverage;
    }
    void set_sound_speed_at_transducer_from_profile(uint16_t sound_speed_at_transducer_from_profile)
    {
        _sound_speed_at_transducer_from_profile = sound_speed_at_transducer_from_profile;
    }
    void set_yaw_stabilization_angle(int16_t yaw_stabilization_angle)
    {
        _yaw_stabilization_angle = yaw_stabilization_angle;
    }
    void set_across_ship_velocity(int16_t across_ship_velocity)
    {
        _across_ship_velocity = across_ship_velocity;
    }
    void set_downward_velocity(int16_t downward_velocity)
    {
        _downward_velocity = downward_velocity;
    }
    void set_em2040_cpu_temperature(int8_t em2040_cpu_temperature)
    {
        _em2040_cpu_temperature = em2040_cpu_temperature;
    }

    void set_etx(uint8_t etx) { _etx = etx; }
    void set_checksum(uint16_t checksum) { _checksum = checksum; }

    // ----- processed data access -----
    /**
     * @brief Get the ping rate in Hz
     *
     * @return _ping_rate * 0.01 Hz (float)
     */
    float get_ping_rate_hertz() const { return _ping_rate * 0.01f; }

    /**
     * @brief Get the distance between swath in percent
     *
     * @return _distance_between_swath * 0.1f (float )
     */
    float get_distance_between_swath_in_percent() const { return _distance_between_swath * 0.1f; }

    /**
     * @brief Get the last received heading in degrees
     *
     * @return _last_received_heading * 0.01f (float )
     */
    float get_last_received_heading_in_degrees() const { return _last_received_heading * 0.01f; }

    /**
     * @brief Get the last received roll in degrees
     *
     * @return _last_received_roll * 0.01f (float )
     */
    float get_last_received_roll_in_degrees() const { return _last_received_roll * 0.01f; }

    /**
     * @brief Get the last received pitch in degrees
     *
     * @return _last_received_pitch * 0.01f (float )
     */
    float get_last_received_pitch_in_degrees() const { return _last_received_pitch * 0.01f; }

    /**
     * @brief Get the last received heave at sonar head in m
     *
     * @return _last_received_heave_at_sonar_head * 0.01f (float )
     */
    float get_last_received_heave_at_sonar_head_in_meters() const
    {
        return _last_received_heave_at_sonar_head * 0.01f;
    }

    /**
     * @brief Get the last received heave at sonar head in meters per second
     *
     * @return _sound_speed_at_transducer * 0.1f (float )
     */
    float get_sound_speed_at_transducer_in_meters_per_second() const
    {
        return _sound_speed_at_transducer * 0.1f;
    }

    /**
     * @brief Get the last received depth in meters
     *
     * @return _last_received_depth * 0.01f (float )
     */
    float get_last_received_depth_in_meters() const { return _last_received_depth * 0.01f; }

    /**
     * @brief Get the along ship velocity in m/s
     *
     * @return _along_ship_velocity * 0.01f (float )
     */
    float get_along_ship_velocity_in_meters_per_second() const
    {
        return _along_ship_velocity * 0.01f;
    }

    /**
     * @brief Get the sound speed at transducer (derived from profile) in m/s
     *
     * @return _sound_speed_at_transducer_from_profile * 0.1f (float )
     */
    float get_sound_speed_at_transducer_from_profile_in_meters_per_second() const
    {
        return _sound_speed_at_transducer_from_profile * 0.1f;
    }

    /**
     * @brief Get the yaw stabilization angle in degrees
     *
     * @return _yaw_stabilization_angle * 0.01f (float )
     */
    float get_yaw_stabilization_angle_in_degrees() const
    {
        return _yaw_stabilization_angle * 0.01f;
    }

    /**
     * @brief Get the across ship velocity in m/s
     *
     * @return _across_ship_velocity * 0.01f (float )
     */
    float get_across_ship_velocity_in_meters_per_second() const
    {
        return _across_ship_velocity * 0.01f;
    }

    /**
     * @brief Get the downward velocity in m/s
     *
     * @return _downward_velocity * 0.01f (float )
     */
    float get_downward_velocity_in_meters_per_second() const { return _downward_velocity * 0.01f; }

    // ----- operators -----
    bool operator==(const PUStatusOutput& other) const = default;

    //----- to/from stream functions -----
    static PUStatusOutput from_stream(std::istream& is, KongsbergAllDatagram header)
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

    static PUStatusOutput from_stream(std::istream& is)
    {
        return from_stream(is, KongsbergAllDatagram::from_stream(is));
    }

    static PUStatusOutput from_stream(std::istream&              is,
                                      t_KongsbergAllDatagramIdentifier datagram_identifier)
    {
        return from_stream(is, KongsbergAllDatagram::from_stream(is, datagram_identifier));
    }

    void to_stream(std::ostream& os)
    {
        KongsbergAllDatagram::to_stream(os);

        // write first part of the datagram (until the first beam)
        os.write(reinterpret_cast<const char*>(&(_status_datagram_counter)), 76 * sizeof(uint8_t));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("PUStatusOutput", float_precision);

        printer.append(KongsbergAllDatagram::__printer__(float_precision));
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

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(PUStatusOutput)
};

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
