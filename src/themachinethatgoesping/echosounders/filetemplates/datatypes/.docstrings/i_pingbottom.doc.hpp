//sourcehash: fda92661f6c435f5b0d5fe91525da6bff01f8abd4e63d15742a2bd879ff8f069

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


static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingBottom = R"doc(Interface for all ping bottom detection functions)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingBottom_I_PingBottom = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingBottom_class_name = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingBottom_feature_group_functions = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingBottom_get_beam_crosstrack_angles =
R"doc(Get the beam crosstrack angles for this ping in °

Returns:
    xt::xtensor<float, 1>)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingBottom_get_beam_crosstrack_angles_2 =
R"doc(Get the beam crosstrack angles for this ping in °

Returns:
    xt::xtensor<float, 1>)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingBottom_get_beam_numbers_per_tx_sector = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingBottom_get_beam_selection_all =
R"doc(Get a beam selection object that selects all beams

Returns:
    pingtools::BeamSelection)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingBottom_get_number_of_beams =
R"doc(Get the number of beams for this ping

Returns:
    uint16_t)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingBottom_get_number_of_tx_sectors =
R"doc(Get the number of transmission sectors.

This function returns the number of transmission sectors for the
echosounder.

Returns:
    The number of transmission sectors.)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingBottom_get_two_way_travel_times =
R"doc(Get the two way travel times of the bottom detection samples

Returns:
    xt::xtensor<float, 1>)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingBottom_get_two_way_travel_times_2 =
R"doc(Get the two way travel times of the bottom detection samples

Returns:
    xt::xtensor<float, 1>)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingBottom_get_tx_sector_per_beam = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingBottom_get_tx_signal_parameters =
R"doc(Get the transmission signal parameters per sector.

Returns:
    const std::vector<algorithms::signalprocessing::datastructures::Tx
    SignalParameters>&)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingBottom_get_xyz =
R"doc(Get an XYZ object containing the XYZ position of the bottom detection
Note: XYZ is in the local coordinate system of the ping! To convert it
use algorithms::geoprocessing::georeferencer class or - Use
get_xyz_utm() to get the bottom detection in UTM coordinates - Use
get_xyz_latlon() to get the bottom detection in Latitude/Longitude
coordinates

Returns:
    algorithms::geoprocessing::datastructures::XYZ<1>)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingBottom_get_xyz_2 =
R"doc(Get an XYZ object containing the XYZ position of the bottom detection
Note: XYZ is in the local coordinate system of the ping! To convert it
use algorithms::geoprocessing::georeferencer class or - Use
get_xyz_utm() to get the bottom detection in UTM coordinates - Use
get_xyz_latlon() to get the bottom detection in Latitude/Longitude
coordinates

Parameter ``selection``:
    structure with selected transducer_ids/beams/samples considered
    for this function

Returns:
    algorithms::geoprocessing::datastructures::XYZ<1>)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingBottom_has_beam_crosstrack_angles =
R"doc(Check this pings supports the extraction of beam_crosstrack_angles

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingBottom_has_two_way_travel_times =
R"doc(Check this pings supports the extraction of two_way_travel_times

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingBottom_has_tx_sector_information = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingBottom_has_tx_signal_parameters = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingBottom_has_xyz =
R"doc(Check this pings supports XYZ data

Returns:
    true

Returns:
    false)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingBottom_primary_feature_functions = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingBottom_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_PingBottom_secondary_feature_functions = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


