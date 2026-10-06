// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "soundvelocity.hpp"

#include <utility>

#include <fmt/format.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

// ----- constructors -----
SoundVelocity::SoundVelocity()
    : _content{}
{
    set_datagram_identifier(DatagramIdentifier);
    // a freshly built record carries sound velocity only (no optional temperature/pressure); keep
    // the DRF size consistent so to/from binary round-trip and has_temperature_and_pressure() work
    set_size(uint32_t(__size + __content_size_minimal));
}

SoundVelocity::SoundVelocity(S7KDatagram header)
    : S7KDatagram(std::move(header))
{
}

// ----- convenient member access -----
float SoundVelocity::get_sound_velocity() const
{
    return _content._sound_velocity;
}
float SoundVelocity::get_temperature() const
{
    return _content._temperature;
}
float SoundVelocity::get_pressure() const
{
    return _content._pressure;
}
uint32_t SoundVelocity::get_checksum() const
{
    return _content._checksum;
}

void SoundVelocity::set_sound_velocity(float val)
{
    _content._sound_velocity = val;
}
void SoundVelocity::set_temperature(float val)
{
    _content._temperature = val;
    // temperature/pressure are only stored by newer IO modules; mark them present in the record
    set_size(uint32_t(__size + __content_size));
}
void SoundVelocity::set_pressure(float val)
{
    _content._pressure = val;
    set_size(uint32_t(__size + __content_size));
}
void SoundVelocity::set_checksum(uint32_t val)
{
    _content._checksum = val;
}

// ----- processed -----
bool SoundVelocity::has_temperature_and_pressure() const
{
    // the optional temperature + pressure pair is present iff the record is large enough to hold
    // the full 12-byte RTH (sound velocity + temperature + pressure) plus the checksum
    return get_size() >= __size + __content_size;
}

// ----- to/from stream functions -----
void SoundVelocity::__read__(std::istream& is)
{
    // The 7610 record carries a 4-byte RTH (sound velocity only) or a 12-byte RTH that
    // additionally holds temperature + pressure (IO module >= V4.0.0.8, spec Table 118). Older
    // records omit the optional pair; detect this from the record size (DRF size - header).
    is.read(reinterpret_cast<char*>(&_content._sound_velocity), sizeof(float));
    if (has_temperature_and_pressure())
    {
        is.read(reinterpret_cast<char*>(&_content._temperature), sizeof(float));
        is.read(reinterpret_cast<char*>(&_content._pressure), sizeof(float));
    }
    else
    {
        _content._temperature = 0.f;
        _content._pressure    = 0.f;
    }
    is.read(reinterpret_cast<char*>(&_content._checksum), sizeof(uint32_t));
}

SoundVelocity SoundVelocity::from_stream(std::istream& is, S7KDatagram header)
{
    SoundVelocity datagram(std::move(header));
    datagram.__read__(is);
    return datagram;
}

SoundVelocity SoundVelocity::from_stream(std::istream& is)
{
    return from_stream(is, S7KDatagram::from_stream(is));
}

SoundVelocity SoundVelocity::from_stream(std::istream& is, o_S7KDatagramIdentifier datagram_identifier)
{
    return from_stream(is, S7KDatagram::from_stream(is, datagram_identifier));
}

void SoundVelocity::to_stream(std::ostream& os) const
{
    S7KDatagram::to_stream(os);
    // Mirror the on-disk layout: write the optional temperature + pressure only when present
    // (so records read without them round-trip to the same 4-byte RTH).
    os.write(reinterpret_cast<const char*>(&_content._sound_velocity), sizeof(float));
    if (has_temperature_and_pressure())
    {
        os.write(reinterpret_cast<const char*>(&_content._temperature), sizeof(float));
        os.write(reinterpret_cast<const char*>(&_content._pressure), sizeof(float));
    }
    os.write(reinterpret_cast<const char*>(&_content._checksum), sizeof(uint32_t));
}

tools::classhelper::ObjectPrinter SoundVelocity::__printer__(unsigned int float_precision,
                                                     bool         superscript_exponents) const
{
    const auto& o_datagram_identifier = S7KDatagram::o_DatagramIdentifier(DatagramIdentifier);
    tools::classhelper::ObjectPrinter printer(
        fmt::format("S7K {} ({})", o_datagram_identifier.name(), uint32_t(o_datagram_identifier)),
        float_precision,
        superscript_exponents);

    printer.append(S7KDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("SoundVelocity content");
    printer.register_value("sound_velocity", _content._sound_velocity, "m/s");
    printer.register_value("temperature", _content._temperature, "K");
    printer.register_value("pressure", _content._pressure, "Pa");
    printer.register_value("checksum", _content._checksum);

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
