// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/amplitudecalibration.doc.hpp"

#include <fmt/core.h>
#include <themachinethatgoesping/algorithms/amplitudecorrection/functions.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/helper.hpp>
#include <themachinethatgoesping/tools/vectorinterpolators.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datatypes {
namespace calibration {

class AmplitudeCalibration
{
    // system offsets
    float _system_offset = std::numeric_limits<float>::quiet_NaN();
    tools::vectorinterpolators::AkimaInterpolator<float> _offset_per_beamangle;
    // tools::vectorinterpolators::AkimaInterpolator _offset_per_swathangle; implement in the future
    tools::vectorinterpolators::AkimaInterpolator<float> _offset_per_range;

    uint64_t _hash;

  public:
    AmplitudeCalibration() { compute_hash(); }
    AmplitudeCalibration(float system_offset)
        : _system_offset(system_offset)
    {
        compute_hash();
    }

    // operator overloads
    bool operator==(const AmplitudeCalibration& other) const
    {
        if (_offset_per_beamangle != other._offset_per_beamangle)
            return false;

        if (_offset_per_range != other._offset_per_range)
            return false;

        if (std::isnan(_system_offset) && std::isnan(other._system_offset))
            return true;

        if (_system_offset == other._system_offset)
            return true;

        return false;
    }
    bool initialized() const
    {
        return _hash != 3244421341483603138ULL;
    } // hash of default constructor

    template<tools::helper::c_xtensor_1d t_xtensor_1d>
    t_xtensor_1d get_per_beam_offsets(const t_xtensor_1d& beam_angles) const
    {
        if (has_offset_per_beamangle())
        {
            t_xtensor_1d per_beam_offset = xt::empty_like(beam_angles);

            for (unsigned int bi = 0; bi < beam_angles.size(); ++bi)
                per_beam_offset[bi] = get_offset_per_beamangle(beam_angles[bi]);

            return per_beam_offset;
        }

        return xt::zeros_like(beam_angles);
    }

    template<tools::helper::c_xtensor_1d t_xtensor_1d>
    t_xtensor_1d get_per_sample_offsets(const t_xtensor_1d& ranges) const
    {
        if (has_offset_per_range())
        {
            t_xtensor_1d per_sample_offset = xt::empty_like(ranges);

            for (unsigned int bi = 0; bi < ranges.size(); ++bi)
                per_sample_offset[bi] = get_offset_per_range(ranges[bi]);

            return per_sample_offset;
        }

        return xt::zeros_like(ranges);
    }

    template<tools::helper::c_xtensor t_xtensor_2d, tools::helper::c_xtensor t_xtensor_1d>
    t_xtensor_2d apply_beam_sample_correction(const t_xtensor_2d& wci,
                                              const t_xtensor_1d& beam_angles,
                                              const t_xtensor_1d& ranges,
                                              int                 mp_cores = 1) const
    {
        using algorithms::amplitudecorrection::functions::apply_beam_correction;
        using algorithms::amplitudecorrection::functions::apply_beam_sample_correction;
        using algorithms::amplitudecorrection::functions::apply_sample_correction;

        if (has_offset_per_beamangle())
        {
            t_xtensor_1d beam_correction = get_per_beam_offsets(beam_angles);

            if (has_system_offset())
                beam_correction += get_system_offset();

            if (has_offset_per_range())
            {
                t_xtensor_1d sample_correction = get_per_sample_offsets(ranges);

                return apply_beam_sample_correction(
                    wci, beam_correction, sample_correction, mp_cores);
            }
            return apply_beam_correction(wci, beam_correction, mp_cores);
        }

        if (has_offset_per_range())
        {
            t_xtensor_1d sample_correction = get_per_sample_offsets(ranges);
            if (has_system_offset())
                sample_correction += get_system_offset();

            return apply_sample_correction(wci, sample_correction, mp_cores);
        }

        if (has_system_offset())
        {
            if (mp_cores == 1)
                return wci + get_system_offset();
            else
            {
                t_xtensor_2d result = wci;
#pragma omp parallel for num_threads(mp_cores)
                for (unsigned int bi = 0; bi < result.shape(0); ++bi)
                    xt::row(result, bi) += get_system_offset();
                return result;
            }
        }
        return wci;
    }

