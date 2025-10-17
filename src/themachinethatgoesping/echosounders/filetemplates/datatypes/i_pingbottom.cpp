// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "i_pingbottom.hpp"

#include <algorithm>
#include <limits>
#include <stdexcept>
#include <vector>

#include <fmt/core.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datatypes {

std::string I_PingBottom::class_name() const
{
	return "I_PingBottom";
}

std::map<t_pingfeature, std::function<bool()>> I_PingBottom::primary_feature_functions() const
{
	auto features = t_base::primary_feature_functions();
	features[t_pingfeature::two_way_travel_times] =
		std::bind(&I_PingBottom::has_two_way_travel_times, this);
	features[t_pingfeature::xyz] = std::bind(&I_PingBottom::has_xyz, this);

	// to be implemented
	// features[t_pingfeature::beam_numbers_per_tx_sector] =
	//     std::bind(&I_PingBottom::has_beam_numbers_per_tx_sector, this);
	// features[t_pingfeature::beam_selection_all] =
	//     std::bind(&I_PingBottom::has_beam_selection_all, this);
	// features[t_pingfeature::number_of_beams] =
	//     std::bind(&I_PingBottom::has_number_of_beams, this);
	// features[t_pingfeature::tx_sector_per_beam] =
	//     std::bind(&I_PingBottom::has_tx_sector_per_beam, this);
	// features[t_pingfeature::tx_sector_information] =
	//     std::bind(&I_PingBottom::has_tx_sector_information, this);

	return features;
}

std::map<t_pingfeature, std::function<bool()>> I_PingBottom::secondary_feature_functions() const
{
	auto features = t_base::secondary_feature_functions();
	features[t_pingfeature::tx_signal_parameters] =
		std::bind(&I_PingBottom::has_tx_signal_parameters, this);
	features[t_pingfeature::number_of_tx_sectors] =
		std::bind(&I_PingBottom::has_number_of_tx_sectors, this);
	features[t_pingfeature::beam_crosstrack_angles] =
		std::bind(&I_PingBottom::has_beam_crosstrack_angles, this);
	return features;
}

std::map<t_pingfeature, std::function<bool()>> I_PingBottom::feature_group_functions() const
{
	return t_base::feature_group_functions();
}

I_PingBottom::I_PingBottom() = default;

I_PingBottom::~I_PingBottom() = default;

bool I_PingBottom::has_tx_signal_parameters() const
{
	return false;
}

bool I_PingBottom::has_number_of_tx_sectors() const
{
	return false;
}

bool I_PingBottom::has_beam_numbers_per_tx_sector() const
{
	return false;
}

bool I_PingBottom::has_tx_sector_per_beam() const
{
	return false;
}

bool I_PingBottom::has_beam_selection_all() const
{
	return has_number_of_beams();
}

bool I_PingBottom::has_number_of_beams() const
{
	return false;
}

bool I_PingBottom::has_beam_crosstrack_angles() const
{
	return false;
}

bool I_PingBottom::has_two_way_travel_times() const
{
	return false;
}

bool I_PingBottom::has_xyz() const
{
	return false;
}

std::vector<algorithms::signalprocessing::datastructures::TxSignalParameters>
	I_PingBottom::get_tx_signal_parameters()
{
	throw not_implemented(__func__, this->class_name());
}

size_t I_PingBottom::get_number_of_tx_sectors()
{
	throw not_implemented(__func__, this->class_name());
}

xt::xtensor<size_t, 1> I_PingBottom::get_tx_sector_per_beam()
{
	return get_tx_sector_per_beam(get_beam_selection_all());
}

xt::xtensor<size_t, 1>
	I_PingBottom::get_tx_sector_per_beam([[maybe_unused]] const pingtools::BeamSelection& bs)
{
	throw not_implemented(__func__, class_name());
}

std::vector<std::vector<size_t>> I_PingBottom::get_beam_numbers_per_tx_sector()
{
	return get_beam_numbers_per_tx_sector(get_beam_selection_all());
}

