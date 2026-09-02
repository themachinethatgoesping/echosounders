// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "rawdetectionbeamcontainer.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {
namespace substructs {

const std::vector<RawDetectionBeam>& RawDetectionBeamContainer::get_beams() const
{
    return _beams;
}

std::vector<RawDetectionBeam>& RawDetectionBeamContainer::beams()
{
    return _beams;
}

void RawDetectionBeamContainer::set_beams(const std::vector<RawDetectionBeam>& beams)
{
    _beams = beams;
}

xt::xtensor<uint16_t, 1> RawDetectionBeamContainer::get_beam_descriptor_tensor() const
{
    return build_tensor<uint16_t>(
        [](const RawDetectionBeam& beam) { return beam.get_beam_descriptor(); });
}

xt::xtensor<float, 1> RawDetectionBeamContainer::get_detection_point_tensor() const
{
    return build_tensor<float>(
        [](const RawDetectionBeam& beam) { return beam.get_detection_point(); });
}

xt::xtensor<float, 1> RawDetectionBeamContainer::get_rx_angle_tensor() const
{
    return build_tensor<float>([](const RawDetectionBeam& beam) { return beam.get_rx_angle(); });
}

xt::xtensor<uint32_t, 1> RawDetectionBeamContainer::get_flags_tensor() const
{
    return build_tensor<uint32_t>([](const RawDetectionBeam& beam) { return beam.get_flags(); });
}

xt::xtensor<uint32_t, 1> RawDetectionBeamContainer::get_quality_tensor() const
{
    return build_tensor<uint32_t>([](const RawDetectionBeam& beam) { return beam.get_quality(); });
}

xt::xtensor<float, 1> RawDetectionBeamContainer::get_uncertainty_tensor() const
{
    return build_tensor<float>([](const RawDetectionBeam& beam) { return beam.get_uncertainty(); });
}

xt::xtensor<float, 1> RawDetectionBeamContainer::get_signal_strength_tensor() const
{
    return build_tensor<float>(
        [](const RawDetectionBeam& beam) { return beam.get_signal_strength(); });
}

xt::xtensor<float, 1> RawDetectionBeamContainer::get_min_limit_tensor() const
{
    return build_tensor<float>([](const RawDetectionBeam& beam) { return beam.get_min_limit(); });
}

xt::xtensor<float, 1> RawDetectionBeamContainer::get_max_limit_tensor() const
{
    return build_tensor<float>([](const RawDetectionBeam& beam) { return beam.get_max_limit(); });
}

size_t RawDetectionBeamContainer::get_number_of_beams() const
{
    return _beams.size();
}

tools::classhelper::ObjectPrinter RawDetectionBeamContainer::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "RawDetectionBeamContainer", float_precision, superscript_exponents);

    printer.register_value("number_of_beams", get_number_of_beams());

    return printer;
}

} // namespace substructs
} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
