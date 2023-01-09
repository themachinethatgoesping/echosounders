// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/stl.h>
#include <xtensor-python/pyarray.hpp> // Numpy bindings

#include <sstream>
#include <tuple>
#include <vector>

#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include "../../themachinethatgoesping/echosounders/em3000/em3000_types.hpp"
#include "../docstrings.hpp"
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

// -- create submodule --
void init_m_em3000(pybind11::module& m)
{
    xt::import_numpy(); // import numpy for xtensor (otherwise there will be weird segfaults)
    using namespace em3000;

    // module description
    auto subm = m.def_submodule("em3000",
                                "Classes related to Kongsberg EM3000 data files (old Kongsberg "
                                ".all / .wcd format, used until SIS 4.0)");

    py::enum_<t_EM3000DatagramIdentifier>(
        subm,
        "t_EM3000DatagramIdentifier",
        DOC(themachinethatgoesping, echosounders, em3000, t_EM3000DatagramIdentifier))
        // Multibeam data
        .value("DepthDatagram",
               t_EM3000DatagramIdentifier::DepthDatagram,
               DOC(themachinethatgoesping,
                   echosounders,
                   em3000,
                   t_EM3000DatagramIdentifier,
                   DepthDatagram))
        .value("XYZDatagram",
               t_EM3000DatagramIdentifier::XYZDatagram,
               DOC(themachinethatgoesping,
                   echosounders,
                   em3000,
                   t_EM3000DatagramIdentifier,
                   XYZDatagram))
        .value("ExtraDetections",
               t_EM3000DatagramIdentifier::ExtraDetections,
               DOC(themachinethatgoesping,
                   echosounders,
                   em3000,
                   t_EM3000DatagramIdentifier,
                   ExtraDetections))
        .value("RawRangeAndAngle",
               t_EM3000DatagramIdentifier::RawRangeAndAngle,
               DOC(themachinethatgoesping,
                   echosounders,
                   em3000,
                   t_EM3000DatagramIdentifier,
                   RawRangeAndAngle))
        .value("SeabedImageData",
               t_EM3000DatagramIdentifier::SeabedImageData,
               DOC(themachinethatgoesping,
                   echosounders,
                   em3000,
                   t_EM3000DatagramIdentifier,
                   SeabedImageData))
        .value("WaterColumnDatagram",
               t_EM3000DatagramIdentifier::WaterColumnDatagram,
               DOC(themachinethatgoesping,
                   echosounders,
                   em3000,
                   t_EM3000DatagramIdentifier,
                   WaterColumnDatagram))
        .value("CombinedWaterColumnDatagram",
               t_EM3000DatagramIdentifier::CombinedWaterColumnDatagram,
               DOC(themachinethatgoesping,
                   echosounders,
                   em3000,
                   t_EM3000DatagramIdentifier,
                   CombinedWaterColumnDatagram))
        .value("QualityFactorDatagram",
               t_EM3000DatagramIdentifier::QualityFactorDatagram,
               DOC(themachinethatgoesping,
                   echosounders,
                   em3000,
                   t_EM3000DatagramIdentifier,
                   QualityFactorDatagram))
        // External sensors
        .value("AttitudeDatagram",
               t_EM3000DatagramIdentifier::AttitudeDatagram,
               DOC(themachinethatgoesping,
                   echosounders,
                   em3000,
                   t_EM3000DatagramIdentifier,
                   AttitudeDatagram))
        .value("NetworkAttitudeVelocityDatagram",
               t_EM3000DatagramIdentifier::NetworkAttitudeVelocityDatagram,
               DOC(themachinethatgoesping,
                   echosounders,
                   em3000,
                   t_EM3000DatagramIdentifier,
                   NetworkAttitudeVelocityDatagram))
        .value("ClockDatagram",
               t_EM3000DatagramIdentifier::ClockDatagram,
               DOC(themachinethatgoesping,
                   echosounders,
                   em3000,
                   t_EM3000DatagramIdentifier,
                   ClockDatagram))
        .value("DepthOrHeightDatagram",
               t_EM3000DatagramIdentifier::DepthOrHeightDatagram,
               DOC(themachinethatgoesping,
                   echosounders,
                   em3000,
                   t_EM3000DatagramIdentifier,
                   DepthOrHeightDatagram))
        .value("HeadingDatagram",
               t_EM3000DatagramIdentifier::HeadingDatagram,
               DOC(themachinethatgoesping,
                   echosounders,
                   em3000,
                   t_EM3000DatagramIdentifier,
                   HeadingDatagram))
        .value("PositionDatagram",
               t_EM3000DatagramIdentifier::PositionDatagram,
               DOC(themachinethatgoesping,
                   echosounders,
                   em3000,
                   t_EM3000DatagramIdentifier,
                   PositionDatagram))
        .value("SingleBeamEchoSounderDepth",
               t_EM3000DatagramIdentifier::SingleBeamEchoSounderDepth,
               DOC(themachinethatgoesping,
                   echosounders,
                   em3000,
                   t_EM3000DatagramIdentifier,
                   SingleBeamEchoSounderDepth))

        // Sound speed
        .value("SurfaceSoundSpeedDatagram",
               t_EM3000DatagramIdentifier::SurfaceSoundSpeedDatagram,
               DOC(themachinethatgoesping,
                   echosounders,
                   em3000,
                   t_EM3000DatagramIdentifier,
                   SurfaceSoundSpeedDatagram))
        .value("SoundSpeedProfileDatagram",
               t_EM3000DatagramIdentifier::SoundSpeedProfileDatagram,
               DOC(themachinethatgoesping,
                   echosounders,
                   em3000,
                   t_EM3000DatagramIdentifier,
                   SoundSpeedProfileDatagram))

        // Multibeam parameters
        .value("InstallationParameterStart",
               t_EM3000DatagramIdentifier::InstallationParameterStart,
               DOC(themachinethatgoesping,
                   echosounders,
                   em3000,
                   t_EM3000DatagramIdentifier,
                   InstallationParameterStart))
        .value("InstallationParameterStop",
               t_EM3000DatagramIdentifier::InstallationParameterStop,
               DOC(themachinethatgoesping,
                   echosounders,
                   em3000,
                   t_EM3000DatagramIdentifier,
                   InstallationParameterStop))
        .value("RuntimeParameters",
               t_EM3000DatagramIdentifier::RuntimeParameters,
               DOC(themachinethatgoesping,
                   echosounders,
                   em3000,
                   t_EM3000DatagramIdentifier,
                   RuntimeParameters))
        .value("ExtraParameters",
               t_EM3000DatagramIdentifier::ExtraParameters,
               DOC(themachinethatgoesping,
                   echosounders,
                   em3000,
                   t_EM3000DatagramIdentifier,
                   ExtraParameters))

        // PU information and status
        .value("PuStatusOutput",
               t_EM3000DatagramIdentifier::PuStatusOutput,
               DOC(themachinethatgoesping,
                   echosounders,
                   em3000,
                   t_EM3000DatagramIdentifier,
                   PuStatusOutput))
        .value("PUIDOutput",
               t_EM3000DatagramIdentifier::PUIDOutput,
               DOC(themachinethatgoesping,
                   echosounders,
                   em3000,
                   t_EM3000DatagramIdentifier,
                   PUIDOutput))
        // other
        .value("unspecified",
               t_EM3000DatagramIdentifier::unspecified,
               DOC(themachinethatgoesping,
                   echosounders,
                   em3000,
                   t_EM3000DatagramIdentifier,
                   unspecified))
        .export_values()
        // pybind enum helper
        // unfortunately magic_enum only works for enums within a specific range that cannot exceed
        // max(uint16_t) therefore we need to use a custom function
        //__PYENUM_FROM_STRING__(t_EM3000DatagramIdentifier)
        .def(py::init([](const std::string& str) {
                 auto datagram_identifier = magic_enum::enum_cast<t_EM3000DatagramIdentifier>(str);
                 if (datagram_identifier.has_value())
                 {
                     return datagram_identifier.value();
                 }

                 std::string enum_values;
                 for (auto& entry : magic_enum::enum_entries<t_EM3000DatagramIdentifier>())
                 {
                     enum_values += fmt::format("{}, ", entry.second);
                 }
                 enum_values = enum_values.substr(0, enum_values.size() - 2);

                 pybind11::print(
                     fmt::format("ERROR: unknown value option '{}'! Try: [{}]", str, enum_values));

                 throw std::invalid_argument(
                     fmt::format("ERROR: unknown value option '{}'! Try: [{}]", str, enum_values));
             }),
             "Construct this enum type from string",
             py::arg("str"))
        //
        ;

    py::implicitly_convertible<std::string, t_EM3000DatagramIdentifier>();

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