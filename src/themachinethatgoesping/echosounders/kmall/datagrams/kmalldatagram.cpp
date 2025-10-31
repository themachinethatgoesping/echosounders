// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "kmalldatagram.hpp"

/* std includes */
#include <fmt/core.h>

/* external includes */
#include <boost/endian/conversion.hpp>

/* themachinethatgoesping includes */
#include <themachinethatgoesping/tools/timeconv.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {

KMALLDatagram KMALLDatagram::from_stream(std::istream& is)
{
    KMALLDatagram d;

    // Read multiple values at once
    std::array<char, __size> buffer;
    is.read(buffer.data(), __size);

    // pack structure because variable order is not sorted
    constexpr size_t offset_1 = sizeof(uint32_t);
    constexpr size_t offset_2 = offset_1 + sizeof(uint32_t);
    constexpr size_t offset_3 = offset_2 + sizeof(uint8_t);
    constexpr size_t offset_4 = offset_3 + sizeof(uint8_t);
    constexpr size_t offset_5 = offset_4 + sizeof(uint16_t);
    constexpr size_t offset_6 = offset_5 + sizeof(uint32_t);

    std::memcpy(&d._bytes_datagram, buffer.data(), sizeof(uint32_t));
    std::memcpy(&d._datagram_identifier.value, buffer.data() + offset_1, sizeof(uint32_t));
    std::memcpy(&d._datagram_version, buffer.data() + offset_2, sizeof(uint8_t));
    std::memcpy(&d._system_id, buffer.data() + offset_3, sizeof(uint8_t));
    std::memcpy(&d._echo_sounder_id, buffer.data() + offset_4, sizeof(uint16_t));
    std::memcpy(&d._time_sec, buffer.data() + offset_5, sizeof(uint32_t));
    std::memcpy(&d._time_nanosec, buffer.data() + offset_6, sizeof(uint32_t));

    return d;
}

KMALLDatagram KMALLDatagram::from_stream(std::istream&             is,
                                         o_KMALLDatagramIdentifier datagram_identifier)
{
    KMALLDatagram d = from_stream(is);

    if (d.get_datagram_identifier() != datagram_identifier)
        throw std::runtime_error(fmt::format("KMALLDatagram::skip_and_verify_header: datagram "
                                             "identifier is not {}, but {}",
                                             datagram_identifier.name(),
                                             d.get_datagram_identifier().name()));

    return d;
}

void KMALLDatagram::to_stream(std::ostream& os) const
{
    // pack structure because variable order is not sorted
    std::array<char, __size> buffer;
    constexpr size_t         offset_1 = sizeof(uint32_t);
    constexpr size_t         offset_2 = offset_1 + sizeof(uint32_t);
    constexpr size_t         offset_3 = offset_2 + sizeof(uint8_t);
    constexpr size_t         offset_4 = offset_3 + sizeof(uint8_t);
    constexpr size_t         offset_5 = offset_4 + sizeof(uint16_t);
    constexpr size_t         offset_6 = offset_5 + sizeof(uint32_t);

    std::memcpy(buffer.data(), &(_bytes_datagram), sizeof(uint32_t));
    std::memcpy(buffer.data() + offset_1, &(_datagram_identifier.value), sizeof(uint32_t));
    std::memcpy(buffer.data() + offset_2, &(_datagram_version), sizeof(uint8_t));
    std::memcpy(buffer.data() + offset_3, &(_system_id), sizeof(uint8_t));
    std::memcpy(buffer.data() + offset_4, &(_echo_sounder_id), sizeof(uint16_t));
    std::memcpy(buffer.data() + offset_5, &(_time_sec), sizeof(uint32_t));
    std::memcpy(buffer.data() + offset_6, &(_time_nanosec), sizeof(uint32_t));

    os.write(buffer.data(), __size);
}

tools::classhelper::ObjectPrinter KMALLDatagram::__printer__(unsigned int float_precision,
                                                             bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "KMALLDatagram", float_precision, superscript_exponents);

    printer.register_value("bytes_datagram", _bytes_datagram, "bytes");
    printer.register_value("datagram_identifier", _datagram_identifier.name());
    printer.register_value("datagram_version", _datagram_version);
    printer.register_value("system_id", _system_id);
    printer.register_value("echo_sounder_id", _echo_sounder_id);
    printer.register_value("time_sec", _time_sec, "s");
    printer.register_value("time_nanosec", _time_nanosec, "ns");

    // time processing (if time is provided)
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
        printer.register_string("date", date, "MM/DD/YYYY");
        printer.register_string("time", time, "HH:MM:SS");
    }

    return printer;
}

} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
