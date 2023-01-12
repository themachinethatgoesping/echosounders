// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/watercolumndatagram.doc.hpp"

// std includes
#include <string>
#include <vector>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../em3000_types.hpp"
#include "em3000datagram.hpp"

#include "substructures/watercolumndatagrambeam.hpp"
#include "substructures/watercolumndatagramtransmitsector.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace datagrams {

/**
 * @brief Used for EM 122, EM 302, EM 710, EM 2040, EM 3002.
 * The receiver beams are roll stabilized.
 */
class WaterColumnDatagram : public EM3000Datagram
{
  protected:
    uint16_t               _ping_counter;
    uint16_t               _system_serial_number;
    uint16_t               _number_of_datagrams;
    uint16_t               _datagram_number;
    uint16_t               _number_of_transmit_sectors; ///< Transmit_sector vector of 2 elements
    uint16_t               _total_no_of_receive_beams;
    uint16_t               _number_of_beams_in_datagram; ///< Beam vector of 2 elements
    uint16_t               _sound_speed;                 ///< in 0.1 m/s
    uint32_t               _sampling_frequency;          //// in 0.01 Hz resolution
    int16_t                _tx_time_heave;               ///< in cm
    uint8_t                _tvg_function_applied;
    int8_t                 _tvg_offset_in_db;
    uint8_t                _scanning_info;
    std::array<uint8_t, 3> _spare;
    std::vector<substructures::WaterColumnDatagramTransmitSector> _transmit_sectors;
    std::vector<substructures::WaterColumnDatagramBeam>           _beams;

    uint8_t  _spare_byte = 0;
    uint8_t  _etx        = 0x03; ///< end identifier (always 0x03)
    uint16_t _checksum;

  private:
    // ----- private constructors -----
    explicit WaterColumnDatagram(EM3000Datagram header)
        : EM3000Datagram(std::move(header))
    {
    }

  public:
    // ----- public constructors -----
    WaterColumnDatagram()
    {
        _datagram_identifier = t_EM3000DatagramIdentifier::WaterColumnDatagram;
    }
    ~WaterColumnDatagram() = default;

    // ----- convenient data access -----
    // getters
    uint16_t get_ping_counter() const { return _ping_counter; }
    uint16_t get_system_serial_number() const { return _system_serial_number; }
    uint16_t get_number_of_datagrams() const { return _number_of_datagrams; }
    uint16_t get_datagram_number() const { return _datagram_number; }
    uint16_t get_number_of_transmit_sectors() const { return _number_of_transmit_sectors; }
    uint16_t get_total_no_of_receive_beams() const { return _total_no_of_receive_beams; }
    uint16_t get_number_of_beams_in_datagram() const { return _number_of_beams_in_datagram; }
    uint16_t get_sound_speed() const { return _sound_speed; }
    uint32_t get_sampling_frequency() const { return _sampling_frequency; }
    int16_t  get_tx_time_heave() const { return _tx_time_heave; }
    uint8_t  get_tvg_function_applied() const { return _tvg_function_applied; }
    int8_t   get_tvg_offset_in_db() const { return _tvg_offset_in_db; }
    uint8_t  get_scanning_info() const { return _scanning_info; }
    std::array<uint8_t, 3> get_spare() const { return _spare; }
    uint8_t                get_spare_byte() const { return _spare_byte; }
    uint8_t                get_etx() const { return _etx; }
    uint16_t               get_checksum() const { return _checksum; }

