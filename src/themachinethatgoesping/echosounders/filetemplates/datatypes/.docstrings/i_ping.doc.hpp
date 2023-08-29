//sourcehash: 6105c1229b1d5361c5eff27ff49075d97e14eb6dcdc7024855a865b9311bd1fd

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

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_feature_string = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_geolocation = R"doc(< Geolocation of the transducer. A)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_get_angle =
R"doc(Compute the launch angle of the (single) target within each sample. If
you see this comment, this function was not implemented for the
current ping type.

Returns:
    xt::xtensor<float, 2>)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_get_beam_pointing_angles =
R"doc(Get the beam pointing angles in °.

Returns:
    xt::xtensor<float, 1> in °)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_get_beam_pointing_angles_2 =
R"doc(Get the beam pointing angles in ° when specifying the beams and
samples to select.

Parameter ``selection:``:
    Structure containing information about which beams and samples to
    select.

Returns:
    xt::xtensor<float, 1> in °)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_get_channel_id = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_get_file_nr = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_get_file_path = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_get_geolocation =
R"doc(Get the geolocation of the transducer.

Returns:
    const navigation::datastructures::GeoLocationLatLon&)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_get_number_of_beams =
R"doc(Get the number of beams

Returns:
    size_t)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_get_number_of_beams_2 =
R"doc(Get the number of beams when specifying the beams and samples to
select. Note: this function just returns
selection.get_number_of_beams()

Parameter ``selection:``:
    Structure containing information about which beams and samples to
    select.

Returns:
    size_t)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_get_number_of_samples_per_beam =
R"doc(Get the number of samples per beam

Returns:
    xt::xtensor<uint16_t, 1>)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_get_number_of_samples_per_beam_2 =
R"doc(Get the number of samples per beam when specifying the beams and
samples to select. Note: this function just returns an array of
selection.get_number_of_samples_ensemble()

Parameter ``selection:``:
    Structure containing information about which beams and samples to
    select.

Returns:
    xt::xtensor<uint16_t, 1>)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_get_sv =
R"doc(Compute volume backscattering. If you see this comment, this function
was not implemented for the current ping type.

Parameter ``dB``:
    Output Sv in dB if true, or linear if false (default).

Returns:
    xt::xtensor<float, 2>)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_get_sv_2 =
R"doc(Compute volume backscattering. If you see this comment, this function
was not implemented for the current ping type.

Parameter ``selection``:
    structure with selected beams/samples considered for this function

Parameter ``dB``:
    Output Sv in dB if true, or linear if false (default).

Returns:
    xt::xtensor<float, 1>)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_get_sv_stacked =
R"doc(Compute stacked volume backscattering (sum over all beams). If you see
this comment, this function was not implemented for the current ping
type.

Parameter ``selection``:
    structure with selected beams/samples considered for this function

Parameter ``dB``:
    Output Sv in dB if true, or linear if false (default).

Returns:
    xt::xtensor<float, 1>)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_get_timestamp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_has_angle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_has_bottom = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_has_sv = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_has_watercolumn = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_load = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_loaded = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_not_implemented = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_not_implemented_not_implemented = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_release = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_set_channel_id = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_set_geolocation = R"doc(Set the geolocation of the transducer.)doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_set_timestamp = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_timestamp = R"doc(< Unix timestamp in seconds (saved in UTC0))doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_watercolumn = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_filetemplates_datatypes_I_Ping_watercolumn_2 = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


