//sourcehash: 5b1192f72a35a897c99647598cd92bb495b3cad78a419d5c453cc80642a19e67

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


static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram =
R"doc(The Quality Factor is an estimate of the standard deviation of the
detected depth. QF = − log(Est(dz)/z) QF = 3.0 means an estimated
standard deviation of 0.1% of the detected depth. QF = 2.0 means an
estimated standard deviation of 1.0% of the detected depth. QF = 0
means that the Quality Factor could not be computed. The Quality
Factor is calculated by the echo sounder according to formulas
provided by IFREMER. Used for EM 122, EM 302, EM 710, EM 2040, EM
2040C, EM 3002 and ME70BO.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_QualityFactorDatagram = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_QualityFactorDatagram_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_STREAM_DEFAULT_TOFROM_BINARY_FUNCTIONS_NOT_CONST = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_checksum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_etx = R"doc(end identifier (always 0x03))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_from_stream = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_from_stream_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_from_stream_3 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_get_checksum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_get_etx = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_get_number_of_parameters_per_beam = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_get_number_of_receive_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_get_ping_counter = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_get_quality_factors = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_get_spare = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_get_spare_byte = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_get_system_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_number_of_parameters_per_beam = R"doc(Npar)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_number_of_receive_beams = R"doc(Nrx)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_operator_eq = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_ping_counter = R"doc(0-65535 ping number (in this file))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_printer = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_qf_shape =
R"doc(return the shape of the quality factor array Computed as
[_number_of_receive_beams, _number_of_parameters_per_beam]

Returns:
    xt::xtensor<float, 2>::shape_type)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_quality_factors = R"doc(dimension is [Nrx, Npar])doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_quality_factors_2 = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_set_checksum = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_set_etx = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_set_number_of_parameters_per_beam = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_set_number_of_receive_beams = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_set_ping_counter = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_set_quality_factors = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_set_spare = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_set_spare_byte = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_set_system_serial_number = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_spare = R"doc(always 0)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_spare_byte = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_system_serial_number = R"doc(100 -)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_kongsbergall_datagrams_QualityFactorDatagram_to_stream = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


