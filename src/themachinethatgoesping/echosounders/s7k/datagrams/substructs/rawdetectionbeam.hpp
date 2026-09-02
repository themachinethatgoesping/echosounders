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
    uint16_t get_beam_descriptor() const { return _beam_descriptor; }
    float    get_detection_point() const { return _detection_point; }
    float    get_rx_angle() const { return _rx_angle; }
    uint32_t get_flags() const { return _flags; }
    uint32_t get_quality() const { return _quality; }
    float    get_uncertainty() const { return _uncertainty; }
    float    get_signal_strength() const { return _signal_strength; }
    float    get_min_limit() const { return _min_limit; }
    float    get_max_limit() const { return _max_limit; }

    void set_beam_descriptor(uint16_t val) { _beam_descriptor = val; }
    void set_detection_point(float val) { _detection_point = val; }
    void set_rx_angle(float val) { _rx_angle = val; }
    void set_flags(uint32_t val) { _flags = val; }
    void set_quality(uint32_t val) { _quality = val; }
    void set_uncertainty(float val) { _uncertainty = val; }
    void set_signal_strength(float val) { _signal_strength = val; }
    void set_min_limit(float val) { _min_limit = val; }
    void set_max_limit(float val) { _max_limit = val; }

    // ----- operators -----
    bool operator==(const RawDetectionBeam& other) const = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            "RawDetectionBeam", float_precision, superscript_exponents);

        printer.register_value("beam_descriptor", _beam_descriptor);
        printer.register_value("detection_point", _detection_point, "samples");
        printer.register_value("rx_angle", _rx_angle, "rad");
        printer.register_value("flags", _flags);
        printer.register_value("quality", _quality);
        printer.register_value("uncertainty", _uncertainty);
        printer.register_value("signal_strength", _signal_strength);
        printer.register_value("min_limit", _min_limit, "samples");
        printer.register_value("max_limit", _max_limit, "samples");

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};
#pragma pack(pop)

} // namespace substructs
} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
