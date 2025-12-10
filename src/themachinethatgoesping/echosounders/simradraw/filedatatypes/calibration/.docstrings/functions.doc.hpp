//sourcehash: 5a6f2ae4a6d11d1e853f6f48587ae98147dc0bff782888eca4dada3f5e768411

/*
  This file contains docstrings for use in the Python bindings.
  Do not edit! They were automatically extracted by pybind11_mkdoc.

  This is a modified version which allows for more than 8 arguments and includes def-guard
 */

#pragma once

#ifndef __DOCSTRINGS_HPP__
#define __DOCSTRINGS_HPP__

#define MKD_EXPAND(x)                                      x
#define MKD_COUNT(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, COUNT, ...)  COUNT
#define MKD_VA_SIZE(...)                                   MKD_EXPAND(MKD_COUNT(__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0))
#define MKD_CAT1(a, b)                                     a ## b
#define MKD_CAT2(a, b)                                     MKD_CAT1(a, b)
#define MKD_DOC1(n1)                                       mkd_doc_##n1
#define MKD_DOC2(n1, n2)                                   mkd_doc_##n1##_##n2
#define MKD_DOC3(n1, n2, n3)                               mkd_doc_##n1##_##n2##_##n3
#define MKD_DOC4(n1, n2, n3, n4)                           mkd_doc_##n1##_##n2##_##n3##_##n4
#define MKD_DOC5(n1, n2, n3, n4, n5)                       mkd_doc_##n1##_##n2##_##n3##_##n4##_##n5
#define MKD_DOC6(n1, n2, n3, n4, n5, n6)                   mkd_doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6
#define MKD_DOC7(n1, n2, n3, n4, n5, n6, n7)               mkd_doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6##_##n7
#define MKD_DOC8(n1, n2, n3, n4, n5, n6, n7, n8)           mkd_doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6##_##n7##_##n8
#define MKD_DOC9(n1, n2, n3, n4, n5, n6, n7, n8, n9)       mkd_doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6##_##n7##_##n8##_##n9
#define MKD_DOC10(n1, n2, n3, n4, n5, n6, n7, n8, n9, n10) mkd_doc_##n1##_##n2##_##n3##_##n4##_##n5##_##n6##_##n7##_##n8##_##n9##_##n10
#define DOC(...)                                           MKD_EXPAND(MKD_EXPAND(MKD_CAT2(MKD_DOC, MKD_VA_SIZE(__VA_ARGS__)))(__VA_ARGS__))

#if defined(__GNUG__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#endif

#endif // __DOCSTRINGS_HPP__
#if defined(__GNUG__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#endif


static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_functions_compute_effective_pulse_duration_cw = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_functions_compute_effective_pulse_duration_cw_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_functions_compute_hann_window_weights =
R"doc(Generate Hann window weights of a given length.

Implements the symmetric Hann window
  w[n] = 0.5 * (1 - cos(2*pi*n/(L-1))), n = 0..L-1

Special cases:
- length <= 0: returns an empty tensor - length == 1: returns a single
  value {1}

Args:
    length:  Number of samples L in the window [1]

Template Args:
    t_xtensor_val:  1D xtensor-like container with nested value_type
                    (e.g., xt::xtensor<float,1>)

Returns:
    t_xtensor_val Window weights of shape {L} in range [0, 1])doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_functions_convolve_full = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_functions_create_linear_chirp_signal =
R"doc(Create a sampled linear chirp signal and its time vector.

Args:
    f0:  Start frequency [Hz]
    f1:  End frequency [Hz]
    pulse_duration:  Pulse duration τ [s]
    sampling_frequency:  Sampling frequency fs [Hz] (default 1.5 MHz)
    start_phase_degrees:  Start phase in degrees (converted internally
                          to radians, default 0)

Template Args:
    t_xtensor_val:  1D xtensor-like container to hold times and
                    samples (value_type is float/double)

Returns:
    std::pair<t_xtensor_val, t_xtensor_val> First: times t [s], shape
        {nsamples} Second: amplitudes y = sin(phi(t)), shape
        {nsamples})doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_functions_filter_and_decimate_pulse = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_filedatatypes_calibration_functions_generate_transmit_pulse =
R"doc(Generate a windowed transmit pulse from a linear chirp.

This function first creates a linear chirp using
create_linear_chirp_signal and then applies a Hann window to the start
and end of the pulse.

Args:
    f0:  Start frequency [Hz]
    f1:  End frequency [Hz]
    pulse_duration:  Pulse duration τ [s]
    slope_factor:  Proportion of the pulse that is windowed by each
                   half of the window. E.g. slope_factor = 0.5 use the
                   first half to ramp amplitudes up and the second
                   half to ramp them down. slope_factor = 0.1 would
                   use 10% of the pulse duration to ramp up and the
                   last 10% to ramp down.
    sampling_frequency:  Sampling frequency fs [Hz] (default 1.5 Mhz)
    start_phase_degrees:  Start phase in degrees (default 0)

Template Args:
    t_xtensor_val:  1D xtensor-like container to hold times and
                    samples (value_type is float/double)

Returns:
    std::pair<t_xtensor_val, t_xtensor_val> First: times t [s], shape
        {nsamples} Second: windowed chirp amplitudes y, shape
        {nsamples}



$See also:

compute_hann_window_weights


$See also:

create_linear_chirp_signal)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


