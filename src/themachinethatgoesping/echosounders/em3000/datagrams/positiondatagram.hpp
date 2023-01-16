// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/positiondatagram.doc.hpp"

// std includes
#include <string>
#include <vector>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../em3000_types.hpp"
#include "em3000datagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace datagrams {

/**
 * @brief Depth (pressure) or height datagrams
 */
class PositionDatagram : public EM3000Datagram
{
  protected:
    uint16_t _position_counter;
    uint16_t _system_serial_number;
    int32_t  _latitude;             ///< latitude in 0.00000005° negative if southern hemishpere
    int32_t  _longitude;            ///< longitude in 0.0000001° negative if western hemishpere
    uint16_t _position_fix_quality; ///< fix quality in cm;
    uint16_t _speed_of_vessel;      ///< over ground in cm/s
    uint16_t _course_of_vessel;     ///< over ground in 0.01°
    uint16_t _heading_of_vessel;    ///< in 0.01°
    uint8_t  _position_system_descriptor;
    uint8_t  _size_of_input_datagram = 0; ///< in input datagram;

    std::string _input_datagram; ///< as received (NMEA 0183);

    uint8_t  _spare;
    uint8_t  _etx = 0x03; ///< end identifier (always 0x03)
    uint16_t _checksum;

  private:
    // ----- private constructors -----
    explicit PositionDatagram(EM3000Datagram header)
        : EM3000Datagram(std::move(header))
    {
    }

  public:
    // ----- public constructors -----
    PositionDatagram() { _datagram_identifier = t_EM3000DatagramIdentifier::PositionDatagram; }
    ~PositionDatagram() = default;

    // ----- convenient data access -----
    // getters
    uint16_t    get_position_counter() const { return _position_counter; }
    uint16_t    get_system_serial_number() const { return _system_serial_number; }
    int32_t     get_latitude() const { return _latitude; }
    int32_t     get_longitude() const { return _longitude; }
    uint16_t    get_position_fix_quality() const { return _position_fix_quality; }
    uint16_t    get_speed_of_vessel() const { return _speed_of_vessel; }
    uint16_t    get_course_of_vessel() const { return _course_of_vessel; }
    uint16_t    get_heading_of_vessel() const { return _heading_of_vessel; }
    uint8_t     get_position_system_descriptor() const { return _position_system_descriptor; }
    uint8_t     get_size_of_input_datagram() const { return _size_of_input_datagram; }
    std::string get_input_datagram() const { return _input_datagram; }
    uint8_t     get_spare() const { return _spare; }
    uint8_t     get_etx() const { return _etx; }
    uint16_t    get_checksum() const { return _checksum; }

    // setters
    void set_position_counter(uint16_t position_counter) { _position_counter = position_counter; }
    void set_system_serial_number(uint16_t system_serial_number)
    {
        _system_serial_number = system_serial_number;
    }
    void set_latitude(int32_t latitude) { _latitude = latitude; }
    void set_longitude(int32_t longitude) { _longitude = longitude; }
    void set_position_fix_quality(uint16_t position_fix_quality)
    {
        _position_fix_quality = position_fix_quality;
    }
    void set_speed_of_vessel(uint16_t speed_of_vessel) { _speed_of_vessel = speed_of_vessel; }
    void set_course_of_vessel(uint16_t course_of_vessel) { _course_of_vessel = course_of_vessel; }
    void set_heading_of_vessel(uint16_t heading_of_vessel)
    {
        _heading_of_vessel = heading_of_vessel;
    }
    void set_position_system_descriptor(uint8_t position_system_descriptor)
    {
        _position_system_descriptor = position_system_descriptor;
    }
    void set_size_of_input_datagram(uint8_t size_of_input_datagram)
    {
        _size_of_input_datagram = size_of_input_datagram;
    }
    void set_input_datagram(std::string input_datagram) { _input_datagram = input_datagram; }
    void set_spare(uint8_t spare) { _spare = spare; }
    void set_etx(uint8_t etx) { _etx = etx; }
    void set_checksum(uint16_t checksum) { _checksum = checksum; }

