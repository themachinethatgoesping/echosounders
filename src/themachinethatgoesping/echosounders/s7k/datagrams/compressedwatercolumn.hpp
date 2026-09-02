// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/compressedwatercolumn.doc.hpp"

// std includes
#include <cstdint>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../types.hpp"
#include "s7kdatagram.hpp"
#include "substructs/compressedwatercolumnbeamcontainer.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {

/**
 * @brief 7k record CompressedWaterColumnData: per-beam water-column magnitude (and optional
 * phase) time series in a compressed (downsampled and/or bit-reduced) form.
 *
 * The exact sample encoding (magnitude bit depth, presence of phase, downsampling) is controlled by
 * the flags bit field. This class decodes the magnitude to float and the phase to radians for
 * convenient access.
 */
class CompressedWaterColumn : public S7KDatagram
{
  public:
    static constexpr auto DatagramIdentifier = t_S7KDatagramIdentifier::CompressedWaterColumnData;

    // flag bits
    static constexpr uint32_t FLAG_MAGNITUDE_ONLY = 1u << 1; ///< strip phase
    static constexpr uint32_t FLAG_MAGNITUDE_DB   = 1u << 2; ///< 8-bit dB magnitude / 8-bit phase
    static constexpr uint32_t FLAG_32BIT_DATA     = 1u << 12; ///< 32-bit magnitude
    static constexpr uint32_t FLAG_SEGMENT_NUMBERS = 1u << 14; ///< per-beam segment number present

  protected:
#pragma pack(push, 1)
    struct Content
    {
        uint64_t serial_number;      ///< sonar serial number
        uint32_t ping_number;        ///< sequential ping number
        uint16_t multi_ping;         ///< 0 = single ping, else multi-ping sequence number
        uint16_t number_beams;       ///< number of beams
        uint32_t samples;            ///< nominal number of samples (based on range)
        uint32_t compressed_samples; ///< maximum number of samples over all beams
        uint32_t flags;              ///< compression control flags bit field
        uint32_t first_sample;       ///< first sample index for each beam
        float    sample_rate;        ///< effective sample rate after downsampling (Hz)
        float    compression_factor; ///< magnitude compression factor
        uint32_t reserved;           ///< reserved

        bool operator==(const Content& other) const = default;
    } _content;
#pragma pack(pop)

    static constexpr size_t __content_size = sizeof(Content); // 44

    substructs::CompressedWaterColumnBeamContainer _beams; ///< per-beam magnitude/phase data

  public:
    CompressedWaterColumn()  = default;
    ~CompressedWaterColumn() = default;

    // ----- record type header access -----
    uint64_t get_serial_number() const { return _content.serial_number; }
    uint32_t get_ping_number() const { return _content.ping_number; }
    uint16_t get_multi_ping() const { return _content.multi_ping; }
    uint16_t get_number_beams() const { return _content.number_beams; }
    uint32_t get_samples() const { return _content.samples; }
    uint32_t get_compressed_samples() const { return _content.compressed_samples; }
    uint32_t get_flags() const { return _content.flags; }
    uint32_t get_first_sample() const { return _content.first_sample; }
    float    get_sample_rate() const { return _content.sample_rate; }
    float    get_compression_factor() const { return _content.compression_factor; }

    void set_serial_number(uint64_t val) { _content.serial_number = val; }
    void set_ping_number(uint32_t val) { _content.ping_number = val; }
    void set_multi_ping(uint16_t val) { _content.multi_ping = val; }
    void set_number_beams(uint16_t val) { _content.number_beams = val; }
    void set_samples(uint32_t val) { _content.samples = val; }
    void set_compressed_samples(uint32_t val) { _content.compressed_samples = val; }
    void set_flags(uint32_t val) { _content.flags = val; }
    void set_first_sample(uint32_t val) { _content.first_sample = val; }
    void set_sample_rate(float val) { _content.sample_rate = val; }
    void set_compression_factor(float val) { _content.compression_factor = val; }

    bool get_has_phase() const { return (_content.flags & FLAG_MAGNITUDE_ONLY) == 0; }
    bool get_magnitude_is_db() const { return (_content.flags & FLAG_MAGNITUDE_DB) != 0; }
    /// number of bytes per magnitude sample as stored on disk (1, 2 or 4)
    int get_magnitude_bytes() const
    {
        if (_content.flags & FLAG_32BIT_DATA)
            return 4;
        if (_content.flags & FLAG_MAGNITUDE_DB)
            return 1;
        return 2;
    }

    // ----- substructure access -----
    const substructs::CompressedWaterColumnBeamContainer& get_beams() const { return _beams; }
    substructs::CompressedWaterColumnBeamContainer&       beams() { return _beams; }
    void set_beams(const substructs::CompressedWaterColumnBeamContainer& beams) { _beams = beams; }

    // ----- operators -----
    bool operator==(const CompressedWaterColumn& other) const = default;

    //----- to/from stream functions -----
    static CompressedWaterColumn from_stream(std::istream& is, S7KDatagram header, bool skip_data = false);
    static CompressedWaterColumn from_stream(std::istream& is, bool skip_data = false);
    static CompressedWaterColumn from_stream(std::istream&           is,
                                             o_S7KDatagramIdentifier datagram_identifier,
                                             bool                    skip_data = false);

    void to_stream(std::ostream& os) const;

    /**
     * @brief Read the (previously skipped) per-beam samples from the stream.
     * @param is Input stream. Must be the same file the record was originally read from.
     */
    void read_samples(std::istream& is);

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(CompressedWaterColumn)

  private:
    explicit CompressedWaterColumn(S7KDatagram header)
        : S7KDatagram(std::move(header))
    {
    }
    void __read__(std::istream& is, bool skip_data = false);
    void __read_beams__(std::istream& is);
};

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
