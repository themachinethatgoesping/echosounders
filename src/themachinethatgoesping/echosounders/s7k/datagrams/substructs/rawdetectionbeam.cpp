// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "rawdetectionbeam.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {
namespace substructs {

// ----- convenient member access -----
uint16_t RawDetectionBeam::get_beam_descriptor() const
{
    return _beam_descriptor;
}
float RawDetectionBeam::get_detection_point() const
{
    return _detection_point;
}
float RawDetectionBeam::get_rx_angle() const
{
    return _rx_angle;
}
uint32_t RawDetectionBeam::get_flags() const
{
    return _flags;
}
uint32_t RawDetectionBeam::get_quality() const
{
    return _quality;
}
float RawDetectionBeam::get_uncertainty() const
{
    return _uncertainty;
}
float RawDetectionBeam::get_signal_strength() const
{
    return _signal_strength;
}
float RawDetectionBeam::get_min_limit() const
{
    return _min_limit;
}
float RawDetectionBeam::get_max_limit() const
{
    return _max_limit;
}

void RawDetectionBeam::set_beam_descriptor(uint16_t val)
{
    _beam_descriptor = val;
}
void RawDetectionBeam::set_detection_point(float val)
{
    _detection_point = val;
}
void RawDetectionBeam::set_rx_angle(float val)
{
    _rx_angle = val;
}
void RawDetectionBeam::set_flags(uint32_t val)
{
    _flags = val;
}
void RawDetectionBeam::set_quality(uint32_t val)
{
    _quality = val;
}
void RawDetectionBeam::set_uncertainty(float val)
{
    _uncertainty = val;
}
void RawDetectionBeam::set_signal_strength(float val)
{
    _signal_strength = val;
}
void RawDetectionBeam::set_min_limit(float val)
{
    _min_limit = val;
}
void RawDetectionBeam::set_max_limit(float val)
{
    _max_limit = val;
}

// ----- objectprinter -----
tools::classhelper::ObjectPrinter RawDetectionBeam::__printer__(unsigned int float_precision,
                                                                bool superscript_exponents) const
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

} // namespace substructs
} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
