// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/pustatusoutput.doc.hpp"

// std includes
#include <cstdint>
#include <string>
#include <vector>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>



#include "../types.hpp"
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
    explicit PUStatusOutput(KongsbergAllDatagram header);

  public:
    // ----- public constructors -----
    PUStatusOutput();
    ~PUStatusOutput() = default;

    // ----- convenient data access -----
    // getters
    uint16_t get_status_datagram_counter() const;
    uint16_t get_system_serial_number() const;
    uint16_t get_ping_rate() const;
    uint16_t get_ping_counter() const;
    uint32_t get_distance_between_swath() const;
    uint32_t get_sensor_input_status_udp_port_2() const;
    uint32_t get_sensor_input_status_serial_port_1() const;
    uint32_t get_sensor_input_status_serial_port_2() const;
    uint32_t get_sensor_input_status_serial_port_3() const;
    uint32_t get_sensor_input_status_serial_port_4() const;
    int8_t   get_pps_status() const;
    int8_t   get_position_status() const;
    int8_t   get_attitude_status() const;
    int8_t   get_clock_status() const;
    int8_t   get_heading_status() const;
    uint8_t  get_pu_status() const;
    uint16_t get_last_received_heading() const;
    int16_t  get_last_received_roll() const;
    int16_t  get_last_received_pitch() const;
    int16_t  get_last_received_heave_at_sonar_head() const;
    uint16_t get_sound_speed_at_transducer() const;
    uint32_t get_last_received_depth() const;
    int16_t  get_along_ship_velocity() const;
    uint8_t  get_attitude_velocity_sensor_status() const;
    uint8_t  get_mammal_protection_ramp() const;
    int8_t   get_backscatter_at_oblique_angle() const;
    int8_t   get_backscatter_at_normal_incidence() const;
    int8_t   get_fixed_gain() const;
    uint8_t  get_depth_to_normal_incidence() const;
    uint16_t get_range_to_normal_incidence() const;
    uint8_t  get_port_coverage() const;
    uint8_t  get_starboard_coverage() const;
    uint16_t get_sound_speed_at_transducer_from_profile() const;
    int16_t  get_yaw_stabilization_angle() const;
    int16_t  get_across_ship_velocity() const;
    int16_t  get_downward_velocity() const;
    int8_t   get_em2040_cpu_temperature() const;

    uint8_t  get_etx() const;
    uint16_t get_checksum() const;

    // setters
    void set_status_datagram_counter(uint16_t status_datagram_counter);
    void set_system_serial_number(uint16_t system_serial_number);
    void set_ping_rate(uint16_t ping_rate);
    void set_ping_counter(uint16_t ping_counter);
    void set_distance_between_swath(uint32_t distance_between_swath);
    void set_sensor_input_status_udp_port_2(uint32_t sensor_input_status_udp_port_2);
    void set_sensor_input_status_serial_port_1(uint32_t sensor_input_status_serial_port_1);
    void set_sensor_input_status_serial_port_2(uint32_t sensor_input_status_serial_port_2);
    void set_sensor_input_status_serial_port_3(uint32_t sensor_input_status_serial_port_3);
    void set_sensor_input_status_serial_port_4(uint32_t sensor_input_status_serial_port_4);
    void set_pps_status(int8_t pps_status);
    void set_position_status(int8_t position_status);
    void set_attitude_status(int8_t attitude_status);
    void set_clock_status(int8_t clock_status);
    void set_heading_status(int8_t heading_status);
    void set_pu_status(int8_t pu_status);
    void set_last_received_heading(uint16_t last_received_heading);
    void set_last_received_roll(int16_t last_received_roll);
    void set_last_received_pitch(int16_t last_received_pitch);
    void set_last_received_heave_at_sonar_head(int16_t last_received_heave_at_sonar_head);
    void set_sound_speed_at_transducer(uint16_t sound_speed_at_transducer);
    void set_last_received_depth(uint32_t last_received_depth);
    void set_along_ship_velocity(int16_t along_ship_velocity);
    void set_attitude_velocity_sensor_status(uint8_t attitude_velocity_sensor_status);
    void set_mammal_protection_ramp(uint8_t mammal_protection_ramp);
    void set_backscatter_at_oblique_angle(int8_t backscatter_at_oblique_angle);
    void set_backscatter_at_normal_incidence(int8_t backscatter_at_normal_incidence);
    void set_fixed_gain(int8_t fixed_gain);
    void set_depth_to_normal_incidence(uint8_t depth_to_normal_incidence);
    void set_range_to_normal_incidence(uint16_t range_to_normal_incidence);
    void set_port_coverage(uint8_t port_coverage);
    void set_starboard_coverage(uint8_t starboard_coverage);
    void set_sound_speed_at_transducer_from_profile(uint16_t sound_speed_at_transducer_from_profile);
    void set_yaw_stabilization_angle(int16_t yaw_stabilization_angle);
    void set_across_ship_velocity(int16_t across_ship_velocity);
    void set_downward_velocity(int16_t downward_velocity);
    void set_em2040_cpu_temperature(int8_t em2040_cpu_temperature);

    void set_etx(uint8_t etx);
    void set_checksum(uint16_t checksum);

    // ----- processed data access -----
    /**
     * @brief Get the ping rate in Hz
     *
     * @return _ping_rate * 0.01 Hz (float)
     */
    float get_ping_rate_hertz() const;

    /**
     * @brief Get the distance between swath in percent
     *
     * @return _distance_between_swath * 0.1f (float )
     */
    float get_distance_between_swath_in_percent() const;

    /**
     * @brief Get the last received heading in degrees
     *
     * @return _last_received_heading * 0.01f (float )
     */
    float get_last_received_heading_in_degrees() const;

    /**
     * @brief Get the last received roll in degrees
     *
     * @return _last_received_roll * 0.01f (float )
     */
    float get_last_received_roll_in_degrees() const;

    /**
     * @brief Get the last received pitch in degrees
     *
     * @return _last_received_pitch * 0.01f (float )
     */
    float get_last_received_pitch_in_degrees() const;

    /**
     * @brief Get the last received heave at sonar head in m
     *
     * @return _last_received_heave_at_sonar_head * 0.01f (float )
     */
    float get_last_received_heave_at_sonar_head_in_meters() const;

    /**
     * @brief Get the last received heave at sonar head in meters per second
     *
     * @return _sound_speed_at_transducer * 0.1f (float )
     */
    float get_sound_speed_at_transducer_in_meters_per_second() const;

    /**
     * @brief Get the last received depth in meters
     *
     * @return _last_received_depth * 0.01f (float )
     */
    float get_last_received_depth_in_meters() const;

    /**
     * @brief Get the along ship velocity in m/s
     *
     * @return _along_ship_velocity * 0.01f (float )
     */
    float get_along_ship_velocity_in_meters_per_second() const;

    /**
     * @brief Get the sound speed at transducer (derived from profile) in m/s
     *
     * @return _sound_speed_at_transducer_from_profile * 0.1f (float )
     */
    float get_sound_speed_at_transducer_from_profile_in_meters_per_second() const;

    /**
     * @brief Get the yaw stabilization angle in degrees
     *
     * @return _yaw_stabilization_angle * 0.01f (float )
     */
    float get_yaw_stabilization_angle_in_degrees() const;

    /**
     * @brief Get the across ship velocity in m/s
     *
     * @return _across_ship_velocity * 0.01f (float )
     */
    float get_across_ship_velocity_in_meters_per_second() const;

    /**
     * @brief Get the downward velocity in m/s
     *
     * @return _downward_velocity * 0.01f (float )
     */
    float get_downward_velocity_in_meters_per_second() const;

    // ----- operators -----
    bool operator==(const PUStatusOutput& other) const = default;

    //----- to/from stream functions -----
    static PUStatusOutput from_stream(std::istream& is, KongsbergAllDatagram header);

    static PUStatusOutput from_stream(std::istream& is);

    static PUStatusOutput from_stream(std::istream&              is,
                                      t_KongsbergAllDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(PUStatusOutput)
};

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
