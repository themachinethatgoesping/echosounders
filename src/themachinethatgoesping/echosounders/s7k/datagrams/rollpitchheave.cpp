// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "rollpitchheave.hpp"

#include <numbers>
#include <utility>

#include <fmt/format.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

// ----- constructors -----
RollPitchHeave::RollPitchHeave()
    : _content{}
{
    set_datagram_identifier(DatagramIdentifier);
}

RollPitchHeave::RollPitchHeave(S7KDatagram header)
    : S7KDatagram(std::move(header))
{
}

// ----- convenient member access -----
float RollPitchHeave::get_roll() const
{
    return _content._roll;
}
float RollPitchHeave::get_pitch() const
{
    return _content._pitch;
}
float RollPitchHeave::get_heave() const
{
    return _content._heave;
}
uint32_t RollPitchHeave::get_checksum() const
{
    return _content._checksum;
}

void RollPitchHeave::set_roll(float val)
{
    _content._roll = val;
}
void RollPitchHeave::set_pitch(float val)
{
    _content._pitch = val;
}
void RollPitchHeave::set_heave(float val)
{
    _content._heave = val;
}
void RollPitchHeave::set_checksum(uint32_t val)
{
    _content._checksum = val;
}

// ----- processed data access -----
float RollPitchHeave::get_roll_in_degrees() const
{
    return _content._roll * 180.f / float(std::numbers::pi);
}
float RollPitchHeave::get_pitch_in_degrees() const
{
    return _content._pitch * 180.f / float(std::numbers::pi);
}

// ----- to/from stream functions -----
void RollPitchHeave::__read__(std::istream& is)
{
    is.read(reinterpret_cast<char*>(&_content), __content_size);
}

RollPitchHeave RollPitchHeave::from_stream(std::istream& is, S7KDatagram header)
{
    RollPitchHeave datagram(std::move(header));
    datagram.__read__(is);
    return datagram;
}

RollPitchHeave RollPitchHeave::from_stream(std::istream& is)
{
    return from_stream(is, S7KDatagram::from_stream(is));
}

RollPitchHeave RollPitchHeave::from_stream(std::istream& is, o_S7KDatagramIdentifier datagram_identifier)
{
    return from_stream(is, S7KDatagram::from_stream(is, datagram_identifier));
}

void RollPitchHeave::to_stream(std::ostream& os) const
{
    S7KDatagram::to_stream(os);
    os.write(reinterpret_cast<const char*>(&_content), __content_size);
}

tools::classhelper::ObjectPrinter RollPitchHeave::__printer__(unsigned int float_precision,
                                                     bool         superscript_exponents) const
{
    const auto& o_datagram_identifier = S7KDatagram::o_DatagramIdentifier(DatagramIdentifier);
    tools::classhelper::ObjectPrinter printer(
        fmt::format("S7K {} ({})", o_datagram_identifier.name(), uint32_t(o_datagram_identifier)),
        float_precision,
        superscript_exponents);

    printer.append(S7KDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("RollPitchHeave content");
    printer.register_value("roll", _content._roll, "rad");
    printer.register_value("pitch", _content._pitch, "rad");
    printer.register_value("heave", _content._heave, "m");
    printer.register_value("checksum", _content._checksum);

    printer.register_section("processed");
    printer.register_value("roll_in_degrees", get_roll_in_degrees(), "°");
    printer.register_value("pitch_in_degrees", get_pitch_in_degrees(), "°");

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
