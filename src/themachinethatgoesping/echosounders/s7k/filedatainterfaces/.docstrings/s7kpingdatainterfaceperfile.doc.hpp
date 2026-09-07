//sourcehash: a5551da8f1d281fea6f9a53b70f64ff8611e7d7bc0fcc5a58ae8413da08da288

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



$.. note::

The datagram-processing function (read_pings) is not implemented yet.
The class currently only provides the structure so the pings can be
filled in in a later step.

Template Args:
    t_ifstream:)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KPingDataInterfacePerFile_S7KPingDataInterfacePerFile = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KPingDataInterfacePerFile_S7KPingDataInterfacePerFile_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KPingDataInterfacePerFile_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KPingDataInterfacePerFile_read_pings =
R"doc(Group this file's ping datagrams into pings.

This first version only assembles the per-ping datagram index
(ping.file_data) so that all datagrams belonging to a ping can be
listed via ping.file_data.datagrams(). The bottom and water-column
data are not read yet (that is a later step).

Grouping is done in file order: a new ping is started at every 7000
SonarSettings record (the record that starts a ping cycle in the 7k
format); every following ping datagram is added to the current ping.
Datagrams that appear before the first SonarSettings record are
collected into a leading ping so no datagram is lost.



$.. note::

This simple file-order grouping assumes each ping starts with a
SonarSettings record. Multi-head / multi-ping files (interleaved
SonarSettings) and files without SonarSettings are not handled
precisely yet and can be refined later (e.g. by grouping on the record
ping_number).)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


