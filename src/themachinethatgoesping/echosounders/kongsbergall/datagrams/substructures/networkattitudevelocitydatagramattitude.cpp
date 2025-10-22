// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "networkattitudevelocitydatagramattitude.hpp"

#include <istream>
#include <ostream>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

float NetworkAttitudeVelocityDatagramAttitude::get_time() const
{
	return static_cast<float>(_time);
}

int16_t NetworkAttitudeVelocityDatagramAttitude::get_roll() const
{
	return _roll;
}

int16_t NetworkAttitudeVelocityDatagramAttitude::get_pitch() const
{
	return _pitch;
}

int16_t NetworkAttitudeVelocityDatagramAttitude::get_heave() const
{
	return _heave;
}

uint16_t NetworkAttitudeVelocityDatagramAttitude::get_heading() const
{
	return _heading;
}

uint16_t NetworkAttitudeVelocityDatagramAttitude::get_number_of_bytes_in_input_datagram() const
{
	return _number_of_bytes_in_input_datagram;
}

const std::string& NetworkAttitudeVelocityDatagramAttitude::get_input_datagram() const
{
	return _input_datagram;
}

void NetworkAttitudeVelocityDatagramAttitude::set_time(uint16_t time)
{
	_time = time;
}

void NetworkAttitudeVelocityDatagramAttitude::set_roll(int16_t roll)
{
	_roll = roll;
}

void NetworkAttitudeVelocityDatagramAttitude::set_pitch(int16_t pitch)
{
	_pitch = pitch;
}

void NetworkAttitudeVelocityDatagramAttitude::set_heave(int16_t heave)
{
	_heave = heave;
}

void NetworkAttitudeVelocityDatagramAttitude::set_heading(uint16_t heading)
{
	_heading = heading;
}

void NetworkAttitudeVelocityDatagramAttitude::set_number_of_bytes_in_input_datagram(
	uint8_t number_of_bytes_in_input_datagram)
{
	_number_of_bytes_in_input_datagram = number_of_bytes_in_input_datagram;
}

void NetworkAttitudeVelocityDatagramAttitude::set_input_datagram(const std::string& input_datagram)
{
	_input_datagram = input_datagram;
}

float NetworkAttitudeVelocityDatagramAttitude::get_time_in_seconds() const
{
	return static_cast<float>(_time) * 0.001f;
}

float NetworkAttitudeVelocityDatagramAttitude::get_roll_in_degrees() const
{
	return static_cast<float>(_roll) * 0.01f;
}

float NetworkAttitudeVelocityDatagramAttitude::get_pitch_in_degrees() const
{
	return static_cast<float>(_pitch) * 0.01f;
}

float NetworkAttitudeVelocityDatagramAttitude::get_heave_in_meters() const
{
	return static_cast<float>(_heave) * 0.01f;
}

float NetworkAttitudeVelocityDatagramAttitude::get_heading_in_degrees() const
{
	return static_cast<float>(_heading) * 0.01f;
}

NetworkAttitudeVelocityDatagramAttitude
NetworkAttitudeVelocityDatagramAttitude::from_stream(std::istream& is)
{
	NetworkAttitudeVelocityDatagramAttitude data;

	is.read(reinterpret_cast<char*>(&(data._time)), 11 * sizeof(uint8_t));

	data._input_datagram.resize(data._number_of_bytes_in_input_datagram);
	is.read(reinterpret_cast<char*>(data._input_datagram.data()),
			static_cast<std::streamsize>(data._input_datagram.size() * sizeof(char)));

	return data;
}

void NetworkAttitudeVelocityDatagramAttitude::to_stream(std::ostream& os)
{
	_number_of_bytes_in_input_datagram = static_cast<uint8_t>(_input_datagram.size());

	os.write(reinterpret_cast<const char*>(&(_time)), 11 * sizeof(uint8_t));

	os.write(reinterpret_cast<const char*>(_input_datagram.data()),
			 static_cast<std::streamsize>(_input_datagram.size() * sizeof(char)));
}

tools::classhelper::ObjectPrinter
NetworkAttitudeVelocityDatagramAttitude::__printer__(unsigned int float_precision,
													 bool         superscript_exponents) const
{
	tools::classhelper::ObjectPrinter printer(
		"NetworkAttitudeVelocityDatagramAttitude", float_precision, superscript_exponents);

	printer.register_value("time", _time, "ms");
	printer.register_value("roll", _roll, "0.01°");
	printer.register_value("pitch", _pitch, "0.01°");
	printer.register_value("heave", _heave, "cm°");
	printer.register_value("heading", _heading, "0.01°");
	printer.register_value("number_of_bytes_in_input_datagram",
						   _number_of_bytes_in_input_datagram);
	printer.register_value("input_datagram", _input_datagram.size(), "bytes");

	printer.register_section("processed");
	printer.register_value("roll", get_roll_in_degrees(), "°");
	printer.register_value("pitch", get_pitch_in_degrees(), "°");
	printer.register_value("heave", get_heave_in_meters(), "m");
	printer.register_value("heading", get_heading_in_degrees(), "°");

	return printer;
}

} // namespace substructures
} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
