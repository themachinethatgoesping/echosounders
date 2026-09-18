// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "s7kdatagram.hpp"

/* std includes */
#include <cstring>
#include <fmt/format.h>
#include <limits>
#include <stdexcept>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/timeconv.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

// ----- skip / interface -----
void S7KDatagram::skip(std::istream& is) const
{
    // _size describes the full record size (version field to end of checksum); __size bytes of
    // the DRF header have already been consumed by from_stream
    is.seekg(_size - __size, std::ios::cur);
}

void S7KDatagram::set_datagram_identifier(o_DatagramIdentifier datagram_identifier)
{
    _record_type_identifier = datagram_identifier;
}
S7KDatagram::o_DatagramIdentifier S7KDatagram::get_datagram_identifier() const
{
    return _record_type_identifier;
}

double S7KDatagram::get_timestamp() const
{
    // spec: if no time is available all 7KTIME fields are zero
    if (_year == 0)
        return std::numeric_limits<double>::quiet_NaN();

    // unix time at midnight (Jan 1) of the year + day-of-year offset + time of day
    const double midnight_jan1 = tools::timeconv::year_month_day_to_unixtime(int(_year), 1, 1);
    return midnight_jan1 + double(int(_day) - 1) * 86400.0 + double(_hours) * 3600.0 +
           double(_minutes) * 60.0 + double(_seconds);
}

std::string S7KDatagram::get_date_string(unsigned int       fractionalSecondsDigits,
                                         const std::string& format) const
{
    return tools::timeconv::unixtime_to_datestring(
        get_timestamp(), fractionalSecondsDigits, format);
}

// ----- convenient member access -----
uint16_t S7KDatagram::get_protocol_version() const
{
    return _protocol_version;
}
uint16_t S7KDatagram::get_offset() const
{
    return _offset;
}
uint32_t S7KDatagram::get_sync_pattern() const
{
    return _sync_pattern;
}
uint32_t S7KDatagram::get_size() const
{
    return _size;
}
uint32_t S7KDatagram::get_optional_data_offset() const
{
    return _optional_data_offset;
}
uint32_t S7KDatagram::get_optional_data_identifier() const
{
    return _optional_data_identifier;
}
uint16_t S7KDatagram::get_year() const
{
    return _year;
}
uint16_t S7KDatagram::get_day() const
{
    return _day;
}
float S7KDatagram::get_seconds() const
{
    return _seconds;
}
uint8_t S7KDatagram::get_hours() const
{
    return _hours;
}
uint8_t S7KDatagram::get_minutes() const
{
    return _minutes;
}
uint16_t S7KDatagram::get_record_version() const
{
    return _record_version;
}
uint32_t S7KDatagram::get_record_type_identifier() const
{
    return uint32_t(_record_type_identifier);
}
uint32_t S7KDatagram::get_device_identifier() const
{
    return _device_identifier;
}
uint16_t S7KDatagram::get_system_enumerator() const
{
    return _system_enumerator;
}
uint16_t S7KDatagram::get_flags() const
{
    return _flags;
}
uint32_t S7KDatagram::get_total_records_in_fragmented_data_record_set() const
{
    return _total_records_in_fragmented_data_record_set;
}
uint32_t S7KDatagram::get_fragment_number() const
{
    return _fragment_number;
}

void S7KDatagram::set_protocol_version(uint16_t v)
{
    _protocol_version = v;
}
void S7KDatagram::set_offset(uint16_t v)
{
    _offset = v;
}
void S7KDatagram::set_sync_pattern(uint32_t v)
{
    _sync_pattern = v;
}
void S7KDatagram::set_size(uint32_t v)
{
    _size = v;
}
void S7KDatagram::set_optional_data_offset(uint32_t v)
{
    _optional_data_offset = v;
}
void S7KDatagram::set_optional_data_identifier(uint32_t v)
{
    _optional_data_identifier = v;
}
void S7KDatagram::set_year(uint16_t v)
{
    _year = v;
}
void S7KDatagram::set_day(uint16_t v)
{
    _day = v;
}
void S7KDatagram::set_seconds(float v)
{
    _seconds = v;
}
void S7KDatagram::set_hours(uint8_t v)
{
    _hours = v;
}
void S7KDatagram::set_minutes(uint8_t v)
{
    _minutes = v;
}
void S7KDatagram::set_record_version(uint16_t v)
{
    _record_version = v;
}
void S7KDatagram::set_device_identifier(uint32_t v)
{
    _device_identifier = v;
}
void S7KDatagram::set_system_enumerator(uint16_t v)
{
    _system_enumerator = v;
}
void S7KDatagram::set_flags(uint16_t v)
{
    _flags = v;
}

