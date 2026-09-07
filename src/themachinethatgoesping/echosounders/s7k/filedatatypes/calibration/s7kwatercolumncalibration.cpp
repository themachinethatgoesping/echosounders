// SPDX-FileCopyrightText: 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#include "s7kwatercolumncalibration.hpp"

#include <cmath>
#include <istream>
#include <ostream>
#include <stdexcept>

#include <fmt/format.h>
#include <themachinethatgoesping/tools/helper/floatcompare.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace filedatatypes {
namespace calibration {

S7KWaterColumnCalibration::S7KWaterColumnCalibration(float sound_velocity,
                                                     float effective_pulse_duration,
                                                     float system_gain_offset,
                                                     float tvg_absorption_db_m,
                                                     float tvg_factor)
    : t_base(tvg_absorption_db_m, tvg_factor)
    , _sound_velocity(sound_velocity)
    , _effective_pulse_duration(effective_pulse_duration)
    , _system_gain_offset(system_gain_offset)
{
    setup_s7k_calibrations();
}

void S7KWaterColumnCalibration::setup_s7k_calibrations()
{
    // power is the raw amplitude data minus the system gain offset
    _power_calibration = std::make_unique<AmplitudeCalibration>(-_system_gain_offset);

    // ap is the same as power; absorption and tvg 40 (log r) are applied on top when requested
    _ap_calibration = std::make_unique<AmplitudeCalibration>(-_system_gain_offset);

    // av adds the volume-scattering conversion factor (effective ensonified volume for a point in
    // the water column) on top of ap; absorption and tvg 20 (log r) are applied when requested
    float av_factor = _effective_pulse_duration * _sound_velocity * 0.5f;
    if (std::isfinite(av_factor) && av_factor > 0.f)
        _av_calibration = std::make_unique<AmplitudeCalibration>(-10.f * std::log10(av_factor) -
                                                                 _system_gain_offset);
    else
        _av_calibration.reset();

    _initialized = true;
}

bool S7KWaterColumnCalibration::operator==(const S7KWaterColumnCalibration& other) const
{
    if (!WaterColumnCalibration::operator==(other))
        return false;

    return tools::helper::float_equals(_sound_velocity, other._sound_velocity) &&
           tools::helper::float_equals(_effective_pulse_duration, other._effective_pulse_duration) &&
           tools::helper::float_equals(_system_gain_offset, other._system_gain_offset);
}

void S7KWaterColumnCalibration::check_initialized() const
{
    if (!initialized())
        throw std::runtime_error(fmt::format("ERROR[{}]: Calibration not initialized, call "
                                             "setup_s7k_calibrations() first!",
                                             __func__));
}

void S7KWaterColumnCalibration::check_modifying_base_calibration_allowed() const
{
    throw std::runtime_error(fmt::format(
        "ERROR[{}]: Modifying base calibrations (power, ap, av) is not allowed for "
        "S7KWaterColumnCalibration. Modify the parameters and call setup_s7k_calibrations() to "
        "recompute, or convert to a generic WaterColumnCalibration(calibration).",
        __func__));
}

S7KWaterColumnCalibration S7KWaterColumnCalibration::from_stream(std::istream& is)
{
    S7KWaterColumnCalibration calibration(t_base::from_stream(is));

    is.read(reinterpret_cast<char*>(&calibration._sound_velocity), sizeof(float) * 3);
    is.read(reinterpret_cast<char*>(&calibration._initialized), sizeof(bool));

    return calibration;
}

void S7KWaterColumnCalibration::to_stream(std::ostream& os) const
{
    WaterColumnCalibration::to_stream(os);

    os.write(reinterpret_cast<const char*>(&_sound_velocity), sizeof(float) * 3);
    os.write(reinterpret_cast<const char*>(&_initialized), sizeof(bool));
}

tools::classhelper::ObjectPrinter S7KWaterColumnCalibration::__printer__(
    unsigned int float_precision,
    bool         superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer(
        "S7KWaterColumnCalibration", float_precision, superscript_exponents);

    printer.register_section("Reson 7k calibration");
    printer.register_value("Sound velocity", _sound_velocity, "m/s");
    printer.register_value("Effective pulse duration", _effective_pulse_duration, "s");
    printer.register_value("System gain offset", _system_gain_offset, "dB");

    printer.register_section("Generic calibration");
    printer.append(WaterColumnCalibration::__printer__(float_precision, superscript_exponents));

    return printer;
}

} // namespace calibration
} // namespace filedatatypes
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
