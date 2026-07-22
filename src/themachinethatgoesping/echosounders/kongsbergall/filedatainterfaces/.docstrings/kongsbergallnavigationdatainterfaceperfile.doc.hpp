//sourcehash: 63d2bdea72d5e46ad7cb24f99ee32727c8ac962574d54d7b8c1eea752cbbebd6

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


static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllNavigationDataInterfacePerFile = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllNavigationDataInterfacePerFile_KongsbergAllNavigationDataInterfacePerFile = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllNavigationDataInterfacePerFile_KongsbergAllNavigationDataInterfacePerFile_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllNavigationDataInterfacePerFile_active_sensor_number =
R"doc(Map an active-sensor enum (from the installation parameters
ARO/AHS/AHE) to the motion sensor number (1 or 2) as encoded in the
attitude datagram sensor system descriptor. Returns -1 if the active
sensor is not a motion / attitude-velocity sensor, in which case no
sensor filtering is applied (legacy behaviour).)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllNavigationDataInterfacePerFile_add_attitudes = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllNavigationDataInterfacePerFile_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllNavigationDataInterfacePerFile_read_navigation_data = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllNavigationDataInterfacePerFile_sort_and_deduplicate_time_series =
R"doc(Sort a time series, drop invalid timestamps, and retain the first
sample for duplicates.)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


