// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "position.hpp"

#include <numbers>
#include <stdexcept>
#include <utility>

#include <fmt/format.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

// ----- constructors -----
Position::Position()
    : _content{}
{
    set_datagram_identifier(DatagramIdentifier);
}

Position::Position(S7KDatagram header)
    : S7KDatagram(std::move(header))
{
}

// ----- convenient member access -----
uint32_t Position::get_datum_identifier() const
{
    return _content._datum_identifier;
}
float Position::get_latency() const
{
    return _content._latency;
}
double Position::get_latitude_or_northing() const
{
    return _content._latitude_or_northing;
}
double Position::get_longitude_or_easting() const
{
    return _content._longitude_or_easting;
}
double Position::get_height() const
{
    return _content._height;
}
Position::o_position_type_flag Position::get_position_type_flag() const
{
    return _content._position_type_flag;
}
uint8_t Position::get_utm_zone() const
{
    return _content._utm_zone;
}
Position::o_quality_flag Position::get_quality_flag() const
{
    return _content._quality_flag;
}
Position::o_position_method Position::get_position_method() const
{
    return _content._position_method;
}
uint8_t Position::get_number_of_satellites() const
{
    return _content._number_of_satellites;
}
uint32_t Position::get_checksum() const
{
    return _content._checksum;
}

void Position::set_datum_identifier(uint32_t val)
{
    _content._datum_identifier = val;
}
void Position::set_latency(float val)
{
    _content._latency = val;
}
void Position::set_latitude_or_northing(double val)
{
    _content._latitude_or_northing = val;
}
void Position::set_longitude_or_easting(double val)
{
    _content._longitude_or_easting = val;
}
void Position::set_height(double val)
{
    _content._height = val;
}
void Position::set_position_type_flag(o_position_type_flag val)
{
    _content._position_type_flag = val;
}
void Position::set_utm_zone(uint8_t val)
{
    _content._utm_zone = val;
}
void Position::set_quality_flag(o_quality_flag val)
{
    _content._quality_flag = val;
}
void Position::set_position_method(o_position_method val)
{
    _content._position_method = val;
}
void Position::set_number_of_satellites(uint8_t val)
{
    _content._number_of_satellites = val;
}
void Position::set_checksum(uint32_t val)
{
    _content._checksum = val;
}

// ----- processed data access -----
double Position::get_latitude_in_degrees() const
{
    if (get_position_type_flag() == t_position_type_flag::grid)
        throw std::runtime_error("ERROR[S7K Position (1003) get_latitude_in_degrees]: Position "
                                 "type 'grid' is not yet implemented");
    return _content._latitude_or_northing * 180.0 / std::numbers::pi;
}

double Position::get_longitude_in_degrees() const
{
    if (get_position_type_flag() == t_position_type_flag::grid)
        throw std::runtime_error("ERROR[S7K Position (1003) get_longitude_in_degrees]: "
                                 "Position type 'grid' is not yet implemented");
    return _content._longitude_or_easting * 180.0 / std::numbers::pi;
}

// ----- to/from stream functions -----
void Position::__read__(std::istream& is)
{
    is.read(reinterpret_cast<char*>(&_content), __content_size);
}

Position Position::from_stream(std::istream& is, S7KDatagram header)
{
    Position datagram(std::move(header));
    datagram.__read__(is);
    return datagram;
}

Position Position::from_stream(std::istream& is)
{
    return from_stream(is, S7KDatagram::from_stream(is));
}

Position Position::from_stream(std::istream& is, o_S7KDatagramIdentifier datagram_identifier)
{
    return from_stream(is, S7KDatagram::from_stream(is, datagram_identifier));
}

void Position::to_stream(std::ostream& os) const
{
    S7KDatagram::to_stream(os);
    os.write(reinterpret_cast<const char*>(&_content), __content_size);
}

tools::classhelper::ObjectPrinter Position::__printer__(unsigned int float_precision,
                                                        bool         superscript_exponents) const
{
    const auto& o_datagram_identifier = S7KDatagram::o_DatagramIdentifier(DatagramIdentifier);
    tools::classhelper::ObjectPrinter printer(
        fmt::format("S7K {} ({})", o_datagram_identifier.name(), uint32_t(o_datagram_identifier)),
        float_precision,
        superscript_exponents);

    printer.append(S7KDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("Position content");
    printer.register_value("datum_identifier", _content._datum_identifier);
    printer.register_value("latency", _content._latency, "s");
    printer.register_value("latitude_or_northing", _content._latitude_or_northing, "rad|m");
    printer.register_value("longitude_or_easting", _content._longitude_or_easting, "rad|m");
    printer.register_value("height", _content._height, "m");
    printer.register_string("position_type_flag",
                            _content._position_type_flag.name(),
                            _content._position_type_flag.alt_name());
    printer.register_value("utm_zone", _content._utm_zone);
    printer.register_string(
        "quality_flag", _content._quality_flag.name(), _content._quality_flag.alt_name());
    printer.register_string(
        "position_method", _content._position_method.name(), _content._position_method.alt_name());
    printer.register_value("number_of_satellites", _content._number_of_satellites);
    printer.register_value("checksum", _content._checksum);

    printer.register_section("processed");
    printer.register_value("latitude_in_degrees", get_latitude_in_degrees(), "°");
    printer.register_value("longitude_in_degrees", get_longitude_in_degrees(), "°");

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping

// ----- explicit template instantiation (matches extern template in position.hpp) -----
template struct themachinethatgoesping::tools::classhelper::OptionFrozen<
    themachinethatgoesping::echosounders::s7k::datagrams::Position::t_position_type_flag,
    themachinethatgoesping::echosounders::s7k::datagrams::Position::t_position_type_flag_values
        .size(),
    themachinethatgoesping::echosounders::s7k::datagrams::Position::t_position_type_flag_values,
    themachinethatgoesping::echosounders::s7k::datagrams::Position::t_position_type_flag_names,
    themachinethatgoesping::echosounders::s7k::datagrams::Position::t_position_type_flag_alt_names>;
template struct themachinethatgoesping::tools::classhelper::OptionFrozen<
    themachinethatgoesping::echosounders::s7k::datagrams::Position::t_quality_flag,
    themachinethatgoesping::echosounders::s7k::datagrams::Position::t_quality_flag_values.size(),
    themachinethatgoesping::echosounders::s7k::datagrams::Position::t_quality_flag_values,
    themachinethatgoesping::echosounders::s7k::datagrams::Position::t_quality_flag_names,
    themachinethatgoesping::echosounders::s7k::datagrams::Position::t_quality_flag_alt_names>;
template struct themachinethatgoesping::tools::classhelper::OptionFrozen<
    themachinethatgoesping::echosounders::s7k::datagrams::Position::t_position_method,
    themachinethatgoesping::echosounders::s7k::datagrams::Position::t_position_method_values.size(),
    themachinethatgoesping::echosounders::s7k::datagrams::Position::t_position_method_values,
    themachinethatgoesping::echosounders::s7k::datagrams::Position::t_position_method_names,
    themachinethatgoesping::echosounders::s7k::datagrams::Position::t_position_method_alt_names>;
