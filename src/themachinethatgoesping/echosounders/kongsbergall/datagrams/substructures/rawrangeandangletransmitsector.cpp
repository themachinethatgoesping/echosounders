// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "rawrangeandangletransmitsector.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

int16_t RawRangeAndAngleTransmitSector::get_tilt_angle() const
{
	return _tilt_angle;
}

uint16_t RawRangeAndAngleTransmitSector::get_focus_range() const
{
	return _focus_range;
}

float RawRangeAndAngleTransmitSector::get_signal_length() const
{
	return _signal_length;
}

float RawRangeAndAngleTransmitSector::get_sector_transmit_delay() const
{
	return _sector_transmit_delay;
}

float RawRangeAndAngleTransmitSector::get_center_frequency() const
{
	return _center_frequency;
}

uint16_t RawRangeAndAngleTransmitSector::get_mean_absorption_coefficient() const
{
	return _mean_absorption_coefficient;
}

uint8_t RawRangeAndAngleTransmitSector::get_signal_waveform_identifier() const
{
	return _signal_waveform_identifier;
}

uint8_t RawRangeAndAngleTransmitSector::get_transmit_sector_number() const
{
	return _transmit_sector_number;
}

float RawRangeAndAngleTransmitSector::get_signal_bandwidth() const
{
	return _signal_bandwidth;
}

void RawRangeAndAngleTransmitSector::set_tilt_angle(int16_t tilt_angle)
{
	_tilt_angle = tilt_angle;
}

void RawRangeAndAngleTransmitSector::set_focus_range(uint16_t focus_range)
{
	_focus_range = focus_range;
}

void RawRangeAndAngleTransmitSector::set_signal_length(float signal_length)
{
	_signal_length = signal_length;
}

void RawRangeAndAngleTransmitSector::set_sector_transmit_delay(float sector_transmit_delay)
{
	_sector_transmit_delay = sector_transmit_delay;
}

void RawRangeAndAngleTransmitSector::set_center_frequency(float center_frequency)
{
	_center_frequency = center_frequency;
}

void RawRangeAndAngleTransmitSector::set_mean_absorption_coefficient(
	uint16_t mean_absorption_coefficient)
{
	_mean_absorption_coefficient = mean_absorption_coefficient;
}

void RawRangeAndAngleTransmitSector::set_signal_waveform_identifier(
	uint8_t signal_waveform_identifier)
{
	_signal_waveform_identifier = signal_waveform_identifier;
}

void RawRangeAndAngleTransmitSector::set_transmit_sector_number(uint8_t transmit_sector_number)
{
	_transmit_sector_number = transmit_sector_number;
}

void RawRangeAndAngleTransmitSector::set_signal_bandwidth(float signal_bandwidth)
{
	_signal_bandwidth = signal_bandwidth;
}

float RawRangeAndAngleTransmitSector::get_tilt_angle_in_degrees() const
{
	return static_cast<float>(_tilt_angle) * 0.01f;
}

float RawRangeAndAngleTransmitSector::get_focus_range_in_m() const
{
	return static_cast<float>(_focus_range) * 0.1f;
}

float RawRangeAndAngleTransmitSector::get_mean_absorption_coefficient_in_dB_per_m() const
{
	return static_cast<float>(_mean_absorption_coefficient) * 0.00001f;
}

algorithms::signalprocessing::types::t_TxSignalType
RawRangeAndAngleTransmitSector::get_tx_signal_type() const
{
	using algorithms::signalprocessing::types::t_TxSignalType;

	switch (_signal_waveform_identifier)
	{
		case 0:
			return t_TxSignalType::CW;
		case 1:
			return t_TxSignalType::FM_UP_SWEEP;
		case 2:
			return t_TxSignalType::FM_DOWN_SWEEP;
		default:
			return t_TxSignalType::UNKNOWN;
	}
}

tools::classhelper::ObjectPrinter
RawRangeAndAngleTransmitSector::__printer__(unsigned int float_precision,
											bool         superscript_exponents) const
{
	tools::classhelper::ObjectPrinter printer(
		"RawRangeAndAngleTransmitSector", float_precision, superscript_exponents);

	printer.register_value("tilt_angle", _tilt_angle, "0.01°");
	printer.register_value("focus_range", _focus_range, "0.1m");
	printer.register_value("signal_length", _signal_length, "s");
	printer.register_value("sector_transmit_delay", _sector_transmit_delay, "s");
	printer.register_value("center_frequency", _center_frequency, "Hz");
	printer.register_value("mean_absorption_coefficient", _mean_absorption_coefficient,
						   "0.01 dB/km");
	printer.register_value("signal_waveform_identifier", _signal_waveform_identifier);
	printer.register_value("transmit_sector_number", _transmit_sector_number);
	printer.register_value("signal_bandwidth", _signal_bandwidth, "Hz");

	printer.register_section("processed");
	printer.register_value("tilt_angle", get_tilt_angle_in_degrees(), "°");
	printer.register_value("focus_range", get_focus_range_in_m(), "m");
	printer.register_value("mean_absorption_coefficient",
						   get_mean_absorption_coefficient_in_dB_per_m(), "dB/m");
	printer.register_value("tx_signal_type",
						   algorithms::signalprocessing::types::to_string(get_tx_signal_type()));

	return printer;
}

} // namespace substructures
} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
