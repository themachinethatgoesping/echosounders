// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/rawdetectionbeam.doc.hpp"

// std includes
#include <cstdint>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../../types.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {
namespace substructs {

/**
 * @brief Per-beam raw detection (7027 RawDetectionData beam record).
 *
 * This is the per-beam detection record. Its on-disk size (the record's data_field_size) is 22, 26,
 * 30 or 34 bytes depending on the record version; trailing fields that are not present are filled
 * with NaN when the record is read. The first 34 bytes are represented here.
 */
#pragma pack(push, 1)
class RawDetectionBeam
{
    uint16_t _beam_descriptor = 0; ///< beam number
    float    _detection_point = 0.f; ///< detection point (fractional sample number)
    float    _rx_angle        = 0.f; ///< receive steering angle (rad)
    uint32_t _flags           = 0; ///< per-beam flags (magnitude/phase detection, quality type, ...)
    uint32_t _quality         = 0; ///< per-beam quality (brightness/colinearity filter passed)
    float    _uncertainty     = 0.f; ///< detection uncertainty (normalized to detection point)
    float    _signal_strength = 0.f; ///< detection signal strength
    float    _min_limit       = 0.f; ///< detection gate minimum sample
    float    _max_limit       = 0.f; ///< detection gate maximum sample

  public:
    RawDetectionBeam()  = default;
    ~RawDetectionBeam() = default;

    // ----- convenient member access -----
    uint16_t get_beam_descriptor() const;
    float    get_detection_point() const;
    float    get_rx_angle() const;
    uint32_t get_flags() const;
    uint32_t get_quality() const;
    float    get_uncertainty() const;
    float    get_signal_strength() const;
    float    get_min_limit() const;
    float    get_max_limit() const;

    void set_beam_descriptor(uint16_t val);
    void set_detection_point(float val);
    void set_rx_angle(float val);
    void set_flags(uint32_t val);
    void set_quality(uint32_t val);
    void set_uncertainty(float val);
    void set_signal_strength(float val);
    void set_min_limit(float val);
    void set_max_limit(float val);

    // ----- operators -----
    bool operator==(const RawDetectionBeam& other) const = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};
#pragma pack(pop)

} // namespace substructs
} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
