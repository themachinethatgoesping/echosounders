// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "watercolumndatagrambeam.hpp"

#include <fmt/format.h>

#include <istream>
#include <ostream>
#include <stdexcept>
#include <vector>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

int16_t WatercolumnDatagramBeam::get_beam_crosstrack_angle() const
{
	return _beam_crosstrack_angle;
}

uint16_t WatercolumnDatagramBeam::get_start_range_sample_number() const
{
	return _start_range_sample_number;
}

uint16_t WatercolumnDatagramBeam::get_number_of_samples() const
{
	return _number_of_samples;
}

uint16_t WatercolumnDatagramBeam::get_detected_range_in_samples() const
{
	return _detected_range_in_samples;
}

uint8_t WatercolumnDatagramBeam::get_transmit_sector_number() const
{
	return _transmit_sector_number;
}

uint8_t WatercolumnDatagramBeam::get_beam_number() const
{
	return _beam_number;
}

size_t WatercolumnDatagramBeam::get_sample_position() const
{
	if (!_samples_are_skipped)
		throw std::runtime_error(
			fmt::format("ERROR[WatercolumnDatagramBeam::get_sample_position]: "
						"The sample position is only available if the data was skipped!"));

	return _sample_pos;
}

void WatercolumnDatagramBeam::_set_sample_are_skipped(size_t sample_pos)
{
	_sample_pos          = sample_pos;
	_samples_are_skipped = true;
	_samples             = xt::xtensor<int8_t, 1>();
}

void WatercolumnDatagramBeam::set_beam_crosstrack_angle(int16_t beam_crosstrack_angle)
{
	_beam_crosstrack_angle = beam_crosstrack_angle;
}

void WatercolumnDatagramBeam::set_start_range_sample_number(uint16_t start_range_sample_number)
{
	_start_range_sample_number = start_range_sample_number;
}

void WatercolumnDatagramBeam::set_number_of_samples(uint16_t number_of_samples)
{
	_number_of_samples = number_of_samples;
}

void WatercolumnDatagramBeam::set_detected_range_in_samples(uint16_t detected_range_in_samples)
{
	_detected_range_in_samples = detected_range_in_samples;
}

void WatercolumnDatagramBeam::set_transmit_sector_number(uint8_t transmit_sector_number)
{
	_transmit_sector_number = transmit_sector_number;
}

void WatercolumnDatagramBeam::set_beam_number(uint8_t beam_number)
{
	_beam_number = beam_number;
}

bool WatercolumnDatagramBeam::get_samples_are_skipped()
{
	return _samples_are_skipped;
}

xt::xtensor<int8_t, 1> WatercolumnDatagramBeam::read_samples(std::istream& ifs) const
{
	auto samples =
		xt::empty<int8_t>(xt::xtensor<int8_t, 1>::shape_type({ _number_of_samples }));

	ifs.seekg(get_sample_position());
	ifs.read(reinterpret_cast<char*>(samples.data()),
			 static_cast<std::streamsize>(_number_of_samples * sizeof(int8_t)));

	return samples;
}

xt::xtensor<int8_t, 1> WatercolumnDatagramBeam::read_samples(std::istream& ifs,
															 size_t        pos_first_sample,
															 size_t        first_sample,
															 size_t        number_of_samples,
															 size_t number_of_samples_in_datagram)
{
	auto samples = xt::xtensor<int8_t, 1>::from_shape({ number_of_samples });

	if (first_sample + number_of_samples > number_of_samples_in_datagram)
		throw std::range_error(
			fmt::format("ERROR[WatercolumnDatagramBeam::read_samples]: The requested number of "
						"samples [{} + {} ] exceeds the number of samples in the datagram [{}]!",
						first_sample,
						number_of_samples,
						number_of_samples_in_datagram));

	ifs.seekg(pos_first_sample + static_cast<std::streamoff>(first_sample * sizeof(int8_t)));
	ifs.read(reinterpret_cast<char*>(samples.data()),
			 static_cast<std::streamsize>(number_of_samples * sizeof(int8_t)));

	return samples;
}

const xt::xtensor<int8_t, 1>& WatercolumnDatagramBeam::get_samples() const
{
	if (_samples_are_skipped)
		throw std::runtime_error(
			fmt::format("ERROR[WatercolumnDatagramBeam::get_samples]: The data is not available "
						"because it was skipped! Call load or set_data first."));

	return _samples;
}

void WatercolumnDatagramBeam::set_samples(const xt::xtensor<int8_t, 1>& samples)
{
	_samples             = samples;
	_samples_are_skipped = false;
}

