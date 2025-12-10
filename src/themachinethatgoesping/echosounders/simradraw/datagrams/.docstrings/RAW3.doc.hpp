//sourcehash: 900d11ec71d318fd4f58ed6d72c7fd8aeb4d26e25cc67aec3315373d1f27e585

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


static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3 =
R"doc(Sample binary datagram (RAW3) This datagram contains the sample data
for each ping. The exact datatype and size depends on the data_type
field!)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_RAW3 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_RAW3_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_channel_id = R"doc(Channel identification (size is always 128))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_count = R"doc(Number of samples in the datagram)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_data_type = R"doc(data_type)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_from_stream_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_from_stream_3 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_from_stream_4 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_get_channel_id = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_get_channel_id_stripped = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_get_count = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_get_data_type = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_get_number_of_complex_samples =
R"doc(Get the number of complex samples. This corresponds to the number of
transducer elements. This field is only valid for complex data types.

Returns:
    simradraw_short)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_get_offset = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_get_sample_data =
R"doc(Get the sample data. The sample data is stored in a variant of xtensor
containers. The exact type depends on the data type.

Returns:
    raw3datatypes::RAW3DataVariant)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_get_spare_1 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_get_spare_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_hash_content_without_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_number_of_complex_samples =
R"doc(Number of transducer samples per sample (used when data_type is
complex))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_offset = R"doc(First sample number in the datagram)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_read_sample_data = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_read_skipped_sample_data = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_sample_data = R"doc(Sample data)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_sample_data_2 =
R"doc(Get the sample data. The sample data is stored in a variant of xtensor
containers. The exact type depends on the data type.

Returns:
    raw3datatypes::RAW3DataVariant)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_sample_data_3 =
R"doc(Get the sample data. (const overload) The sample data is stored in a
variant of xtensor containers. The exact type depends on the data
type.

Returns:
    raw3datatypes::RAW3DataVariant)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_set_channel_id = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_set_count = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_set_data_type = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_set_number_of_complex_samples = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_set_offset = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_set_sample_data = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_set_spare_1 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_set_spare_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_spare_1 = R"doc(Spare 1)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_spare_2 = R"doc(Spare 2)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_to_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_RAW3_to_stream_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_simradraw_datagrams_hash_value =
R"doc(Provide a boost hash function for XML_Parameter_Channel
- Note: this is needed to use XML_Parameter_Channel as
  boost::flyweight

Args:
    data: 

Returns:
    std::size_t)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


