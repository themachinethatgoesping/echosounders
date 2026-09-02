// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/compressedwatercolumnbeam.doc.hpp"

// std includes
#include <cstdint>
#include <string>

#include <xtensor/containers/xtensor.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../../types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {
namespace substructs {

/**
 * @brief Per-beam data of a 7042 CompressedWaterColumnData record.
 *
 * The magnitude (and optional phase) samples are kept as the raw (interleaved) on-disk bytes and
 * decoded on demand. The sample encoding (magnitude bit depth, presence and bit depth of phase) is
 * controlled by the record flags and stored per beam so each beam can decode itself.
 */
class CompressedWaterColumnBeam
{
    uint16_t    _beam_number    = 0; ///< beam number
    uint8_t     _segment_number = 0; ///< segment number (0 if segments are not used)
    uint32_t    _sample_count   = 0; ///< number of samples for this beam
    std::string _raw_samples;        ///< raw interleaved [magnitude][phase] sample bytes

    // decode parameters (record flags, stored per beam for self-contained decoding)
    uint8_t _magnitude_bytes          = 2;     ///< bytes per magnitude sample (1, 2 or 4)
    bool    _has_phase                = false; ///< true if a phase value follows each magnitude
    bool    _phase_8bit               = false; ///< true if the phase is 8-bit (else 16-bit)
    bool    _magnitude_is_db          = false; ///< true if the magnitude is already stored in dB
    bool    _magnitude_is_32bit_float = false; ///< true if the magnitude is 32-bit IEEE float

  public:
    CompressedWaterColumnBeam()  = default;
    ~CompressedWaterColumnBeam() = default;

    // ----- meta data access -----
    uint16_t get_beam_number() const { return _beam_number; }
    uint8_t  get_segment_number() const { return _segment_number; }
    uint32_t get_sample_count() const { return _sample_count; }

    void set_beam_number(uint16_t val) { _beam_number = val; }
    void set_segment_number(uint8_t val) { _segment_number = val; }
    void set_sample_count(uint32_t val) { _sample_count = val; }

    // ----- decode parameters -----
    uint8_t get_magnitude_bytes() const { return _magnitude_bytes; }
    bool    get_has_phase() const { return _has_phase; }
    bool    get_phase_8bit() const { return _phase_8bit; }
    bool    get_magnitude_is_db() const { return _magnitude_is_db; }
    bool    get_magnitude_is_32bit_float() const { return _magnitude_is_32bit_float; }

    void set_magnitude_bytes(uint8_t val) { _magnitude_bytes = val; }
    void set_has_phase(bool val) { _has_phase = val; }
    void set_phase_8bit(bool val) { _phase_8bit = val; }
    void set_magnitude_is_db(bool val) { _magnitude_is_db = val; }
    void set_magnitude_is_32bit_float(bool val) { _magnitude_is_32bit_float = val; }

    /// number of on-disk bytes per sample (magnitude + optional phase)
    size_t get_sample_stride() const
    {
        return size_t(_magnitude_bytes) + (_has_phase ? (_phase_8bit ? 1u : 2u) : 0u);
    }

    // ----- raw sample access -----
    const std::string& get_raw_samples() const { return _raw_samples; }
    void               set_raw_samples(const std::string& raw_samples) { _raw_samples = raw_samples; }

    // ----- decoded sample access (computed on demand) -----
    /// magnitude of this beam (raw value, or dB if get_magnitude_is_db())
    xt::xtensor<float, 1> get_magnitude() const;
    /// phase of this beam in radians (empty if there is no phase)
    xt::xtensor<float, 1> get_phase() const;
    /// magnitude of this beam in dB (see CompressedWaterColumn::get_beam_magnitude_in_db)
    xt::xtensor<float, 1> get_magnitude_in_db() const;
    /// phase of this beam in degrees (empty if there is no phase)
    xt::xtensor<float, 1> get_phase_in_degrees() const;

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
