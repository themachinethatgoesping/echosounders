// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/beamgeometrybeamcontainer.doc.hpp"

// std includes
#include <cstddef>
#include <cstdint>

#include <xtensor/containers/xtensor.hpp>

// themachinethatgoesping import
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "beamgeometrybeam.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {
namespace substructs {

/**
 * @brief Container for the per-beam geometry of a 7004 BeamGeometry record.
 *
 * The 7004 record stores its per-beam values as separate arrays (structure of arrays) on disk, so
 * the container keeps those arrays (read as bulk block reads) and can either return them directly
 * or assemble a per-beam BeamGeometryBeam view on demand.
 */
class BeamGeometryBeamContainer
{
    xt::xtensor<float, 1> _beam_vertical_angle;   ///< along-track (vertical) angle (rad)
    xt::xtensor<float, 1> _beam_horizontal_angle; ///< across-track (horizontal) angle (rad)
    xt::xtensor<float, 1> _beamwidth_vertical;    ///< along-track (vertical) -3dB width (rad)
    xt::xtensor<float, 1> _beamwidth_horizontal;  ///< across-track (horizontal) -3dB width (rad)
    xt::xtensor<float, 1> _tx_delay;              ///< transmit delay (fractional samples, optional)
    bool                  _has_tx_delay = false;  ///< true if the tx_delay array is present

  public:
    BeamGeometryBeamContainer()  = default;
    ~BeamGeometryBeamContainer() = default;

    // ----- array access (structure of arrays, as stored on disk) -----
    const xt::xtensor<float, 1>& get_beam_vertical_angle() const { return _beam_vertical_angle; }
    const xt::xtensor<float, 1>& get_beam_horizontal_angle() const { return _beam_horizontal_angle; }
    const xt::xtensor<float, 1>& get_beamwidth_vertical() const { return _beamwidth_vertical; }
    const xt::xtensor<float, 1>& get_beamwidth_horizontal() const { return _beamwidth_horizontal; }
    const xt::xtensor<float, 1>& get_tx_delay() const { return _tx_delay; }
    bool                         get_has_tx_delay() const { return _has_tx_delay; }

    void set_beam_vertical_angle(const xt::xtensor<float, 1>& v) { _beam_vertical_angle = v; }
    void set_beam_horizontal_angle(const xt::xtensor<float, 1>& v) { _beam_horizontal_angle = v; }
    void set_beamwidth_vertical(const xt::xtensor<float, 1>& v) { _beamwidth_vertical = v; }
    void set_beamwidth_horizontal(const xt::xtensor<float, 1>& v) { _beamwidth_horizontal = v; }
    void set_tx_delay(const xt::xtensor<float, 1>& v) { _tx_delay = v; }
    void set_has_tx_delay(bool v) { _has_tx_delay = v; }

    // ----- mutable array access (used when reading the record in bulk) -----
    xt::xtensor<float, 1>& beam_vertical_angle() { return _beam_vertical_angle; }
    xt::xtensor<float, 1>& beam_horizontal_angle() { return _beam_horizontal_angle; }
    xt::xtensor<float, 1>& beamwidth_vertical() { return _beamwidth_vertical; }
    xt::xtensor<float, 1>& beamwidth_horizontal() { return _beamwidth_horizontal; }
    xt::xtensor<float, 1>& tx_delay() { return _tx_delay; }

    // ----- per-beam struct access (assembled on demand) -----
    BeamGeometryBeam get_beam(size_t beam_index) const;

    // ----- processed -----
    size_t get_number_of_beams() const;

    // ----- operators -----
    bool operator==(const BeamGeometryBeamContainer& other) const = default;

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
