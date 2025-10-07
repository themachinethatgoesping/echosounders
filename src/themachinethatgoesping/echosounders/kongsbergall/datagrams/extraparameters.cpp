// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "extraparameters.hpp"

#include <fmt/format.h>

#include <istream>
#include <ostream>
#include <stdexcept>
#include <utility>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

ExtraParameters::ExtraParameters() { _datagram_identifier = DatagramIdentifier; }

ExtraParameters::ExtraParameters(KongsbergAllDatagram header)
    : KongsbergAllDatagram(std::move(header))
{
}

uint16_t ExtraParameters::get_ping_counter() const { return _ping_counter; }

uint16_t ExtraParameters::get_system_serial_number() const { return _system_serial_number; }

ExtraParameters::t_ContentIdentifier ExtraParameters::get_content_identifier() const
{
    return _content_identifier;
}

std::string ExtraParameters::get_raw_content() const { return _raw_content; }

uint8_t ExtraParameters::get_spare() const { return _spare; }

uint8_t ExtraParameters::get_etx() const { return _etx; }

uint16_t ExtraParameters::get_checksum() const { return _checksum; }

void ExtraParameters::set_ping_counter(uint16_t ping_counter) { _ping_counter = ping_counter; }

void ExtraParameters::set_system_serial_number(uint16_t system_serial_number)
{
    _system_serial_number = system_serial_number;
}

void ExtraParameters::set_content_identifier(t_ContentIdentifier content_identifier)
{
    _content_identifier = content_identifier;
}

void ExtraParameters::set_raw_content(std::string raw_content)
{
    _raw_content = std::move(raw_content);
}

void ExtraParameters::set_spare(uint8_t spare) { _spare = spare; }

void ExtraParameters::set_checksum(uint16_t checksum) { _checksum = checksum; }

void ExtraParameters::set_etx(uint8_t etx) { _etx = etx; }

ExtraParameters ExtraParameters::from_stream(std::istream& is, KongsbergAllDatagram header)
{
    ExtraParameters datagram(std::move(header));

    if (datagram._datagram_identifier != DatagramIdentifier)
        throw std::runtime_error(fmt::format(
            "ExtraParameters: datagram identifier is not 0x{:02x}, but 0x{:02x}",
            static_cast<uint8_t>(DatagramIdentifier),
            static_cast<uint8_t>(datagram._datagram_identifier)));

    is.read(reinterpret_cast<char*>(&datagram._ping_counter), 6 * sizeof(uint8_t));

    constexpr uint8_t header_bytes = sizeof(uint8_t) * 22;

    datagram._raw_content.resize(datagram.get_bytes() - header_bytes);
    is.read(reinterpret_cast<char*>(datagram._raw_content.data()), datagram._raw_content.size());

    is.read(reinterpret_cast<char*>(&datagram._spare), 4 * sizeof(uint8_t));

    if (datagram._etx != 0x03)
        throw std::runtime_error(fmt::format(
            "ExtraParameters: end identifier is not 0x03, but 0x{:x}", datagram._etx));

    return datagram;
}

ExtraParameters ExtraParameters::from_stream(std::istream& is)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is));
}

ExtraParameters ExtraParameters::from_stream(std::istream&                    is,
                                            t_KongsbergAllDatagramIdentifier datagram_identifier)
{
    return from_stream(is, KongsbergAllDatagram::from_stream(is, datagram_identifier));
}

void ExtraParameters::to_stream(std::ostream& os)
{
    if (_bytes - 22 != _raw_content.size())
        throw std::runtime_error(fmt::format(
            "ExtraParameters: bytes - 22 ({}) does not match the size of the _raw_content string ({})",
            _bytes - 22,
            _raw_content.size()));

    KongsbergAllDatagram::to_stream(os);

    os.write(reinterpret_cast<const char*>(&_ping_counter), 6 * sizeof(uint8_t));

    os.write(reinterpret_cast<const char*>(_raw_content.data()),
             _raw_content.size() * sizeof(uint8_t));

    os.write(reinterpret_cast<const char*>(&_spare), 4 * sizeof(uint8_t));
}

tools::classhelper::ObjectPrinter ExtraParameters::__printer__(unsigned int float_precision,
                                                               bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "ExtraParameters", float_precision, superscript_exponents);

    printer.append(KongsbergAllDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("datagram content");
    printer.register_value("ping_counter", _ping_counter);
    printer.register_value("system_serial_number", _system_serial_number);
    printer.register_enum("content_identifier", _content_identifier);
    printer.register_value("raw_content", _raw_content.size(), "bytes");
    printer.register_string("etx", fmt::format("0x{:02x}", _etx));
    printer.register_value("checksum", _checksum);

    return printer;
}

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping

template class themachinethatgoesping::tools::classhelper::Option<
    themachinethatgoesping::echosounders::kongsbergall::datagrams::ExtraParameters::
        t_ContentIdentifier>;