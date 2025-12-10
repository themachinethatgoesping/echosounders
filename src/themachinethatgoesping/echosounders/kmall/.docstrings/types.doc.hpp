//sourcehash: 28825bb6987418f93e6c676469a74ec545a09cdb237800773f1c384c01fe76c0

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


static const char *mkd_doc__unnamed_class_at_themachinethatgoesping_echosounders_kmall_types_hpp_211_67 = R"doc()doc";





static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_KMALLDatagram_type_from_string =
R"doc(Parse datagram type from string representation.
Args:
    value: String view containing decimal representation.

Returns:
    Parsed datagram type numeric value.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_c_chars2Int = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagram_type_to_string =
R"doc(Convert datagram type from uint32_t to string representation.
Args:
    value: Datagram type as uint32_t.

Returns:
    String representation (decimal) of the datagram type.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_datagram_type_to_string_2 =
R"doc(Convert datagram type identifier to string representation.
Args:
    value: Datagram type identifier enum.

Returns:
    String representation (decimal) of the datagram type.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_C_HEAVE = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_C_POSITION = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_F_CALIBRATION_FILE = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_I_INSTALLATION_PARAM = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_I_OP_RUNTIME = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_KM_BINARY = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_M_RANGE_AND_DEPTH = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_M_WATER_COLUMN = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_S_CLOCK = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_S_DEPTH = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_S_HEIGHT = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_S_KM_BINARY = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_S_POSITION = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_S_POSITION_DATUM = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_S_POSITION_ERROR = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_S_SOUND_VELOCITY_PROFILE = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_S_SOUND_VELOCITY_TRANSDUCER = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_t_KMALLDatagramIdentifier_unspecified = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


