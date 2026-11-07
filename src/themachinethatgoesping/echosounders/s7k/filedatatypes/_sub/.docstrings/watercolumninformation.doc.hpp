//sourcehash: 620caa56ce9a4362027701b6013d9e010607fb0b8475478a334353421df44322

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


static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WaterColumnInformation =
R"doc(Lightweight water-column information of a single s7k ping (7042
CompressedWaterColumnData).

It stores only what is needed to read the water column efficiently -
the per-beam sample counts and the per-beam file positions of the
samples - but NOT the samples themselves. The samples are read on
demand (a subset of beams / samples at a time) directly from the file
via read_beam_samples() and returned to the caller, so they are never
held in memory. The per-beam numbers / sample counts and the record-
wide information are deduplicated across pings with flyweights.

Note this is a private substructure and thus not part of the public
API or nanobind interface.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WaterColumnInformation_WaterColumnInformation = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WaterColumnInformation_WaterColumnInformation_2 =
R"doc(Build the water-column information from a 7042 record that was read
with skip_data = true (i.e. only the per-beam headers + sample
positions were read, not the samples).

)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WaterColumnInformation_beam_numbers = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WaterColumnInformation_convert_magnitude_to_db =
R"doc(Convert raw magnitude values (as float) to dB according to the record
encoding.

Vectorized (xsimd friendly) expression reused by the ping water-column
accessor to convert only the selected beams/samples. 8-bit values are
already in a (compressed) dB scale and pass through; 16/32-bit values
are 20*log10(mag/full_scale).

)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WaterColumnInformation_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WaterColumnInformation_get_beam_numbers = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WaterColumnInformation_get_data_type = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WaterColumnInformation_get_downsampling_divisor = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WaterColumnInformation_get_first_sample = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WaterColumnInformation_get_has_phase = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WaterColumnInformation_get_magnitude_is_32bit = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WaterColumnInformation_get_magnitude_is_db = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WaterColumnInformation_get_number_of_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WaterColumnInformation_get_sample_counts = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WaterColumnInformation_get_sample_positions = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WaterColumnInformation_get_sample_rate = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WaterColumnInformation_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WaterColumnInformation_read_beam_samples =
R"doc(Read a (contiguous) sub-range of one beam's samples from the file.

The samples are returned in their native (on-disk) encoding as a
CompressedWaterColumnDataVariant (magnitude / phase decoding is
deferred to the accessor). The data is read directly from the stream
and returned - it is never stored on this object.

Args:
    beam_number: index of the beam (0-based, into the per-beam arrays)
    first_sample: first sample (within the beam) to read
    number_of_samples: number of samples to read
    ifs: input stream of the file the 7042 record was read from

Template Args:
    t_ifstream: input stream type

)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WaterColumnInformation_sample_counts = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WaterColumnInformation_sample_positions = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WaterColumnInformation_to_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_sub_WaterColumnInformation_wci_infos = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


