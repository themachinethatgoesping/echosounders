//sourcehash: 91307b20f55dc346b6782b6c752e1bce0d3d50049a81b0d9e8206b64b6742f10

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


static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle =
R"doc(This datagram is used for the models EM 2040, EM 2040C, EM 710, EM
122, EM 302 and ME70BO. All receiver beams are included, check
detection info and real time cleaning for beam status (note 4 and 5).)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_RawRangeAndAngle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_RawRangeAndAngle_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_beams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_beams_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_d_scale = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_etx = R"doc(< end identifier (always 0x03))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_from_stream_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_get_beams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_get_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_get_d_scale = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_get_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_get_number_of_receiver_beams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_get_number_of_transmit_sectors = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_get_number_of_valid_detections = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_get_ping_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_get_sampling_frequency = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_get_sound_speed_at_transducer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_get_sound_speed_at_transducer_in_m_per_s =
R"doc(Get the sound speed at the transducerin meters per seconds

Returns:
    _sound_speed_at_transducer * 0.1 meters per seconds (float))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_get_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_get_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_get_transmit_sectors = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_number_of_receiver_beams = R"doc(< in Datagram nrx)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_number_of_transmit_sectors = R"doc(< ntx)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_number_of_valid_detections = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_ping_counter = R"doc(< sequential number)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_sampling_frequency = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_set_beams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_set_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_set_d_scale = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_set_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_set_number_of_receiver_beams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_set_number_of_transmit_sectors = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_set_number_of_valid_detections = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_set_ping_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_set_sampling_frequency = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_set_sound_speed_at_transducer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_set_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_set_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_set_transmit_sectors = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_sound_speed_at_transducer = R"doc(< in 0.1 m/s)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_transmit_sectors = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_RawRangeAndAngle_transmit_sectors_2 = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


