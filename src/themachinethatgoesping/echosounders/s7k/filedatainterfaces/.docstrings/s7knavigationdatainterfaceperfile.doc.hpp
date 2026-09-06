//sourcehash: ae7d77f0c5bbf991a408053cf7d3790584ef15b0135cc1db4c7695e6528606f0

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


static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KNavigationDataInterfacePerFile =
R"doc(Interface that reads the navigation (position, attitude, heading) of a
single .s7k file.

The 7k format stores each navigation quantity in two kinds of records:
a modern "fused" record (1015 Navigation for position/heading, 1016
Attitude for roll/pitch/heave/heading) and a legacy single-quantity
record (1003 Position, 1012 Roll Pitch Heave, 1013 Heading). By
default the modern records are preferred; the two preferences can be
toggled with the setters below.

Template Args:
    t_ifstream:)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KNavigationDataInterfacePerFile_S7KNavigationDataInterfacePerFile = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KNavigationDataInterfacePerFile_S7KNavigationDataInterfacePerFile_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KNavigationDataInterfacePerFile_get_prefer_attitude_over_rollpitchheave =
R"doc(Get whether the 1016 Attitude record is preferred over the 1012 Roll
Pitch Heave record
Returns:
    true if 1016 Attitude is preferred (default))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KNavigationDataInterfacePerFile_get_prefer_navigation_over_position =
R"doc(Get whether the 1015 Navigation record is preferred over the 1003
Position record
Returns:
    true if 1015 Navigation is preferred (default))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KNavigationDataInterfacePerFile_has_datagrams =
R"doc(Check whether the file contains at least one datagram of the given
type.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KNavigationDataInterfacePerFile_prefer_attitude_over_rollpitchheave = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KNavigationDataInterfacePerFile_prefer_navigation_over_position = R"doc(Prefer 1015 Navigation over 1003 Position)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KNavigationDataInterfacePerFile_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KNavigationDataInterfacePerFile_read_attitude_from_attitude =
R"doc(Read roll, pitch, heave and heading from the 1016 Attitude records.

Each 1016 record holds several samples, each with a time offset
(delta_time, in ms) relative to the record timestamp. The 7k sign
conventions (7k DFD Table 2) match ours: roll +port up, pitch +bow up,
heave +up, heading true north-referenced -> no sign flips are needed.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KNavigationDataInterfacePerFile_read_attitude_from_rollpitchheave =
R"doc(Read roll, pitch and heave from the 1012 Roll Pitch Heave records (no
heading).)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KNavigationDataInterfacePerFile_read_heading_from_attitude =
R"doc(Read heading only from the 1016 Attitude records (roll/pitch/heave
read elsewhere).)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KNavigationDataInterfacePerFile_read_heading_from_heading = R"doc(Read heading from the 1013 Heading records.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KNavigationDataInterfacePerFile_read_heading_from_navigation = R"doc(Read heading from the 1015 Navigation records.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KNavigationDataInterfacePerFile_read_navigation_data = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KNavigationDataInterfacePerFile_read_position_from_navigation = R"doc(Read position (latitude/longitude) from the 1015 Navigation records.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KNavigationDataInterfacePerFile_read_position_from_position =
R"doc(Read position (latitude/longitude) from the 1003 Position records.

Only geographical coordinates are supported; records in grid
coordinates are skipped.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KNavigationDataInterfacePerFile_set_prefer_attitude_over_rollpitchheave =
R"doc(Set whether the 1016 Attitude record is preferred over the 1012 Roll
Pitch Heave record
Args:
    prefer: true to prefer 1016 Attitude (default), false to prefer
            1012 Roll Pitch Heave)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KNavigationDataInterfacePerFile_set_prefer_navigation_over_position =
R"doc(Set whether the 1015 Navigation record is preferred over the 1003
Position record
Args:
    prefer: true to prefer 1015 Navigation (default), false to prefer
            1003 Position)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_filedatainterfaces_S7KNavigationDataInterfacePerFile_sort_and_deduplicate_time_series =
R"doc(Sort a time series, drop invalid timestamps, and keep the first sample
for duplicates.

The associated value vectors are reordered in lock-step with the
timestamps.)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


