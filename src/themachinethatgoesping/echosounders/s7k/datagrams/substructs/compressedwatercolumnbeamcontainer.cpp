// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "compressedwatercolumnbeamcontainer.hpp"

#include <numbers>
#include <stdexcept>

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {
namespace substructs {

// ----- record-wide sample encoding -----
uint8_t CompressedWaterColumnBeamContainer::get_magnitude_bytes() const
{
    return _magnitude_bytes;
}
bool CompressedWaterColumnBeamContainer::get_has_phase() const
{
    return _has_phase;
}
bool CompressedWaterColumnBeamContainer::get_magnitude_is_db() const
{
    return _magnitude_is_db;
}
bool CompressedWaterColumnBeamContainer::get_magnitude_is_32bit() const
{
    return _magnitude_bytes == 4;
}

void CompressedWaterColumnBeamContainer::set_magnitude_bytes(uint8_t val)
{
    _magnitude_bytes = val;
}
void CompressedWaterColumnBeamContainer::set_has_phase(bool val)
{
    _has_phase = val;
}
void CompressedWaterColumnBeamContainer::set_magnitude_is_db(bool val)
{
    _magnitude_is_db = val;
}

t_CompressedWaterColumnDataType CompressedWaterColumnBeamContainer::get_data_type() const
{
    return compressed_water_column_data_type(_magnitude_bytes, _has_phase);
}

// ----- skip / lazy reading -----
bool CompressedWaterColumnBeamContainer::get_samples_are_skipped() const
{
    return _skipped;
}
void CompressedWaterColumnBeamContainer::set_skipped(int64_t sample_position)
{
    _skipped         = true;
    _sample_position = sample_position;
}
void CompressedWaterColumnBeamContainer::clear_skipped()
{
    _skipped = false;
}

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
    // raw magnitude values as float (no dB conversion)
    return xt::cast<float>(_beams.at(beam_index).get_raw_magnitude());
}

xt::xtensor<float, 1> CompressedWaterColumnBeamContainer::get_phase(size_t beam_index) const
{
    // raw phase values (int16 scale) to radians
    return xt::cast<float>(_beams.at(beam_index).get_raw_phase()) * PHASE_TO_RADIANS;
}

xt::xtensor<float, 1> CompressedWaterColumnBeamContainer::get_magnitude_in_db(
    size_t beam_index) const
{
    return convert_magnitude_to_db(get_magnitude(beam_index));
}

xt::xtensor<float, 1> CompressedWaterColumnBeamContainer::get_phase_in_degrees(
    size_t beam_index) const
{
    constexpr float rad2deg = 180.f / std::numbers::pi_v<float>;
    return get_phase(beam_index) * rad2deg;
}

std::vector<xt::xtensor<float, 1>> CompressedWaterColumnBeamContainer::get_magnitudes() const
{
    std::vector<xt::xtensor<float, 1>> out(_beams.size());
    for (size_t b = 0; b < _beams.size(); ++b)
        out[b] = get_magnitude(b);
    return out;
}

std::vector<xt::xtensor<float, 1>> CompressedWaterColumnBeamContainer::get_phases() const
{
    std::vector<xt::xtensor<float, 1>> out(_beams.size());
    for (size_t b = 0; b < _beams.size(); ++b)
        out[b] = get_phase(b);
    return out;
}

std::vector<xt::xtensor<float, 1>> CompressedWaterColumnBeamContainer::get_magnitudes_in_db() const
{
    std::vector<xt::xtensor<float, 1>> out(_beams.size());
    for (size_t b = 0; b < _beams.size(); ++b)
        out[b] = get_magnitude_in_db(b);
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

    printer.register_section("Beams (.beams)");
    printer.register_value(
        "beams (vector)", fmt::format("size={}", get_number_of_beams()), "beams");

    printer.register_container("beam_number_tensor", get_beam_number_tensor());
    printer.register_container("segment_number_tensor", get_segment_number_tensor());
    printer.register_container("sample_count_tensor", get_sample_count_tensor(), "samples");

    printer.register_value("total_number_of_samples", get_total_number_of_samples());
    printer.register_value("magnitude_bytes", _magnitude_bytes);
    printer.register_value("has_phase", _has_phase);
    printer.register_value("magnitude_is_db", _magnitude_is_db);
    printer.register_value("samples_are_skipped", _skipped);

    return printer;
}

} // namespace substructs
} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
