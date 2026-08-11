//sourcehash: a9ec18b7ab18d7ead3bcf5fd7dc3caebfda6c0cee820b052f4244ad56be7c632

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


static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterfacePerFile = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterfacePerFile_I_PingDataInterfacePerFile = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterfacePerFile_I_PingDataInterfacePerFile_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterfacePerFile_configuration_data_interface = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterfacePerFile_configuration_data_interface_const = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterfacePerFile_configuration_data_interface_for_file = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterfacePerFile_configuration_data_interface_for_file_const = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterfacePerFile_environment_data_interface = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterfacePerFile_environment_data_interface_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterfacePerFile_environment_data_interface_const = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterfacePerFile_init_file_interface_data =
R"doc(Hook called on the owning thread for each primary file before any
parallel ping-reading workers are launched.

Derived classes may override this to eagerly load per-file data (e.g.
runtime parameters, sound-speed profiles) on the owning thread,
ensuring that their initialization is sequential and therefore avoids
concurrent file I/O or concurrent flyweight-factory access.

The default implementation is a no-op.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterfacePerFile_init_from_file = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterfacePerFile_navigation_data_interface = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterfacePerFile_navigation_data_interface_Const = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterfacePerFile_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_PingDataInterfacePerFile_read_pings = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


