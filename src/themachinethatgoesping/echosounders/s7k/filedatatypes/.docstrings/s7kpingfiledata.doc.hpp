//sourcehash: 30effe93f7c3dcb3673aa5fd311e40c760bc2680de36c6eaf52b4715da3ceb70

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


static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData =
R"doc(Raw file data of a single s7k ping. Holds the datagram index of the
ping (via the S7KDatagramInterface base) and provides raw access to
the ping's datagrams.

Template Args:
    t_ifstream: 

Note:
    The datagram-processing functions are not implemented yet. This
    class currently only provides the structure so it can be filled in
    in a later step.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_S7KPingFileData = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_S7KPingFileData_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_class_name = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_detection_loaded = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_detectioninformation = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_get_detection_point_per_beam_number = R"doc(detected bottom sample number (fractional) per beam number)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_get_detectioninfos = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_get_detectioninfos_const = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_get_file_numbers = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_get_file_paths = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_get_ifs =
R"doc(Input stream of the first datagram of the given type (for lazy, on-
demand reads).

)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_get_multisector_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_get_primary_file_path = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_get_rx_angle_in_degrees_per_beam_number =
R"doc(receive steering angle (degrees) per beam number (nudged strictly
increasing)

)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_get_sysinfos = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_get_sysinfos_const = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_get_watercolumn_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_get_watercolumn_calibration_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_get_wcinfos = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_get_wcinfos_const = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_has_datagram_type = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_has_raw_detection = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_has_sonar_settings = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_has_water_column = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_has_watercolumn_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_info_string =
R"doc(                                                                                           \
return an info string using the class __printer__ object
\

Args:
    float_precision: number of digits for floating point values
                     \
    superscript_exponents: print exponents in superscript
                           \

Returns:
    std::string
    \

)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_init_watercolumn_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_load_detection = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_load_sys = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_load_wci =
R"doc(Lightweight water-column information (per-beam sample counts + file
positions + the record-wide encoding). The water-column samples
themselves are NOT loaded here - they are read on demand per beam via
S7KPingWatercolumn. Reading metadata therefore no longer pulls the
whole 7042 record into memory.

)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_multisector_calibration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_must_have_datagrams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_print =
R"doc(                                                                                           \
print the object information to the given outpustream
\ \

Args:
    os: output stream, e.g. file stream or std::out or std::cerr
        \
    float_precision: number of digits for floating point values
                     \
    superscript_exponents: print exponents in superscript
                           \

)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_read_first_datagram = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_release_detection = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_release_sys = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_release_wci = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_set_detectioninformation = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_set_systeminformation = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_set_watercolumninformation = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_sys_loaded = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_systeminformation = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_watercolumninformation = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatatypes_S7KPingFileData_wci_loaded = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


