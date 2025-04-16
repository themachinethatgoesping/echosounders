// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/kongsbergallamplitudeconverter.doc.hpp"

/* generated doc strings */
#include ".docstrings/types.doc.hpp"

#include <complex>

#include <fmt/core.h>
#include <magic_enum/magic_enum.hpp>
#include <xtensor/containers/xtensor.hpp>

#include <themachinethatgoesping/tools/helper.hpp>

/**
 * @brief Type definitions for kongsberg .all types according to kongsberg em series datagram
 * formats specificaztion see also
 * https://www.kongsberg.com/contentassets/47d7f3d5d4fa4c1b980d9861d1c70c12/160692_em_datagram_formats.pdf
 *
 */

/*  */
//
namespace themachinethatgoesping {
namespace echosounders {
namespace kongsbergall {

template<typename T_xt>
class KongsbergAllAmpltitudeConverter
{
    T_xt  _total_factor;
    T_xt  _range_factor;
    T_xt  _pulse_factor_array;
    float _pulse_factor_val;
    float _static_factor;

    bool _sound_velocity_is_array;
    bool _total_factor_is_computed = false;

  public:
    KongsbergAllAmpltitudeConverter(const T_xt& sample_numbers,
                                    float       sample_interval,
                                    float       tvg_factor_applied,
                                    float       effective_pulse_length,
                                    float       sound_velocity,
                                    float       tvg_offset)
    {
        set_range_factor(sample_numbers, sample_interval, sound_velocity, tvg_factor_applied);
        set_pulse_factor(sound_velocity, effective_pulse_length);
        set_static_factor(tvg_offset);
    }

    KongsbergAllAmpltitudeConverter(const T_xt& ranges,
                                    float       tvg_factor_applied,
                                    float       effective_pulse_length,
                                    float       sound_velocity,
                                    float       tvg_offset)
    {
        set_range_factor(ranges, tvg_factor_applied);
        set_pulse_factor(sound_velocity, effective_pulse_length);
        set_static_factor(tvg_offset);
    }

    KongsbergAllAmpltitudeConverter(const T_xt& ranges,
                                    float       tvg_factor_applied,
                                    float       effective_pulse_length,
                                    const T_xt& sound_velocity,
                                    float       tvg_offset)
    {
        set_range_factor(ranges, tvg_factor_applied);
        set_pulse_factor(sound_velocity, effective_pulse_length);
        set_static_factor(tvg_offset);
    }

    // ----- setters -----
    void set_range_factor(const T_xt& sample_numbers,
                          float       sample_interval,
                          float       sound_velocity,
                          float       tvg_factor_applied)
    {
        float tmp =
            20 -
            tvg_factor_applied; // switching (tvg_factor_applied-20) to makes the factor negative
        float tmp_2         = sound_velocity * sample_interval * 0.5;
        auto  _range_factor = xt::eval(tmp * xt::eval(xt::log10(xt::eval(sample_numbers * tmp_2))));
        _total_factor_is_computed = false;
    }

    void set_range_factor(const T_xt& ranges, float tvg_factor_applied)
    {
        float tmp =
            20 -
            tvg_factor_applied; // switching (tvg_factor_applied-20) to makes the factor negative
        _range_factor             = xt::eval(tmp * xt::eval(xt::log10(ranges)));
        _total_factor_is_computed = false;
    }

    void set_pulse_factor(float sound_velocity, float pulse_length)
    {
        _pulse_factor_val = std::log10(sound_velocity * pulse_length * 0.5);

        _sound_velocity_is_array  = false;
        _total_factor_is_computed = false;
    }

    void set_pulse_factor(const T_xt& sound_velocity, float pulse_length)
    {
        _pulse_factor_array = xt::eval(xt::log10(xt::eval(sound_velocity * (pulse_length * 0.5))));

        _sound_velocity_is_array  = true;
        _total_factor_is_computed = false;
    }

    void set_static_factor(float tvg_offset)
    {
        _static_factor            = tvg_offset;
        _total_factor_is_computed = false;
    }

    // ----- compute ------
    void compute_total_compensation_factor()
    {
        if (_total_factor_is_computed)
            return;

        if (_sound_velocity_is_array)
        {
            _total_factor =
                xt::eval(xt::eval(_range_factor - _pulse_factor_array) - _static_factor);
        }
        else
        {
            _total_factor = xt::eval(_range_factor - (_pulse_factor_val - _static_factor));
        }

        _total_factor_is_computed = true;
    }

    // ----- getters -----
    T_xt get_total_compensation_factor()
    {
        compute_total_compensation_factor();
        return _total_factor;
    }

    T_xt                      get_range_factor() { return _range_factor; }
    std::variant<float, T_xt> get_pulse_factor()
    {
        if (_sound_velocity_is_array)
        {
            return _pulse_factor_array;
        }
        else
        {
            return _pulse_factor_val;
        }
    }
    float get_static_factor() { return _static_factor; }
    bool  get_sound_velocity_is_array() { return _sound_velocity_is_array; }

    // ----- operators -----
    T_xt operator()(const T_xt& amplitudes)
    {
        return xt::eval(amplitudes * 0.5) + get_total_compensation_factor();
    }

    bool operator==(const KongsbergAllAmpltitudeConverter& other) const = default;
};

} // kongsbergall
} // namespace echosounders
} // namespace themachinethatgoesping
