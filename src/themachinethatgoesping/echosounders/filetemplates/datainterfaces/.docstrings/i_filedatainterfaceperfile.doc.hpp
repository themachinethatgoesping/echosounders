//sourcehash: 71094c35fc090a37fd020632a1247a45eec8e08003008206fb081d0af5f99476

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


static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterfacePerFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterfacePerFile_I_FileDataInterfacePerFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterfacePerFile_add_file_information = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterfacePerFile_deinitialize = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterfacePerFile_file_nr = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterfacePerFile_file_path = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterfacePerFile_get_file_name = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterfacePerFile_get_file_nr =
R"doc(Get the file nr This function assumes that the file nr is the same for
all datagrams in the file

Returns:
    size_t)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterfacePerFile_get_file_path =
R"doc(Get the file name This function assumes that the file name is the same
for_linked_file all datagrams in the file

Returns:
    std::string)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterfacePerFile_get_file_size = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterfacePerFile_get_linked_file = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterfacePerFile_get_linked_file_nr =
R"doc(Get the file nr of the linked file

Returns:
    size_t)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterfacePerFile_get_linked_file_path =
R"doc(Get the file name of the linked file

Returns:
    std::string)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterfacePerFile_has_linked_file = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterfacePerFile_ignored_extension_datagram_identifiers = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterfacePerFile_init_from_file = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterfacePerFile_is_initialized = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterfacePerFile_is_primary_file = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterfacePerFile_is_secondary_file = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterfacePerFile_link_file_interfaces = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterfacePerFile_linked_primary_file = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterfacePerFile_linked_secondary_file = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterfacePerFile_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_FileDataInterfacePerFile_used_extension_datagram_identifiers = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


