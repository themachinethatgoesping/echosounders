// SPDX-FileCopyrightText: 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#include "kmallwatercolumncalibration.hpp"

#include <cmath>
#include <istream>
#include <ostream>
#include <stdexcept>

#include <fmt/core.h>
#include <themachinethatgoesping/algorithms/amplitudecorrection/functions.hpp>
#include <themachinethatgoesping/tools/helper/floatcompare.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace filedatatypes {
namespace calibration {

KMALLWaterColumnCalibration::KMALLWaterColumnCalibration(
    float sound_velocity,
    float effective_pulse_duration,
    float system_gain_offset,
    float tvg_absorption_db_m,
    float tvg_factor)
    : t_base(tvg_absorption_db_m, tvg_factor)
    , _sound_velocity(sound_velocity)
    , _effective_pulse_duration(effective_pulse_duration)
    , _system_gain_offset(system_gain_offset)
{
    setup_kongsberg_em_calibrations();
}

void KMALLWaterColumnCalibration::modify_kongsberg_em_calibrations(
    std::optional<float> sound_velocity,
    std::optional<float> effective_pulse_duration,
    std::optional<float> system_gain_offset,
    std::optional<float> tvg_absorption_db_m,
    std::optional<float> tvg_factor)
{
    if (sound_velocity)
        _sound_velocity = *sound_velocity;
    if (effective_pulse_duration)
        _effective_pulse_duration = *effective_pulse_duration;
    if (system_gain_offset)
        _system_gain_offset = *system_gain_offset;
    if (tvg_absorption_db_m)
        _tvg_absorption_db_m = *tvg_absorption_db_m;
    if (tvg_factor)
        _tvg_factor = *tvg_factor;

    setup_kongsberg_em_calibrations();
}

void KMALLWaterColumnCalibration::setup_kongsberg_em_calibrations()
{
    // power is the raw amplitude data substracted by the system gain offset
    _power_calibration = std::make_unique<AmplitudeCalibration>(-_system_gain_offset);

    // ap calibration is the same as power, however absorption and tvg 40 will be applied
    _ap_calibration = std::make_unique<AmplitudeCalibration>(-_system_gain_offset);

    // This catches the problem that the pulse duration is only saved in the
    // raw_range_and_angle datagram, but not in the watercolumn datagram
    // TODO: this should issue a warning in the log
    float av_factor = _effective_pulse_duration * _sound_velocity * 0.5f;
    if (std::isfinite(av_factor))
        _av_calibration = std::make_unique<AmplitudeCalibration>(-std::log10(av_factor) -
                                                                 _system_gain_offset);
    else
        _av_calibration.reset();

    _initialized = true;
    check_initialization();
}

bool KMALLWaterColumnCalibration::operator==(
    const KMALLWaterColumnCalibration& other) const
{
    if (!WaterColumnCalibration::operator==(other))
        return false;

    return tools::helper::float_equals(_sound_velocity, other._sound_velocity) &&
           tools::helper::float_equals(_effective_pulse_duration,
                                       other._effective_pulse_duration) &&
           tools::helper::float_equals(_system_gain_offset, other._system_gain_offset);
}

void KMALLWaterColumnCalibration::check_initialized() const
{
    if (!initialized())
        throw std::runtime_error(fmt::format("ERROR[{}]:Calibration not initialized, call "
                                             "setup_kongsberg_em_calibrations() first!",
                                             __func__));
}

void KMALLWaterColumnCalibration::check_modifying_base_calibration_allowed() const
{
    throw std::runtime_error(fmt::format(
        "ERROR[{}]:Modifying base calibrations (power, ap, av) is not allowed for "
        "KMALLWaterColumnCalibration. You may modify the parameters used for "
        "the calibration, and call setup_simrad_calibration() to recompute the "
        "calibration. You may also modify the used sp and sv calibrations. Alternatively you "
        "can explicitly convert the calibration to a generic calibration. using "
        "WaterColumnCalibration(calibration)",
        __func__));
}

void KMALLWaterColumnCalibration::check_initialization() const
{
    check_initialized();

    // Effective pulse duration is NAN if no raw_range_and_angle datagram is available, but not
    // in the watercolumn datagram. This problem is caught in the
    // setup_kongsberg_em_calibrations function by setting the av_calibration factor to 1
    // TODO: this should issue a warning in the log as
    // get_av is different if .wcd is read without .all
    // if (!std::isfinite(_effective_pulse_duration))
    //     throw_because_value_is_note_finite("effective_pulse_duration",
    //                                        _effective_pulse_duration);
    // if (!std::isfinite(_sound_velocity))
    //     throw_because_value_is_note_finite("sound_velocity", _sound_velocity);
    if (!std::isfinite(_system_gain_offset))
        throw_because_value_is_note_finite("system_gain_offset", _system_gain_offset);
}

KMALLWaterColumnCalibration KMALLWaterColumnCalibration::from_stream(std::istream& is)
{
    KMALLWaterColumnCalibration calibration(t_base::from_stream(is));

    is.read(reinterpret_cast<char*>(&calibration._sound_velocity), sizeof(float) * 3);

    return calibration;
}

void KMALLWaterColumnCalibration::to_stream(std::ostream& os) const
{
    WaterColumnCalibration::to_stream(os);

    os.write(reinterpret_cast<const char*>(&_sound_velocity), sizeof(float) * 3);
}

tools::classhelper::ObjectPrinter KMALLWaterColumnCalibration::__printer__(
    unsigned int float_precision, bool superscript_exponents) const
{
    tools::classhelper::ObjectPrinter printer("KMALLWaterColumnCalibration",
                                               float_precision,
                                               superscript_exponents);

    printer.register_section("Kongsberg EM calibration");
    printer.register_value("Sound velocity", _sound_velocity, "m/s");
    printer.register_value("Effective pulse duration", _effective_pulse_duration, "s");
    printer.register_value("System gain offset", _system_gain_offset, "dB");

    printer.register_section("Generic calibration");
    printer.append(WaterColumnCalibration::__printer__(float_precision, superscript_exponents));

    return printer;
}

void KMALLWaterColumnCalibration::throw_because_value_is_note_finite(std::string_view value_name,
                                                                            float value)
{
    throw std::runtime_error(fmt::format("ERROR[KMALLWaterColumnCalibration]:"
                                         "Calibration not initialized because {} is {}!",
                                         value_name,
                                         value));
}

}
}
}
}
}