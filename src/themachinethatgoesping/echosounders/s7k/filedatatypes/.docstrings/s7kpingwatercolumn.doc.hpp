//sourcehash: 4ff365f54a71d574219147f296f238998eeb3715379d6d3b4b690712fa0fa41c

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


static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn =
R"doc(Water column accessor of an s7k ping.

The water-column amplitudes come from the 7042 CompressedWaterColumn
record; the per-beam receive angles and the detected bottom sample
come from the 7027 RawDetection record; the sample interval and sound
velocity come from the 7000 SonarSettings record. This first version
assumes a single transmit sector and a contiguous beam numbering
(water-column beam i == detection beam i).

Template Args:
    t_ifstream:)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_S7KPingWatercolumn = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_assemble_beam_samples =
R"doc(Assemble per-beam sample data into a [beams, samples] ensemble for a
selection.

Mirrors the kmall get_raw_amplitudes assembly: for each selected beam
the accessor returns the beam's native 1D samples, the selected sample
range is copied into the output row (cast to t_out on assignment).
Missing beams/samples are NaN (floating point) or 0 (integer).

Template Args:
    t_out: output value type
    t_beam_accessor: callable (const CompressedWaterColumnBeam&) ->
                     xt::xtensor<...,1>)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_class_name = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_get_amplitudes = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_get_beam_alongtrack_angles = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_get_beam_crosstrack_angles = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_get_beam_numbers_per_tx_sector = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_get_bottom_range_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_get_first_sample_offset_per_beam = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_get_multisectorwatercolumn_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_get_number_of_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_get_number_of_samples_per_beam = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_get_number_of_tx_sectors = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_get_phase =
R"doc(Water column phase in degrees (NaN for missing beams/samples, all-NaN
if the record contains no phase).)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_get_phase_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_get_raw_amplitudes =
R"doc(Water column amplitudes (magnitude) in their raw, unconverted values
(uint32).

The values are returned as stored on disk (widened to uint32; 16 bit
records keep their 0..65535 range). No dB conversion is applied - see
get_amplitudes for dB. Missing beams/samples are 0.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_get_raw_amplitudes_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_get_raw_phase =
R"doc(Water column phase in its raw, unconverted int16 values (radians =
value / 10430).

All-zero if the record contains no phase. Missing beams/samples are 0.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_get_raw_phase_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_get_sample_interval = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_get_sound_speed_at_transducer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_get_tx_sector_per_beam = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_get_tx_signal_parameters = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_get_watercolumn_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_has_amplitudes = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_has_beam_crosstrack_angles = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_has_beam_numbers_per_tx_sector = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_has_bottom_range_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_has_multisectorwatercolumn_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_has_number_of_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_has_number_of_tx_sectors = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_has_tx_sector_per_beam = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_has_tx_signal_parameters = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_has_watercolumn_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_index_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_load = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_loaded = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingWatercolumn_release = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


