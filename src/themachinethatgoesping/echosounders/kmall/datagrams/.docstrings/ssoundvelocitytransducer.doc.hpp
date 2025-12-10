//sourcehash: edfb40e1b96795b4ef26afe38aaa37ed30e72fe445e447ada0965b0b72b3b537

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


static const char *mkd_doc__unnamed_class_at_themachinethatgoesping_echosounders_kmall_datagrams_ssoundvelocitytransducer_hpp_211_67 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer = R"doc(Clock datagrams)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_Content = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_Content_bytes_content = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_Content_filter_time_sec = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_Content_number_of_bytes_per_sample = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_Content_number_of_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_Content_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_Content_sensor_data_contents = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_Content_sensor_input_format = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_Content_sensor_status = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_Content_sound_velocity_offset_m_per_sec = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_SSoundVelocityTransducer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_SVTSample = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_SVTSample_get_sensor_date_string = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_SVTSample_get_sensor_timestamp = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_SVTSample_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_SVTSample_pressure_pa = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_SVTSample_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_SVTSample_salinity = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_SVTSample_soundVelocity_m_per_sec = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_SVTSample_temp_c = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_SVTSample_time_nanosec = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_SVTSample_time_sec = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_bytes_datagram_check = R"doc(Each datagram ends with the size of the datagram for integrity check)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_content = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_from_stream_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_from_stream_3 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_bytes_content = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_bytes_datagram_check = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_filter_time_sec = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_number_of_bytes_per_sample = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_number_of_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_pressure_active = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_salinity_active = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_sensor_data = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_sensor_data_contents = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_sensor_input_format = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_sensor_status = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_sound_velocity_active = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_sound_velocity_offset_m_per_sec = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_svt_pressures = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_svt_salinities = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_svt_sound_velocities = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_svt_temperatures = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_svt_timestamps = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_temperature_active = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_read = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_sensor_data = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_set_bytes_content = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_set_bytes_datagram_check = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_set_filter_time_sec = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_set_number_of_bytes_per_sample = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_set_number_of_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_set_pressure_active = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_set_salinity_active = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_set_sensor_data = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_set_sensor_data_contents = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_set_sensor_input_format = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_set_sensor_status = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_set_sound_velocity_active = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_set_sound_velocity_offset_m_per_sec = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_set_temperature_active = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_t_sensor_format = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_t_sensor_format_AML_NMEA = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_t_sensor_format_AML_SV = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_t_sensor_format_AML_SVP = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_t_sensor_format_AML_SVT = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_t_sensor_format_KSSIS_43 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_t_sensor_format_KSSIS_80 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_t_sensor_format_Micro_SV = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_t_sensor_format_Micro_SVP = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_t_sensor_format_Micro_SVT = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_t_sensor_format_Valeport_MiniSVS = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_t_sensor_format_Valeport_NMEA = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_t_sensor_format_XDR_S = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


