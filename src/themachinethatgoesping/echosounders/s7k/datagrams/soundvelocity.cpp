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
uint32_t SoundVelocity::get_checksum() const
{
    return _content._checksum;
}

void SoundVelocity::set_sound_velocity(float val)
{
    _content._sound_velocity = val;
}
void SoundVelocity::set_checksum(uint32_t val)
{
    _content._checksum = val;
}

// ----- to/from stream functions -----
void SoundVelocity::__read__(std::istream& is)
{
    is.read(reinterpret_cast<char*>(&_content), __content_size);
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
    os.write(reinterpret_cast<const char*>(&_content), __content_size);
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
    printer.register_value("checksum", _content._checksum);

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
