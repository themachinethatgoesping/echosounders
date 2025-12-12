//sourcehash: de7c138bef49ad419f4c4fdc64521af9877b0c5c0bb89b3cd6f573dc0e4543d0

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


static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_KMALLPingFileData = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_KMALLPingFileData_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_class_name = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_get_datagram_infos = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_get_file_numbers = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_get_file_paths = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_get_ifs =
R"doc(Return the filestream associated with the first datagram of the
specified type

Args:
    datagram_identifier: 

Returns:
    std::istream&)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_get_multisector_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_get_primary_file_path = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_get_runtime_parameters = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_get_sysinfos = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_get_sysinfos_const = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_get_watercolumn_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_get_watercolumn_calibration_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_get_wcinfos = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_get_wcinfos_const = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_has_any_of_datagram_types = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_has_datagram_type = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_has_datagram_type_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_has_runtime_parameters = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_has_watercolumn_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_init_watercolumn_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_load_sys = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_load_wci = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_multisector_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_multisector_calibration_loaded = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_must_have_datagrams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_read_first_datagram = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_read_xyz =
R"doc(read XYZ for the bottom detection datagram

Returns:
    algorithms::geoprocessing::datastructures::XYZ<1>)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_read_xyz_2 =
R"doc(read XYZ for the specified beams from the bottom detection datagram
Note: if the beam numbers from the beam selection exceed the number of
      beams in the
datagram, the corresponding XYZ values will be NaN

Args:
    bs: beam selection

Returns:
    algorithms::geoprocessing::datastructures::XYZ<1>)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_release_multisector_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_release_sys = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_release_wci = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_runtime_parameters = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_set_multisector_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_set_runtime_parameters = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_set_systeminformation = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_set_watercolumn_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_set_watercolumn_calibration_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_set_watercolumninformation = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_sys_loaded = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_systeminformation = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_update_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_watercolumninformation = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatatypes_KMALLPingFileData_wci_loaded = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


