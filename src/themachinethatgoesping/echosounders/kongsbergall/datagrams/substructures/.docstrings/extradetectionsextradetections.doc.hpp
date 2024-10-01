//sourcehash: 02409257e6c2ac37aba99fcfdb673a3c332035bd899d077f8aa24df16972a56b

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


static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections = R"doc(Extra Detections in the extra detections datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_ExtraDetectionsExtraDetections = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_across = R"doc(< y in m)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_along = R"doc(< x in m)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_applied_pointing_angle_correction = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_applied_two_way_travel_time_corrections = R"doc(< seconds, f.ex. Doppler correction)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_backscatter = R"doc(< 0.1 dB)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_beam_angle_across = R"doc(< re vertical °)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_beam_crosstrack_angle = R"doc(< deg. re array)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_beam_incidence_angle_adjustment = R"doc(< IBA in 0.1°)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_confidence_level = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_delta_latitude = R"doc(< °)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_delta_longitude = R"doc(< °)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_depth = R"doc(< z in m)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_detected_range = R"doc(< in (WCsr) samples)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_detection_class_number = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_detection_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_detection_window_length = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_get_across = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_get_along = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_get_applied_pointing_angle_correction = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_get_applied_two_way_travel_time_corrections = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_get_backscatter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_get_backscatter_in_db =
R"doc(Get the backscatter in dB

Returns:
    _backscatter * 0.1 dB (double))doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_get_backscatter_is_compensated =
R"doc(This function evaluates the detection information flag. If the 4th bit
is set to 1, the detection is compensated for beam incident angle. If
the 4th bit is set to 0, the detection is not compensated for beam
incident angle.

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_get_beam_angle_across = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_get_beam_crosstrack_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_get_beam_incidence_angle_adjustment = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_get_confidence_level = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_get_delta_latitude = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_get_delta_longitude = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_get_depth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_get_detected_range = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_get_detection_class_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_get_detection_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_get_detection_is_valid =
R"doc(This function evaluates the detection information flag. If the last
bit is set to 1, the detection is valid. If the last bit is set to 0,
the detection is invalid.

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_get_detection_type =
R"doc(This function evaluates the detection information flag. The first 3
bits indicate the type of detection.

Returns:
    t_DetectionType)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_get_detection_window_length = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_get_number_of_raw_amplitude_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_get_qf_10 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_get_qf_threshold =
R"doc(Get the ifremer QF threshold

Returns:
    qf_threshold_10 * 0.1 (double))doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_get_quality_factor_old = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_get_range_factor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_get_real_time_cleaning_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_get_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_get_two_way_travel_time = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_get_tx_sector_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_get_water_column_beam_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_number_of_raw_amplitude_samples = R"doc(< NS)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_qf_10 = R"doc(< Ifremer Quality factor * 10)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_quality_factor_old = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_range_factor = R"doc(< in %)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_real_time_cleaning_info = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_set_across = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_set_along = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_set_applied_pointing_angle_correction = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_set_applied_two_way_travel_time_corrections = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_set_backscatter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_set_beam_angle_across = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_set_beam_crosstrack_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_set_beam_incidence_angle_adjustment = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_set_confidence_level = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_set_delta_latitude = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_set_delta_longitude = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_set_depth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_set_detected_range = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_set_detection_class_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_set_detection_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_set_detection_window_length = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_set_number_of_raw_amplitude_samples = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_set_qf_10 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_set_quality_factor_old = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_set_range_factor = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_set_real_time_cleaning_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_set_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_set_two_way_travel_time = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_set_tx_sector_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_set_water_column_beam_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_two_way_travel_time = R"doc(< s)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_tx_sector_number = R"doc(< or TX array index)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_substructures_ExtraDetectionsExtraDetections_water_column_beam_number = R"doc(<)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


