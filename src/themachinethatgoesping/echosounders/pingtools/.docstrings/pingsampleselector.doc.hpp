//sourcehash: 2e0d4fadfef474f377afab41fe86b2a52be0c2bb014db848ba1118205311d36d

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


static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_PingSampleSelector = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_apply_selection = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_beam_step = R"doc(< step size for beam numbers)doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_clear = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_clear_beam_angle_range = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_clear_beam_number_range = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_clear_beam_step = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_clear_sample_number_range = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_clear_sample_range_range = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_clear_sample_step = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_from_stream =
R"doc(Return a PingSampleSelector read from a binary stream

Parameter ``is``:
    input stream

Returns:
    PingSampleSelector)doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_get_beam_step = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_get_max_beam_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_get_max_beam_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_get_max_sample_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_get_max_sample_range = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_get_min_beam_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_get_min_beam_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_get_min_sample_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_get_min_sample_range = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_get_sample_step = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_max_beam_angle = R"doc(< max beam angle to select (°))doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_max_beam_number = R"doc(< max beam number to select)doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_max_sample_number = R"doc(< max sample number to select)doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_max_sample_range = R"doc(< max sample range to select (m))doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_min_beam_angle = R"doc(< min beam angle to select (°))doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_min_beam_number = R"doc(< min beam number to select)doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_min_sample_number = R"doc(< min sample number to select)doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_min_sample_range = R"doc(< min sample range to select (m))doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_printer =
R"doc(Print function, needs __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__ macro
See also: classhelper/objectprinter.hpp

Parameter ``float_precision``:
    Precision of floating point numbers

Returns:
    classhelper::ObjectPrinter)doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_sample_step = R"doc(< step size for sample numbers)doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_select_beam_range_by_angles = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_select_beam_range_by_numbers = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_select_sample_range_by_numbers = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_select_sample_range_by_ranges = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_set_beam_step = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_set_sample_step = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_PingSampleSelector_to_stream =
R"doc(Write a PingSampleSelector to a binary stream

Parameter ``os``:
    output stream)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


