//sourcehash: 88fcdbcdf10eb07d7b1e49ae3759ca6caee797ddc0beefbc3c0f81f617fc3391

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


static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram =
R"doc(The Quality Factor is an estimate of the standard deviation of the
detected depth. QF = − log(Est(dz)/z) QF = 3.0 means an estimated
standard deviation of 0.1% of the detected depth. QF = 2.0 means an
estimated standard deviation of 1.0% of the detected depth. QF = 0
means that the Quality Factor could not be computed. The Quality
Factor is calculated by the echo sounder according to formulas
provided by IFREMER. Used for EM 122, EM 302, EM 710, EM 2040, EM
2040C, EM 3002 and ME70BO.)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_QualityFactorDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_QualityFactorDatagram_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_etx = R"doc(< end identifier (always 0x03))doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_from_stream = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_from_stream_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_from_stream_3 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_get_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_get_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_get_number_of_parameters_per_beam = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_get_number_of_receive_beams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_get_ping_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_get_quality_factors = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_get_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_get_spare_byte = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_get_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_number_of_parameters_per_beam = R"doc(< Npar)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_number_of_receive_beams = R"doc(< Nrx)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_operator_eq = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_ping_counter = R"doc(< 0-65535 ping number (in this file))doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_printer = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_qf_shape =
R"doc(return the shape of the quality factor array Computed as
[_number_of_receive_beams, _number_of_parameters_per_beam]

Returns:
    xt::xtensor<float, 2>::shape_type)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_quality_factors = R"doc(< dimension is [Nrx, Npar])doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_quality_factors_2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_set_checksum = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_set_etx = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_set_number_of_parameters_per_beam = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_set_number_of_receive_beams = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_set_ping_counter = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_set_quality_factors = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_set_spare = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_set_spare_byte = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_set_system_serial_number = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_spare = R"doc(< always 0)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_spare_byte = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_system_serial_number = R"doc(< 100 -)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


