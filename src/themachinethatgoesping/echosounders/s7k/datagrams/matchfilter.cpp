// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "matchfilter.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

MatchFilter MatchFilter::from_stream(std::istream& is, S7KDatagram header)
{
    MatchFilter datagram(std::move(header));
    datagram.__read__(is);
    return datagram;
}

MatchFilter MatchFilter::from_stream(std::istream& is)
{
    return from_stream(is, S7KDatagram::from_stream(is));
}

MatchFilter MatchFilter::from_stream(std::istream& is, o_S7KDatagramIdentifier datagram_identifier)
{
    return from_stream(is, S7KDatagram::from_stream(is, datagram_identifier));
}

void MatchFilter::to_stream(std::ostream& os) const
{
    S7KDatagram::to_stream(os);
    os.write(reinterpret_cast<const char*>(&_content), __content_size);
}

tools::classhelper::ObjectPrinter MatchFilter::__printer__(unsigned int float_precision,
                                                     bool         superscript_exponents) const
{
    const auto& o_datagram_identifier = S7KDatagram::o_DatagramIdentifier(DatagramIdentifier);
    tools::classhelper::ObjectPrinter printer(
        fmt::format("S7K {} ({})", o_datagram_identifier.name(), uint32_t(o_datagram_identifier)),
        float_precision,
        superscript_exponents);

    printer.append(S7KDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("MatchFilter content");
    printer.register_value("serial_number", _content._serial_number);
    printer.register_value("ping_number", _content._ping_number);
    printer.register_string(
        "operation", _content._operation.name(), _content._operation.alt_name());
    printer.register_value("start_frequency", _content._start_frequency, "Hz");
    printer.register_value("end_frequency", _content._end_frequency, "Hz");
    printer.register_string(
        "window_type", _content._window_type.name(), _content._window_type.alt_name());
    printer.register_value("shading", _content._shading);
    printer.register_value("effective_pulse_width", _content._effective_pulse_width, "s");
    printer.register_value("checksum", _content._checksum);

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
