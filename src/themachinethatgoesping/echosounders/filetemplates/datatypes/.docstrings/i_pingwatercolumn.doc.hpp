//sourcehash: 640aedff2ebd851f398ae5b70742e7d7be9d995e3e0a1ae788b87dcf08e7db7a

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


static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn =
R"doc(Interface for all ping watercolumn functions

@class I_PingWatercolumn Interface for watercolumn ping data.

This class represents an interface for accessing watercolumn ping
data. It inherits from the I_PingCommon class and provides additional
functions and variables specific to watercolumn pings.)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_I_PingWatercolumn = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_I_PingWatercolumn_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_beam_sample_selection_all = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_beam_sample_selection_all_initialized = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_class_name = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_amplitudes =
R"doc(Get tha raw water amplitude data converted to float(32bit)

Returns:
    xt::xtensor<float,2>)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_amplitudes_2 =
R"doc(Get tha raw water amplitude data converted to float(32bit)

Parameter ``selection``:
    Selection of Beams and Samples to extract

Returns:
    xt::xtensor<float,2>)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_beam_alongtrack_angles =
R"doc(Get the beam alongtrack angles for this ping in °

Returns:
    xt::xtensor<float, 1>)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_beam_alongtrack_angles_2 =
R"doc(Get the beam alongtrack angles for this ping in °

Returns:
    xt::xtensor<float, 1>)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_beam_crosstrack_angles =
R"doc(Get the beam crosstrack angles for this ping in °

Returns:
    xt::xtensor<float, 1>)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_beam_crosstrack_angles_2 =
R"doc(Get the beam crosstrack angles for this ping in °

Returns:
    xt::xtensor<float, 1>)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_beam_sample_selection_all =
R"doc(Get beam sample selection that selects all beams and samples

Returns:
    pingtools::BeamSampleSelection)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_beam_selection_all =
R"doc(Get a beam selection object that selects all beams

Returns:
    pingtools::BeamSelection)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_bottom_range_samples =
R"doc(Get the sample number of the bottom detection for each beam

Returns:
    xt::xtensor<uint16_t, 1>)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_bottom_range_samples_2 =
R"doc(Get the sample number of the bottom detection for each selected beam

Parameter ``selection``:
    Selection of Beams to extract

Returns:
    xt::xtensor<uint16_t, 1>)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_first_sample_offset_per_beam = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_number_of_beams =
R"doc(Get the number of beams for this ping

Returns:
    uint16_t)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_number_of_samples_per_beam = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_number_of_samples_per_beam_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_get_sample_interval =
R"doc(Get the sample interval in seconds

Returns:
    float)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_has_amplitudes =
R"doc(Check this pings supports AMPLITUDES data

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_has_bottom_range_samples =
R"doc(Check this pings supports bottom range samples

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingWatercolumn_printer = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


