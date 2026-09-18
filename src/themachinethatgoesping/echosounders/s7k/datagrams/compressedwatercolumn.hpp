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

    // flag bits (Table 83)
    static constexpr uint32_t FLAG_USE_MAX_BOTTOM_DETECTION = 1u << 0;  ///< limit to bottom + 10%
    static constexpr uint32_t FLAG_MAGNITUDE_ONLY           = 1u << 1;  ///< strip phase
    static constexpr uint32_t FLAG_MAGNITUDE_DB             = 1u << 2;  ///< 8-bit dB mag / 8-bit phase
    static constexpr uint32_t FLAG_32BIT_DATA               = 1u << 12; ///< 32-bit magnitude
    static constexpr uint32_t FLAG_COMPRESSION_FACTOR       = 1u << 13; ///< compression factor avail
    static constexpr uint32_t FLAG_SEGMENT_NUMBERS          = 1u << 14; ///< per-beam segment number
    static constexpr uint32_t FLAG_FIRST_SAMPLE_RXDELAY     = 1u << 15; ///< first sample = RxDelay

  protected:
#pragma pack(push, 1)
    struct Content
    {
        uint64_t _serial_number      = 0;   ///< sonar serial number
        uint32_t _ping_number        = 0;   ///< sequential ping number
        uint16_t _multi_ping         = 0;   ///< 0 = single ping, else multi-ping sequence number
        uint16_t _number_beams       = 0;   ///< number of beams
        uint32_t _samples            = 0;   ///< nominal number of samples (based on range)
        uint32_t _compressed_samples = 0;   ///< maximum number of samples over all beams
        uint32_t _flags              = 0;   ///< compression control flags bit field
        uint32_t _first_sample       = 0;   ///< first sample index for each beam
        float    _sample_rate        = 0.f; ///< effective sample rate after downsampling (Hz)
        float    _compression_factor = 0.f; ///< magnitude compression factor
        uint32_t _reserved           = 0;   ///< reserved

        bool operator==(const Content& other) const = default;
    } _content;
#pragma pack(pop)

    static constexpr size_t __content_size = sizeof(Content); // 44

    substructs::CompressedWaterColumnBeamContainer _beams; ///< per-beam magnitude/phase data

    uint32_t _checksum = 0; ///< record checksum (last 4 bytes; see S7KDatagram, debugging only)

  public:
    CompressedWaterColumn();
    ~CompressedWaterColumn() = default;

    // ----- record type header access -----
    uint64_t get_serial_number() const;
    uint32_t get_ping_number() const;
    uint16_t get_multi_ping() const;
    uint16_t get_number_beams() const;
    uint32_t get_samples() const;
    uint32_t get_compressed_samples() const;
    uint32_t get_flags() const;
    uint32_t get_first_sample() const;
    float    get_sample_rate() const;
    float    get_compression_factor() const;
    uint32_t get_checksum() const;

    void set_serial_number(uint64_t val);
    void set_ping_number(uint32_t val);
    void set_multi_ping(uint16_t val);
    void set_number_beams(uint16_t val);
    void set_samples(uint32_t val);
    void set_compressed_samples(uint32_t val);
    void set_flags(uint32_t val);
    void set_first_sample(uint32_t val);
    void set_sample_rate(float val);
    void set_compression_factor(float val);
    void set_checksum(uint32_t val);

    // ----- processed (decoded flags) -----
    /// Bit 0: water column data is limited to the bottom detection point (+10%).
    bool get_flag_use_maximum_bottom_detection() const;
    /// Bit 1: only intensity (magnitude) data is included, phase is stripped.
    bool get_flag_intensity_only() const;
    /// Bit 2: magnitude is converted to dB and stored as an 8-bit value (phase as 8-bit).
    bool get_flag_magnitude_to_db() const;
    /// Bit 12: magnitude is stored as 32-bit values.
    bool get_flag_32bit_data() const;
    /// Bit 13: a custom compression factor is available (else a factor of 40 is used).
    bool get_flag_compression_factor_available() const;
    /// Bit 14: per-beam segment numbers are available.
    bool get_flag_segment_numbers_available() const;
    /// Bit 15: the first sample contains the RxDelay value.
    bool get_flag_first_sample_is_rxdelay() const;
    /// Bits 4-7: downsampling divisor (1 means no downsampling).
    uint8_t get_downsampling_divisor() const;
    /// Bits 8-11: downsampling type (0 none, 1 middle, 2 peak, 3 average).
    uint8_t get_downsampling_type() const;

    /// whether the record contains phase data (derived from bit 1)
    bool get_has_phase() const;
    /// whether the magnitude is stored as 8-bit dB values (derived from bit 2)
    bool get_magnitude_is_db() const;
    /// number of bytes per magnitude sample as stored on disk (1, 2 or 4)
    int get_magnitude_bytes() const;

    // ----- substructure access -----
    const substructs::CompressedWaterColumnBeamContainer& get_beams() const;
    substructs::CompressedWaterColumnBeamContainer&       beams();
    void set_beams(const substructs::CompressedWaterColumnBeamContainer& beams);

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
    explicit CompressedWaterColumn(S7KDatagram header);
    void __read__(std::istream& is, bool skip_data = false);
    void __read_beams__(std::istream& is);
};

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
