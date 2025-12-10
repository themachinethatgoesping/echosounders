//sourcehash: 60006caac6197af4d46c1715a842119372baa97defe365e6e678fe8b4512c3b6

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


static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle =
R"doc( This datagram is used for the models EM 2040, EM 2040C, EM 710, EM
 122, EM
302 and ME70BO. All receiver beams are included, check detection info
and real time cleaning for beam status (note 4 and 5).)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_RawRangeAndAngle = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_RawRangeAndAngle_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_beams_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_checksum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_d_scale = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_etx = R"doc(end identifier (always 0x03))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_from_stream_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_from_stream_3 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_get_beam_crosstrack_angles =
R"doc(Read the beam crosstrack angles from the RawRangeAndAngle structure

Returns:
    xt::xtensor<float, 1>)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_get_beam_crosstrack_angles_2 =
R"doc(Read the two way travel times for given beam_number vector from the
RawRangeAndAngle structure Note: if a beam number is not found, the
corresponding time value will be NaN

Args:
    beam_numbers:  

Returns:
    xt::xtensor<float, 1>)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_get_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_get_checksum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_get_d_scale = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_get_etx = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_get_number_of_receiver_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_get_number_of_transmit_sectors = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_get_number_of_valid_detections = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_get_ping_counter = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_get_sampling_frequency = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_get_sound_speed_at_transducer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_get_sound_speed_at_transducer_in_m_per_s =
R"doc(Get the sound speed at the transducerin meters per seconds

Returns:
    _sound_speed_at_transducer * 0.1 meters per seconds (float))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_get_spare = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_get_system_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_get_transmit_sectors = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_get_two_way_travel_times =
R"doc(Read the two way travel times from the RawRangeAndAngle structure

Returns:
    xt::xtensor<float, 1>)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_get_two_way_travel_times_2 =
R"doc(Read the two way travel times for given beam_number vector from the
RawRangeAndAngle structure Note: if a beam number is not found, the
corresponding time value will be NaN

Args:
    beam_numbers:  

Returns:
    xt::xtensor<float, 1>)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_number_of_receiver_beams = R"doc(in Datagram nrx)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_number_of_transmit_sectors = R"doc(ntx)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_number_of_valid_detections = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_ping_counter = R"doc(sequential number)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_sampling_frequency = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_set_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_set_checksum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_set_d_scale = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_set_etx = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_set_number_of_receiver_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_set_number_of_transmit_sectors = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_set_number_of_valid_detections = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_set_ping_counter = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_set_sampling_frequency = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_set_sound_speed_at_transducer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_set_spare = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_set_system_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_set_transmit_sectors = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_sound_speed_at_transducer = R"doc(in 0.1 m/s)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_spare = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_system_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_to_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_transmit_sectors = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_RawRangeAndAngle_transmit_sectors_2 = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


