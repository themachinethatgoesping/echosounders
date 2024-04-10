//sourcehash: 367ba0a6826a56cbbb447b4d12387ff8adf8e388536b317de5d87d3d8d70c602

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


static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_KongsbergAllPingWatercolumn = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_class_name = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_get_amplitudes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_get_av = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_get_beam_alongtrack_angles = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_get_beam_crosstrack_angles = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_get_beam_numbers_per_tx_sector = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_get_bottom_range_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_get_corrected_amp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_get_detected_range_in_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_get_first_sample_offset_per_beam = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_get_number_of_beams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_get_number_of_samples_per_beam = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_get_number_of_tx_sectors = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_get_sample_correction = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_get_sample_interval = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_get_sample_positions = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_get_sector_correction = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_get_sound_speed_at_transducer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_get_start_range_sample_numbers = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_get_sv = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_get_system_correction = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_get_transmit_sector_numbers = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_get_tvg_factor_applied = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_get_tvg_offset = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_get_tx_sector_per_beam = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_get_tx_signal_parameters = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_has_amplitudes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_has_av = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_has_bottom_range_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_has_tx_sector_information = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_has_tx_signal_parameters = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_load = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_loaded = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingWatercolumn_release = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


