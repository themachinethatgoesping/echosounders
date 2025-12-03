// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "mwcrxbeamdatacontainer.hpp"

#include <fmt/format.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace datagrams {
namespace substructs {

const std::vector<MWCRxBeamData>& MWCRxBeamDataContainer::get_beams() const
{
    return _beams;
}

std::vector<MWCRxBeamData>& MWCRxBeamDataContainer::beams()
{
    return _beams;
}

void MWCRxBeamDataContainer::set_beams(const std::vector<MWCRxBeamData>& beams)
{
    _beams = beams;
}

xt::xtensor<float, 1> MWCRxBeamDataContainer::get_beam_pointing_angle_re_vertical_deg_tensor() const
{
    return build_tensor<float>([](const MWCRxBeamData& beam) {
        return beam.get_beam_pointing_angle_re_vertical_deg();
    });
}

xt::xtensor<uint16_t, 1> MWCRxBeamDataContainer::get_start_range_sample_number_tensor() const
{
    return build_tensor<uint16_t>([](const MWCRxBeamData& beam) {
        return beam.get_start_range_sample_number();
    });
}

xt::xtensor<uint16_t, 1> MWCRxBeamDataContainer::get_detected_range_in_samples_tensor() const
{
    return build_tensor<uint16_t>([](const MWCRxBeamData& beam) {
        return beam.get_detected_range_in_samples();
    });
}

xt::xtensor<uint16_t, 1> MWCRxBeamDataContainer::get_transmit_sector_number_tensor() const
{
    return build_tensor<uint16_t>([](const MWCRxBeamData& beam) {
        return beam.get_transmit_sector_number();
    });
}

xt::xtensor<uint16_t, 1> MWCRxBeamDataContainer::get_number_of_samples_tensor() const
{
    return build_tensor<uint16_t>([](const MWCRxBeamData& beam) {
        return beam.get_number_of_samples();
    });
}

xt::xtensor<float, 1> MWCRxBeamDataContainer::get_detected_range_in_samples_high_resolution_tensor() const
{
    return build_tensor<float>([](const MWCRxBeamData& beam) {
        return beam.get_detected_range_in_samples_high_resolution();
    });
}

size_t MWCRxBeamDataContainer::get_number_of_beams() const
{
    return _beams.size();
}

size_t MWCRxBeamDataContainer::get_total_number_of_samples() const
{
    size_t total = 0;
    for (const auto& beam : _beams)
        total += beam.get_number_of_samples();
    return total;
}

tools::classhelper::ObjectPrinter MWCRxBeamDataContainer::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "MWCRxBeamDataContainer", float_precision, superscript_exponents);

    printer.register_section("Beams (.beams)");
    printer.register_value("beams (vector)", fmt::format("size={}", get_number_of_beams()), "beams");

    printer.register_container("beam_pointing_angle_re_vertical_deg",
                               get_beam_pointing_angle_re_vertical_deg_tensor(),
                               "deg");
    printer.register_container("start_range_sample_number",
                               get_start_range_sample_number_tensor());
    printer.register_container("detected_range_in_samples",
                               get_detected_range_in_samples_tensor());
    printer.register_container("transmit_sector_number",
                               get_transmit_sector_number_tensor());
    printer.register_container("number_of_samples", get_number_of_samples_tensor());
    printer.register_container("detected_range_in_samples_high_resolution",
                               get_detected_range_in_samples_high_resolution_tensor());

    printer.register_section("processed");
    printer.register_value("number_of_beams", get_number_of_beams());
    printer.register_value("total_number_of_samples", get_total_number_of_samples(), "samples");

    return printer;
}

} // namespace substructs
} // namespace datagrams
} // namespace kmall
} // namespace echosounders
} // namespace themachinethatgoesping
