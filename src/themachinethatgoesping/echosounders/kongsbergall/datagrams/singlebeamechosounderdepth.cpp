// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "singlebeamechosounderdepth.hpp"

#include <fmt/format.h>

#include <stdexcept>
#include <utility>

#include <themachinethatgoesping/tools/timeconv.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

SingleBeamEchoSounderDepth::SingleBeamEchoSounderDepth(KongsbergAllDatagram header)
	: KongsbergAllDatagram(std::move(header))
{
}

SingleBeamEchoSounderDepth::SingleBeamEchoSounderDepth()
{
	_datagram_identifier = t_KongsbergAllDatagramIdentifier::SingleBeamEchoSounderDepth;
}

uint16_t SingleBeamEchoSounderDepth::get_echo_sounder_counter() const
{
	return _echo_sounder_counter;
}

uint16_t SingleBeamEchoSounderDepth::get_system_serial_number() const
{
	return _system_serial_number;
}

uint32_t SingleBeamEchoSounderDepth::get_input_date() const
{
	return _input_date;
}

uint32_t SingleBeamEchoSounderDepth::get_input_time_since_midnight() const
{
	return _input_time_since_midnight;
}

uint32_t SingleBeamEchoSounderDepth::get_echo_sounder_depth() const
{
	return _echo_sounder_depth;
}

char SingleBeamEchoSounderDepth::get_source_identifier() const
{
	return _source_identifier;
}

uint8_t SingleBeamEchoSounderDepth::get_etx() const
{
	return _etx;
}

uint16_t SingleBeamEchoSounderDepth::get_checksum() const
{
	return _checksum;
}

void SingleBeamEchoSounderDepth::set_echo_sounder_counter(uint16_t echo_sounder_counter)
{
	_echo_sounder_counter = echo_sounder_counter;
}

void SingleBeamEchoSounderDepth::set_system_serial_number(uint16_t system_serial_number)
{
	_system_serial_number = system_serial_number;
}

void SingleBeamEchoSounderDepth::set_input_date(uint32_t date)
{
	_input_date = date;
}

void SingleBeamEchoSounderDepth::set_input_time_since_midnight(uint32_t time)
{
	_input_time_since_midnight = time;
}

void SingleBeamEchoSounderDepth::set_echo_sounder_depth(uint32_t echo_sounder_depth)
{
	_echo_sounder_depth = echo_sounder_depth;
}

void SingleBeamEchoSounderDepth::set_source_identifier(char source_identifier)
{
	_source_identifier = source_identifier;
}

void SingleBeamEchoSounderDepth::set_etx(uint8_t etx)
{
	_etx = etx;
}

void SingleBeamEchoSounderDepth::set_checksum(uint16_t checksum)
{
	_checksum = checksum;
}

double SingleBeamEchoSounderDepth::get_input_timestamp() const
{
	int y = static_cast<int>(_input_date / 10000);
	int m = static_cast<int>(_input_date / 100) - y * 100;
	int d = static_cast<int>(_input_date) - y * 10000 - m * 100;

	return tools::timeconv::year_month_day_to_unixtime(
		y, m, d, static_cast<uint64_t>(_input_time_since_midnight) * 1000);
}

std::string SingleBeamEchoSounderDepth::get_input_date_string(
	unsigned int       fractionalSecondsDigits,
	const std::string& format) const
{
	return tools::timeconv::unixtime_to_datestring(
		get_input_timestamp(), fractionalSecondsDigits, format);
}

float SingleBeamEchoSounderDepth::get_echo_sounder_depth_in_meters() const
{
	return _echo_sounder_depth * 0.01F;
}

SingleBeamEchoSounderDepth SingleBeamEchoSounderDepth::from_stream(std::istream& is,
																   KongsbergAllDatagram header)
{
	SingleBeamEchoSounderDepth datagram(std::move(header));

	if (datagram._datagram_identifier !=
		t_KongsbergAllDatagramIdentifier::SingleBeamEchoSounderDepth)
		throw std::runtime_error(fmt::format(
			"SingleBeamEchoSounderDepth: datagram identifier is not 0x{:02x}, but 0x{:02x}",
			uint8_t(t_KongsbergAllDatagramIdentifier::SingleBeamEchoSounderDepth),
			uint8_t(datagram._datagram_identifier)));

	is.read(reinterpret_cast<char*>(&(datagram._echo_sounder_counter)), 20 * sizeof(uint8_t));

	if (datagram._etx != 0x03)
		throw std::runtime_error(fmt::format(
			"SingleBeamEchoSounderDepth: end identifier is not 0x03, but 0x{:x}",
			datagram._etx));

	return datagram;
}

SingleBeamEchoSounderDepth SingleBeamEchoSounderDepth::from_stream(std::istream& is)
{
	return from_stream(is, KongsbergAllDatagram::from_stream(is));
}

SingleBeamEchoSounderDepth SingleBeamEchoSounderDepth::from_stream(
	std::istream&              is,
	t_KongsbergAllDatagramIdentifier datagram_identifier)
{
	return from_stream(is, KongsbergAllDatagram::from_stream(is, datagram_identifier));
}

void SingleBeamEchoSounderDepth::to_stream(std::ostream& os)
{
	KongsbergAllDatagram::to_stream(os);

	os.write(reinterpret_cast<const char*>(&(_echo_sounder_counter)), 20 * sizeof(uint8_t));
}

tools::classhelper::ObjectPrinter SingleBeamEchoSounderDepth::__printer__(
	unsigned int float_precision,
	bool         superscript_exponents) const
{
	using tools::timeconv::unixtime_to_datestring;

	static const std::string format_date("%d/%m/%Y");
	static const std::string format_time("%H:%M:%S");
	auto                     timestamp = get_input_timestamp();

	auto date = unixtime_to_datestring(timestamp, 0, format_date);
	auto time = unixtime_to_datestring(timestamp, 3, format_time);

	tools::classhelper::ObjectPrinter printer(
		"SingleBeamEchoSounderDepth", float_precision, superscript_exponents);

	printer.append(KongsbergAllDatagram::__printer__(float_precision, superscript_exponents));
	printer.register_section("datagram content");
	printer.register_value("echo_sounder_counter", _echo_sounder_counter);
	printer.register_value("system_serial_number", _system_serial_number);
	printer.register_value("input_date", _input_date, "YYYYMMDD");
	printer.register_value("input_time_since_midnight", _input_time_since_midnight, "ms");
	printer.register_value("echo_sounder_depth", _echo_sounder_depth, "m");

	printer.register_string("etx", fmt::format("0x{:02x}", _etx));
	printer.register_value("checksum", _checksum);

	printer.register_section("processed");
	printer.register_value("input_timestamp", timestamp, "s");
	printer.register_string("input_date", date, "MM/DD/YYYY");
	printer.register_string("input_time", time, "HH:MM:SS");
	printer.register_value("echo_sounder_depth", get_echo_sounder_depth_in_meters(), "m");
	return printer;
}

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
