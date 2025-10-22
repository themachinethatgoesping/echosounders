// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "attitudedatagramattitude.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

float AttitudeDatagramAttitude::get_time() const
{
	return static_cast<float>(_time);
}

uint16_t AttitudeDatagramAttitude::get_sensor_status() const
{
	return _sensor_status;
}

int16_t AttitudeDatagramAttitude::get_roll() const
{
	return _roll;
}

int16_t AttitudeDatagramAttitude::get_pitch() const
{
	return _pitch;
}

int16_t AttitudeDatagramAttitude::get_heave() const
{
	return _heave;
}

uint16_t AttitudeDatagramAttitude::get_heading() const
{
	return _heading;
}

void AttitudeDatagramAttitude::set_time(uint16_t time)
{
	_time = time;
}

void AttitudeDatagramAttitude::set_sensor_status(uint16_t sensor_status)
{
	_sensor_status = sensor_status;
}

void AttitudeDatagramAttitude::set_roll(int16_t roll)
{
	_roll = roll;
}

void AttitudeDatagramAttitude::set_pitch(int16_t pitch)
{
	_pitch = pitch;
}

void AttitudeDatagramAttitude::set_heave(int16_t heave)
{
	_heave = heave;
}

void AttitudeDatagramAttitude::set_heading(uint16_t heading)
{
	_heading = heading;
}

float AttitudeDatagramAttitude::get_time_in_seconds() const
{
	return static_cast<float>(_time) * 0.001f;
}

float AttitudeDatagramAttitude::get_roll_in_degrees() const
{
	return static_cast<float>(_roll) * 0.01f;
}

float AttitudeDatagramAttitude::get_pitch_in_degrees() const
{
	return static_cast<float>(_pitch) * 0.01f;
}

float AttitudeDatagramAttitude::get_heave_in_meters() const
{
	return static_cast<float>(_heave) * 0.01f;
}

float AttitudeDatagramAttitude::get_heading_in_degrees() const
{
	return static_cast<float>(_heading) * 0.01f;
}

tools::classhelper::ObjectPrinter
AttitudeDatagramAttitude::__printer__(unsigned int float_precision,
									  bool         superscript_exponents) const
{
	tools::classhelper::ObjectPrinter printer(
		"AttitudeDatagramAttitude", float_precision, superscript_exponents);

	printer.register_value("time", _time, "ms");
	printer.register_value("sensor_status", _sensor_status);
	printer.register_value("roll", _roll, "0.01°");
	printer.register_value("pitch", _pitch, "0.01°");
	printer.register_value("heave", _heave, "cm°");
	printer.register_value("heading", _heading, "0.01°");

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
