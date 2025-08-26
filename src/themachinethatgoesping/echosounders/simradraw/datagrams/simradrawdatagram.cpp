// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "simradrawdatagram.hpp"

// std
#include <fmt/format.h>

// themachinethatgoesping import  
#include <themachinethatgoesping/tools/timeconv.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace datagrams {

// ----- protected methods -----
void SimradRawDatagram::_verify_datagram_end(std::istream& is) const
{
    // verify that we are at the end of the datagram by reading the enclosing length field
    // This should be the same as _length if everything is ok
    simradraw_long length;
    is.read(reinterpret_cast<char*>(&length), sizeof(length));

    // (the datagrams are encapsulated by length)
    // if the lengths do not match the datagrams was not read correctly
    if (!is || length != _length)
    {
        auto error = fmt::format(
            "ERROR[SimradRawDatagram]: Datagram length check failed (read). Expected: {}, got: {}",
            _length,
            length);
        [[maybe_unused]] auto error_verbose =
            fmt::format("{}\n--- read header ---\n{}\n---", error, info_string());

        throw std::runtime_error(error);
        // std::cerr << error << std::endl;
    }
}

// ----- public methods -----
void SimradRawDatagram::skip(std::istream& is) const
{
    // _length is the length the datagram that is enclosed by _length
    static constexpr simradraw_long tmp = sizeof(simradraw_long) * 3;

    is.seekg(_length - tmp, std::ios::cur);

    // verify the datagram is read correctly by reading the length field at the end
    _verify_datagram_end(is);
}

double SimradRawDatagram::get_timestamp() const
{
    return tools::timeconv::windows_filetime_to_unixtime(_high_date_time, _low_date_time);
}

void SimradRawDatagram::set_timestamp(double unixtime)
{
    std::tie(_high_date_time, _low_date_time) =
        tools::timeconv::unixtime_to_windows_filetime(unixtime);
}

std::string SimradRawDatagram::get_date_string(unsigned int       fractionalSecondsDigits,
                                              const std::string& format) const
{
    return tools::timeconv::unixtime_to_datestring(
        get_timestamp(), fractionalSecondsDigits, format);
}

// ----- static methods -----
SimradRawDatagram SimradRawDatagram::from_stream(std::istream& is)
{
    SimradRawDatagram d;
    is.read(reinterpret_cast<char*>(&d._length), 4 * sizeof(simradraw_long));

    return d;
}

SimradRawDatagram SimradRawDatagram::from_stream(std::istream&              is,
                                                t_SimradRawDatagramIdentifier datagram_identifier)
{
    SimradRawDatagram d = from_stream(is);

    if (d.get_datagram_identifier() != datagram_identifier)
        throw std::runtime_error(fmt::format("SimradRawDatagram: Datagram identifier mismatch!"));

    return d;
}

void SimradRawDatagram::to_stream(std::ostream& os) const
{
    os.write(reinterpret_cast<const char*>(&_length), 4 * sizeof(simradraw_long));
}

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
