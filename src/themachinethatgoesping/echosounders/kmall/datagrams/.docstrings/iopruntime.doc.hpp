//sourcehash: de6442df41e4bb9ff57f6e8850cb4bf56fdcea9a3ccc2875650b337d1aff60ea

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


static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_IOpRuntime = R"doc(Clock datagrams)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_IOpRuntime_IOpRuntime = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_IOpRuntime_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_IOpRuntime_bytes_content = R"doc(< bytes of the datagram body)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_IOpRuntime_bytes_datagram_check =
R"doc(< Each datagram ends with the size of the datagram for < integrity
check)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_IOpRuntime_decode_runtime_txt =
R"doc(Decode a runtime_txt string into a key-value map (static version)

Parameter ``runtime_txt``:
    The runtime parameter text to decode

Returns:
    std::map<std::string, std::string> Map of parameter names to
    values)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_IOpRuntime_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_IOpRuntime_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_IOpRuntime_from_stream_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_IOpRuntime_get_bytes_content = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_IOpRuntime_get_bytes_datagram_check = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_IOpRuntime_get_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_IOpRuntime_get_runtime_txt = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_IOpRuntime_get_runtime_txt_decoded =
R"doc(Decode the runtime_txt string into a key-value map

This function parses the KMALL operator runtime parameter text format.
The format contains newline-separated sections with key: value pairs.

Returns:
    std::map<std::string, std::string> Map of parameter names to
    values)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_IOpRuntime_get_runtime_txt_key_info =
R"doc(Get human-readable explanation for a runtime_txt key

Parameter ``key``:
    The key to look up

Returns:
    std::string Human-readable explanation, or "Unknown key" if not
    found)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_IOpRuntime_get_runtime_txt_key_infos =
R"doc(Get all known runtime_txt key explanations

Returns:
    const std::map<std::string, std::string>& Map of keys to their
    explanations)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_IOpRuntime_get_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_IOpRuntime_hash_content_only =
R"doc(Hash the content of the IOpRuntime datagram (excluding header
timestamp)

Returns:
    xxh::hash_t<64> 64-bit hash value)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_IOpRuntime_info = R"doc(< Information. For future use.)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_IOpRuntime_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_IOpRuntime_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_IOpRuntime_runtime_txt = R"doc(< Runtime parameters as text format.)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_IOpRuntime_set_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_IOpRuntime_set_runtime_txt = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_IOpRuntime_set_status = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_IOpRuntime_status = R"doc(< Status. For future use.)doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_IOpRuntime_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kmall_datagrams_hash_value =
R"doc(Provide a boost hash function for IOpRuntime - Note: this is needed to
use IOpRuntime as boost::flyweight - IMPORTANT: this hash function
only uses the content of the IOpRuntime for hashing (not information
from header e.g. timestamp, etc.)

Parameter ``data``:
    $Returns:

std::size_t)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


