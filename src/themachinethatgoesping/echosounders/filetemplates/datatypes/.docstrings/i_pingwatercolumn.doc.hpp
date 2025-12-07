//sourcehash: 5a9ee9e656409d8603a8b66336db3fa80447c904b4abd0f58b1198b338b83c21

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


static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn =
R"doc(Interface for all ping watercolumn functions

@class I_PingWatercolumn Interface for watercolumn ping data.

This class represents an interface for accessing watercolumn ping
data. It inherits from the I_PingCommon class and provides additional
functions and variables specific to watercolumn pings.)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_I_PingWatercolumn = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_beam_sample_selection_all = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_beam_sample_selection_all_is_initialized = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_class_name = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_feature_group_functions = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_amplitudes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_amplitudes_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_ap = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_ap_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_approximate_ranges = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_approximate_ranges_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_av = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_av_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_beam_alongtrack_angles = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_beam_alongtrack_angles_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_beam_crosstrack_angles = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_beam_crosstrack_angles_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_beam_numbers_per_tx_sector = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_beam_numbers_per_tx_sector_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_beam_sample_selection_all = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_beam_selection_all = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_bottom_range_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_bottom_range_samples_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_calibrated_wci = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_first_sample_offset_per_beam = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_minslant_sample_nr = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_minslant_sample_nr_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_multisectorwatercolumn_calibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_number_of_beams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_number_of_samples_per_beam = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_number_of_samples_per_beam_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_number_of_tx_sectors = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_power = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_power_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_pp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_pp_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_pv = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_pv_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_rp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_rp_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_rv = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_rv_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_sample_interval = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_sound_speed_at_transducer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_sp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_sp_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_sv = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_sv_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_test_mode = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_tx_sector_per_beam = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_tx_sector_per_beam_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_tx_signal_parameters = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_watercolumn_calibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_watercolumn_calibration_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_wci = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_wci_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_wci_correction = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_wci_correction_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_wci_correction_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_has_amplitudes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_has_ap = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_has_av = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_has_beam_crosstrack_angles = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_has_beam_numbers_per_tx_sector = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_has_beam_selection_all = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_has_bottom_range_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_has_multisectorwatercolumn_calibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_has_number_of_beams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_has_number_of_tx_sectors = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_has_power = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_has_pp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_has_pv = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_has_rp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_has_rv = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_has_sp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_has_sv = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_has_tx_sector_per_beam = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_has_tx_signal_parameters = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_has_watercolumn_calibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_primary_feature_functions = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_secondary_feature_functions = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_set_test_mode = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_test_mode = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


