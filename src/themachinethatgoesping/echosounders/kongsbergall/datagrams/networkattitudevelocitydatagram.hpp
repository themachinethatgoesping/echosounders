// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/networkattitudevelocitydatagram.doc.hpp"

// std includes
#include <cstdint>
#include <string>
#include <vector>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>



#include "../types.hpp"
#include "kongsbergalldatagram.hpp"

#include "substructures/networkattitudevelocitydatagramattitude.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

/**
 * @brief Network attitude velocity datagram 110.
 * This datagram is currently not used in the processing because the Attitude datagram already
 * contains all necessary information.
 */
class NetworkAttitudeVelocityDatagram : public KongsbergAllDatagram
{
  public:
    static constexpr auto DatagramIdentifier =
        t_KongsbergAllDatagramIdentifier::NetworkAttitudeVelocityDatagram;

  protected:
    uint16_t _network_attitude_counter;
    uint16_t _system_serial_number;
    uint16_t _number_of_entries; ///< N
    int8_t   _sensor_system_descriptor;
    uint8_t  _spare;

    // Number_of_entries x Attitude
    std::vector<substructures::NetworkAttitudeVelocityDatagramAttitude>
        _attitudes; ///< N x Attitude data

    uint8_t  _spare_align = 0;
    uint8_t  _etx         = 0x03; ///< end identifier (always 0x03)
    uint16_t _checksum;

  private:
    // ----- private constructors -----
    explicit NetworkAttitudeVelocityDatagram(KongsbergAllDatagram header);

  public:
    // ----- public constructors -----
    NetworkAttitudeVelocityDatagram();
    ~NetworkAttitudeVelocityDatagram() = default;

    // ----- convenient data access -----
    // getters
    uint16_t get_network_attitude_counter() const;
    uint16_t get_system_serial_number() const;
    uint16_t get_number_of_entries() const;
    uint8_t  get_sensor_system_descriptor() const;
    uint8_t  get_etx() const;
    uint16_t get_checksum() const;
    uint8_t  get_spare() const;
    uint8_t  get_spare_align() const;

    // setters
    void set_network_attitude_counter(uint16_t network_attitude_counter);
    void set_system_serial_number(uint16_t system_serial_number);
    void set_number_of_entries(uint16_t number_of_entries);
    void set_sensor_system_descriptor(uint8_t sensor_system_descriptor);
    void set_etx(uint8_t etx);
    void set_checksum(uint16_t checksum);
    void set_spare(uint8_t spare);
    void set_spare_align(uint8_t spare_align);

    // substructures
    std::vector<substructures::NetworkAttitudeVelocityDatagramAttitude>& attitudes();
    const std::vector<substructures::NetworkAttitudeVelocityDatagramAttitude>& get_attitudes() const;
    void set_attitudes(
        std::vector<substructures::NetworkAttitudeVelocityDatagramAttitude> attitudes);

    // ----- processed data access -----
    /**
     * @brief Get the number of attitude sensor from the sensor system descriptor field.
     * If this field is
     * xx10 xxxx – attitude velocity sensor 1 (UDP5)
     * xx11 xxxx – attitude velocity sensor 2 (UDP6)
     *
     * @return 1 or 2
     *
     */
    unsigned int get_attitude_velocity_sensor_number() const;

    /**
     * @brief Evaluate if the velocity sensor is active using sensor system descriptor field.
     * 0bxxxxxxx1 : velocity is active
     * 0bxxxxxxx1 : velocity is inactive
     *
     * The exact meaning of this field is currently not clear to us.
     * If this field is set to false, the attitude data seems to be exactly the same as in the
     * attitude datagram. If it is set to true, the attitude data will be a little bit different.
     *
     * @return bool
     *
     */
    bool get_velocity_sensor_is_active() const;

    /**
     * @brief Evaluate if the heading sensor is active using sensor system descriptor field.
     * 0bxxxxxxx1 : heading is active
     * 0bxxxxxxx1 : heading is inactive
     *
     * @return bool
     *
     */
    bool get_heading_sensor_is_active() const;

    /**
     * @brief Evaluate if the roll sensor is active using sensor system descriptor field.
     * 0bxxxxxx1x : roll is active
     * 0bxxxxxx0x : roll is inactive
     *
     * @return bool
     *
     */
    bool get_roll_sensor_is_active() const;

    /**
     * @brief Evaluate if the pitch sensor is active using sensor system descriptor field.
     * 0bxxxxx1xx : pitch is active
     * 0bxxxxx0xx : pitch is inactive
     *
     * @return bool
     *
     */
    bool get_pitch_sensor_is_active() const;

    /**
     * @brief Evaluate if the heave sensor is active using sensor system descriptor field.
     * 0bxxxx1xxx : heave is active
     * 0bxxxx0xxx : heave is inactive
     *
     * @return bool
     *
     */
    bool get_heave_sensor_is_active() const;

    /**
     * @brief Evaluate if the function is used.
     * -1 : function is not used
     *
     * @return bool
     *
     */
    bool get_function_is_used() const;

    // ----- operators -----
    bool operator==(const NetworkAttitudeVelocityDatagram& other) const = default;

    //----- to/from stream functions -----
    static NetworkAttitudeVelocityDatagram from_stream(std::istream& is, KongsbergAllDatagram header);

    static NetworkAttitudeVelocityDatagram from_stream(std::istream& is);

    static NetworkAttitudeVelocityDatagram from_stream(
        std::istream&              is,
        t_KongsbergAllDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os);

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(NetworkAttitudeVelocityDatagram)
};

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
