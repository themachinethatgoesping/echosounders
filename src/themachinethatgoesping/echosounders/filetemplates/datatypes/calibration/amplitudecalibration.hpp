// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Sven Schorge, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/amplitudecalibration.doc.hpp"

#include <iosfwd>
#include <limits>
#include <optional>
#include <vector>

#include <boost/iostreams/stream.hpp>
#include <xxhash.hpp>

#include <themachinethatgoesping/algorithms/amplitudecorrection/functions.hpp>
#include <themachinethatgoesping/tools/classhelper/objectprinter.hpp>
#include <themachinethatgoesping/tools/helper/xtensor.hpp>
#include <themachinethatgoesping/tools/vectorinterpolators/akimainterpolator.hpp>
#include <themachinethatgoesping/tools/vectorinterpolators/bivectorinterpolator.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace datatypes {
namespace calibration {

class AmplitudeCalibration
{

    // system offsets
    float _system_offset = std::numeric_limits<float>::quiet_NaN();
    tools::vectorinterpolators::AkimaInterpolator<float> _offset_per_beamangle =
        tools::vectorinterpolators::AkimaInterpolator<float>(
            tools::vectorinterpolators::t_extr_mode::nearest);
    // tools::vectorinterpolators::AkimaInterpolator _offset_per_swathangle;
    // implement in the future
    tools::vectorinterpolators::AkimaInterpolator<float> _offset_per_range =
        tools::vectorinterpolators::AkimaInterpolator<float>(
            tools::vectorinterpolators::t_extr_mode::nearest);

    tools::vectorinterpolators::BiVectorInterpolator<
        tools::vectorinterpolators::AkimaInterpolator<float>>
        _offset_per_beamangle_and_range = tools::vectorinterpolators::BiVectorInterpolator<
            tools::vectorinterpolators::AkimaInterpolator<float>>(
            tools::vectorinterpolators::t_extr_mode::nearest);

  public:
    AmplitudeCalibration() {}
    AmplitudeCalibration(float system_offset);

    // operator overloads
    bool operator==(const AmplitudeCalibration& other) const;

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
    t_xtensor_2d apply_beam_sample_correction(
        const t_xtensor_2d&                                                         wci,
        const t_xtensor_1d&                                                         beam_angles,
        const t_xtensor_1d&                                                         ranges,
        std::optional<typename tools::helper::xtensor_datatype<t_xtensor_1d>::type> absorption_db_m,
        std::optional<typename tools::helper::xtensor_datatype<t_xtensor_1d>::type> tvg_factor,
        int mp_cores = 1) const
    {
        namespace ampcorr = algorithms::amplitudecorrection::functions;

        t_xtensor_1d range_varying_offset =
            ampcorr::compute_cw_range_correction(ranges, absorption_db_m, tvg_factor);

        if (has_offset_per_range())
            range_varying_offset += get_per_sample_offsets(ranges);

        if (has_offset_per_beamangle())
        {
            t_xtensor_1d beam_correction = get_per_beam_offsets(beam_angles);

            if (has_system_offset())
                beam_correction += get_system_offset();

            return ampcorr::apply_beam_sample_correction(
                wci, beam_correction, range_varying_offset, mp_cores);
        }

        if (has_system_offset())
            range_varying_offset += get_system_offset();

        return ampcorr::apply_sample_correction(wci, range_varying_offset, mp_cores);
    }

    template<tools::helper::c_xtensor t_xtensor_2d, tools::helper::c_xtensor t_xtensor_1d>
    void inplace_beam_sample_correction(
        [[maybe_unused]] t_xtensor_2d&                                              wci,
        const t_xtensor_1d&                                                         beam_angles,
        const t_xtensor_1d&                                                         ranges,
        std::optional<typename tools::helper::xtensor_datatype<t_xtensor_1d>::type> absorption_db_m,
        std::optional<typename tools::helper::xtensor_datatype<t_xtensor_1d>::type> tvg_factor,
        std::optional<size_t> min_beam_index = std::nullopt,
        std::optional<size_t> max_beam_index = std::nullopt,
        int                   mp_cores       = 1) const
    {
        namespace ampcorr = algorithms::amplitudecorrection::functions;

        t_xtensor_1d range_varying_offset =
            ampcorr::compute_cw_range_correction(ranges, absorption_db_m, tvg_factor);

        //if (has_offset_per_beamangle_and_range())
        //    wci += _offset_per_beamangle_and_range(beam_angles, ranges);

        if (has_offset_per_range())
            range_varying_offset += get_per_sample_offsets(ranges);

        if (has_offset_per_beamangle())
        {
            t_xtensor_1d beam_correction = get_per_beam_offsets(beam_angles);

            if (has_system_offset())
                beam_correction += get_system_offset();

            ampcorr::inplace_beam_sample_correction(wci,
                                                    beam_correction,
                                                    range_varying_offset,
                                                    min_beam_index,
                                                    max_beam_index,
                                                    mp_cores);
            return;
        }

        if (has_system_offset())
            range_varying_offset += get_system_offset();

        ampcorr::inplace_sample_correction(
            wci, range_varying_offset, min_beam_index, max_beam_index, mp_cores);
    }

