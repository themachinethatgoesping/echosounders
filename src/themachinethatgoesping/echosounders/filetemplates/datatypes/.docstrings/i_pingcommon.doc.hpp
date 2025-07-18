//sourcehash: 600608dba509229d48b69203e21b46d4b09e5a97485a4781a07cd35a11b93f52

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


static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_I_PingCommon = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_available_feature_groups = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_available_features = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_class_name = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_feature_group_functions = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_feature_groups =
R"doc(Get a string of all registered feature groups for this ping class

Returns:
    std::string)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_feature_groups_string =
R"doc(Get a string of all registered feature groups that are available or
not available

Parameter ``available``:
    if True (default) return available features, else return not
    available features

Returns:
    std::string)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_feature_string =
R"doc(Get a string of all registered features that are available or not
available

Parameter ``available``:
    if True (default) return available features, else return not
    available features

Returns:
    std::string)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_has_all_of_features =
R"doc(Check if all of the specified features are available

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_has_any_of_features =
R"doc(Check if any of the specified features is available

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_has_feature =
R"doc(Check if any of the registered features is available

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_has_feature_groups = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_has_features =
R"doc(Check if any of the registered features is available

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_has_primary_features =
R"doc(Check if any of the registered main features is available

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_has_secondary_features = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_load = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_loaded = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_not_implemented = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_not_implemented_not_implemented = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_possible_feature_groups = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_possible_features = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_primary_feature_functions = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_primary_features =
R"doc(Get a string of all registered primary features for this ping class

Returns:
    std::string)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_print_feature_groups = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_print_features = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_registered_features =
R"doc(Get a string of all registered features for this ping class

Returns:
    std::string)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_release = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_secondary_feature_functions = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingCommon_secondary_features =
R"doc(Get a string of all registered secondary features for this ping class

Returns:
    std::string)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_t_pingfeature = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_t_pingfeature_amplitudes = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_t_pingfeature_ap = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_t_pingfeature_av = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_t_pingfeature_beam_crosstrack_angles = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_t_pingfeature_beam_numbers_per_tx_sector = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_t_pingfeature_beam_selection_all = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_t_pingfeature_bottom = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_t_pingfeature_bottom_range_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_t_pingfeature_channel_id = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_t_pingfeature_datetime = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_t_pingfeature_file_data = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_t_pingfeature_geolocation = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_t_pingfeature_multisectorwatercolumn_calibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_t_pingfeature_navigation_interpolator_latlon = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_t_pingfeature_number_of_beams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_t_pingfeature_number_of_tx_sectors = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_t_pingfeature_power = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_t_pingfeature_pp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_t_pingfeature_pv = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_t_pingfeature_rp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_t_pingfeature_rv = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_t_pingfeature_sensor_configuration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_t_pingfeature_sensor_data_latlon = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_t_pingfeature_sp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_t_pingfeature_sv = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_t_pingfeature_timestamp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_t_pingfeature_two_way_travel_times = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_t_pingfeature_tx_sector_per_beam = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_t_pingfeature_tx_signal_parameters = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_t_pingfeature_watercolumn = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_t_pingfeature_watercolumn_calibration = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_t_pingfeature_xyz = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


