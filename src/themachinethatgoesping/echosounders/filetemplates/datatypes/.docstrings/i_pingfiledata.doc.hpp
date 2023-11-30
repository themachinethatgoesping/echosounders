//sourcehash: 12e060584565e3961ca1c8daf64d582abdd63b1af7add7860ed82fa36ef65900

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


static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingFileData =
R"doc(@class I_PingFileData Interface for raw ping data.

This class defines an interface for raw ping data. It provides methods
to access and manipulate the properties of the ping data, such as the
name, file ping counter, primary file number, file numbers, primary
file path, and file paths.

The class also includes a nested exception class, `not_implemented`,
which is thrown when a method is not implemented.

The class provides a `__printer__` function for object printing, which
can be used to print the properties of the ping data.)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingFileData_I_PingFileData =
R"doc(Constructor for I_PingFileData.

Parameter ``name``:
    The name of the ping data.)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingFileData_file_ping_counter = R"doc(< Counter of the ping in the file (starting at 0))doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingFileData_get_file_numbers =
R"doc(Get the file numbers of the contained datagrams.

Returns:
    std::vector<size_t> The file numbers.

Throws:
    not_implemented Exception if not implemented.)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingFileData_get_file_paths =
R"doc(Get the file paths.

Returns:
    std::vector<std::string> The file paths associated with the
    contained datagrams.

Throws:
    not_implemented Exception if not implemented.)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingFileData_get_file_ping_counter =
R"doc(Get the file ping counter.

Returns:
    size_t The file ping counter.)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingFileData_get_name =
R"doc(Get the name of the ping data.

Returns:
    const std::string& The name of the ping data.)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingFileData_get_primary_file_nr =
R"doc(Get the primary file number of this ping.

Returns:
    size_t The primary file number.)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingFileData_get_primary_file_path =
R"doc(Get the primary file path of this ping.

Returns:
    std::string The primary file path of this ping.

Throws:
    not_implemented Exception if not implemented.)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingFileData_name = R"doc(< Name of the ping data.)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingFileData_not_implemented =
R"doc(@struct not_implemented Exception thrown when a method is not
implemented.)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingFileData_not_implemented_not_implemented =
R"doc(Constructor for not_implemented.

Parameter ``method_name``:
    The name of the method.

Parameter ``name``:
    The name of the ping data.)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingFileData_primary_file_nr = R"doc(< File number of the primary file)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingFileData_printer =
R"doc(ObjectPrinter for I_PingFileData.

Parameter ``float_precision``:
    The float precision for printing.

Returns:
    tools::classhelper::ObjectPrinter The ObjectPrinter instance.)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingFileData_set_file_ping_counter =
R"doc(Set the file ping counter.

Parameter ``file_ping_counter``:
    The file ping counter to set.)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingFileData_set_primary_file_nr =
R"doc(Set the primary file number for this ping.

Parameter ``primary_file_nr``:
    The primary file number to set.)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