    // getters / setters
    float get_system_offset() const { return _system_offset; }
    void  set_system_offset(float value) { _system_offset = value; }

    void set_offset_per_beamangle(const std::vector<float>& beamangle,
                                  const std::vector<float>& offset);

    template<tools::helper::c_xtensor_1d t_xtensor_1d>
    void set_offset_per_beamangle(const t_xtensor_1d& beamangle, const t_xtensor_1d& offset)
    {
        _offset_per_beamangle.set_data_XY(std::vector<float>(beamangle.begin(), beamangle.end()),
                                          std::vector<float>(offset.begin(), offset.end()));
    }

    void set_offset_per_range(const std::vector<float>& range, const std::vector<float>& offset);

    template<tools::helper::c_xtensor t_xtensor_1d>
    void set_offset_per_range(const t_xtensor_1d& range, const t_xtensor_1d& offset)
    {
        _offset_per_range.set_data_XY(std::vector<float>(range.begin(), range.end()),
                                      std::vector<float>(offset.begin(), offset.end()));
    }

    void set_offset_per_beamangle_and_range(const std::vector<float>&              beamangle,
                                            const std::vector<float>&              range,
                                            const std::vector<std::vector<float>>& values);

    template<tools::helper::c_xtensor t_xtensor_1d, tools::helper::c_xtensor t_xtensor_2d>
    void set_offset_per_beamangle_and_range(const t_xtensor_1d& beamangle,
                                            const t_xtensor_1d& range,
                                            const t_xtensor_2d& values)
    {
        _offset_per_beamangle_and_range.clear();
        for (unsigned int bi = 0; bi < beamangle.size(); ++bi)
            _offset_per_beamangle_and_range.append_row(
                beamangle[bi], std::vector<float>(range.begin(), range.end()), values.row(bi));
    }

    // interpolator access
    bool has_offset_per_beamangle() const { return !_offset_per_beamangle.empty(); }
    bool has_offset_per_range() const { return !_offset_per_range.empty(); }
    bool has_offset_per_beamangle_and_range() const
    {
        return !_offset_per_beamangle_and_range.empty();
    }
    bool has_system_offset() const { return !std::isnan(_system_offset); }

    const auto& get_interpolator_offset_per_beamangle() const { return _offset_per_beamangle; }
    const auto& get_interpolator_offset_per_range() const { return _offset_per_range; }
    const auto& get_interpolator_offset_per_beamangle_and_range() const
    {
        return _offset_per_beamangle_and_range;
    }

    auto get_offset_per_beamangle(const std::vector<float>& beamangles);

    float get_offset_per_beamangle(float beamangle) const;

    auto get_offset_per_range(const std::vector<float>& ranges);

    float get_offset_per_range(float range) const;

    auto get_offset_per_beamangle_and_range(const std::vector<float>& beamangles,
                                            const std::vector<float>& ranges) const;

    static AmplitudeCalibration from_stream(std::istream& is);

    void to_stream(std::ostream& os) const;

    // ----- objectprinter -----
    tools::classhelper::ObjectPrinter __printer__(unsigned int float_precision,
                                                  bool         superscript_exponents) const;

    xxh::hash_t<64> binary_hash() const;

    // ----- class helper macros -----
    __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__
    __STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NO_HASH__(AmplitudeCalibration)

    void add_hash(boost::iostreams::stream<XXHashSink>& hash_stream) const;
};

// boost hash
// IGNORE_DOC:__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_calibration_hash_value
inline std::size_t hash_value(const AmplitudeCalibration& arg)
{
    return arg.binary_hash();
}
}
}
}
}
}