std::vector<std::vector<size_t>> I_PingBottom::get_beam_numbers_per_tx_sector(
	[[maybe_unused]] const pingtools::BeamSelection& bs)
{
	throw not_implemented(__func__, class_name());
}

pingtools::BeamSelection I_PingBottom::get_beam_selection_all()
{
	return pingtools::BeamSelection(get_number_of_beams());
}

uint32_t I_PingBottom::get_number_of_beams()
{
	throw not_implemented(__func__, class_name());
}

xt::xtensor<float, 1> I_PingBottom::get_beam_crosstrack_angles()
{
	return get_beam_crosstrack_angles(get_beam_selection_all());
}

xt::xtensor<float, 1> I_PingBottom::get_beam_crosstrack_angles(
	[[maybe_unused]] const pingtools::BeamSelection& bs)
{
	throw not_implemented(__func__, class_name());
}

algorithms::geoprocessing::datastructures::XYZ<1> I_PingBottom::get_xyz()
{
	return get_xyz(get_beam_selection_all());
}

algorithms::geoprocessing::datastructures::XYZ<1> I_PingBottom::get_xyz(
	[[maybe_unused]] const pingtools::BeamSelection& selection)
{
	throw not_implemented(__func__, this->class_name());
}

float I_PingBottom::get_bottom_z()
{
	return get_bottom_z(get_beam_selection_all());
}

float I_PingBottom::get_bottom_z(const pingtools::BeamSelection& selection)
{
	auto xyz = get_xyz(selection);

	if (xyz.size() == 0)
		throw std::runtime_error(fmt::format("Error[{}]: No valid bottom z found", __func__));
	if (xyz.size() == 1)
		return xyz.z[0];

	std::vector<float> bottom_distances(xyz.z.begin(), xyz.z.end());

	auto median_it = bottom_distances.begin() + bottom_distances.size() / 2;
	std::nth_element(bottom_distances.begin(), median_it, bottom_distances.end());
	auto median = *median_it;

	auto q3_it = bottom_distances.begin() + 3 * bottom_distances.size() / 4;
	std::nth_element(median_it, q3_it, bottom_distances.end());
	auto q3 = *q3_it;

	auto q1_it = bottom_distances.begin() + bottom_distances.size() / 4;
	std::nth_element(bottom_distances.begin(), q1_it, median_it);
	auto q1      = *q1_it;
	auto min_iqr = median - (q3 - q1) * 1.5F;

	std::sort(bottom_distances.begin(), q1_it);
	float bottom_z = std::numeric_limits<float>::max();
	for (auto it = bottom_distances.begin(); it != bottom_distances.end(); ++it)
		if (*it > min_iqr && *it < bottom_z)
			bottom_z = *it;

	if (bottom_z == std::numeric_limits<float>::max())
		throw std::runtime_error(fmt::format("Error[{}]: No valid bottom z found", __func__));

	return bottom_z;
}

xt::xtensor<float, 1> I_PingBottom::get_two_way_travel_times()
{
	return get_two_way_travel_times(get_beam_selection_all());
}

xt::xtensor<float, 1> I_PingBottom::get_two_way_travel_times(
	[[maybe_unused]] const pingtools::BeamSelection& selection)
{
	throw not_implemented(__func__, this->class_name());
}

tools::classhelper::ObjectPrinter I_PingBottom::__printer__(unsigned int float_precision,
															bool         superscript_exponents) const
{
	tools::classhelper::ObjectPrinter printer(
		this->class_name(), float_precision, superscript_exponents);

	printer.append(I_PingCommon::__printer__(float_precision, superscript_exponents));

	printer.register_section("Bottom detection infos");
	auto features     = this->feature_string();
	auto not_features = this->feature_string(false);
	if (!not_features.empty())
		printer.register_string("Features", features, std::string("Not:") + not_features);
	else
		printer.register_string("Features", features);

	return printer;
}

} // namespace themachinethatgoesping
} // namespace echosounders
} // namespace datatypes
} // namespace filetemplates
