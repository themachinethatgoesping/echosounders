//sourcehash: a3b03243ff83e6403b36f56651463de13576859f6d81e831c6ef57a9c31e558d

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


static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MWCRxBeamData = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MWCRxBeamData_MWCRxBeamData = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MWCRxBeamData_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MWCRxBeamData_beam_pointing_angle_re_vertical_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MWCRxBeamData_detected_range_in_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MWCRxBeamData_detected_range_in_samples_high_resolution = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MWCRxBeamData_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MWCRxBeamData_get_beam_pointing_angle_re_vertical_deg = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MWCRxBeamData_get_detected_range_in_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MWCRxBeamData_get_detected_range_in_samples_high_resolution = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MWCRxBeamData_get_number_of_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MWCRxBeamData_get_sample_amplitudes_in_db = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MWCRxBeamData_get_start_range_sample_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MWCRxBeamData_get_transmit_sector_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MWCRxBeamData_number_of_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MWCRxBeamData_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MWCRxBeamData_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MWCRxBeamData_read_sample_amplitudes_05dB =
R"doc(Read and return the sample data. This function allows for only reading
a selected number of samples

Parameter ``ifs``:
    InputFileHandler stream. Must be the same file the original
    structure was read from

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

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MWCRxBeamData_sample_amplitudes_05dB = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MWCRxBeamData_sample_pos =
R"doc(< the position of the sample data in the filestream. This < is used to
load skipped sample data.)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MWCRxBeamData_start_range_sample_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MWCRxBeamData_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_substructs_MWCRxBeamData_transmit_sector_number = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


