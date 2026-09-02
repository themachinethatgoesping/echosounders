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
    ReferencePoint                   = 1000, ///< Reference point
    SensorOffsetPosition             = 1001, ///< Sensor offset position
    SensorOffsetPositionCalibrated   = 1002, ///< Sensor offset position calibrated
    Position                         = 1003, ///< Position
    CustomAttitudeInformation        = 1004, ///< Custom attitude information
    Tide                             = 1005, ///< Tide
    Altitude                         = 1006, ///< Altitude
    MotionOverGround                 = 1007, ///< Motion over ground
    Depth                            = 1008, ///< Depth
    SoundVelocityProfile             = 1009, ///< Sound velocity profile
    CTD                              = 1010, ///< CTD
    Geodesy                          = 1011, ///< Geodesy
    RollPitchHeave                   = 1012, ///< Roll pitch heave
    Heading                          = 1013, ///< Heading
    SurveyLine                       = 1014, ///< Survey line
    Navigation                       = 1015, ///< Navigation
    Attitude                         = 1016, ///< Attitude
    PanTilt                          = 1017, ///< Pan tilt
    SonarInstallationIdentifiers     = 1020, ///< Sonar installation identifiers
    SonarPipeEnvironment             = 2004, ///< Sonar pipe environment
    ContactOutput                    = 3001, ///< Contact output
    SonarSettings                    = 7000, ///< 7k sonar settings
    Configuration                    = 7001, ///< 7k configuration
    MatchFilter                      = 7002, ///< 7k match filter
    FirmwareAndHardwareConfiguration = 7003, ///< 7k firmware and hardware configuration
    BeamGeometry                     = 7004, ///< 7k beam geometry
    BathymetricData = 7006, ///< 7k bathymetric data (deprecated, superseded by 7027)
    SideScanData    = 7007, ///< 7k side-scan data
    GenericWaterColumnData =
        7008, ///< 7k generic water column data (deprecated, superseded by 7018/7028)
    VerticalDepth                 = 7009, ///< Vertical depth
    TVGValues                     = 7010, ///< TVG values
    ImageData                     = 7011, ///< 7k image data
    PingMotionData                = 7012, ///< 7k ping motion data
    AdaptiveGate                  = 7014, ///< 7k adaptive gate
    DetectionDataSetup            = 7017, ///< 7k detection data setup (deprecated)
    BeamformedData                = 7018, ///< 7k beamformed data (water column magnitude & phase)
    BuiltInTestEnvironmentData    = 7021, ///< 7k built-in test environment data (BITE)
    SonarSourceVersion            = 7022, ///< 7k sonar source version
    WetEndVersion8k               = 7023, ///< 8k wet end version
    DetectionData                 = 7026, ///< 7k detection data
    RawDetectionData              = 7027, ///< 7k raw detection data (bathymetry, preferred)
    SnippetData                   = 7028, ///< 7k snippet data (water column)
    VernierProcessingDataFiltered = 7029, ///< Vernier processing data (filtered)
    SonarInstallationParameters   = 7030, ///< Sonar installation parameters
    BuiltInTestEnvironmentDataSummary = 7031, ///< 7k built-in test environment data (summary)
    CompressedBeamformedIntensityData = 7041, ///< Compressed beamformed intensity data
    CompressedWaterColumnData         = 7042, ///< Compressed water column data
    SegmentedRawDetectionData         = 7047, ///< 7k segmented raw detection data
    CalibratedBeamData                = 7048, ///< 7k calibrated beam data
    SystemEvents                      = 7050, ///< 7k system events
    SystemEventMessage                = 7051, ///< 7k system event message
    RDRRecordingStatus                = 7052, ///< RDR recording status
    Subscriptions                     = 7053, ///< 7k subscriptions
    NormalizationStatus               = 7055, ///< Normalization status
    CalibratedSideScanData            = 7057, ///< Calibrated side-scan data
    SnippetBackscatteringStrength     = 7058, ///< Snippet backscattering strength
    MB2SpecificStatus                 = 7059, ///< MB2 specific status
    FileHeader                        = 7200, ///< 7k file header
    FileCatalogRecord                 = 7300, ///< 7k file catalogue record
    TimeMessage                       = 7400, ///< 7k time message
    RemoteControl                     = 7500, ///< 7k remote control
    RemoteControlAcknowledge          = 7501, ///< 7k remote control acknowledge
    RemoteControlNotAcknowledge       = 7502, ///< 7k remote control not acknowledge
    RemoteControlSonarSettings        = 7503, ///< 7k remote control sonar settings
    SensorSettings7P                  = 7504, ///< 7P sensor settings
    SVFiltering                       = 7510, ///< SV filtering
    SystemLockStatus                  = 7511, ///< System lock status
    Timestamp                         = 7515, ///< Timestamp
    SoundVelocity                     = 7610, ///< 7k sound velocity
    AbsorptionLoss                    = 7611, ///< 7k absorption loss
    SpreadingLoss                     = 7612, ///< 7k spreading loss
    ProfileAverageSalinity            = 7613, ///< Profile average salinity
    ProfileAverageTemperature         = 7614, ///< Profile average temperature
    FillerRecord                      = 7777, ///< Filler record (used when repairing corrupt files)
    Sonar8kSeriesData                 = 8100, ///< 8k series sonar data

    unspecified = std::numeric_limits<uint32_t>::max(), ///< placeholder for unknown record types
};

