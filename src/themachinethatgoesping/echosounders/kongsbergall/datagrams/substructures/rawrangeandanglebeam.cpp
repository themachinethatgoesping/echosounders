// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "rawrangeandanglebeam.hpp"

#include <fmt/format.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

int16_t RawRangeAndAngleBeam::get_beam_crosstrack_angle() const
{
	return _beam_crosstrack_angle;
}

uint8_t RawRangeAndAngleBeam::get_transmit_sector_number() const
{
	return _transmit_sector_number;
}

uint8_t RawRangeAndAngleBeam::get_detection_info() const
{
	return _detection_info;
}

uint16_t RawRangeAndAngleBeam::get_detection_window_length_in_samples() const
{
	return _detection_window_length_in_samples;
}

uint8_t RawRangeAndAngleBeam::get_quality_factor() const
{
	return _quality_factor;
}

int8_t RawRangeAndAngleBeam::get_d_corr() const
{
	return _d_corr;
}

float RawRangeAndAngleBeam::get_two_way_travel_time() const
{
	return _two_way_travel_time;
}

int16_t RawRangeAndAngleBeam::get_reflectivity() const
{
	return _reflectivity;
}

int8_t RawRangeAndAngleBeam::get_realtime_cleaning_info() const
{
	return _realtime_cleaning_info;
}

uint8_t RawRangeAndAngleBeam::get_spare() const
{
	return _spare;
}

void RawRangeAndAngleBeam::set_beam_crosstrack_angle(int16_t beam_crosstrack_angle)
{
	_beam_crosstrack_angle = beam_crosstrack_angle;
}

void RawRangeAndAngleBeam::set_transmit_sector_number(uint8_t transmit_sector_number)
{
	_transmit_sector_number = transmit_sector_number;
}

void RawRangeAndAngleBeam::set_detection_info(uint8_t detection_info)
{
	_detection_info = detection_info;
}

void RawRangeAndAngleBeam::set_detection_window_length_in_samples(
	uint16_t detection_window_length_in_samples)
{
	_detection_window_length_in_samples = detection_window_length_in_samples;
}

void RawRangeAndAngleBeam::set_quality_factor(uint8_t quality_factor)
{
	_quality_factor = quality_factor;
}

void RawRangeAndAngleBeam::set_d_corr(int8_t d_corr)
{
	_d_corr = d_corr;
}

void RawRangeAndAngleBeam::set_two_way_travel_time(float two_way_travel_time)
{
	_two_way_travel_time = two_way_travel_time;
}

void RawRangeAndAngleBeam::set_reflectivity(int16_t reflectivity)
{
	_reflectivity = reflectivity;
}

void RawRangeAndAngleBeam::set_realtime_cleaning_info(int8_t realtime_cleaning_info)
{
	_realtime_cleaning_info = realtime_cleaning_info;
}

void RawRangeAndAngleBeam::set_spare(uint8_t spare)
{
	_spare = spare;
}

float RawRangeAndAngleBeam::get_beam_crosstrack_angle_in_degrees() const
{
	return static_cast<float>(_beam_crosstrack_angle) * 0.01f;
}

float RawRangeAndAngleBeam::get_reflectivity_in_db() const
{
	return static_cast<float>(_reflectivity) * 0.1f;
}

bool RawRangeAndAngleBeam::get_detection_is_valid() const
{
	return detection_information::get_detection_is_valid(_detection_info);
}

detection_information::o_DetectionType RawRangeAndAngleBeam::get_detection_type() const
{
	return detection_information::get_detection_type(_detection_info);
}

bool RawRangeAndAngleBeam::get_backscatter_is_compensated() const
{
	return detection_information::get_backscatter_is_compensated(_detection_info);
}

tools::classhelper::ObjectPrinter
RawRangeAndAngleBeam::__printer__(unsigned int float_precision,
								  bool         superscript_exponents) const
{
	tools::classhelper::ObjectPrinter printer(
		"RawRangeAndAngleBeam", float_precision, superscript_exponents);

	printer.register_value("beam_crosstrack_angle", _beam_crosstrack_angle, "0.01°");
	printer.register_value("transmit_sector_number", _transmit_sector_number);
	printer.register_string("detection_info", fmt::format("0b{:08b}", _detection_info));
	printer.register_value("detection_window_length_in_samples",
						   _detection_window_length_in_samples);
	printer.register_value("quality_factor", _quality_factor);
	printer.register_value("d_corr", _d_corr);
	printer.register_value("two_way_travel_time", _two_way_travel_time, "s");
	printer.register_value("reflectivity", _reflectivity, "0.1 dB");
	printer.register_value("realtime_cleaning_info", _realtime_cleaning_info);
	printer.register_value("spare", _spare);

	printer.register_section("processed");
	printer.register_value("beam_crosstrack_angle", get_beam_crosstrack_angle_in_degrees(), "°");
	printer.register_value("reflectivity", get_reflectivity_in_db(), "dB");
	printer.register_value("detection_is_valid", get_detection_is_valid());
	printer.register_enum("detection_type", get_detection_type().value);
	printer.register_value("backscatter_is_compensated", get_backscatter_is_compensated());

	return printer;
}

} // namespace substructures
} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
