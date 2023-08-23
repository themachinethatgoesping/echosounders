// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/em3000datagram.doc.hpp"

// std includes
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/classhelper/stream.hpp>
#include <themachinethatgoesping/tools/timeconv.hpp>

#include "../em3000_types.hpp"
// #include "../misc/DateTime.h"
// #include "DSMToolsLib/HelperFunctions.h"

namespace themachinethatgoesping {
namespace echosounders {
namespace em3000 {
namespace datagrams {

class EM3000Datagram
{
  public:
    using t_DatagramIdentifier = t_EM3000DatagramIdentifier;

  protected:
    uint32_t _bytes; ///< number of bytes in the datagram (not including the _bytes field itself)
    uint8_t  _stx = 0x02;                      ///< (start identifier)
    t_DatagramIdentifier _datagram_identifier; ///< EM3000 datagram identifier
    uint16_t             _model_number;        ///< EM3000 model number (example: EM 3002 = 3002)
    uint32_t             _date; ///< year*1000 + month*100 + day(Example:Jun 27, 2020 = 20200627)
    uint32_t             _time_since_midnight; // in milliseconds

  protected:
    /**
     * @brief verify the datagram is read correctly by reading the ETX (end identifier) field and
     * the checksum at the end of the datagram Note: the checksum is not verified. (describes sum of
     * bytes between STX and ETX)
     *
     * @param is istream. Must be at the end position of the datagram header. Pos will be
     * incremented by 3 bytes (ETX and checksum).
     */
    void _verify_datagram_end(std::istream& is) const
    {
        // read the end identifier and the check sum
        struct t_EndIdentifier
        {
            uint8_t  etx;          // (end identifier)
            uint16_t checksum = 0; // the sum of all bytes between STX end ETX
        } etx;

        is.read(reinterpret_cast<char*>(&etx.etx), 3 * sizeof(uint8_t));

        if (etx.etx != 0x03)
            throw std::runtime_error(
                fmt::format("EM3000Datagram: end identifier is not 0x03, but 0x{:x}", etx.etx));
    }

  public:
    EM3000Datagram(uint32_t             bytes,
                   t_DatagramIdentifier datagram_identifier = t_DatagramIdentifier::unspecified,
                   uint16_t             model_number        = 0,
                   uint16_t             date                = 0,
                   uint16_t             time_since_midnight = 0)
        : _bytes(bytes)
        , _datagram_identifier(datagram_identifier)
        , _model_number(model_number)
        , _date(date)
        , _time_since_midnight(time_since_midnight)
    {
    }
    EM3000Datagram()          = default;
    virtual ~EM3000Datagram() = default;

    void skip(std::istream& is) const
    {
        // _bytes describes the number of bytes in the datagram, except the bytes field (4 bytes)
        // skip is called after from_stream so 12 bytes after the bytes field are read already
        // we want to jump to the end identifier (0x03) so we need to skip _Bytes - 12 - 3 - bytes
        const static uint8_t tmp = sizeof(uint8_t) * (15);

        is.seekg(_bytes - tmp, std::ios::cur);

        // verify the datagram is read correctly by reading the length field at the end
        _verify_datagram_end(is);
    }

    // ----- convenient member access -----
    uint32_t             get_bytes() const { return _bytes; }
    uint8_t              get_stx() const { return _stx; }
    t_DatagramIdentifier get_datagram_identifier() const { return _datagram_identifier; }
    uint16_t             get_model_number() const { return _model_number; }
    uint32_t             get_date() const { return _date; }
    uint32_t             get_time_since_midnight() const { return _time_since_midnight; }

    void set_bytes(uint32_t bytes) { _bytes = bytes; }
    void set_stx(uint8_t stx) { _stx = stx; }
    void set_datagram_identifier(t_DatagramIdentifier datagram_identifier)
    {
        _datagram_identifier = datagram_identifier;
    }
    void set_model_number(uint16_t model_number) { _model_number = model_number; }
    void set_date(uint32_t date) { _date = date; }
    void set_time_since_midnight(uint32_t time_since_midnight)
    {
        _time_since_midnight = time_since_midnight;
    }

    // ----- processed member access -----
    /**
     * @brief convert the date and time_since_midnight field to a unix timestamp
     *
     * @return unixtime as double
     */
    double get_timestamp() const
    {
        int y = int(_date / 10000);
        int m = int(_date / 100) - y * 100;
        int d = int(_date) - y * 10000 - m * 100;

        return tools::timeconv::year_month_day_to_unixtime(
            y, m, d, uint64_t(_time_since_midnight) * 1000);
    }

    /**
     * @brief Get the time as string
     *
     * @param fractionalSecondsDigits
     * @param format
     * @return std::string
     */
    std::string get_date_string(unsigned int       fractionalSecondsDigits = 2,
                                const std::string& format = "%z__%d-%m-%Y__%H:%M:%S") const
    {
        return tools::timeconv::unixtime_to_datestring(
            get_timestamp(), fractionalSecondsDigits, format);
    }

    // ----- operators -----
    bool operator==(const EM3000Datagram& other) const = default;

    static EM3000Datagram from_stream(std::istream& is)
    {
        EM3000Datagram d;
        is.read(reinterpret_cast<char*>(&d._bytes), 16 * sizeof(uint8_t));

        if (d._stx != 0x02)
            throw std::runtime_error(
                fmt::format("EM3000Datagram: start identifier is not 0x02, but 0x{:x}", d._stx));

        return d;
    }

    static EM3000Datagram from_stream(std::istream&              is,
                                      t_EM3000DatagramIdentifier datagram_identifier)
    {
        EM3000Datagram d = from_stream(is);

        if (d.get_datagram_identifier() != datagram_identifier)
            throw std::runtime_error(fmt::format("EM3000Datagram: Datagram identifier mismatch!"));

        return d;
    }

    void to_stream(std::ostream& os) const
    {
        os.write(reinterpret_cast<const char*>(&_bytes), 16 * sizeof(uint8_t));
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        using tools::timeconv::unixtime_to_datestring;

        static const std::string format_date("%d/%m/%Y");
        static const std::string format_time("%H:%M:%S");
        auto                     timestamp = get_timestamp();

        auto date = unixtime_to_datestring(timestamp, 0, format_date);
        auto time = unixtime_to_datestring(timestamp, 3, format_time);

        tools::classhelper::ObjectPrinter printer("EM3000Datagram", float_precision);

        printer.register_value("bytes", _bytes);
        printer.register_string("stx", fmt::format("0x{:02x}", _stx));
        printer.register_string(
            "datagram_identifier",
            fmt::format("0x{:02x}", uint8_t(_datagram_identifier)),
            datagram_identifier_to_string(t_EM3000DatagramIdentifier(_datagram_identifier)));
        printer.register_string("model_number", "EM" + std::to_string(_model_number));
        printer.register_value("date", _date, "YYYYMMDD");
        printer.register_value("time_since_midnight", _time_since_midnight, "ms");

        printer.register_section("date/time");
        printer.register_value("timestamp", timestamp, "s");
        printer.register_string("date", date, "MM/DD/YYYY");
        printer.register_string("time", time, "HH:MM:SS");

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(EM3000Datagram)
};

} // namespace datagrams
} // namespace em3000
} // namespace echosounders
} // namespace themachinethatgoesping
