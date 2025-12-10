//sourcehash: 3e81b6a1eff32be4a92348d60aa4263d7017f2c41a0a6f1a76eb070c8801e9ee

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


static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData =
R"doc( This datagram is used for the models EM 2040, EM 2040C, EM 710, EM
 122, EM
302 and ME70BO. All receiver beams are included, check detection info
and real time cleaning for beam status (note 4 and 5).)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_SeabedImageData = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_SeabedImageData_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_beams_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_checksum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_etx = R"doc(end identifier (always 0x03))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_from_stream_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_from_stream_3 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_get_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_get_checksum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_get_etx = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_get_normal_incidence_backscatter = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_get_normal_incidence_backscatter_in_db =
R"doc(Get the normal incidence backscatter in db

Returns:
    _normal_incidence_backscatter * 0.01f (float))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_get_number_of_valid_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_get_oblique_backscatter = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_get_oblique_backscatter_in_db =
R"doc(Get the oblique backscatter in db

Returns:
    _oblique_backscatter * 0.01f (float))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_get_ping_counter = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_get_range_to_normal_incidence = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_get_sample_amplitudes = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_get_sampling_frequency = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_get_spare_byte = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_get_system_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_get_tvg_law_crossover_angle = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_get_tvg_law_crossover_angle_in_degrees =
R"doc(get the tvg law crossover angle in degrees

Returns:
    _tvg_law_crossover_angle * 0.1f (float))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_get_tx_beamwidth_along = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_get_tx_beamwidth_along_in_degrees =
R"doc(get the tx beamwidth along in degrees

Returns:
    _tx_beamwidth_along * 0.1f (float))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_normal_incidence_backscatter = R"doc(in 0.01 dB (BSN))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_number_of_valid_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_oblique_backscatter = R"doc(in 0.01 dB (BSO))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_ping_counter = R"doc(sequential number)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_range_to_normal_incidence = R"doc(used to correct sample amplitudes in no. of samples)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_sample_amplitudes = R"doc(in 0.1 dB (size = sum of _Number_of_samples of all Beams)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_sample_amplitudes_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_sampling_frequency = R"doc(in Hz)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_set_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_set_checksum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_set_etx = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_set_normal_incidence_backscatter = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_set_number_of_valid_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_set_oblique_backscatter = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_set_ping_counter = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_set_range_to_normal_incidence = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_set_sample_amplitudes = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_set_sampling_frequency = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_set_spare_byte = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_set_system_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_set_tvg_law_crossover_angle = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_set_tx_beamwidth_along = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_spare_byte = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_system_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_to_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_tvg_law_crossover_angle = R"doc(in 0.1 degree)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_SeabedImageData_tx_beamwidth_along = R"doc(in 0.1 degree)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


