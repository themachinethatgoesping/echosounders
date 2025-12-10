//sourcehash: a667569d774f3038b5f3c5c4e52eb81dc16143341b7794eaee0221d333e09544

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


static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_XML_Configuration = R"doc(XML Configuration datagram structure.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_XML_Configuration_ActivePingMode = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_XML_Configuration_ApplicationName = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_XML_Configuration_ChannelConfigurations = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_XML_Configuration_ConfiguredSensors = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_XML_Configuration_Copyright = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_XML_Configuration_FileFormatVersion = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_XML_Configuration_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_XML_Configuration_SensorConfigurations = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_XML_Configuration_TimeBias = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_XML_Configuration_Transceivers = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_XML_Configuration_Transducers = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_XML_Configuration_Version = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_XML_Configuration_XML_Configuration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_XML_Configuration_XML_Configuration_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_XML_Configuration_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_XML_Configuration_get_prioritized_sensor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_XML_Configuration_get_sensor_configuration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_XML_Configuration_get_sensors_sorted_by_priority = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_XML_Configuration_get_transceiver = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_XML_Configuration_get_transceiver_channel = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_XML_Configuration_get_transceiver_channels = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_XML_Configuration_get_transceivers = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_XML_Configuration_initialize = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_XML_Configuration_initialize_channelconfigurations = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_XML_Configuration_initialize_sensorconfigurations = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_XML_Configuration_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_XML_Configuration_operator_ne = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_XML_Configuration_parsed_completely = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_XML_Configuration_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_XML_Configuration_to_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_XML_Configuration_unknown_attributes = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_xml_datagrams_XML_Configuration_unknown_children = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


