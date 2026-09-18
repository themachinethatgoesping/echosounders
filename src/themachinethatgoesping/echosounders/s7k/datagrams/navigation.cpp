// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "navigation.hpp"

#include <numbers>
#include <utility>

#include <fmt/format.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

// ----- constructors -----
Navigation::Navigation()
    : _content{}
{
    set_datagram_identifier(DatagramIdentifier);
}

Navigation::Navigation(S7KDatagram header)
    : S7KDatagram(std::move(header))
{
}

// ----- convenient member access -----
Navigation::o_vertical_reference Navigation::get_vertical_reference() const
{
    return _content._vertical_reference;
}
double Navigation::get_latitude() const
{
    return _content._latitude;
}
double Navigation::get_longitude() const
{
    return _content._longitude;
}
float Navigation::get_position_accuracy() const
{
    return _content._position_accuracy;
}
float Navigation::get_height() const
{
    return _content._height;
}
float Navigation::get_height_accuracy() const
{
    return _content._height_accuracy;
}
float Navigation::get_speed() const
{
    return _content._speed;
}
float Navigation::get_course() const
{
    return _content._course;
}
float Navigation::get_heading() const
{
    return _content._heading;
}
uint32_t Navigation::get_checksum() const
{
    return _content._checksum;
}

void Navigation::set_vertical_reference(o_vertical_reference val)
{
    _content._vertical_reference = val;
}
void Navigation::set_latitude(double val)
{
    _content._latitude = val;
}
void Navigation::set_longitude(double val)
{
    _content._longitude = val;
}
void Navigation::set_position_accuracy(float val)
{
    _content._position_accuracy = val;
}
void Navigation::set_height(float val)
{
    _content._height = val;
}
void Navigation::set_height_accuracy(float val)
{
    _content._height_accuracy = val;
}
void Navigation::set_speed(float val)
{
    _content._speed = val;
}
void Navigation::set_course(float val)
{
    _content._course = val;
}
void Navigation::set_heading(float val)
{
    _content._heading = val;
}
void Navigation::set_checksum(uint32_t val)
{
    _content._checksum = val;
}

// ----- processed data access -----
double Navigation::get_latitude_in_degrees() const
{
    return _content._latitude * 180.0 / std::numbers::pi;
}
double Navigation::get_longitude_in_degrees() const
{
    return _content._longitude * 180.0 / std::numbers::pi;
}
float Navigation::get_course_in_degrees() const
{
    return _content._course * 180.f / float(std::numbers::pi);
}
float Navigation::get_heading_in_degrees() const
{
    return _content._heading * 180.f / float(std::numbers::pi);
}

// ----- to/from stream functions -----
void Navigation::__read__(std::istream& is)
{
    is.read(reinterpret_cast<char*>(&_content), __content_size);
}

Navigation Navigation::from_stream(std::istream& is, S7KDatagram header)
{
    Navigation datagram(std::move(header));
    datagram.__read__(is);
    return datagram;
}

Navigation Navigation::from_stream(std::istream& is)
{
    return from_stream(is, S7KDatagram::from_stream(is));
}

Navigation Navigation::from_stream(std::istream& is, o_S7KDatagramIdentifier datagram_identifier)
{
    return from_stream(is, S7KDatagram::from_stream(is, datagram_identifier));
}

void Navigation::to_stream(std::ostream& os) const
{
    S7KDatagram::to_stream(os);
    os.write(reinterpret_cast<const char*>(&_content), __content_size);
}

tools::classhelper::ObjectPrinter Navigation::__printer__(unsigned int float_precision,
                                                     bool         superscript_exponents) const
{
    const auto& o_datagram_identifier = S7KDatagram::o_DatagramIdentifier(DatagramIdentifier);
    tools::classhelper::ObjectPrinter printer(
        fmt::format("S7K {} ({})", o_datagram_identifier.name(), uint32_t(o_datagram_identifier)),
        float_precision,
        superscript_exponents);

    printer.append(S7KDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("Navigation content");
    printer.register_string("vertical_reference",
                            _content._vertical_reference.name(),
                            _content._vertical_reference.alt_name());
    printer.register_value("latitude", _content._latitude, "rad");
    printer.register_value("longitude", _content._longitude, "rad");
    printer.register_value("position_accuracy", _content._position_accuracy, "m");
    printer.register_value("height", _content._height, "m");
    printer.register_value("height_accuracy", _content._height_accuracy, "m");
    printer.register_value("speed", _content._speed, "m/s");
    printer.register_value("course", _content._course, "rad");
    printer.register_value("heading", _content._heading, "rad");
    printer.register_value("checksum", _content._checksum);

    printer.register_section("processed");
    printer.register_value("latitude_in_degrees", get_latitude_in_degrees(), "°");
    printer.register_value("longitude_in_degrees", get_longitude_in_degrees(), "°");
    printer.register_value("course_in_degrees", get_course_in_degrees(), "°");
    printer.register_value("heading_in_degrees", get_heading_in_degrees(), "°");

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping

// ----- explicit template instantiation (matches extern template in navigation.hpp) -----
template struct themachinethatgoesping::tools::classhelper::OptionFrozen<
    themachinethatgoesping::echosounders::s7k::datagrams::Navigation::t_vertical_reference,
    themachinethatgoesping::echosounders::s7k::datagrams::Navigation::t_vertical_reference_values
        .size(),
    themachinethatgoesping::echosounders::s7k::datagrams::Navigation::t_vertical_reference_values,
    themachinethatgoesping::echosounders::s7k::datagrams::Navigation::t_vertical_reference_names,
    themachinethatgoesping::echosounders::s7k::datagrams::Navigation::t_vertical_reference_alt_names>;
