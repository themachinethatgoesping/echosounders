// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "soundvelocity.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

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
    const auto& o_datagram_identifier = S7KDatagram::o_DatagramIdentifier(get_datagram_identifier());
    tools::classhelper::ObjectPrinter printer(
        fmt::format("S7KHeader {} ({})", o_datagram_identifier.name(), uint32_t(o_datagram_identifier)),
        float_precision,
        superscript_exponents);

    printer.append(S7KDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("SoundVelocity content");
    printer.register_value("sound_velocity", _content.sound_velocity, "m/s");

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
