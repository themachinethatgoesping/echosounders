//sourcehash: 9c47fa1467e5870ed14c683a9ef799cbb59ef82ad0c227b0b50667fc0219abd4

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


static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer =
R"doc(Container for the per-beam data of a 7042 CompressedWaterColumnData
record.

Holds the per-beam raw sample blocks and the record-wide sample
encoding (magnitude bit depth, presence/bit depth of phase). Magnitude
and phase are decoded from the raw bytes on demand. If the samples
were skipped while reading, the file position is stored so they can be
read lazily.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_CompressedWaterColumnBeamContainer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_build_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_clear_skipped = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_decode_magnitude = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_decode_phase = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_beam_number_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_has_phase = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_magnitude = R"doc(magnitude of a beam (raw value, or dB if get_magnitude_is_db()))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_magnitude_bytes = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_magnitude_in_db =
R"doc(magnitude of a beam in dB (already-dB values pass through, else
20*log10(mag/full_scale)))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_magnitude_is_32bit_float = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_magnitude_is_db = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_number_of_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_phase = R"doc(phase of a beam in radians (empty if there is no phase))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_phase_8bit = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_phase_in_degrees = R"doc(phase of a beam in degrees (empty if there is no phase))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_sample_count_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_sample_position = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_sample_stride = R"doc(number of on-disk bytes per sample (magnitude + optional phase))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_samples_are_skipped = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_segment_number_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_total_number_of_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_has_phase = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_magnitude_bytes = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_magnitude_is_32bit_float = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_magnitude_is_db = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_phase_8bit = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_sample_position = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_set_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_set_has_phase = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_set_magnitude_bytes = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_set_magnitude_is_32bit_float = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_set_magnitude_is_db = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_set_phase_8bit = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_set_skipped = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_skipped = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


