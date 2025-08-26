// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "simradrawdatagram.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {

// ----- objectprinter -----
tools::classhelper::ObjectPrinter SimradRawDatagram::__printer__(unsigned int float_precision, bool superscript_exponents) const
{
    using tools::timeconv::unixtime_to_datestring;

    static const std::string format_data("%d/%m/%Y");
    static const std::string format_time("%H:%M:%S");
    auto                     timestamp = get_timestamp();

    auto date = unixtime_to_datestring(timestamp, 0, format_data);
    auto time = unixtime_to_datestring(timestamp, 3, format_time);

    tools::classhelper::ObjectPrinter printer("SimradRawDatagram", float_precision, superscript_exponents);

    printer.register_value("length", _length, "bytes");
    printer.register_string(
        "datagram_identifier",
        datagram_identifier_to_string(t_SimradRawDatagramIdentifier(_datagram_type)));
    printer.register_value("timestamp", timestamp, "s");
    printer.register_string("date", date, "MM/DD/YYYY");
    printer.register_string("time", time, "HH:MM:SS");

    return printer;
}

} // namespace datagrams
} // namespace simradraw
} // namespace echosounders
} // namespace themachinethatgoesping
