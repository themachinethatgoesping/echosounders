// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/pytypes.h>
#include <pybind11/stl.h>

#include "../../themachinethatgoesping/echosounders/pingtools/beamselection.hpp"
#include "../../themachinethatgoesping/echosounders/pingtools/beamsampleselection.hpp"
#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_pingtools {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::pingtools;

#define DOC_BeamSelection(arg)                                                                     \
    DOC(themachinethatgoesping, echosounders, pingtools, BeamSelection, arg)

void init_c_beamselection(pybind11::module& m)
{
    py::class_<BeamSelection, std::shared_ptr<BeamSelection>>(
        m, "BeamSelection", DOC(themachinethatgoesping, echosounders, pingtools, BeamSelection))
        .def(py::init<>(), DOC_BeamSelection(BeamSelection))
        .def(py::init<const BeamSampleSelection& >(), DOC_BeamSelection(BeamSelection), py::arg("beam_sample_selection"))
        .def(py::init<uint32_t>(), DOC_BeamSelection(BeamSelection_2), py::arg("number_of_beams"))
        .def(py::init<std::vector<uint32_t>>(),
             DOC_BeamSelection(BeamSelection_3),
             py::arg("beam_numbers"))

        // --- add beam/samples ---
        .def("add_beam",
             &BeamSelection::add_beam,
             DOC_BeamSelection(add_beam),
             py::arg("beam_number"))

        // --- convenient data access ---
        .def("get_number_of_beams",
             &BeamSelection::get_number_of_beams,
             DOC_BeamSelection(get_number_of_beams))
        .def("empty",
             &BeamSelection::empty,
             DOC_BeamSelection(empty))
        .def("get_beam_numbers",
             &BeamSelection::get_beam_numbers,
             py::return_value_policy::reference_internal,
             DOC_BeamSelection(get_beam_numbers))

        // ----- operators -----
        .def("__eq__", &BeamSelection::operator==, DOC_BeamSelection(operator_eq), py::arg("other"))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(BeamSelection)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(BeamSelection)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(BeamSelection);
}

}
}
}
}