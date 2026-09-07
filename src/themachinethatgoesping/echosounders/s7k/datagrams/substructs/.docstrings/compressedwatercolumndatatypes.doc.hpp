//sourcehash: 49c4ec2d4dcf0d68b89af1ad9032a8a3d7bcc841e643a5d9a8622e42b4c57756

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


static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude16 = R"doc(B) 16 bit magnitude, no phase (16 bits total).)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude16Phase16 =
R"doc(A) 16 bit magnitude + 16 bit phase (32 bits total).

The interleaved [magnitude, phase] samples are stored as a [n, 2]
unsigned tensor exactly as on disk; magnitude is column 0, the phase
bits are column 1 (reinterpreted as int16 on access).)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude16Phase16_CompressedWaterColumnDataMagnitude16Phase16 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude16Phase16_CompressedWaterColumnDataMagnitude16Phase16_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude16Phase16_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude16Phase16_get_number_of_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude16Phase16_get_raw_magnitude = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude16Phase16_get_raw_phase = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude16Phase16_has_magnitude = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude16Phase16_has_phase = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude16Phase16_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude16Phase16_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude16Phase16_samples = R"doc([n, 2] interleaved magnitude (col 0) and phase (col 1))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude16Phase16_to_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude16_CompressedWaterColumnDataMagnitude16 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude16_CompressedWaterColumnDataMagnitude16_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude16_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude16_get_number_of_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude16_get_raw_magnitude = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude16_has_magnitude = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude16_magnitude = R"doc([n] magnitude samples)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude16_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude16_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude16_to_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude32 =
R"doc(F) 32 bit magnitude, no phase (32 bits total). The 32 bit magnitude is
an unsigned integer (DWORD, see Appendix I), not an IEEE float.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude32Phase8 =
R"doc(E) 32 bit magnitude + 8 bit phase (40 bits total).

Magnitude (uint32) and phase (int8) have different sizes, so they are
de-interleaved into two separate native tensors at read time (the only
encoding that is not stored as a single tensor).)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude32Phase8_CompressedWaterColumnDataMagnitude32Phase8 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude32Phase8_CompressedWaterColumnDataMagnitude32Phase8_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude32Phase8_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude32Phase8_get_number_of_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude32Phase8_get_raw_magnitude = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude32Phase8_get_raw_phase = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude32Phase8_has_magnitude = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude32Phase8_has_phase = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude32Phase8_magnitude = R"doc([n] magnitude samples (32 bit unsigned))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude32Phase8_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude32Phase8_phase = R"doc([n] phase samples (8 bit, high byte of int16 phase))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude32Phase8_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude32Phase8_to_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude32_CompressedWaterColumnDataMagnitude32 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude32_CompressedWaterColumnDataMagnitude32_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude32_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude32_get_number_of_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude32_get_raw_magnitude = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude32_has_magnitude = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude32_magnitude = R"doc([n] magnitude samples (32 bit unsigned))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude32_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude32_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude32_to_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude8 = R"doc(D) 8 bit (dB) magnitude, no phase (8 bits total).)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude8Phase8 =
R"doc(C) 8 bit (dB) magnitude + 8 bit phase (16 bits total).

Stored as a [n, 2] unsigned tensor (magnitude col 0, phase col 1). The
8 bit phase is the high byte of the 16 bit phase, so it is widened to
int16 by shifting it back into the high byte.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude8Phase8_CompressedWaterColumnDataMagnitude8Phase8 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude8Phase8_CompressedWaterColumnDataMagnitude8Phase8_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude8Phase8_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude8Phase8_get_number_of_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude8Phase8_get_raw_magnitude = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude8Phase8_get_raw_phase = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude8Phase8_has_magnitude = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude8Phase8_has_phase = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude8Phase8_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude8Phase8_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude8Phase8_samples = R"doc([n, 2] interleaved magnitude (col 0) and phase (col 1))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude8Phase8_to_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude8_CompressedWaterColumnDataMagnitude8 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude8_CompressedWaterColumnDataMagnitude8_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude8_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude8_get_number_of_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude8_get_raw_magnitude = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude8_has_magnitude = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude8_magnitude = R"doc([n] magnitude samples (8 bit dB))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude8_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude8_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataMagnitude8_to_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataSkipped =
R"doc(The (default) state of a beam whose samples were not read (skipped for
lazy reading).)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataSkipped_CompressedWaterColumnDataSkipped = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataSkipped_get_raw_magnitude = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataSkipped_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataSkipped_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_CompressedWaterColumnDataSkipped_to_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_I_CompressedWaterColumnData =
R"doc(Interface for the per-beam sample data of a 7042
CompressedWaterColumnData record.

The concrete implementations store the samples in their native (on-
disk) integer type as xtensors (magnitude as unsigned integers, phase
as signed integers). No floating point / dB conversion is done at read
or at raw access; conversion is deferred to the ping water column
accessor (S7KPingWatercolumn) where it can run vectorized on only the
selected beams/samples.

Raw access returns the widest lossless integer type (magnitude ->
uint32, phase -> int16) so a single virtual signature can serve all
encodings. The 8 bit phase is widened to the same int16 scale as the
16 bit phase (shifted into the high byte), so phase-to-radians is
uniform (radians = raw_phase / 10430).)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_I_CompressedWaterColumnData_I_CompressedWaterColumnData = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_I_CompressedWaterColumnData_class_name = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_I_CompressedWaterColumnData_get_number_of_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_I_CompressedWaterColumnData_get_raw_magnitude = R"doc(magnitude samples in their raw (unconverted) values, widened to uint32)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_I_CompressedWaterColumnData_get_raw_phase =
R"doc(phase samples in their raw (unconverted) values, widened to the int16
phase scale (empty if there is no phase). radians = raw_phase / 10430)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_I_CompressedWaterColumnData_has_magnitude = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_I_CompressedWaterColumnData_has_phase = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_I_CompressedWaterColumnData_name = R"doc(name of the concrete type (for printing / error messages))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_compressed_water_column_data_from_stream =
R"doc(Read one beam's samples from the stream into the matching variant
alternative.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_compressed_water_column_data_type =
R"doc(Determine the per-sample encoding of a 7042 record from its flags.

Args:
    magnitude_bytes: number of magnitude bytes as stored on disk (1, 2
                     or 4)
    has_phase: whether the record contains phase data)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_t_CompressedWaterColumnDataType =
R"doc(The possible per-sample encodings of a 7042 CompressedWaterColumnData
beam (Table 84).

The encoding is record-wide (derived from the record flags); every
beam of one record uses the same encoding. Skipped is the state of a
beam whose samples were not read (yet).)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_t_CompressedWaterColumnDataType_Magnitude16 = R"doc(B) 16 bit magnitude, no phase)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_t_CompressedWaterColumnDataType_Magnitude16Phase16 = R"doc(A) 16 bit magnitude + 16 bit phase)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_t_CompressedWaterColumnDataType_Magnitude32 = R"doc(F) 32 bit magnitude, no phase)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_t_CompressedWaterColumnDataType_Magnitude32Phase8 = R"doc(E) 32 bit magnitude + 8 bit phase)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_t_CompressedWaterColumnDataType_Magnitude8 = R"doc(D) 8 bit (dB) magnitude, no phase)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_t_CompressedWaterColumnDataType_Magnitude8Phase8 = R"doc(C) 8 bit (dB) magnitude + 8 bit phase)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagrams_substructs_t_CompressedWaterColumnDataType_Skipped = R"doc(samples not read (lazy))doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


