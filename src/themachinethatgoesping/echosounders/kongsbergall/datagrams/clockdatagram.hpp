// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/clockdatagram.doc.hpp"

// std includes
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
 * @brief Clock datagrams
 */
class ClockDatagram : public KongsbergAllDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_KongsbergAllDatagramIdentifier::ClockDatagram;

  protected:
    uint16_t _clock_counter; ///< sequential number
    uint16_t _system_serial_number;
    uint32_t _date_external; ///< from external clock input year*1000 + month*100 + day(Example:Jun
                             ///< 27, 2020 = 20200627)
    uint32_t _time_since_midnight_external; ///< in ms from external clock datagram
    uint8_t _pps_active; ///< 0 = inactive (Shows if the system clock is synchronized to an external
                         ///< PPS signal or not)

    uint8_t  _etx = 0x03; ///< end identifier (always 0x03)
    uint16_t _checksum;

  private:
    // ----- private constructors -----
    explicit ClockDatagram(KongsbergAllDatagram header)
        : KongsbergAllDatagram(std::move(header))
    {
    }

  public:
    // ----- public constructors -----
    ClockDatagram() { _datagram_identifier = t_KongsbergAllDatagramIdentifier::ClockDatagram; }
    ~ClockDatagram() = default;

    // ----- convenient data access -----
    // getters
    uint16_t get_clock_counter() const { return _clock_counter; }
    uint16_t get_system_serial_number() const { return _system_serial_number; }
    uint32_t get_date_external() const { return _date_external; }
    uint32_t get_time_since_midnight_external() const { return _time_since_midnight_external; }
    uint8_t  get_pps_active() const { return _pps_active; }
    uint8_t  get_etx() const { return _etx; }
    uint16_t get_checksum() const { return _checksum; }

    // setters
    void set_clock_counter(uint16_t clock_counter) { _clock_counter = clock_counter; }
    void set_system_serial_number(uint16_t system_serial_number)
    {
        _system_serial_number = system_serial_number;
    }
    void set_date_external(uint32_t date_external) { _date_external = date_external; }
    void set_time_since_midnight_external(uint32_t time_since_midnight_external)
    {
        _time_since_midnight_external = time_since_midnight_external;
    }
    void set_pps_active(uint8_t pps_active) { _pps_active = pps_active; }
    void set_etx(uint8_t etx) { _etx = etx; }
    void set_checksum(uint16_t checksum) { _checksum = checksum; }

    // ----- processed data access -----
    /**
     * @brief convert the date and time_since_midnight field to a unix timestamp
     *
     * @return unixtime as double
     */
    double get_timestamp_external() const
    {
        int y = int(_date_external / 10000);
        int m = int(_date_external / 100) - y * 100;
        int d = int(_date_external) - y * 10000 - m * 100;

        return tools::timeconv::year_month_day_to_unixtime(
            y, m, d, uint64_t(_time_since_midnight_external) * 1000);
    }

    /**
     * @brief difference between timestamp and timestamp_external
     *
     * @return timestamp_external - timestamp
     */
    double get_timestamp_offset() const { return get_timestamp_external() - get_timestamp(); }

    std::string get_date_string_external_clock(
        unsigned int       fractionalSecondsDigits = 2,
        const std::string& format                  = "%z__%d-%m-%Y__%H:%M:%S") const
    {
        return tools::timeconv::unixtime_to_datestring(
            get_timestamp_external(), fractionalSecondsDigits, format);
    }

    // ----- operators -----
    bool operator==(const ClockDatagram& other) const = default;

    //----- to/from stream functions -----
    static ClockDatagram from_stream(std::istream& is, KongsbergAllDatagram header)
    {
        ClockDatagram datagram(std::move(header));

        if (datagram._datagram_identifier != t_KongsbergAllDatagramIdentifier::ClockDatagram)
            throw std::runtime_error(
                fmt::format("ClockDatagram: datagram identifier is not 0x{:02x}, but 0x{:02x}",
                            uint8_t(t_KongsbergAllDatagramIdentifier::ClockDatagram),
                            uint8_t(datagram._datagram_identifier)));

        // read first part of the datagram (until the first beam)
        is.read(reinterpret_cast<char*>(&(datagram._clock_counter)), 16 * sizeof(uint8_t));

        if (datagram._etx != 0x03)
            throw std::runtime_error(fmt::format(
                "ClockDatagram: end identifier is not 0x03, but 0x{:x}", datagram._etx));

        return datagram;
    }

    static ClockDatagram from_stream(std::istream& is)
    {
        return from_stream(is, KongsbergAllDatagram::from_stream(is));
    }

    static ClockDatagram from_stream(std::istream&              is,
                                     t_KongsbergAllDatagramIdentifier datagram_identifier)
    {
        return from_stream(is, KongsbergAllDatagram::from_stream(is, datagram_identifier));
    }

    void to_stream(std::ostream& os)
    {
        KongsbergAllDatagram::to_stream(os);

        // write first part of the datagram (until the first beam)
        os.write(reinterpret_cast<const char*>(&(_clock_counter)), 16 * sizeof(uint8_t));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer("ClockDatagram", float_precision, superscript_exponents);

        static const std::string format_date("%d/%m/%Y");
        static const std::string format_time("%H:%M:%S");
        auto                     timestamp_external = get_timestamp_external();

        using tools::timeconv::unixtime_to_datestring;
        auto date = unixtime_to_datestring(timestamp_external, 0, format_date);
        auto time = unixtime_to_datestring(timestamp_external, 3, format_time);

        printer.append(KongsbergAllDatagram::__printer__(float_precision, superscript_exponents));
        printer.register_section("datagram content");
        printer.register_value("clock_counter", _clock_counter);
        printer.register_value("system_serial_number", _system_serial_number);
        printer.register_value("date_external", _date_external, "YYYYMMDD");
        printer.register_value("time_since_midnight_external", _time_since_midnight_external, "ms");
        printer.register_value("pps_active", _pps_active);
        printer.register_string("etx", fmt::format("0x{:02x}", _etx));
        printer.register_value("checksum", _checksum);

        printer.register_section("External clock date/time");
        printer.register_value("timestamp", timestamp_external, "s");
        printer.register_string("date", date, "MM/DD/YYYY");
        printer.register_string("time", time, "HH:MM:SS");
        printer.register_value("timestamp_offset", (get_timestamp_offset()), "s");
        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(ClockDatagram)
};

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
