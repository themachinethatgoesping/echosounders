// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "compressedwatercolumn.hpp"

#include <cmath>
#include <limits>
#include <numbers>

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

namespace {
constexpr float S7K_PHASE_SCALE = 10430.f; ///< int16 phase value / 10430 = radians
}

void CompressedWaterColumn::__read__(std::istream& is, bool skip_data)
{
    is.read(reinterpret_cast<char*>(&_content), __content_size);

    if (skip_data)
    {
        // skip the (large) per-beam sample data; leave the per-beam arrays empty
        is.seekg(std::streamoff(compute_size_content()) - std::streamoff(__content_size),
                 std::ios::cur);
        return;
    }

    const size_t B         = _content.number_beams;
    const int    mag_bytes = get_magnitude_bytes();
    const bool   has_phase = get_has_phase();
    const bool   phase_8bit =
        (_content.flags & FLAG_MAGNITUDE_DB) || (_content.flags & FLAG_32BIT_DATA);
    const bool has_segment = (_content.flags & FLAG_SEGMENT_NUMBERS) != 0;

    _beam_number.resize({ B });
    _segment_number.resize({ B });
    _sample_count.resize({ B });
    _magnitude.resize(B);
    _phase.resize(B);

    for (size_t b = 0; b < B; ++b)
    {
        uint16_t beam_number = 0;
        is.read(reinterpret_cast<char*>(&beam_number), sizeof(beam_number));

        uint8_t segment_number = 0;
        if (has_segment)
            is.read(reinterpret_cast<char*>(&segment_number), sizeof(segment_number));

        uint32_t nsamples = 0;
        is.read(reinterpret_cast<char*>(&nsamples), sizeof(nsamples));

        _beam_number.unchecked(b)    = beam_number;
        _segment_number.unchecked(b) = segment_number;
        _sample_count.unchecked(b)   = nsamples;

        _magnitude[b].resize({ size_t(nsamples) });
        if (has_phase)
            _phase[b].resize({ size_t(nsamples) });

        for (uint32_t s = 0; s < nsamples; ++s)
        {
            // --- magnitude ---
            float m = 0.f;
            if (mag_bytes == 4)
            {
                float v = 0.f; // 32-bit magnitude is IEEE float32 (flag bit 12), not an integer
                is.read(reinterpret_cast<char*>(&v), 4);
                m = v;
            }
            else if (mag_bytes == 1)
            {
                uint8_t v = 0;
                is.read(reinterpret_cast<char*>(&v), 1);
                m = float(v);
            }
            else
            {
                uint16_t v = 0;
                is.read(reinterpret_cast<char*>(&v), 2);
                m = float(v);
            }
            _magnitude[b].unchecked(s) = m;

            // --- phase ---
            if (has_phase)
            {
                float p = 0.f;
                if (phase_8bit)
                {
                    int8_t v = 0;
                    is.read(reinterpret_cast<char*>(&v), 1);
                    // 8-bit phase is the high byte of the 16-bit phase value
                    p = float(int16_t(int16_t(v) << 8)) / S7K_PHASE_SCALE;
                }
                else
                {
                    int16_t v = 0;
                    is.read(reinterpret_cast<char*>(&v), 2);
                    p = float(v) / S7K_PHASE_SCALE;
                }
                _phase[b].unchecked(s) = p;
            }
        }
    }
}

CompressedWaterColumn CompressedWaterColumn::from_stream(std::istream& is, S7KDatagram header, bool skip_data)
{
    CompressedWaterColumn datagram(std::move(header));
    datagram.__read__(is, skip_data);
    return datagram;
}

CompressedWaterColumn CompressedWaterColumn::from_stream(std::istream& is, bool skip_data)
{
    return from_stream(is, S7KDatagram::from_stream(is), skip_data);
}

CompressedWaterColumn CompressedWaterColumn::from_stream(
    std::istream&           is,
    o_S7KDatagramIdentifier datagram_identifier,
    bool                    skip_data)
{
    return from_stream(is, S7KDatagram::from_stream(is, datagram_identifier), skip_data);
}

void CompressedWaterColumn::to_stream(std::ostream& os) const
{
    S7KDatagram::to_stream(os);
    os.write(reinterpret_cast<const char*>(&_content), __content_size);

    const size_t B         = _content.number_beams;
    const int    mag_bytes = get_magnitude_bytes();
    const bool   has_phase = get_has_phase();
    const bool   phase_8bit =
        (_content.flags & FLAG_MAGNITUDE_DB) || (_content.flags & FLAG_32BIT_DATA);
    const bool has_segment = (_content.flags & FLAG_SEGMENT_NUMBERS) != 0;

    for (size_t b = 0; b < B; ++b)
    {
        uint16_t beam_number = _beam_number.unchecked(b);
        os.write(reinterpret_cast<const char*>(&beam_number), sizeof(beam_number));
        if (has_segment)
        {
            uint8_t segment_number = _segment_number.unchecked(b);
            os.write(reinterpret_cast<const char*>(&segment_number), sizeof(segment_number));
        }
        uint32_t nsamples = _sample_count.unchecked(b);
        os.write(reinterpret_cast<const char*>(&nsamples), sizeof(nsamples));

        for (uint32_t s = 0; s < nsamples; ++s)
        {
            float m = _magnitude[b].unchecked(s);
            if (mag_bytes == 4)
            {
                float v = m; // 32-bit magnitude is IEEE float32 (flag bit 12)
                os.write(reinterpret_cast<const char*>(&v), 4);
            }
            else if (mag_bytes == 1)
            {
                uint8_t v = uint8_t(m);
                os.write(reinterpret_cast<const char*>(&v), 1);
            }
            else
            {
                uint16_t v = uint16_t(m);
                os.write(reinterpret_cast<const char*>(&v), 2);
            }

            if (has_phase)
            {
                float p = _phase[b].unchecked(s);
                if (phase_8bit)
                {
                    int8_t v = int8_t(int16_t(std::lround(p * S7K_PHASE_SCALE)) >> 8);
                    os.write(reinterpret_cast<const char*>(&v), 1);
                }
                else
                {
                    int16_t v = int16_t(std::lround(p * S7K_PHASE_SCALE));
                    os.write(reinterpret_cast<const char*>(&v), 2);
                }
            }
        }
    }
}

xt::xtensor<float, 1> CompressedWaterColumn::get_beam_magnitude_in_db(size_t beam_index) const
{
    const auto&           mag = _magnitude.at(beam_index);
    xt::xtensor<float, 1> db;
    db.resize({ mag.size() });

    if (get_magnitude_is_db())
    {
        // values are already stored in dB (8-bit truncated dB, flag bit 2): pass through unchanged
        for (size_t i = 0; i < mag.size(); ++i)
            db.unchecked(i) = mag.unchecked(i);
        return db;
    }

    // linear magnitude -> dB relative to full scale (65535 for 16-bit, 1 for 32-bit float)
    const float full_scale = (_content.flags & FLAG_32BIT_DATA) ? 1.f : 65535.f;
    const float neg_inf    = -std::numeric_limits<float>::infinity();
    for (size_t i = 0; i < mag.size(); ++i)
    {
        const float v   = mag.unchecked(i);
        db.unchecked(i) = v > 0.f ? 20.f * std::log10(v / full_scale) : neg_inf;
    }
    return db;
}

xt::xtensor<float, 1> CompressedWaterColumn::get_beam_phase_in_degrees(size_t beam_index) const
{
    const auto&           ph      = _phase.at(beam_index);
    constexpr float       rad2deg = 180.f / std::numbers::pi_v<float>;
    xt::xtensor<float, 1> deg;
    deg.resize({ ph.size() });
    for (size_t i = 0; i < ph.size(); ++i)
        deg.unchecked(i) = ph.unchecked(i) * rad2deg;
    return deg;
}

std::vector<xt::xtensor<float, 1>> CompressedWaterColumn::get_magnitude_in_db() const
{
    std::vector<xt::xtensor<float, 1>> out(_magnitude.size());
    for (size_t b = 0; b < _magnitude.size(); ++b)
        out[b] = get_beam_magnitude_in_db(b);
    return out;
}

std::vector<xt::xtensor<float, 1>> CompressedWaterColumn::get_phase_in_degrees() const
{
    std::vector<xt::xtensor<float, 1>> out(_phase.size());
    for (size_t b = 0; b < _phase.size(); ++b)
        out[b] = get_beam_phase_in_degrees(b);
    return out;
}

tools::classhelper::ObjectPrinter CompressedWaterColumn::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    const auto& o_datagram_identifier = S7KDatagram::o_DatagramIdentifier(DatagramIdentifier);
    tools::classhelper::ObjectPrinter printer(
        fmt::format("S7K {} ({})", o_datagram_identifier.name(), uint32_t(o_datagram_identifier)),
        float_precision,
        superscript_exponents);

    printer.append(S7KDatagram::__printer__(float_precision, superscript_exponents));
    printer.register_section("CompressedWaterColumn content");
    printer.register_value("serial_number", _content.serial_number);
    printer.register_value("ping_number", _content.ping_number);
    printer.register_value("multi_ping", _content.multi_ping);
    printer.register_value("number_beams", _content.number_beams);
    printer.register_value("samples", _content.samples);
    printer.register_value("compressed_samples", _content.compressed_samples);
    printer.register_value("flags", _content.flags);
    printer.register_value("first_sample", _content.first_sample);
    printer.register_value("sample_rate", _content.sample_rate, "Hz");
    printer.register_value("compression_factor", _content.compression_factor);
    printer.register_value("has_phase", get_has_phase());
    printer.register_value("magnitude_is_db", get_magnitude_is_db());
    printer.register_value("magnitude_bytes", get_magnitude_bytes());

    printer.register_section("per-beam samples");
    printer.register_container("beam_number", _beam_number);
    printer.register_container("sample_count", _sample_count, "samples");

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
