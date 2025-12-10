//sourcehash: 0397c712687381f252682fd895b3e94bc406c1be630459f87e4b3299837c672f

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


static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_I_NavigationDataInterface = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_add_file_interface = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_configuration_data_interface = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_configuration_data_interface_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_configuration_data_interface_const = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_deinitialize = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_get_channel_ids = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_get_channel_ids_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_get_navigation_data =
R"doc(Get navigation data as a map of GeolocationLatLonVector per channel

This function extracts navigation data for all available channels at
regular time intervals. It automatically detects available sensor
configurations, time ranges, and handles data gaps by not
interpolating across them.

Args:
    downsample_interval_sec: Time interval between samples in seconds.
                             Use 0 or negative to disable downsampling
                             (use all original timestamps)
    max_gap_sec: Maximum allowed gap in the original data before
                 considering it a data gap. Points that would require
                 interpolating across a gap larger than this are
                 skipped. If <= 0, defaults to 2x
                 downsample_interval_sec (or 10 seconds if no
                 downsampling)

Returns:
    std::unordered_map<std::string,
        navigation::datastructures::GeolocationLatLonVector> Map from
        channel_id to GeolocationLatLonVector containing timestamps
        and positions)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_get_navigation_interpolator = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_get_navigation_interpolator_flyweight = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_get_navigation_interpolator_keys = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_get_navigation_interpolators = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_has_navigation_interpolator = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_init_from_file = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_is_initialized = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_is_initialized_navigation_interpolator = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_is_initialized_navigation_interpolators = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_navigation_interpolators = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_set_navigation_interpolator = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_set_navigation_interpolator_flyweight = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_filetemplates_datainterfaces_I_NavigationDataInterface_set_navigation_interpolators = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


