// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/stl.h>
#include <xtensor-python/pyarray.hpp> // Numpy bindings

#include <sstream>
#include <tuple>
#include <vector>

#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include "../../themachinethatgoesping/echosounders/kongsbergall/kongsbergall_types.hpp"

#include "module.hpp"

// datagram submodules
#include "py_datagrams/module.hpp"
#include "py_filedatacontainers/module.hpp"
#include "py_filedatainterfaces/module.hpp"
#include "py_filedatatypes/module.hpp"

namespace py = pybind11;

#include <pybind11/pybind11.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {

// -- submodule declarations --
void init_c_kongsbergallfilehandler(pybind11::module& m); // c_kongsbergallfilehandler.cpp

// void init_c_file_test_functions(pybind11::module& m); // c_file_test_functions.cpp

#define DOC_t_KongsbergAllDatagramIdentifier(ARG)                                                        \
    DOC(themachinethatgoesping, echosounders, kongsbergall, t_KongsbergAllDatagramIdentifier, ARG)
#define DOC_t_KongsbergAllActiveSensor(ARG)                                                              \
    DOC(themachinethatgoesping, echosounders, kongsbergall, t_KongsbergAllActiveSensor, ARG)
#define DOC_t_KongsbergAllSystemTransducerConfiguration(ARG)                                             \
    DOC(themachinethatgoesping, echosounders, kongsbergall, t_KongsbergAllSystemTransducerConfiguration, ARG)

