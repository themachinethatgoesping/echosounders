//sourcehash: c79810e31505548cdb9a0be4e3cfc5c85ff582e7e35d04c1601ecf325b1379a1

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


static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KPingDataInterfacePerFile =
R"doc(Interface that reads the pings (bathymetry, water column) of a single
.s7k file.

Grouping is done in file order: a new ping is started at every 7000
SonarSettings record (the record that starts a ping cycle in the 7k
format); every following ping datagram is added to the current ping.
For every ping the lightweight per-ping information is built early
(and persisted into the index cache): the water-column information
(per-beam sample positions, NOT the samples), the bottom-detection
information and the system information. The water-column samples
themselves are read on demand per beam and never held in memory.

Template Args:
    t_ifstream:)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KPingDataInterfacePerFile_S7KPingCacheHandler =
R"doc(Reads / writes the per-ping water-column, detection and system
information from / to the index cache, mirroring the KMALL ping cache
handler. If no index cache is available the information is simply
(re)read from the file.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KPingDataInterfacePerFile_S7KPingCacheHandler_S7KPingCacheHandler = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KPingDataInterfacePerFile_S7KPingCacheHandler_S7KPingCacheHandler_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KPingDataInterfacePerFile_S7KPingCacheHandler_buffer_detectioninformation = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KPingDataInterfacePerFile_S7KPingCacheHandler_buffer_systeminformation = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KPingDataInterfacePerFile_S7KPingCacheHandler_buffer_watercolumninformation = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KPingDataInterfacePerFile_S7KPingCacheHandler_file_cache = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KPingDataInterfacePerFile_S7KPingCacheHandler_index_path = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KPingDataInterfacePerFile_S7KPingCacheHandler_read_or_get_detectioninformation = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KPingDataInterfacePerFile_S7KPingCacheHandler_read_or_get_systeminformation = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KPingDataInterfacePerFile_S7KPingCacheHandler_read_or_get_watercolumninformation = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KPingDataInterfacePerFile_S7KPingCacheHandler_update_index = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KPingDataInterfacePerFile_S7KPingCacheHandler_update_index_file = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KPingDataInterfacePerFile_S7KPingDataInterfacePerFile = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KPingDataInterfacePerFile_S7KPingDataInterfacePerFile_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KPingDataInterfacePerFile_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KPingDataInterfacePerFile_read_pings = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


