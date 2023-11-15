// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/attitudedatagram.doc.hpp"

// std includes
#include <string>
#include <vector>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../kongsbergall_types.hpp"
#include "kongsbergalldatagram.hpp"

#include "substructures/attitudedatagramattitude.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

/**
 * @brief This datagram is used for the models EM 2040, EM 2040C, EM 710, EM 122, EM
302 and ME70BO. All receiver beams are included, check detection info and real time
cleaning for beam status (note 4 and 5).
 */
class AttitudeDatagram : public KongsbergAllDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_KongsbergAllDatagramIdentifier::AttitudeDatagram;

  protected:
    uint16_t _attitude_counter;
    uint16_t _system_serial_number;
    uint16_t _number_of_entries; ///< N

    // Number_of_entries x Attitude
    std::vector<substructures::AttitudeDatagramAttitude> _attitudes; ///< N x Attitude data

    uint8_t  _sensor_system_descriptor;
    uint8_t  _etx = 0x03; ///< end identifier (always 0x03)
    uint16_t _checksum;

  private:
    // ----- private constructors -----
    explicit AttitudeDatagram(KongsbergAllDatagram header)
        : KongsbergAllDatagram(std::move(header))
    {
    }

  public:
    // ----- public constructors -----
    AttitudeDatagram() { _datagram_identifier = t_KongsbergAllDatagramIdentifier::AttitudeDatagram; }
    ~AttitudeDatagram() = default;

    // ----- convenient data access -----
    // getters
    uint16_t get_attitude_counter() const { return _attitude_counter; }
    uint16_t get_system_serial_number() const { return _system_serial_number; }
    uint16_t get_number_of_entries() const { return _number_of_entries; }
    uint8_t  get_sensor_system_descriptor() const { return _sensor_system_descriptor; }
    uint8_t  get_etx() const { return _etx; }
    uint16_t get_checksum() const { return _checksum; }

    // setters
    void set_attitude_counter(uint16_t attitude_counter) { _attitude_counter = attitude_counter; }
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

    // substructures
    std::vector<substructures::AttitudeDatagramAttitude>&       attitudes() { return _attitudes; }
    const std::vector<substructures::AttitudeDatagramAttitude>& get_attitudes() const
    {
        return _attitudes;
    }
    void set_attitudes(std::vector<substructures::AttitudeDatagramAttitude> attitudes)
    {
        _attitudes = std::move(attitudes);
    }

    // ----- processed data access -----
    /**
     * @brief Get the number of attitude sensor from the sensor system descriptor field.
     * xx00 xxxx – attitude sensor number 1
     * xx01 xxxx – attitude sensor number 2
     *
     * @return 1 or 2
     *
     */
    int get_attitude_sensor_number() const
    {
        if (_sensor_system_descriptor & 0b00110000)
            return 2;
        else
            return 1;
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
        if (_sensor_system_descriptor & 0b00001000)
            return true;
        else
            return false;
    }

    // ----- operators -----
    bool operator==(const AttitudeDatagram& other) const = default;

    //----- to/from stream functions -----
    static AttitudeDatagram from_stream(std::istream& is, KongsbergAllDatagram header)
    {
        AttitudeDatagram datagram(std::move(header));

        if (datagram._datagram_identifier != t_KongsbergAllDatagramIdentifier::AttitudeDatagram)
            throw std::runtime_error(
                fmt::format("AttitudeDatagram: datagram identifier is not 0x{:02x}, but 0x{:02x}",
                            uint8_t(t_KongsbergAllDatagramIdentifier::AttitudeDatagram),
                            uint8_t(datagram._datagram_identifier)));

        // read first part of the datagram (until the first beam)
        is.read(reinterpret_cast<char*>(&(datagram._attitude_counter)), 6 * sizeof(uint8_t));

        // read the attitude data
        datagram._attitudes.resize(datagram._number_of_entries);
        is.read(reinterpret_cast<char*>(datagram._attitudes.data()),
                datagram._number_of_entries * sizeof(substructures::AttitudeDatagramAttitude));

        // read the rest of the datagram
        is.read(reinterpret_cast<char*>(&(datagram._sensor_system_descriptor)),
                4 * sizeof(uint8_t));

        if (datagram._etx != 0x03)
            throw std::runtime_error(fmt::format(
                "AttitudeDatagram: end identifier is not 0x03, but 0x{:x}", datagram._etx));

        return datagram;
    }

    static AttitudeDatagram from_stream(std::istream& is)
    {
        return from_stream(is, KongsbergAllDatagram::from_stream(is));
    }

    static AttitudeDatagram from_stream(std::istream&              is,
                                        t_KongsbergAllDatagramIdentifier datagram_identifier)
    {
        return from_stream(is, KongsbergAllDatagram::from_stream(is, datagram_identifier));
    }

    void to_stream(std::ostream& os)
    {
        KongsbergAllDatagram::to_stream(os);
        _number_of_entries = _attitudes.size();

        // write first part of the datagram (until the first beam)
        os.write(reinterpret_cast<const char*>(&(_attitude_counter)), 6 * sizeof(uint8_t));

        // write the beams
        os.write(reinterpret_cast<const char*>(_attitudes.data()),
                 _number_of_entries * sizeof(substructures::AttitudeDatagramAttitude));

        // write the rest of the datagram
        os.write(reinterpret_cast<const char*>(&(_sensor_system_descriptor)), 4 * sizeof(uint8_t));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("AttitudeDatagram", float_precision);

        printer.append(KongsbergAllDatagram::__printer__(float_precision));
        printer.register_section("datagram content");
        printer.register_value("attitude_counter", _attitude_counter);
        printer.register_value("system_serial_number", _system_serial_number);
        printer.register_value("number_of_entries", _number_of_entries);
        printer.register_string("sensor_system_descriptor",
                                fmt::format("0b{:08b}", _sensor_system_descriptor));
        printer.register_string("etx", fmt::format("0x{:02x}", _etx));
        printer.register_value("checksum", _checksum);

        printer.register_section("processed");
        printer.register_value("attitude_sensor_number", get_attitude_sensor_number(), "1,2");
        printer.register_value("heading_sensor_is_active", get_heading_sensor_is_active());
        printer.register_value("roll_sensor_is_active", get_roll_sensor_is_active());
        printer.register_value("pitch_sensor_is_active", get_pitch_sensor_is_active());
        printer.register_value("heave_sensor_is_active", get_heave_sensor_is_active());

        printer.register_section("substructures");
        printer.register_value("attitudes", _attitudes.size(), "AttitudeDatagramAttitude");

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(AttitudeDatagram)
};

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
