// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "clockdatagram.hpp"

#include <fmt/format.h>

#include <stdexcept>
#include <utility>

#include <themachinethatgoesping/tools/timeconv.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

ClockDatagram::ClockDatagram(KongsbergAllDatagram header)
    : KongsbergAllDatagram(std::move(header))
{
}

ClockDatagram::ClockDatagram()
{
    _datagram_identifier = t_KongsbergAllDatagramIdentifier::ClockDatagram;
}

uint16_t ClockDatagram::get_clock_counter() const
{
    return _clock_counter;
}

uint16_t ClockDatagram::get_system_serial_number() const
{
    return _system_serial_number;
}

uint32_t ClockDatagram::get_date_external() const
{
    return _date_external;
}

uint32_t ClockDatagram::get_time_since_midnight_external() const
{
    return _time_since_midnight_external;
}

uint8_t ClockDatagram::get_pps_active() const
{
    return _pps_active;
}

uint8_t ClockDatagram::get_etx() const
{
    return _etx;
}

uint16_t ClockDatagram::get_checksum() const
{
    return _checksum;
}

void ClockDatagram::set_clock_counter(uint16_t clock_counter)
{
    _clock_counter = clock_counter;
}

void ClockDatagram::set_system_serial_number(uint16_t system_serial_number)
{
    _system_serial_number = system_serial_number;
}

void ClockDatagram::set_date_external(uint32_t date_external)
{
    _date_external = date_external;
}

void ClockDatagram::set_time_since_midnight_external(uint32_t time_since_midnight_external)
{
    _time_since_midnight_external = time_since_midnight_external;
}

void ClockDatagram::set_pps_active(uint8_t pps_active)
{
    _pps_active = pps_active;
}

void ClockDatagram::set_etx(uint8_t etx)
{
    _etx = etx;
}

void ClockDatagram::set_checksum(uint16_t checksum)
{
    _checksum = checksum;
}

// ----- processed data access -----

double ClockDatagram::get_timestamp_external() const
{
    int y = int(_date_external / 10000);
    int m = int(_date_external / 100) - y * 100;
    int d = int(_date_external) - y * 10000 - m * 100;

    return tools::timeconv::year_month_day_to_unixtime(
        y, m, d, uint64_t(_time_since_midnight_external) * 1000);
}

std::string ClockDatagram::get_date_string_external_clock(
    unsigned int       fractionalSecondsDigits,
    const std::string& format) const
{
    return tools::timeconv::unixtime_to_datestring(
        get_timestamp_external(), fractionalSecondsDigits, format);
}

double ClockDatagram::get_timestamp_offset() const
{
	return get_timestamp_external() - get_timestamp();
}

// ----- to/from stream functions -----

ClockDatagram ClockDatagram::from_stream(std::istream& is, KongsbergAllDatagram header)
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

ClockDatagram ClockDatagram::from_stream(std::istream& is)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is));
}

ClockDatagram ClockDatagram::from_stream(std::istream&              is,
                                 t_KongsbergAllDatagramIdentifier datagram_identifier)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is, datagram_identifier));
}

void ClockDatagram::to_stream(std::ostream& os)
{
    KongsbergAllDatagram::to_stream(os);

    // write first part of the datagram (until the first beam)
    os.write(reinterpret_cast<const char*>(&(_clock_counter)), 16 * sizeof(uint8_t));
}

// ----- objectprinter -----

tools::classhelper::ObjectPrinter ClockDatagram::__printer__(unsigned int float_precision, bool superscript_exponents) const
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

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
