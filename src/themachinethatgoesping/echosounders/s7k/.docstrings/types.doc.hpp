//sourcehash: e69d7a6da956966b1482225bd5b08af10f841a611cebfb76e245bf8e046cd56d

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


static const char *mkd_doc__unnamed_struct_at_themachinethatgoesping_echosounders_s7k_types_hpp_348_68 = R"doc()doc";



static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_S7KDatagram_type_from_string =
R"doc(Parse a record type identifier from its numeric string representation.
Args:
    value: String containing the decimal record number (e.g. "7027").

Returns:
    Parsed record type identifier.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagram_identifier_is_known =
R"doc(Test if a record type identifier is a known/named 7k record type.
Args:
    value: Record type identifier.

Returns:
    true if the identifier is a named record type, false otherwise.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_datagram_type_to_string =
R"doc(Convert a record type identifier to a descriptive name.
Args:
    value: Record type identifier.

Returns:
    The record type name (e.g. "RawDetectionData") or "unknown" if not
    a named type.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier =
R"doc(7k record type identifiers (the "record type" field of the Data Record
Frame).

The underlying value is the numeric record type as defined by the 7k
specification. The enum only lists the record types that are
known/named; unknown record types are still representable because the
underlying type can hold any 32-bit value.)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_AbsorptionLoss = R"doc(7k absorption loss)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_AdaptiveGate = R"doc(7k adaptive gate)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_Altitude = R"doc(Altitude)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_Attitude = R"doc(Attitude)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_BathymetricData = R"doc(7k bathymetric data (deprecated, superseded by 7027))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_BeamGeometry = R"doc(7k beam geometry)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_BeamformedData = R"doc(7k beamformed data (water column magnitude & phase))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_BuiltInTestEnvironmentData = R"doc(7k built-in test environment data (BITE))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_BuiltInTestEnvironmentDataSummary = R"doc(7k built-in test environment data (summary))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_CTD = R"doc(CTD)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_CalibratedBeamData = R"doc(7k calibrated beam data)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_CalibratedSideScanData = R"doc(Calibrated side-scan data)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_CompressedBeamformedIntensityData = R"doc(Compressed beamformed intensity data)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_CompressedWaterColumnData = R"doc(Compressed water column data)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_Configuration = R"doc(7k configuration)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_ContactOutput = R"doc(Contact output)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_CustomAttitudeInformation = R"doc(Custom attitude information)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_Depth = R"doc(Depth)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_DetectionData = R"doc(7k detection data)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_DetectionDataSetup = R"doc(7k detection data setup (deprecated))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_FileCatalogRecord = R"doc(7k file catalogue record)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_FileHeader = R"doc(7k file header)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_FillerRecord = R"doc(Filler record (used when repairing corrupt files))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_FirmwareAndHardwareConfiguration = R"doc(7k firmware and hardware configuration)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_GenericWaterColumnData = R"doc()doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_Geodesy = R"doc(Geodesy)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_Heading = R"doc(Heading)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_ImageData = R"doc(7k image data)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_MB2SpecificStatus = R"doc(MB2 specific status)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_MatchFilter = R"doc(7k match filter)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_MotionOverGround = R"doc(Motion over ground)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_Navigation = R"doc(Navigation)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_NormalizationStatus = R"doc(Normalization status)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_PanTilt = R"doc(Pan tilt)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_PingMotionData = R"doc(7k ping motion data)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_Position = R"doc(Position)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_ProfileAverageSalinity = R"doc(Profile average salinity)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_ProfileAverageTemperature = R"doc(Profile average temperature)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_RDRRecordingStatus = R"doc(RDR recording status)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_RawDetectionData = R"doc(7k raw detection data (bathymetry, preferred))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_ReferencePoint = R"doc(Reference point)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_RemoteControl = R"doc(7k remote control)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_RemoteControlAcknowledge = R"doc(7k remote control acknowledge)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_RemoteControlNotAcknowledge = R"doc(7k remote control not acknowledge)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_RemoteControlSonarSettings = R"doc(7k remote control sonar settings)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_RollPitchHeave = R"doc(Roll pitch heave)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_SVFiltering = R"doc(SV filtering)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_SegmentedRawDetectionData = R"doc(7k segmented raw detection data)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_SensorOffsetPosition = R"doc(Sensor offset position)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_SensorOffsetPositionCalibrated = R"doc(Sensor offset position calibrated)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_SensorSettings7P = R"doc(7P sensor settings)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_SideScanData = R"doc(7k side-scan data)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_SnippetBackscatteringStrength = R"doc(Snippet backscattering strength)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_SnippetData = R"doc(7k snippet data (water column))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_Sonar8kSeriesData = R"doc(8k series sonar data)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_SonarInstallationIdentifiers = R"doc(Sonar installation identifiers)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_SonarInstallationParameters = R"doc(Sonar installation parameters)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_SonarPipeEnvironment = R"doc(Sonar pipe environment)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_SonarSettings = R"doc(7k sonar settings)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_SonarSourceVersion = R"doc(7k sonar source version)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_SoundVelocity = R"doc(7k sound velocity)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_SoundVelocityProfile = R"doc(Sound velocity profile)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_SpreadingLoss = R"doc(7k spreading loss)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_Subscriptions = R"doc(7k subscriptions)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_SurveyLine = R"doc(Survey line)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_SystemEventMessage = R"doc(7k system event message)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_SystemEvents = R"doc(7k system events)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_SystemLockStatus = R"doc(System lock status)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_TVGValues = R"doc(TVG values)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_Tide = R"doc(Tide)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_TimeMessage = R"doc(7k time message)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_Timestamp = R"doc(Timestamp)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_VernierProcessingDataFiltered = R"doc(Vernier processing data (filtered))doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_VerticalDepth = R"doc(Vertical depth)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_WetEndVersion8k = R"doc(8k wet end version)doc";

static const char *mkd_doc_themachinethatgoesping_echosounders_s7k_t_S7KDatagramIdentifier_unspecified = R"doc(placeholder for unknown record types)doc";

#if defined(__GNUG__)
#pragma GCC diagnostic pop
#endif


