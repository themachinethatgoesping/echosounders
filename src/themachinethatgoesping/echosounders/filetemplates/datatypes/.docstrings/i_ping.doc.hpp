//sourcehash: f42455258eb8392c080cfd596ee49efb549a0b0d308d0c19522a659d51d315d3

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


static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_I_Ping = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_bottom = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_bottom_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_channel_id = R"doc(< channel id of the transducer)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_class_name = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_feature_group_functions = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_get_channel_id = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_get_geolocation = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_get_navigation_interpolator_latlon = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_get_sensor_configuration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_get_sensor_configuration_base_hash =
R"doc(Returns the hash of the base sensor configuraiton. This is the sensor
configuration with the "Transducer" target removed. This hash can be
used to get the correct navigation interpolator from the
navigation_data_interface Note: This function is for testing and
finding errors. It is rather slow.

Returns:
    uint64_t)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_get_sensor_data_latlon = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_get_timestamp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_has_bottom = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_has_channel_id = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_has_geolocation = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_has_navigation_interpolator_latlon = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_has_sensor_configuration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_has_sensor_data_latlon = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_has_timestamp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_has_watercolumn = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_load = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_loaded = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_navigation_interpolator_latlon = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_navigation_interpolator_set = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_not_implemented = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_not_implemented_not_implemented = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_primary_feature_functions = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_release = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_secondary_feature_functions = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_sensor_configuration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_sensor_configuration_set = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_set_channel_id = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_set_navigation_interpolator_latlon = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_set_navigation_interpolator_latlon_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_set_sensor_configuration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_set_sensor_configuration_flyweight = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_set_timestamp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_timestamp = R"doc(< Unix timestamp in seconds (saved in UTC0))doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_watercolumn = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_watercolumn_2 = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


