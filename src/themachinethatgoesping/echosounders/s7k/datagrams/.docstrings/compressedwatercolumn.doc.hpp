//sourcehash: 2c24d9c27454f7b160344876045895a34c66c348dd361902b309ddd01701306b

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


static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn =
R"doc(7k record CompressedWaterColumnData: per-beam water-column magnitude
(and optional phase) time series in a compressed (downsampled and/or
bit-reduced) form.

The exact sample encoding (magnitude bit depth, presence of phase,
downsampling) is controlled by the flags bit field. This class decodes
the magnitude to float and the phase to radians for convenient access.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_CompressedWaterColumn = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_Content = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_Content_compressed_samples = R"doc(maximum number of samples over all beams)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_Content_compression_factor = R"doc(magnitude compression factor)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_Content_first_sample = R"doc(first sample index for each beam)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_Content_flags = R"doc(compression control flags bit field)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_Content_multi_ping = R"doc(0 = single ping, else multi-ping sequence number)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_Content_number_beams = R"doc(number of beams)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_Content_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_Content_ping_number = R"doc(sequential ping number)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_Content_reserved = R"doc(reserved)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_Content_sample_rate = R"doc(effective sample rate after downsampling (Hz))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_Content_samples = R"doc(nominal number of samples (based on range))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_Content_serial_number = R"doc(sonar serial number)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_beams = R"doc(per-beam magnitude/phase data)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_beams_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_checksum = R"doc(record checksum (last 4 bytes; see S7KDatagram, debugging only))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_content = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_from_stream_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_from_stream_3 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_checksum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_compressed_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_compression_factor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_downsampling_divisor = R"doc(Bits 4-7: downsampling divisor (1 means no downsampling).)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_downsampling_type = R"doc(Bits 8-11: downsampling type (0 none, 1 middle, 2 peak, 3 average).)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_first_sample = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_flag_32bit_data = R"doc(Bit 12: magnitude is stored as 32-bit values.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_flag_compression_factor_available =
R"doc(Bit 13: a custom compression factor is available (else a factor of 40
is used).)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_flag_first_sample_is_rxdelay = R"doc(Bit 15: the first sample contains the RxDelay value.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_flag_intensity_only = R"doc(Bit 1: only intensity (magnitude) data is included, phase is stripped.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_flag_magnitude_to_db =
R"doc(Bit 2: magnitude is converted to dB and stored as an 8-bit value
(phase as 8-bit).)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_flag_segment_numbers_available = R"doc(Bit 14: per-beam segment numbers are available.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_flag_use_maximum_bottom_detection =
R"doc(Bit 0: water column data is limited to the bottom detection point
(+10%).)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_flags = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_has_phase = R"doc(whether the record contains phase data (derived from bit 1))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_magnitude_bytes = R"doc(number of bytes per magnitude sample as stored on disk (1, 2 or 4))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_magnitude_is_db =
R"doc(whether the magnitude is stored as 8-bit dB values (derived from bit
2))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_multi_ping = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_number_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_ping_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_sample_rate = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_get_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_read = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_read_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_read_samples =
R"doc(Read the (previously skipped) per-beam samples from the stream.
Args:
    is: Input stream. Must be the same file the record was originally
        read from.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_set_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_set_checksum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_set_compressed_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_set_compression_factor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_set_first_sample = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_set_flags = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_set_multi_ping = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_set_number_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_set_ping_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_set_sample_rate = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_set_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_set_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_CompressedWaterColumn_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


