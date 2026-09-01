// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

/* generated doc strings */
#include ".docstrings/types.doc.hpp"

#include <array>
#include <set>
#include <string>
#include <string_view>
#include <vector>

#include <fmt/format.h>

#include <themachinethatgoesping/tools/classhelper/option_frozen.hpp>
#include <themachinethatgoesping/tools/helper/stringconversion.hpp>

/**
 * @brief Type definitions for Teledyne RESON .s7k (7k) data format.
 *
 * Record type identifiers according to the "7k Data Format Definition" specification
 * (v3.12, April 2020), Table 8: Record Type Definitions. A local copy of the specification
 * is stored in docs/s7k_format/.
 */

namespace themachinethatgoesping {
namespace echosounders {
namespace s7k {

/**
 * @brief 7k record type identifiers (the "record type" field of the Data Record Frame).
 *
 * The underlying value is the numeric record type as defined by the 7k specification.
 * The enum only lists the record types that are known/named; unknown record types are
 * still representable because the underlying type can hold any 32-bit value.
 */
enum class t_S7KDatagramIdentifier : uint32_t
{
    R1000_ReferencePoint = 1000, ///< Reference point
    R1001_SensorOffsetPosition = 1001, ///< Sensor offset position
    R1002_SensorOffsetPositionCalibrated = 1002, ///< Sensor offset position calibrated
    R1003_Position = 1003, ///< Position
    R1004_CustomAttitudeInformation = 1004, ///< Custom attitude information
    R1005_Tide = 1005, ///< Tide
    R1006_Altitude = 1006, ///< Altitude
    R1007_MotionOverGround = 1007, ///< Motion over ground
    R1008_Depth = 1008, ///< Depth
    R1009_SoundVelocityProfile = 1009, ///< Sound velocity profile
    R1010_CTD = 1010, ///< CTD
    R1011_Geodesy = 1011, ///< Geodesy
    R1012_RollPitchHeave = 1012, ///< Roll pitch heave
    R1013_Heading = 1013, ///< Heading
    R1014_SurveyLine = 1014, ///< Survey line
    R1015_Navigation = 1015, ///< Navigation
    R1016_Attitude = 1016, ///< Attitude
    R1017_PanTilt = 1017, ///< Pan tilt
    R1020_SonarInstallationIdentifiers = 1020, ///< Sonar installation identifiers
    R2004_SonarPipeEnvironment = 2004, ///< Sonar pipe environment
    R3001_ContactOutput = 3001, ///< Contact output
    R7000_SonarSettings = 7000, ///< 7k sonar settings
    R7001_Configuration = 7001, ///< 7k configuration
    R7002_MatchFilter = 7002, ///< 7k match filter
    R7003_FirmwareAndHardwareConfiguration = 7003, ///< 7k firmware and hardware configuration
    R7004_BeamGeometry = 7004, ///< 7k beam geometry
    R7006_BathymetricData = 7006, ///< 7k bathymetric data (deprecated, superseded by 7027)
    R7007_SideScanData = 7007, ///< 7k side-scan data
    R7008_GenericWaterColumnData = 7008, ///< 7k generic water column data (deprecated, superseded by 7018/7028)
    R7009_VerticalDepth = 7009, ///< Vertical depth
    R7010_TVGValues = 7010, ///< TVG values
    R7011_ImageData = 7011, ///< 7k image data
    R7012_PingMotionData = 7012, ///< 7k ping motion data
    R7014_AdaptiveGate = 7014, ///< 7k adaptive gate
    R7017_DetectionDataSetup = 7017, ///< 7k detection data setup (deprecated)
    R7018_BeamformedData = 7018, ///< 7k beamformed data (water column magnitude & phase)
    R7021_BuiltInTestEnvironmentData = 7021, ///< 7k built-in test environment data (BITE)
    R7022_SonarSourceVersion = 7022, ///< 7k sonar source version
    R7023_WetEndVersion8k = 7023, ///< 8k wet end version
    R7026_DetectionData = 7026, ///< 7k detection data
    R7027_RawDetectionData = 7027, ///< 7k raw detection data (bathymetry, preferred)
    R7028_SnippetData = 7028, ///< 7k snippet data (water column)
    R7029_VernierProcessingDataFiltered = 7029, ///< Vernier processing data (filtered)
    R7030_SonarInstallationParameters = 7030, ///< Sonar installation parameters
    R7031_BuiltInTestEnvironmentDataSummary = 7031, ///< 7k built-in test environment data (summary)
    R7041_CompressedBeamformedIntensityData = 7041, ///< Compressed beamformed intensity data
    R7042_CompressedWaterColumnData = 7042, ///< Compressed water column data
    R7047_SegmentedRawDetectionData = 7047, ///< 7k segmented raw detection data
    R7048_CalibratedBeamData = 7048, ///< 7k calibrated beam data
    R7050_SystemEvents = 7050, ///< 7k system events
    R7051_SystemEventMessage = 7051, ///< 7k system event message
    R7052_RDRRecordingStatus = 7052, ///< RDR recording status
    R7053_Subscriptions = 7053, ///< 7k subscriptions
    R7055_NormalizationStatus = 7055, ///< Normalization status
    R7057_CalibratedSideScanData = 7057, ///< Calibrated side-scan data
    R7058_SnippetBackscatteringStrength = 7058, ///< Snippet backscattering strength
    R7059_MB2SpecificStatus = 7059, ///< MB2 specific status
    R7200_FileHeader = 7200, ///< 7k file header
    R7300_FileCatalogRecord = 7300, ///< 7k file catalogue record
    R7400_TimeMessage = 7400, ///< 7k time message
    R7500_RemoteControl = 7500, ///< 7k remote control
    R7501_RemoteControlAcknowledge = 7501, ///< 7k remote control acknowledge
    R7502_RemoteControlNotAcknowledge = 7502, ///< 7k remote control not acknowledge
    R7503_RemoteControlSonarSettings = 7503, ///< 7k remote control sonar settings
    R7504_SensorSettings7P = 7504, ///< 7P sensor settings
    R7510_SVFiltering = 7510, ///< SV filtering
    R7511_SystemLockStatus = 7511, ///< System lock status
    R7515_Timestamp = 7515, ///< Timestamp
    R7610_SoundVelocity = 7610, ///< 7k sound velocity
    R7611_AbsorptionLoss = 7611, ///< 7k absorption loss
    R7612_SpreadingLoss = 7612, ///< 7k spreading loss
    R7613_ProfileAverageSalinity = 7613, ///< Profile average salinity
    R7614_ProfileAverageTemperature = 7614, ///< Profile average temperature
    R7777_FillerRecord = 7777, ///< Filler record (used when repairing corrupt files)
    R8100_Sonar8kSeriesData = 8100, ///< 8k series sonar data