inline constexpr std::array<t_S7KDatagramIdentifier, 75> t_S7KDatagramIdentifier_values = {
    t_S7KDatagramIdentifier::ReferencePoint,
    t_S7KDatagramIdentifier::SensorOffsetPosition,
    t_S7KDatagramIdentifier::SensorOffsetPositionCalibrated,
    t_S7KDatagramIdentifier::Position,
    t_S7KDatagramIdentifier::CustomAttitudeInformation,
    t_S7KDatagramIdentifier::Tide,
    t_S7KDatagramIdentifier::Altitude,
    t_S7KDatagramIdentifier::MotionOverGround,
    t_S7KDatagramIdentifier::Depth,
    t_S7KDatagramIdentifier::SoundVelocityProfile,
    t_S7KDatagramIdentifier::CTD,
    t_S7KDatagramIdentifier::Geodesy,
    t_S7KDatagramIdentifier::RollPitchHeave,
    t_S7KDatagramIdentifier::Heading,
    t_S7KDatagramIdentifier::SurveyLine,
    t_S7KDatagramIdentifier::Navigation,
    t_S7KDatagramIdentifier::Attitude,
    t_S7KDatagramIdentifier::PanTilt,
    t_S7KDatagramIdentifier::SonarInstallationIdentifiers,
    t_S7KDatagramIdentifier::SonarPipeEnvironment,
    t_S7KDatagramIdentifier::ContactOutput,
    t_S7KDatagramIdentifier::SonarSettings,
    t_S7KDatagramIdentifier::Configuration,
    t_S7KDatagramIdentifier::MatchFilter,
    t_S7KDatagramIdentifier::FirmwareAndHardwareConfiguration,
    t_S7KDatagramIdentifier::BeamGeometry,
    t_S7KDatagramIdentifier::BathymetricData,
    t_S7KDatagramIdentifier::SideScanData,
    t_S7KDatagramIdentifier::GenericWaterColumnData,
    t_S7KDatagramIdentifier::VerticalDepth,
    t_S7KDatagramIdentifier::TVGValues,
    t_S7KDatagramIdentifier::ImageData,
    t_S7KDatagramIdentifier::PingMotionData,
    t_S7KDatagramIdentifier::AdaptiveGate,
    t_S7KDatagramIdentifier::DetectionDataSetup,
    t_S7KDatagramIdentifier::BeamformedData,
    t_S7KDatagramIdentifier::BuiltInTestEnvironmentData,
    t_S7KDatagramIdentifier::SonarSourceVersion,
    t_S7KDatagramIdentifier::WetEndVersion8k,
    t_S7KDatagramIdentifier::DetectionData,
    t_S7KDatagramIdentifier::RawDetectionData,
    t_S7KDatagramIdentifier::SnippetData,
    t_S7KDatagramIdentifier::VernierProcessingDataFiltered,
    t_S7KDatagramIdentifier::SonarInstallationParameters,
    t_S7KDatagramIdentifier::BuiltInTestEnvironmentDataSummary,
    t_S7KDatagramIdentifier::CompressedBeamformedIntensityData,
    t_S7KDatagramIdentifier::CompressedWaterColumnData,
    t_S7KDatagramIdentifier::SegmentedRawDetectionData,
    t_S7KDatagramIdentifier::CalibratedBeamData,
    t_S7KDatagramIdentifier::SystemEvents,
    t_S7KDatagramIdentifier::SystemEventMessage,
    t_S7KDatagramIdentifier::RDRRecordingStatus,
    t_S7KDatagramIdentifier::Subscriptions,
    t_S7KDatagramIdentifier::NormalizationStatus,
    t_S7KDatagramIdentifier::CalibratedSideScanData,
    t_S7KDatagramIdentifier::SnippetBackscatteringStrength,
    t_S7KDatagramIdentifier::MB2SpecificStatus,
    t_S7KDatagramIdentifier::FileHeader,
    t_S7KDatagramIdentifier::FileCatalogRecord,
    t_S7KDatagramIdentifier::TimeMessage,
    t_S7KDatagramIdentifier::RemoteControl,
    t_S7KDatagramIdentifier::RemoteControlAcknowledge,
    t_S7KDatagramIdentifier::RemoteControlNotAcknowledge,
    t_S7KDatagramIdentifier::RemoteControlSonarSettings,
    t_S7KDatagramIdentifier::SensorSettings7P,
    t_S7KDatagramIdentifier::SVFiltering,
    t_S7KDatagramIdentifier::SystemLockStatus,
    t_S7KDatagramIdentifier::Timestamp,
    t_S7KDatagramIdentifier::SoundVelocity,
    t_S7KDatagramIdentifier::AbsorptionLoss,
    t_S7KDatagramIdentifier::SpreadingLoss,
    t_S7KDatagramIdentifier::ProfileAverageSalinity,
    t_S7KDatagramIdentifier::ProfileAverageTemperature,
    t_S7KDatagramIdentifier::FillerRecord,
    t_S7KDatagramIdentifier::Sonar8kSeriesData,
};

