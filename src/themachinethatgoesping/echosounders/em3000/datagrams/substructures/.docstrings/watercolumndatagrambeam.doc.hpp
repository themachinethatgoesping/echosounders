//sourcehash: edfc381b6b42cc8bf6cabd54907eb1550d10aac580b32dc1dbf245ac6f4edccf

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


static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_WaterColumnDatagramBeam = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_beam_number = R"doc(< redundant info, max 255 even if more beams exist)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_beam_pointing_angle = R"doc(< re vertical in 0.01 steps°)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_detected_range_in_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_get_beam_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_get_beam_pointing_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_get_beam_pointing_angle_in_degrees =
R"doc(get the tilt angle in °

Returns:
    _beam_pointing_angle * 0.1° (float))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_get_detected_range_in_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_get_number_of_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_get_sample_position = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_get_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_get_samples_are_skipped = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_get_samples_in_db = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_get_start_range_sample_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_get_transmit_sector_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_number_of_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_read_samples =
R"doc(Read and return the sample data. This is useful if the sample data was
originally skipped

Parameter ``ifs``:
    Inputfile stream. Must be the same file the original structure was
    read from

Returns:
    xt::xtensor<int8_t, 1>)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_read_samples_2 =
R"doc(Read and return the sample data. This function allows for only reading
a selected number of samples

Parameter ``ifs``:
    Inputfile stream. Must be the same file the original structure was
    read from

Parameter ``pos_first_samples``:
    The position of the first sample in the structure

Parameter ``first_sample``:
    The first sample to read

Parameter ``number_of_samples``:
    The number of samples to read

Parameter ``number_of_samples_in_datagram``:
    The total number of samples in the datagram

Parameter ``fill_val``:
    The value to fill the array with if the requested number of
    samples is

Returns:
    xt::xtensor<int8_t, 1>)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_sample_pos =
R"doc(< the position of the sample data in the filestream. This < is used to
load skipped sample data.)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_samples_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_samples_are_skipped = R"doc(< in 0.5 dB steps)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_set_beam_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_set_beam_pointing_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_set_detected_range_in_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_set_number_of_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_set_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_set_start_range_sample_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_set_transmit_sector_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_start_range_sample_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_WaterColumnDatagramBeam_transmit_sector_number = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


