// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <magic_enum.hpp>

#include <pybind11/iostream.h>
#include <pybind11/pytypes.h>
#include <pybind11/stl.h>

#include <xtensor-python/pyarray.hpp> // Numpy bindings
#include <xtensor/xmath.hpp>          // xtensor import for the C++ universal functions

#include <chrono>

#include <themachinethatgoesping/navigation/nmea_0183.hpp>
#include <themachinethatgoesping/tools/progressbars.hpp>
#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/kongsbergall/types.hpp"
#include "../../../themachinethatgoesping/echosounders/kongsbergall/datagrams.hpp"

#include "../../py_filetemplates/py_datacontainers/datagramcontainer.hpp"
#include "../../py_filetemplates/py_datainterfaces/i_datagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_filedatacontainers {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

void init_c_kongsbergalldatagramcontainer(pybind11::module& m)
{
    using namespace py_filetemplates::py_datacontainers;
    // KongsbergAllDATAGRAMTYPEAREA

    py_datagramcontainer::create_DatagramContainerTypes<datagrams::KongsbergAllDatagram,
                                                        t_KongsbergAllDatagramIdentifier>(
        m, "KongsbergAllDatagramContainer_Header");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::KongsbergAllUnknown,
                                                        t_KongsbergAllDatagramIdentifier>(
        m, "KongsbergAllDatagramContainer_Unknown");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::XYZDatagram,
                                                        t_KongsbergAllDatagramIdentifier>(
        m, "KongsbergAllDatagramContainer_XYZDatagram");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::ExtraDetections,
                                                        t_KongsbergAllDatagramIdentifier>(
        m, "KongsbergAllDatagramContainer_ExtraDetections");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::RawRangeAndAngle,
                                                        t_KongsbergAllDatagramIdentifier>(
        m, "KongsbergAllDatagramContainer_RawRangeAndAngle");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::SeabedImageData,
                                                        t_KongsbergAllDatagramIdentifier>(
        m, "KongsbergAllDatagramContainer_SeabedImageData");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::WatercolumnDatagram,
                                                        t_KongsbergAllDatagramIdentifier>(
        m, "KongsbergAllDatagramContainer_WatercolumnDatagram");
    py_datagramcontainer::create_DatagramContainerTypes<
        datagrams::WatercolumnDatagram,
        t_KongsbergAllDatagramIdentifier,
        datagrams::KongsbergAllSkipDataFactory<datagrams::WatercolumnDatagram>>(
        m, "KongsbergAllDatagramContainer_WatercolumnDatagram_SkippedData");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::QualityFactorDatagram,
                                                        t_KongsbergAllDatagramIdentifier>(
        m, "KongsbergAllDatagramContainer_QualityFactorDatagram");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::AttitudeDatagram,
                                                        t_KongsbergAllDatagramIdentifier>(
        m, "KongsbergAllDatagramContainer_AttitudeDatagram");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::NetworkAttitudeVelocityDatagram,
                                                        t_KongsbergAllDatagramIdentifier>(
        m, "KongsbergAllDatagramContainer_NetworkAttitudeVelocityDatagram");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::ClockDatagram,
                                                        t_KongsbergAllDatagramIdentifier>(
        m, "KongsbergAllDatagramContainer_ClockDatagram");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::DepthOrHeightDatagram,
                                                        t_KongsbergAllDatagramIdentifier>(
        m, "KongsbergAllDatagramContainer_DepthOrHeightDatagram");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::HeadingDatagram,
                                                        t_KongsbergAllDatagramIdentifier>(
        m, "KongsbergAllDatagramContainer_HeadingDatagram");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::PositionDatagram,
                                                        t_KongsbergAllDatagramIdentifier>(
        m, "KongsbergAllDatagramContainer_PositionDatagram");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::SingleBeamEchoSounderDepth,
                                                        t_KongsbergAllDatagramIdentifier>(
        m, "KongsbergAllDatagramContainer_SingleBeamEchoSounderDepth");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::SurfaceSoundSpeedDatagram,
                                                        t_KongsbergAllDatagramIdentifier>(
        m, "KongsbergAllDatagramContainer_SurfaceSoundSpeedDatagram");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::SoundSpeedProfileDatagram,
                                                        t_KongsbergAllDatagramIdentifier>(
        m, "KongsbergAllDatagramContainer_SoundSpeedProfileDatagram");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::InstallationParameters,
                                                        t_KongsbergAllDatagramIdentifier>(
        m, "KongsbergAllDatagramContainer_InstallationParameters");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::RuntimeParameters,
                                                        t_KongsbergAllDatagramIdentifier>(
        m, "KongsbergAllDatagramContainer_RuntimeParameters");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::ExtraParameters,
                                                        t_KongsbergAllDatagramIdentifier>(
        m, "KongsbergAllDatagramContainer_ExtraParameters");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::PUIDOutput,
                                                        t_KongsbergAllDatagramIdentifier>(
        m, "KongsbergAllDatagramContainer_PUIDOutput");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::PUStatusOutput,
                                                        t_KongsbergAllDatagramIdentifier>(
        m, "KongsbergAllDatagramContainer_PUStatusOutput");

    py_datagramcontainer::create_DatagramContainerTypes<datagrams::t_KongsbergAllDatagramVariant,
                                                        t_KongsbergAllDatagramIdentifier,
                                                        datagrams::KongsbergAllDatagramVariant>(
        m, "KongsbergAllDatagramContainer_Variant");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::t_KongsbergAllDatagramVariant,
                                                        t_KongsbergAllDatagramIdentifier,
                                                        datagrams::KongsbergAllSkipDataVariantFactory>(
        m, "KongsbergAllDatagramContainer_Variant_SkippedData");
}

}
}
}
}
}