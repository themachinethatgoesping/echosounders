// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/beamgeometrybeam.doc.hpp"

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
 * @brief Per-beam transmit/receive geometry of a 7004 BeamGeometry record.
 *
 * The 7004 record stores its per-beam values as separate arrays on disk (structure of arrays), so
 * the container (BeamGeometryBeamContainer) keeps the arrays and assembles this per-beam view on
 * demand.
 */
class BeamGeometryBeam
{
    float _beam_vertical_angle    = 0.f; ///< along-track (vertical) angle (rad)
    float _beam_horizontal_angle  = 0.f; ///< across-track (horizontal) angle (rad)
    float _beamwidth_vertical     = 0.f; ///< along-track (vertical) -3dB width (rad)
    float _beamwidth_horizontal   = 0.f; ///< across-track (horizontal) -3dB width (rad)
    float _tx_delay               = 0.f; ///< transmit delay (fractional samples, optional)
    bool  _has_tx_delay           = false; ///< true if the tx_delay value is present

  public:
    BeamGeometryBeam()  = default;
    ~BeamGeometryBeam() = default;

    // ----- convenient member access -----
    float get_beam_vertical_angle() const { return _beam_vertical_angle; }
    float get_beam_horizontal_angle() const { return _beam_horizontal_angle; }
    float get_beamwidth_vertical() const { return _beamwidth_vertical; }
    float get_beamwidth_horizontal() const { return _beamwidth_horizontal; }
    float get_tx_delay() const { return _tx_delay; }
    bool  get_has_tx_delay() const { return _has_tx_delay; }

    void set_beam_vertical_angle(float val) { _beam_vertical_angle = val; }
    void set_beam_horizontal_angle(float val) { _beam_horizontal_angle = val; }
    void set_beamwidth_vertical(float val) { _beamwidth_vertical = val; }
    void set_beamwidth_horizontal(float val) { _beamwidth_horizontal = val; }
    void set_tx_delay(float val) { _tx_delay = val; }
    void set_has_tx_delay(bool val) { _has_tx_delay = val; }

    // ----- operators -----
    bool operator==(const BeamGeometryBeam& other) const = default;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            "BeamGeometryBeam", float_precision, superscript_exponents);

        printer.register_value("beam_vertical_angle", _beam_vertical_angle, "rad");
        printer.register_value("beam_horizontal_angle", _beam_horizontal_angle, "rad");
        printer.register_value("beamwidth_vertical", _beamwidth_vertical, "rad");
        printer.register_value("beamwidth_horizontal", _beamwidth_horizontal, "rad");
        printer.register_value("has_tx_delay", _has_tx_delay);
        if (_has_tx_delay)
            printer.register_value("tx_delay", _tx_delay, "samples");

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
};

} // namespace substructs
} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
