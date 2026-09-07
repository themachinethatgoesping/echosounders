//sourcehash: 8f6a0a9c3eb951a6dabb2f307526e47c49518c82a53b8c38b396a720324da6c5

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

Holds the per-beam samples (each beam stores its data in its native,
on-disk encoding, see CompressedWaterColumnDataVariant) and the
record-wide sample encoding (magnitude bit depth, presence of phase).
Magnitude/phase are converted to float / dB / degrees on demand; the
dB and phase conversions are centralized here (convert_magnitude_to_db
/ phase constants) and reused by the ping water column accessor for
the deferred, vectorized bulk conversion. If the samples were skipped
while reading, the file position is stored so they can be read lazily.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_CompressedWaterColumnBeamContainer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_build_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_clear_skipped = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_convert_magnitude_to_db =
R"doc(Convert raw magnitude values (as float) to dB, according to the record
encoding.

This is a vectorized (xsimd-friendly) expression that is reused by the
ping water column accessor to convert only the selected beams/samples.
8 bit values are already stored in a (compressed) dB scale and pass
through; 16/32 bit values are 20*log10(mag/full_scale).

Template Args:
    Tensor: xtensor of float (1D per beam or 2D beams x samples))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_beam_number_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_data_type =
R"doc(the per-sample encoding of this record (derived from the encoding
flags))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_has_phase = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_magnitude = R"doc(magnitude of a beam (raw values as float, not dB))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_magnitude_bytes = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_magnitude_in_db =
R"doc(magnitude of a beam in dB (already-dB values pass through, else
20*log10(mag/full_scale)))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_magnitude_is_32bit = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_magnitude_is_db = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_number_of_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_phase = R"doc(phase of a beam in radians (empty if there is no phase))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_phase_in_degrees = R"doc(phase of a beam in degrees (empty if there is no phase))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_sample_count_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_sample_position = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_samples_are_skipped = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_segment_number_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_get_total_number_of_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_has_phase = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_magnitude_bytes = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_magnitude_is_db = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_sample_position = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_set_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_set_has_phase = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_set_magnitude_bytes = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_set_magnitude_is_db = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_set_skipped = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnBeamContainer_skipped = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


