// SPDX-FileCopyrightText: 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/watercolumncalibration.doc.hpp"

#include <fmt/core.h>
#include <themachinethatgoesping/algorithms/amplitudecorrection/functions.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/helper/floatcompare.hpp>



#include "amplitudecalibration.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datatypes {
namespace calibration {

class WaterColumnCalibration
{
  protected:
    // different types of offsets
    std::unique_ptr<AmplitudeCalibration> _power_calibration;
    std::unique_ptr<AmplitudeCalibration> _ap_calibration;
    std::unique_ptr<AmplitudeCalibration> _av_calibration;
    std::unique_ptr<AmplitudeCalibration> _sp_calibration;
    std::unique_ptr<AmplitudeCalibration> _sv_calibration;

    // water column corrections to be applied
    std::optional<float> _absorption_db_m; // new absorption that should be
                                           // applied to the data in dB/m

    // factors that have been applied to the raw data by a TVG function
    float _tvg_absorption_db_m = 0.0f; // the absorption applied to the data in dB/m
    float _tvg_factor = 0.0f; // the TVG factor applied to the data (typically 0, 20 or 40 (log(r)))

  public:
    enum class t_calibration_type
    {
        power,
        rp, /// power derived point scattering (uncalibrated TS without parameter and absorption compensation)
        rv, /// power derived volume scattering (uncalibrated SV without parameter and absorption compensation)
        pp, /// power derived point scattering (uncalibrated TS without parameter compensation)
        pv, /// power derived volume scattering (uncalibrated SV without parameter compensation)
        ap, /// amplitude derived point scattering (uncalibrated TS)
        av, /// amplitude derived volume scattering (uncalibrated SV)
        sp, /// point scattering (uncompensated TS)
        sv  /// volume scattering SV
    };

  public:
    WaterColumnCalibration(float tvg_absorption_db_m = 0.0f, float tvg_factor = 0.0f)
        : _tvg_absorption_db_m(tvg_absorption_db_m)
        , _tvg_factor(tvg_factor)
    {
    }
    WaterColumnCalibration(const AmplitudeCalibration& power_calibration,
                           const AmplitudeCalibration& ap_calibration,
                           const AmplitudeCalibration& av_calibration,
                           float                       tvg_absorption_db_m = 0.0f,
                           float                       tvg_factor          = 0.0f)
        : _power_calibration(std::make_unique<AmplitudeCalibration>(power_calibration))
        , _ap_calibration(std::make_unique<AmplitudeCalibration>(ap_calibration))
        , _av_calibration(std::make_unique<AmplitudeCalibration>(av_calibration))
        , _tvg_absorption_db_m(tvg_absorption_db_m)
        , _tvg_factor(tvg_factor)
    {
    }
    WaterColumnCalibration(const WaterColumnCalibration& other);

    virtual ~WaterColumnCalibration() = default;

    // this is used to check if parent classes are initialized
    virtual void check_initialized() const {}
    virtual void check_modifying_base_calibration_allowed() const {}

    // operator overloads

    void set_absorption_db_m(std::optional<float> value) { _absorption_db_m = value; }

    std::optional<float> get_absorption_to_apply(
        std::optional<float> absorption_db_m = std::nullopt) const;
    bool has_valid_absorption_db_m() const;

    std::optional<float> get_tvg_factor_to_apply(float tvg_factor) const;

