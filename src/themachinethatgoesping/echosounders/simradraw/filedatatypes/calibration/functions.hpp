// SPDX-FileCopyrightText: 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
//

#pragma once

/* generated doc strings */
#include ".docstrings/functions.doc.hpp"

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif

#include <cmath>
#include <numbers>
#include <utility>

#include <themachinethatgoesping/tools/helper/xtensor.hpp>

#include <xtensor/containers/xtensor.hpp>
#include <xtensor/core/xmath.hpp>         // cos, sin
#include <xtensor/core/xshape.hpp>        // for xt::placeholders::_
#include <xtensor/misc/xmanipulation.hpp> // arange
#include <xtensor/views/xview.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace simradraw {
namespace filedatatypes {
namespace calibration {
namespace functions {

/**
 * @brief Generate Hann window weights of a given length.
 *
 * Implements the symmetric Hann window
 *   w[n] = 0.5 * (1 - cos(2*pi*n/(L-1))), n = 0..L-1
 *
 * Special cases:
 * - length <= 0: returns an empty tensor
 * - length == 1: returns a single value {1}
 *
 * @tparam t_xtensor_val
 *         1D xtensor-like container with nested value_type (e.g., xt::xtensor<float,1>)
 * @param length
 *        Number of samples L in the window [1]
 * @return t_xtensor_val
 *         Window weights of shape {L} in range [0, 1]
 */
template<tools::helper::c_xtensor_1d t_xtensor_val>
static inline t_xtensor_val compute_hann_window_weights(const int length)
{
    using t_float = typename t_xtensor_val::value_type;

    if (length <= 0) // return empty tensor
        return t_xtensor_val::from_shape({ 0u });
    else if (length == 1) // return 1
        return t_xtensor_val({ 1 }, t_float(1.0));

    auto n = xt::arange<t_float>(t_float(0.), static_cast<t_float>(length));
    return t_float(0.5) * (t_float(1.0) - xt::cos(t_float(2.0) * std::numbers::pi_v<t_float> * n /
                                                  t_float(length - 1)));
}

/**
 * @brief Create a sampled linear chirp signal and its time vector.
 *
 * @tparam t_xtensor_val
 *         1D xtensor-like container to hold times and samples (value_type is float/double)
 * @param f0
 *        Start frequency [Hz]
 * @param f1
 *        End frequency [Hz]
 * @param pulse_duration
 *        Pulse duration τ [s]
 * @param sampling_frequency
 *        Sampling frequency fs [Hz] (default 1.5 MHz)
 * @param start_phase_degrees
 *        Start phase in degrees (converted internally to radians, default 0)
 * @return std::pair<t_xtensor_val, t_xtensor_val>
 *         First: times t [s], shape {nsamples}
 *         Second: amplitudes y = sin(phi(t)), shape {nsamples}
 */
template<tools::helper::c_xtensor_1d t_xtensor_val>
static inline std::pair<t_xtensor_val, t_xtensor_val> create_linear_chirp_signal(
    const typename t_xtensor_val::value_type f0,
    const typename t_xtensor_val::value_type f1,
    const typename t_xtensor_val::value_type pulse_duration,
    const typename t_xtensor_val::value_type sampling_frequency  = 1500000,
    const typename t_xtensor_val::value_type start_phase_degrees = 0)
{
    using t_float = typename t_xtensor_val::value_type;

    // compute number of samples in pulse
    const int nsamples =
        std::max(1, static_cast<int>(std::floor(pulse_duration * sampling_frequency)));

    // create time vector
    xt::xtensor<t_float, 1> times =
        xt::linspace<t_float>(t_float(0), t_float(nsamples - 1), nsamples) / sampling_frequency;

    // precompute static factors
    const t_float chirp_rate  = (f1 - f0) / pulse_duration;
    const t_float A           = t_float(2) * std::numbers::pi_v<t_float> * f0;
    const t_float B           = std::numbers::pi_v<t_float> * chirp_rate;
    const t_float start_phase = start_phase_degrees * std::numbers::pi_v<t_float> / t_float(180.0);

    // return { std::move(times), xt::sin(start_phase + A * times + B * times * times) };
    //  matching default scipy/matlab chirp signal that uses cosine
    return { std::move(times), xt::cos(start_phase + A * times + B * times * times) };
}

/**
 * @brief Generate a windowed transmit pulse from a linear chirp.
 *
 * This function first creates a linear chirp using create_linear_chirp_signal and then
 * applies a Hann window to the start and end of the pulse.
 *
 * @tparam t_xtensor_val
 *         1D xtensor-like container to hold times and samples (value_type is float/double)
 * @param f0
 *        Start frequency [Hz]
 * @param f1
 *        End frequency [Hz]
 * @param pulse_duration
 *        Pulse duration τ [s]
 * @param slope_factor
 *        Proportion of the pulse that is windowed by each half of the window.
 *        E.g. slope_factor = 0.5 use the first half to ramp amplitudes up and the second half to
 * ramp them down. slope_factor = 0.1 would use 10% of the pulse duration to ramp up and the last
 * 10% to ramp down.
 * @param sampling_frequency
 *        Sampling frequency fs [Hz] (default 1.5 Mhz)
 * @param start_phase_degrees
 *        Start phase in degrees (default 0)
 * @return std::pair<t_xtensor_val, t_xtensor_val>
 *         First: times t [s], shape {nsamples}
 *         Second: windowed chirp amplitudes y, shape {nsamples}
 * @see compute_hann_window_weights
 * @see create_linear_chirp_signal
 */
template<tools::helper::c_xtensor_1d t_xtensor_val>
static inline std::pair<t_xtensor_val, t_xtensor_val> generate_transmit_pulse(
    const typename t_xtensor_val::value_type f0,
    const typename t_xtensor_val::value_type f1,
    const typename t_xtensor_val::value_type pulse_duration,
    const typename t_xtensor_val::value_type slope_factor,
    const typename t_xtensor_val::value_type sampling_frequency  = 1500000,
    const typename t_xtensor_val::value_type start_phase_degrees = 0)
{
    using t_float = typename t_xtensor_val::value_type;
    using xt::placeholders::_;

    // Chirp
    auto [times, amplitudes] = create_linear_chirp_signal<t_xtensor_val>(
        f0, f1, pulse_duration, sampling_frequency, start_phase_degrees);

    // Hann window length
    // slope_factor describes percentage of pulse that is influenced by each half of the window
    // e.g. slope_factor = 0.5 means that the first half of the pulse will be used to ramp signal up
    // and the second half will be used to ramp signal down
    // to compute the full window length we thus the pulse duration multiplied by the slope factor
    // times 2
    const int window_length =
        std::max(0,
                 static_cast<int>(std::round(pulse_duration * sampling_frequency * slope_factor *
                                             t_float(2.0))));

    if (window_length >= 2)
    {
        const auto w = compute_hann_window_weights<t_xtensor_val>(window_length);

        const int half_window = window_length / 2;

        const auto ramp_up   = xt::view(w, xt::range(0, half_window));
        const auto ramp_down = xt::view(w, xt::range(half_window, window_length));

        // multiply each half of the window with the beginning and end of the signal respectively
        xt::view(amplitudes, xt::range(_, ramp_up.size())) *= ramp_up;
        xt::view(amplitudes, xt::range(-ramp_down.size(), _)) *= ramp_down;
    }

    return { std::move(times), std::move(amplitudes) };
}

// NumPy-like 1D full convolution: y = np.convolve(x, h) with real x and complex h
template<tools::helper::c_xtensor_1d t_xtensor_val, tools::helper::c_xtensor_1d t_xtensor_complex>
inline t_xtensor_complex _convolve_full(const t_xtensor_val& x, const t_xtensor_complex& h)
{
    // using t_float   = typename t_xtensor_val::value_type;
    using t_complex = typename t_xtensor_complex::value_type;

    const std::size_t N = x.size();
    const std::size_t M = h.size();

    if (N == 0 || M == 0)
        return t_xtensor_complex::from_shape({ 0L });

    auto y = t_xtensor_complex::from_shape({ static_cast<long>(N + M - 1) });
    std::fill(y.begin(), y.end(), t_complex{ 0 });

    for (std::size_t i = 0; i < N + M - 1; ++i)
    {
        const std::size_t kmin = (i >= (M - 1)) ? (i - (M - 1)) : 0;
        const std::size_t kmax = std::min<std::size_t>(i, N - 1);
        t_complex         acc{ 0 };
        for (std::size_t k = kmin; k <= kmax; ++k)
        {
            const std::size_t h_idx = i - k; // 0..M-1
            acc += static_cast<t_complex>(x(k)) * h(h_idx);
        }
        y(i) = acc;
    }
    return y;
}

template<tools::helper::c_xtensor_1d t_xtensor_val, tools::helper::c_xtensor_1d t_xtensor_coeffs>
static inline std::pair<t_xtensor_val, t_xtensor_coeffs> filter_and_decimate_pulse(
    const t_xtensor_val&    pulse_amplitudes,
    const int16_t           stage1_decimation_factor,
    const t_xtensor_coeffs& stage1_filter_coefficients,
    const int16_t           stage2_decimation_factor,
    const t_xtensor_coeffs& stage2_filter_coefficients,
    const double            sampling_frequency = 1500000.0)
{
    using t_float = typename t_xtensor_val::value_type;

    const auto stage1_convolved = _convolve_full(pulse_amplitudes, stage1_filter_coefficients);

    const auto stage1_decimated =
        xt::view(stage1_convolved, xt::range(0, stage1_convolved.size(), stage1_decimation_factor));

    const auto stage2_convolved = _convolve_full(stage1_decimated, stage2_filter_coefficients);

    const auto stage2_decimated =
        xt::view(stage2_convolved, xt::range(0, stage2_convolved.size(), stage2_decimation_factor));

    // create time vector
    const double decimated_frequency =
        sampling_frequency / (static_cast<double>(stage1_decimation_factor) *
                              static_cast<double>(stage2_decimation_factor));
    xt::xtensor<t_float, 1> times = xt::linspace<t_float>(t_float(0),
                                                          t_float(stage2_decimated.size() - 1),
                                                          stage2_decimated.size()) /
                                    decimated_frequency;

    return { std::move(times), stage2_decimated };
}

template<tools::helper::c_xtensor_1d t_xtensor_complex, std::floating_point t_float>
auto compute_effective_pulse_duration_cw(const t_xtensor_complex& pulse_amplitudes,
                                         const t_float            sample_interval,
                                         const bool               round_to_full_samples = true)
{
    // Calculate |pulse_amplitudes|^2
    const auto y_abs         = xt::abs(pulse_amplitudes);
    const auto y_abs_squared = y_abs * y_abs;

    // Calculate total energy (sum of |pulse_amplitudes|^2)
    const auto total_energy = xt::nansum(y_abs_squared)(); // () makes it scalar

    // Calculate peak energy (max of |pulse_amplitudes|^2)
    const auto peak_energy = xt::nanmax(y_abs_squared)(); // () makes it scalar

    // Convert from energy ratio to number of samples (matching ESP3s implementation)
    if (round_to_full_samples)
        return sample_interval * std::round(total_energy / peak_energy);

    // Convert energy ratio to time duration (no rounding / matching Echopype implementation)
    return sample_interval * std::round(total_energy / peak_energy);
}

template<tools::helper::c_xtensor_1d t_xtensor_complex, tools::helper::c_xtensor_1d t_xtensor_vals>
auto compute_effective_pulse_duration_cw(const t_xtensor_complex& pulse_amplitudes,
                                         const t_xtensor_vals&    pulse_times)
{
    using xt::placeholders::_;

    // Calculate |pulse_amplitudes|^2
    const auto y_abs         = xt::abs(pulse_amplitudes);
    const auto y_abs_squared = y_abs * y_abs;

    // compute sample widths from pulse_times
    auto       sample_durations = xt::ones_like(pulse_times);
    const auto n                = pulse_times.size();

    if (n >= 2)
    {
        auto diffs = xt::diff(pulse_times); // size = n-1

        // First sample: full distance to next sample
        sample_durations(0) = diffs(0);

        // Middle samples: half distance to previous + half distance to next
        if (n > 2)
        {
            xt::view(sample_durations, xt::range(1, n - 1)) =
                0.5 * xt::view(diffs, xt::range(0, n - 2)) +
                0.5 * xt::view(diffs, xt::range(1, n - 1));
        }

        // Last sample: full distance to previous sample
        sample_durations(n - 1) = diffs(n - 2);
    }

    // Calculate total energy (sum of |pulse_amplitudes|^2)
    const auto total_energy = xt::nansum(y_abs_squared * sample_durations)();

    // Calculate peak energy (max of |pulse_amplitudes|^2)
    const auto peak_energy = xt::nanmax(y_abs_squared)();

    return total_energy / peak_energy;
}

}
}
}
}
}
}