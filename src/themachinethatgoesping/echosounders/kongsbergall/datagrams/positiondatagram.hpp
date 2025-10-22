// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/positiondatagram.doc.hpp"

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
 * @brief Depth (pressure) or height datagrams
 */
class PositionDatagram : public KongsbergAllDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_KongsbergAllDatagramIdentifier::PositionDatagram;

  protected:
    uint16_t _position_counter;
    uint16_t _system_serial_number;
    int32_t  _latitude;             ///< latitude in 0.00000005° negative if southern hemishpere
    int32_t  _longitude;            ///< longitude in 0.0000001° negative if western hemishpere
    uint16_t _position_fix_quality; ///< fix quality in cm;
    uint16_t _speed;                ///< over ground in cm/s
    uint16_t _course;               ///< over ground in 0.01°
    uint16_t _heading;              ///< in 0.01°
    uint8_t  _position_system_descriptor;
    uint8_t  _size_of_input_datagram = 0; ///< in input datagram;

    std::string _input_datagram; ///< as received (NMEA 0183);

    uint8_t  _spare = 0;    ///< only if required to make the datagram size even
    uint8_t  _etx   = 0x03; ///< end identifier (always 0x03)
    uint16_t _checksum;

  private:
    // ----- private constructors -----
    explicit PositionDatagram(KongsbergAllDatagram header);

  public:
    // ----- public constructors -----
    PositionDatagram();
    ~PositionDatagram() = default;

    // ----- convenient data access -----
    // getters
    uint16_t    get_position_counter() const;
    uint16_t    get_system_serial_number() const;
    int32_t     get_latitude() const;
    int32_t     get_longitude() const;
    uint16_t    get_position_fix_quality() const;
    uint16_t    get_speed() const;
    uint16_t    get_course() const;
    uint16_t    get_heading() const;
    uint8_t     get_position_system_descriptor() const;
    uint8_t     get_size_of_input_datagram() const;
    std::string get_input_datagram() const;
    uint8_t     get_spare() const;
    uint8_t     get_etx() const;
    uint16_t    get_checksum() const;

    // setters
    void set_position_counter(uint16_t position_counter);
    void set_system_serial_number(uint16_t system_serial_number);
    void set_latitude(int32_t latitude);
    void set_longitude(int32_t longitude);
    void set_position_fix_quality(uint16_t position_fix_quality);
    void set_speed(uint16_t speed);
    void set_course(uint16_t course);
    void set_heading(uint16_t heading);
    void set_position_system_descriptor(uint8_t position_system_descriptor);
    void set_size_of_input_datagram(uint8_t size_of_input_datagram);
    void set_input_datagram(std::string input_datagram);
    void set_spare(uint8_t spare);
    void set_etx(uint8_t etx);
    void set_checksum(uint16_t checksum);

    // ----- processed data access -----
    /**
     * @brief Get the latitude in degrees
     *
     * @return _latitude * 0.00000005° (double)
     */
    double get_latitude_in_degrees() const;

    /**
     * @brief Get the longitude in degrees
     *
     * @return _longitude * 0.0000001° (double)
     */
    double get_longitude_in_degrees() const;

    /**
     * @brief Get the position fix quality in meters
     *
     * @return _position_fix_quality * 0.01m (float)
     */
    float get_position_fix_quality_in_meters() const;

    /**
     * @brief Get the speed of vessel in meter per second
     *
     * @return _speed * 0.01m/s (float)
     */
    float get_speed_in_meters_per_second() const;

    /**
     * @brief Get the course of vessel in degrees
     *
     * @return _course * 0.01° (float)
     */
    float get_course_in_degrees() const;

    /**
     * @brief Get the heading of vessel in degrees
     *
     * @return _heading * 0.01° (float)
     */
    float get_heading_in_degrees() const;

    /**
     * @brief Evaluate if the position_system_descriptor for the used system number
     *
     * @return 1, 2 or 3 (uint8_t )
     */
    uint8_t get_position_system_number() const;

    /**
     * @brief Evaluate if the position_system_descriptor for the used system number
     *
     * xxxx 1xxx – the position may have to be derived from the input datagram which is then in
     * SIMRADRAW 90 format.
     *
     * @return true or false (bool)
     */
    bool get_position_system_SIMRAD90_flag() const;

    /**
     * @brief Evaluate the position_system_descriptor for the used time
     *
     * @return true: system time has been used
     * @return false: input datagram time has been used
     */
    bool get_position_system_system_time_has_been_used() const;

    // ----- operators -----
    bool operator==(const PositionDatagram& other) const = default;

    //----- to/from stream functions -----
    static PositionDatagram from_stream(std::istream& is, KongsbergAllDatagram header);

    static PositionDatagram from_stream(std::istream& is);

    static PositionDatagram from_stream(std::istream&              is,
                                        t_KongsbergAllDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(PositionDatagram)
};

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
