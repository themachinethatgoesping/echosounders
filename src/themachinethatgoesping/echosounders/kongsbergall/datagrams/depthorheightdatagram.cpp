// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "depthorheightdatagram.hpp"

#include <fmt/format.h>

#include <stdexcept>
#include <utility>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

DepthOrHeightDatagram::DepthOrHeightDatagram(KongsbergAllDatagram header)
	: KongsbergAllDatagram(std::move(header))
{
}

DepthOrHeightDatagram::DepthOrHeightDatagram()
{
	_datagram_identifier = t_KongsbergAllDatagramIdentifier::DepthOrHeightDatagram;
}

uint16_t DepthOrHeightDatagram::get_height_counter() const
{
	return _height_counter;
}

uint16_t DepthOrHeightDatagram::get_system_serial_number() const
{
	return _system_serial_number;
}

int32_t DepthOrHeightDatagram::get_height() const
{
	return _height;
}

uint8_t DepthOrHeightDatagram::get_height_type() const
{
	return _height_type;
}

uint8_t DepthOrHeightDatagram::get_etx() const
{
	return _etx;
}

uint16_t DepthOrHeightDatagram::get_checksum() const
{
	return _checksum;
}

void DepthOrHeightDatagram::set_height_counter(uint16_t height_counter)
{
	_height_counter = height_counter;
}

void DepthOrHeightDatagram::set_system_serial_number(uint16_t system_serial_number)
{
	_system_serial_number = system_serial_number;
}

void DepthOrHeightDatagram::set_height(int32_t height)
{
	_height = height;
}

void DepthOrHeightDatagram::set_height_type(uint8_t height_type)
{
	_height_type = height_type;
}

void DepthOrHeightDatagram::set_etx(uint8_t etx)
{
	_etx = etx;
}

void DepthOrHeightDatagram::set_checksum(uint16_t checksum)
{
	_checksum = checksum;
}

float DepthOrHeightDatagram::get_height_in_meters() const
{
	return _height * 0.01F;
}

std::string DepthOrHeightDatagram::get_height_type_explained() const
{
	if (_height_type == 0)
	{
		return "The height is derived from the GGK or GGA datagram and is the height of the "
			   "water level at the vertical datum (possibly motion corrected). \n height is "
			   "derived from the active position system only.";
	}
	if (_height_type <= 99)
	{
		return "The height type is as given in the Depth (pressure) or height input datagram";
	}
	if (_height_type == 100)
	{
		return "The input is depth taken from the OwnShipsData/S90.";
	}
	if (_height_type == 200)
	{
		return "Input from depth sensor.";
	}

	return "Unknown height type";
}

DepthOrHeightDatagram DepthOrHeightDatagram::from_stream(std::istream& is, KongsbergAllDatagram header)
{
	DepthOrHeightDatagram datagram(std::move(header));

	if (datagram._datagram_identifier != t_KongsbergAllDatagramIdentifier::DepthOrHeightDatagram)
		throw std::runtime_error(fmt::format(
			"DepthOrHeightDatagram: datagram identifier is not 0x{:02x}, but 0x{:02x}",
			uint8_t(t_KongsbergAllDatagramIdentifier::DepthOrHeightDatagram),
			uint8_t(datagram._datagram_identifier)));

	is.read(reinterpret_cast<char*>(&(datagram._height_counter)), 12 * sizeof(uint8_t));

	if (datagram._etx != 0x03)
		throw std::runtime_error(fmt::format(
			"DepthOrHeightDatagram: end identifier is not 0x03, but 0x{:x}", datagram._etx));

	return datagram;
}

DepthOrHeightDatagram DepthOrHeightDatagram::from_stream(std::istream& is)
{
	return from_stream(is, KongsbergAllDatagram::from_stream(is));
}

DepthOrHeightDatagram DepthOrHeightDatagram::from_stream(
	std::istream&              is,
	t_KongsbergAllDatagramIdentifier datagram_identifier)
{
	return from_stream(is, KongsbergAllDatagram::from_stream(is, datagram_identifier));
}

void DepthOrHeightDatagram::to_stream(std::ostream& os)
{
	KongsbergAllDatagram::to_stream(os);

	os.write(reinterpret_cast<const char*>(&(_height_counter)), 12 * sizeof(uint8_t));
}

tools::classhelper::ObjectPrinter DepthOrHeightDatagram::__printer__(unsigned int float_precision,
																	 bool         superscript_exponents) const
{
	tools::classhelper::ObjectPrinter printer(
		"DepthOrHeightDatagram", float_precision, superscript_exponents);

	printer.append(KongsbergAllDatagram::__printer__(float_precision, superscript_exponents));
	printer.register_section("datagram content");
	printer.register_value("height_counter", _height_counter);
	printer.register_value("system_serial_number", _system_serial_number);
	printer.register_value("height", _height, "cm");
	printer.register_value("height_type", _height_type);
	printer.register_string("etx", fmt::format("0x{:02x}", _etx));
	printer.register_value("checksum", _checksum);

	printer.register_section("processed");
	printer.register_value("height", get_height_in_meters(), "m");
	printer.register_string("height_type", get_height_type_explained());
	return printer;
}

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
