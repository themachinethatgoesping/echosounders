//sourcehash: 2f7ef35872947db5322d996bbd4f4f8087a62dcfb4fbedfe972bb6268c6d1911

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


static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_SampleAmplitudesStructure =
R"doc(A structure to store the sample amplitudes of multiple beams in a
single array. Each beam may have a different number of samples. One of
the main reasons behind this structure is read/write performance and
the possibility to use xsimd on the data (stored as xtensor).

Template Args:
    t_sample:)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_SampleAmplitudesStructure_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_SampleAmplitudesStructure_SampleAmplitudesStructure = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_SampleAmplitudesStructure_SampleAmplitudesStructure_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_SampleAmplitudesStructure_db_step_size = R"doc(db step size associated with this structure (typically 0.1 dB))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_SampleAmplitudesStructure_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_SampleAmplitudesStructure_get_beam =
R"doc(return a view of the sample amplitudes of a single beam

Args:
    beam_index: 

Returns:
    xt::xtensor<t_sample, 1>)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_SampleAmplitudesStructure_get_beam_in_db =
R"doc(return a xtensor of the sample amplitudes of a single beam converted
to db

Args:
    mp_cores: number of cores to use for parallelization (default 1)
    beam_index: 

Returns:
    xt::xtensor<float, 1>)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_SampleAmplitudesStructure_get_db_step_size = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_SampleAmplitudesStructure_get_sample_amplitudes = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_SampleAmplitudesStructure_get_sample_amplitudes_in_db =
R"doc(Convert the sample amplitudes to db using _db_step_size.

Returns:
    xt::xtensor<float, 1>)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_SampleAmplitudesStructure_get_sample_amplitudes_per_beam =
R"doc(get all sample amplitude values of all beams in a single xtensor

Returns:
    xt::xtensor<float, 1>)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_SampleAmplitudesStructure_get_sample_amplitudes_per_beam_in_db =
R"doc(get all sample amplitude valuesof all beams in a single xtensor in db
Convert the sample amplitudes to db using _db_step_size.

Args:
    mp_cores: number of cores to use for parallelization (default 1)

Returns:
    xt::xtensor<float, 1>)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_SampleAmplitudesStructure_get_samples_per_beam = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_SampleAmplitudesStructure_get_start_index_per_beam = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_SampleAmplitudesStructure_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_SampleAmplitudesStructure_operator_ne = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_SampleAmplitudesStructure_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_SampleAmplitudesStructure_sample_amplitudes = R"doc(in db steps)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_SampleAmplitudesStructure_samples_per_beam = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_SampleAmplitudesStructure_set_db_step_size = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_SampleAmplitudesStructure_set_sample_amplitudes = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_SampleAmplitudesStructure_set_samples_per_beam = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_SampleAmplitudesStructure_set_start_index_per_beam = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_SampleAmplitudesStructure_size = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_SampleAmplitudesStructure_size_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_SampleAmplitudesStructure_start_index_per_beam = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_SampleAmplitudesStructure_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


