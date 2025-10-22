// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "kongsbergalldatagram.hpp"

/* std includes */
#include <fmt/core.h>
#include <istream>
#include <ostream>
#include <stdexcept>
#include <string>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/timeconv.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

void KongsbergAllDatagram::_verify_datagram_end(std::istream& is) const
{
    struct t_EndIdentifier
    {
        uint8_t  etx;
        uint16_t checksum = 0;
    } etx;

    is.read(reinterpret_cast<char*>(&etx.etx), 3 * sizeof(uint8_t));

    if (etx.etx != 0x03)
        throw std::runtime_error(fmt::format(
            "KongsbergAllDatagram: end identifier is not 0x03, but 0x{:x}", etx.etx));
}

KongsbergAllDatagram::KongsbergAllDatagram(uint32_t             bytes,
                                           t_DatagramIdentifier datagram_identifier,
                                           uint16_t             model_number,
                                           uint16_t             date,
                                           uint16_t             time_since_midnight)
    : _bytes(bytes)
    , _datagram_identifier(datagram_identifier)
    , _model_number(model_number)
    , _date(date)
    , _time_since_midnight(time_since_midnight)
{
}

void KongsbergAllDatagram::skip(std::istream& is) const
{
    static constexpr uint8_t skipped_bytes = sizeof(uint8_t) * 15;

    is.seekg(_bytes - skipped_bytes, std::ios::cur);

    _verify_datagram_end(is);
}

size_t KongsbergAllDatagram::skip_and_verify_header(std::istream&                    is,
                                                    size_t                           stream_pos,
                                                    t_KongsbergAllDatagramIdentifier identifier)
{
    is.seekg(stream_pos + 5, std::ios::beg);

    t_KongsbergAllDatagramIdentifier datagram_identifier;
    is.read(reinterpret_cast<char*>(&datagram_identifier),
            sizeof(t_KongsbergAllDatagramIdentifier));
    if (datagram_identifier != identifier)
        throw std::runtime_error(
            fmt::format("KongsbergAllDatagram::skip_and_verify_header: datagram "
                        "identifier is not {}, but {}",
                        datagram_type_to_string(identifier),
                        datagram_type_to_string(datagram_identifier)));

    is.seekg(10, std::ios::cur);

    return is.tellg();
}

uint32_t KongsbergAllDatagram::get_bytes() const { return _bytes; }

uint8_t KongsbergAllDatagram::get_stx() const { return _stx; }

KongsbergAllDatagram::t_DatagramIdentifier KongsbergAllDatagram::get_datagram_identifier() const
{
    return _datagram_identifier;
}

uint16_t KongsbergAllDatagram::get_model_number() const { return _model_number; }

uint32_t KongsbergAllDatagram::get_date() const { return _date; }

uint32_t KongsbergAllDatagram::get_time_since_midnight() const { return _time_since_midnight; }

void KongsbergAllDatagram::set_bytes(uint32_t bytes) { _bytes = bytes; }

void KongsbergAllDatagram::set_stx(uint8_t stx) { _stx = stx; }

void KongsbergAllDatagram::set_datagram_identifier(t_DatagramIdentifier datagram_identifier)
{
    _datagram_identifier = datagram_identifier;
}

void KongsbergAllDatagram::set_model_number(uint16_t model_number) { _model_number = model_number; }

void KongsbergAllDatagram::set_date(uint32_t date) { _date = date; }

void KongsbergAllDatagram::set_time_since_midnight(uint32_t time_since_midnight)
{
    _time_since_midnight = time_since_midnight;
}

double KongsbergAllDatagram::get_timestamp() const
{
    int y = int(_date / 10000);
    int m = int(_date / 100) - y * 100;
    int d = int(_date) - y * 10000 - m * 100;

    return tools::timeconv::year_month_day_to_unixtime(
        y, m, d, static_cast<uint64_t>(_time_since_midnight) * 1000);
}

std::string KongsbergAllDatagram::get_date_string(unsigned int       fractionalSecondsDigits,
                                                  const std::string& format) const
{
    return tools::timeconv::unixtime_to_datestring(
        get_timestamp(), fractionalSecondsDigits, format);
}

std::string KongsbergAllDatagram::get_model_number_as_string() const
{
    if (_model_number == 2045)
        return "EM2040C";

    return "EM" + std::to_string(_model_number);
}

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
