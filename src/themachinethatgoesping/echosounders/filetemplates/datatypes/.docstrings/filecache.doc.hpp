//sourcehash: 32e2c93040eeca413c46eed31f41d5f09800e113a0bfdd43efad7426d320d433

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


static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_FileCache = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_FileCache_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_add_to_cache = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_cache_buffer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_cache_buffer_header = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_file_name = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_file_size = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_from_file =
R"doc(Create a FileCache from a file

Parameter ``index_path``:
    Path to the cache file to read

Returns:
    FileCache object created from the file)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_from_stream =
R"doc(Create a FileCache from a stream

Parameter ``is``:
    Input stream to read from

Returns:
    FileCache object created from the stream)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_get_cache_buffer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_get_cache_buffer_header = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_get_cache_names = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_get_file_name = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_get_file_size = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_get_from_cache = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_get_from_cache_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_get_loaded_cache_names = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_get_not_loaded_cache_names = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_has_cache =
R"doc(Check if a cache entry with the given name exists

Parameter ``name``:
    Name of the cache entry to check

Returns:
    true if the cache entry exists)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_path_is_valid =
R"doc(Check if the index path contains a valid cache file

Parameter ``index_path``:
    Path to the index file to validate

Returns:
    true if the path contains a valid cache file matching this
    FileCache)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_printer =
R"doc(Create ObjectPrinter for this FileCache

Parameter ``float_precision``:
    Precision for floating point values

Parameter ``superscript_exponents``:
    Whether to use superscript for exponents

Returns:
    ObjectPrinter configured for this FileCache)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_read_cache_buffer_from_stream =
R"doc(Read cache buffer from stream

Parameter ``is``:
    Input stream to read from)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_read_cache_buffer_from_stream_2 =
R"doc(Read cache buffer from stream for specific cache keys

Parameter ``is``:
    Input stream to read from

Parameter ``cache_keys``:
    Vector of cache keys to load)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_read_check_type_id =
R"doc(Read and verify type ID from stream

Parameter ``is``:
    Input stream to read from)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_read_check_type_version =
R"doc(Read and verify type version from stream

Parameter ``is``:
    Input stream to read from

Returns:
    true if version is correct)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_remove_from_cache =
R"doc(Remove a cache entry and all entries added after it

Parameter ``name``:
    Name of the cache entry to remove)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_to_stream =
R"doc(Write the FileCache to a stream

Parameter ``os``:
    Output stream to write to)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_update_file =
R"doc(Update or create the cache file at the specified path

Parameter ``index_path``:
    Path where to write the cache file

Parameter ``emulate_only``:
    If true, only simulate the update without actually writing)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_write_type_id =
R"doc(Write type ID to stream

Parameter ``os``:
    Output stream to write to)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_write_type_version =
R"doc(Write type version to stream

Parameter ``os``:
    Output stream to write to)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


