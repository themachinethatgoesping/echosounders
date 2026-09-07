// SPDX-FileCopyrightText: 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/s7kwatercolumncalibration.doc.hpp"

#include <iosfwd>
#include <limits>
#include <optional>
#include <string_view>

#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>

#include "../../../filetemplates/datatypes/calibration/multisectorwatercolumncalibration.hpp"
#include "../../../filetemplates/datatypes/calibration/watercolumncalibration.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace filedatatypes {
namespace calibration {

/**
 * @brief Water column calibration for Teledyne RESON 7k systems.
 *
 * This is a first, uncalibrated setup: the power/ap/av calibrations only carry the volume/point
 * conversion factor derived from the pulse duration and sound velocity (no system offset, no
 * per-beam/per-range calibration curves). av is therefore an uncalibrated Sv (a first guess of Sv);
 * a real Sv calibration (system offset, beam pattern, ...) still has to be added.
 */
class S7KWaterColumnCalibration
    : public filetemplates::datatypes::calibration::WaterColumnCalibration
{
    using AmplitudeCalibration = filetemplates::datatypes::calibration::AmplitudeCalibration;
    using t_base               = filetemplates::datatypes::calibration::WaterColumnCalibration;

  protected:
    float _sound_velocity           = std::numeric_limits<float>::quiet_NaN();
    float _effective_pulse_duration = std::numeric_limits<float>::quiet_NaN();
    float _system_gain_offset       = std::numeric_limits<float>::quiet_NaN();

    bool _initialized = false;

  public:
    S7KWaterColumnCalibration()
        : t_base()
    {
    }

    S7KWaterColumnCalibration(const t_base& other)
        : t_base(other)
    {
    }

    S7KWaterColumnCalibration(float sound_velocity,
                              float effective_pulse_duration,
                              float system_gain_offset,
                              float tvg_absorption_db_m,
                              float tvg_factor);

    // ------ getters ------
    float get_sound_velocity() const { return _sound_velocity; }
    float get_effective_pulse_duration() const { return _effective_pulse_duration; }
    float get_system_gain_offset() const { return _system_gain_offset; }

    // ----- setup calibration for reson 7k systems -----
    void setup_s7k_calibrations();

    // operator overloads
    bool operator==(const S7KWaterColumnCalibration& other) const;

    bool initialized() const { return _initialized; }

    void check_initialized() const override;
    void check_modifying_base_calibration_allowed() const override;

    // stream i/o
    static S7KWaterColumnCalibration from_stream(std::istream& is);
    void                             to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(S7KWaterColumnCalibration)
};

// boost hash
// IGNORE_DOC:mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_hash_value
inline std::size_t hash_value(const S7KWaterColumnCalibration& arg)
{
    return arg.binary_hash();
}

using S7KMultiSectorWaterColumnCalibration =
    filetemplates::datatypes::calibration::T_MultiSectorCalibration<S7KWaterColumnCalibration>;

} // namespace calibration
} // namespace filedatatypes
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