    // ----- processed data access -----
    /**
     * @brief Get the latitude in degrees
     *
     * @return _latitude * 0.00000005° (double)
     */
    double get_latitude_in_degrees() const { return _latitude * 0.00000005; }

    /**
     * @brief Get the longitude in degrees
     *
     * @return _longitude * 0.0000001° (double)
     */
    double get_longitude_in_degrees() const { return _longitude * 0.0000001; }

    /**
     * @brief Get the position fix quality in meters
     *
     * @return _position_fix_quality * 0.01m (float)
     */
    float get_position_fix_quality_in_meters() const { return _position_fix_quality * 0.01; }

    /**
     * @brief Get the speed of vessel in meter per second
     *
     * @return _speed_of_vessel * 0.01m/s (float)
     */
    float get_speed_of_vessel_in_meters_per_second() const { return _speed_of_vessel * 0.01; }

    /**
     * @brief Get the course of vessel in degrees
     *
     * @return _course_of_vessel * 0.01° (float)
     */
    float get_course_of_vessel_in_degrees() const { return _course_of_vessel * 0.01; }

    /**
     * @brief Get the heading of vessel in degrees
     *
     * @return _heading_of_vessel * 0.01° (float)
     */
    float get_heading_of_vessel_in_degrees() const { return _heading_of_vessel * 0.01; }

    /**
     * @brief Evaluate if the position_system_descriptor for the used system number
     *
     * @return 1, 2 or 3 (uint8_t )
     */
    uint8_t get_position_system_number() const { return _position_system_descriptor & 0b00000011; }

    /**
     * @brief Evaluate if the position_system_descriptor for the used system number
     *
     * xxxx 1xxx – the position may have to be derived from the input datagram which is then in
     * SIMRAD 90 format.
     *
     * @return true or false (bool)
     */
    bool get_position_system_SIMRAD90_flag() const
    {
        if ((_position_system_descriptor & 0b00001000) > 0)
            return true;
        else
            return false;
    }

    /**
     * @brief Evaluate the position_system_descriptor for the used time
     *
     * @return true: system time has been used
     * @return false: input datagram time has been used
     */
    bool get_position_system_system_time_has_been_used() const
    {
        if ((_position_system_descriptor & 0b11000000) == 0b10000000)
            return true;
        else
            return false;
    }

    // ----- operators -----
    bool operator==(const PositionDatagram& other) const
    {
        return EM3000Datagram::operator==(other) && _position_counter == other._position_counter &&
               _system_serial_number == other._system_serial_number &&
               _latitude == other._latitude && _longitude == other._longitude &&
               _position_fix_quality == other._position_fix_quality &&
               _speed_of_vessel == other._speed_of_vessel &&
               _course_of_vessel == other._course_of_vessel &&
               _heading_of_vessel == other._heading_of_vessel &&
               _position_system_descriptor == other._position_system_descriptor &&
               _size_of_input_datagram == other._size_of_input_datagram &&
               _input_datagram == other._input_datagram && _spare == other._spare &&
               _etx == other._etx && _checksum == other._checksum;
    }
    bool operator!=(const PositionDatagram& other) const { return !operator==(other); }

