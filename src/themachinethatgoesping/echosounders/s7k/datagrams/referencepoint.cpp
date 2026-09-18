// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "referencepoint.hpp"

#include <utility>

#include <fmt/format.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

// ----- constructors -----
ReferencePoint::ReferencePoint()
    : _content{}
{
    set_datagram_identifier(DatagramIdentifier);
}

ReferencePoint::ReferencePoint(S7KDatagram header)
    : S7KDatagram(std::move(header))
{
}

// ----- convenient member access -----
float ReferencePoint::get_offset_x() const
{
    return _content._offset_x;
}
float ReferencePoint::get_offset_y() const
{
    return _content._offset_y;
}
float ReferencePoint::get_offset_z() const
{
    return _content._offset_z;
}
float ReferencePoint::get_water_z() const
{
    return _content._water_z;
}
uint32_t ReferencePoint::get_checksum() const
{
    return _content._checksum;
}

void ReferencePoint::set_offset_x(float val)
{
    _content._offset_x = val;
}
void ReferencePoint::set_offset_y(float val)
{
    _content._offset_y = val;
}
void ReferencePoint::set_offset_z(float val)
{
    _content._offset_z = val;
}
void ReferencePoint::set_water_z(float val)
{
    _content._water_z = val;
}
void ReferencePoint::set_checksum(uint32_t val)
{
    _content._checksum = val;
}

// ----- to/from stream functions -----
void ReferencePoint::__read__(std::istream& is)
{
    is.read(reinterpret_cast<char*>(&_content), __content_size);
}

ReferencePoint ReferencePoint::from_stream(std::istream& is, S7KDatagram header)
{
    ReferencePoint datagram(std::move(header));
    datagram.__read__(is);
    return datagram;
}

ReferencePoint ReferencePoint::from_stream(std::istream& is)
{
    return from_stream(is, S7KDatagram::from_stream(is));
}

ReferencePoint ReferencePoint::from_stream(std::istream& is, o_S7KDatagramIdentifier datagram_identifier)
{
    return from_stream(is, S7KDatagram::from_stream(is, datagram_identifier));
}

void ReferencePoint::to_stream(std::ostream& os) const
{
    S7KDatagram::to_stream(os);
    os.write(reinterpret_cast<const char*>(&_content), __content_size);
}

tools::classhelper::ObjectPrinter ReferencePoint::__printer__(unsigned int float_precision,
                                                     bool         superscript_exponents) const
{
    const auto& o_datagram_identifier = S7KDatagram::o_DatagramIdentifier(DatagramIdentifier);
    tools::classhelper::ObjectPrinter printer(
        fmt::format("S7K {} ({})", o_datagram_identifier.name(), uint32_t(o_datagram_identifier)),
        float_precision,
        superscript_exponents);

    printer.append(S7KDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("ReferencePoint content");
    printer.register_value("offset_x", _content._offset_x, "m");
    printer.register_value("offset_y", _content._offset_y, "m");
    printer.register_value("offset_z", _content._offset_z, "m");
    printer.register_value("water_z", _content._water_z, "m");
    printer.register_value("checksum", _content._checksum);

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
