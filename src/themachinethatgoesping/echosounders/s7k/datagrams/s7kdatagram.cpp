// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "s7kdatagram.hpp"

/* std includes */
#include <fmt/format.h>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/timeconv.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

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
    printer.register_value_bytes("flags", _flags);
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
