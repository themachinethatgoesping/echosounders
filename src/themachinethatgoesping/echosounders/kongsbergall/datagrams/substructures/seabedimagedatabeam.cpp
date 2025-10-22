// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "seabedimagedatabeam.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

uint16_t SeabedImageDataBeam::get_sorting_direction() const
{
	return static_cast<uint16_t>(_sorting_direction);
}

uint8_t SeabedImageDataBeam::get_detection_info() const
{
	return _detection_info;
}

uint16_t SeabedImageDataBeam::get_number_of_samples() const
{
	return _number_of_samples;
}

uint16_t SeabedImageDataBeam::get_centre_sample_number() const
{
	return _centre_sample_number;
}

void SeabedImageDataBeam::set_sorting_direction(const uint16_t& sorting_direction)
{
	_sorting_direction = static_cast<int8_t>(sorting_direction);
}

void SeabedImageDataBeam::set_detection_info(const uint8_t& detection_info)
{
	_detection_info = detection_info;
}

void SeabedImageDataBeam::set_number_of_samples(const uint16_t& number_of_samples)
{
	_number_of_samples = number_of_samples;
}

void SeabedImageDataBeam::set_centre_sample_number(const uint16_t& centre_sample_number)
{
	_centre_sample_number = centre_sample_number;
}

bool SeabedImageDataBeam::get_detection_is_valid() const
{
	return detection_information::get_detection_is_valid(_detection_info);
}

detection_information::o_DetectionType SeabedImageDataBeam::get_detection_type() const
{
	return detection_information::get_detection_type(_detection_info);
}

bool SeabedImageDataBeam::get_backscatter_is_compensated() const
{
	return detection_information::get_backscatter_is_compensated(_detection_info);
}

tools::classhelper::ObjectPrinter
SeabedImageDataBeam::__printer__(unsigned int float_precision,
								 bool         superscript_exponents) const
{
	tools::classhelper::ObjectPrinter printer(
		"SeabedImageDataBeam", float_precision, superscript_exponents);

	printer.register_value("sorting_direction", _sorting_direction);
	printer.register_value("detection_info", _detection_info);
	printer.register_value("number_of_samples", _number_of_samples, "per beam");
	printer.register_value("centre_sample_number", _centre_sample_number);

	printer.register_section("processed");
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
