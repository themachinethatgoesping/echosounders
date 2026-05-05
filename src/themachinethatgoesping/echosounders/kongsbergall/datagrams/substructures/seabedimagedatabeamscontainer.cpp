// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "seabedimagedatabeamscontainer.hpp"

#include <fmt/core.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

const std::vector<SeabedImageDataBeam>& SeabedImageDataBeamsContainer::get_beams() const
{
    return _beams;
}

std::vector<SeabedImageDataBeam>& SeabedImageDataBeamsContainer::beams()
{
    return _beams;
}

void SeabedImageDataBeamsContainer::set_beams(const std::vector<SeabedImageDataBeam>& beams)
{
    _beams = beams;
}

xt::xtensor<int8_t, 1> SeabedImageDataBeamsContainer::get_sorting_direction_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<int8_t>(
        [](const SeabedImageDataBeam& b) {
            return static_cast<int8_t>(b.get_sorting_direction());
        },
        beam_numbers);
}

xt::xtensor<uint8_t, 1> SeabedImageDataBeamsContainer::get_detection_info_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<uint8_t>(
        [](const SeabedImageDataBeam& b) { return b.get_detection_info(); }, beam_numbers);
}

xt::xtensor<uint16_t, 1> SeabedImageDataBeamsContainer::get_number_of_samples_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<uint16_t>(
        [](const SeabedImageDataBeam& b) { return b.get_number_of_samples(); }, beam_numbers);
}

xt::xtensor<uint16_t, 1> SeabedImageDataBeamsContainer::get_centre_sample_number_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<uint16_t>(
        [](const SeabedImageDataBeam& b) { return b.get_centre_sample_number(); }, beam_numbers);
}

xt::xtensor<uint8_t, 1> SeabedImageDataBeamsContainer::get_detection_is_valid_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<uint8_t>(
        [](const SeabedImageDataBeam& b) {
            return static_cast<uint8_t>(b.get_detection_is_valid());
        },
        beam_numbers);
}

xt::xtensor<uint8_t, 1> SeabedImageDataBeamsContainer::get_detection_type_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<uint8_t>(
        [](const SeabedImageDataBeam& b) {
            return static_cast<uint8_t>(b.get_detection_type());
        },
        beam_numbers);
}

xt::xtensor<uint8_t, 1> SeabedImageDataBeamsContainer::get_backscatter_is_compensated_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<uint8_t>(
        [](const SeabedImageDataBeam& b) {
            return static_cast<uint8_t>(b.get_backscatter_is_compensated());
        },
        beam_numbers);
}

size_t SeabedImageDataBeamsContainer::get_number_of_beams() const { return _beams.size(); }

tools::classhelper::ObjectPrinter SeabedImageDataBeamsContainer::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "SeabedImageDataBeamsContainer", float_precision, superscript_exponents);
    printer.register_value("number_of_beams", _beams.size());
    return printer;
}

} // namespace substructures
} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
