// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/networkattitudevelocitydatagram.doc.hpp"

// std includes
#include <string>
#include <vector>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../em3000_types.hpp"
#include "em3000datagram.hpp"

#include "substructures/networkattitudevelocitydatagramattitude.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace datagrams {

/**
 * @brief Network attitude velocity datagram 110.
 * This datagram is currently not used in the processing because the Attitude datagram already
 * contains all necessary information.
 */
class NetworkAttitudeVelocityDatagram : public EM3000Datagram
{
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
    explicit NetworkAttitudeVelocityDatagram(EM3000Datagram header)
        : EM3000Datagram(std::move(header))
    {
    }

  public:
    // ----- public constructors -----
    NetworkAttitudeVelocityDatagram()
    {
        _datagram_identifier = t_EM3000DatagramIdentifier::NetworkAttitudeVelocityDatagram;
    }
    ~NetworkAttitudeVelocityDatagram() = default;

    // ----- convenient data access -----
    // getters
    uint16_t get_network_attitude_counter() const { return _network_attitude_counter; }
    uint16_t get_system_serial_number() const { return _system_serial_number; }
    uint16_t get_number_of_entries() const { return _number_of_entries; }
    uint8_t  get_sensor_system_descriptor() const { return _sensor_system_descriptor; }
    uint8_t  get_etx() const { return _etx; }
    uint16_t get_checksum() const { return _checksum; }
    uint8_t  get_spare() const { return _spare; }
    uint8_t  get_spare_align() const { return _spare_align; }

    // setters
    void set_network_attitude_counter(uint16_t network_attitude_counter)
    {
        _network_attitude_counter = network_attitude_counter;
    }
    void set_system_serial_number(uint16_t system_serial_number)
    {
        _system_serial_number = system_serial_number;
    }
    void set_number_of_entries(uint16_t number_of_entries)
    {
        _number_of_entries = number_of_entries;
    }
    void set_sensor_system_descriptor(uint8_t sensor_system_descriptor)
    {
        _sensor_system_descriptor = sensor_system_descriptor;
    }
    void set_etx(uint8_t etx) { _etx = etx; }
    void set_checksum(uint16_t checksum) { _checksum = checksum; }
    void set_spare(uint8_t spare) { _spare = spare; }
    void set_spare_align(uint8_t spare_align) { _spare_align = spare_align; }

    // substructures
    std::vector<substructures::NetworkAttitudeVelocityDatagramAttitude>& attitudes()
    {
        return _attitudes;
    }
    const std::vector<substructures::NetworkAttitudeVelocityDatagramAttitude>& get_attitudes() const
    {
        return _attitudes;
    }
    void set_attitudes(
        std::vector<substructures::NetworkAttitudeVelocityDatagramAttitude> attitudes)
    {
        _attitudes = std::move(attitudes);
    }

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
    unsigned int get_attitude_velocity_sensor_number() const
    {
        if (!get_function_is_used())
            return false;

        if (_sensor_system_descriptor & 0b00110000)
            return 2;
        else
            return 1;
    }

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
    bool get_velocity_sensor_is_active() const
    {
        if (!get_function_is_used())
            return false;

        if (_sensor_system_descriptor & 0b01000000)
            return true;
        else
            return false;
    }

    /**
     * @brief Evaluate if the heading sensor is active using sensor system descriptor field.
     * 0bxxxxxxx1 : heading is active
     * 0bxxxxxxx1 : heading is inactive
     *
     * @return bool
     *
     */
    bool get_heading_sensor_is_active() const
    {
        if (!get_function_is_used())
            return false;

        if (_sensor_system_descriptor & 0b00000001)
            return true;
        else
            return false;
    }

    /**
     * @brief Evaluate if the roll sensor is active using sensor system descriptor field.
     * 0bxxxxxx1x : roll is active
     * 0bxxxxxx0x : roll is inactive
     *
     * @return bool
     *
     */
    bool get_roll_sensor_is_active() const
    {
        if (!get_function_is_used())
            return false;

        if (_sensor_system_descriptor & 0b00000010)
            return true;
        else
            return false;
    }

    /**
     * @brief Evaluate if the pitch sensor is active using sensor system descriptor field.
     * 0bxxxxx1xx : pitch is active
     * 0bxxxxx0xx : pitch is inactive
     *
     * @return bool
     *
     */
    bool get_pitch_sensor_is_active() const
    {
        if (!get_function_is_used())
            return false;

        if (_sensor_system_descriptor & 0b00000100)
            return true;
        else
            return false;
    }

    /**
     * @brief Evaluate if the heave sensor is active using sensor system descriptor field.
     * 0bxxxx1xxx : heave is active
     * 0bxxxx0xxx : heave is inactive
     *
     * @return bool
     *
     */
    bool get_heave_sensor_is_active() const
    {
        if (!get_function_is_used())
            return false;

        if (_sensor_system_descriptor & 0b00001000)
            return true;
        else
            return false;
    }

    /**
     * @brief Evaluate if the function is used.
     * -1 : function is not used
     *
     * @return bool
     *
     */
    bool get_function_is_used() const
    {
        if (_sensor_system_descriptor == -1)
            return false;
        else
            return true;
    }

