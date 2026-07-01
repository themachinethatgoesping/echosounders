// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "xyzdatagrambeamscontainer.hpp"

#include <fmt/format.h>
#include <xtensor/core/xmath.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace datagrams {
namespace substructures {

const std::vector<XYZDatagramBeam>& XYZDatagramBeamsContainer::get_beams() const
{
    return _beams;
}

std::vector<XYZDatagramBeam>& XYZDatagramBeamsContainer::beams()
{
    return _beams;
}

void XYZDatagramBeamsContainer::set_beams(const std::vector<XYZDatagramBeam>& beams)
{
    _beams = beams;
}

xt::xtensor<float, 1> XYZDatagramBeamsContainer::get_depth_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<float>([](const XYZDatagramBeam& beam) { return beam.get_depth(); },
                               beam_numbers);
}

xt::xtensor<float, 1> XYZDatagramBeamsContainer::get_acrosstrack_distance_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<float>(
        [](const XYZDatagramBeam& beam) { return beam.get_acrosstrack_distance(); }, beam_numbers);
}

xt::xtensor<float, 1> XYZDatagramBeamsContainer::get_alongtrack_distance_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<float>(
        [](const XYZDatagramBeam& beam) { return beam.get_alongtrack_distance(); }, beam_numbers);
}

xt::xtensor<uint16_t, 1> XYZDatagramBeamsContainer::get_detection_window_length_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<uint16_t>(
        [](const XYZDatagramBeam& beam) { return beam.get_detection_window_length(); },
        beam_numbers);
}

xt::xtensor<uint8_t, 1> XYZDatagramBeamsContainer::get_quality_factor_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<uint8_t>(
        [](const XYZDatagramBeam& beam) { return beam.get_quality_factor(); }, beam_numbers);
}

xt::xtensor<int8_t, 1> XYZDatagramBeamsContainer::get_beam_incidence_angle_adjustment_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<int8_t>(
        [](const XYZDatagramBeam& beam) { return beam.get_beam_incidence_angle_adjustment(); },
        beam_numbers);
}

xt::xtensor<uint8_t, 1> XYZDatagramBeamsContainer::get_detection_info_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<uint8_t>(
        [](const XYZDatagramBeam& beam) { return beam.get_detection_info(); }, beam_numbers);
}

xt::xtensor<int8_t, 1> XYZDatagramBeamsContainer::get_realtime_cleaning_information_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<int8_t>(
        [](const XYZDatagramBeam& beam) { return beam.get_realtime_cleaning_information(); },
        beam_numbers);
}

xt::xtensor<int16_t, 1> XYZDatagramBeamsContainer::get_reflectivity_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<int16_t>(
        [](const XYZDatagramBeam& beam) { return beam.get_reflectivity(); }, beam_numbers);
}

xt::xtensor<float, 1> XYZDatagramBeamsContainer::get_backscatter_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<float>([](const XYZDatagramBeam& beam) { return beam.get_backscatter(); },
                               beam_numbers);
}

xt::xtensor<float, 1>
XYZDatagramBeamsContainer::get_beam_incidence_angle_adjustment_in_degrees_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<float>(
        [](const XYZDatagramBeam& beam) {
            return beam.get_beam_incidence_angle_adjustment_in_degrees();
        },
        beam_numbers);
}

xt::xtensor<uint8_t, 1> XYZDatagramBeamsContainer::get_detection_is_valid_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<uint8_t>(
        [](const XYZDatagramBeam& beam) {
            return static_cast<uint8_t>(beam.get_detection_is_valid());
        },
        beam_numbers);
}

xt::xtensor<uint8_t, 1> XYZDatagramBeamsContainer::get_detection_type_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<uint8_t>(
        [](const XYZDatagramBeam& beam) { return static_cast<uint8_t>(beam.get_detection_type()); },
        beam_numbers);
}

xt::xtensor<uint8_t, 1> XYZDatagramBeamsContainer::get_backscatter_is_compensated_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    return build_tensor<uint8_t>(
        [](const XYZDatagramBeam& beam) {
            return static_cast<uint8_t>(beam.get_backscatter_is_compensated());
        },
        beam_numbers);
}