    // setters
    void set_ping_counter(uint16_t ping_counter) { _ping_counter = ping_counter; }
    void set_system_serial_number(uint16_t system_serial_number)
    {
        _system_serial_number = system_serial_number;
    }
    void set_number_of_datagrams(uint16_t number_of_datagrams)
    {
        _number_of_datagrams = number_of_datagrams;
    }
    void set_datagram_number(uint16_t datagram_number) { _datagram_number = datagram_number; }
    void set_number_of_transmit_sectors(uint16_t number_of_transmit_sectors)
    {
        _number_of_transmit_sectors = number_of_transmit_sectors;
    }
    void set_total_no_of_receive_beams(uint16_t total_no_of_receive_beams)
    {
        _total_no_of_receive_beams = total_no_of_receive_beams;
    }
    void set_number_of_beams_in_datagram(uint16_t number_of_beams_in_datagram)
    {
        _number_of_beams_in_datagram = number_of_beams_in_datagram;
    }
    void set_sound_speed(uint16_t sound_speed) { _sound_speed = sound_speed; }
    void set_sampling_frequency(uint32_t sampling_frequency)
    {
        _sampling_frequency = sampling_frequency;
    }
    void set_tx_time_heave(int16_t tx_time_heave) { _tx_time_heave = tx_time_heave; }
    void set_tvg_function_applied(uint8_t tvg_function_applied)
    {
        _tvg_function_applied = tvg_function_applied;
    }
    void set_tvg_offset_in_db(int8_t tvg_offset_in_db) { _tvg_offset_in_db = tvg_offset_in_db; }
    void set_scanning_info(uint8_t scanning_info) { _scanning_info = scanning_info; }
    void set_spare(std::array<uint8_t, 3> spare) { _spare = spare; }

    void set_spare_byte(uint8_t spare_byte) { _spare_byte = spare_byte; }
    void set_etx(uint8_t etx) { _etx = etx; }
    void set_checksum(uint16_t checksum) { _checksum = checksum; }

    // ----- substructure access -----
    const std::vector<substructures::WaterColumnDatagramTransmitSector>& get_transmit_sectors()
        const
    {
        return _transmit_sectors;
    }
    std::vector<substructures::WaterColumnDatagramTransmitSector>& transmit_sectors()
    {
        return _transmit_sectors;
    }
    void set_transmit_sectors(
        std::vector<substructures::WaterColumnDatagramTransmitSector> transmit_sectors)
    {
        _transmit_sectors = transmit_sectors;
    }

    const std::vector<substructures::WaterColumnDatagramBeam>& get_beams() const { return _beams; }
    std::vector<substructures::WaterColumnDatagramBeam>&       beams() { return _beams; }
    void set_beams(std::vector<substructures::WaterColumnDatagramBeam> beams) { _beams = beams; }

    // ----- processed data access -----
    /**
     * @brief Get the sound speed in m/s
     *
     * @return _sound_speed * 0.1 m/s (float)
     */
    float get_sound_speed_m_s() const { return _sound_speed * 0.1f; }

    /**
     * @brief Get the sampling frequency in Hz
     *
     * @return _sampling_frequency * 0.01 Hz (float)
     */
    float get_sampling_frequency_in_hz() const { return _sampling_frequency * 0.01f; }

    /**
     * @brief Get the transmit time heave in m
     *
     * @return _tx_time_heave * 0.01 m (float)
     */
    float get_tx_time_heave_in_m() const { return _tx_time_heave * 0.01f; }

    // ----- operators -----
    bool operator==(const WaterColumnDatagram& other) const
    {
        return _ping_counter == other._ping_counter &&
               _system_serial_number == other._system_serial_number &&
               _number_of_datagrams == other._number_of_datagrams &&
               _datagram_number == other._datagram_number &&
               _number_of_transmit_sectors == other._number_of_transmit_sectors &&
               _total_no_of_receive_beams == other._total_no_of_receive_beams &&
               _number_of_beams_in_datagram == other._number_of_beams_in_datagram &&
               _sound_speed == other._sound_speed &&
               _sampling_frequency == other._sampling_frequency &&
               _tx_time_heave == other._tx_time_heave &&
               _tvg_function_applied == other._tvg_function_applied &&
               _tvg_offset_in_db == other._tvg_offset_in_db &&
               _scanning_info == other._scanning_info && _spare == other._spare &&
               _transmit_sectors == other._transmit_sectors && _beams == other._beams &&
               _spare_byte == other._spare_byte && _etx == other._etx &&
               _checksum == other._checksum && true;
    }
    bool operator!=(const WaterColumnDatagram& other) const { return !operator==(other); }

