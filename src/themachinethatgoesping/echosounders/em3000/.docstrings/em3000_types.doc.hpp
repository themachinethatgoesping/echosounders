//sourcehash: 5dcee0302af762eebc254fd54c75e729138c8299ef06755e1ccb04f4e6586571

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


static const char *__doc_themachinethatgoesping_echosounders_datagram_identifier_info = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_datagram_identifier_to_string = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_EM3000Datagram_type_from_string = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_datagram_type_to_string = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_AttitudeDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_ClockDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_DepthOrHeightDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_ExtraDetections = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_ExtraParameters = R"doc(< TODO: implement!)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_HeadingDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_InstallationParameterStart = R"doc(< TODO: implement!)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_InstallationParameterStop = R"doc(< TODO: implement!)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_NetworkAttitudeVelocityDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_PUIDOutput = R"doc(< TODO: implement!)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_PositionDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_PuStatusOutput = R"doc(< TODO: implement!)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_QualityFactorDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_RawRangeAndAngle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_RuntimeParameters = R"doc(< TODO: implement!)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_SeabedImageData = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_SingleBeamEchoSounderDepth = R"doc(< TODO: implement!)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_SoundSpeedProfileDatagram = R"doc(< TODO: implement!)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_SurfaceSoundSpeedDatagram = R"doc(< TODO: implement!)doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_WaterColumnDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_XYZDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_em3000_t_EM3000DatagramIdentifier_unspecified = R"doc()doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


