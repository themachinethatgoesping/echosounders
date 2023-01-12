//sourcehash: 9515cb25ab86505d1dadbacb4badda5c1c34fb496e124526ee93ae92ab2d163c

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


static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_SampleAmplitudesStructure =
R"doc(A structure to store the sample amplitudes of multiple beams in a
single array. Each beam may have a different number of samples. One of
the main reasons behind this structure is read/write performance and
the possibility to use xsimd on the data (stored as xtensor).

Template parameter ``t_sample``:)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_SampleAmplitudesStructure_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_SampleAmplitudesStructure_SampleAmplitudesStructure = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_SampleAmplitudesStructure_SampleAmplitudesStructure_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_SampleAmplitudesStructure_db_step_size = R"doc(< db step size associated with this structure (typically 0.1 dB))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_SampleAmplitudesStructure_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_SampleAmplitudesStructure_get_beam =
R"doc(return a view of the sample amplitudes of a single beam

Parameter ``beam_index``:
    $Returns:

xt::xtensor<t_sample, 1>)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_SampleAmplitudesStructure_get_beam_in_db =
R"doc(return a xtensor of the sample amplitudes of a single beam converted
to db

Parameter ``beam_index``:
    $Returns:

xt::xtensor<float, 1>)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_SampleAmplitudesStructure_get_db_step_size = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_SampleAmplitudesStructure_get_sample_amplitudes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_SampleAmplitudesStructure_get_sample_amplitudes_in_db =
R"doc(Convert the sample amplitudes to db using _db_step_size.

Returns:
    xt::xtensor<float, 1>)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_SampleAmplitudesStructure_get_samples_per_beam = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_SampleAmplitudesStructure_get_start_index_per_beam = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_SampleAmplitudesStructure_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_SampleAmplitudesStructure_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_SampleAmplitudesStructure_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_SampleAmplitudesStructure_sample_amplitudes = R"doc(< in db steps)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_SampleAmplitudesStructure_samples_per_beam = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_SampleAmplitudesStructure_set_db_step_size = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_SampleAmplitudesStructure_set_sample_amplitudes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_SampleAmplitudesStructure_set_samples_per_beam = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_SampleAmplitudesStructure_set_start_index_per_beam = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_SampleAmplitudesStructure_size = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_SampleAmplitudesStructure_size_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_SampleAmplitudesStructure_start_index_per_beam = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_SampleAmplitudesStructure_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


