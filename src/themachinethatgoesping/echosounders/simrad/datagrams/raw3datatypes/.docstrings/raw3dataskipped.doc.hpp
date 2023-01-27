//sourcehash: f8f3d60d6d96f92b7b7cd1b05de7f13decfd5532cd23621e8bdc6312c9218ad3

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


static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_raw3datatypes_RAW3DataSkipped =
R"doc(This class represents a pseudo data type that is used to skip the raw3
data in the stream. It is used to load the RAW3 datagram info without
the samples.)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_raw3datatypes_RAW3DataSkipped_RAW3DataSkipped = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_raw3datatypes_RAW3DataSkipped_from_stream =
R"doc(This function returns an empty RawDataSkipped object, but skips the
data in the stream according to the given parameters (they must be
known in advance)

Parameter ``is``:
    input stream

Parameter ``count``:
    number of elements

Parameter ``data_type``:
    data type

Parameter ``number_of_complex_samples``:
    number of complex samples

Returns:
    RAW3DataSkipped)doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_raw3datatypes_RAW3DataSkipped_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_raw3datatypes_RAW3DataSkipped_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_raw3datatypes_RAW3DataSkipped_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_simrad_datagrams_raw3datatypes_RAW3DataSkipped_to_stream =
R"doc(This function writes zeros to the stream according to the given
parameters (they must be known in advance)

Parameter ``os``:
    output stream

Parameter ``count``:
    number of elements

Parameter ``data_type``:
    data type

Parameter ``number_of_complex_samples``:
    number of complex samples)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


