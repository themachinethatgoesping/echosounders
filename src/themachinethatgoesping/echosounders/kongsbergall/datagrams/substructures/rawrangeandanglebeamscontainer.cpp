// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "rawrangeandanglebeamscontainer.hpp"

#include <fmt/core.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

const std::vector<RawRangeAndAngleBeam>& RawRangeAndAngleBeamsContainer::get_beams() const
{
    return _beams;
}

std::vector<RawRangeAndAngleBeam>& RawRangeAndAngleBeamsContainer::beams()
{
    return _beams;
}

void RawRangeAndAngleBeamsContainer::set_beams(const std::vector<RawRangeAndAngleBeam>& beams)
{
    _beams = beams;
}

xt::xtensor<int16_t, 1> RawRangeAndAngleBeamsContainer::get_beam_crosstrack_angle_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<int16_t>(
        [](const RawRangeAndAngleBeam& b) { return b.get_beam_crosstrack_angle(); }, beam_numbers);
}

xt::xtensor<uint8_t, 1> RawRangeAndAngleBeamsContainer::get_transmit_sector_number_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<uint8_t>(
        [](const RawRangeAndAngleBeam& b) { return b.get_transmit_sector_number(); },
        beam_numbers);
}

xt::xtensor<uint8_t, 1> RawRangeAndAngleBeamsContainer::get_detection_info_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<uint8_t>(
        [](const RawRangeAndAngleBeam& b) { return b.get_detection_info(); }, beam_numbers);
}

xt::xtensor<uint16_t, 1>
RawRangeAndAngleBeamsContainer::get_detection_window_length_in_samples_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<uint16_t>(
        [](const RawRangeAndAngleBeam& b) { return b.get_detection_window_length_in_samples(); },
        beam_numbers);
}

xt::xtensor<uint8_t, 1> RawRangeAndAngleBeamsContainer::get_quality_factor_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<uint8_t>(
        [](const RawRangeAndAngleBeam& b) { return b.get_quality_factor(); }, beam_numbers);
}

xt::xtensor<int8_t, 1> RawRangeAndAngleBeamsContainer::get_d_corr_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<int8_t>(
        [](const RawRangeAndAngleBeam& b) { return b.get_d_corr(); }, beam_numbers);
}

xt::xtensor<float, 1> RawRangeAndAngleBeamsContainer::get_two_way_travel_time_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<float>(
        [](const RawRangeAndAngleBeam& b) { return b.get_two_way_travel_time(); }, beam_numbers);
}

xt::xtensor<int16_t, 1> RawRangeAndAngleBeamsContainer::get_reflectivity_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<int16_t>(
        [](const RawRangeAndAngleBeam& b) { return b.get_reflectivity(); }, beam_numbers);
}

xt::xtensor<int8_t, 1> RawRangeAndAngleBeamsContainer::get_realtime_cleaning_info_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<int8_t>(
        [](const RawRangeAndAngleBeam& b) { return b.get_realtime_cleaning_info(); },
        beam_numbers);
}

xt::xtensor<uint8_t, 1> RawRangeAndAngleBeamsContainer::get_spare_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<uint8_t>(
        [](const RawRangeAndAngleBeam& b) { return b.get_spare(); }, beam_numbers);
}

xt::xtensor<float, 1> RawRangeAndAngleBeamsContainer::get_beam_crosstrack_angle_in_degrees_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<float>(
        [](const RawRangeAndAngleBeam& b) { return b.get_beam_crosstrack_angle_in_degrees(); },
        beam_numbers);
}

xt::xtensor<float, 1> RawRangeAndAngleBeamsContainer::get_reflectivity_in_db_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<float>(
        [](const RawRangeAndAngleBeam& b) { return b.get_reflectivity_in_db(); }, beam_numbers);
}

xt::xtensor<uint8_t, 1> RawRangeAndAngleBeamsContainer::get_detection_is_valid_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<uint8_t>(
        [](const RawRangeAndAngleBeam& b) {
            return static_cast<uint8_t>(b.get_detection_is_valid());
        },
        beam_numbers);
}

xt::xtensor<uint8_t, 1> RawRangeAndAngleBeamsContainer::get_detection_type_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<uint8_t>(
        [](const RawRangeAndAngleBeam& b) {
            return static_cast<uint8_t>(b.get_detection_type());
        },
        beam_numbers);
}

xt::xtensor<uint8_t, 1> RawRangeAndAngleBeamsContainer::get_backscatter_is_compensated_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<uint8_t>(
        [](const RawRangeAndAngleBeam& b) {
            return static_cast<uint8_t>(b.get_backscatter_is_compensated());
        },
        beam_numbers);
}

size_t RawRangeAndAngleBeamsContainer::get_number_of_beams() const { return _beams.size(); }

tools::classhelper::ObjectPrinter RawRangeAndAngleBeamsContainer::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "RawRangeAndAngleBeamsContainer", float_precision, superscript_exponents);
    printer.register_value("number_of_beams", _beams.size());
    return printer;
}

} // namespace substructures
} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