    template<t_calibration_type       calibration_type,
             tools::helper::c_xtensor t_xtensor_2d,
             tools::helper::c_xtensor t_xtensor_1d>
    t_xtensor_2d apply_beam_sample_correction(const t_xtensor_2d& wci,
                                              const t_xtensor_1d& beam_angles,
                                              const t_xtensor_1d& ranges,
                                              int                 mp_cores = 1) const
    {
        this->check_initialized();

        if constexpr (calibration_type == t_calibration_type::power)
        {
            check_calibration_initialized(__func__, "Power calibration", _power_calibration);

            return _power_calibration->apply_beam_sample_correction(wci,
                                                                    beam_angles,
                                                                    ranges,
                                                                    get_absorption_to_apply(0),
                                                                    get_tvg_factor_to_apply(0),
                                                                    mp_cores);
        }
        else if constexpr (calibration_type == t_calibration_type::rp)
        {
            check_calibration_initialized(__func__, "Power calibration", _power_calibration);

            return _power_calibration->apply_beam_sample_correction(wci,
                                                                    beam_angles,
                                                                    ranges,
                                                                    get_absorption_to_apply(0),
                                                                    get_tvg_factor_to_apply(40),
                                                                    mp_cores);
        }
        else if constexpr (calibration_type == t_calibration_type::rv)
        {
            check_calibration_initialized(__func__, "Power calibration", _power_calibration);

            return _power_calibration->apply_beam_sample_correction(wci,
                                                                    beam_angles,
                                                                    ranges,
                                                                    get_absorption_to_apply(0),
                                                                    get_tvg_factor_to_apply(20),
                                                                    mp_cores);
        }
        else if constexpr (calibration_type == t_calibration_type::pp)
        {
            check_calibration_initialized(__func__, "Power calibration", _power_calibration);

            return _power_calibration->apply_beam_sample_correction(wci,
                                                                    beam_angles,
                                                                    ranges,
                                                                    get_absorption_to_apply(),
                                                                    get_tvg_factor_to_apply(40),
                                                                    mp_cores);
        }
        else if constexpr (calibration_type == t_calibration_type::pv)
        {
            check_calibration_initialized(__func__, "Power calibration", _power_calibration);

            return _power_calibration->apply_beam_sample_correction(wci,
                                                                    beam_angles,
                                                                    ranges,
                                                                    get_absorption_to_apply(),
                                                                    get_tvg_factor_to_apply(20),
                                                                    mp_cores);
        }
        else if constexpr (calibration_type == t_calibration_type::ap)
        {
            check_calibration_initialized(__func__, "Ap calibration", _ap_calibration);

            return _ap_calibration->apply_beam_sample_correction(wci,
                                                                 beam_angles,
                                                                 ranges,
                                                                 get_absorption_to_apply(),
                                                                 get_tvg_factor_to_apply(40),
                                                                 mp_cores);
        }
        else if constexpr (calibration_type == t_calibration_type::av)
        {
            check_calibration_initialized(__func__, "Av calibration", _av_calibration);

            return _av_calibration->apply_beam_sample_correction(wci,
                                                                 beam_angles,
                                                                 ranges,
                                                                 get_absorption_to_apply(),
                                                                 get_tvg_factor_to_apply(20),
                                                                 mp_cores);
        }
        else if constexpr (calibration_type == t_calibration_type::sp)
        {
            check_calibration_initialized(__func__, "Sp calibration", _sp_calibration);

            return _sp_calibration->apply_beam_sample_correction(wci,
                                                                 beam_angles,
                                                                 ranges,
                                                                 get_absorption_to_apply(),
                                                                 get_tvg_factor_to_apply(40),
                                                                 mp_cores);
        }
        else if constexpr (calibration_type == t_calibration_type::sv)
        {
            check_calibration_initialized(__func__, "Sv calibration", _sv_calibration);

            return _sv_calibration->apply_beam_sample_correction(wci,
                                                                 beam_angles,
                                                                 ranges,
                                                                 get_absorption_to_apply(),
                                                                 get_tvg_factor_to_apply(20),
                                                                 mp_cores);
        }
        throw std::runtime_error(
            fmt::format("ERROR[{}]:Unhandled calibration type {}. Please report.",
                        __func__,
                        magic_enum::enum_name(calibration_type)));
    }

