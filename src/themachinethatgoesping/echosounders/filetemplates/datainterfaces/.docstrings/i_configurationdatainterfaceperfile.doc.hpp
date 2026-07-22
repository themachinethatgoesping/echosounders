//sourcehash: 4d0918f66f755fc4242d44753368d5b824d48a37367051b02747b7182e9e6d6a

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


static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_ConfigurationDataInterfacePerFile = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_ConfigurationDataInterfacePerFile_I_ConfigurationDataInterfacePerFile = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_ConfigurationDataInterfacePerFile_deinitialize = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_ConfigurationDataInterfacePerFile_get_sensor_configuration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_ConfigurationDataInterfacePerFile_get_use_surface_sound_speed_in_sound_velocity_profile =
R"doc(Whether the measured transducer/surface sound speed is integrated into
the sound velocity profile at the transducer depth when ray tracing.

This is read from the file's installation parameters when the
interface is initialized (e.g. from the Kongsberg .all "SHC" field: 0
-> true, 1 -> false). Formats that do not specify it default to true.
It can be overridden with
set_use_surface_sound_speed_in_sound_velocity_profile().

Returns:
    true if the surface sound speed should be used, false otherwise.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_ConfigurationDataInterfacePerFile_init_from_file = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_ConfigurationDataInterfacePerFile_is_initialized = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_ConfigurationDataInterfacePerFile_is_initialized_sensor_configuration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_ConfigurationDataInterfacePerFile_is_initialized_sensor_configuration_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_ConfigurationDataInterfacePerFile_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_ConfigurationDataInterfacePerFile_read_sensor_configuration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_ConfigurationDataInterfacePerFile_sensor_configuration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_ConfigurationDataInterfacePerFile_set_sensor_configuration = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_ConfigurationDataInterfacePerFile_set_use_surface_sound_speed_in_sound_velocity_profile =
R"doc(Set whether the measured transducer/surface sound speed is integrated
into the sound velocity profile at the transducer depth when ray
tracing.

Args:
    use_surface_sound_speed: true to use the surface sound speed,
                             false to raytrace the archived profile as
                             is.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_ConfigurationDataInterfacePerFile_use_surface_sound_speed_in_sound_velocity_profile =
R"doc(Whether the measured transducer/surface sound speed should be
integrated into the sound velocity profile at the transducer depth
when ray tracing. Read and stored from the file's installation
parameters on initialization (format-specific, e.g. the Kongsberg .all
"SHC"
field: 0 = used [default], 1 = not used); defaults to true for formats
       that do not specify.)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