    // ----- operators -----
    bool operator==(const NetworkAttitudeVelocityDatagram& other) const
    {
        return EM3000Datagram::operator==(other) &&
               _network_attitude_counter == other._network_attitude_counter &&
               _system_serial_number == other._system_serial_number &&
               _number_of_entries == other._number_of_entries &&
               _sensor_system_descriptor == other._sensor_system_descriptor && _etx == other._etx &&
               _checksum == other._checksum && _attitudes == other._attitudes;
    }
    bool operator!=(const NetworkAttitudeVelocityDatagram& other) const
    {
        return !operator==(other);
    }

    //----- to/from stream functions -----
    static NetworkAttitudeVelocityDatagram from_stream(std::istream& is, EM3000Datagram header)
    {
        auto start_pos = is.tellg();

        NetworkAttitudeVelocityDatagram datagram(std::move(header));

        if (datagram._datagram_identifier !=
            t_EM3000DatagramIdentifier::NetworkAttitudeVelocityDatagram)
            throw std::runtime_error(
                fmt::format("NetworkAttitudeVelocityDatagram: datagram identifier is not 0x{:02x}, "
                            "but 0x{:02x}",
                            uint8_t(t_EM3000DatagramIdentifier::NetworkAttitudeVelocityDatagram),
                            uint8_t(datagram._datagram_identifier)));

        // read first part of the datagram (until the first beam)
        is.read(reinterpret_cast<char*>(&(datagram._network_attitude_counter)),
                8 * sizeof(uint8_t));

        // read the attitude entries
        datagram._attitudes.reserve(datagram._number_of_entries);
        for (size_t i = 0; i < datagram._number_of_entries; ++i)
        {
            datagram._attitudes.emplace_back(
                substructures::NetworkAttitudeVelocityDatagramAttitude::from_stream(is));
        }

        // check if alignment is necessary
        // if pos difference is even, read the _spar_align field
        if ((is.tellg() - start_pos) % 2 != 1)
            is.read(reinterpret_cast<char*>(&(datagram._spare_align)), 4 * sizeof(uint8_t));

        else
        {
            is.read(reinterpret_cast<char*>(&(datagram._etx)), 3 * sizeof(uint8_t));
            // is.read(reinterpret_cast<char*>(&(datagram._etx)), sizeof(uint8_t));
            // is.read(reinterpret_cast<char*>(&(datagram._checksum)), sizeof(uint16_t));
        }

        if (datagram._etx != 0x03)
            throw std::runtime_error(fmt::format(
                "NetworkAttitudeVelocityDatagram: end identifier is not 0x03, but 0x{:x}",
                datagram._etx));

        return datagram;
    }

    static NetworkAttitudeVelocityDatagram from_stream(std::istream& is)
    {
        return from_stream(is, EM3000Datagram::from_stream(is));
    }

    static NetworkAttitudeVelocityDatagram from_stream(
        std::istream&              is,
        t_EM3000DatagramIdentifier datagram_identifier)
    {
        return from_stream(is, std::move(EM3000Datagram::from_stream(is, datagram_identifier)));
    }

    void to_stream(std::ostream& os)
    {
        auto start_pos = os.tellp();

        EM3000Datagram::to_stream(os);
        _number_of_entries = _attitudes.size();

        // write first part of the datagram (until the first beam)
        os.write(reinterpret_cast<const char*>(&(_network_attitude_counter)), 8 * sizeof(uint8_t));

        // write the attitude entries
        for (auto& attitude : _attitudes)
            attitude.to_stream(os);

        // check if alignment is necessary
        // if pos difference is even, write the _spar_align field (0)
        if ((os.tellp() - start_pos) % 2 != 1)
            os.write(reinterpret_cast<const char*>(&(_spare_align)), 4 * sizeof(uint8_t));

        else
        {
            os.write(reinterpret_cast<const char*>(&(_etx)), sizeof(uint8_t));
            os.write(reinterpret_cast<const char*>(&(_checksum)), sizeof(uint16_t));
        }
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("NetworkAttitudeVelocityDatagram",
                                                  float_precision);

        printer.append(EM3000Datagram::__printer__(float_precision));
        printer.register_section("datagram content");
        printer.register_value("network_attitude_counter", _network_attitude_counter);
        printer.register_value("system_serial_number", _system_serial_number);
        printer.register_value("number_of_entries", _number_of_entries);
        printer.register_string("sensor_system_descriptor",
                                fmt::format("0b{:08b}", _sensor_system_descriptor));
        printer.register_value("spare", _spare);
        printer.register_value("spare_align", _spare_align);
        printer.register_string("etx", fmt::format("0x{:02x}", _etx));
        printer.register_value("checksum", _checksum);

        printer.register_section("processed");
        printer.register_value(
            "attitude_velocity_sensor_number", get_attitude_velocity_sensor_number(), "1,2");
        printer.register_value("velocity_sensor_is_active", get_velocity_sensor_is_active());
        printer.register_value("heading_sensor_is_active", get_heading_sensor_is_active());
        printer.register_value("roll_sensor_is_active", get_roll_sensor_is_active());
        printer.register_value("pitch_sensor_is_active", get_pitch_sensor_is_active());
        printer.register_value("heave_sensor_is_active", get_heave_sensor_is_active());
        printer.register_value("function_is_used", get_function_is_used());

        printer.register_section("substructures");
        printer.register_value(
            "attitudes", _attitudes.size(), "NetworkAttitudeVelocityDatagramAttitude");

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(NetworkAttitudeVelocityDatagram)
};

} // namespace datagrams
} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping
