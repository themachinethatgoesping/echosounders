//sourcehash: bc9776fd5f8389ac64c8f8c837129475a8f1a130e91e340aa2bfbf850543005f

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


static const char *__doc_themachinethatgoesping_echosounders_pingtools_substructures_BeamSampleSelection =
R"doc(A class to hold the selected beams/sample range for a single
transducer)doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_substructures_BeamSampleSelection_BeamSampleSelection = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_substructures_BeamSampleSelection_BeamSampleSelection_2 =
R"doc(Construct a new Beam Sample Selection object

Parameter ``beam_selection``:)doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_substructures_BeamSampleSelection_BeamSampleSelection_3 =
R"doc(Initialize a beam sample selection from a whole swath

Parameter ``beam_nr``:
    beam number

Parameter ``first_sample_number``:
    first sample number to select

Parameter ``last_sample_number_per_beam``:
    last sample number to select)doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_substructures_BeamSampleSelection_add_beam =
R"doc(Add a beam to the selection

Parameter ``beam_nr``:
    beam number

Parameter ``first_sample_number``:
    first sample number to select

Parameter ``last_sample_number_per_beam``:
    last sample number to select)doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_substructures_BeamSampleSelection_first_sample_number_ensemble = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_substructures_BeamSampleSelection_first_sample_number_per_beam = R"doc(< first sample number per beam)doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_substructures_BeamSampleSelection_from_stream =
R"doc(Return a BeamSampleSelection read from a binary stream

Parameter ``is``:
    input stream

Returns:
    BeamSampleSelection)doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_substructures_BeamSampleSelection_get_first_sample_number_ensemble =
R"doc(Return the first sample number of the ensemble

Returns:
    uint16_t)doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_substructures_BeamSampleSelection_get_first_sample_number_per_beam =
R"doc(Return the first sample number per beam

Returns:
    std::vector<uint16_t>)doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_substructures_BeamSampleSelection_get_last_sample_number_ensemble =
R"doc(Return the last sample number of the ensemble

Returns:
    uint16_t)doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_substructures_BeamSampleSelection_get_last_sample_number_per_beam =
R"doc(Return the max number of samples per beam

Returns:
    std::vector<uint16_t>)doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_substructures_BeamSampleSelection_get_number_of_samples_ensemble =
R"doc(return the number of samples within the ensemble

Returns:
    uint16_t)doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_substructures_BeamSampleSelection_get_read_sample_range =
R"doc(Return the read sample range for a given beam

Parameter ``beam_index``:
    index of the beam within the beam sample selection

Parameter ``first_sample_offset``:
    offset to the first sample (often 0)

Parameter ``number_of_samples``:
    number of samples in the real beam structure

Returns:
    ReadSampleRange read sample range)doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_substructures_BeamSampleSelection_get_sample_step_ensemble =
R"doc(Return the sample step size

Returns:
    uint16_t)doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_substructures_BeamSampleSelection_last_sample_number_ensemble = R"doc(< maximum sample number < (max(last_sample_number_per_beam)))doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_substructures_BeamSampleSelection_last_sample_number_per_beam = R"doc(< last sample number per beam)doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_substructures_BeamSampleSelection_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_substructures_BeamSampleSelection_printer =
R"doc(Print function, needs __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__ macro
See also: classhelper/objectprinter.hpp

Parameter ``float_precision``:
    Precision of floating point numbers

Returns:
    classhelper::ObjectPrinter)doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_substructures_BeamSampleSelection_sample_step_ensemble = R"doc(< sample step size (same for the entire ensemble))doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_substructures_BeamSampleSelection_set_first_sample_number_ensemble = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_substructures_BeamSampleSelection_set_last_sample_number_ensemble = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_substructures_BeamSampleSelection_set_sample_step_ensemble = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_substructures_BeamSampleSelection_to_stream =
R"doc(Write a BeamSampleSelection to a binary stream

Parameter ``os``:
    output stream)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


