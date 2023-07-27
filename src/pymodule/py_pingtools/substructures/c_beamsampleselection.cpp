// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/pytypes.h>
#include <pybind11/stl.h>

#include "../../../themachinethatgoesping/echosounders/pingtools/substructures/beamsampleselection.hpp"
#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_pingtools {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::pingtools::substructures;

#define DOC_BeamSampleSelection(arg)                                                               \
    DOC(themachinethatgoesping, echosounders, pingtools, substructures, BeamSampleSelection, arg)

void init_c_beamsampleselection(pybind11::module& m)
{
    py::class_<BeamSampleSelection>(
        m,
        "BeamSampleSelection",
        DOC(themachinethatgoesping, echosounders, pingtools, substructures, BeamSampleSelection))
        .def(py::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 pingtools,
                 substructures,
                 BeamSampleSelection))

        // --- add beam/samples ---
        .def("add_beam",
             &BeamSampleSelection::add_beam,
             DOC_BeamSampleSelection(add_beam),
             py::arg("beam_number"),
             py::arg("first_sample_number"),
             py::arg("max_number_of_samples"))

        .def("set_sample_step_ensemble",
             &BeamSampleSelection::set_sample_step_ensemble,
             py::arg("sample_step_ensemble"),
             DOC_BeamSampleSelection(set_sample_step_ensemble))

        // --- convenient data access ---
        .def("get_number_of_beams",
             &BeamSampleSelection::get_number_of_beams,
             DOC_BeamSampleSelection(get_number_of_beams))
        .def("get_beam_numbers",
             &BeamSampleSelection::get_beam_numbers,
             py::return_value_policy::reference_internal,
             DOC_BeamSampleSelection(get_beam_numbers))
        .def("get_first_sample_number_per_beam",
             &BeamSampleSelection::get_first_sample_number_per_beam,
             py::return_value_policy::reference_internal,
             DOC_BeamSampleSelection(get_first_sample_number_per_beam))
        .def("get_max_number_of_samples_per_beam",
             &BeamSampleSelection::get_max_number_of_samples_per_beam,
             py::return_value_policy::reference_internal,
             DOC_BeamSampleSelection(get_max_number_of_samples_per_beam))

        // ----- operators -----
        .def("__eq__",
             &BeamSampleSelection::operator==,
             DOC_BeamSampleSelection(operator_eq),
             py::arg("other"))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(BeamSampleSelection)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(BeamSampleSelection)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(BeamSampleSelection);
}

}
}
}
}