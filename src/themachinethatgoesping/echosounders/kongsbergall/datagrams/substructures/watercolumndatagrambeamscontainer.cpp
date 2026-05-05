// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "watercolumndatagrambeamscontainer.hpp"

#include <fmt/core.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

const std::vector<WatercolumnDatagramBeam>&
WatercolumnDatagramBeamsContainer::get_beams() const
{
    return _beams;
}

std::vector<WatercolumnDatagramBeam>& WatercolumnDatagramBeamsContainer::beams()
{
    return _beams;
}

void WatercolumnDatagramBeamsContainer::set_beams(
    const std::vector<WatercolumnDatagramBeam>& beams)
{
    _beams = beams;
}

xt::xtensor<int16_t, 1> WatercolumnDatagramBeamsContainer::get_beam_crosstrack_angle_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<int16_t>(
        [](const WatercolumnDatagramBeam& b) { return b.get_beam_crosstrack_angle(); },
        beam_numbers);
}

xt::xtensor<uint16_t, 1> WatercolumnDatagramBeamsContainer::get_start_range_sample_number_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<uint16_t>(
        [](const WatercolumnDatagramBeam& b) { return b.get_start_range_sample_number(); },
        beam_numbers);
}

xt::xtensor<uint16_t, 1> WatercolumnDatagramBeamsContainer::get_number_of_samples_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<uint16_t>(
        [](const WatercolumnDatagramBeam& b) { return b.get_number_of_samples(); }, beam_numbers);
}

xt::xtensor<uint16_t, 1>
WatercolumnDatagramBeamsContainer::get_detected_range_in_samples_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<uint16_t>(
        [](const WatercolumnDatagramBeam& b) { return b.get_detected_range_in_samples(); },
        beam_numbers);
}

xt::xtensor<uint8_t, 1> WatercolumnDatagramBeamsContainer::get_transmit_sector_number_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<uint8_t>(
        [](const WatercolumnDatagramBeam& b) { return b.get_transmit_sector_number(); },
        beam_numbers);
}

xt::xtensor<uint8_t, 1> WatercolumnDatagramBeamsContainer::get_beam_number_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<uint8_t>(
        [](const WatercolumnDatagramBeam& b) { return b.get_beam_number(); }, beam_numbers);
}

xt::xtensor<float, 1>
WatercolumnDatagramBeamsContainer::get_beam_crosstrack_angle_in_degrees_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<float>(
        [](const WatercolumnDatagramBeam& b) { return b.get_beam_crosstrack_angle_in_degrees(); },
        beam_numbers);
}

size_t WatercolumnDatagramBeamsContainer::get_number_of_beams() const { return _beams.size(); }

tools::classhelper::ObjectPrinter WatercolumnDatagramBeamsContainer::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "WatercolumnDatagramBeamsContainer", float_precision, superscript_exponents);

    printer.register_section("Beams (.beams)");
    printer.register_value(
        "beams (vector)", fmt::format("size={}", get_number_of_beams()), "beams");

    printer.register_container("beam_crosstrack_angle", get_beam_crosstrack_angle_tensor());
    printer.register_container("start_range_sample_number",
                               get_start_range_sample_number_tensor());
    printer.register_container("number_of_samples", get_number_of_samples_tensor());
    printer.register_container("detected_range_in_samples",
                               get_detected_range_in_samples_tensor());
    printer.register_container("transmit_sector_number", get_transmit_sector_number_tensor());
    printer.register_container("beam_number", get_beam_number_tensor());

    printer.register_section("processed");
    printer.register_value("number_of_beams", get_number_of_beams());
    printer.register_container("beam_crosstrack_angle_in_degrees",
                               get_beam_crosstrack_angle_in_degrees_tensor(),
                               "deg");

    return printer;
}

} // namespace substructures
} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
