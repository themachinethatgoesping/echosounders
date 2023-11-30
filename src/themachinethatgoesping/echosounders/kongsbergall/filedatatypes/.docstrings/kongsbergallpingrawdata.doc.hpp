//sourcehash: 844ef318908268ca654c05d199f9f4b84189c7b5572c71aa4706ec1c5f59d1c5

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


static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingRawData = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingRawData_KongsbergAllPingRawData = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingRawData_get_file_numbers = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingRawData_get_file_paths = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingRawData_get_ifs =
R"doc(Return the filestream associated with the first datagram of the
specified type

Parameter ``datagram_identifier``:
    $Returns:

std::istream&)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingRawData_get_name = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingRawData_get_primary_file_path = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingRawData_get_runtime_parameters = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingRawData_must_have_datagrams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingRawData_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingRawData_read_first_datagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingRawData_read_merged_watercolumndatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingRawData_read_xyz =
R"doc(read XYZ for the bottom detection datagram

Returns:
    algorithms::geoprocessing::datastructures::XYZ<1>)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingRawData_read_xyz_2 =
R"doc(read XYZ for the specified beams from the bottom detection datagram
Note: if the beam numbers from the beam selection exceed the number of
beams in the datagram, the corresponding XYZ values will be NaN

Parameter ``bs``:
    beam selection

Returns:
    algorithms::geoprocessing::datastructures::XYZ<1>)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingRawData_runtime_parameters = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatatypes_KongsbergAllPingRawData_set_runtime_parameters = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


