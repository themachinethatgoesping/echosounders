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

        // --- convenient data access ---
        .def_readwrite("beam_numbers",
                       &BeamSampleSelection::beam_numbers,
                       DOC_BeamSampleSelection(beam_numbers))
        .def_readwrite("first_sample_number_per_beam",
                       &BeamSampleSelection::first_sample_number_per_beam,
                       DOC_BeamSampleSelection(first_sample_number_per_beam))
        .def_readwrite("max_number_of_samples_per_beam",
                       &BeamSampleSelection::max_number_of_samples_per_beam,
                       DOC_BeamSampleSelection(max_number_of_samples_per_beam))
        .def_readwrite("sample_step_ensemble",
                       &BeamSampleSelection::sample_step_ensemble,
                       DOC_BeamSampleSelection(sample_step_ensemble))

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