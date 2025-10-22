// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "surfacesoundspeeddatagram.hpp"

#include <fmt/format.h>

#include <stdexcept>
#include <utility>
#include <xtensor/containers/xadapt.hpp>
#include <xtensor/views/xview.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

SurfaceSoundSpeedDatagram::SurfaceSoundSpeedDatagram(KongsbergAllDatagram header)
	: KongsbergAllDatagram(std::move(header))
{
}

SurfaceSoundSpeedDatagram::SurfaceSoundSpeedDatagram()
{
	_datagram_identifier = t_KongsbergAllDatagramIdentifier::SurfaceSoundSpeedDatagram;
}

uint16_t SurfaceSoundSpeedDatagram::get_sound_speed_counter() const
{
	return _sound_speed_counter;
}

uint16_t SurfaceSoundSpeedDatagram::get_system_serial_number() const
{
	return _system_serial_number;
}

uint16_t SurfaceSoundSpeedDatagram::get_number_of_entries() const
{
	return _number_of_entries;
}

uint8_t SurfaceSoundSpeedDatagram::get_spare() const
{
	return _spare;
}

uint8_t SurfaceSoundSpeedDatagram::get_etx() const
{
	return _etx;
}

uint16_t SurfaceSoundSpeedDatagram::get_checksum() const
{
	return _checksum;
}

void SurfaceSoundSpeedDatagram::set_sound_speed_counter(uint16_t sound_speed_counter)
{
	_sound_speed_counter = sound_speed_counter;
}

void SurfaceSoundSpeedDatagram::set_system_serial_number(uint16_t system_serial_number)
{
	_system_serial_number = system_serial_number;
}

void SurfaceSoundSpeedDatagram::set_number_of_entries(int32_t number_of_entries)
{
	_number_of_entries = static_cast<uint16_t>(number_of_entries);
}

void SurfaceSoundSpeedDatagram::set_spare(uint8_t spare)
{
	_spare = spare;
}

void SurfaceSoundSpeedDatagram::set_etx(uint8_t etx)
{
	_etx = etx;
}

void SurfaceSoundSpeedDatagram::set_checksum(uint16_t checksum)
{
	_checksum = checksum;
}

xt::xtensor<uint16_t, 2>& SurfaceSoundSpeedDatagram::times_and_sound_speeds()
{
	return _times_and_sound_speeds;
}

const xt::xtensor<uint16_t, 2>& SurfaceSoundSpeedDatagram::get_times_and_sound_speeds() const
{
	return _times_and_sound_speeds;
}

void SurfaceSoundSpeedDatagram::set_times_and_sound_speeds(
	xt::xtensor<uint16_t, 2> times_and_sound_speeds)
{
	_times_and_sound_speeds = std::move(times_and_sound_speeds);
}

xt::xtensor<double, 1> SurfaceSoundSpeedDatagram::get_sound_speed_timestamps() const
{
	double timestamp = get_timestamp();
	return xt::xtensor<double, 1>(xt::view(_times_and_sound_speeds, xt::all(), 0) * 0.001 + timestamp);
}

xt::xtensor<float, 1> SurfaceSoundSpeedDatagram::get_sound_speeds_in_meters_per_second() const
{
	return xt::xtensor<float, 1>(xt::view(_times_and_sound_speeds, xt::all(), 1) * 0.1F);
}

SurfaceSoundSpeedDatagram SurfaceSoundSpeedDatagram::from_stream(std::istream& is,
																 KongsbergAllDatagram header)
{
	SurfaceSoundSpeedDatagram datagram(std::move(header));

	if (datagram._datagram_identifier !=
		t_KongsbergAllDatagramIdentifier::SurfaceSoundSpeedDatagram)
		throw std::runtime_error(fmt::format(
			"SurfaceSoundSpeedDatagram: datagram identifier is not 0x{:02x}, but 0x{:02x}",
			uint8_t(t_KongsbergAllDatagramIdentifier::SurfaceSoundSpeedDatagram),
			uint8_t(datagram._datagram_identifier)));

	is.read(reinterpret_cast<char*>(&(datagram._sound_speed_counter)), 6 * sizeof(uint8_t));

	if (datagram._number_of_entries > 0)
	{
		datagram._times_and_sound_speeds = xt::empty<uint16_t>(
			xt::xtensor<uint16_t, 2>::shape_type({ datagram._number_of_entries, 2 }));

		is.read(reinterpret_cast<char*>(datagram._times_and_sound_speeds.data()),
				static_cast<std::streamsize>(datagram._times_and_sound_speeds.size() * sizeof(uint16_t)));
	}
	else
	{
		datagram._times_and_sound_speeds = xt::xtensor<uint16_t, 2>::from_shape({ 0u, 2u });
	}

	is.read(reinterpret_cast<char*>(&(datagram._spare)), 4 * sizeof(uint8_t));

	if (datagram._etx != 0x03)
		throw std::runtime_error(fmt::format(
			"SurfaceSoundSpeedDatagram: end identifier is not 0x03, but 0x{:x}", datagram._etx));

	return datagram;
}

SurfaceSoundSpeedDatagram SurfaceSoundSpeedDatagram::from_stream(std::istream& is)
{
	return from_stream(is, KongsbergAllDatagram::from_stream(is));
}

SurfaceSoundSpeedDatagram SurfaceSoundSpeedDatagram::from_stream(
	std::istream&              is,
	t_KongsbergAllDatagramIdentifier datagram_identifier)
{
	return from_stream(is, KongsbergAllDatagram::from_stream(is, datagram_identifier));
}

void SurfaceSoundSpeedDatagram::to_stream(std::ostream& os) const
{
	if (_number_of_entries != _times_and_sound_speeds.shape()[0])
		throw std::runtime_error(
			fmt::format("SurfaceSoundSpeedDatagram: number of entries ({}) does not match the "
						"size of the times_and_sound_speeds array ({})",
						_number_of_entries,
						_times_and_sound_speeds.shape()[0]));

	KongsbergAllDatagram::to_stream(os);

	os.write(reinterpret_cast<const char*>(&(_sound_speed_counter)), 6 * sizeof(uint8_t));

	os.write(reinterpret_cast<const char*>(_times_and_sound_speeds.data()),
			 static_cast<std::streamsize>(_times_and_sound_speeds.size() * sizeof(uint16_t)));

	os.write(reinterpret_cast<const char*>(&(_spare)), 4 * sizeof(uint8_t));
}

tools::classhelper::ObjectPrinter SurfaceSoundSpeedDatagram::__printer__(
	unsigned int float_precision,
	bool         superscript_exponents) const
{
	tools::classhelper::ObjectPrinter printer(
		"SurfaceSoundSpeedDatagram", float_precision, superscript_exponents);

	printer.append(KongsbergAllDatagram::__printer__(float_precision, superscript_exponents));
	printer.register_section("datagram content");
	printer.register_value("sound_speed_counter", _sound_speed_counter);
	printer.register_value("system_serial_number", _system_serial_number);
	printer.register_value("number_of_entries", _number_of_entries);

	printer.register_section("processed");
	printer.register_container("sound_speed_timestamps", get_sound_speed_timestamps(), "s");
	printer.register_container(
		"sound_speeds", get_sound_speeds_in_meters_per_second(), "m");

	printer.register_section("substructures");
	printer.register_container("times_and_sound_speeds", _times_and_sound_speeds);

	return printer;
}

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