size_t XYZDatagramBeamsContainer::get_number_of_beams() const
{
    return _beams.size();
}

XYZDatagramBeamsContainer::t_XYZ XYZDatagramBeamsContainer::get_xyz() const
{
    t_XYZ xyz({ _beams.size() });

    for (std::size_t bn = 0; bn < _beams.size(); ++bn)
    {
        xyz.x.unchecked(bn) = _beams[bn].get_alongtrack_distance();
        xyz.y.unchecked(bn) = _beams[bn].get_acrosstrack_distance();
        xyz.z.unchecked(bn) = _beams[bn].get_depth();
    }

    return xyz;
}

XYZDatagramBeamsContainer::t_XYZ XYZDatagramBeamsContainer::get_xyz(
    const std::vector<uint32_t>& beam_numbers) const
{
    t_XYZ xyz({ beam_numbers.size() });

    for (std::size_t bi = 0; bi < beam_numbers.size(); ++bi)
    {
        const auto bn = beam_numbers[bi];
        if (bn >= _beams.size())
        {
            xyz.x.unchecked(bi) = std::numeric_limits<float>::quiet_NaN();
            xyz.y.unchecked(bi) = std::numeric_limits<float>::quiet_NaN();
            xyz.z.unchecked(bi) = std::numeric_limits<float>::quiet_NaN();
        }
        else
        {
            xyz.x.unchecked(bi) = _beams[bn].get_alongtrack_distance();
            xyz.y.unchecked(bi) = _beams[bn].get_acrosstrack_distance();
            xyz.z.unchecked(bi) = _beams[bn].get_depth();
        }
    }

    return xyz;
}

xt::xtensor<float, 1>
XYZDatagramBeamsContainer::get_beam_incidence_angle_horizontal_plane_in_degrees_tensor(
    const std::vector<uint32_t>& beam_numbers) const
{
    constexpr float to_degrees         = 180.0f / static_cast<float>(M_PI);
    auto            depth_tensor       = get_depth_tensor(beam_numbers);
    auto            acrosstrack_tensor = get_acrosstrack_distance_tensor(beam_numbers);
    auto adjustment_tensor = get_beam_incidence_angle_adjustment_in_degrees_tensor(beam_numbers);

    return xt::atan(acrosstrack_tensor / xt::abs(depth_tensor)) * to_degrees + adjustment_tensor;
}

tools::classhelper::ObjectPrinter XYZDatagramBeamsContainer::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "XYZDatagramBeamsContainer", float_precision, superscript_exponents);

    printer.register_section("Beams (.beams)");
    printer.register_value(
        "beams (vector)", fmt::format("size={}", get_number_of_beams()), "beams");

    printer.register_container("depth", get_depth_tensor(), "m");
    printer.register_container("acrosstrack_distance", get_acrosstrack_distance_tensor(), "m");
    printer.register_container("alongtrack_distance", get_alongtrack_distance_tensor(), "m");
    printer.register_container(
        "detection_window_length", get_detection_window_length_tensor(), "samples");
    printer.register_container("quality_factor", get_quality_factor_tensor());
    printer.register_container(
        "beam_incidence_angle_adjustment", get_beam_incidence_angle_adjustment_tensor(), "0.1 deg");
    printer.register_container("detection_info", get_detection_info_tensor());
    printer.register_container("realtime_cleaning_information",
                               get_realtime_cleaning_information_tensor());
    printer.register_container("reflectivity", get_reflectivity_tensor(), "0.1 dB");

    printer.register_section("processed");
    printer.register_value("number_of_beams", get_number_of_beams());
    printer.register_container("backscatter", get_backscatter_tensor(), "dB");
    printer.register_container("beam_incidence_angle_adjustment_in_degrees",
                               get_beam_incidence_angle_adjustment_in_degrees_tensor(),
                               "deg");
    printer.register_container("detection_is_valid", get_detection_is_valid_tensor());
    printer.register_container("detection_type", get_detection_type_tensor());
    printer.register_container("backscatter_is_compensated",
                               get_backscatter_is_compensated_tensor());

    return printer;
}

} // namespace substructures
} // namespace datagrams
} // namespace kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping