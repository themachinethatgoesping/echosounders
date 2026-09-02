// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "compressedwatercolumnbeamcontainer.hpp"

#include <cmath>
#include <cstring>
#include <limits>
#include <numbers>
#include <stdexcept>

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {
namespace substructs {

namespace {
constexpr float S7K_PHASE_SCALE = 10430.f; ///< int16 phase value / 10430 = radians
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

xt::xtensor<float, 1> CompressedWaterColumnBeamContainer::decode_magnitude(
    const CompressedWaterColumnBeam& beam) const
{
    const size_t          n      = beam.get_sample_count();
    const size_t          stride = get_sample_stride();
    const char*           raw    = beam.get_raw_samples().data();
    xt::xtensor<float, 1> out    = xt::xtensor<float, 1>::from_shape({ n });

    for (size_t s = 0; s < n; ++s)
    {
        const char* p = raw + s * stride;
        float       m = 0.f;
        if (_magnitude_bytes == 4)
        {
            float v = 0.f; // 32-bit magnitude is IEEE float32 (flag bit 12), not an integer
            std::memcpy(&v, p, 4);
            m = v;
        }
        else if (_magnitude_bytes == 1)
        {
            uint8_t v = 0;
            std::memcpy(&v, p, 1);
            m = float(v);
        }
        else
        {
            uint16_t v = 0;
            std::memcpy(&v, p, 2);
            m = float(v);
        }
        out.unchecked(s) = m;
    }
    return out;
}

xt::xtensor<float, 1> CompressedWaterColumnBeamContainer::decode_phase(
    const CompressedWaterColumnBeam& beam) const
{
    if (!_has_phase)
        return xt::xtensor<float, 1>::from_shape({ 0 });

    const size_t          n      = beam.get_sample_count();
    const size_t          stride = get_sample_stride();
    const char*           raw    = beam.get_raw_samples().data();
    xt::xtensor<float, 1> out    = xt::xtensor<float, 1>::from_shape({ n });

    for (size_t s = 0; s < n; ++s)
    {
        const char* p     = raw + s * stride + _magnitude_bytes;
        float       phase = 0.f;
        if (_phase_8bit)
        {
            int8_t v = 0;
            std::memcpy(&v, p, 1);
            // 8-bit phase is the high byte of the 16-bit phase value
            phase = float(int16_t(int16_t(v) << 8)) / S7K_PHASE_SCALE;
        }
        else
        {
            int16_t v = 0;
            std::memcpy(&v, p, 2);
            phase = float(v) / S7K_PHASE_SCALE;
        }
        out.unchecked(s) = phase;
    }
    return out;
}

xt::xtensor<float, 1> CompressedWaterColumnBeamContainer::get_magnitude(size_t beam_index) const
{
    return decode_magnitude(_beams.at(beam_index));
}

xt::xtensor<float, 1> CompressedWaterColumnBeamContainer::get_phase(size_t beam_index) const
{
    return decode_phase(_beams.at(beam_index));
}

xt::xtensor<float, 1> CompressedWaterColumnBeamContainer::get_magnitude_in_db(
    size_t beam_index) const
{
    xt::xtensor<float, 1> mag = decode_magnitude(_beams.at(beam_index));

    if (_magnitude_is_db)
        return mag; // values are already stored in dB (8-bit truncated dB, flag bit 2)

    // linear magnitude -> dB relative to full scale (65535 for 16-bit, 1 for 32-bit float)
    const float full_scale = _magnitude_is_32bit_float ? 1.f : 65535.f;
    const float neg_inf    = -std::numeric_limits<float>::infinity();
    for (size_t i = 0; i < mag.size(); ++i)
    {
        const float v    = mag.unchecked(i);
        mag.unchecked(i) = v > 0.f ? 20.f * std::log10(v / full_scale) : neg_inf;
    }
    return mag;
}

xt::xtensor<float, 1> CompressedWaterColumnBeamContainer::get_phase_in_degrees(
    size_t beam_index) const
{
    xt::xtensor<float, 1> phase   = decode_phase(_beams.at(beam_index));
    constexpr float       rad2deg = 180.f / std::numbers::pi_v<float>;
    for (size_t i = 0; i < phase.size(); ++i)
        phase.unchecked(i) *= rad2deg;
    return phase;
}

std::vector<xt::xtensor<float, 1>> CompressedWaterColumnBeamContainer::get_magnitudes() const
{
    std::vector<xt::xtensor<float, 1>> out(_beams.size());
    for (size_t b = 0; b < _beams.size(); ++b)
        out[b] = decode_magnitude(_beams[b]);
    return out;
}

std::vector<xt::xtensor<float, 1>> CompressedWaterColumnBeamContainer::get_phases() const
{
    std::vector<xt::xtensor<float, 1>> out(_beams.size());
    for (size_t b = 0; b < _beams.size(); ++b)
        out[b] = decode_phase(_beams[b]);
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

    printer.register_value("number_of_beams", get_number_of_beams());
    printer.register_value("total_number_of_samples", get_total_number_of_samples());
    printer.register_value("magnitude_bytes", _magnitude_bytes);
    printer.register_value("has_phase", _has_phase);
    printer.register_value("samples_are_skipped", _skipped);

    return printer;
}

} // namespace substructs
} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
