// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "attitudesample.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace datagrams {
namespace substructs {

// ----- convenient member access -----
uint16_t AttitudeSample::get_delta_time() const
{
    return _delta_time;
}
float AttitudeSample::get_roll() const
{
    return _roll;
}
float AttitudeSample::get_pitch() const
{
    return _pitch;
}
float AttitudeSample::get_heave() const
{
    return _heave;
}
float AttitudeSample::get_heading() const
{
    return _heading;
}

void AttitudeSample::set_delta_time(uint16_t val)
{
    _delta_time = val;
}
void AttitudeSample::set_roll(float val)
{
    _roll = val;
}
void AttitudeSample::set_pitch(float val)
{
    _pitch = val;
}
void AttitudeSample::set_heave(float val)
{
    _heave = val;
}
void AttitudeSample::set_heading(float val)
{
    _heading = val;
}

// ----- objectprinter -----
tools::classhelper::ObjectPrinter AttitudeSample::__printer__(unsigned int float_precision,
                                                              bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "AttitudeSample", float_precision, superscript_exponents);

    printer.register_value("delta_time", _delta_time, "ms");
    printer.register_value("roll", _roll, "rad");
    printer.register_value("pitch", _pitch, "rad");
    printer.register_value("heave", _heave, "m");
    printer.register_value("heading", _heading, "rad");

    return printer;
}

} // namespace substructs
} // namespace datagrams
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