inline constexpr std::array<std::string_view, 75> t_S7KDatagramIdentifier_names = {
    "ReferencePoint",
    "SensorOffsetPosition",
    "SensorOffsetPositionCalibrated",
    "Position",
    "CustomAttitudeInformation",
    "Tide",
    "Altitude",
    "MotionOverGround",
    "Depth",
    "SoundVelocityProfile",
    "CTD",
    "Geodesy",
    "RollPitchHeave",
    "Heading",
    "SurveyLine",
    "Navigation",
    "Attitude",
    "PanTilt",
    "SonarInstallationIdentifiers",
    "SonarPipeEnvironment",
    "ContactOutput",
    "SonarSettings",
    "Configuration",
    "MatchFilter",
    "FirmwareAndHardwareConfiguration",
    "BeamGeometry",
    "BathymetricData",
    "SideScanData",
    "GenericWaterColumnData",
    "VerticalDepth",
    "TVGValues",
    "ImageData",
    "PingMotionData",
    "AdaptiveGate",
    "DetectionDataSetup",
    "BeamformedData",
    "BuiltInTestEnvironmentData",
    "SonarSourceVersion",
    "WetEndVersion8k",
    "DetectionData",
    "RawDetectionData",
    "SnippetData",
    "VernierProcessingDataFiltered",
    "SonarInstallationParameters",
    "BuiltInTestEnvironmentDataSummary",
    "CompressedBeamformedIntensityData",
    "CompressedWaterColumnData",
    "SegmentedRawDetectionData",
    "CalibratedBeamData",
    "SystemEvents",
    "SystemEventMessage",
    "RDRRecordingStatus",
    "Subscriptions",
    "NormalizationStatus",
    "CalibratedSideScanData",
    "SnippetBackscatteringStrength",
    "MB2SpecificStatus",
    "FileHeader",
    "FileCatalogRecord",
    "TimeMessage",
    "RemoteControl",
    "RemoteControlAcknowledge",
    "RemoteControlNotAcknowledge",
    "RemoteControlSonarSettings",
    "SensorSettings7P",
    "SVFiltering",
    "SystemLockStatus",
    "Timestamp",
    "SoundVelocity",
    "AbsorptionLoss",
    "SpreadingLoss",
    "ProfileAverageSalinity",
    "ProfileAverageTemperature",
    "FillerRecord",
    "Sonar8kSeriesData"
};

// alternative names: the decimal record number as string
inline constexpr std::array<std::string_view, 75> t_S7KDatagramIdentifier_alt_names = {
    "1000", "1001", "1002", "1003", "1004", "1005", "1006", "1007", "1008", "1009", "1010",
    "1011", "1012", "1013", "1014", "1015", "1016", "1017", "1020", "2004", "3001", "7000",
    "7001", "7002", "7003", "7004", "7006", "7007", "7008", "7009", "7010", "7011", "7012",
    "7014", "7017", "7018", "7021", "7022", "7023", "7026", "7027", "7028", "7029", "7030",
    "7031", "7041", "7042", "7047", "7048", "7050", "7051", "7052", "7053", "7055", "7057",
    "7058", "7059", "7200", "7300", "7400", "7500", "7501", "7502", "7503", "7504", "7510",
    "7511", "7515", "7610", "7611", "7612", "7613", "7614", "7777", "8100"
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
 * @return The record type name (e.g. "RawDetectionData") or "unknown" if not a named type.
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
