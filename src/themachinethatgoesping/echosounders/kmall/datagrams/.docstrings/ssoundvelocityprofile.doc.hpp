//sourcehash: 9632595f580364922844495db3df4388eadd4bc4cc171602bf0da257e3f9a243

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


static const char *mkd_doc__unnamed_class_at_themachinethatgoesping_echosounders_kmall_datagrams_ssoundvelocityprofile_hpp_169_67 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile = R"doc(Clock datagrams)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_Content = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_Content_bytes_content = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_Content_latitude_deg = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_Content_longitude_deg = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_Content_number_of_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_Content_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_Content_sensor_format = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_Content_svp_time_sec = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_SSoundVelocityProfile = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_SVPPoint = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_SVPPoint_depth_m = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_SVPPoint_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_SVPPoint_padding = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_SVPPoint_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_SVPPoint_salinity = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_SVPPoint_soundVelocity_m_per_sec = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_SVPPoint_temp_c = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_bytes_datagram_check = R"doc(Each datagram ends with the size of the datagram for integrity check)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_content = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_from_stream_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_from_stream_3 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_get_bytes_content = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_get_bytes_datagram_check = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_get_latitude_deg = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_get_longitude_deg = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_get_number_of_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_get_sensor_data = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_get_sensor_format = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_get_svp_absorption_computed = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_get_svp_depths = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_get_svp_salinities = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_get_svp_sound_velocities = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_get_svp_sound_velocities_computed = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_get_svp_temperatures = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_get_svp_time_sec = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_sensor_data = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_set_bytes_content = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_set_bytes_datagram_check = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_set_latitude_deg = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_set_longitude_deg = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_set_number_of_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_set_sensor_data = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_set_sensor_format = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_set_svp_time_sec = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_t_sensor_format = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_t_sensor_format_ctd_profile = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_t_sensor_format_sound_velocity_profile = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityProfile_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