// ----- processed -----
bool S7KDatagram::get_flag_checksum_is_valued() const
{
    return (_flags & 0b0000000000000001) != 0;
}
bool S7KDatagram::get_flag_data_live_or_recorded() const
{
    return (_flags & 0b1000000000000000) != 0;
}
bool S7KDatagram::drf_sync_pattern_is_valid() const
{
    return _sync_pattern == SYNC_PATTERN;
}

// ----- helper -----
size_t S7KDatagram::compute_size_content() const
{
    return _size - __size;
}

// ----- checksum (debugging only) -----
uint32_t S7KDatagram::compute_checksum(std::string_view buffer)
{
    uint32_t     checksum = 0;
    const size_t n        = buffer.size() > 4 ? buffer.size() - 4 : 0;
    for (size_t i = 0; i < n; ++i)
        checksum += static_cast<uint8_t>(buffer[i]);
    return checksum;
}

uint32_t S7KDatagram::read_checksum(std::string_view buffer)
{
    if (buffer.size() < 4)
        return 0;
    uint32_t checksum = 0;
    std::memcpy(&checksum, buffer.data() + buffer.size() - 4, sizeof(checksum));
    return checksum;
}

bool S7KDatagram::test_checksum_is_correct(std::string_view buffer)
{
    return compute_checksum(buffer) == read_checksum(buffer);
}

// ----- protected read / check helpers -----
void S7KDatagram::__s7kdatagram_read__(std::istream& is)
{
    // all DRF fields are naturally aligned in declaration order, thus the __size bytes can be
    // read directly into the contiguous member block starting at _protocol_version
    is.read(reinterpret_cast<char*>(&(_protocol_version)), __size);
}

void S7KDatagram::__check_datagram_identifier__(const o_DatagramIdentifier actual,
                                                const o_DatagramIdentifier expected)
{
    if (actual.value != expected.value)
        throw std::runtime_error(fmt::format(
            "S7KDatagram::__check_datagram_identifier__: datagram identifier is not "
            "{}, but {}",
            datagram_type_to_string(expected),
            datagram_type_to_string(actual)));
}

S7KDatagram S7KDatagram::from_stream(std::istream& is)
{
    S7KDatagram d;
    d.__s7kdatagram_read__(is);
    return d;
}

S7KDatagram S7KDatagram::from_stream(std::istream&                 is,
                                     const o_S7KDatagramIdentifier datagram_identifier)
{
    S7KDatagram d = from_stream(is);
    __check_datagram_identifier__(d._record_type_identifier, datagram_identifier);

    return d;
}

void S7KDatagram::to_stream(std::ostream& os) const
{
    os.write(reinterpret_cast<const char*>(&_protocol_version), __size);
}

tools::classhelper::ObjectPrinter S7KDatagram::__printer__(unsigned int float_precision,
                                                           bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "S7KDatagram", float_precision, superscript_exponents);

    printer.register_section("Header");
    printer.register_value("protocol_version", _protocol_version);
    printer.register_value("offset", _offset);
    printer.register_value("sync_pattern", fmt::format("0x{:08X}", _sync_pattern));
    printer.register_value("size", _size, "bytes");

    printer.register_value("optional_data_offset", _optional_data_offset, "bytes");
    printer.register_value("optional_data_identifier", _optional_data_identifier);

    printer.register_value("record_version", _record_version);
    printer.register_value("record_type_identifier",
                           uint32_t(_record_type_identifier),
                           datagram_type_to_string(_record_type_identifier));
    printer.register_value("device_identifier", _device_identifier);
    printer.register_value("system_enumerator", _system_enumerator);
    printer.register_value("flags", fmt::format("0x{:016b}", _flags));
    printer.register_value("total_records_in_fragmented_data_record_set",
                           _total_records_in_fragmented_data_record_set);
    printer.register_value("fragment_number", _fragment_number);

    // time processing (if time is provided)
    // printer.register_container("year, day, seconds, hours, minutes",
    //                            std::make_tuple<uint16_t, uint16_t, float, uint8_t, uint8_t>(
    //                                _year, _day, _seconds, _hours, _minutes));
    auto timestamp = get_timestamp();
    if (std::isfinite(timestamp))
    {
        static const std::string format_date("%d/%m/%Y");
        static const std::string format_time("%H:%M:%S");
        using tools::timeconv::unixtime_to_datestring;
        auto date = unixtime_to_datestring(timestamp, 0, format_date);
        auto time = unixtime_to_datestring(timestamp, 3, format_time);

        printer.register_section("date/time");
        printer.register_value("timestamp", timestamp, "s");
        printer.register_string("date", date, "DD/MM/YYYY");
        printer.register_string("time", time, "HH:MM:SS");
    }

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
