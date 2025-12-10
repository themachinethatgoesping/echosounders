//sourcehash: e9e9bb56e1c087206ec07143c1b11e9eccdf51c93ae4153c30380c683879a700

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


static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_MRZSoundingsContainer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_build_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_beam_angle_correction_deg_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_beam_angle_re_rx_deg_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_beam_inc_angle_adj_deg_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_bs_calibration_db_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_delta_latitude_deg_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_delta_longitude_deg_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_detection_class_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_detection_confidence_level_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_detection_method_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_detection_type_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_detection_uncertainty_hor_m_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_detection_uncertainty_ver_m_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_detection_window_length_sec_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_echo_length_sec_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_mean_abs_coeff_db_per_km_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_number_of_seabed_image_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_number_of_soundings = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_padding_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_post_processing_info_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_quality_factor_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_range_factor_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_real_time_clean_info_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_receiver_sensitivity_applied_db_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_reflectivity_1_db_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_reflectivity_2_db_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_rejection_info_1_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_rejection_info_2_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_seabed_image_sounding_index_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_si_centre_sample_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_si_num_samples_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_si_start_range_samples_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_sounding_index_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_soundings = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_source_level_applied_db_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_tvg_db_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_two_way_travel_time_correction_sec_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_two_way_travel_time_sec_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_tx_sector_number_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_wc_beam_number_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_wc_nom_beam_angle_across_deg_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_wc_range_samples_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_x_re_ref_point_m_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_y_re_ref_point_m_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_get_z_re_ref_point_m_tensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_set_soundings = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MRZSoundingsContainer_soundings = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