// -- create submodule --
void init_m_kongsbergall(pybind11::module& m)
{
    using namespace kongsbergall;

    // module description
    auto subm = m.def_submodule("kongsbergall",
                                "Classes related to Kongsberg KongsbergAll data files (old Kongsberg "
                                ".all / .wcd format, used until SIS 4.0)");

    auto tmp_enum =
        py::enum_<t_KongsbergAllDatagramIdentifier>(
            subm,
            "t_KongsbergAllDatagramIdentifier",
            DOC(themachinethatgoesping, echosounders, kongsbergall, t_KongsbergAllDatagramIdentifier))
            // Multibeam data
            //      .value("DepthDatagram",
            //             t_KongsbergAllDatagramIdentifier::DepthDatagram,
            //             DOC_t_KongsbergAllDatagramIdentifier(DepthDatagram))
            .value("XYZDatagram",
                   t_KongsbergAllDatagramIdentifier::XYZDatagram,
                   DOC_t_KongsbergAllDatagramIdentifier(XYZDatagram))
            .value("ExtraDetections",
                   t_KongsbergAllDatagramIdentifier::ExtraDetections,
                   DOC_t_KongsbergAllDatagramIdentifier(ExtraDetections))
            .value("RawRangeAndAngle",
                   t_KongsbergAllDatagramIdentifier::RawRangeAndAngle,
                   DOC_t_KongsbergAllDatagramIdentifier(RawRangeAndAngle))
            .value("SeabedImageData",
                   t_KongsbergAllDatagramIdentifier::SeabedImageData,
                   DOC_t_KongsbergAllDatagramIdentifier(SeabedImageData))
            .value("WatercolumnDatagram",
                   t_KongsbergAllDatagramIdentifier::WatercolumnDatagram,
                   DOC_t_KongsbergAllDatagramIdentifier(WatercolumnDatagram))
            .value("QualityFactorDatagram",
                   t_KongsbergAllDatagramIdentifier::QualityFactorDatagram,
                   DOC_t_KongsbergAllDatagramIdentifier(QualityFactorDatagram))
            // External sensors
            .value("AttitudeDatagram",
                   t_KongsbergAllDatagramIdentifier::AttitudeDatagram,
                   DOC_t_KongsbergAllDatagramIdentifier(AttitudeDatagram))
            .value("NetworkAttitudeVelocityDatagram",
                   t_KongsbergAllDatagramIdentifier::NetworkAttitudeVelocityDatagram,
                   DOC_t_KongsbergAllDatagramIdentifier(NetworkAttitudeVelocityDatagram))
            .value("ClockDatagram",
                   t_KongsbergAllDatagramIdentifier::ClockDatagram,
                   DOC_t_KongsbergAllDatagramIdentifier(ClockDatagram))
            .value("DepthOrHeightDatagram",
                   t_KongsbergAllDatagramIdentifier::DepthOrHeightDatagram,
                   DOC_t_KongsbergAllDatagramIdentifier(DepthOrHeightDatagram))
            .value("HeadingDatagram",
                   t_KongsbergAllDatagramIdentifier::HeadingDatagram,
                   DOC_t_KongsbergAllDatagramIdentifier(HeadingDatagram))
            .value("PositionDatagram",
                   t_KongsbergAllDatagramIdentifier::PositionDatagram,
                   DOC_t_KongsbergAllDatagramIdentifier(PositionDatagram))
            .value("SingleBeamEchoSounderDepth",
                   t_KongsbergAllDatagramIdentifier::SingleBeamEchoSounderDepth,
                   DOC_t_KongsbergAllDatagramIdentifier(SingleBeamEchoSounderDepth))

            // Sound speed
            .value("SurfaceSoundSpeedDatagram",
                   t_KongsbergAllDatagramIdentifier::SurfaceSoundSpeedDatagram,
                   DOC_t_KongsbergAllDatagramIdentifier(SurfaceSoundSpeedDatagram))
            .value("SoundSpeedProfileDatagram",
                   t_KongsbergAllDatagramIdentifier::SoundSpeedProfileDatagram,
                   DOC_t_KongsbergAllDatagramIdentifier(SoundSpeedProfileDatagram))

            // Multibeam parameters
            .value("InstallationParametersStart",
                   t_KongsbergAllDatagramIdentifier::InstallationParametersStart,
                   DOC_t_KongsbergAllDatagramIdentifier(InstallationParametersStart))
            .value("InstallationParametersStop",
                   t_KongsbergAllDatagramIdentifier::InstallationParametersStop,
                   DOC_t_KongsbergAllDatagramIdentifier(InstallationParametersStop))
            .value("RuntimeParameters",
                   t_KongsbergAllDatagramIdentifier::RuntimeParameters,
                   DOC_t_KongsbergAllDatagramIdentifier(RuntimeParameters))
            .value("ExtraParameters",
                   t_KongsbergAllDatagramIdentifier::ExtraParameters,
                   DOC_t_KongsbergAllDatagramIdentifier(ExtraParameters))

            // PU information and status
            .value("PUStatusOutput",
                   t_KongsbergAllDatagramIdentifier::PUStatusOutput,
                   DOC_t_KongsbergAllDatagramIdentifier(PUStatusOutput))
            .value("PUIDOutput",
                   t_KongsbergAllDatagramIdentifier::PUIDOutput,
                   DOC_t_KongsbergAllDatagramIdentifier(PUIDOutput))
            // other
            .value("unspecified",
                   t_KongsbergAllDatagramIdentifier::unspecified,
                   DOC_t_KongsbergAllDatagramIdentifier(unspecified))
            .export_values()

        ;

    // py::implicitly_convertible<std::string, t_KongsbergAllDatagramIdentifier>();
    tools::pybind_helper::add_string_to_enum_conversion<t_KongsbergAllDatagramIdentifier>(tmp_enum);

    auto pyenum_activekongsbergallsensor =
        py::enum_<t_KongsbergAllActiveSensor>(
            subm,
            "t_KongsbergAllActiveSensor",
            DOC(themachinethatgoesping, echosounders, kongsbergall, t_KongsbergAllActiveSensor))
            .value("PositionSystem3",
                   t_KongsbergAllActiveSensor::PositionSystem3,
                   DOC_t_KongsbergAllActiveSensor(PositionSystem3))
            .value("PositionSystem1",
                   t_KongsbergAllActiveSensor::PositionSystem1,
                   DOC_t_KongsbergAllActiveSensor(PositionSystem1))
            .value("PositionSystem2",
                   t_KongsbergAllActiveSensor::PositionSystem2,
                   DOC_t_KongsbergAllActiveSensor(PositionSystem2))
            .value("MotionSensor1",
                   t_KongsbergAllActiveSensor::MotionSensor1,
                   DOC_t_KongsbergAllActiveSensor(MotionSensor1))
            .value("MotionSensor2",
                   t_KongsbergAllActiveSensor::MotionSensor2,
                   DOC_t_KongsbergAllActiveSensor(MotionSensor2))
            .value("MultiCast1",
                   t_KongsbergAllActiveSensor::MultiCast1,
                   DOC_t_KongsbergAllActiveSensor(MultiCast1))
            .value("MultiCast2",
                   t_KongsbergAllActiveSensor::MultiCast2,
                   DOC_t_KongsbergAllActiveSensor(MultiCast2))
            .value("MultiCast3",
                   t_KongsbergAllActiveSensor::MultiCast3,
                   DOC_t_KongsbergAllActiveSensor(MultiCast3))
            .value("AttitudeVelocitySensor1",
                   t_KongsbergAllActiveSensor::AttitudeVelocitySensor1,
                   DOC_t_KongsbergAllActiveSensor(AttitudeVelocitySensor1))
            .value("AttitudeVelocitySensor2",
                   t_KongsbergAllActiveSensor::AttitudeVelocitySensor2,
                   DOC_t_KongsbergAllActiveSensor(AttitudeVelocitySensor2))
            .value("NotSet", t_KongsbergAllActiveSensor::NotSet, DOC_t_KongsbergAllActiveSensor(NotSet))
            .export_values()
        //
        ;

    tools::pybind_helper::add_string_to_enum_conversion<t_KongsbergAllActiveSensor>(
        pyenum_activekongsbergallsensor);

    auto pyenum_stc =
        py::enum_<t_KongsbergAllSystemTransducerConfiguration>(subm,
                                                         "t_KongsbergAllSystemTransducerConfiguration",
                                                         DOC(themachinethatgoesping,
                                                             echosounders,
                                                             kongsbergall,
                                                             t_KongsbergAllSystemTransducerConfiguration))
            .value("SingleTXSingleRX",
                   t_KongsbergAllSystemTransducerConfiguration::SingleTXSingleRX,
                   DOC_t_KongsbergAllSystemTransducerConfiguration(SingleTXSingleRX))
            .value("SingleHead",
                   t_KongsbergAllSystemTransducerConfiguration::SingleHead,
                   DOC_t_KongsbergAllSystemTransducerConfiguration(SingleHead))
            .value("DualHead",
                   t_KongsbergAllSystemTransducerConfiguration::DualHead,
                   DOC_t_KongsbergAllSystemTransducerConfiguration(DualHead))
            .value("SingleTXDualRX",
                   t_KongsbergAllSystemTransducerConfiguration::SingleTXDualRX,
                   DOC_t_KongsbergAllSystemTransducerConfiguration(SingleTXDualRX))
            .value("DualTXDualRX",
                   t_KongsbergAllSystemTransducerConfiguration::DualTXDualRX,
                   DOC_t_KongsbergAllSystemTransducerConfiguration(DualTXDualRX))
            .value("PortableSingleHead",
                   t_KongsbergAllSystemTransducerConfiguration::PortableSingleHead,
                   DOC_t_KongsbergAllSystemTransducerConfiguration(PortableSingleHead))
            .value("Modular",
                   t_KongsbergAllSystemTransducerConfiguration::Modular,
                   DOC_t_KongsbergAllSystemTransducerConfiguration(Modular))
            .export_values()
        //
        ;

    tools::pybind_helper::add_string_to_enum_conversion<t_KongsbergAllSystemTransducerConfiguration>(
        pyenum_stc);

    subm.def("datagram_type_to_string",
             py::overload_cast<t_KongsbergAllDatagramIdentifier>(&datagram_type_to_string),
             DOC(themachinethatgoesping, echosounders, kongsbergall, datagram_type_to_string),
             py::arg("datagram_type"));
    subm.def("KongsbergAllDatagram_type_from_string",
             &KongsbergAllDatagram_type_from_string,
             DOC(themachinethatgoesping, echosounders, kongsbergall, KongsbergAllDatagram_type_from_string),
             py::arg("datagram_type"));

    // datagrams
    py_datagrams::init_m_kongsbergalldatagrams(subm);
    py_filedatatypes::init_m_kongsbergallfiledatatypes(subm);
    py_filedatacontainers::init_m_kongsbergallfiledatacontainers(subm);
    py_filedatainterfaces::init_m_kongsbergallfiledatainterfaces(subm);

    // kongsbergall classes
    init_c_kongsbergallfilehandler(subm);

    // init_c_file_test_functions(subm);
}

}
}
}
}