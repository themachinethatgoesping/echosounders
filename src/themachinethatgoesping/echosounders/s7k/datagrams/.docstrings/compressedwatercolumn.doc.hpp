//sourcehash: 6e1cc25cfc2604fe6287555f108926870e04d8b857bb6cd64bf41cf495f2de69

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


static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn =
R"doc(7k record CompressedWaterColumnData: per-beam water-column magnitude
(and optional phase) time series in a compressed (downsampled and/or
bit-reduced) form.

The exact sample encoding (magnitude bit depth, presence of phase,
downsampling) is controlled by the flags bit field. This class decodes
the magnitude to float and the phase to radians for convenient access.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_CompressedWaterColumn = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_Content = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_Content_compressed_samples = R"doc(maximum number of samples over all beams)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_Content_compression_factor = R"doc(magnitude compression factor)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_Content_first_sample = R"doc(first sample index for each beam)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_Content_flags = R"doc(compression control flags bit field)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_Content_multi_ping = R"doc(0 = single ping, else multi-ping sequence number)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_Content_number_beams = R"doc(number of beams)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_Content_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_Content_ping_number = R"doc(sequential ping number)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_Content_reserved = R"doc(reserved)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_Content_sample_rate = R"doc(effective sample rate after downsampling (Hz))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_Content_samples = R"doc(nominal number of samples (based on range))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_Content_serial_number = R"doc(sonar serial number)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_beam_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_content = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_from_stream_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_from_stream_3 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_beam_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_beam_phase_in_degrees = R"doc(phase of a single beam in degrees (empty if magnitude-only))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_compressed_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_compression_factor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_first_sample = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_flags = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_has_phase = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_magnitude_bytes = R"doc(number of bytes per magnitude sample as stored on disk (1, 2 or 4))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_magnitude_is_db = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_multi_ping = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_number_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_ping_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_sample_count = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_sample_rate = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_segment_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_sample_count = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_segment_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


