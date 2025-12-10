//sourcehash: 49df50a09761919fbed1312902070ebc557499bb2dd49f4d5ff06dbac4f727d1

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


static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram =
R"doc( This datagram is used for the models EM 2040, EM 2040C, EM 710, EM
 122, EM
302 and ME70BO. All receiver beams are included, check detection info
and real time cleaning for beam status (note 4 and 5).)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_AttitudeDatagram = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_AttitudeDatagram_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_attitude_counter = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_attitudes = R"doc(N x Attitude data)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_attitudes_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_checksum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_etx = R"doc(end identifier (always 0x03))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_from_stream_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_from_stream_3 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_get_attitude_counter = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_get_attitude_sensor_number =
R"doc(Get the number of attitude sensor from the sensor system descriptor
field. xx00 xxxx – attitude sensor number 1 xx01 xxxx – attitude
sensor number 2

Returns:
    1 or 2)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_get_attitudes = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_get_checksum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_get_etx = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_get_heading_sensor_is_active =
R"doc(Evaluate if the heading sensor is active using sensor system
descriptor field. 0bxxxxxxx1 : heading is active 0bxxxxxxx1 : heading
is inactive

Returns:
    bool)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_get_heave_sensor_is_active =
R"doc(Evaluate if the heave sensor is active using sensor system descriptor
field. 0bxxxx1xxx : heave is active 0bxxxx0xxx : heave is inactive

Returns:
    bool)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_get_number_of_entries = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_get_pitch_sensor_is_active =
R"doc(Evaluate if the pitch sensor is active using sensor system descriptor
field. 0bxxxxx1xx : pitch is active 0bxxxxx0xx : pitch is inactive

Returns:
    bool)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_get_roll_sensor_is_active =
R"doc(Evaluate if the roll sensor is active using sensor system descriptor
field. 0bxxxxxx1x : roll is active 0bxxxxxx0x : roll is inactive

Returns:
    bool)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_get_sensor_system_descriptor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_get_system_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_number_of_entries = R"doc(N)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_sensor_system_descriptor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_set_attitude_counter = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_set_attitudes = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_set_checksum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_set_etx = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_set_number_of_entries = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_set_sensor_system_descriptor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_set_system_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_system_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_AttitudeDatagram_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


