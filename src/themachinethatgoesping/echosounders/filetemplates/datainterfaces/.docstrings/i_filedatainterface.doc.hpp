//sourcehash: 415ca8b6cbe0d43b33cec919acf85ce2bbcca547ec393917be70a43703fb64c2

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


static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_I_FileDataInterface = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_add_datagram_info = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_add_file_information = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_add_file_interface = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_class_name = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_deinitialize = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_init_from_file = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_init_from_file_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_interface_per_file = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_is_initialized = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_name = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_per_file =
R"doc(get a vector with references to the per file interfaces This is useful
for iterating over all files

Returns:
    std::vector<t_filedatainterface_perfile&>)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_per_file_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_per_file_const = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_per_file_ptr = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_per_primary_file =
R"doc(get a vector with references to the primary per file interfaces This
is useful for iterating over all primary files Secondary files will be
ignored (e.g. .wcd for Kongsberg data if .all is present)

Returns:
    std::vector<t_filedatainterface_perfile&>)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_per_secondary_file =
R"doc(get a vector with references to the secondary per file interfaces This
is useful for iterating over all secondary files Primary files will be
ignored (e.g. .all for Kongsberg data if .wcd is present)

Returns:
    std::vector<t_filedatainterface_perfile&>)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_pyindexer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_sort_by_time = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterface_verify_linked_file_interfaces_are_consistent = R"doc(This functions throws if linked file interfaces are not consistent)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


