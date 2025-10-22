// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "xyzdatagrambeam.hpp"

#include <fmt/format.h>

#include <themachinethatgoesping/tools/helper/floatcompare.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

namespace {

constexpr double backscatter_scale     = 0.1;
constexpr double incidence_angle_scale = 0.1;

} // namespace

float XYZDatagramBeam::get_depth() const
{
	return _depth;
}

float XYZDatagramBeam::get_acrosstrack_distance() const
{
	return _acrosstrack_distance;
}

float XYZDatagramBeam::get_alongtrack_distance() const
{
	return _alongtrack_distance;
}

uint16_t XYZDatagramBeam::get_detection_window_length() const
{
	return _detection_window_length;
}

uint8_t XYZDatagramBeam::get_quality_factor() const
{
	return _quality_factor;
}

int8_t XYZDatagramBeam::get_beam_incidence_angle_adjustment() const
{
	return _beam_incidence_angle_adjustment;
}

uint8_t XYZDatagramBeam::get_detection_info() const
{
	return _detection_info;
}

int8_t XYZDatagramBeam::get_realtime_cleaning_information() const
{
	return _realtime_cleaning_information;
}

int16_t XYZDatagramBeam::get_reflectivity() const
{
	return _reflectivity;
}

void XYZDatagramBeam::set_depth(float depth)
{
	_depth = depth;
}

void XYZDatagramBeam::set_acrosstrack_distance(float acrosstrack_distance)
{
	_acrosstrack_distance = acrosstrack_distance;
}

void XYZDatagramBeam::set_alongtrack_distance(float alongtrack_distance)
{
	_alongtrack_distance = alongtrack_distance;
}

void XYZDatagramBeam::set_detection_window_length(uint16_t detection_window_length)
{
	_detection_window_length = detection_window_length;
}

void XYZDatagramBeam::set_quality_factor(uint8_t quality_factor)
{
	_quality_factor = quality_factor;
}

void XYZDatagramBeam::set_beam_incidence_angle_adjustment(double beam_incidence_angle_adjustment)
{
	_beam_incidence_angle_adjustment = static_cast<int8_t>(beam_incidence_angle_adjustment);
}

void XYZDatagramBeam::set_detection_info(uint8_t detection_info)
{
	_detection_info = detection_info;
}

void XYZDatagramBeam::set_realtime_cleaning_information(int8_t realtime_cleaning_information)
{
	_realtime_cleaning_information = realtime_cleaning_information;
}

void XYZDatagramBeam::set_reflectivity(int16_t reflectivity)
{
	_reflectivity = reflectivity;
}

double XYZDatagramBeam::get_backscatter() const
{
	return static_cast<double>(_reflectivity) * backscatter_scale;
}

double XYZDatagramBeam::get_beam_incidence_angle_adjustment_in_degrees() const
{
	return static_cast<double>(_beam_incidence_angle_adjustment) * incidence_angle_scale;
}

bool XYZDatagramBeam::get_detection_is_valid() const
{
	return detection_information::get_detection_is_valid(_detection_info);
}

detection_information::o_DetectionType XYZDatagramBeam::get_detection_type() const
{
	return detection_information::get_detection_type(_detection_info);
}

bool XYZDatagramBeam::get_backscatter_is_compensated() const
{
	return detection_information::get_backscatter_is_compensated(_detection_info);
}

bool XYZDatagramBeam::operator==(const XYZDatagramBeam& other) const
{
	using tools::helper::float_equals;

	return float_equals(_depth, other._depth) &&
	       float_equals(_acrosstrack_distance, other._acrosstrack_distance) &&
	       float_equals(_alongtrack_distance, other._alongtrack_distance) &&
	       _detection_window_length == other._detection_window_length &&
	       _quality_factor == other._quality_factor &&
	       _beam_incidence_angle_adjustment == other._beam_incidence_angle_adjustment &&
	       _detection_info == other._detection_info &&
	       _realtime_cleaning_information == other._realtime_cleaning_information &&
	       _reflectivity == other._reflectivity;
}

tools::classhelper::ObjectPrinter XYZDatagramBeam::__printer__(
	unsigned int float_precision, bool superscript_exponents) const
{
	tools::classhelper::ObjectPrinter printer(
	    "XYZDatagramBeam", float_precision, superscript_exponents);

	printer.register_value("depth", _depth, "-z in m");
	printer.register_value("acrosstrack_distance", _acrosstrack_distance, "y in m");
	printer.register_value("alongtrack_distance", _alongtrack_distance, "x in m");
	printer.register_value("detection_window_length", _detection_window_length, "in samples");
	printer.register_value("quality_factor", _quality_factor);
	printer.register_value(
	    "beam_incidence_angle_adjustment", _beam_incidence_angle_adjustment, "0.1°");
	printer.register_string("detection_info", fmt::format("0x{:08b}", _detection_info));
	printer.register_value("realtime_cleaning_information", _realtime_cleaning_information);
	printer.register_value("reflectivity", _reflectivity, "0.1 dB");

	printer.register_section("processed");
	printer.register_value("beam_incidence_angle_adjustment",
	                      get_beam_incidence_angle_adjustment_in_degrees(),
	                      "°");
	printer.register_value("detection_is_valid", get_detection_is_valid());
	printer.register_enum("detection_type", get_detection_type().value);
	printer.register_value("backscatter_is_compensated", get_backscatter_is_compensated());
	printer.register_value("reflectivity", get_backscatter(), "dB");

	return printer;
}

} // namespace substructures
} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
