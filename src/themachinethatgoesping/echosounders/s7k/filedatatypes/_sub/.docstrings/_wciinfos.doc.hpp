//sourcehash: 42ca63b9f3a39a2328edeb231332739f2d6fe1c28b5843ad6e7d3b241366dabd

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


static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WCIInfos =
R"doc(Record-wide (not per-beam) information of a 7042
CompressedWaterColumnData record.

This is the part of the water column information that is constant for
the whole record (sample rate, first sample, beam count and the sample
encoding). It is held as a flyweight so that identical configurations
(the common case for consecutive pings) are stored only once.

Note this is a private substructure and thus not part of the public
API or nanobind interface.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WCIInfos_WCIInfos = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WCIInfos_WCIInfos_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WCIInfos_downsampling_divisor = R"doc(downsampling divisor (1 = no downsampling))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WCIInfos_first_sample = R"doc(first sample index (same for every beam))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WCIInfos_from_binary = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WCIInfos_get_bytes_per_sample = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WCIInfos_get_data_type = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WCIInfos_get_downsampling_divisor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WCIInfos_get_first_sample = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WCIInfos_get_has_phase = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WCIInfos_get_magnitude_bytes = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WCIInfos_get_magnitude_compression_factor =
R"doc(factor used to compress magnitude into 8-bit dB (stored =
factor*log10(mag); DFD App. I); 0 when the magnitude is not stored as
8-bit dB

)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WCIInfos_get_magnitude_is_32bit = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WCIInfos_get_magnitude_is_db = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WCIInfos_get_number_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WCIInfos_get_sample_rate = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WCIInfos_has_phase = R"doc(whether the record contains phase data)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WCIInfos_magnitude_bytes = R"doc(bytes per magnitude sample on disk (1, 2 or 4))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WCIInfos_magnitude_compression_factor = R"doc(8-bit dB compression factor (0 if not dB))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WCIInfos_magnitude_is_db = R"doc(whether the 8-bit magnitude is already in dB)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WCIInfos_number_beams = R"doc(number of beams)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WCIInfos_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WCIInfos_sample_rate = R"doc(effective sample rate after downsampling (Hz))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WCIInfos_to_binary = R"doc()doc";


#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