    unspecified = std::numeric_limits<uint32_t>::max(), ///< placeholder for unknown record types
};

inline constexpr std::array<t_S7KDatagramIdentifier, 75> t_S7KDatagramIdentifier_values = {
    t_S7KDatagramIdentifier::R1000_ReferencePoint,
    t_S7KDatagramIdentifier::R1001_SensorOffsetPosition,
    t_S7KDatagramIdentifier::R1002_SensorOffsetPositionCalibrated,
    t_S7KDatagramIdentifier::R1003_Position,
    t_S7KDatagramIdentifier::R1004_CustomAttitudeInformation,
    t_S7KDatagramIdentifier::R1005_Tide,
    t_S7KDatagramIdentifier::R1006_Altitude,
    t_S7KDatagramIdentifier::R1007_MotionOverGround,
    t_S7KDatagramIdentifier::R1008_Depth,
    t_S7KDatagramIdentifier::R1009_SoundVelocityProfile,
    t_S7KDatagramIdentifier::R1010_CTD,
    t_S7KDatagramIdentifier::R1011_Geodesy,
    t_S7KDatagramIdentifier::R1012_RollPitchHeave,
    t_S7KDatagramIdentifier::R1013_Heading,
    t_S7KDatagramIdentifier::R1014_SurveyLine,
    t_S7KDatagramIdentifier::R1015_Navigation,
    t_S7KDatagramIdentifier::R1016_Attitude,
    t_S7KDatagramIdentifier::R1017_PanTilt,
    t_S7KDatagramIdentifier::R1020_SonarInstallationIdentifiers,
    t_S7KDatagramIdentifier::R2004_SonarPipeEnvironment,
    t_S7KDatagramIdentifier::R3001_ContactOutput,
    t_S7KDatagramIdentifier::R7000_SonarSettings,
    t_S7KDatagramIdentifier::R7001_Configuration,
    t_S7KDatagramIdentifier::R7002_MatchFilter,
    t_S7KDatagramIdentifier::R7003_FirmwareAndHardwareConfiguration,
    t_S7KDatagramIdentifier::R7004_BeamGeometry,
    t_S7KDatagramIdentifier::R7006_BathymetricData,
    t_S7KDatagramIdentifier::R7007_SideScanData,
    t_S7KDatagramIdentifier::R7008_GenericWaterColumnData,
    t_S7KDatagramIdentifier::R7009_VerticalDepth,
    t_S7KDatagramIdentifier::R7010_TVGValues,
    t_S7KDatagramIdentifier::R7011_ImageData,
    t_S7KDatagramIdentifier::R7012_PingMotionData,
    t_S7KDatagramIdentifier::R7014_AdaptiveGate,
    t_S7KDatagramIdentifier::R7017_DetectionDataSetup,
    t_S7KDatagramIdentifier::R7018_BeamformedData,
    t_S7KDatagramIdentifier::R7021_BuiltInTestEnvironmentData,
    t_S7KDatagramIdentifier::R7022_SonarSourceVersion,
    t_S7KDatagramIdentifier::R7023_WetEndVersion8k,
    t_S7KDatagramIdentifier::R7026_DetectionData,
    t_S7KDatagramIdentifier::R7027_RawDetectionData,
    t_S7KDatagramIdentifier::R7028_SnippetData,
    t_S7KDatagramIdentifier::R7029_VernierProcessingDataFiltered,
    t_S7KDatagramIdentifier::R7030_SonarInstallationParameters,
    t_S7KDatagramIdentifier::R7031_BuiltInTestEnvironmentDataSummary,
    t_S7KDatagramIdentifier::R7041_CompressedBeamformedIntensityData,
    t_S7KDatagramIdentifier::R7042_CompressedWaterColumnData,
    t_S7KDatagramIdentifier::R7047_SegmentedRawDetectionData,
    t_S7KDatagramIdentifier::R7048_CalibratedBeamData,
    t_S7KDatagramIdentifier::R7050_SystemEvents,
    t_S7KDatagramIdentifier::R7051_SystemEventMessage,
    t_S7KDatagramIdentifier::R7052_RDRRecordingStatus,
    t_S7KDatagramIdentifier::R7053_Subscriptions,
    t_S7KDatagramIdentifier::R7055_NormalizationStatus,
    t_S7KDatagramIdentifier::R7057_CalibratedSideScanData,
    t_S7KDatagramIdentifier::R7058_SnippetBackscatteringStrength,
    t_S7KDatagramIdentifier::R7059_MB2SpecificStatus,
    t_S7KDatagramIdentifier::R7200_FileHeader,
    t_S7KDatagramIdentifier::R7300_FileCatalogRecord,
    t_S7KDatagramIdentifier::R7400_TimeMessage,
    t_S7KDatagramIdentifier::R7500_RemoteControl,
    t_S7KDatagramIdentifier::R7501_RemoteControlAcknowledge,
    t_S7KDatagramIdentifier::R7502_RemoteControlNotAcknowledge,
    t_S7KDatagramIdentifier::R7503_RemoteControlSonarSettings,
    t_S7KDatagramIdentifier::R7504_SensorSettings7P,
    t_S7KDatagramIdentifier::R7510_SVFiltering,
    t_S7KDatagramIdentifier::R7511_SystemLockStatus,
    t_S7KDatagramIdentifier::R7515_Timestamp,
    t_S7KDatagramIdentifier::R7610_SoundVelocity,
    t_S7KDatagramIdentifier::R7611_AbsorptionLoss,
    t_S7KDatagramIdentifier::R7612_SpreadingLoss,
    t_S7KDatagramIdentifier::R7613_ProfileAverageSalinity,
    t_S7KDatagramIdentifier::R7614_ProfileAverageTemperature,
    t_S7KDatagramIdentifier::R7777_FillerRecord,
    t_S7KDatagramIdentifier::R8100_Sonar8kSeriesData,
};

inline constexpr std::array<std::string_view, 75> t_S7KDatagramIdentifier_names = {
    "R1000_ReferencePoint", "R1001_SensorOffsetPosition", "R1002_SensorOffsetPositionCalibrated", "R1003_Position",
    "R1004_CustomAttitudeInformation", "R1005_Tide", "R1006_Altitude", "R1007_MotionOverGround",
    "R1008_Depth", "R1009_SoundVelocityProfile", "R1010_CTD", "R1011_Geodesy",
    "R1012_RollPitchHeave", "R1013_Heading", "R1014_SurveyLine", "R1015_Navigation",
    "R1016_Attitude", "R1017_PanTilt", "R1020_SonarInstallationIdentifiers", "R2004_SonarPipeEnvironment",
    "R3001_ContactOutput", "R7000_SonarSettings", "R7001_Configuration", "R7002_MatchFilter",
    "R7003_FirmwareAndHardwareConfiguration", "R7004_BeamGeometry", "R7006_BathymetricData", "R7007_SideScanData",
    "R7008_GenericWaterColumnData", "R7009_VerticalDepth", "R7010_TVGValues", "R7011_ImageData",
    "R7012_PingMotionData", "R7014_AdaptiveGate", "R7017_DetectionDataSetup", "R7018_BeamformedData",
    "R7021_BuiltInTestEnvironmentData", "R7022_SonarSourceVersion", "R7023_WetEndVersion8k", "R7026_DetectionData",
    "R7027_RawDetectionData", "R7028_SnippetData", "R7029_VernierProcessingDataFiltered", "R7030_SonarInstallationParameters",
    "R7031_BuiltInTestEnvironmentDataSummary", "R7041_CompressedBeamformedIntensityData", "R7042_CompressedWaterColumnData", "R7047_SegmentedRawDetectionData",
    "R7048_CalibratedBeamData", "R7050_SystemEvents", "R7051_SystemEventMessage", "R7052_RDRRecordingStatus",
    "R7053_Subscriptions", "R7055_NormalizationStatus", "R7057_CalibratedSideScanData", "R7058_SnippetBackscatteringStrength",
    "R7059_MB2SpecificStatus", "R7200_FileHeader", "R7300_FileCatalogRecord", "R7400_TimeMessage",
    "R7500_RemoteControl", "R7501_RemoteControlAcknowledge", "R7502_RemoteControlNotAcknowledge", "R7503_RemoteControlSonarSettings",
    "R7504_SensorSettings7P", "R7510_SVFiltering", "R7511_SystemLockStatus", "R7515_Timestamp",
    "R7610_SoundVelocity", "R7611_AbsorptionLoss", "R7612_SpreadingLoss", "R7613_ProfileAverageSalinity",
    "R7614_ProfileAverageTemperature", "R7777_FillerRecord", "R8100_Sonar8kSeriesData"
};

// alternative names: the decimal record number as string
inline constexpr std::array<std::string_view, 75> t_S7KDatagramIdentifier_alt_names = {
    "1000", "1001", "1002", "1003",
    "1004", "1005", "1006", "1007",
    "1008", "1009", "1010", "1011",
    "1012", "1013", "1014", "1015",
    "1016", "1017", "1020", "2004",
    "3001", "7000", "7001", "7002",
    "7003", "7004", "7006", "7007",
    "7008", "7009", "7010", "7011",
    "7012", "7014", "7017", "7018",
    "7021", "7022", "7023", "7026",
    "7027", "7028", "7029", "7030",
    "7031", "7041", "7042", "7047",
    "7048", "7050", "7051", "7052",
    "7053", "7055", "7057", "7058",
    "7059", "7200", "7300", "7400",
    "7500", "7501", "7502", "7503",
    "7504", "7510", "7511", "7515",
    "7610", "7611", "7612", "7613",
    "7614", "7777", "8100"
};

using o_S7KDatagramIdentifier =
    themachinethatgoesping::tools::classhelper::OptionFrozen<t_S7KDatagramIdentifier,
                                                             t_S7KDatagramIdentifier_values.size(),
                                                             t_S7KDatagramIdentifier_values,
                                                             t_S7KDatagramIdentifier_names,
                                                             t_S7KDatagramIdentifier_alt_names>;

/**
 * @brief Test if a record type identifier is a known/named 7k record type.
 * @param value Record type identifier.
 * @return true if the identifier is a named record type, false otherwise.
 */
inline bool datagram_identifier_is_known(t_S7KDatagramIdentifier value)
{
    static const o_S7KDatagramIdentifier checker;
    return checker.enum_contains(static_cast<uint32_t>(value));
}

/**
 * @brief Convert a record type identifier to a descriptive name.
 * @param value Record type identifier.
 * @return The record type name (e.g. "R7027_RawDetectionData") or "unknown" if not a named type.
 */
inline std::string datagram_type_to_string(t_S7KDatagramIdentifier value)
{
    if (datagram_identifier_is_known(value))
        return std::string(o_S7KDatagramIdentifier(value).name());
    return "unknown";
}

/**
 * @brief Parse a record type identifier from its numeric string representation.
 * @param value String containing the decimal record number (e.g. "7027").
 * @return Parsed record type identifier.
 */
inline t_S7KDatagramIdentifier S7KDatagram_type_from_string(std::string_view value)
{
    return static_cast<t_S7KDatagramIdentifier>(tools::helper::string_as_int<uint32_t>(value));
}

} // namespace s7k

// ----- interface utility functions (used by the generic datagram interface) -----

// IGNORE_DOC:mkd_doc_themachinethatgoesping_echosounders_datagram_identifier_to_string
inline std::string datagram_identifier_to_string(s7k::t_S7KDatagramIdentifier value)
{
    return tools::helper::int_as_string<uint32_t>(uint32_t(value));
}

// IGNORE_DOC:mkd_doc_themachinethatgoesping_echosounders_datagram_identifier_info
inline std::string datagram_identifier_info(s7k::t_S7KDatagramIdentifier datagram_type)
{
    return s7k::datagram_type_to_string(datagram_type);
}

} // namespace echosounders
} // namespace themachinethatgoesping

extern template struct themachinethatgoesping::tools::classhelper::OptionFrozen<
    themachinethatgoesping::echosounders::s7k::t_S7KDatagramIdentifier,
    themachinethatgoesping::echosounders::s7k::t_S7KDatagramIdentifier_values.size(),
    themachinethatgoesping::echosounders::s7k::t_S7KDatagramIdentifier_values,
    themachinethatgoesping::echosounders::s7k::t_S7KDatagramIdentifier_names,
    themachinethatgoesping::echosounders::s7k::t_S7KDatagramIdentifier_alt_names>;
