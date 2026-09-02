// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "compressedwatercolumnbeamcontainer.hpp"

#include <stdexcept>

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {
namespace substructs {

const std::vector<CompressedWaterColumnBeam>& CompressedWaterColumnBeamContainer::get_beams() const
{
    return _beams;
}

std::vector<CompressedWaterColumnBeam>& CompressedWaterColumnBeamContainer::beams()
{
    return _beams;
}

void CompressedWaterColumnBeamContainer::set_beams(
    const std::vector<CompressedWaterColumnBeam>& beams)
{
    _beams = beams;
}

xt::xtensor<uint16_t, 1> CompressedWaterColumnBeamContainer::get_beam_number_tensor() const
{
    return build_tensor<uint16_t>(
        [](const CompressedWaterColumnBeam& beam) { return beam.get_beam_number(); });
}

xt::xtensor<uint8_t, 1> CompressedWaterColumnBeamContainer::get_segment_number_tensor() const
{
    return build_tensor<uint8_t>(
        [](const CompressedWaterColumnBeam& beam) { return beam.get_segment_number(); });
}

xt::xtensor<uint32_t, 1> CompressedWaterColumnBeamContainer::get_sample_count_tensor() const
{
    return build_tensor<uint32_t>(
        [](const CompressedWaterColumnBeam& beam) { return beam.get_sample_count(); });
}

xt::xtensor<float, 1> CompressedWaterColumnBeamContainer::get_magnitude(size_t beam_index) const
{
    return _beams.at(beam_index).get_magnitude();
}

xt::xtensor<float, 1> CompressedWaterColumnBeamContainer::get_phase(size_t beam_index) const
{
    return _beams.at(beam_index).get_phase();
}

xt::xtensor<float, 1> CompressedWaterColumnBeamContainer::get_magnitude_in_db(
    size_t beam_index) const
{
    return _beams.at(beam_index).get_magnitude_in_db();
}

xt::xtensor<float, 1> CompressedWaterColumnBeamContainer::get_phase_in_degrees(
    size_t beam_index) const
{
    return _beams.at(beam_index).get_phase_in_degrees();
}

std::vector<xt::xtensor<float, 1>> CompressedWaterColumnBeamContainer::get_magnitudes() const
{
    std::vector<xt::xtensor<float, 1>> out(_beams.size());
    for (size_t b = 0; b < _beams.size(); ++b)
        out[b] = _beams[b].get_magnitude();
    return out;
}

std::vector<xt::xtensor<float, 1>> CompressedWaterColumnBeamContainer::get_phases() const
{
    std::vector<xt::xtensor<float, 1>> out(_beams.size());
    for (size_t b = 0; b < _beams.size(); ++b)
        out[b] = _beams[b].get_phase();
    return out;
}

std::vector<xt::xtensor<float, 1>> CompressedWaterColumnBeamContainer::get_magnitudes_in_db() const
{
    std::vector<xt::xtensor<float, 1>> out(_beams.size());
    for (size_t b = 0; b < _beams.size(); ++b)
        out[b] = _beams[b].get_magnitude_in_db();
    return out;
}

size_t CompressedWaterColumnBeamContainer::get_number_of_beams() const
{
    return _beams.size();
}

size_t CompressedWaterColumnBeamContainer::get_total_number_of_samples() const
{
    size_t total = 0;
    for (const auto& beam : _beams)
        total += beam.get_sample_count();
    return total;
}

int64_t CompressedWaterColumnBeamContainer::get_sample_position() const
{
    if (!_skipped)
        throw std::runtime_error(
            "ERROR[CompressedWaterColumnBeamContainer::get_sample_position]: The sample position is "
            "only available if the data was skipped!");

    return _sample_position;
}

tools::classhelper::ObjectPrinter CompressedWaterColumnBeamContainer::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "CompressedWaterColumnBeamContainer", float_precision, superscript_exponents);

    printer.register_value("number_of_beams", get_number_of_beams());
    printer.register_value("total_number_of_samples", get_total_number_of_samples());
    printer.register_value("samples_are_skipped", _skipped);

    return printer;
}

} // namespace substructs
} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
