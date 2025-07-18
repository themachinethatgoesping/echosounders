//sourcehash: 05d96f3fafbecba0f7e1a0a7bd904324601191be53c98316d1c632ca6686f266

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


static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllConfigurationDataInterfacePerFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllConfigurationDataInterfacePerFile_KongsbergAllConfigurationDataInterfacePerFile = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllConfigurationDataInterfacePerFile_active_heading_sensor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllConfigurationDataInterfacePerFile_active_heave_sensor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllConfigurationDataInterfacePerFile_active_pitch_roll_sensor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllConfigurationDataInterfacePerFile_active_position_system_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllConfigurationDataInterfacePerFile_get_active_heading_sensor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllConfigurationDataInterfacePerFile_get_active_heave_sensor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllConfigurationDataInterfacePerFile_get_active_pitch_roll_sensor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllConfigurationDataInterfacePerFile_get_active_position_system_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllConfigurationDataInterfacePerFile_get_runtime_parameters = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllConfigurationDataInterfacePerFile_init_runtime_parameters =
R"doc(read the runtime parameters from the file and save them in the
internal map This function is automatically called by
get_runtime_parameters)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllConfigurationDataInterfacePerFile_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllConfigurationDataInterfacePerFile_read_extra_info_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllConfigurationDataInterfacePerFile_read_installation_parameters =
R"doc(Read the installation parameters from the file, this function also
checks if the start and end parameters are the same

Returns:
    datagrams::InstallationParameters)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllConfigurationDataInterfacePerFile_read_sensor_configuration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllConfigurationDataInterfacePerFile_runtime_parameters_by_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllConfigurationDataInterfacePerFile_runtime_parameters_initialized = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllConfigurationDataInterfacePerFile_set_active_heading_sensor =
R"doc(Set the active heading sensor "NotSet": this will be overwritten by
"read_sensor_configuration" / "init_interface" All other values: see
t_KongsbergAllActiveSensor

Parameter ``sensor``:)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllConfigurationDataInterfacePerFile_set_active_heave_sensor =
R"doc(Set the active heave sensor "NotSet": this will be overwritten by
"read_sensor_configuration" / "init_interface" All other values: see
t_KongsbergAllActiveSensor

Parameter ``sensor``:)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllConfigurationDataInterfacePerFile_set_active_pitch_roll_sensor =
R"doc(Set the active roll pitch sensor "NotSet": this will be overwritten by
"read_sensor_configuration" / "init_interface" All other values: see
t_KongsbergAllActiveSensor

Parameter ``sensor``:)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_filedatainterfaces_KongsbergAllConfigurationDataInterfacePerFile_set_active_position_system_number =
R"doc(Set the active position system number 0: this will be overwritten by
"read_sensor_configuration" / "init_interface" 1-3: position system
1-3

Parameter ``number``:)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


