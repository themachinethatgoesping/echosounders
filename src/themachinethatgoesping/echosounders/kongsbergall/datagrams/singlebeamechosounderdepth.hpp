// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/singlebeamechosounderdepth.doc.hpp"

// std includes
#include <string>
#include <vector>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>


#include "../types.hpp"
#include "kongsbergalldatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

/**
 * @brief Single beam echo sounder depth datagram
 */
class SingleBeamEchoSounderDepth : public KongsbergAllDatagram
{
  public:
    static constexpr auto DatagramIdentifier =
        t_KongsbergAllDatagramIdentifier::SingleBeamEchoSounderDepth;

  protected:
    uint16_t _echo_sounder_counter; ///< Sequential Number
    uint16_t _system_serial_number;
    uint32_t _input_date; ///< year*10000 + month*100 + day (from input datagram if available)
    uint32_t _input_time_since_midnight; ///< time since midnight in milliseconds (from input
                                         ///< datagram if available)
    uint32_t _echo_sounder_depth;        ///< from waterline in cm
    char     _source_identifier;         ///< 'S', 'T', '1', '2' or '3'

    uint8_t  _etx = 0x03; ///< end identifier (always 0x03)
    uint16_t _checksum;

  private:
    // ----- private constructors -----
    explicit SingleBeamEchoSounderDepth(KongsbergAllDatagram header)
        : KongsbergAllDatagram(std::move(header))
    {
    }

  public:
    // ----- public constructors -----
    SingleBeamEchoSounderDepth()
    {
        _datagram_identifier = t_KongsbergAllDatagramIdentifier::SingleBeamEchoSounderDepth;
    }
    ~SingleBeamEchoSounderDepth() = default;

    // ----- convenient data access -----
    // getters
    uint16_t get_echo_sounder_counter() const { return _echo_sounder_counter; }
    uint16_t get_system_serial_number() const { return _system_serial_number; }
    uint32_t get_input_date() const { return _input_date; }
    uint32_t get_input_time_since_midnight() const { return _input_time_since_midnight; }
    uint32_t get_echo_sounder_depth() const { return _echo_sounder_depth; }
    char     get_source_identifier() const { return _source_identifier; }
    uint8_t  get_etx() const { return _etx; }
    uint16_t get_checksum() const { return _checksum; }

    // setters
    void set_echo_sounder_counter(uint16_t echo_sounder_counter)
    {
        _echo_sounder_counter = echo_sounder_counter;
    }
    void set_system_serial_number(uint16_t system_serial_number)
    {
        _system_serial_number = system_serial_number;
    }
    void set_input_date(uint32_t date) { _input_date = date; }
    void set_input_time_since_midnight(uint32_t time) { _input_time_since_midnight = time; }
    void set_echo_sounder_depth(uint32_t echo_sounder_depth)
    {
        _echo_sounder_depth = echo_sounder_depth;
    }
    void set_source_identifier(char source_identifier) { _source_identifier = source_identifier; }
    void set_etx(uint8_t etx) { _etx = etx; }
    void set_checksum(uint16_t checksum) { _checksum = checksum; }

    // ----- processed data access -----
    /**
     * @brief convert the date and time_since_midnight field to a unix timestamp
     *
     * @return unixtime as double
     */
    double get_input_timestamp() const
    {
        int y = int(_input_date / 10000);
        int m = int(_input_date / 100) - y * 100;
        int d = int(_input_date) - y * 10000 - m * 100;

        return tools::timeconv::year_month_day_to_unixtime(
            y, m, d, uint64_t(_input_time_since_midnight) * 1000);
    }

    /**
     * @brief Get the time as string
     *
     * @param fractionalSecondsDigits
     * @param format
     * @return std::string
     */
    std::string get_input_date_string(unsigned int       fractionalSecondsDigits = 2,
                                      const std::string& format = "%z__%d-%m-%Y__%H:%M:%S") const
    {
        return tools::timeconv::unixtime_to_datestring(
            get_input_timestamp(), fractionalSecondsDigits, format);
    }

    /**
     * @brief Get the echo sounder depth in meters
     *
     * @return _echo_sounder_depth * 0.01f (float)
     */
    float get_echo_sounder_depth_in_meters() const { return _echo_sounder_depth * 0.01f; }

    // ----- operators -----
    bool operator==(const SingleBeamEchoSounderDepth& other) const = default;

    //----- to/from stream functions -----
    static SingleBeamEchoSounderDepth from_stream(std::istream& is, KongsbergAllDatagram header)
    {
        SingleBeamEchoSounderDepth datagram(std::move(header));

        if (datagram._datagram_identifier != t_KongsbergAllDatagramIdentifier::SingleBeamEchoSounderDepth)
            throw std::runtime_error(fmt::format(
                "SingleBeamEchoSounderDepth: datagram identifier is not 0x{:02x}, but 0x{:02x}",
                uint8_t(t_KongsbergAllDatagramIdentifier::SingleBeamEchoSounderDepth),
                uint8_t(datagram._datagram_identifier)));

        // read first part of the datagram (until the first beam)
        is.read(reinterpret_cast<char*>(&(datagram._echo_sounder_counter)), 20 * sizeof(uint8_t));

        if (datagram._etx != 0x03)
            throw std::runtime_error(
                fmt::format("SingleBeamEchoSounderDepth: end identifier is not 0x03, but 0x{:x}",
                            datagram._etx));

        return datagram;
    }

    static SingleBeamEchoSounderDepth from_stream(std::istream& is)
    {
        return from_stream(is, KongsbergAllDatagram::from_stream(is));
    }

    static SingleBeamEchoSounderDepth from_stream(std::istream&              is,
                                                  t_KongsbergAllDatagramIdentifier datagram_identifier)
    {
        return from_stream(is, KongsbergAllDatagram::from_stream(is, datagram_identifier));
    }

    void to_stream(std::ostream& os)
    {
        KongsbergAllDatagram::to_stream(os);

        // write first part of the datagram (until the first beam)
        os.write(reinterpret_cast<const char*>(&(_echo_sounder_counter)), 20 * sizeof(uint8_t));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const
    {
        using tools::timeconv::unixtime_to_datestring;

        static const std::string format_date("%d/%m/%Y");
        static const std::string format_time("%H:%M:%S");
        auto                     timestamp = get_input_timestamp();

        auto date = unixtime_to_datestring(timestamp, 0, format_date);
        auto time = unixtime_to_datestring(timestamp, 3, format_time);

        tools::classhelper::ObjectPrinter printer("SingleBeamEchoSounderDepth", float_precision, superscript_exponents);

        printer.append(KongsbergAllDatagram::__printer__(float_precision, superscript_exponents));
        printer.register_section("datagram content");
        printer.register_value("echo_sounder_counter", _echo_sounder_counter);
        printer.register_value("system_serial_number", _system_serial_number);
        printer.register_value("input_date", _input_date, "YYYYMMDD");
        printer.register_value("input_time_since_midnight", _input_time_since_midnight, "ms");
        printer.register_value("echo_sounder_depth", _echo_sounder_depth, "m");

        printer.register_string("etx", fmt::format("0x{:02x}", _etx));
        printer.register_value("checksum", _checksum);

        printer.register_section("processed");
        printer.register_value("input_timestamp", timestamp, "s");
        printer.register_string("input_date", date, "MM/DD/YYYY");
        printer.register_string("input_time", time, "HH:MM:SS");
        printer.register_value("echo_sounder_depth", get_echo_sounder_depth_in_meters(), "m");
        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST__(SingleBeamEchoSounderDepth)
};

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
