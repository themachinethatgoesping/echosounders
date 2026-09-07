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
        // (up to the trailing 4-byte checksum, which is read here)
        _beams.set_skipped(sample_position);
        is.seekg(std::streamoff(compute_size_content()) - std::streamoff(__content_size) -
                     std::streamoff(sizeof(_checksum)),
                 std::ios::cur);
        is.read(reinterpret_cast<char*>(&_checksum), sizeof(_checksum));
        return;
    }

    __read_beams__(is);

    // read the trailing 4-byte checksum (stored for debugging only, not verified)
    is.read(reinterpret_cast<char*>(&_checksum), sizeof(_checksum));
}

void CompressedWaterColumn::__read_beams__(std::istream& is)
{
    // record-wide sample encoding (from the flags), stored once on the container
    _beams.set_magnitude_bytes(uint8_t(get_magnitude_bytes()));
    _beams.set_has_phase(get_has_phase());
    _beams.set_magnitude_is_db(get_magnitude_is_db());

    const bool has_segment = (_content._flags & FLAG_SEGMENT_NUMBERS) != 0;
    const auto type        = _beams.get_data_type();

    auto& beams = _beams.beams();
    beams.resize(_content._number_beams);

    // each beam reads its header and samples directly into the matching native-typed variant
    for (auto& beam : beams)
        beam.read(is, has_segment, type);
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

    const bool has_segment = (_content._flags & FLAG_SEGMENT_NUMBERS) != 0;
    for (const auto& beam : _beams.get_beams())
        beam.to_stream(os, has_segment);

    os.write(reinterpret_cast<const char*>(&_checksum), sizeof(_checksum));
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
    printer.register_value("serial_number", _content._serial_number);
    printer.register_value("ping_number", _content._ping_number);
    printer.register_value("multi_ping", _content._multi_ping);
    printer.register_value("number_beams", _content._number_beams);
    printer.register_value("samples", _content._samples);
    printer.register_value("compressed_samples", _content._compressed_samples);
    printer.register_value("flags", fmt::format("0b{:032b}", _content._flags));
    printer.register_value("first_sample", _content._first_sample);
    printer.register_value("sample_rate", _content._sample_rate, "Hz");
    printer.register_value("compression_factor", _content._compression_factor);
    printer.register_value("checksum", _checksum);

    printer.register_section("Processed (decoded flags)");
    printer.register_value("flag_use_maximum_bottom_detection",
                           get_flag_use_maximum_bottom_detection());
    printer.register_value("flag_intensity_only", get_flag_intensity_only());
    printer.register_value("flag_magnitude_to_db", get_flag_magnitude_to_db());
    printer.register_value("flag_32bit_data", get_flag_32bit_data());
    printer.register_value("flag_compression_factor_available",
                           get_flag_compression_factor_available());
    printer.register_value("flag_segment_numbers_available", get_flag_segment_numbers_available());
    printer.register_value("flag_first_sample_is_rxdelay", get_flag_first_sample_is_rxdelay());
    printer.register_value("downsampling_divisor", get_downsampling_divisor());
    printer.register_value("downsampling_type", get_downsampling_type());
    printer.register_value("has_phase", get_has_phase());
    printer.register_value("magnitude_is_db", get_magnitude_is_db());
    printer.register_value("magnitude_bytes", get_magnitude_bytes(), "bytes");

    printer.register_section("beams");
    printer.append(_beams.__printer__(float_precision, superscript_exponents));

    return printer;
}

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
