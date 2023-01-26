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

#include "../../../themachinethatgoesping/echosounders/em3000/em3000_datagrams.hpp"
#include "../../../themachinethatgoesping/echosounders/em3000/em3000_types.hpp"

#include "../../py_filetemplates/py_datacontainers/datagramcontainer.hpp"
#include "../../py_filetemplates/py_datainterfaces/i_datagraminterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_em3000 {
namespace py_filedatacontainers {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::filetemplates;
using namespace themachinethatgoesping::echosounders::em3000;
using themachinethatgoesping::tools::progressbars::I_ProgressBar;

void init_c_em3000datagramcontainer(pybind11::module& m)
{
    using namespace py_filetemplates::py_datacontainers;
    // EM3000DATAGRAMTYPEAREA

    py_datagramcontainer::create_DatagramContainerTypes<datagrams::EM3000Datagram,
                                                        t_EM3000DatagramIdentifier>(
        m, "EM3000DatagramContainer_Header");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::EM3000Unknown,
                                                        t_EM3000DatagramIdentifier>(
        m, "EM3000DatagramContainer_Unknown");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::XYZDatagram,
                                                        t_EM3000DatagramIdentifier>(
        m, "EM3000DatagramContainer_XYZDatagram");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::ExtraDetections,
                                                        t_EM3000DatagramIdentifier>(
        m, "EM3000DatagramContainer_ExtraDetections");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::RawRangeAndAngle,
                                                        t_EM3000DatagramIdentifier>(
        m, "EM3000DatagramContainer_RawRangeAndAngle");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::SeabedImageData,
                                                        t_EM3000DatagramIdentifier>(
        m, "EM3000DatagramContainer_SeabedImageData");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::WaterColumnDatagram,
                                                        t_EM3000DatagramIdentifier>(
        m, "EM3000DatagramContainer_WaterColumnDatagram");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::QualityFactorDatagram,
                                                        t_EM3000DatagramIdentifier>(
        m, "EM3000DatagramContainer_QualityFactorDatagram");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::AttitudeDatagram,
                                                        t_EM3000DatagramIdentifier>(
        m, "EM3000DatagramContainer_AttitudeDatagram");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::NetworkAttitudeVelocityDatagram,
                                                        t_EM3000DatagramIdentifier>(
        m, "EM3000DatagramContainer_NetworkAttitudeVelocityDatagram");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::ClockDatagram,
                                                        t_EM3000DatagramIdentifier>(
        m, "EM3000DatagramContainer_ClockDatagram");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::DepthOrHeightDatagram,
                                                        t_EM3000DatagramIdentifier>(
        m, "EM3000DatagramContainer_DepthOrHeightDatagram");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::HeadingDatagram,
                                                        t_EM3000DatagramIdentifier>(
        m, "EM3000DatagramContainer_HeadingDatagram");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::PositionDatagram,
                                                        t_EM3000DatagramIdentifier>(
        m, "EM3000DatagramContainer_PositionDatagram");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::SingleBeamEchoSounderDepth,
                                                        t_EM3000DatagramIdentifier>(
        m, "EM3000DatagramContainer_SingleBeamEchoSounderDepth");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::SurfaceSoundSpeedDatagram,
                                                        t_EM3000DatagramIdentifier>(
        m, "EM3000DatagramContainer_SurfaceSoundSpeedDatagram");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::SoundSpeedProfileDatagram,
                                                        t_EM3000DatagramIdentifier>(
        m, "EM3000DatagramContainer_SoundSpeedProfileDatagram");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::InstallationParameters,
                                                        t_EM3000DatagramIdentifier>(
        m, "EM3000DatagramContainer_InstallationParameters");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::RuntimeParameters,
                                                        t_EM3000DatagramIdentifier>(
        m, "EM3000DatagramContainer_RuntimeParameters");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::ExtraParameters,
                                                        t_EM3000DatagramIdentifier>(
        m, "EM3000DatagramContainer_ExtraParameters");
    py_datagramcontainer::create_DatagramContainerTypes<datagrams::PUStatusOutput,
                                                        t_EM3000DatagramIdentifier>(
        m, "EM3000DatagramContainer_PUStatusOutput");

    py_datagramcontainer::create_DatagramContainerTypes<datagrams::t_EM3000DatagramVariant,
                                                        t_EM3000DatagramIdentifier,
                                                        datagrams::EM3000DatagramVariant>(
        m, "EM3000DatagramContainer_Variant");
}

}
}
}
}
}