// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "compressedwatercolumn.hpp"

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
    // record-wide sample encoding (from the flags), stored once on the container
    _beams.set_magnitude_bytes(get_magnitude_bytes());
    _beams.set_has_phase(get_has_phase());
    _beams.set_phase_8bit((_content.flags & FLAG_MAGNITUDE_DB) || (_content.flags & FLAG_32BIT_DATA));
    _beams.set_magnitude_is_db(get_magnitude_is_db());
    _beams.set_magnitude_is_32bit_float((_content.flags & FLAG_32BIT_DATA) != 0);

    const bool   has_segment = (_content.flags & FLAG_SEGMENT_NUMBERS) != 0;
    const size_t stride      = _beams.get_sample_stride();

    auto& beams = _beams.beams();
    beams.resize(_content.number_beams);

    // each beam reads its header and (raw) sample block directly from the stream (no extra copy)
    for (auto& beam : beams)
        beam.read(is, has_segment, stride);
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
        beam.to_stream(os, has_segment);
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
