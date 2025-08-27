// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "kongsbergalldatagram.hpp"

/* std includes */
#include <fmt/core.h>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/timeconv.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

KongsbergAllDatagram KongsbergAllDatagram::from_stream(std::istream& is)
{
    KongsbergAllDatagram d;
    is.read(reinterpret_cast<char*>(&d._bytes), 16 * sizeof(uint8_t));

    if (d._stx != 0x02)
        throw std::runtime_error(fmt::format(
            "KongsbergAllDatagram: start identifier is not 0x02, but 0x{:x}", d._stx));

    return d;
}

KongsbergAllDatagram KongsbergAllDatagram::from_stream(std::istream&                    is,
                                                      t_KongsbergAllDatagramIdentifier datagram_identifier)
{
    KongsbergAllDatagram d = from_stream(is);

    if (d.get_datagram_identifier() != datagram_identifier)
        throw std::runtime_error(
            fmt::format("KongsbergAllDatagram::skip_and_verify_header: datagram "
                        "identifier is not {}, but {}",
                        datagram_type_to_string(datagram_identifier),
                        datagram_type_to_string(d.get_datagram_identifier())));

    return d;
}

void KongsbergAllDatagram::to_stream(std::ostream& os) const
{
    os.write(reinterpret_cast<const char*>(&_bytes), 16 * sizeof(uint8_t));
}

tools::classhelper::ObjectPrinter KongsbergAllDatagram::__printer__(unsigned int float_precision,
                                                                   bool         superscript_exponents) const
{
    using tools::timeconv::unixtime_to_datestring;

    static const std::string format_date("%d/%m/%Y");
    static const std::string format_time("%H:%M:%S");
    auto                     timestamp = get_timestamp();

    auto date = unixtime_to_datestring(timestamp, 0, format_date);
    auto time = unixtime_to_datestring(timestamp, 3, format_time);

    tools::classhelper::ObjectPrinter printer(
        "KongsbergAllDatagram", float_precision, superscript_exponents);

    printer.register_value("bytes", _bytes);
    printer.register_string("stx", fmt::format("0x{:02x}", _stx));
    printer.register_string(
        "datagram_identifier",
        fmt::format("0x{:02x}", uint8_t(_datagram_identifier)),
        datagram_identifier_to_string(t_KongsbergAllDatagramIdentifier(_datagram_identifier)));
    printer.register_string(
        "model_number", get_model_number_as_string(), std::to_string(get_model_number()));
    printer.register_value("date", _date, "YYYYMMDD");
    printer.register_value("time_since_midnight", _time_since_midnight, "ms");

    printer.register_section("date/time");
    printer.register_value("timestamp", timestamp, "s");
    printer.register_string("date", date, "MM/DD/YYYY");
    printer.register_string("time", time, "HH:MM:SS");
    ;

    return printer;
}

} // namespace datagrams
} // namespace kongsbergall  
} // namespace echosounders
} // namespace themachinethatgoesping
