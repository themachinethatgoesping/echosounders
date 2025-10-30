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
    is.read(reinterpret_cast<char*>(&d._num_bytes_dgm), sizeof(KMALLDatagram));

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
    os.write(reinterpret_cast<const char*>(&_num_bytes_dgm), sizeof(KMALLDatagram));
}

tools::classhelper::ObjectPrinter KMALLDatagram::__printer__(unsigned int float_precision,
                                                             bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "KMALLDatagram", float_precision, superscript_exponents);

    printer.register_value("num_bytes_dgm", _num_bytes_dgm, "bytes");
    printer.register_value("dgm_type", _dgm_type.name());
    printer.register_value("dgm_version", _dgm_version);
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
