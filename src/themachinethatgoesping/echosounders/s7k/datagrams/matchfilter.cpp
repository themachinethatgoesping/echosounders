// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "matchfilter.hpp"

#include <utility>

#include <fmt/format.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

// ----- constructors -----
MatchFilter::MatchFilter()
    : _content{}
{
    set_datagram_identifier(DatagramIdentifier);
}

MatchFilter::MatchFilter(S7KDatagram header)
    : S7KDatagram(std::move(header))
{
}

// ----- convenient member access -----
uint64_t MatchFilter::get_serial_number() const
{
    return _content._serial_number;
}
uint32_t MatchFilter::get_ping_number() const
{
    return _content._ping_number;
}
MatchFilter::o_operation MatchFilter::get_operation() const
{
    return _content._operation;
}
float MatchFilter::get_start_frequency() const
{
    return _content._start_frequency;
}
float MatchFilter::get_end_frequency() const
{
    return _content._end_frequency;
}
MatchFilter::o_window_type MatchFilter::get_window_type() const
{
    return _content._window_type;
}
float MatchFilter::get_shading() const
{
    return _content._shading;
}
float MatchFilter::get_effective_pulse_width() const
{
    return _content._effective_pulse_width;
}
uint32_t MatchFilter::get_checksum() const
{
    return _content._checksum;
}

void MatchFilter::set_serial_number(uint64_t val)
{
    _content._serial_number = val;
}
void MatchFilter::set_ping_number(uint32_t val)
{
    _content._ping_number = val;
}
void MatchFilter::set_operation(o_operation val)
{
    _content._operation = val;
}
void MatchFilter::set_start_frequency(float val)
{
    _content._start_frequency = val;
}
void MatchFilter::set_end_frequency(float val)
{
    _content._end_frequency = val;
}
void MatchFilter::set_window_type(o_window_type val)
{
    _content._window_type = val;
}
void MatchFilter::set_shading(float val)
{
    _content._shading = val;
}
void MatchFilter::set_effective_pulse_width(float val)
{
    _content._effective_pulse_width = val;
}
void MatchFilter::set_checksum(uint32_t val)
{
    _content._checksum = val;
}

// ----- to/from stream functions -----
void MatchFilter::__read__(std::istream& is)
{
    is.read(reinterpret_cast<char*>(&_content), __content_size);
}

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

// ----- explicit template instantiation (matches extern template in matchfilter.hpp) -----
template struct themachinethatgoesping::tools::classhelper::OptionFrozen<
    themachinethatgoesping::echosounders::s7k::datagrams::MatchFilter::t_operation,
    themachinethatgoesping::echosounders::s7k::datagrams::MatchFilter::t_operation_values.size(),
    themachinethatgoesping::echosounders::s7k::datagrams::MatchFilter::t_operation_values,
    themachinethatgoesping::echosounders::s7k::datagrams::MatchFilter::t_operation_names,
    themachinethatgoesping::echosounders::s7k::datagrams::MatchFilter::t_operation_alt_names>;
template struct themachinethatgoesping::tools::classhelper::OptionFrozen<
    themachinethatgoesping::echosounders::s7k::datagrams::MatchFilter::t_window_type,
    themachinethatgoesping::echosounders::s7k::datagrams::MatchFilter::t_window_type_values.size(),
    themachinethatgoesping::echosounders::s7k::datagrams::MatchFilter::t_window_type_values,
    themachinethatgoesping::echosounders::s7k::datagrams::MatchFilter::t_window_type_names,
    themachinethatgoesping::echosounders::s7k::datagrams::MatchFilter::t_window_type_alt_names>;
