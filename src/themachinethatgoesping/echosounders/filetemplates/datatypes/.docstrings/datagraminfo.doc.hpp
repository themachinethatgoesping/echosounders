//sourcehash: 472b6677bede5c4bf46176390c47c575538260963e29dabfbefa0e16ff5dedbd

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


static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_DatagramInfoData = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_DatagramInfoData_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_DatagramInfoData_3 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_add_extra_info = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_datagram_identifier = R"doc(datagram type of this datagram)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_extra_infos = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_file_pos = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_from_stream_no_extra_infos = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_get_datagram_identifier = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_get_extra_info = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_get_extra_infos = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_get_file_pos = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_get_timestamp = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_set_extra_info = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_set_extra_infos = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_timestamp = R"doc(timestamp (unixtime) of this datagram)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_to_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfoData_to_stream_no_extra_infos = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_DatagramInfo = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_DatagramInfo_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_file_nr = R"doc(file number of this datagram)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_file_nr_to_file_path = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_get_file_nr = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_get_file_path = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_get_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_get_stream_and_seek = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_input_file_manager = R"doc(input file manager)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_read_datagram_from_file = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datatypes_DatagramInfo_read_datagram_from_file_2 =
R"doc(same as above, but this function provides the skip data option (which
is not avaliable for all datagram types)

Args:
    skip_data: 

Template Args:
    t_DatagramType: 
    t_DatagramTypeFactory: 

Returns:
    t_DatagramType)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


