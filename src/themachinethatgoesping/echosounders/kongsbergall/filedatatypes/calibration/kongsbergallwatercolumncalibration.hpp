// SPDX-FileCopyrightText: 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/kongsbergallwatercolumncalibration.doc.hpp"

#include <fmt/core.h>
#include <themachinethatgoesping/algorithms/amplitudecorrection/functions.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/helper.hpp>
#include <themachinethatgoesping/tools/vectorinterpolators.hpp>

#include "../../../filetemplates/datatypes/calibration/multisectorwatercolumncalibration.hpp"
#include "../../../filetemplates/datatypes/calibration/watercolumncalibration.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {
namespace filedatatypes {
namespace calibration {

class KongsbergAllWaterColumnCalibration
    : public filetemplates::datatypes::calibration::WaterColumnCalibration
{
    using AmplitudeCalibration = filetemplates::datatypes::calibration::AmplitudeCalibration;
    using t_base               = filetemplates::datatypes::calibration::WaterColumnCalibration;

  protected:
    float _sound_velocity           = std::numeric_limits<float>::quiet_NaN();
    float _effective_pulse_duration = std::numeric_limits<float>::quiet_NaN();
    float _system_gain_offset       = std::numeric_limits<float>::quiet_NaN();

    bool _initialized = false;
    // // different types of offsets
    // AmplitudeCalibration _power_calibration;
    // AmplitudeCalibration _ap_calibration;
    // AmplitudeCalibration _av_calibration;
    // AmplitudeCalibration _sp_calibration;
    // AmplitudeCalibration _sv_calibration;

    // // water column corrections to be applied
    // float _absorption_db_m =
    //     std::numeric_limits<float>::quiet_NaN(); // new absorption that should be
    //                                              // applied to the data in dB/m

    // // factors that have been applied to the raw data by a TVG function
    // float _tvg_absorption_db_m = 0.0f; // the absorption applied to the data in dB/m
    // float _tvg_factor = 0.0f; // the TVG factor applied to the data (typically 0, 20 or 40
    // (log(r)))

    // uint64_t _hash;

  public:
    KongsbergAllWaterColumnCalibration()
        : t_base()
    {
    }

    KongsbergAllWaterColumnCalibration(const t_base& other)
        : t_base(other)
    {
    }

    KongsbergAllWaterColumnCalibration(float sound_velocity,
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

    // ------ getters ------
    float get_sound_velocity() const { return _sound_velocity; }
    float get_effective_pulse_duration() const { return _effective_pulse_duration; }
    float get_system_gain_offset() const { return _system_gain_offset; }

    // ----- setup calibration for kongsberg em systems ----
    void setup_kongsberg_em_calibrations()
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

    // operator overloads
    bool operator==(const KongsbergAllWaterColumnCalibration& other) const
    {
        if (!WaterColumnCalibration::operator==(other))
            return false;

        return tools::helper::float_equals(_sound_velocity, other._sound_velocity) &&
               tools::helper::float_equals(_effective_pulse_duration,
                                           other._effective_pulse_duration) &&
               tools::helper::float_equals(_system_gain_offset, other._system_gain_offset);
    }

    bool initialized() const { return _initialized; } // hash of default constructor

    void check_initialized() const override
    {
        if (!initialized())
            throw std::runtime_error(fmt::format("ERROR[{}]:Calibration not initialized, call "
                                                 "setup_kongsberg_em_calibrations() first!",
                                                 __func__));
    }
    void check_modifying_base_calibration_allowed() const override
    {
        throw std::runtime_error(fmt::format(
            "ERROR[{}]:Modifying base calibrations (power, ap, av) is not allowed for "
            "KongsbergAllWaterColumnCalibration. You may modify the parameters used for "
            "the calibration, and call setup_simrad_calibration() to recompute the "
            "calibration. You may also modify the used sp and sv calibrations. Alternatively you "
            "can explicitly convert the calibration to a generic calibration. using "
            "WaterColumnCalibration(calibration)",
            __func__));
    }

    void check_initialization() const
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

    // stream i/o
    static KongsbergAllWaterColumnCalibration from_stream(std::istream& is)
    {
        KongsbergAllWaterColumnCalibration calibration(t_base::from_stream(is));

        is.read(reinterpret_cast<char*>(&calibration._sound_velocity), sizeof(float) * 3);

        return calibration;
    }

    void to_stream(std::ostream& os) const
    {
        WaterColumnCalibration::to_stream(os);

        os.write(reinterpret_cast<const char*>(&_sound_velocity), sizeof(float) * 3);
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer(
            "KongsbergAllWaterColumnCalibration", float_precision, superscript_exponents);

        printer.register_section("Kongsberg EM calibration");
        printer.register_value("Sound velocity", _sound_velocity, "m/s");
        printer.register_value("Effective pulse duration", _effective_pulse_duration, "s");
        printer.register_value("System gain offset", _system_gain_offset, "dB");

        printer.register_section("Generic calibration");
        printer.append(WaterColumnCalibration::__printer__(float_precision, superscript_exponents));

        return printer;
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(KongsbergAllWaterColumnCalibration)

  private:
    static void throw_because_value_is_note_finite(std::string_view value_name, float value)
    {
        throw std::runtime_error(fmt::format("ERROR[KongsbergAllWaterColumnCalibration]:"
                                             "Calibration not initialized because {} is {}!",
                                             value_name,
                                             value));
    }
};

// boost hash
// IGNORE_DOC:__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_hash_value
inline std::size_t hash_value(const KongsbergAllWaterColumnCalibration& arg)
{
    return arg.binary_hash();
}

using KongsbergAllMultiSectorWaterColumnCalibration =
    filetemplates::datatypes::calibration::T_MultiSectorCalibration<
        KongsbergAllWaterColumnCalibration>;
}
}
}
}
}