xt::xtensor<int8_t, 1>& WatercolumnDatagramBeam::samples()
{
	return _samples;
}

float WatercolumnDatagramBeam::get_beam_crosstrack_angle_in_degrees() const
{
	return static_cast<float>(_beam_crosstrack_angle) * 0.01f;
}

xt::xtensor<float, 1> WatercolumnDatagramBeam::get_samples_in_db(float db_offset) const
{
	if (_samples_are_skipped)
		throw std::runtime_error(
			fmt::format("ERROR[WatercolumnDatagramBeam::get_samples]: The data is not available "
						"because it was skipped! Call load or set_data first."));

	return xt::xtensor<float, 1>(xt::eval(_samples * 0.5f - db_offset));
}

WatercolumnDatagramBeam WatercolumnDatagramBeam::from_stream(std::istream& is, bool skip_data)
{
	WatercolumnDatagramBeam data;

	is.read(reinterpret_cast<char*>(&data._beam_crosstrack_angle), 10 * sizeof(uint8_t));

	data._sample_pos = static_cast<size_t>(is.tellg());

	if (skip_data)
	{
		data._samples_are_skipped = true;
		data._samples             = xt::xtensor<int8_t, 1>();
		is.seekg(static_cast<std::streamoff>(data._number_of_samples * sizeof(int8_t)),
				 std::ios_base::cur);
	}
	else
	{
		data._samples_are_skipped = false;
		data._samples =
			xt::empty<int8_t>(xt::xtensor<int8_t, 1>::shape_type({ data._number_of_samples }));
		is.read(reinterpret_cast<char*>(data._samples.data()),
				static_cast<std::streamsize>(data._number_of_samples * sizeof(int8_t)));
	}

	return data;
}

void WatercolumnDatagramBeam::to_stream(std::ostream& os)
{
	_number_of_samples = static_cast<uint16_t>(_samples.size());

	os.write(reinterpret_cast<const char*>(&_beam_crosstrack_angle), 10 * sizeof(uint8_t));

	if (!_samples_are_skipped)
	{
		if (_samples.size() != _number_of_samples)
			throw std::runtime_error(
				fmt::format("ERROR[WatercolumnDatagramBeam::to_stream]: The number of samples "
							"does not match the number of samples in the sample amplitude "
							"array!"));

		os.write(reinterpret_cast<const char*>(_samples.data()),
				 static_cast<std::streamsize>(_number_of_samples * sizeof(int8_t)));
	}
	else
	{
		std::vector<int8_t> zeros(_number_of_samples, 0);
		os.write(reinterpret_cast<const char*>(zeros.data()),
				 static_cast<std::streamsize>(_number_of_samples * sizeof(int8_t)));
	}
}

bool WatercolumnDatagramBeam::operator==(const WatercolumnDatagramBeam& other) const
{
	return _beam_crosstrack_angle == other._beam_crosstrack_angle &&
		   _start_range_sample_number == other._start_range_sample_number &&
		   _number_of_samples == other._number_of_samples &&
		   _detected_range_in_samples == other._detected_range_in_samples &&
		   _transmit_sector_number == other._transmit_sector_number &&
		   _beam_number == other._beam_number &&
		   xt::all(xt::equal(_samples, other._samples));
}

bool WatercolumnDatagramBeam::operator!=(const WatercolumnDatagramBeam& other) const
{
	return !(*this == other);
}

tools::classhelper::ObjectPrinter
WatercolumnDatagramBeam::__printer__(unsigned int float_precision,
									 bool         superscript_exponents) const
{
	tools::classhelper::ObjectPrinter printer(
		"WatercolumnDatagramBeam", float_precision, superscript_exponents);

	printer.register_value("beam_crosstrack_angle", _beam_crosstrack_angle, "0.01°");
	printer.register_value("start_range_sample_number", _start_range_sample_number);
	printer.register_value("number_of_samples", _number_of_samples);
	printer.register_value("detected_range_in_samples", _detected_range_in_samples);
	printer.register_value("transmit_sector_number", _transmit_sector_number);
	printer.register_value("beam_number", _beam_number);

	printer.register_section("samples");
	if (!_samples_are_skipped)
		printer.register_container("samples", _samples);
	else
		printer.register_string("samples", "skipped");

	printer.register_section("processed");
	printer.register_value("beam_crosstrack_angle", get_beam_crosstrack_angle_in_degrees(), "°");

	return printer;
}

} // namespace substructures
} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
