//sourcehash: 786be254f772effc545ae80e1eca6f51a84d777910fe666bca5939138c343c10

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


static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_sub_WaterColumnInformation =
R"doc(This is a substructure of the KMALLPingWaterColumn class. It is used
to store information necessary to efficiently read water column data
from the file. It does not hold the actual water column samples

Note this is a private substructure and is thus not part of the public
API or pybind11 interface.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_sub_WaterColumnInformation_WaterColumnInformation = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_sub_WaterColumnInformation_WaterColumnInformation_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_sub_WaterColumnInformation_detected_range_in_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_sub_WaterColumnInformation_detected_range_in_samples_high_resolution = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_sub_WaterColumnInformation_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_sub_WaterColumnInformation_get_beam_crosstrack_angles = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_sub_WaterColumnInformation_get_detected_range_in_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_sub_WaterColumnInformation_get_detected_range_in_samples_high_resolution = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_sub_WaterColumnInformation_get_number_of_samples_per_beam = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_sub_WaterColumnInformation_get_sample_interval = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_sub_WaterColumnInformation_get_sample_positions = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_sub_WaterColumnInformation_get_sound_speed_at_transducer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_sub_WaterColumnInformation_get_start_range_sample_numbers = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_sub_WaterColumnInformation_get_transmit_sector_numbers = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_sub_WaterColumnInformation_get_transmit_sectors = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_sub_WaterColumnInformation_get_tvg_factor_applied = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_sub_WaterColumnInformation_get_tvg_offset_in_db = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_sub_WaterColumnInformation_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_sub_WaterColumnInformation_read_beam_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_sub_WaterColumnInformation_sample_positions = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_sub_WaterColumnInformation_to_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_sub_WaterColumnInformation_wci_infos = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


