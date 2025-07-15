//sourcehash: 8e10056024176900cbd497e36bf09fdd0a6b5e43ca0235e5e565c738d9c49f4c

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


static const char *__doc_themachinethatgoesping_echosounders_pingtools_ReadSampleRange = R"doc(A class to hold range of samples for a single beam)doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_ReadSampleRange_ReadSampleRange = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_ReadSampleRange_ReadSampleRange_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_ReadSampleRange_first_read_sample_offset = R"doc(< offset of the first read sample (compared to global < sample number))doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_ReadSampleRange_first_sample_to_read = R"doc(< first sample number to read (local to beam sample offset))doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_ReadSampleRange_from_stream =
R"doc(Return a ReadSampleRange read from a binary stream

Parameter ``is``:
    input stream

Returns:
    ReadSampleRange)doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_ReadSampleRange_get_first_read_sample_offset = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_ReadSampleRange_get_first_sample_to_read =
R"doc(Return the first sample number to read (local to beam sample offset)

Returns:
    uint32_t)doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_ReadSampleRange_get_last_read_sample_offset = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_ReadSampleRange_get_number_of_samples_to_read = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_ReadSampleRange_last_read_sample_offset = R"doc(< offset of the last read sample (compared to global)doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_ReadSampleRange_number_of_samples_to_read = R"doc(< number of samples to read (local to beam sample offset))doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_ReadSampleRange_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_ReadSampleRange_printer =
R"doc(Print function, needs __CLASSHELPER_DEFAULT_PRINTING_FUNCTIONS__ macro
See also: classhelper/objectprinter.hpp

Parameter ``float_precision``:
    Precision of floating point numbers

Returns:
    classhelper::ObjectPrinter)doc";

static const char *__doc_themachinethatgoesping_echosounders_pingtools_ReadSampleRange_to_stream =
R"doc(Write a ReadSampleRange to a binary stream

Parameter ``os``:
    output stream)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


