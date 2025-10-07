//sourcehash: 3012652e9971f1cbf9e3331451b4e48d7178978f7998d4939ba0ca6cf58099da

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


static const char *__doc__unnamed_class_at_themachinethatgoesping_echosounders_kongsbergall_types_hpp_165_67 = R"doc()doc";

static const char *__doc__unnamed_class_at_themachinethatgoesping_echosounders_kongsbergall_types_hpp_168_67 = R"doc()doc";

static const char *__doc__unnamed_class_at_themachinethatgoesping_echosounders_kongsbergall_types_hpp_171_67 = R"doc()doc";


static const char *__doc_themachinethatgoesping_echosounders_datagram_identifier_to_string = R"doc()doc";



static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_KongsbergAllDatagram_type_from_string = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_datagram_type_to_string = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllActiveSensor =
R"doc(This enum is used to identify the active sensor in the
InstallationParameters datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllActiveSensor_AttitudeVelocitySensor1 = R"doc(< UDP5)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllActiveSensor_AttitudeVelocitySensor2 = R"doc(< UDP6)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllActiveSensor_MotionSensor1 = R"doc(< COM2)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllActiveSensor_MotionSensor2 = R"doc(< COM3)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllActiveSensor_MultiCast1 = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllActiveSensor_MultiCast2 = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllActiveSensor_MultiCast3 = R"doc(<)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllActiveSensor_NotSet = R"doc(< this is not a valid value)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllActiveSensor_PositionSystem1 = R"doc(< COM1)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllActiveSensor_PositionSystem2 = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllActiveSensor_PositionSystem3 = R"doc(< UDP2 or COM4)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllActiveSensor_to_attitude_sensor_number =
R"doc(Convert a t_KongsbergAllActiveSensor to an attitude sensor number 0:
the enum value is not an attitude sensor 1-2: attitude sensor number

Parameter ``value``:
    $Returns:

int)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllDatagramIdentifier = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllDatagramIdentifier_AttitudeDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllDatagramIdentifier_CentralBeamsEchogram_NotImplemented = R"doc(< not yet implemented)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllDatagramIdentifier_ClockDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllDatagramIdentifier_DepthDatagram_NotImplemented = R"doc(< not yet implemented)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllDatagramIdentifier_DepthOrHeightDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllDatagramIdentifier_ExtraDetections = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllDatagramIdentifier_ExtraParameters = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllDatagramIdentifier_HeadingDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllDatagramIdentifier_InstallationParametersStart = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllDatagramIdentifier_InstallationParametersStop = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllDatagramIdentifier_MechanicalTransducerTilt_NotImplemented = R"doc(< not yet implemented)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllDatagramIdentifier_NetworkAttitudeVelocityDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllDatagramIdentifier_PUBISTResultOutput = R"doc(< not yet implemented)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllDatagramIdentifier_PUIDOutput = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllDatagramIdentifier_PUStatusOutput = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllDatagramIdentifier_PositionDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllDatagramIdentifier_QualityFactorDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllDatagramIdentifier_RawRangeAndAngle = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllDatagramIdentifier_RawRangeAndAngle_F_NotImplemented = R"doc(< not yet implemented)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllDatagramIdentifier_RawRangeAndAngle_f_NotImplemented = R"doc(< not yet implemented)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllDatagramIdentifier_RuntimeParameters = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllDatagramIdentifier_SeabedImageData = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllDatagramIdentifier_SeabedImageDatagram_NotImplemented = R"doc(< not yet implemented)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllDatagramIdentifier_SingleBeamEchoSounderDepth = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllDatagramIdentifier_SoundSpeedProfileDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllDatagramIdentifier_SurfaceSoundSpeedDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllDatagramIdentifier_TideDatagram_NotImplemented = R"doc(< not yet implemented)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllDatagramIdentifier_WatercolumnDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllDatagramIdentifier_XYZDatagram = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllDatagramIdentifier_unspecified = R"doc()doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllSystemTransducerConfiguration =
R"doc(This enum is used to identify the transducer configuration (STC field)
in the InstallationParameters datagram)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllSystemTransducerConfiguration_DualHead = R"doc(< EM3002 Dual Head, EM2040C Dual Head)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllSystemTransducerConfiguration_DualTXDualRX = R"doc(< EM2040 Dual TX)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllSystemTransducerConfiguration_Modular = R"doc(< EM2040M)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllSystemTransducerConfiguration_PortableSingleHead = R"doc(< EM2040P)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllSystemTransducerConfiguration_SingleHead = R"doc(< EM3002 Single Head, EM2040C Single Head)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllSystemTransducerConfiguration_SingleTXDualRX = R"doc(< EM2040 Dual RX)doc";

static const char *__doc_themachinethatgoesping_echosounders_kongsbergall_t_KongsbergAllSystemTransducerConfiguration_SingleTXSingleRX = R"doc(< EM122, EM302, EM710, EM2040 Single)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


