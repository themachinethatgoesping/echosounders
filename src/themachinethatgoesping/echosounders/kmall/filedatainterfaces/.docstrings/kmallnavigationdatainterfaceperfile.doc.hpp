//sourcehash: a1754c1ee80484cdb7e3bca01ccae92a9df0a27381ac9c5e70723dfe47050bfb

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


static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatainterfaces_KMALLNavigationDataInterfacePerFile = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatainterfaces_KMALLNavigationDataInterfacePerFile_KMALLNavigationDataInterfacePerFile = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatainterfaces_KMALLNavigationDataInterfacePerFile_KMALLNavigationDataInterfacePerFile_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatainterfaces_KMALLNavigationDataInterfacePerFile_get_prefer_skm_over_che =
R"doc(Get whether S_KM_BINARY is preferred over C_HEAVE for heave data
Returns:
    true if S_KM_BINARY is preferred (default))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatainterfaces_KMALLNavigationDataInterfacePerFile_get_prefer_spo_over_cpo =
R"doc(Get whether S_POSITION is preferred over C_POSITION
Returns:
    true if S_POSITION is preferred (default))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatainterfaces_KMALLNavigationDataInterfacePerFile_packet_timestamp_in_range =
R"doc(Internal function to check if a timestamp is within the allowed time
range If the timestamp is equal to the previous one, it is ignored
(return false). If the timestamp is smaller than the previous one, an
exception is thrown.

Args:
    times: vector with previous timestamps
    packet_timestamp: timestamp to check
    data_name: name of the data type for error messages

Returns:
    true if timestamp is valid and should be added false if timestamp
    should be ignored (duplicate))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatainterfaces_KMALLNavigationDataInterfacePerFile_prefer_skm_over_che = R"doc(Prefer S_KM_BINARY over C_HEAVE for heave)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatainterfaces_KMALLNavigationDataInterfacePerFile_prefer_spo_over_cpo = R"doc(Prefer S_POSITION over C_POSITION)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatainterfaces_KMALLNavigationDataInterfacePerFile_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatainterfaces_KMALLNavigationDataInterfacePerFile_read_attitude_from_skm =
R"doc(Read attitude data from S_KM_BINARY datagrams

S_KM_BINARY contains multiple samples per datagram with:
- Position (lat, lon, height) - Attitude (roll, pitch, heading, heave)
  - Velocities and accelerations - Validity flags for each data type)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatainterfaces_KMALLNavigationDataInterfacePerFile_read_heave_from_che = R"doc(Read heave data from C_HEAVE datagrams)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatainterfaces_KMALLNavigationDataInterfacePerFile_read_navigation_data = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatainterfaces_KMALLNavigationDataInterfacePerFile_read_position_from_cpo = R"doc(Read position data from C_POSITION datagrams)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatainterfaces_KMALLNavigationDataInterfacePerFile_read_position_from_spo = R"doc(Read position data from S_POSITION datagrams)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatainterfaces_KMALLNavigationDataInterfacePerFile_set_prefer_skm_over_che =
R"doc(Set whether S_KM_BINARY is preferred over C_HEAVE for heave data
Args:
    prefer: true to prefer S_KM_BINARY (default), false to prefer
            C_HEAVE)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatainterfaces_KMALLNavigationDataInterfacePerFile_set_prefer_spo_over_cpo =
R"doc(Set whether S_POSITION is preferred over C_POSITION
Args:
    prefer: true to prefer S_POSITION (default), false to prefer
            C_POSITION)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


