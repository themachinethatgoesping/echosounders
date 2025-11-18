//sourcehash: ae446ac028040537f627ebf1a13089bc911069278fb4fe528e97152ed5359773

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


static const char *__doc__unnamed_class_at_themachinethatgoesping_echosounders_kmall_datagrams_ssoundvelocitytransducer_hpp_211_67 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer = R"doc(Clock datagrams)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_Content = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_Content_bytes_content = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_Content_filter_time_sec = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_Content_number_of_bytes_per_sample = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_Content_number_of_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_Content_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_Content_sensor_data_contents = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_Content_sensor_input_format = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_Content_sensor_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_Content_sound_velocity_offset_m_per_sec = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_SSoundVelocityTransducer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_SVTSample = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_SVTSample_get_sensor_date_string = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_SVTSample_get_sensor_timestamp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_SVTSample_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_SVTSample_pressure_pa = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_SVTSample_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_SVTSample_salinity = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_SVTSample_soundVelocity_m_per_sec = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_SVTSample_temp_c = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_SVTSample_time_nanosec = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_SVTSample_time_sec = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_bytes_datagram_check =
R"doc(< Each datagram ends with the size of the datagram for < integrity
check)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_content = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_from_stream_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_bytes_content = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_bytes_datagram_check = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_filter_time_sec = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_number_of_bytes_per_sample = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_number_of_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_pressure_active = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_salinity_active = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_sensor_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_sensor_data_contents = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_sensor_input_format = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_sensor_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_sound_velocity_active = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_sound_velocity_offset_m_per_sec = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_svt_pressures = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_svt_salinities = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_svt_sound_velocities = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_svt_temperatures = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_svt_timestamps = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_get_temperature_active = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_read = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_sensor_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_set_bytes_content = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_set_bytes_datagram_check = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_set_filter_time_sec = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_set_number_of_bytes_per_sample = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_set_number_of_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_set_pressure_active = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_set_salinity_active = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_set_sensor_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_set_sensor_data_contents = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_set_sensor_input_format = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_set_sensor_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_set_sound_velocity_active = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_set_sound_velocity_offset_m_per_sec = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_set_temperature_active = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_t_sensor_format = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_t_sensor_format_AML_NMEA = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_t_sensor_format_AML_SV = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_t_sensor_format_AML_SVP = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_t_sensor_format_AML_SVT = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_t_sensor_format_KSSIS_43 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_t_sensor_format_KSSIS_80 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_t_sensor_format_Micro_SV = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_t_sensor_format_Micro_SVP = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_t_sensor_format_Micro_SVT = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_t_sensor_format_Valeport_MiniSVS = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_t_sensor_format_Valeport_NMEA = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_t_sensor_format_XDR_S = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_SSoundVelocityTransducer_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


