// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "snippetdatabeamcontainer.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {
namespace substructs {

const std::vector<SnippetDataBeam>& SnippetDataBeamContainer::get_beams() const
{
    return _beams;
}

std::vector<SnippetDataBeam>& SnippetDataBeamContainer::beams()
{
    return _beams;
}

void SnippetDataBeamContainer::set_beams(const std::vector<SnippetDataBeam>& beams)
{
    _beams = beams;
}

xt::xtensor<uint16_t, 1> SnippetDataBeamContainer::get_beam_descriptor_tensor() const
{
    return build_tensor<uint16_t>(
        [](const SnippetDataBeam& beam) { return beam.get_beam_descriptor(); });
}

xt::xtensor<uint32_t, 1> SnippetDataBeamContainer::get_snippet_start_tensor() const
{
    return build_tensor<uint32_t>(
        [](const SnippetDataBeam& beam) { return beam.get_snippet_start(); });
}

xt::xtensor<uint32_t, 1> SnippetDataBeamContainer::get_detection_sample_tensor() const
{
    return build_tensor<uint32_t>(
        [](const SnippetDataBeam& beam) { return beam.get_detection_sample(); });
}

xt::xtensor<uint32_t, 1> SnippetDataBeamContainer::get_snippet_end_tensor() const
{
    return build_tensor<uint32_t>(
        [](const SnippetDataBeam& beam) { return beam.get_snippet_end(); });
}

xt::xtensor<uint32_t, 1> SnippetDataBeamContainer::get_number_of_samples_tensor() const
{
    return build_tensor<uint32_t>(
        [](const SnippetDataBeam& beam) { return beam.get_number_of_samples(); });
}

size_t SnippetDataBeamContainer::get_number_of_beams() const
{
    return _beams.size();
}

size_t SnippetDataBeamContainer::get_total_number_of_samples() const
{
    size_t total = 0;
    for (const auto& beam : _beams)
        total += beam.get_number_of_samples();
    return total;
}

tools::classhelper::ObjectPrinter SnippetDataBeamContainer::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "SnippetDataBeamContainer", float_precision, superscript_exponents);

    printer.register_value("number_of_beams", get_number_of_beams());
    printer.register_value("total_number_of_samples", get_total_number_of_samples());

    return printer;
}

} // namespace substructs
} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