    template<tools::helper::c_xtensor t_xtensor_2d, tools::helper::c_xtensor t_xtensor_1d>
    t_xtensor_2d apply_beam_sample_correction(
        const t_xtensor_2d&                                          wci,
        const t_xtensor_1d&                                          beam_angles,
        const t_xtensor_1d&                                          ranges,
        typename tools::helper::xtensor_datatype<t_xtensor_1d>::type absorption_db_m,
        typename tools::helper::xtensor_datatype<t_xtensor_1d>::type tvg_factor,
        int                                                          mp_cores = 1) const
    {
        using algorithms::amplitudecorrection::functions::apply_beam_correction;
        using algorithms::amplitudecorrection::functions::apply_beam_sample_correction;
        using algorithms::amplitudecorrection::functions::apply_sample_correction;
        using algorithms::amplitudecorrection::functions::compute_cw_range_correction;

        t_xtensor_1d range_varying_offset =
            compute_cw_range_correction(ranges, absorption_db_m, tvg_factor);

        if (has_offset_per_range())
            range_varying_offset += get_per_sample_offsets(ranges);

        if (has_offset_per_beamangle())
        {
            t_xtensor_1d beam_correction = get_per_beam_offsets(beam_angles);

            if (has_system_offset())
                beam_correction += get_system_offset();

            return apply_beam_sample_correction(
                wci, beam_correction, range_varying_offset, mp_cores);
        }

        if (has_system_offset())
            range_varying_offset += get_system_offset();

        return apply_sample_correction(wci, range_varying_offset, mp_cores);
    }

    // getters / setters
    float get_system_offset() const { return _system_offset; }
    void  set_system_offset(float value)
    {
        _system_offset = value;
        compute_hash();
    }

    void set_offset_per_beamangle(const std::vector<float>& beamangle,
                                  const std::vector<float>& offset)
    {
        _offset_per_beamangle.set_data_XY(beamangle, offset);
        compute_hash();
    }

    void set_offset_per_range(const std::vector<float>& range, const std::vector<float>& offset)
    {
        _offset_per_range.set_data_XY(range, offset);
        compute_hash();
    }

    // interpolator access
    bool has_offset_per_beamangle() const { return !_offset_per_beamangle.empty(); }
    bool has_offset_per_range() const { return !_offset_per_range.empty(); }
    bool has_system_offset() const { return !std::isnan(_system_offset); }

    const auto& get_interpolator_offset_per_beamangle() const { return _offset_per_beamangle; }
    const auto& get_interpolator_offset_per_range() const { return _offset_per_range; }

    auto get_offset_per_beamangle(const std::vector<float>& beamangles)
    {
        return _offset_per_beamangle(beamangles);
    }

    auto get_offset_per_beamangle(float beamangle) const
    {
        return _offset_per_beamangle.get_y_const(beamangle);
    }

    auto get_offset_per_range(const std::vector<float>& ranges)
    {
        return _offset_per_range(ranges);
    }

    auto get_offset_per_range(float range) const { return _offset_per_range.get_y_const(range); }

    static AmplitudeCalibration from_stream(std::istream& is)
    {
        AmplitudeCalibration calibration;

        is.read(reinterpret_cast<char*>(&calibration._system_offset), sizeof(float));

        calibration._offset_per_beamangle = calibration._offset_per_beamangle.from_stream(is);
        calibration._offset_per_range     = calibration._offset_per_range.from_stream(is);

        calibration.compute_hash();
        return calibration;
    }

    void to_stream(std::ostream& os) const
    {
        os.write(reinterpret_cast<const char*>(&_system_offset), sizeof(float));

        _offset_per_beamangle.to_stream(os);
        _offset_per_range.to_stream(os);
    }

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision) const
    {
        tools::classhelper::ObjectPrinter printer("AmplitudeCalibration", float_precision);

        printer.register_section("System offsets");
        if (!std::isnan(_system_offset))
            printer.register_value("system_offset", _system_offset);
        if (!_offset_per_beamangle.empty())
            printer.append(_offset_per_beamangle.__printer__(float_precision));
        if (!_offset_per_range.empty())
            printer.append(_offset_per_range.__printer__(float_precision));

        return printer;
    }

    uint64_t        cached_hash() const { return _hash; }
    xxh::hash_t<64> binary_hash() const
    {
        xxh::hash3_state_t<64>               hash;
        boost::iostreams::stream<XXHashSink> stream(hash);

        add_hash(stream);

        stream.flush();
        return hash.digest();
    }

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NO_HASH__(AmplitudeCalibration)

    void add_hash(boost::iostreams::stream<XXHashSink>& hash_stream) const
    {
        if (has_system_offset())
            hash_stream.write(reinterpret_cast<const char*>(&_system_offset), sizeof(float));

        if (has_offset_per_beamangle())
            _offset_per_beamangle.to_stream(hash_stream);

        if (has_offset_per_range())
            _offset_per_range.to_stream(hash_stream);
    }

  private:
    void compute_hash() { _hash = binary_hash(); }
};

// boost hash
// IGNORE_DOC:__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_hash_value
inline std::size_t hash_value(const AmplitudeCalibration& arg)
{
    return arg.cached_hash();
}

}
}
}
}
}
