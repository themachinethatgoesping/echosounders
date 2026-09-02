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
    tools::classhelper::ObjectPrinter printer("MatchFilter", float_precision, superscript_exponents);

    printer.append(S7KDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("MatchFilter content");
    printer.register_value("serial_number", _content.serial_number);
    printer.register_value("ping_number", _content.ping_number);
    printer.register_value("operation", _content.operation);
    printer.register_value("start_frequency", _content.start_frequency, "Hz");
    printer.register_value("end_frequency", _content.end_frequency, "Hz");
    printer.register_value("window_type", _content.window_type);
    printer.register_value("shading", _content.shading);
    printer.register_value("effective_pulse_width", _content.effective_pulse_width, "s");

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
