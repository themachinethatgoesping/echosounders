//sourcehash: a41b2fd7e069064ea7fab0e28c45be0266b624ea14454698f8b2210b4cdaa2f5

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


static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram =
R"doc(Used for EM 122, EM 302, EM 710, EM 2040, EM 3002. The receiver beams
are roll stabilized.)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_WaterColumnDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_WaterColumnDatagram_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_append_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_beams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_beams_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_datagram_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_etx = R"doc(< end identifier (always 0x03))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_from_stream_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_get_beams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_get_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_get_datagram_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_get_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_get_max_number_of_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_get_number_of_beams_in_datagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_get_number_of_datagrams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_get_number_of_transmit_sectors = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_get_ping_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_get_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_get_sampling_frequency = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_get_sampling_frequency_in_hz =
R"doc(Get the sampling frequency in Hz

Returns:
    _sampling_frequency * 0.01 Hz (float))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_get_scanning_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_get_sound_speed = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_get_sound_speed_m_s =
R"doc(Get the sound speed in m/s

Returns:
    _sound_speed * 0.1 m/s (float))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_get_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_get_spare_byte = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_get_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_get_total_no_of_receive_beams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_get_transmit_sectors = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_get_tvg_function_applied = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_get_tvg_offset_in_db = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_get_tx_time_heave = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_get_tx_time_heave_in_m =
R"doc(Get the transmit time heave in m

Returns:
    _tx_time_heave * 0.01 m (float))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_number_of_beams_in_datagram = R"doc(< Beam vector of 2 elements)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_number_of_datagrams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_number_of_transmit_sectors = R"doc(< Transmit_sector vector of 2 elements)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_ping_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_read_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_sampling_frequency = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_scanning_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_set_beams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_set_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_set_datagram_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_set_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_set_number_of_beams_in_datagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_set_number_of_datagrams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_set_number_of_transmit_sectors = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_set_ping_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_set_sampling_frequency = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_set_scanning_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_set_sound_speed = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_set_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_set_spare_byte = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_set_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_set_total_no_of_receive_beams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_set_transmit_sectors = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_set_tvg_function_applied = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_set_tvg_offset_in_db = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_set_tx_time_heave = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_sound_speed = R"doc(< in 0.1 m/s)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_spare_byte = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_total_no_of_receive_beams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_transmit_sectors = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_transmit_sectors_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_tvg_function_applied = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_tvg_offset_in_db = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_tx_time_heave = R"doc(< in cm)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_WaterColumnDatagram_without_beams = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


