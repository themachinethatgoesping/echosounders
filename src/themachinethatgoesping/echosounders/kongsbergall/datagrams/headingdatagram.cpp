// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "headingdatagram.hpp"

#include <fmt/format.h>

#include <stdexcept>
#include <utility>
#include <xtensor/containers/xadapt.hpp>
#include <xtensor/views/xview.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {

HeadingDatagram::HeadingDatagram(KongsbergAllDatagram header)
	: KongsbergAllDatagram(std::move(header))
{
}

HeadingDatagram::HeadingDatagram()
{
	_datagram_identifier = t_KongsbergAllDatagramIdentifier::HeadingDatagram;
}

uint16_t HeadingDatagram::get_heading_counter() const
{
	return _heading_counter;
}

uint16_t HeadingDatagram::get_system_serial_number() const
{
	return _system_serial_number;
}

uint16_t HeadingDatagram::get_number_of_entries() const
{
	return _number_of_entries;
}

uint8_t HeadingDatagram::get_heading_indicator() const
{
	return _heading_indicator;
}

uint8_t HeadingDatagram::get_etx() const
{
	return _etx;
}

uint16_t HeadingDatagram::get_checksum() const
{
	return _checksum;
}

void HeadingDatagram::set_heading_counter(uint16_t heading_counter)
{
	_heading_counter = heading_counter;
}

void HeadingDatagram::set_system_serial_number(uint16_t system_serial_number)
{
	_system_serial_number = system_serial_number;
}

void HeadingDatagram::set_number_of_entries(int32_t number_of_entries)
{
	_number_of_entries = static_cast<uint16_t>(number_of_entries);
}

void HeadingDatagram::set_heading_indicator(uint8_t heading_indicator)
{
	_heading_indicator = heading_indicator;
}

void HeadingDatagram::set_etx(uint8_t etx)
{
	_etx = etx;
}

void HeadingDatagram::set_checksum(uint16_t checksum)
{
	_checksum = checksum;
}

xt::xtensor<uint16_t, 2>& HeadingDatagram::times_and_headings()
{
	return _times_and_headings;
}

const xt::xtensor<uint16_t, 2>& HeadingDatagram::get_times_and_headings() const
{
	return _times_and_headings;
}

void HeadingDatagram::set_times_and_headings(const xt::xtensor<uint16_t, 2>& times_and_headings)
{
	_times_and_headings = times_and_headings;
}

xt::xtensor<double, 1> HeadingDatagram::get_heading_timestamps() const
{
	const double timestamp = get_timestamp();
	return xt::xtensor<double, 1>(xt::view(_times_and_headings, xt::all(), 0) * 0.001 + timestamp);
}

xt::xtensor<float, 1> HeadingDatagram::get_headings_in_degrees() const
{
	return xt::xtensor<float, 1>(xt::view(_times_and_headings, xt::all(), 1) * 0.01F);
}

HeadingDatagram HeadingDatagram::from_stream(std::istream& is, KongsbergAllDatagram header)
{
	HeadingDatagram datagram(std::move(header));

	if (datagram._datagram_identifier != t_KongsbergAllDatagramIdentifier::HeadingDatagram)
		throw std::runtime_error(
			fmt::format("HeadingDatagram: datagram identifier is not 0x{:02x}, but 0x{:02x}",
						uint8_t(t_KongsbergAllDatagramIdentifier::HeadingDatagram),
						uint8_t(datagram._datagram_identifier)));

	is.read(reinterpret_cast<char*>(&(datagram._heading_counter)), 6 * sizeof(uint8_t));

	if (datagram._number_of_entries > 0)
	{
		datagram._times_and_headings = xt::empty<uint16_t>(
			xt::xtensor<uint16_t, 2>::shape_type({ datagram._number_of_entries, 2 }));

		is.read(reinterpret_cast<char*>(datagram._times_and_headings.data()),
				static_cast<std::streamsize>(datagram._times_and_headings.size() * sizeof(uint16_t)));
	}
	else
	{
		datagram._times_and_headings = xt::xtensor<uint16_t, 2>::from_shape({ 0u, 2u });
	}

	is.read(reinterpret_cast<char*>(&(datagram._heading_indicator)), 4 * sizeof(uint8_t));

	if (datagram._etx != 0x03)
		throw std::runtime_error(
			fmt::format("HeadingDatagram: end identifier is not 0x03, but 0x{:x}", datagram._etx));

	return datagram;
}

HeadingDatagram HeadingDatagram::from_stream(std::istream& is)
{
	return from_stream(is, KongsbergAllDatagram::from_stream(is));
}

HeadingDatagram HeadingDatagram::from_stream(std::istream&              is,
											 t_KongsbergAllDatagramIdentifier datagram_identifier)
{
	return from_stream(is, KongsbergAllDatagram::from_stream(is, datagram_identifier));
}

void HeadingDatagram::to_stream(std::ostream& os) const
{
	if (_number_of_entries != _times_and_headings.shape()[0])
		throw std::runtime_error(
			fmt::format("HeadingDatagram: number of entries ({}) does not match the size of the "
						"times_and_headings array ({})",
						_number_of_entries,
						_times_and_headings.shape()[0]));

	KongsbergAllDatagram::to_stream(os);

	os.write(reinterpret_cast<const char*>(&(_heading_counter)), 6 * sizeof(uint8_t));

	os.write(reinterpret_cast<const char*>(_times_and_headings.data()),
			 static_cast<std::streamsize>(_times_and_headings.size() * sizeof(uint16_t)));

	os.write(reinterpret_cast<const char*>(&(_heading_indicator)), 4 * sizeof(uint8_t));
}

tools::classhelper::ObjectPrinter HeadingDatagram::__printer__(unsigned int float_precision,
															   bool superscript_exponents) const
{
	tools::classhelper::ObjectPrinter printer(
		"HeadingDatagram", float_precision, superscript_exponents);

	printer.append(KongsbergAllDatagram::__printer__(float_precision, superscript_exponents));
	printer.register_section("datagram content");
	printer.register_value("heading_counter", _heading_counter);
	printer.register_value("system_serial_number", _system_serial_number);
	printer.register_value("number_of_entries", _number_of_entries);

	printer.register_section("processed");
	printer.register_container("heading_timestamps", get_heading_timestamps(), "s");
	printer.register_container("headings", get_headings_in_degrees(), "°");

	printer.register_section("substructures");
	printer.register_container("times_and_headings", _times_and_headings);

	return printer;
}

} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
