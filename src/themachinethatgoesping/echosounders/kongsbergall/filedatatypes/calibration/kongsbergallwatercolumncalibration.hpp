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
    float _beam_width_transmit      = std::numeric_limits<float>::quiet_NaN();
    float _beam_width_receive       = std::numeric_limits<float>::quiet_NaN();
    float _system_gain_offset       = std::numeric_limits<float>::quiet_NaN();
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
        compute_hash();
    }

    KongsbergAllWaterColumnCalibration(const t_base& other)
        : t_base(other)
    {
        compute_hash();
    }

    KongsbergAllWaterColumnCalibration(float sound_velocity,
                                       float effective_pulse_duration,
                                       float beam_width_transmit,
                                       float beam_width_receive,
                                       float system_gain_offset,
                                       float tvg_absorption_db_m,
                                       float tvg_factor)
        : t_base(tvg_absorption_db_m, tvg_factor)
        , _sound_velocity(sound_velocity)
        , _effective_pulse_duration(effective_pulse_duration)
        , _beam_width_transmit(beam_width_transmit)
        , _beam_width_receive(beam_width_receive)
        , _system_gain_offset(system_gain_offset)
    {
        setup_kongsberg_em_calibrations();
        compute_hash();
    }

    // ----- setup calibration for kongsberg em systems ----
    void setup_kongsberg_em_calibrations()
    {
        // power is the raw amplitude data substracted by the system gain offset
        _power_calibration = AmplitudeCalibration(-_system_gain_offset);

        // ap calibration is the same as power, however absorption and tvg 40 will be applied
        _ap_calibration = AmplitudeCalibration(-_system_gain_offset);

        // the beam apeture seems to be substracted for Kongsberg water column data already
        //static const float to_rad   = M_PI / 180.f;    // convert angle to rad
        //static const float to_rad_2 = to_rad * to_rad; // convert two multiplied angles to rad

        float av_factor = _effective_pulse_duration * _sound_velocity * 0.5f;
        //av_factor *= _beam_width_transmit * _beam_width_receive * to_rad_2;
        _av_calibration = AmplitudeCalibration(-10 * std::log10(av_factor) - _system_gain_offset);
    }

    // operator overloads
    bool operator==(const KongsbergAllWaterColumnCalibration& other) const
    {
        if (!WaterColumnCalibration::operator==(other))
            return false;

        return tools::helper::float_equals(_sound_velocity, other._sound_velocity) &&
               tools::helper::float_equals(_effective_pulse_duration,
                                           other._effective_pulse_duration) &&
               tools::helper::float_equals(_beam_width_transmit, other._beam_width_transmit) &&
               tools::helper::float_equals(_beam_width_receive, other._beam_width_receive) &&
               tools::helper::float_equals(_system_gain_offset, other._system_gain_offset);
    }

    bool initialized() const
    {
        return std::isfinite(_sound_velocity) && std::isfinite(_effective_pulse_duration) &&
               std::isfinite(_beam_width_transmit) && std::isfinite(_beam_width_receive) &&
               std::isfinite(_system_gain_offset);
    } // hash of default constructor

    // stream i/o
    static KongsbergAllWaterColumnCalibration from_stream(std::istream& is)
    {
        KongsbergAllWaterColumnCalibration calibration(t_base::from_stream(is));

        is.read(reinterpret_cast<char*>(&calibration._sound_velocity), sizeof(float) * 5);

        calibration.compute_hash();

        return calibration;
    }

    void to_stream(std::ostream& os) const
    {
        WaterColumnCalibration::to_stream(os);

        os.write(reinterpret_cast<const char*>(&_sound_velocity), sizeof(float) * 5);
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer("KongsbergAllWaterColumnCalibration",
                                                  float_precision, superscript_exponents);

        printer.register_section("Kongsberg EM calibration");
        printer.register_value("Sound velocity", _sound_velocity, "m/s");
        printer.register_value("Effective pulse duration", _effective_pulse_duration, "s");
        printer.register_value("Beam width transmit", _beam_width_transmit, "deg");
        printer.register_value("Beam width receive", _beam_width_receive, "deg");
        printer.register_value("System gain offset", _system_gain_offset, "dB");

        printer.register_section("Generic calibration");
        printer.append(WaterColumnCalibration::__printer__(float_precision, superscript_exponents));

        return printer;
    }

    uint64_t        cached_hash() const { return _hash; }
    xxh::hash_t<64> binary_hash() const override
    {

        xxh::hash3_state_t<64>               hash;
        boost::iostreams::stream<XXHashSink> stream(hash);

        WaterColumnCalibration::add_hash(stream);

        stream.write(reinterpret_cast<const char*>(&_sound_velocity), sizeof(float) * 5);

        stream.flush();
        return hash.digest();
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NO_HASH__(KongsbergAllWaterColumnCalibration)

  private:
    void compute_hash() { _hash = binary_hash(); }
};

// boost hash
// IGNORE_DOC:__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_hash_value
inline std::size_t hash_value(const KongsbergAllWaterColumnCalibration& arg)
{
    return arg.cached_hash();
}
}
}
}
}
}