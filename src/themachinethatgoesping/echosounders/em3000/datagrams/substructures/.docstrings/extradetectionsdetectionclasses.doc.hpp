//sourcehash: 2218ca47a16315c2cb97c79a45504c9adf127f9454bcf69929bd701c8a946ee4

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


static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses = R"doc(Extra Detections Detection Classes)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_ExtraDetectionsDetectionClasses = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_alarm_flag_1 =
R"doc(< 0: (no alarm) 1:Number of extra detections are above Alarm
threshold.)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_alarm_threshold = R"doc(< number of extra det. required (1-99 0=off))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_bs_threshold = R"doc(< dB (-10 - 60))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_get_alarm_flag_1 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_get_alarm_threshold = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_get_bs_threshold = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_get_number_of_extra_detections = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_get_qf_threshold =
R"doc(Get the ifremer QF threshold The Ifremer Quality factor is used to
estimate the relative depth error. QF threshold equal to 0.1 means a
0.1% depth error threshold. At 100 m depth this the depth error
threshold would be 10 cm. Valid range is 0.01 to 1 %.

Returns:
    qf_threshold_100 * 0.01 (double))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_get_qf_threshold_100 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_get_show_class = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_get_snr_threshold = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_get_start_depth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_get_stop_depth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_number_of_extra_detections = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_operator_ne = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_qf_threshold_100 = R"doc(< 100 * QF threshold (1-100))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_set_alarm_flag_1 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_set_alarm_threshold = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_set_bs_threshold = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_set_number_of_extra_detections = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_set_qf_threshold_100 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_set_show_class = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_set_snr_threshold = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_set_start_depth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_set_stop_depth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_show_class = R"doc(< 0-1)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_snr_threshold = R"doc(< 5-15)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_start_depth = R"doc(< % of depth (0-300))doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagrams_substructures_ExtraDetectionsDetectionClasses_stop_depth = R"doc(< % of depth (1-300))doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


