//sourcehash: e6cb3731e56c8ff7a4c84342d885876eebc31ea13d096d6a5cd8feb41f257801

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


static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector =
R"doc(The beam data are given re the transmit transducer or sonar head depth
and the horizontal location (x,y) of the active positioning system's
reference point. Heave, roll, pitch, sound speed at the transducer
depth and ray bending through the water column have been applied.)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_RawRangeAndAngleTransmitSector = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_center_frequency = R"doc(< in Hz)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_focus_range = R"doc(< in 0.1m 0 = no focus applied)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_get_center_frequency = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_get_focus_range = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_get_focus_range_in_m =
R"doc(Get the focus range in m

Returns:
    _focus_range * 0.1 (float))doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_get_mean_absorption_coefficient = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_get_mean_absorption_coefficient_in_dB_per_m =
R"doc(Get the mean absorption coefficient in dB/m

Returns:
    _mean_absorption_coefficient * 10 (float))doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_get_sector_transmit_delay = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_get_signal_bandwidth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_get_signal_length = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_get_signal_waveform_identifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_get_tilt_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_get_tilt_angle_in_degrees =
R"doc(Get the tilt angle in °

Returns:
    _tilt_angle * 0.01 (float))doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_get_transmit_sector_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_get_tx_signal_type = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_mean_absorption_coefficient = R"doc(< in 0.01 dB/km)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_sector_transmit_delay = R"doc(< relative first TX pulse, in s)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_set_center_frequency = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_set_focus_range = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_set_mean_absorption_coefficient = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_set_sector_transmit_delay = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_set_signal_bandwidth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_set_signal_length = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_set_signal_waveform_identifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_set_tilt_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_set_transmit_sector_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_signal_bandwidth = R"doc(< in Hz)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_signal_length = R"doc(< in s)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_signal_waveform_identifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_tilt_angle = R"doc(< re TX array in 0.01°)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_RawRangeAndAngleTransmitSector_transmit_sector_number = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


