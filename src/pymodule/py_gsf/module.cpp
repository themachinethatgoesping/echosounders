// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/stl.h>
#include <xtensor-python/pytensor.hpp> // Numpy bindings

#include <sstream>
#include <tuple>
#include <vector>

#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>
#include <themachinethatgoesping/echosounders/gsf/types.hpp>

#include "module.hpp"

// datagram submodules
// #include "py_datagrams/module.hpp"
// #include "py_filedatacontainers/module.hpp"
// #include "py_filedatainterfaces/module.hpp"
// #include "py_filedatatypes/module.hpp"

namespace py = pybind11;

#include <pybind11/pybind11.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_gsf {

// -- submodule declarations --
void init_c_gsffilehandler(pybind11::module& m); // c_gsffilehandler.cpp

// void init_c_file_test_functions(pybind11::module& m); // c_file_test_functions.cpp

#define DOC_t_GSFDatagramIdentifier(ARG)                                                        \
    DOC(themachinethatgoesping, echosounders, gsf, t_GSFDatagramIdentifier, ARG)
#define DOC_t_GSFActiveSensor(ARG)                                                              \
    DOC(themachinethatgoesping, echosounders, gsf, t_GSFActiveSensor, ARG)
#define DOC_t_GSFSystemTransducerConfiguration(ARG)                                             \
    DOC(themachinethatgoesping, echosounders, gsf, t_GSFSystemTransducerConfiguration, ARG)

// -- create submodule --
void init_m_gsf(pybind11::module& m)
{
    using namespace gsf;

    // module description
    auto subm = m.def_submodule("gsf",
                                "Classes related to GSF data files");

              

    auto tmp_enum =
        py::enum_<t_GSFDatagramIdentifier>(
            subm,
            "t_GSFDatagramIdentifier",
            DOC(themachinethatgoesping, echosounders, gsf, t_GSFDatagramIdentifier))
            .value("HEADER",
                   t_GSFDatagramIdentifier::HEADER,
                   DOC_t_GSFDatagramIdentifier(HEADER))
            .value("SWATH_BATHYMETRY",
                   t_GSFDatagramIdentifier::SWATH_BATHYMETRY,
                   DOC_t_GSFDatagramIdentifier(SWATH_BATHYMETRY))
            .value("SOUND_VELOCITY_PROFILE",
                   t_GSFDatagramIdentifier::SOUND_VELOCITY_PROFILE,
                   DOC_t_GSFDatagramIdentifier(SOUND_VELOCITY_PROFILE))
            .value("PROCESSING_PARAMETERS",
                   t_GSFDatagramIdentifier::PROCESSING_PARAMETERS,
                   DOC_t_GSFDatagramIdentifier(PROCESSING_PARAMETERS))
            .value("SENSOR_PARAMETERS",
                   t_GSFDatagramIdentifier::SENSOR_PARAMETERS,
                   DOC_t_GSFDatagramIdentifier(SENSOR_PARAMETERS))
            .value("COMMENT",
                   t_GSFDatagramIdentifier::COMMENT,
                   DOC_t_GSFDatagramIdentifier(COMMENT))
            .value("HISTORY",
                   t_GSFDatagramIdentifier::HISTORY,
                   DOC_t_GSFDatagramIdentifier(HISTORY))
            .value("NAVIGATION_ERROR",
                   t_GSFDatagramIdentifier::NAVIGATION_ERROR,
                   DOC_t_GSFDatagramIdentifier(NAVIGATION_ERROR))
            .value("SWATH_BATHY_SUMMARY",
                   t_GSFDatagramIdentifier::SWATH_BATHY_SUMMARY,
                   DOC_t_GSFDatagramIdentifier(SWATH_BATHY_SUMMARY))
            .value("SINGLE_BEAM_SOUNDING",
                   t_GSFDatagramIdentifier::SINGLE_BEAM_SOUNDING,
                   DOC_t_GSFDatagramIdentifier(SINGLE_BEAM_SOUNDING))
            .value("ATTITUDE",
                   t_GSFDatagramIdentifier::ATTITUDE,
                   DOC_t_GSFDatagramIdentifier(ATTITUDE))
            // other
            .value("unspecified",
                   t_GSFDatagramIdentifier::unspecified,
                   DOC_t_GSFDatagramIdentifier(unspecified))
            .export_values()

        ;

    // py::implicitly_convertible<std::string, t_GSFDatagramIdentifier>();
    tools::pybind_helper::add_string_to_enum_conversion<t_GSFDatagramIdentifier>(tmp_enum);

    subm.def("datagram_type_to_string",
             py::overload_cast<t_GSFDatagramIdentifier>(&datagram_type_to_string),
             DOC(themachinethatgoesping, echosounders, gsf, datagram_type_to_string),
             py::arg("datagram_type"));
    subm.def("GSFDatagram_type_from_string",
             &GSFDatagram_type_from_string,
             DOC(themachinethatgoesping, echosounders, gsf, GSFDatagram_type_from_string),
             py::arg("datagram_type"));

    // datagrams
//     py_datagrams::init_m_gsfdatagrams(subm);
//     py_filedatatypes::init_m_gsffiledatatypes(subm);
//     py_filedatacontainers::init_m_gsffiledatacontainers(subm);
//     py_filedatainterfaces::init_m_gsffiledatainterfaces(subm);

    // gsf classes
    init_c_gsffilehandler(subm);

    // init_c_file_test_functions(subm);
}

}
}
}
}