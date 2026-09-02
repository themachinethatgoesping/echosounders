// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "compressedwatercolumnbeam.hpp"

#include <cmath>
#include <cstring>
#include <limits>
#include <numbers>

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {
namespace substructs {

namespace {
constexpr float S7K_PHASE_SCALE = 10430.f; ///< int16 phase value / 10430 = radians
}

xt::xtensor<float, 1> CompressedWaterColumnBeam::get_magnitude() const
{
    const size_t          n      = _sample_count;
    const size_t          stride = get_sample_stride();
    xt::xtensor<float, 1> out    = xt::xtensor<float, 1>::from_shape({ n });

    for (size_t s = 0; s < n; ++s)
    {
        const char* p = _raw_samples.data() + s * stride;
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

xt::xtensor<float, 1> CompressedWaterColumnBeam::get_phase() const
{
    if (!_has_phase)
        return xt::xtensor<float, 1>::from_shape({ 0 });

    const size_t          n      = _sample_count;
    const size_t          stride = get_sample_stride();
    xt::xtensor<float, 1> out    = xt::xtensor<float, 1>::from_shape({ n });

    for (size_t s = 0; s < n; ++s)
    {
        const char* p = _raw_samples.data() + s * stride + _magnitude_bytes;
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

xt::xtensor<float, 1> CompressedWaterColumnBeam::get_magnitude_in_db() const
{
    xt::xtensor<float, 1> mag = get_magnitude();

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

xt::xtensor<float, 1> CompressedWaterColumnBeam::get_phase_in_degrees() const
{
    xt::xtensor<float, 1> phase   = get_phase();
    constexpr float       rad2deg = 180.f / std::numbers::pi_v<float>;
    for (size_t i = 0; i < phase.size(); ++i)
        phase.unchecked(i) *= rad2deg;
    return phase;
}

tools::classhelper::ObjectPrinter CompressedWaterColumnBeam::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "CompressedWaterColumnBeam", float_precision, superscript_exponents);

    printer.register_value("beam_number", _beam_number);
    printer.register_value("segment_number", _segment_number);
    printer.register_value("sample_count", _sample_count, "samples");
    printer.register_value("magnitude_bytes", _magnitude_bytes);
    printer.register_value("has_phase", _has_phase);

    return printer;
}

} // namespace substructs
} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