    //----- to/from stream functions -----
    static WaterColumnDatagram from_stream(std::istream& is, EM3000Datagram header)
    {
        WaterColumnDatagram datagram(std::move(header));

        if (datagram._datagram_identifier != t_EM3000DatagramIdentifier::WaterColumnDatagram)
            throw std::runtime_error(fmt::format(
                "WaterColumnDatagram: datagram identifier is not 0x{:02x}, but 0x{:02x}",
                uint8_t(t_EM3000DatagramIdentifier::WaterColumnDatagram),
                uint8_t(datagram._datagram_identifier)));

        // read first part of the datagram (until the first beam)
        is.read(reinterpret_cast<char*>(&(datagram._ping_counter)), 28 * sizeof(uint8_t));

        // read the transmit_sectors
        datagram._transmit_sectors.resize(datagram._number_of_transmit_sectors);
        is.read(reinterpret_cast<char*>(datagram._transmit_sectors.data()),
                datagram._number_of_transmit_sectors *
                    sizeof(substructures::WaterColumnDatagramTransmitSector));

        // read the beams
        datagram._beams.reserve(datagram._number_of_beams_in_datagram);
        for (auto i = 0; i < datagram._number_of_beams_in_datagram; ++i)
            datagram._beams.emplace_back(substructures::WaterColumnDatagramBeam::from_stream(is));

        // read the rest of the datagram
        is.read(reinterpret_cast<char*>(&(datagram._spare_byte)), 4 * sizeof(uint8_t));

        if (datagram._etx != 0x03)
            throw std::runtime_error(fmt::format(
                "WaterColumnDatagram: end identifier is not 0x03, but 0x{:x}", datagram._etx));

        return datagram;
    }

    static WaterColumnDatagram from_stream(std::istream& is)
    {
        return from_stream(is, EM3000Datagram::from_stream(is));
    }

    static WaterColumnDatagram from_stream(std::istream&              is,
                                           t_EM3000DatagramIdentifier datagram_identifier)
    {
        return from_stream(is, std::move(EM3000Datagram::from_stream(is, datagram_identifier)));
    }

    void to_stream(std::ostream& os)
    {
        EM3000Datagram::to_stream(os);
        _number_of_transmit_sectors  = _transmit_sectors.size();
        _number_of_beams_in_datagram = _beams.size();

        // write first part of the datagram (until the first beam)
        os.write(reinterpret_cast<const char*>(&(_ping_counter)), 28 * sizeof(uint8_t));

        // write the transmit sector
        os.write(reinterpret_cast<const char*>(_transmit_sectors.data()),
                 _number_of_transmit_sectors *
                     sizeof(substructures::WaterColumnDatagramTransmitSector));

        // write the beams
        for (auto beam : _beams)
            beam.to_stream(os);

        // write the rest of the datagram
        os.write(reinterpret_cast<const char*>(&(_spare_byte)), 4 * sizeof(uint8_t));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("WaterColumnDatagram", float_precision);

        printer.append(EM3000Datagram::__printer__(float_precision));
        printer.register_section("datagram content");
        printer.register_value("ping_counter", _ping_counter);
        printer.register_value("system_serial_number", _system_serial_number);
        printer.register_value("number_of_datagrams", _number_of_datagrams);
        printer.register_value("datagram_number", _datagram_number);
        printer.register_value("number_of_transmit_sectors", _number_of_transmit_sectors);
        printer.register_value("total_no_of_receive_beams", _total_no_of_receive_beams);
        printer.register_value("number_of_beams_in_datagram", _number_of_beams_in_datagram);
        printer.register_value("sound_speed", _sound_speed, "0.1 m/s");
        printer.register_value("sampling_frequency", _sampling_frequency, "0.01 Hz");
        printer.register_value("tx_time_heave", _tx_time_heave, "cm");
        printer.register_value("tvg_function_applied", _tvg_function_applied);
        printer.register_value("tvg_offset_in_db", _tvg_offset_in_db);
        printer.register_string("scanning_info", fmt::format("0b{:08b}", _scanning_info));
        printer.register_string("spare",
                                fmt::format("0x{:1x}{:1x}{:1x}", _spare[0], _spare[1], _spare[2]));
        printer.register_value("spare_byte", _spare_byte);

        printer.register_section("processed");
        printer.register_value("sound_speed", get_sound_speed_m_s(), "m/s");
        printer.register_value("sampling_frequency", get_sampling_frequency_in_hz(), "Hz");
        printer.register_value("tx_time_heave", get_tx_time_heave_in_m(), "m");

        printer.register_section("substructures");
        printer.register_value(
            "WaterColumnDatagramTransmitSector", _transmit_sectors.size(), "structures");
        printer.register_value("WaterColumnDatagramBeams", _beams.size(), "structures");

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(WaterColumnDatagram)
};

} // namespace datagrams
} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping
