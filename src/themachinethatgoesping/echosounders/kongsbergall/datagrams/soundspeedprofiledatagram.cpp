// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "soundspeedprofiledatagram.hpp"

#include <fmt/format.h>

#include <stdexcept>
#include <utility>
#include <xtensor/containers/xadapt.hpp>
#include <xtensor/views/xview.hpp>

#include <themachinethatgoesping/tools/timeconv.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

SoundSpeedProfileDatagram::SoundSpeedProfileDatagram(KongsbergAllDatagram header)
	: KongsbergAllDatagram(std::move(header))
{
}

SoundSpeedProfileDatagram::SoundSpeedProfileDatagram()
{
	_datagram_identifier = t_KongsbergAllDatagramIdentifier::SoundSpeedProfileDatagram;
}

uint16_t SoundSpeedProfileDatagram::get_profile_counter() const
{
	return _profile_counter;
}

uint16_t SoundSpeedProfileDatagram::get_system_serial_number() const
{
	return _system_serial_number;
}

uint32_t SoundSpeedProfileDatagram::get_profile_date() const
{
	return _profile_date;
}

uint32_t SoundSpeedProfileDatagram::get_profile_time_since_midnight() const
{
	return _profile_time_since_midnight;
}

uint16_t SoundSpeedProfileDatagram::get_number_of_entries() const
{
	return _number_of_entries;
}

uint16_t SoundSpeedProfileDatagram::get_depth_resolution() const
{
	return _depth_resolution;
}

uint8_t SoundSpeedProfileDatagram::get_spare() const
{
	return _spare;
}

uint8_t SoundSpeedProfileDatagram::get_etx() const
{
	return _etx;
}

uint16_t SoundSpeedProfileDatagram::get_checksum() const
{
	return _checksum;
}

void SoundSpeedProfileDatagram::set_profile_counter(uint16_t profile_counter)
{
	_profile_counter = profile_counter;
}

void SoundSpeedProfileDatagram::set_system_serial_number(uint16_t system_serial_number)
{
	_system_serial_number = system_serial_number;
}

void SoundSpeedProfileDatagram::set_profile_date(uint32_t profile_date)
{
	_profile_date = profile_date;
}

void SoundSpeedProfileDatagram::set_profile_time_since_midnight(uint32_t profile_time_since_midnight)
{
	_profile_time_since_midnight = profile_time_since_midnight;
}

void SoundSpeedProfileDatagram::set_number_of_entries(int32_t number_of_entries)
{
	_number_of_entries = static_cast<uint16_t>(number_of_entries);
}

void SoundSpeedProfileDatagram::set_depth_resolution(uint16_t depth_resolution)
{
	_depth_resolution = depth_resolution;
}

void SoundSpeedProfileDatagram::set_spare(uint8_t spare)
{
	_spare = spare;
}

void SoundSpeedProfileDatagram::set_etx(uint8_t etx)
{
	_etx = etx;
}

void SoundSpeedProfileDatagram::set_checksum(uint16_t checksum)
{
	_checksum = checksum;
}

xt::xtensor<uint32_t, 2>& SoundSpeedProfileDatagram::depths_and_sound_speeds()
{
	return _depths_and_sound_speeds;
}

const xt::xtensor<uint32_t, 2>& SoundSpeedProfileDatagram::get_depths_and_sound_speeds() const
{
	return _depths_and_sound_speeds;
}

void SoundSpeedProfileDatagram::set_depths_and_sound_speeds(
	const xt::xtensor<uint32_t, 2>& depths_and_sound_speeds)
{
	_depths_and_sound_speeds = depths_and_sound_speeds;
}

float SoundSpeedProfileDatagram::get_depth_resolution_in_meters() const
{
	return _depth_resolution * 0.01F;
}

xt::xtensor<double, 1> SoundSpeedProfileDatagram::get_depths_in_meters() const
{
	return xt::xtensor<double, 1>(xt::view(_depths_and_sound_speeds, xt::all(), 0) * 0.01);
}

xt::xtensor<float, 1> SoundSpeedProfileDatagram::get_sound_speeds_in_meters_per_second() const
{
	return xt::xtensor<float, 1>(xt::view(_depths_and_sound_speeds, xt::all(), 1) * 0.1F);
}

double SoundSpeedProfileDatagram::get_profile_timestamp() const
{
	int y = static_cast<int>(_profile_date / 10000);
	int m = static_cast<int>(_profile_date / 100) - y * 100;
	int d = static_cast<int>(_profile_date) - y * 10000 - m * 100;

	return tools::timeconv::year_month_day_to_unixtime(
	    y, m, d, static_cast<uint64_t>(_profile_time_since_midnight) * 1000);
}

std::string SoundSpeedProfileDatagram::get_profile_date_string(
	unsigned int fractionalSecondsDigits, const std::string& format) const
{
	return tools::timeconv::unixtime_to_datestring(
	    get_profile_timestamp(), fractionalSecondsDigits, format);
}

SoundSpeedProfileDatagram SoundSpeedProfileDatagram::from_stream(std::istream&       is,
	                                                             KongsbergAllDatagram header)
{
	SoundSpeedProfileDatagram datagram(std::move(header));

	if (datagram._datagram_identifier !=
	    t_KongsbergAllDatagramIdentifier::SoundSpeedProfileDatagram)
		throw std::runtime_error(fmt::format(
		    "SoundSpeedProfileDatagram: datagram identifier is not 0x{:02x}, but 0x{:02x}",
		    uint8_t(t_KongsbergAllDatagramIdentifier::SoundSpeedProfileDatagram),
		    uint8_t(datagram._datagram_identifier)));

	is.read(reinterpret_cast<char*>(&(datagram._profile_counter)),
	        static_cast<std::streamsize>(16 * sizeof(uint8_t)));

	if (datagram._number_of_entries > 0)
	{
		datagram._depths_and_sound_speeds = xt::empty<uint32_t>(
		    xt::xtensor<uint32_t, 2>::shape_type({ datagram._number_of_entries, 2 }));

		is.read(reinterpret_cast<char*>(datagram._depths_and_sound_speeds.data()),
		        static_cast<std::streamsize>(
		            datagram._depths_and_sound_speeds.size() * sizeof(uint32_t)));
	}
	else
	{
		datagram._depths_and_sound_speeds = xt::xtensor<uint32_t, 2>::from_shape({ 0u, 2u });
	}

	is.read(reinterpret_cast<char*>(&(datagram._spare)),
	        static_cast<std::streamsize>(4 * sizeof(uint8_t)));

	if (datagram._etx != 0x03)
		throw std::runtime_error(fmt::format(
		    "SoundSpeedProfileDatagram: end identifier is not 0x03, but 0x{:x}", datagram._etx));

	return datagram;
}

SoundSpeedProfileDatagram SoundSpeedProfileDatagram::from_stream(std::istream& is)
{
	return from_stream(is, KongsbergAllDatagram::from_stream(is));
}

SoundSpeedProfileDatagram SoundSpeedProfileDatagram::from_stream(
	std::istream&              is,
	t_KongsbergAllDatagramIdentifier datagram_identifier)
{
	return from_stream(is, KongsbergAllDatagram::from_stream(is, datagram_identifier));
}

void SoundSpeedProfileDatagram::to_stream(std::ostream& os) const
{
	if (_number_of_entries != _depths_and_sound_speeds.shape()[0])
		throw std::runtime_error(
		    fmt::format("SoundSpeedProfileDatagram: number of entries ({}) does not match the "
		                "size of the depths_and_sound_speeds array ({})",
		                _number_of_entries,
		                _depths_and_sound_speeds.shape()[0]));

	KongsbergAllDatagram::to_stream(os);

	os.write(reinterpret_cast<const char*>(&(_profile_counter)),
	         static_cast<std::streamsize>(16 * sizeof(uint8_t)));

	os.write(reinterpret_cast<const char*>(_depths_and_sound_speeds.data()),
	         static_cast<std::streamsize>(
	             _depths_and_sound_speeds.size() * sizeof(uint32_t)));

	os.write(reinterpret_cast<const char*>(&(_spare)),
	         static_cast<std::streamsize>(4 * sizeof(uint8_t)));
}

tools::classhelper::ObjectPrinter SoundSpeedProfileDatagram::__printer__(
	unsigned int float_precision, bool superscript_exponents) const
{
	using tools::timeconv::unixtime_to_datestring;

	static const std::string format_date("%d/%m/%Y");
	static const std::string format_time("%H:%M:%S");
	auto                     timestamp = get_profile_timestamp();

	auto date = unixtime_to_datestring(timestamp, 0, format_date);
	auto time = unixtime_to_datestring(timestamp, 3, format_time);

	tools::classhelper::ObjectPrinter printer(
	    "SoundSpeedProfileDatagram", float_precision, superscript_exponents);

	printer.append(KongsbergAllDatagram::__printer__(float_precision, superscript_exponents));
	printer.register_section("datagram content");
	printer.register_value("profile_counter", _profile_counter);
	printer.register_value("system_serial_number", _system_serial_number);
	printer.register_value("number_of_entries", _number_of_entries);
	printer.register_value("depth_resolution", _depth_resolution, "cm");

	printer.register_section("processed");
	printer.register_value("profile_timestamp", timestamp, "s");
	printer.register_string("profile_date", date, "MM/DD/YYYY");
	printer.register_string("profile_time", time, "HH:MM:SS");
	printer.register_value("depth_resolution", get_depth_resolution_in_meters(), "m");
	printer.register_container("meters", get_depths_in_meters(), "s");
	printer.register_container("sound_speeds", get_sound_speeds_in_meters_per_second(), "°");

	printer.register_section("substructures");
	printer.register_container("depths_and_sound_speeds", _depths_and_sound_speeds);

	return printer;
}

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
