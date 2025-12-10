// SPDX-FileCopyrightText: 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/kmallwatercolumncalibration.doc.hpp"

#include <iosfwd>
#include <limits>
#include <optional>
#include <string_view>

#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../../../filetemplates/datatypes/calibration/multisectorwatercolumncalibration.hpp"
#include "../../../filetemplates/datatypes/calibration/watercolumncalibration.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace kmall {
namespace filedatatypes {
namespace calibration {

class KMALLWaterColumnCalibration
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
    KMALLWaterColumnCalibration()
        : t_base()
    {
    }

    KMALLWaterColumnCalibration(const t_base& other)
        : t_base(other)
    {
    }

    KMALLWaterColumnCalibration(float sound_velocity,
                                       float effective_pulse_duration,
                                       float system_gain_offset,
                                       float tvg_absorption_db_m,
                                       float tvg_factor);

    // ------ getters ------
    float get_sound_velocity() const { return _sound_velocity; }
    float get_effective_pulse_duration() const { return _effective_pulse_duration; }
    float get_system_gain_offset() const { return _system_gain_offset; }

    // ----- setup calibration for kongsberg em systems ----
    void modify_kongsberg_em_calibrations(
        std::optional<float> sound_velocity           = std::nullopt,
        std::optional<float> effective_pulse_duration = std::nullopt,
        std::optional<float> system_gain_offset       = std::nullopt,
        std::optional<float> tvg_absorption_db_m      = std::nullopt,
        std::optional<float> tvg_factor               = std::nullopt);

    void setup_kongsberg_em_calibrations();

    // operator overloads
    bool operator==(const KMALLWaterColumnCalibration& other) const;

    bool initialized() const { return _initialized; } // hash of default constructor

    void check_initialized() const override;
    
    void check_modifying_base_calibration_allowed() const override;

    void check_initialization() const;

    // stream i/o
    static KMALLWaterColumnCalibration from_stream(std::istream& is);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(KMALLWaterColumnCalibration)

  private:
    static void throw_because_value_is_note_finite(std::string_view value_name, float value);
};

// boost hash
// IGNORE_DOC:mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_hash_value
inline std::size_t hash_value(const KMALLWaterColumnCalibration& arg)
{
    return arg.binary_hash();
}

using KMALLMultiSectorWaterColumnCalibration =
    filetemplates::datatypes::calibration::T_MultiSectorCalibration<
        KMALLWaterColumnCalibration>;
}
}
}
}
}