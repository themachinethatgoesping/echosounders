//sourcehash: fa233a5df40029301003943aa1967c96be11ddf84275781635d8442e9ff344cc

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


static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData =
R"doc(7k record SnippetData (7028): water-column intensity snippets around
each beam detection.

The record holds, per beam, a short intensity time series (snippet)
around the bottom detection. The per-beam descriptors are stored in a
SnippetDataBeamContainer (read as one bulk block), the intensity
samples in a SnippetDataAmplitudes container (16- or 32-bit depending
on bit 0 of the flags field, read as one bulk block). Array/dB
conversions are computed on demand.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_Content = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_Content_control_flags = R"doc(snippet window control flags)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_Content_error_flag = R"doc(0 = ok, 6 = bottom detection failed, else error)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_Content_flags = R"doc(flags bit field (bit 0: 0 = 16-bit, 1 = 32-bit snippets))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_Content_multi_ping = R"doc(0 = single ping, else multi-ping sequence number)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_Content_number_beams = R"doc(number of detection points (beams))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_Content_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_Content_ping_number = R"doc(sequential ping number)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_Content_reserved = R"doc(reserved)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_Content_serial_number = R"doc(sonar serial number)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_SnippetData = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_amplitudes = R"doc(per-beam intensity samples)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_amplitudes_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_beams = R"doc(per-beam snippet descriptors)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_beams_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_content = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_from_stream_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_from_stream_3 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_get_amplitudes = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_get_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_get_control_flags = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_get_error_flag = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_get_flags = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_get_multi_ping = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_get_number_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_get_ping_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_get_samples_are_32bit =
R"doc(true if the intensity samples are stored as 32-bit values (flags bit
0))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_get_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_set_amplitudes = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_set_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_set_control_flags = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_set_error_flag = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_set_flags = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_set_multi_ping = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_set_number_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_set_ping_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_set_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_SnippetData_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