    //----- to/from stream functions -----
    static PositionDatagram from_stream(std::istream& is, EM3000Datagram header)
    {
        PositionDatagram datagram(std::move(header));

        if (datagram._datagram_identifier != t_EM3000DatagramIdentifier::PositionDatagram)
            throw std::runtime_error(
                fmt::format("PositionDatagram: datagram identifier is not 0x{:02x}, but 0x{:02x}",
                            uint8_t(t_EM3000DatagramIdentifier::PositionDatagram),
                            uint8_t(datagram._datagram_identifier)));

        // read first part of the datagram (until the first beam)
        is.read(reinterpret_cast<char*>(&(datagram._position_counter)), 22 * sizeof(uint8_t));

        // read the input datagram
        datagram._input_datagram.resize(datagram._size_of_input_datagram);
        is.read(reinterpret_cast<char*>(datagram._input_datagram.data()),
                datagram._size_of_input_datagram * sizeof(uint8_t));

        // read the last part of the datagram
        is.read(reinterpret_cast<char*>(&(datagram._spare)), 4 * sizeof(uint8_t));

        if (datagram._etx != 0x03)
            throw std::runtime_error(fmt::format(
                "PositionDatagram: end identifier is not 0x03, but 0x{:x}", datagram._etx));

        return datagram;
    }

    static PositionDatagram from_stream(std::istream& is)
    {
        return from_stream(is, EM3000Datagram::from_stream(is));
    }

    static PositionDatagram from_stream(std::istream&              is,
                                        t_EM3000DatagramIdentifier datagram_identifier)
    {
        return from_stream(is, std::move(EM3000Datagram::from_stream(is, datagram_identifier)));
    }

    void to_stream(std::ostream& os) const
    {
        if (_input_datagram.size() != _size_of_input_datagram)
            throw std::runtime_error(fmt::format(
                "PositionDatagram::to_stream(): size of input datagram is not {}, but {}",
                _size_of_input_datagram,
                _input_datagram.size()));

        EM3000Datagram::to_stream(os);

        // write first part of the datagram (until the first beam)
        os.write(reinterpret_cast<const char*>(&(_position_counter)), 22 * sizeof(uint8_t));

        // write the input datagram
        os.write(reinterpret_cast<const char*>(_input_datagram.data()),
                 _size_of_input_datagram * sizeof(uint8_t));

        // write the last part of the datagram
        os.write(reinterpret_cast<const char*>(&_spare), 4 * sizeof(uint8_t));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("PositionDatagram", float_precision);

        printer.append(EM3000Datagram::__printer__(float_precision));
        printer.register_section("datagram content");
        printer.register_value("position_counter", _position_counter);
        printer.register_value("system_serial_number", _system_serial_number);
        printer.register_value("latitude", _latitude, "°0.00000005°");
        printer.register_value("longitude", _longitude, " 0.0000001°");
        printer.register_value("position_fix_quality", _position_fix_quality, "cm");
        printer.register_value("speed_of_vessel", _speed_of_vessel, "cm/s");
        printer.register_value("course_of_vessel", _course_of_vessel, "0.01°");
        printer.register_value("heading_of_vessel", _heading_of_vessel, "0.01°");
        printer.register_string("position_system_descriptor",
                                fmt::format("0b{:08x}", _position_system_descriptor));
        printer.register_value("size_of_input_datagram", _size_of_input_datagram, "bytes");

        printer.register_section("processed");
        printer.register_value("latitude", get_latitude_in_degrees(), "°");
        printer.register_value("longitude", get_longitude_in_degrees(), "°");
        printer.register_value("position_fix_quality", get_position_fix_quality_in_meters(), "m");
        printer.register_value(
            "speed_of_vessel", get_speed_of_vessel_in_meters_per_second(), "m/s");
        printer.register_value("course_of_vessel", get_course_of_vessel_in_degrees(), "°");
        printer.register_value("heading_of_vessel", get_heading_of_vessel_in_degrees(), "°");
        printer.register_value("position_system_number", get_position_system_number(), "1,2 or 3");
        printer.register_value("position_system_SIMRAD90_flag",
                               get_position_system_SIMRAD90_flag());
        printer.register_value("position_system_system_time_has_been_used",
                               get_position_system_system_time_has_been_used());
        printer.register_value("position_system_input_datagram_time_has_been_used",
                               !get_position_system_system_time_has_been_used());

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(PositionDatagram)
};

} // namespace datagrams
} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping
