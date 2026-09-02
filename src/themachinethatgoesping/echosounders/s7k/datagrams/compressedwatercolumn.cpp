// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "compressedwatercolumn.hpp"

#include <cstring>
#include <string>

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

void CompressedWaterColumn::__read__(std::istream& is, bool skip_data)
{
    is.read(reinterpret_cast<char*>(&_content), __content_size);

    const int64_t sample_position = int64_t(is.tellg());

    if (skip_data)
    {
        // remember the sample position so the samples can be read lazily later, then seek past them
        _beams.set_skipped(sample_position);
        is.seekg(std::streamoff(compute_size_content()) - std::streamoff(__content_size),
                 std::ios::cur);
        return;
    }

    __read_beams__(is);
}

void CompressedWaterColumn::__read_beams__(std::istream& is)
{
    const size_t B          = _content.number_beams;
    const int    mag_bytes  = get_magnitude_bytes();
    const bool   has_phase  = get_has_phase();
    const bool   phase_8bit = (_content.flags & FLAG_MAGNITUDE_DB) || (_content.flags & FLAG_32BIT_DATA);
    const bool   has_segment = (_content.flags & FLAG_SEGMENT_NUMBERS) != 0;
    const bool   mag_is_db   = get_magnitude_is_db();
    const bool   mag_32f     = (_content.flags & FLAG_32BIT_DATA) != 0;
    const size_t stride      = size_t(mag_bytes) + (has_phase ? (phase_8bit ? 1u : 2u) : 0u);

    // read the whole remaining record content in a single bulk read, then parse it in memory
    const size_t remaining = compute_size_content() - __content_size;
    std::string  buf(remaining, '\0');
    is.read(buf.data(), std::streamsize(remaining));

    auto& beams = _beams.beams();
    beams.resize(B);

    size_t pos = 0;
    for (size_t b = 0; b < B; ++b)
    {
        auto& beam = beams[b];

        uint16_t beam_number = 0;
        std::memcpy(&beam_number, buf.data() + pos, sizeof(beam_number));
        pos += sizeof(beam_number);

        uint8_t segment_number = 0;
        if (has_segment)
        {
            std::memcpy(&segment_number, buf.data() + pos, sizeof(segment_number));
            pos += sizeof(segment_number);
        }

        uint32_t nsamples = 0;
        std::memcpy(&nsamples, buf.data() + pos, sizeof(nsamples));
        pos += sizeof(nsamples);

        beam.set_beam_number(beam_number);
        beam.set_segment_number(segment_number);
        beam.set_sample_count(nsamples);
        beam.set_magnitude_bytes(uint8_t(mag_bytes));
        beam.set_has_phase(has_phase);
        beam.set_phase_8bit(phase_8bit);
        beam.set_magnitude_is_db(mag_is_db);
        beam.set_magnitude_is_32bit_float(mag_32f);

        const size_t nbytes = size_t(nsamples) * stride;
        beam.set_raw_samples(buf.substr(pos, nbytes));
        pos += nbytes;
    }
}

void CompressedWaterColumn::read_samples(std::istream& is)
{
    if (!_beams.get_samples_are_skipped())
        return;

    is.seekg(_beams.get_sample_position());
    __read_beams__(is);
    _beams.clear_skipped();
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

    const bool has_segment = (_content.flags & FLAG_SEGMENT_NUMBERS) != 0;

    for (const auto& beam : _beams.get_beams())
    {
        uint16_t beam_number = beam.get_beam_number();
        os.write(reinterpret_cast<const char*>(&beam_number), sizeof(beam_number));
        if (has_segment)
        {
            uint8_t segment_number = beam.get_segment_number();
            os.write(reinterpret_cast<const char*>(&segment_number), sizeof(segment_number));
        }
        uint32_t nsamples = beam.get_sample_count();
        os.write(reinterpret_cast<const char*>(&nsamples), sizeof(nsamples));

        const auto& raw = beam.get_raw_samples();
        os.write(raw.data(), std::streamsize(raw.size()));
    }
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

    printer.register_section("beams");
    printer.append(_beams.__printer__(float_precision, superscript_exponents));

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
