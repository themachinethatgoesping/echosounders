// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "extradetectionsdetectionclasses.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

uint16_t ExtraDetectionsDetectionClasses::get_start_depth() const
{
	return _start_depth;
}

uint16_t ExtraDetectionsDetectionClasses::get_stop_depth() const
{
	return _stop_depth;
}

uint16_t ExtraDetectionsDetectionClasses::get_qf_threshold_100() const
{
	return _qf_threshold_100;
}

int16_t ExtraDetectionsDetectionClasses::get_bs_threshold() const
{
	return _bs_threshold;
}

uint16_t ExtraDetectionsDetectionClasses::get_snr_threshold() const
{
	return _snr_threshold;
}

uint16_t ExtraDetectionsDetectionClasses::get_alarm_threshold() const
{
	return _alarm_threshold;
}

uint16_t ExtraDetectionsDetectionClasses::get_number_of_extra_detections() const
{
	return _number_of_extra_detections;
}

bool ExtraDetectionsDetectionClasses::get_show_class() const
{
	return _show_class;
}

uint8_t ExtraDetectionsDetectionClasses::get_alarm_flag_1() const
{
	return _alarm_flag_1;
}

void ExtraDetectionsDetectionClasses::set_start_depth(uint16_t start_depth)
{
	_start_depth = start_depth;
}

void ExtraDetectionsDetectionClasses::set_stop_depth(uint16_t stop_depth)
{
	_stop_depth = stop_depth;
}

void ExtraDetectionsDetectionClasses::set_qf_threshold_100(uint16_t qf_threshold_100)
{
	_qf_threshold_100 = qf_threshold_100;
}

void ExtraDetectionsDetectionClasses::set_bs_threshold(int16_t bs_threshold)
{
	_bs_threshold = bs_threshold;
}

void ExtraDetectionsDetectionClasses::set_snr_threshold(uint16_t snr_threshold)
{
	_snr_threshold = snr_threshold;
}

void ExtraDetectionsDetectionClasses::set_alarm_threshold(uint16_t alarm_threshold)
{
	_alarm_threshold = alarm_threshold;
}

void ExtraDetectionsDetectionClasses::set_number_of_extra_detections(
	uint16_t number_of_extra_detections)
{
	_number_of_extra_detections = number_of_extra_detections;
}

void ExtraDetectionsDetectionClasses::set_show_class(bool show_class)
{
	_show_class = show_class;
}

void ExtraDetectionsDetectionClasses::set_alarm_flag_1(uint8_t alarm_flag_1)
{
	_alarm_flag_1 = alarm_flag_1;
}

double ExtraDetectionsDetectionClasses::get_qf_threshold() const
{
	return _qf_threshold_100 * 0.01;
}

tools::classhelper::ObjectPrinter
ExtraDetectionsDetectionClasses::__printer__(unsigned int float_precision,
											 bool         superscript_exponents) const
{
	tools::classhelper::ObjectPrinter printer(
		"ExtraDetectionsDetectionClasses", float_precision, superscript_exponents);

	printer.register_value("start_depth", _start_depth, "%");
	printer.register_value("stopt_depth", _stop_depth, "%");
	printer.register_value("qf_threshold_100", _qf_threshold_100, "1-100");
	printer.register_value("bs_threshold", _bs_threshold, "dB");
	printer.register_value("snr_threshold", _snr_threshold, "5-15");
	printer.register_value("alarm_threshold", _alarm_threshold);
	printer.register_value("number_of_extra_detections", _number_of_extra_detections);
	printer.register_value("show_class", _show_class);
	printer.register_value("alarm_flag_1", _alarm_flag_1);

	printer.register_section("Processed");
	printer.register_value("IFREMER QF Threshold", get_qf_threshold(), "0.01 - 1");

	return printer;
}

} // namespace substructures
} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
