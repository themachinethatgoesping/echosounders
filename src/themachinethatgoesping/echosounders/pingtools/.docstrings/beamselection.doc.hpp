//sourcehash: e797db2e76f4324b9a01f41a4cd562126d695469cb51215f61726d475fdb8186

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


static const char *mkd_doc_themachinethatgoesping_echosounders_pingtools_BeamSelection =
R"doc(A class to hold the selected beams/sample range for a single
transducer)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_pingtools_BeamSelection_BeamSelection = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_pingtools_BeamSelection_BeamSelection_2 =
R"doc(Initialize a beam sample selection from a whole swath

Args:
    number_of_beams: number of beams in the swath)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_pingtools_BeamSelection_BeamSelection_3 =
R"doc(Initialize a beam sample selection from a whole swath

Args:
    number_of_beams: number of beams in the swath)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_pingtools_BeamSelection_add_beam =
R"doc(Add a beam to the selection

Args:
    beam_nr: beam number
    first_sample_number: first sample number to select
    last_sample_number_per_beam: last sample number to select)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_pingtools_BeamSelection_beam_numbers = R"doc(selected beam numbers)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_pingtools_BeamSelection_empty =
R"doc(return if the selection contains beams

Returns:
    true false)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_pingtools_BeamSelection_from_stream =
R"doc(Return a BeamSelection read from a binary stream

Args:
    is: input stream

Returns:
    BeamSelection)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_pingtools_BeamSelection_get_beam_numbers =
R"doc(Return the beam numbers

Returns:
    std::vector<uint32_t>)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_pingtools_BeamSelection_get_number_of_beams =
R"doc(Return the number of beams

Returns:
    size_t)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_pingtools_BeamSelection_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_pingtools_BeamSelection_printer =
R"doc(Print function, needs __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__ macro
See also: classhelper/objectprinter.hpp

Args:
    float_precision: Precision of floating point numbers

Returns:
    classhelper::ObjectPrinter)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_pingtools_BeamSelection_to_stream =
R"doc(Write a BeamSelection to a binary stream

Args:
    os: output stream)doc";


#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


