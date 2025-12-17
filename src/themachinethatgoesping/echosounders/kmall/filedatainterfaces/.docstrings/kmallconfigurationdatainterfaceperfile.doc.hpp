//sourcehash: b635935cf90cf78359bf25976ed07afe9872bc55c2a9843ebecedda2a989ae28

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


static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatainterfaces_KMALLConfigurationDataInterfacePerFile = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatainterfaces_KMALLConfigurationDataInterfacePerFile_KMALLConfigurationDataInterfacePerFile = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatainterfaces_KMALLConfigurationDataInterfacePerFile_active_attitude_sensor_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatainterfaces_KMALLConfigurationDataInterfacePerFile_active_position_system_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatainterfaces_KMALLConfigurationDataInterfacePerFile_get_active_attitude_sensor_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatainterfaces_KMALLConfigurationDataInterfacePerFile_get_active_position_system_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatainterfaces_KMALLConfigurationDataInterfacePerFile_get_runtime_parameters =
R"doc(Get the runtime parameters for a specific ping

This function searches for the runtime parameters that were active at
the given ping time. It uses last_index as an optimization to avoid
searching from the beginning each time.

Args:
    system_serial_number: The PU serial number to search for
    ping_time: The timestamp of the ping
    last_index: Shared pointer to the last index used for optimization
                (will be updated)

Returns:
    boost::flyweight<datagrams::IOpRuntime> The runtime parameters for
          the ping)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatainterfaces_KMALLConfigurationDataInterfacePerFile_get_transducer_id = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatainterfaces_KMALLConfigurationDataInterfacePerFile_init_runtime_parameters =
R"doc(Read the runtime parameters from the file and save them in the
internal map This function is automatically called by
get_runtime_parameters)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatainterfaces_KMALLConfigurationDataInterfacePerFile_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatainterfaces_KMALLConfigurationDataInterfacePerFile_read_installation_parameters =
R"doc(Read the installation parameters from the file

Returns:
    datagrams::IInstallationParam)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatainterfaces_KMALLConfigurationDataInterfacePerFile_read_sensor_configuration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatainterfaces_KMALLConfigurationDataInterfacePerFile_runtime_parameters_by_system_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatainterfaces_KMALLConfigurationDataInterfacePerFile_runtime_parameters_initialized = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatainterfaces_KMALLConfigurationDataInterfacePerFile_set_active_attitude_sensor_number =
R"doc(Set the active attitude sensor number
0: this will be overwritten by "read_sensor_configuration" /
   "init_interface"
1-4: attitude sensor 1-4

Args:
    number:)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kmall_filedatainterfaces_KMALLConfigurationDataInterfacePerFile_set_active_position_system_number =
R"doc(Set the active position system number
0: this will be overwritten by "read_sensor_configuration" /
   "init_interface"
1-4: position system 1-4

Args:
    number:)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


