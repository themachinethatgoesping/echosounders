// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/compressedwatercolumnbeam.doc.hpp"

// std includes
#include <cstdint>
#include <iosfwd>
#include <string>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../../types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {
namespace substructs {

/**
 * @brief Per-beam data of a 7042 CompressedWaterColumnData record, exactly as stored on disk.
 *
 * Holds the beam number, optional segment number, sample count and the raw (interleaved
 * magnitude[+phase]) sample bytes. The sample bytes are read straight from the stream into
 * _raw_samples (no intermediate copy). Decoding to magnitude/phase is done by the owning
 * CompressedWaterColumnBeamContainer, which knows the record-wide sample encoding.
 */
class CompressedWaterColumnBeam
{
    uint16_t    _beam_number    = 0; ///< beam number
    uint8_t     _segment_number = 0; ///< segment number (0 if segments are not used)
    uint32_t    _sample_count   = 0; ///< number of samples for this beam
    std::string _raw_samples;        ///< raw interleaved [magnitude][phase] sample bytes (on disk)

  public:
    CompressedWaterColumnBeam()  = default;
    ~CompressedWaterColumnBeam() = default;

    // ----- convenient member access -----
    uint16_t get_beam_number() const { return _beam_number; }
    uint8_t  get_segment_number() const { return _segment_number; }
    uint32_t get_sample_count() const { return _sample_count; }

    void set_beam_number(uint16_t val) { _beam_number = val; }
    void set_segment_number(uint8_t val) { _segment_number = val; }
    void set_sample_count(uint32_t val) { _sample_count = val; }

    const std::string& get_raw_samples() const { return _raw_samples; }
    void               set_raw_samples(const std::string& raw_samples) { _raw_samples = raw_samples; }

    // ----- stream i/o (read/write directly, no intermediate buffer) -----
    void read(std::istream& is, bool has_segment, size_t sample_stride);
    void to_stream(std::ostream& os, bool has_segment) const;

    // ----- operators -----
    bool operator==(const CompressedWaterColumnBeam& other) const = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};

} // namespace substructs
} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
