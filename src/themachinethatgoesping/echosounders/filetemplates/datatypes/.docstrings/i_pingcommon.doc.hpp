//sourcehash: f0cc608e040edd21cd97fcddac012db9d86230804ba977e05e09837a18c232dd

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


static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_I_PingCommon = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_I_PingCommon_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_check_feature = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_class_name = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_feature_string =
R"doc(Get a string of all registered features that are available or not
available

Parameter ``available``:
    if True (default) return available features, else return not
    available features

Returns:
    std::string)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_get_number_of_tx_sectors =
R"doc(Get the number of transmission sectors.

This function returns the number of transmission sectors for the
echosounder.

Returns:
    The number of transmission sectors.)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_get_sample_interval =
R"doc(Get the sample interval in seconds

Returns:
    float)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_get_tx_signal_parameters =
R"doc(Get the transmission signal parameters per sector.

Returns:
    const std::vector<algorithms::signalprocessing::datastructures::Tx
    SignalParameters>&)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_has_all_of_features =
R"doc(Check if all of the specified features are available

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_has_any_of_features =
R"doc(Check if any of the specified features is available

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_has_feature =
R"doc(Check if any of the registered features is available

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_has_features =
R"doc(Check if any of the registered features is available

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_has_main_features =
R"doc(Check if any of the registered main features is available

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_has_tx_sector_information = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_has_tx_signal_parameters = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_load = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_loaded = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_main_features =
R"doc(Get a string of all registered main features for this ping class

Returns:
    std::string)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_not_implemented = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_not_implemented_not_implemented = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_print_features = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_register_feature =
R"doc(Register a feature

Parameter ``feature_name``:
    $Parameter ``has_feature``:)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_registered_features =
R"doc(Get a string of all registered features for this ping class

Returns:
    std::string)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_release = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


