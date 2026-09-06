//sourcehash: ce1a4bea069ed4fa4491e45138565669c5e8c5e97ecf75c47fe7b01a35d963be

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


static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_S7KFileHandler =
R"doc(File handler for Teledyne RESON .s7k (7k) data files.

Indexes all datagrams (Data Record Frames) in the given file(s), sorts
them into the specialized file-data interfaces (configuration,
navigation, environment, ping, other) and provides access to the raw
datagrams via the datagram_interface().



$.. note::

The specialized interfaces are structurally present and the datagrams
are already sorted into them, but their read_* processing functions
are not implemented yet. Initializing them (and therefore get_pings())
is deferred to a later step.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_S7KFileHandler_S7KFileHandler = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_S7KFileHandler_S7KFileHandler_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_S7KFileHandler_S7KFileHandler_3 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_S7KFileHandler_S7KFileHandler_4 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_S7KFileHandler_callback_scan_new_file_begin = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_S7KFileHandler_callback_scan_new_file_end = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_S7KFileHandler_callback_scan_packet = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_S7KFileHandler_configuration_interface = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_S7KFileHandler_configuration_interface_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_S7KFileHandler_datagramdata_interface = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_S7KFileHandler_datagramdata_interface_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_S7KFileHandler_environment_interface = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_S7KFileHandler_environment_interface_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_S7KFileHandler_get_channel_ids = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_S7KFileHandler_get_pings = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_S7KFileHandler_init_interfaces = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_S7KFileHandler_navigation_interface = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_S7KFileHandler_navigation_interface_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_S7KFileHandler_otherfiledata_interface = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_S7KFileHandler_otherfiledata_interface_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_S7KFileHandler_ping_interface = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_S7KFileHandler_ping_interface_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_S7KFileHandler_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_S7KFileHandler_setup_interfaces = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


