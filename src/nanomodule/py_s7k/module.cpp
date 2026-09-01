// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/string.h>

#include <sstream>
#include <tuple>
#include <vector>

#include <themachinethatgoesping/echosounders/s7k/types.hpp>
#include <themachinethatgoesping/tools_nanobind/enumhelper.hpp>

#include "module.hpp"

namespace nb = nanobind;
namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {

// -- submodule declarations --
void init_c_s7kdatagrams(nanobind::module_& m);          // c_s7kdatagrams.cpp
void init_c_s7kdatagramcontainer(nanobind::module_& m);  // c_s7kdatagramcontainer.cpp
void init_c_s7kdatagraminterface(nanobind::module_& m);  // c_s7kdatagraminterface.cpp
void init_c_s7kfilehandler(nanobind::module_& m);        // c_s7kfilehandler.cpp

// -- create submodule --
void init_m_s7k(nanobind::module_& m)
{
    using namespace s7k;

    // module description
    auto subm = m.def_submodule("s7k", "Classes related to Teledyne RESON .s7k (7k) data files");

    nb::enum_<t_S7KDatagramIdentifier>(
        subm,
        "t_S7KDatagramIdentifier",
        DOC(themachinethatgoesping, echosounders, s7k, t_S7KDatagramIdentifier))
        .value("R1000_ReferencePoint", t_S7KDatagramIdentifier::R1000_ReferencePoint, "1000 - Reference point")
        .value("R1001_SensorOffsetPosition", t_S7KDatagramIdentifier::R1001_SensorOffsetPosition, "1001 - Sensor offset position")
        .value("R1002_SensorOffsetPositionCalibrated", t_S7KDatagramIdentifier::R1002_SensorOffsetPositionCalibrated, "1002 - Sensor offset position calibrated")
        .value("R1003_Position", t_S7KDatagramIdentifier::R1003_Position, "1003 - Position")
        .value("R1004_CustomAttitudeInformation", t_S7KDatagramIdentifier::R1004_CustomAttitudeInformation, "1004 - Custom attitude information")
        .value("R1005_Tide", t_S7KDatagramIdentifier::R1005_Tide, "1005 - Tide")
        .value("R1006_Altitude", t_S7KDatagramIdentifier::R1006_Altitude, "1006 - Altitude")
        .value("R1007_MotionOverGround", t_S7KDatagramIdentifier::R1007_MotionOverGround, "1007 - Motion over ground")
        .value("R1008_Depth", t_S7KDatagramIdentifier::R1008_Depth, "1008 - Depth")
        .value("R1009_SoundVelocityProfile", t_S7KDatagramIdentifier::R1009_SoundVelocityProfile, "1009 - Sound velocity profile")
        .value("R1010_CTD", t_S7KDatagramIdentifier::R1010_CTD, "1010 - CTD")
        .value("R1011_Geodesy", t_S7KDatagramIdentifier::R1011_Geodesy, "1011 - Geodesy")
        .value("R1012_RollPitchHeave", t_S7KDatagramIdentifier::R1012_RollPitchHeave, "1012 - Roll pitch heave")
        .value("R1013_Heading", t_S7KDatagramIdentifier::R1013_Heading, "1013 - Heading")
        .value("R1014_SurveyLine", t_S7KDatagramIdentifier::R1014_SurveyLine, "1014 - Survey line")
        .value("R1015_Navigation", t_S7KDatagramIdentifier::R1015_Navigation, "1015 - Navigation")
        .value("R1016_Attitude", t_S7KDatagramIdentifier::R1016_Attitude, "1016 - Attitude")
        .value("R1017_PanTilt", t_S7KDatagramIdentifier::R1017_PanTilt, "1017 - Pan tilt")
        .value("R1020_SonarInstallationIdentifiers", t_S7KDatagramIdentifier::R1020_SonarInstallationIdentifiers, "1020 - Sonar installation identifiers")
        .value("R2004_SonarPipeEnvironment", t_S7KDatagramIdentifier::R2004_SonarPipeEnvironment, "2004 - Sonar pipe environment")
        .value("R3001_ContactOutput", t_S7KDatagramIdentifier::R3001_ContactOutput, "3001 - Contact output")
        .value("R7000_SonarSettings", t_S7KDatagramIdentifier::R7000_SonarSettings, "7000 - 7k sonar settings")
        .value("R7001_Configuration", t_S7KDatagramIdentifier::R7001_Configuration, "7001 - 7k configuration")
        .value("R7002_MatchFilter", t_S7KDatagramIdentifier::R7002_MatchFilter, "7002 - 7k match filter")
        .value("R7003_FirmwareAndHardwareConfiguration", t_S7KDatagramIdentifier::R7003_FirmwareAndHardwareConfiguration, "7003 - 7k firmware and hardware configuration")
        .value("R7004_BeamGeometry", t_S7KDatagramIdentifier::R7004_BeamGeometry, "7004 - 7k beam geometry")
        .value("R7006_BathymetricData", t_S7KDatagramIdentifier::R7006_BathymetricData, "7006 - 7k bathymetric data (deprecated, superseded by 7027)")
        .value("R7007_SideScanData", t_S7KDatagramIdentifier::R7007_SideScanData, "7007 - 7k side-scan data")
        .value("R7008_GenericWaterColumnData", t_S7KDatagramIdentifier::R7008_GenericWaterColumnData, "7008 - 7k generic water column data (deprecated, superseded by 7018/7028)")
        .value("R7009_VerticalDepth", t_S7KDatagramIdentifier::R7009_VerticalDepth, "7009 - Vertical depth")
        .value("R7010_TVGValues", t_S7KDatagramIdentifier::R7010_TVGValues, "7010 - TVG values")
        .value("R7011_ImageData", t_S7KDatagramIdentifier::R7011_ImageData, "7011 - 7k image data")
        .value("R7012_PingMotionData", t_S7KDatagramIdentifier::R7012_PingMotionData, "7012 - 7k ping motion data")
        .value("R7014_AdaptiveGate", t_S7KDatagramIdentifier::R7014_AdaptiveGate, "7014 - 7k adaptive gate")
        .value("R7017_DetectionDataSetup", t_S7KDatagramIdentifier::R7017_DetectionDataSetup, "7017 - 7k detection data setup (deprecated)")
        .value("R7018_BeamformedData", t_S7KDatagramIdentifier::R7018_BeamformedData, "7018 - 7k beamformed data (water column magnitude & phase)")
        .value("R7021_BuiltInTestEnvironmentData", t_S7KDatagramIdentifier::R7021_BuiltInTestEnvironmentData, "7021 - 7k built-in test environment data (BITE)")
        .value("R7022_SonarSourceVersion", t_S7KDatagramIdentifier::R7022_SonarSourceVersion, "7022 - 7k sonar source version")
        .value("R7023_WetEndVersion8k", t_S7KDatagramIdentifier::R7023_WetEndVersion8k, "7023 - 8k wet end version")
        .value("R7026_DetectionData", t_S7KDatagramIdentifier::R7026_DetectionData, "7026 - 7k detection data")
        .value("R7027_RawDetectionData", t_S7KDatagramIdentifier::R7027_RawDetectionData, "7027 - 7k raw detection data (bathymetry, preferred)")
        .value("R7028_SnippetData", t_S7KDatagramIdentifier::R7028_SnippetData, "7028 - 7k snippet data (water column)")
        .value("R7029_VernierProcessingDataFiltered", t_S7KDatagramIdentifier::R7029_VernierProcessingDataFiltered, "7029 - Vernier processing data (filtered)")
        .value("R7030_SonarInstallationParameters", t_S7KDatagramIdentifier::R7030_SonarInstallationParameters, "7030 - Sonar installation parameters")
        .value("R7031_BuiltInTestEnvironmentDataSummary", t_S7KDatagramIdentifier::R7031_BuiltInTestEnvironmentDataSummary, "7031 - 7k built-in test environment data (summary)")
        .value("R7041_CompressedBeamformedIntensityData", t_S7KDatagramIdentifier::R7041_CompressedBeamformedIntensityData, "7041 - Compressed beamformed intensity data")
        .value("R7042_CompressedWaterColumnData", t_S7KDatagramIdentifier::R7042_CompressedWaterColumnData, "7042 - Compressed water column data")
        .value("R7047_SegmentedRawDetectionData", t_S7KDatagramIdentifier::R7047_SegmentedRawDetectionData, "7047 - 7k segmented raw detection data")
        .value("R7048_CalibratedBeamData", t_S7KDatagramIdentifier::R7048_CalibratedBeamData, "7048 - 7k calibrated beam data")
        .value("R7050_SystemEvents", t_S7KDatagramIdentifier::R7050_SystemEvents, "7050 - 7k system events")
        .value("R7051_SystemEventMessage", t_S7KDatagramIdentifier::R7051_SystemEventMessage, "7051 - 7k system event message")
        .value("R7052_RDRRecordingStatus", t_S7KDatagramIdentifier::R7052_RDRRecordingStatus, "7052 - RDR recording status")
        .value("R7053_Subscriptions", t_S7KDatagramIdentifier::R7053_Subscriptions, "7053 - 7k subscriptions")
        .value("R7055_NormalizationStatus", t_S7KDatagramIdentifier::R7055_NormalizationStatus, "7055 - Normalization status")
        .value("R7057_CalibratedSideScanData", t_S7KDatagramIdentifier::R7057_CalibratedSideScanData, "7057 - Calibrated side-scan data")
        .value("R7058_SnippetBackscatteringStrength", t_S7KDatagramIdentifier::R7058_SnippetBackscatteringStrength, "7058 - Snippet backscattering strength")
        .value("R7059_MB2SpecificStatus", t_S7KDatagramIdentifier::R7059_MB2SpecificStatus, "7059 - MB2 specific status")
        .value("R7200_FileHeader", t_S7KDatagramIdentifier::R7200_FileHeader, "7200 - 7k file header")
        .value("R7300_FileCatalogRecord", t_S7KDatagramIdentifier::R7300_FileCatalogRecord, "7300 - 7k file catalogue record")
        .value("R7400_TimeMessage", t_S7KDatagramIdentifier::R7400_TimeMessage, "7400 - 7k time message")
        .value("R7500_RemoteControl", t_S7KDatagramIdentifier::R7500_RemoteControl, "7500 - 7k remote control")
        .value("R7501_RemoteControlAcknowledge", t_S7KDatagramIdentifier::R7501_RemoteControlAcknowledge, "7501 - 7k remote control acknowledge")
        .value("R7502_RemoteControlNotAcknowledge", t_S7KDatagramIdentifier::R7502_RemoteControlNotAcknowledge, "7502 - 7k remote control not acknowledge")
        .value("R7503_RemoteControlSonarSettings", t_S7KDatagramIdentifier::R7503_RemoteControlSonarSettings, "7503 - 7k remote control sonar settings")
        .value("R7504_SensorSettings7P", t_S7KDatagramIdentifier::R7504_SensorSettings7P, "7504 - 7P sensor settings")
        .value("R7510_SVFiltering", t_S7KDatagramIdentifier::R7510_SVFiltering, "7510 - SV filtering")
        .value("R7511_SystemLockStatus", t_S7KDatagramIdentifier::R7511_SystemLockStatus, "7511 - System lock status")
        .value("R7515_Timestamp", t_S7KDatagramIdentifier::R7515_Timestamp, "7515 - Timestamp")
        .value("R7610_SoundVelocity", t_S7KDatagramIdentifier::R7610_SoundVelocity, "7610 - 7k sound velocity")
        .value("R7611_AbsorptionLoss", t_S7KDatagramIdentifier::R7611_AbsorptionLoss, "7611 - 7k absorption loss")
        .value("R7612_SpreadingLoss", t_S7KDatagramIdentifier::R7612_SpreadingLoss, "7612 - 7k spreading loss")
        .value("R7613_ProfileAverageSalinity", t_S7KDatagramIdentifier::R7613_ProfileAverageSalinity, "7613 - Profile average salinity")
        .value("R7614_ProfileAverageTemperature", t_S7KDatagramIdentifier::R7614_ProfileAverageTemperature, "7614 - Profile average temperature")
        .value("R7777_FillerRecord", t_S7KDatagramIdentifier::R7777_FillerRecord, "7777 - Filler record (used when repairing corrupt files)")
        .value("R8100_Sonar8kSeriesData", t_S7KDatagramIdentifier::R8100_Sonar8kSeriesData, "8100 - 8k series sonar data")
        .value("unspecified", t_S7KDatagramIdentifier::unspecified, "unknown record type");

    themachinethatgoesping::tools::nanobind_helper::make_option_class<o_S7KDatagramIdentifier>(
        subm, "o_S7KDatagramIdentifier");

    subm.def("datagram_type_to_string",
             &datagram_type_to_string,
             DOC(themachinethatgoesping, echosounders, s7k, datagram_type_to_string),
             nb::arg("datagram_type"));
    subm.def("S7KDatagram_type_from_string",
             &S7KDatagram_type_from_string,
             DOC(themachinethatgoesping, echosounders, s7k, S7KDatagram_type_from_string),
             nb::arg("value"));

    // s7k classes
    init_c_s7kdatagrams(subm);
    init_c_s7kdatagramcontainer(subm);
    init_c_s7kdatagraminterface(subm);
    init_c_s7kfilehandler(subm);
}

}
}
}
}
