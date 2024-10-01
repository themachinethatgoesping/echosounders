// SPDX-FileCopyrightText: 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/watercolumncalibration.doc.hpp"

#include <fmt/core.h>
#include <themachinethatgoesping/algorithms/amplitudecorrection/functions.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/helper.hpp>
#include <themachinethatgoesping/tools/vectorinterpolators.hpp>

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
    AmplitudeCalibration _power_calibration;
    AmplitudeCalibration _ap_calibration;
    AmplitudeCalibration _av_calibration;
    AmplitudeCalibration _sp_calibration;
    AmplitudeCalibration _sv_calibration;

    // water column corrections to be applied
    float _absorption_db_m =
        std::numeric_limits<float>::quiet_NaN(); // new absorption that should be
                                                 // applied to the data in dB/m

    // factors that have been applied to the raw data by a TVG function
    float _tvg_absorption_db_m = 0.0f; // the absorption applied to the data in dB/m
    float _tvg_factor = 0.0f; // the TVG factor applied to the data (typically 0, 20 or 40 (log(r)))

    uint64_t _hash;

  public:
    WaterColumnCalibration(float tvg_absorption_db_m = 0.0f, float tvg_factor = 0.0f)
        : _absorption_db_m(tvg_absorption_db_m)
        , _tvg_absorption_db_m(tvg_absorption_db_m)
        , _tvg_factor(tvg_factor)
    {
        compute_hash();
    }
    WaterColumnCalibration(const AmplitudeCalibration& power_calibration,
                           const AmplitudeCalibration& ap_calibration,
                           const AmplitudeCalibration& av_calibration,
                           float                       tvg_absorption_db_m = 0.0f,
                           float                       tvg_factor          = 0.0f)
        : _power_calibration(power_calibration)
        , _ap_calibration(ap_calibration)
        , _av_calibration(av_calibration)
    {
        compute_hash();
    }

    float get_absorption_to_apply() const
    {
        if (std::isfinite(_absorption_db_m))
            return _absorption_db_m - _tvg_absorption_db_m;

        return 0.f;
    }

    float get_tvg_factor_to_apply(float tvg_factor) const { return tvg_factor - _tvg_factor; }

    template<tools::helper::c_xtensor t_xtensor_2d, tools::helper::c_xtensor t_xtensor_1d>
    t_xtensor_2d apply_beam_sample_correction_power(const t_xtensor_2d& wci,
                                                    const t_xtensor_1d& beam_angles,
                                                    const t_xtensor_1d& ranges) const
    {
        return _power_calibration.apply_beam_sample_correction(wci, beam_angles, ranges);
    }

    template<tools::helper::c_xtensor t_xtensor_2d, tools::helper::c_xtensor t_xtensor_1d>
    t_xtensor_2d apply_beam_sample_correction_ap(const t_xtensor_2d& wci,
                                                 const t_xtensor_1d& beam_angles,
                                                 const t_xtensor_1d& ranges) const
    {
        return _ap_calibration.apply_beam_sample_correction(
            wci, beam_angles, ranges, get_absorption_to_apply(), get_tvg_factor_to_apply(40));
    }

    template<tools::helper::c_xtensor t_xtensor_2d, tools::helper::c_xtensor t_xtensor_1d>
    t_xtensor_2d apply_beam_sample_correction_sp(const t_xtensor_2d& wci,
                                                 const t_xtensor_1d& beam_angles,
                                                 const t_xtensor_1d& ranges) const
    {
        return _sp_calibration.apply_beam_sample_correction(
            wci, beam_angles, ranges, get_absorption_to_apply(), get_tvg_factor_to_apply(40));
    }

    template<tools::helper::c_xtensor t_xtensor_2d, tools::helper::c_xtensor t_xtensor_1d>
    t_xtensor_2d apply_beam_sample_correction_av(const t_xtensor_2d& wci,
                                                 const t_xtensor_1d& beam_angles,
                                                 const t_xtensor_1d& ranges) const
    {
        return _av_calibration.apply_beam_sample_correction(
            wci, beam_angles, ranges, get_absorption_to_apply(), get_tvg_factor_to_apply(20));
    }

    template<tools::helper::c_xtensor t_xtensor_2d, tools::helper::c_xtensor t_xtensor_1d>
    t_xtensor_2d apply_beam_sample_correction_sv(const t_xtensor_2d& wci,
                                                 const t_xtensor_1d& beam_angles,
                                                 const t_xtensor_1d& ranges) const
    {
        return _sv_calibration.apply_beam_sample_correction(
            wci, beam_angles, ranges, get_absorption_to_apply(), get_tvg_factor_to_apply(20));
    }

    // getters / setters
    float get_absorption_db_m() const
    {
        if (std::isfinite(_absorption_db_m))
            return _absorption_db_m;
        return _tvg_absorption_db_m;
    }

    float get_tvg_absorption_db_m() const { return _tvg_absorption_db_m; }
    float get_tvg_factor() const { return _tvg_factor; }

    // has calibration
    bool has_power_calibration() const { return _power_calibration.initialized(); }
    bool has_ap_calibration() const { return _ap_calibration.initialized(); }
    bool has_av_calibration() const { return _av_calibration.initialized(); }
    bool has_sp_calibration() const { return _sp_calibration.initialized(); }
    bool has_sv_calibration() const { return _sv_calibration.initialized(); }

    // getters / setters
    const AmplitudeCalibration& get_power_calibration() const
    {
        if (!has_power_calibration())
        {
            throw std::runtime_error(
                fmt::format("ERROR[{}]:Power calibration not initialized", __func__));
        }
        return _power_calibration;
    }
    const AmplitudeCalibration& get_ap_calibration() const
    {
        if (!has_ap_calibration())
        {
            throw std::runtime_error(
                fmt::format("ERROR[{}]:Ap calibration not initialized", __func__));
        }
        return _ap_calibration;
    }
    const AmplitudeCalibration& get_av_calibration() const
    {
        if (!has_av_calibration())
        {
            throw std::runtime_error(
                fmt::format("ERROR[{}]:Av calibration not initialized", __func__));
        }
        return _av_calibration;
    }
    const AmplitudeCalibration& get_sp_calibration() const
    {
        if (!has_sp_calibration())
        {
            throw std::runtime_error(
                fmt::format("ERROR[{}]:Sp calibration not initialized", __func__));
        }
        return _sp_calibration;
    }
    const AmplitudeCalibration& get_sv_calibration() const
    {
        if (!has_sv_calibration())
        {
            throw std::runtime_error(
                fmt::format("ERROR[{}]:Sv calibration not initialized", __func__));
        }
        return _sv_calibration;
    }
    void set_power_calibration(const AmplitudeCalibration& calibration)
    {
        _power_calibration = calibration;
        compute_hash();
    }

    void set_ap_calibration(const AmplitudeCalibration& calibration)
    {
        _ap_calibration = calibration;
        compute_hash();
    }

    void set_av_calibration(const AmplitudeCalibration& calibration)
    {
        _av_calibration = calibration;
        compute_hash();
    }
    void set_sp_calibration(const AmplitudeCalibration& calibration)
    {
        _sp_calibration = calibration;
        compute_hash();
    }

    void set_sv_calibration(const AmplitudeCalibration& calibration)
    {
        _sv_calibration = calibration;
        compute_hash();
    }

    // operator overloads
    bool operator==(const WaterColumnCalibration& other) const
    {
        if (_power_calibration != other._power_calibration)
            return false;

        if (_ap_calibration != other._ap_calibration)
            return false;

        if (_av_calibration != other._av_calibration)
            return false;

        if (_sp_calibration != other._sp_calibration)
            return false;

        if (_sv_calibration != other._sv_calibration)
            return false;

        if (!tools::helper::float_equals(_absorption_db_m, other._absorption_db_m))
            return false;

        if (!tools::helper::float_equals(_tvg_absorption_db_m, other._tvg_absorption_db_m))
            return false;

        if (!tools::helper::float_equals(_tvg_factor, other._tvg_factor))
            return false;

        return true;
    }

    bool initialized() const
    {
        return _hash != 14166511957577999600ULL;
    } // hash of default constructor

    // stream i/o
    static WaterColumnCalibration from_stream(std::istream& is)
    {
        WaterColumnCalibration calibration;

        calibration._power_calibration = AmplitudeCalibration::from_stream(is);
        calibration._ap_calibration    = AmplitudeCalibration::from_stream(is);
        calibration._av_calibration    = AmplitudeCalibration::from_stream(is);
        calibration._sp_calibration    = AmplitudeCalibration::from_stream(is);
        calibration._sv_calibration    = AmplitudeCalibration::from_stream(is);

        is.read(reinterpret_cast<char*>(&calibration._absorption_db_m), sizeof(float) * 3);

        calibration.compute_hash();

        return calibration;
    }

    void to_stream(std::ostream& os) const
    {
        _power_calibration.to_stream(os);
        _ap_calibration.to_stream(os);
        _av_calibration.to_stream(os);
        _sp_calibration.to_stream(os);
        _sv_calibration.to_stream(os);

        os.write(reinterpret_cast<const char*>(&_absorption_db_m), sizeof(float) * 3);
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision, bool superscript_exponents) const
    {
        tools::classhelper::ObjectPrinter printer("WaterColumnCalibration", float_precision, superscript_exponents);

        printer.register_section("Absorption");
        printer.register_value("Absorption", _absorption_db_m, "dB/m");
        printer.register_section("TVG applied to raw data");
        printer.register_value("TVG Absorption", _tvg_absorption_db_m, "dB/m");
        printer.register_value("TVG Factor", _tvg_factor, "log(r)");

        printer.register_section("Power Calibration");
        printer.append(_power_calibration.__printer__(float_precision, superscript_exponents));
        printer.register_section("Ap Calibration (Uncompensated uncalibrated TS)");
        printer.append(_ap_calibration.__printer__(float_precision, superscript_exponents));
        printer.register_section("Av Calibration (Uncalibrated volume scattering)");
        printer.append(_av_calibration.__printer__(float_precision, superscript_exponents));
        printer.register_section("Ap Calibration (Uncalibrated TS)");
        printer.append(_sp_calibration.__printer__(float_precision, superscript_exponents));
        printer.register_section("Sv Calibration (Volume scattering)");
        printer.append(_sv_calibration.__printer__(float_precision, superscript_exponents));

        return printer;
    }

    void add_hash(boost::iostreams::stream<XXHashSink>& hash_stream) const
    {
        _power_calibration.add_hash(hash_stream);
        _ap_calibration.add_hash(hash_stream);
        _av_calibration.add_hash(hash_stream);
        _sp_calibration.add_hash(hash_stream);
        _sv_calibration.add_hash(hash_stream);

        hash_stream.write(reinterpret_cast<const char*>(&_absorption_db_m), sizeof(float) * 3);
    }

    uint64_t                cached_hash() const { return _hash; }
    virtual xxh::hash_t<64> binary_hash() const
    {

        xxh::hash3_state_t<64>               hash;
        boost::iostreams::stream<XXHashSink> stream(hash);

        add_hash(stream);

        stream.flush();
        return hash.digest();
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NO_HASH__(WaterColumnCalibration)

  private:
    void compute_hash() { _hash = binary_hash(); }
};

// boost hash
// IGNORE_DOC:__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_hash_value
inline std::size_t hash_value(const WaterColumnCalibration& arg)
{
    return arg.cached_hash();
}
}
}
}
}
}