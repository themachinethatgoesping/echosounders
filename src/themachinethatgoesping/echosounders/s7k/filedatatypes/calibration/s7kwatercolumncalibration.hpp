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

#include <themachinethatgoesping/pingprocessing/datatypes/calibration/multisectorwatercolumncalibration.hpp>
#include <themachinethatgoesping/pingprocessing/datatypes/calibration/watercolumncalibration.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {
namespace filedatatypes {
namespace calibration {

/**
 * @brief Water column calibration for Teledyne RESON 7k (and Norbit) systems.
 *
 * This is a first, uncalibrated setup. The power/ap/av calibrations carry the per-ping system gain
 * offset (transmit source level "power selection" + receiver "gain selection") and, for av, the
 * volume-scattering conversion factor derived from the effective pulse duration and sound velocity.
 * For CW the effective pulse duration is the nominal transmit pulse width; for a linear chirp (FM)
 * it is the matched-filter compressed duration (~ 1 / bandwidth), because the water column is the
 * compressed envelope. av is therefore an uncalibrated Sv (a first guess of Sv); the remaining fixed
 * calibration constant (equivalent beam angle, beam pattern, electronics offset) still has to be
 * added via a dedicated calibration before the result may be called a true Sv.
 */
class S7KWaterColumnCalibration
    : public pingprocessing::datatypes::calibration::WaterColumnCalibration
{
    using AmplitudeCalibration = pingprocessing::datatypes::calibration::AmplitudeCalibration;
    using t_base               = pingprocessing::datatypes::calibration::WaterColumnCalibration;

  protected:
    float _sound_velocity           = std::numeric_limits<float>::quiet_NaN();
    float _effective_pulse_duration = std::numeric_limits<float>::quiet_NaN();
    float _system_gain_offset       = std::numeric_limits<float>::quiet_NaN();

    bool _is_fm       = false; ///< whether the transmit pulse is a linear chirp (FM) rather than CW
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
                              float tvg_factor,
                              bool  is_fm = false);

    // ------ getters ------
    float get_sound_velocity() const { return _sound_velocity; }
    float get_effective_pulse_duration() const { return _effective_pulse_duration; }
    float get_system_gain_offset() const { return _system_gain_offset; }
    /// whether the effective pulse duration is the FM (matched-filter compressed) duration
    bool  is_fm() const { return _is_fm; }

    // ----- setup calibration for reson 7k systems -----
    /**
     * @brief Modify individual calibration parameters and recompute the power/ap/av calibrations.
     *
     * Only the supplied (non-nullopt) parameters are changed; the rest keep their current value.
     * This mirrors the kmall modify_* updater and is the supported way to tweak the (immutable)
     * base calibrations.
     */
    void modify_s7k_calibrations(std::optional<float> sound_velocity           = std::nullopt,
                                 std::optional<float> effective_pulse_duration = std::nullopt,
                                 std::optional<float> system_gain_offset       = std::nullopt,
                                 std::optional<float> tvg_absorption_db_m      = std::nullopt,
                                 std::optional<float> tvg_factor               = std::nullopt,
                                 std::optional<bool>  is_fm                    = std::nullopt);

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
// IGNORE_DOC:mkd_doc_themachinethatgoesping_pingprocessing_datatypes_calibration_hash_value
inline std::size_t hash_value(const S7KWaterColumnCalibration& arg)
{
    return arg.binary_hash();
}

using S7KMultiSectorWaterColumnCalibration =
    pingprocessing::datatypes::calibration::T_MultiSectorCalibration<S7KWaterColumnCalibration>;

} // namespace calibration
} // namespace filedatatypes
} // namespace s7k
} // namespace echosounders
} // namespace themachinethatgoesping