    template<t_calibration_type       calibration_type,
             tools::helper::c_xtensor t_xtensor_2d,
             tools::helper::c_xtensor t_xtensor_1d>
    void inplace_beam_sample_correction(t_xtensor_2d&         wci,
                                        const t_xtensor_1d&   beam_angles,
                                        const t_xtensor_1d&   ranges,
                                        std::optional<size_t> min_beam_index = std::nullopt,
                                        std::optional<size_t> max_beam_index = std::nullopt,
                                        int                   mp_cores       = 1) const
    {
        this->check_initialized();

        if constexpr (calibration_type == t_calibration_type::power)
        {
            check_calibration_initialized(__func__, "Power calibration", _power_calibration);

            _power_calibration->inplace_beam_sample_correction(wci,
                                                               beam_angles,
                                                               ranges,
                                                               get_absorption_to_apply(0),
                                                               get_tvg_factor_to_apply(0),
                                                               min_beam_index,
                                                               max_beam_index,
                                                               mp_cores);
            return;
        }
        else if constexpr (calibration_type == t_calibration_type::rp)
        {
            check_calibration_initialized(__func__, "Power calibration", _power_calibration);

            _power_calibration->inplace_beam_sample_correction(wci,
                                                               beam_angles,
                                                               ranges,
                                                               get_absorption_to_apply(0),
                                                               get_tvg_factor_to_apply(40),
                                                               min_beam_index,
                                                               max_beam_index,
                                                               mp_cores);
            return;
        }
        else if constexpr (calibration_type == t_calibration_type::rv)
        {
            check_calibration_initialized(__func__, "Power calibration", _power_calibration);

            _power_calibration->inplace_beam_sample_correction(wci,
                                                               beam_angles,
                                                               ranges,
                                                               get_absorption_to_apply(0),
                                                               get_tvg_factor_to_apply(20),
                                                               min_beam_index,
                                                               max_beam_index,
                                                               mp_cores);
            return;
        }
        else if constexpr (calibration_type == t_calibration_type::pp)
        {
            check_calibration_initialized(__func__, "Power calibration", _power_calibration);

            _power_calibration->inplace_beam_sample_correction(wci,
                                                               beam_angles,
                                                               ranges,
                                                               get_absorption_to_apply(),
                                                               get_tvg_factor_to_apply(40),
                                                               min_beam_index,
                                                               max_beam_index,
                                                               mp_cores);
            return;
        }
        else if constexpr (calibration_type == t_calibration_type::pv)
        {
            check_calibration_initialized(__func__, "Power calibration", _power_calibration);

            _power_calibration->inplace_beam_sample_correction(wci,
                                                               beam_angles,
                                                               ranges,
                                                               get_absorption_to_apply(),
                                                               get_tvg_factor_to_apply(20),
                                                               min_beam_index,
                                                               max_beam_index,
                                                               mp_cores);
            return;
        }
        else if constexpr (calibration_type == t_calibration_type::ap)
        {
            check_calibration_initialized(__func__, "Ap calibration", _ap_calibration);

            _ap_calibration->inplace_beam_sample_correction(wci,
                                                            beam_angles,
                                                            ranges,
                                                            get_absorption_to_apply(),
                                                            get_tvg_factor_to_apply(40),
                                                            min_beam_index,
                                                            max_beam_index,
                                                            mp_cores);
            return;
        }
        else if constexpr (calibration_type == t_calibration_type::av)
        {
            check_calibration_initialized(__func__, "Av calibration", _av_calibration);

            _av_calibration->inplace_beam_sample_correction(wci,
                                                            beam_angles,
                                                            ranges,
                                                            get_absorption_to_apply(),
                                                            get_tvg_factor_to_apply(20),
                                                            min_beam_index,
                                                            max_beam_index,
                                                            mp_cores);
            return;
        }
        else if constexpr (calibration_type == t_calibration_type::sp)
        {
            check_calibration_initialized(__func__, "Sp calibration", _sp_calibration);

            _sp_calibration->inplace_beam_sample_correction(wci,
                                                            beam_angles,
                                                            ranges,
                                                            get_absorption_to_apply(),
                                                            get_tvg_factor_to_apply(40),
                                                            min_beam_index,
                                                            max_beam_index,
                                                            mp_cores);
            return;
        }
        else if constexpr (calibration_type == t_calibration_type::sv)
        {
            check_calibration_initialized(__func__, "Sv calibration", _sv_calibration);

            _sv_calibration->inplace_beam_sample_correction(wci,
                                                            beam_angles,
                                                            ranges,
                                                            get_absorption_to_apply(),
                                                            get_tvg_factor_to_apply(20),
                                                            min_beam_index,
                                                            max_beam_index,
                                                            mp_cores);
            return;
        }

        throw std::runtime_error(
            fmt::format("ERROR[{}]:Unhandled calibration type {}. Please report.",
                        __func__,
                        magic_enum::enum_name(calibration_type)));
    }

    // getters / setters
    float get_absorption_db_m() const;

    float get_tvg_absorption_db_m() const;
    float get_tvg_factor() const;

    // has calibration
    bool has_power_calibration() const;
    bool has_ap_calibration() const;
    bool has_av_calibration() const;
    bool has_sp_calibration() const;
    bool has_sv_calibration() const;

    // getters / setters
    const AmplitudeCalibration& get_power_calibration() const;
    const AmplitudeCalibration& get_ap_calibration() const;
    const AmplitudeCalibration& get_av_calibration() const;
    const AmplitudeCalibration& get_sp_calibration() const;
    const AmplitudeCalibration& get_sv_calibration() const;
    void set_power_calibration(const AmplitudeCalibration& calibration);

    void set_ap_calibration(const AmplitudeCalibration& calibration);

    void set_av_calibration(const AmplitudeCalibration& calibration);
    void set_sp_calibration(const AmplitudeCalibration& calibration);

    void set_sv_calibration(const AmplitudeCalibration& calibration);

    // operator overloads
    WaterColumnCalibration operator=(const WaterColumnCalibration& other);

    bool operator==(const WaterColumnCalibration& other) const;

    // stream i/o
    static WaterColumnCalibration from_stream(std::istream& is);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS__(WaterColumnCalibration)

  private:
    void check_calibration_initialized(std::string_view function_name,
                                       std::string_view calibration_name,
                                       const std::unique_ptr<AmplitudeCalibration>& ptr) const;
};

// boost hash
// IGNORE_DOC:__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_hash_value
inline std::size_t hash_value(const WaterColumnCalibration& arg)
{
    return arg.binary_hash();
}
}
}
}
}
}