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

#include "py_datagrams/module.hpp"
#include "py_filedatacontainers/module.hpp"
#include "py_filedatainterfaces/module.hpp"

namespace nb = nanobind;
namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {

// -- submodule declarations --
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
        .value("ReferencePoint", t_S7KDatagramIdentifier::ReferencePoint, "1000 - Reference point")
        .value("SensorOffsetPosition", t_S7KDatagramIdentifier::SensorOffsetPosition, "1001 - Sensor offset position")
        .value("SensorOffsetPositionCalibrated", t_S7KDatagramIdentifier::SensorOffsetPositionCalibrated, "1002 - Sensor offset position calibrated")
        .value("Position", t_S7KDatagramIdentifier::Position, "1003 - Position")
        .value("CustomAttitudeInformation", t_S7KDatagramIdentifier::CustomAttitudeInformation, "1004 - Custom attitude information")
        .value("Tide", t_S7KDatagramIdentifier::Tide, "1005 - Tide")
        .value("Altitude", t_S7KDatagramIdentifier::Altitude, "1006 - Altitude")
        .value("MotionOverGround", t_S7KDatagramIdentifier::MotionOverGround, "1007 - Motion over ground")
        .value("Depth", t_S7KDatagramIdentifier::Depth, "1008 - Depth")
        .value("SoundVelocityProfile", t_S7KDatagramIdentifier::SoundVelocityProfile, "1009 - Sound velocity profile")
        .value("CTD", t_S7KDatagramIdentifier::CTD, "1010 - CTD")
        .value("Geodesy", t_S7KDatagramIdentifier::Geodesy, "1011 - Geodesy")
        .value("RollPitchHeave", t_S7KDatagramIdentifier::RollPitchHeave, "1012 - Roll pitch heave")
        .value("Heading", t_S7KDatagramIdentifier::Heading, "1013 - Heading")
        .value("SurveyLine", t_S7KDatagramIdentifier::SurveyLine, "1014 - Survey line")
        .value("Navigation", t_S7KDatagramIdentifier::Navigation, "1015 - Navigation")
        .value("Attitude", t_S7KDatagramIdentifier::Attitude, "1016 - Attitude")
        .value("PanTilt", t_S7KDatagramIdentifier::PanTilt, "1017 - Pan tilt")
        .value("SonarInstallationIdentifiers", t_S7KDatagramIdentifier::SonarInstallationIdentifiers, "1020 - Sonar installation identifiers")
        .value("SonarPipeEnvironment", t_S7KDatagramIdentifier::SonarPipeEnvironment, "2004 - Sonar pipe environment")
        .value("ContactOutput", t_S7KDatagramIdentifier::ContactOutput, "3001 - Contact output")
        .value("SonarSettings", t_S7KDatagramIdentifier::SonarSettings, "7000 - 7k sonar settings")
        .value("Configuration", t_S7KDatagramIdentifier::Configuration, "7001 - 7k configuration")
        .value("MatchFilter", t_S7KDatagramIdentifier::MatchFilter, "7002 - 7k match filter")
        .value("FirmwareAndHardwareConfiguration", t_S7KDatagramIdentifier::FirmwareAndHardwareConfiguration, "7003 - 7k firmware and hardware configuration")
        .value("BeamGeometry", t_S7KDatagramIdentifier::BeamGeometry, "7004 - 7k beam geometry")
        .value("BathymetricData", t_S7KDatagramIdentifier::BathymetricData, "7006 - 7k bathymetric data (deprecated, superseded by 7027)")
        .value("SideScanData", t_S7KDatagramIdentifier::SideScanData, "7007 - 7k side-scan data")
        .value("GenericWaterColumnData", t_S7KDatagramIdentifier::GenericWaterColumnData, "7008 - 7k generic water column data (deprecated, superseded by 7018/7028)")
        .value("VerticalDepth", t_S7KDatagramIdentifier::VerticalDepth, "7009 - Vertical depth")
        .value("TVGValues", t_S7KDatagramIdentifier::TVGValues, "7010 - TVG values")
        .value("ImageData", t_S7KDatagramIdentifier::ImageData, "7011 - 7k image data")
        .value("PingMotionData", t_S7KDatagramIdentifier::PingMotionData, "7012 - 7k ping motion data")
        .value("AdaptiveGate", t_S7KDatagramIdentifier::AdaptiveGate, "7014 - 7k adaptive gate")
        .value("DetectionDataSetup", t_S7KDatagramIdentifier::DetectionDataSetup, "7017 - 7k detection data setup (deprecated)")
        .value("BeamformedData", t_S7KDatagramIdentifier::BeamformedData, "7018 - 7k beamformed data (water column magnitude & phase)")
        .value("BuiltInTestEnvironmentData", t_S7KDatagramIdentifier::BuiltInTestEnvironmentData, "7021 - 7k built-in test environment data (BITE)")
        .value("SonarSourceVersion", t_S7KDatagramIdentifier::SonarSourceVersion, "7022 - 7k sonar source version")
        .value("WetEndVersion8k", t_S7KDatagramIdentifier::WetEndVersion8k, "7023 - 8k wet end version")
        .value("DetectionData", t_S7KDatagramIdentifier::DetectionData, "7026 - 7k detection data")
        .value("RawDetectionData", t_S7KDatagramIdentifier::RawDetectionData, "7027 - 7k raw detection data (bathymetry, preferred)")
        .value("SnippetData", t_S7KDatagramIdentifier::SnippetData, "7028 - 7k snippet data (water column)")
        .value("VernierProcessingDataFiltered", t_S7KDatagramIdentifier::VernierProcessingDataFiltered, "7029 - Vernier processing data (filtered)")
        .value("SonarInstallationParameters", t_S7KDatagramIdentifier::SonarInstallationParameters, "7030 - Sonar installation parameters")
        .value("BuiltInTestEnvironmentDataSummary", t_S7KDatagramIdentifier::BuiltInTestEnvironmentDataSummary, "7031 - 7k built-in test environment data (summary)")
        .value("CompressedBeamformedIntensityData", t_S7KDatagramIdentifier::CompressedBeamformedIntensityData, "7041 - Compressed beamformed intensity data")
        .value("CompressedWaterColumnData", t_S7KDatagramIdentifier::CompressedWaterColumnData, "7042 - Compressed water column data")
        .value("SegmentedRawDetectionData", t_S7KDatagramIdentifier::SegmentedRawDetectionData, "7047 - 7k segmented raw detection data")
        .value("CalibratedBeamData", t_S7KDatagramIdentifier::CalibratedBeamData, "7048 - 7k calibrated beam data")
        .value("SystemEvents", t_S7KDatagramIdentifier::SystemEvents, "7050 - 7k system events")
        .value("SystemEventMessage", t_S7KDatagramIdentifier::SystemEventMessage, "7051 - 7k system event message")
        .value("RDRRecordingStatus", t_S7KDatagramIdentifier::RDRRecordingStatus, "7052 - RDR recording status")
        .value("Subscriptions", t_S7KDatagramIdentifier::Subscriptions, "7053 - 7k subscriptions")
        .value("NormalizationStatus", t_S7KDatagramIdentifier::NormalizationStatus, "7055 - Normalization status")
        .value("CalibratedSideScanData", t_S7KDatagramIdentifier::CalibratedSideScanData, "7057 - Calibrated side-scan data")
        .value("SnippetBackscatteringStrength", t_S7KDatagramIdentifier::SnippetBackscatteringStrength, "7058 - Snippet backscattering strength")
        .value("MB2SpecificStatus", t_S7KDatagramIdentifier::MB2SpecificStatus, "7059 - MB2 specific status")
        .value("FileHeader", t_S7KDatagramIdentifier::FileHeader, "7200 - 7k file header")
        .value("FileCatalogRecord", t_S7KDatagramIdentifier::FileCatalogRecord, "7300 - 7k file catalogue record")
        .value("TimeMessage", t_S7KDatagramIdentifier::TimeMessage, "7400 - 7k time message")
        .value("RemoteControl", t_S7KDatagramIdentifier::RemoteControl, "7500 - 7k remote control")
        .value("RemoteControlAcknowledge", t_S7KDatagramIdentifier::RemoteControlAcknowledge, "7501 - 7k remote control acknowledge")
        .value("RemoteControlNotAcknowledge", t_S7KDatagramIdentifier::RemoteControlNotAcknowledge, "7502 - 7k remote control not acknowledge")
        .value("RemoteControlSonarSettings", t_S7KDatagramIdentifier::RemoteControlSonarSettings, "7503 - 7k remote control sonar settings")
        .value("SensorSettings7P", t_S7KDatagramIdentifier::SensorSettings7P, "7504 - 7P sensor settings")
        .value("SVFiltering", t_S7KDatagramIdentifier::SVFiltering, "7510 - SV filtering")
        .value("SystemLockStatus", t_S7KDatagramIdentifier::SystemLockStatus, "7511 - System lock status")
        .value("Timestamp", t_S7KDatagramIdentifier::Timestamp, "7515 - Timestamp")
        .value("SoundVelocity", t_S7KDatagramIdentifier::SoundVelocity, "7610 - 7k sound velocity")
        .value("AbsorptionLoss", t_S7KDatagramIdentifier::AbsorptionLoss, "7611 - 7k absorption loss")
        .value("SpreadingLoss", t_S7KDatagramIdentifier::SpreadingLoss, "7612 - 7k spreading loss")
        .value("ProfileAverageSalinity", t_S7KDatagramIdentifier::ProfileAverageSalinity, "7613 - Profile average salinity")
        .value("ProfileAverageTemperature", t_S7KDatagramIdentifier::ProfileAverageTemperature, "7614 - Profile average temperature")
        .value("FillerRecord", t_S7KDatagramIdentifier::FillerRecord, "7777 - Filler record (used when repairing corrupt files)")
        .value("Sonar8kSeriesData", t_S7KDatagramIdentifier::Sonar8kSeriesData, "8100 - 8k series sonar data")
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
    py_datagrams::init_m_s7kdatagrams(subm);
    py_filedatacontainers::init_m_s7kfiledatacontainers(subm);
    py_filedatainterfaces::init_m_s7kfiledatainterfaces(subm);
    init_c_s7kfilehandler(subm);
}

}
}
}
}
