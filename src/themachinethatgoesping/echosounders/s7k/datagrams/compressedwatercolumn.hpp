// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/compressedwatercolumn.doc.hpp"

// std includes
#include <cstdint>
#include <vector>

#include <xtensor/containers/xtensor.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../types.hpp"
#include "s7kdatagram.hpp"

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

    // per-beam meta data (length = number_beams)
    xt::xtensor<uint16_t, 1> _beam_number;
    xt::xtensor<uint8_t, 1>  _segment_number;
    xt::xtensor<uint32_t, 1> _sample_count;

    // decoded per-beam samples (one array per beam)
    std::vector<xt::xtensor<float, 1>> _magnitude; ///< magnitude (raw value, or dB if FLAG_MAGNITUDE_DB)
    std::vector<xt::xtensor<float, 1>> _phase;     ///< phase in radians (empty beams if magnitude only)

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

    // ----- per-beam data access -----
    const xt::xtensor<uint16_t, 1>& get_beam_number() const { return _beam_number; }
    const xt::xtensor<uint8_t, 1>&  get_segment_number() const { return _segment_number; }
    const xt::xtensor<uint32_t, 1>& get_sample_count() const { return _sample_count; }

    /// magnitude arrays (one per beam; dB if get_magnitude_is_db(), else raw magnitude)
    const std::vector<xt::xtensor<float, 1>>& get_magnitude() const { return _magnitude; }
    /// phase arrays in radians (one per beam; empty if magnitude-only)
    const std::vector<xt::xtensor<float, 1>>& get_phase() const { return _phase; }
    const xt::xtensor<float, 1>& get_beam_magnitude(size_t beam_index) const
    {
        return _magnitude.at(beam_index);
    }
    const xt::xtensor<float, 1>& get_beam_phase(size_t beam_index) const
    {
        return _phase.at(beam_index);
    }

    // ----- convenience conversions (computed on demand) -----
    /// magnitude of a single beam in decibels. If the data is already stored in dB
    /// (get_magnitude_is_db(), flag bit 2) the stored value is returned unchanged; otherwise the
    /// linear magnitude is converted with 20*log10(magnitude / full_scale) (full_scale = 65535 for
    /// 16-bit magnitude, 1 for 32-bit float magnitude). Zero magnitude maps to -inf.
    xt::xtensor<float, 1> get_beam_magnitude_in_db(size_t beam_index) const;
    /// phase of a single beam in degrees (empty if magnitude-only)
    xt::xtensor<float, 1> get_beam_phase_in_degrees(size_t beam_index) const;
    /// magnitude in dB, one array per beam (see get_beam_magnitude_in_db)
    std::vector<xt::xtensor<float, 1>> get_magnitude_in_db() const;
    /// phase in degrees, one array per beam (see get_beam_phase_in_degrees)
    std::vector<xt::xtensor<float, 1>> get_phase_in_degrees() const;

    // ----- operators -----
    bool operator==(const CompressedWaterColumn& other) const = default;

    //----- to/from stream functions -----
    static CompressedWaterColumn from_stream(std::istream& is, S7KDatagram header);
    static CompressedWaterColumn from_stream(std::istream& is);
    static CompressedWaterColumn from_stream(std::istream&           is,
                                             t_S7KDatagramIdentifier datagram_identifier);

    void to_stream(std::ostream& os) const;

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
    void __read__(std::istream& is);
};

} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
