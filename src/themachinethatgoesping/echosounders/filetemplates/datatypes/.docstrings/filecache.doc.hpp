//sourcehash: 32e2c93040eeca413c46eed31f41d5f09800e113a0bfdd43efad7426d320d433

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


static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_FileCache = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_FileCache_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_add_to_cache = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_cache_buffer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_cache_buffer_header = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_file_name = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_file_size = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_from_file =
R"doc(Create a FileCache from a file

Args:
    index_path: Path to the cache file to read

Returns:
    FileCache object created from the file)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_from_stream =
R"doc(Create a FileCache from a stream

Args:
    is: Input stream to read from

Returns:
    FileCache object created from the stream)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_get_cache_buffer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_get_cache_buffer_header = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_get_cache_names = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_get_file_name = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_get_file_size = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_get_from_cache = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_get_from_cache_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_get_loaded_cache_names = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_get_not_loaded_cache_names = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_has_cache =
R"doc(Check if a cache entry with the given name exists

Args:
    name: Name of the cache entry to check

Returns:
    true if the cache entry exists)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_path_is_valid =
R"doc(Check if the index path contains a valid cache file

Args:
    index_path: Path to the index file to validate

Returns:
    true if the path contains a valid cache file matching this
    FileCache)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_printer =
R"doc(Create ObjectPrinter for this FileCache

Args:
    float_precision: Precision for floating point values
    superscript_exponents: Whether to use superscript for exponents

Returns:
    ObjectPrinter configured for this FileCache)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_read_cache_buffer_from_stream =
R"doc(Read cache buffer from stream

Args:
    is: Input stream to read from)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_read_cache_buffer_from_stream_2 =
R"doc(Read cache buffer from stream for specific cache keys

Args:
    is: Input stream to read from
    cache_keys: Vector of cache keys to load)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_read_check_type_id =
R"doc(Read and verify type ID from stream

Args:
    is: Input stream to read from)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_read_check_type_version =
R"doc(Read and verify type version from stream

Args:
    is: Input stream to read from

Returns:
    true if version is correct)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_remove_from_cache =
R"doc(Remove a cache entry and all entries added after it

Args:
    name: Name of the cache entry to remove)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_to_stream =
R"doc(Write the FileCache to a stream

Args:
    os: Output stream to write to)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_update_file =
R"doc(Update or create the cache file at the specified path

Args:
    index_path: Path where to write the cache file
    emulate_only: If true, only simulate the update without actually
                  writing)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_write_type_id =
R"doc(Write type ID to stream

Args:
    os: Output stream to write to)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_FileCache_write_type_version =
R"doc(Write type version to stream

Args:
    os: Output stream to write to)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


