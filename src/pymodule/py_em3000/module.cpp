// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/stl.h>
#include <xtensor-python/pyarray.hpp> // Numpy bindings

#include <sstream>
#include <tuple>
#include <vector>

#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include "../../themachinethatgoesping/echosounders/em3000/em3000_types.hpp"

#include "module.hpp"

// datagram submodules
#include "py_datagrams/module.hpp"
#include "py_filedatacontainers/module.hpp"
#include "py_filedatainterfaces/module.hpp"

namespace py = pybind11;

#include <pybind11/pybind11.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_em3000 {

// -- submodule declarations --
void init_c_fileem3000(pybind11::module& m); // c_fileem3000.cpp

// void init_c_file_test_functions(pybind11::module& m); // c_file_test_functions.cpp

#define DOC_t_EM3000DatagramIdentifier(ARG)                                                        \
    DOC(themachinethatgoesping, echosounders, em3000, t_EM3000DatagramIdentifier, ARG)

// -- create submodule --
void init_m_em3000(pybind11::module& m)
{
    xt::import_numpy(); // import numpy for xtensor (otherwise there will be weird segfaults)
    using namespace em3000;

    // module description
    auto subm = m.def_submodule("em3000",
                                "Classes related to Kongsberg EM3000 data files (old Kongsberg "
                                ".all / .wcd format, used until SIS 4.0)");

    auto tmp_enum =
        py::enum_<t_EM3000DatagramIdentifier>(
            subm,
            "t_EM3000DatagramIdentifier",
            DOC(themachinethatgoesping, echosounders, em3000, t_EM3000DatagramIdentifier))
            // Multibeam data
            //      .value("DepthDatagram",
            //             t_EM3000DatagramIdentifier::DepthDatagram,
            //             DOC_t_EM3000DatagramIdentifier(DepthDatagram))
            .value("XYZDatagram",
                   t_EM3000DatagramIdentifier::XYZDatagram,
                   DOC_t_EM3000DatagramIdentifier(XYZDatagram))
            .value("ExtraDetections",
                   t_EM3000DatagramIdentifier::ExtraDetections,
                   DOC_t_EM3000DatagramIdentifier(ExtraDetections))
            .value("RawRangeAndAngle",
                   t_EM3000DatagramIdentifier::RawRangeAndAngle,
                   DOC_t_EM3000DatagramIdentifier(RawRangeAndAngle))
            .value("SeabedImageData",
                   t_EM3000DatagramIdentifier::SeabedImageData,
                   DOC_t_EM3000DatagramIdentifier(SeabedImageData))
            .value("WaterColumnDatagram",
                   t_EM3000DatagramIdentifier::WaterColumnDatagram,
                   DOC_t_EM3000DatagramIdentifier(WaterColumnDatagram))
            .value("QualityFactorDatagram",
                   t_EM3000DatagramIdentifier::QualityFactorDatagram,
                   DOC_t_EM3000DatagramIdentifier(QualityFactorDatagram))
            // External sensors
            .value("AttitudeDatagram",
                   t_EM3000DatagramIdentifier::AttitudeDatagram,
                   DOC_t_EM3000DatagramIdentifier(AttitudeDatagram))
            .value("NetworkAttitudeVelocityDatagram",
                   t_EM3000DatagramIdentifier::NetworkAttitudeVelocityDatagram,
                   DOC_t_EM3000DatagramIdentifier(NetworkAttitudeVelocityDatagram))
            .value("ClockDatagram",
                   t_EM3000DatagramIdentifier::ClockDatagram,
                   DOC_t_EM3000DatagramIdentifier(ClockDatagram))
            .value("DepthOrHeightDatagram",
                   t_EM3000DatagramIdentifier::DepthOrHeightDatagram,
                   DOC_t_EM3000DatagramIdentifier(DepthOrHeightDatagram))
            .value("HeadingDatagram",
                   t_EM3000DatagramIdentifier::HeadingDatagram,
                   DOC_t_EM3000DatagramIdentifier(HeadingDatagram))
            .value("PositionDatagram",
                   t_EM3000DatagramIdentifier::PositionDatagram,
                   DOC_t_EM3000DatagramIdentifier(PositionDatagram))
            .value("SingleBeamEchoSounderDepth",
                   t_EM3000DatagramIdentifier::SingleBeamEchoSounderDepth,
                   DOC_t_EM3000DatagramIdentifier(SingleBeamEchoSounderDepth))

            // Sound speed
            .value("SurfaceSoundSpeedDatagram",
                   t_EM3000DatagramIdentifier::SurfaceSoundSpeedDatagram,
                   DOC_t_EM3000DatagramIdentifier(SurfaceSoundSpeedDatagram))
            .value("SoundSpeedProfileDatagram",
                   t_EM3000DatagramIdentifier::SoundSpeedProfileDatagram,
                   DOC_t_EM3000DatagramIdentifier(SoundSpeedProfileDatagram))

            // Multibeam parameters
            .value("InstallationParameterStart",
                   t_EM3000DatagramIdentifier::InstallationParameterStart,
                   DOC_t_EM3000DatagramIdentifier(InstallationParameterStart))
            .value("InstallationParameterStop",
                   t_EM3000DatagramIdentifier::InstallationParameterStop,
                   DOC_t_EM3000DatagramIdentifier(InstallationParameterStop))
            .value("RuntimeParameters",
                   t_EM3000DatagramIdentifier::RuntimeParameters,
                   DOC_t_EM3000DatagramIdentifier(RuntimeParameters))
            .value("ExtraParameters",
                   t_EM3000DatagramIdentifier::ExtraParameters,
                   DOC_t_EM3000DatagramIdentifier(ExtraParameters))

            // PU information and status
            .value("PuStatusOutput",
                   t_EM3000DatagramIdentifier::PuStatusOutput,
                   DOC_t_EM3000DatagramIdentifier(PuStatusOutput))
            .value("PUIDOutput",
                   t_EM3000DatagramIdentifier::PUIDOutput,
                   DOC_t_EM3000DatagramIdentifier(PUIDOutput))
            // other
            .value("unspecified",
                   t_EM3000DatagramIdentifier::unspecified,
                   DOC_t_EM3000DatagramIdentifier(unspecified))
            .export_values()

        ;

    // py::implicitly_convertible<std::string, t_EM3000DatagramIdentifier>();
    tools::pybind_helper::add_string_to_enum_conversion<t_EM3000DatagramIdentifier>(tmp_enum);

    subm.def("datagram_type_to_string",
             py::overload_cast<t_EM3000DatagramIdentifier>(&datagram_type_to_string),
             DOC(themachinethatgoesping, echosounders, em3000, datagram_type_to_string),
             py::arg("datagram_type"));
    subm.def("EM3000Datagram_type_from_string",
             &EM3000Datagram_type_from_string,
             DOC(themachinethatgoesping, echosounders, em3000, EM3000Datagram_type_from_string),
             py::arg("datagram_type"));

    // datagrams
    py_datagrams::init_m_EM3000Datagrams(subm);
    // py_filedatatypes::init_m_EM3000FileDataTypes(subm);
    py_filedatacontainers::init_m_EM3000FileDataContainers(subm);
    py_filedatainterfaces::init_m_EM3000FileDataInterfaces(subm);

    // em3000 classes
    init_c_fileem3000(subm);

    // init_c_file_test_functions(subm);
}

}
}
}
}