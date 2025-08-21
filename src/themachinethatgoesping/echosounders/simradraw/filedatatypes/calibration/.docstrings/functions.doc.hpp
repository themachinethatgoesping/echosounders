//sourcehash: 5a6f2ae4a6d11d1e853f6f48587ae98147dc0bff782888eca4dada3f5e768411

/*
  This file contains docstrings for use in the Python bindings.
  Do not edit! They were automatically extracted by pybind11_mkdoc.

  This is a modified version which allows for more than 8 arguments and includes def-guard
 */

#pragma once

#ifndef __DOCSTRINGS_HPP__

#define __EXPAND(x)                                                  x
#define __COUNT(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, COUNT, ...) COUNT
#define __VA_SIZE(...)                                               __EXPAND(__COUNT(__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1))
#define __CAT1(a, b)                                                 a##b
#define __CAT2(a, b)                                                 __CAT1(a, b)
#define __DOC1(n1)                                                   __doc_##n1
#define __DOC2(n1, n2)                                               __doc_##n1##_##n2
#define __DOC3(n1, n2, n3)                                           __doc_##n1##_##n2##_##n3
#define __DOC4(n1, n2, n3, n4)                                       __doc_##n1##_##n2##_##n3##_##n4
#define __DOC5(n1, n2, n3, n4, n5)                                   __doc_##n1##_##n2##_##n3##_##n4##_##n5
#define __DOC6(n1, n2, n3, n4, n5, n6)                               __doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6
#define __DOC7(n1, n2, n3, n4, n5, n6, n7)                           __doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6##_##n7
#define __DOC8(n1, n2, n3, n4, n5, n6, n7, n8)                                                     \
    __doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6##_##n7##_##n8
#define __DOC9(n1, n2, n3, n4, n5, n6, n7, n8, n9)                                                 \
    __doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6##_##n7##_##n8##_##n9
#define __DOC10(n1, n2, n3, n4, n5, n6, n7, n8, n9, n10)                                           \
    __doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6##_##n7##_##n8##_##n9##_##n10
#define DOC(...) __EXPAND(__EXPAND(__CAT2(__DOC, __VA_SIZE(__VA_ARGS__)))(__VA_ARGS__))

#endif // NEW_DOC_HEADER_HPP
#if defined(__GNUG__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#endif


static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_functions_compute_effective_pulse_duration_cw = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_functions_compute_effective_pulse_duration_cw_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_functions_compute_hann_window_weights =
R"doc(Generate Hann window weights of a given length.

Implements the symmetric Hann window w[n] = 0.5 * (1 -
cos(2*pi*n/(L-1))), n = 0..L-1

Special cases: - length <= 0: returns an empty tensor - length == 1:
returns a single value {1}

Template parameter ``t_xtensor_val``:
    1D xtensor-like container with nested value_type (e.g.,
    xt::xtensor<float,1>)

Parameter ``length``:
    Number of samples L in the window [1]

Returns:
    t_xtensor_val Window weights of shape {L} in range [0, 1])doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_functions_convolve_full = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_functions_create_linear_chirp_signal =
R"doc(Create a sampled linear chirp signal and its time vector.

Template parameter ``t_xtensor_val``:
    1D xtensor-like container to hold times and samples (value_type is
    float/double)

Parameter ``f0``:
    Start frequency [Hz]

Parameter ``f1``:
    End frequency [Hz]

Parameter ``pulse_duration``:
    Pulse duration τ [s]

Parameter ``sampling_frequency``:
    Sampling frequency fs [Hz] (default 1.5 MHz)

Parameter ``start_phase_degrees``:
    Start phase in degrees (converted internally to radians, default
    0)

Returns:
    std::pair<t_xtensor_val, t_xtensor_val> First: times t [s], shape
    {nsamples} Second: amplitudes y = sin(phi(t)), shape {nsamples})doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_functions_filter_and_decimate_pulse = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_functions_generate_transmit_pulse =
R"doc(Generate a windowed transmit pulse from a linear chirp.

This function first creates a linear chirp using
create_linear_chirp_signal and then applies a Hann window to the start
and end of the pulse.

Template parameter ``t_xtensor_val``:
    1D xtensor-like container to hold times and samples (value_type is
    float/double)

Parameter ``f0``:
    Start frequency [Hz]

Parameter ``f1``:
    End frequency [Hz]

Parameter ``pulse_duration``:
    Pulse duration τ [s]

Parameter ``slope_factor``:
    Proportion of the pulse that is windowed by each half of the
    window. E.g. slope_factor = 0.5 use the first half to ramp
    amplitudes up and the second half to ramp them down. slope_factor
    = 0.1 would use 10% of the pulse duration to ramp up and the last
    10% to ramp down.

Parameter ``sampling_frequency``:
    Sampling frequency fs [Hz] (default 1.5 Mhz)

Parameter ``start_phase_degrees``:
    Start phase in degrees (default 0)

Returns:
    std::pair<t_xtensor_val, t_xtensor_val> First: times t [s], shape
    {nsamples} Second: windowed chirp amplitudes y, shape {nsamples}

See also:
    compute_hann_window_weights

See also:
    create_linear_chirp_signal)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


