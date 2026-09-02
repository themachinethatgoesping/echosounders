//sourcehash: 9a93fc171ac407689eea96dc64ddc0f878e532e7d234209dd85eed51adebde60

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


static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam =
R"doc(Per-beam data of a 7042 CompressedWaterColumnData record.

The magnitude (and optional phase) samples are kept as the raw
(interleaved) on-disk bytes and decoded on demand. The sample encoding
(magnitude bit depth, presence and bit depth of phase) is controlled
by the record flags and stored per beam so each beam can decode
itself.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_CompressedWaterColumnBeam = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_beam_number = R"doc(beam number)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_get_beam_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_get_has_phase = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_get_magnitude = R"doc(magnitude of this beam (raw value, or dB if get_magnitude_is_db()))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_get_magnitude_bytes = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_get_magnitude_in_db =
R"doc(magnitude of this beam in dB (see
CompressedWaterColumn::get_beam_magnitude_in_db))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_get_magnitude_is_32bit_float = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_get_magnitude_is_db = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_get_phase = R"doc(phase of this beam in radians (empty if there is no phase))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_get_phase_8bit = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_get_phase_in_degrees = R"doc(phase of this beam in degrees (empty if there is no phase))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_get_raw_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_get_sample_count = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_get_sample_stride = R"doc(number of on-disk bytes per sample (magnitude + optional phase))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_get_segment_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_has_phase = R"doc(true if a phase value follows each magnitude)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_magnitude_bytes = R"doc(bytes per magnitude sample (1, 2 or 4))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_magnitude_is_32bit_float = R"doc(true if the magnitude is 32-bit IEEE float)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_magnitude_is_db = R"doc(true if the magnitude is already stored in dB)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_phase_8bit = R"doc(true if the phase is 8-bit (else 16-bit))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_raw_samples = R"doc(raw interleaved [magnitude][phase] sample bytes)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_sample_count = R"doc(number of samples for this beam)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_segment_number = R"doc(segment number (0 if segments are not used))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_set_beam_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_set_has_phase = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_set_magnitude_bytes = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_set_magnitude_is_32bit_float = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_set_magnitude_is_db = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_set_phase_8bit = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_set_raw_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_set_sample_count = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeam_set_segment_number = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


