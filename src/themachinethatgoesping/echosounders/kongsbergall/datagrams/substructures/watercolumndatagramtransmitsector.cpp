// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "watercolumndatagramtransmitsector.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

namespace {

constexpr float tilt_angle_scale = 0.01f;
constexpr float frequency_scale  = 10.f;

} // namespace

int16_t WatercolumnDatagramTransmitSector::get_tilt_angle() const
{
	return _tilt_angle;
}

uint16_t WatercolumnDatagramTransmitSector::get_center_frequency() const
{
	return _center_frequency;
}

uint8_t WatercolumnDatagramTransmitSector::get_transmit_sector_number() const
{
	return _transmit_sector_number;
}

uint8_t WatercolumnDatagramTransmitSector::get_spare() const
{
	return _spare;
}

void WatercolumnDatagramTransmitSector::set_tilt_angle(int16_t tilt_angle)
{
	_tilt_angle = tilt_angle;
}

void WatercolumnDatagramTransmitSector::set_center_frequency(uint16_t center_frequency)
{
	_center_frequency = center_frequency;
}

void WatercolumnDatagramTransmitSector::set_transmit_sector_number(uint8_t transmit_sector_number)
{
	_transmit_sector_number = transmit_sector_number;
}

void WatercolumnDatagramTransmitSector::set_spare(uint8_t spare)
{
	_spare = spare;
}

float WatercolumnDatagramTransmitSector::get_tilt_angle_in_degrees() const
{
	return _tilt_angle * tilt_angle_scale;
}

float WatercolumnDatagramTransmitSector::get_center_frequency_in_hz() const
{
	return _center_frequency * frequency_scale;
}

tools::classhelper::ObjectPrinter WatercolumnDatagramTransmitSector::__printer__(
	unsigned int float_precision, bool superscript_exponents) const
{
	tools::classhelper::ObjectPrinter printer(
		"WatercolumnDatagramTransmitSector", float_precision, superscript_exponents);

	printer.register_value("tilt_angle", _tilt_angle, "0.01°");
	printer.register_value("center_frequency", _center_frequency, "10 Hz");
	printer.register_value("transmit_sector_number", _transmit_sector_number);
	printer.register_value("spare", _spare);

	printer.register_section("processed");
	printer.register_value("tilt_angle", get_tilt_angle_in_degrees(), "°");
	printer.register_value("center_frequency", get_center_frequency_in_hz(), "Hz");

	return printer;
}

} // namespace substructures
} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
