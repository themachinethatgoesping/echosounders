//sourcehash: 472b6677bede5c4bf46176390c47c575538260963e29dabfbefa0e16ff5dedbd

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


static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_DatagramInfoData = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_DatagramInfoData_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_DatagramInfoData_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_add_extra_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_datagram_identifier = R"doc(< datagram type of this datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_extra_infos = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_file_pos = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_from_stream_no_extra_infos = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_get_datagram_identifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_get_extra_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_get_extra_infos = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_get_file_pos = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_get_timestamp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_set_extra_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_set_extra_infos = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_timestamp = R"doc(< timestamp (unixtime) of this datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_to_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_to_stream_no_extra_infos = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_DatagramInfo = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_DatagramInfo_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_file_nr = R"doc(< file number of this datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_file_nr_to_file_path = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_get_file_nr = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_get_file_path = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_get_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_get_stream_and_seek = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_input_file_manager = R"doc(< input file manager)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_read_datagram_from_file = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_read_datagram_from_file_2 =
R"doc(same as above, but this function provides the skip data option (which
is not avaliable for all datagram types)

Template parameter ``t_DatagramType``:
    $Template parameter ``t_DatagramTypeFactory``:

Parameter ``skip_data``:
    $Returns:

t_DatagramType)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


