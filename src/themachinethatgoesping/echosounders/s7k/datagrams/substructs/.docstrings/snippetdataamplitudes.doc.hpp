//sourcehash: eeb703823784ada5c6e7a60978ffa8f69d9e597f5853ce8d0e1f17648430ad7e

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


static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_SnippetDataAmplitudes =
R"doc(Intensity snippet samples of a 7028 SnippetData record (all beams).

The samples of all beams are stored as one contiguous block on disk
and are therefore read as a single bulk read into a flat array. The
sample data type is either 16- or 32-bit unsigned (flags bit 0 of the
record) and is held as a std::variant. Per-beam access, list access
and dB conversion are computed on demand from the flat array and the
per-beam offset table. If the samples were skipped while reading, the
file position is stored so they can be read lazily (read_samples).)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_SnippetDataAmplitudes_SnippetDataAmplitudes = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_SnippetDataAmplitudes_beam_offsets = R"doc(per-beam start offsets into _samples (N + 1))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_SnippetDataAmplitudes_get_beam =
R"doc(intensity samples of a single beam (as float, in the raw amplitude
scale))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_SnippetDataAmplitudes_get_beam_in_db =
R"doc(intensity samples of a single beam in relative dB (20*log10(amplitude)
+ db_offset))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_SnippetDataAmplitudes_get_beam_offsets =
R"doc(per-beam start offsets into the flat sample array (size =
number_of_beams + 1))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_SnippetDataAmplitudes_get_number_of_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_SnippetDataAmplitudes_get_sample_position =
R"doc(file position of the first sample byte (only valid if the samples were
skipped))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_SnippetDataAmplitudes_get_samples = R"doc(flat samples of all beams (16- or 32-bit, concatenated over all beams))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_SnippetDataAmplitudes_get_samples_are_32bit =
R"doc(true if the intensity samples are stored as 32-bit values (else
16-bit))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_SnippetDataAmplitudes_get_samples_are_skipped = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_SnippetDataAmplitudes_get_total_number_of_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_SnippetDataAmplitudes_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_SnippetDataAmplitudes_operator_ne = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_SnippetDataAmplitudes_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_SnippetDataAmplitudes_read_samples =
R"doc(Read the (previously skipped) samples from the stream.
Args:
    is: Input stream. Must be the same file the record was originally
        read from.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_SnippetDataAmplitudes_sample_position = R"doc(file position of the first sample byte)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_SnippetDataAmplitudes_samples = R"doc(flat samples of all beams (concatenated))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_SnippetDataAmplitudes_samples_are_32bit = R"doc(true if the samples are 32-bit)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_SnippetDataAmplitudes_set_beam_offsets = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_SnippetDataAmplitudes_set_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_SnippetDataAmplitudes_set_samples_are_32bit = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_SnippetDataAmplitudes_set_skipped =
R"doc(mark the samples as skipped and remember the file position of the
first sample byte)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_SnippetDataAmplitudes_skipped = R"doc(true if the samples were skipped)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


