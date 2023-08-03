// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/pytypes.h>
#include <pybind11/stl.h>

#include "../../themachinethatgoesping/echosounders/pingtools/pingsampleselection.hpp"
#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_pingtools {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::pingtools;

#define DOC_PingSampleSelection(arg)                                                               \
    DOC(themachinethatgoesping, echosounders, pingtools, PingSampleSelection, arg)

void init_c_pingsampleselection(pybind11::module& m)
{
    py::class_<PingSampleSelection>(
        m,
        "PingSampleSelection",
        DOC(themachinethatgoesping, echosounders, pingtools, PingSampleSelection))
        .def(py::init<>(), DOC_PingSampleSelection(PingSampleSelection))

        // --- add beams/samples ---
        .def("add_beam",
             &PingSampleSelection::add_beam,
             DOC_PingSampleSelection(add_beam),
             py::arg("transducer_id"),
             py::arg("beam_nr"),
             py::arg("first_sample_number")   = 0,
             py::arg("max_number_of_samples") = std::numeric_limits<uint16_t>::max())
        .def("add_beam_sample_selection",
             &PingSampleSelection::add_beam_sample_selection,
             DOC_PingSampleSelection(add_beam_sample_selection),
             py::arg("transducer_id"),
             py::arg("BeamSampleSelection"))

        .def("set_first_sample_number_ensemble",
             &PingSampleSelection::set_first_sample_number_ensemble,
             DOC_PingSampleSelection(set_first_sample_number_ensemble),
             py::arg("set_first_sample_number_ensemble"))
        .def("set_last_sample_number_ensemble",
             &PingSampleSelection::set_last_sample_number_ensemble,
             DOC_PingSampleSelection(set_last_sample_number_ensemble),
             py::arg("set_last_sample_number_ensemble"))

        // ---- ensemble infos -----
        .def("set_sample_step_ensemble",
             &PingSampleSelection::set_sample_step_ensemble,
             DOC_PingSampleSelection(set_sample_step_ensemble),
             py::arg("sample_step_ensemble"))
        .def("set_first_sample_number_ensemble",
             &PingSampleSelection::set_first_sample_number_ensemble,
             DOC_PingSampleSelection(set_first_sample_number_ensemble),
             py::arg("set_first_sample_number_ensemble"))
        .def("set_last_sample_number_ensemble",
             &PingSampleSelection::set_last_sample_number_ensemble,
             DOC_PingSampleSelection(set_last_sample_number_ensemble),
             py::arg("set_last_sample_number_ensemble"))

        .def("get_sample_step_ensemble",
             &PingSampleSelection::get_sample_step_ensemble,
             DOC_PingSampleSelection(get_sample_step_ensemble))
        .def("get_first_sample_number_ensemble",
             &PingSampleSelection::get_first_sample_number_ensemble,
             DOC_PingSampleSelection(get_first_sample_number_ensemble))
        .def("get_last_sample_number_ensemble",
             &PingSampleSelection::get_last_sample_number_ensemble,
             DOC_PingSampleSelection(get_last_sample_number_ensemble))

        // --- convenient data access ---
        .def("transducer_ids",
             &PingSampleSelection::transducer_ids,
             DOC_PingSampleSelection(transducer_ids))

        .def("get_sample_selections",
             &PingSampleSelection::get_sample_selections,
             DOC_PingSampleSelection(get_sample_selections))

        // ----- get information -----
        .def("get_number_of_beams",
             &PingSampleSelection::get_number_of_beams,
             DOC_PingSampleSelection(get_number_of_beams))
        .def("get_number_of_samples_ensemble",
             &PingSampleSelection::get_number_of_samples_ensemble,
             DOC_PingSampleSelection(get_number_of_samples_ensemble))

        // ----- operators -----
        .def("__eq__",
             &PingSampleSelection::operator==,
             DOC_PingSampleSelection(operator_eq),
             py::arg("other"))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(PingSampleSelection)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(PingSampleSelection)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(PingSampleSelection);
}

}
}
}
}