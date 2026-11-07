//sourcehash: 3b0f838b8f56a9efd29bcf498d8799db739ea2d2c0a154df34ce88e00fe72fa0

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


static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_SysInfos =
R"doc(Record-wide system settings of a ping, extracted from the 7000
SonarSettings record.

All fields are small scalars that are constant for a given sonar
configuration, so the whole structure is held as a flyweight
(identical configurations across pings are stored once). 6 contiguous
floats -> no padding, so the raw bytes are used for serialization and
hashing.

Note this is a private substructure and thus not part of the public
API or nanobind interface.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_SysInfos_SysInfos = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_SysInfos_SysInfos_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_SysInfos_absorption = R"doc(absorption (dB/km, as stored in the 7000 record))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_SysInfos_frequency = R"doc(transmit frequency (Hz))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_SysInfos_from_binary = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_SysInfos_get_absorption = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_SysInfos_get_frequency = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_SysInfos_get_receiver_bandwidth = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_SysInfos_get_sound_velocity = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_SysInfos_get_spreading = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_SysInfos_get_tx_pulse_width = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_SysInfos_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_SysInfos_receiver_bandwidth = R"doc(receiver bandwidth (Hz))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_SysInfos_sound_velocity = R"doc(sound velocity (m/s))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_SysInfos_spreading = R"doc(spreading loss / applied TVG log factor)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_SysInfos_to_binary = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_SysInfos_tx_pulse_width = R"doc(transmit pulse length (s))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_SystemInformation =
R"doc(Lightweight system information of a single s7k ping (7000
SonarSettings).

Provides the transmit signal parameters (a single CW sector for s7k)
and the scalars needed to build the water-column calibration (sound
velocity, pulse duration, applied TVG factor, absorption). The 7000
record itself is not retained; identical configurations are
deduplicated via the _SysInfos flyweight.

Note this is a private substructure and thus not part of the public
API or nanobind interface.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_SystemInformation_SystemInformation = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_SystemInformation_SystemInformation_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_SystemInformation_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_SystemInformation_get_absorption_db_m = R"doc(absorption to (un)apply in dB/m (7000 absorption is dB/km))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_SystemInformation_get_number_of_tx_sectors = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_SystemInformation_get_pulse_duration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_SystemInformation_get_sound_velocity = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_SystemInformation_get_tvg_factor = R"doc(applied TVG log-range factor ("spreading": 0 / 20 / 40))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_SystemInformation_get_tx_signal_parameters = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_SystemInformation_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_SystemInformation_sysinfos = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_SystemInformation_to_stream = R"doc()doc";


#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


