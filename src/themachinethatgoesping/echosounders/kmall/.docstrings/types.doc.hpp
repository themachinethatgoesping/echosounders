//sourcehash: df0db23226db61fb6bd2f6d1514b96b8f6704a36823f029b9e4ebf972707452c

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


static const char *__doc__unnamed_class_at_themachinethatgoesping_echosounders_kmall_types_hpp_192_67 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_datagram_identifier_info =
R"doc(Get descriptive information about a datagram type.

Parameter ``datagram_type``:
    Datagram identifier.

Returns:
    Human-readable description.)doc";


static const char *__doc_themachinethatgoesping_echosounders_datagram_identifiers_to_string =
R"doc(Convert vector of datagram identifiers to vector of strings.

Parameter ``values``:
    Vector of identifiers.

Returns:
    Vector of decimal string representations.)doc";

static const char *__doc_themachinethatgoesping_echosounders_datagram_identifiers_to_string_2 =
R"doc(Convert set of datagram identifiers to vector of strings.

Parameter ``values``:
    Set of identifiers.

Returns:
    Vector of decimal string representations (in set iteration order).)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_KMALLDatagram_type_from_string =
R"doc(Parse datagram type from string representation.

Parameter ``value``:
    String view containing decimal representation.

Returns:
    Parsed datagram type numeric value.)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_c_DGM2Int = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagram_type_to_string =
R"doc(Convert datagram type from uint32_t to string representation.

Parameter ``value``:
    Datagram type as uint32_t.

Returns:
    String representation (decimal) of the datagram type.)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagram_type_to_string_2 =
R"doc(Convert datagram type identifier to string representation.

Parameter ``value``:
    Datagram type identifier enum.

Returns:
    String representation (decimal) of the datagram type.)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_C_HEAVE = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_C_POSITION = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_F_CALIBRATION_FILE = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_I_INSTALLATION_PARAM = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_I_OP_RUNTIME = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_M_RANGE_AND_DEPTH = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_M_WATER_COLUMN = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_S_CLOCK = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_S_DEPTH = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_S_HEIGHT = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_S_KM_BINARY = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_S_POSITION = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_S_POSITION_DATUM = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_S_POSITION_ERROR = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_S_SOUND_VELOCITY_PROFILE = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_S_SOUND_VELOCITY_TRANSDUCER = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_unspecified = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


