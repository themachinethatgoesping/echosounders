// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "beamgeometrybeamcontainer.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {
namespace substructs {

BeamGeometryBeam BeamGeometryBeamContainer::get_beam(size_t beam_index) const
{
    BeamGeometryBeam beam;
    beam.set_beam_vertical_angle(_beam_vertical_angle.unchecked(beam_index));
    beam.set_beam_horizontal_angle(_beam_horizontal_angle.unchecked(beam_index));
    beam.set_beamwidth_vertical(_beamwidth_vertical.unchecked(beam_index));
    beam.set_beamwidth_horizontal(_beamwidth_horizontal.unchecked(beam_index));
    beam.set_has_tx_delay(_has_tx_delay);
    if (_has_tx_delay)
        beam.set_tx_delay(_tx_delay.unchecked(beam_index));
    return beam;
}

size_t BeamGeometryBeamContainer::get_number_of_beams() const
{
    return _beam_vertical_angle.size();
}

tools::classhelper::ObjectPrinter BeamGeometryBeamContainer::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "BeamGeometryBeamContainer", float_precision, superscript_exponents);

    printer.register_value("number_of_beams", get_number_of_beams());
    printer.register_value("has_tx_delay", _has_tx_delay);

    return printer;
}

} // namespace substructs
} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
