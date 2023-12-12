// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/pytypes.h>
#include <pybind11/stl.h>

#include <xtensor-python/pyarray.hpp>                  // Numpy bindings
#include <xtensor-python/pytensor.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // Numpy bindings

#include "../../themachinethatgoesping/echosounders/pingtools/beamsampleselection.hpp"
#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_pingtools {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::pingtools;

#define DOC_BeamSampleSelection(arg)                                                               \
    DOC(themachinethatgoesping, echosounders, pingtools, BeamSampleSelection, arg)

void init_c_beamsampleselection(pybind11::module& m)
{
    py::class_<BeamSampleSelection, BeamSelection, std::shared_ptr<BeamSampleSelection>>(
        m,
        "BeamSampleSelection",
        DOC(themachinethatgoesping, echosounders, pingtools, BeamSampleSelection))
        .def(py::init<uint16_t>(),
             DOC_BeamSampleSelection(BeamSampleSelection),
             py::arg("sample_step_ensemble") = 1)
        .def(py::init<std::vector<uint16_t>, std::vector<uint16_t>, uint16_t>(),
             DOC_BeamSampleSelection(BeamSampleSelection_2),
             py::arg("first_sample_number_per_beam"),
             py::arg("last_sample_number_per_beam"),
             py::arg("sample_step_ensemble") = 1)
        .def(py::init<BeamSelection>(),
             DOC_BeamSampleSelection(BeamSampleSelection_3),
             py::arg("beam_selection"))

        // --- get read sample range ---
        .def("get_read_sample_range",
             &BeamSampleSelection::get_read_sample_range,
             DOC_BeamSampleSelection(get_read_sample_range),
             py::arg("beam_index"),
             py::arg("first_sample_offset_in_beam"),
             py::arg("number_of_samples_in_beam"))

        // --- get sample numbers ---
        .def("get_sample_numbers_ensemble_1d",
             &BeamSampleSelection::get_sample_numbers_ensemble_1d,
             DOC_BeamSampleSelection(get_sample_numbers_ensemble_1d))
        .def("get_sample_numbers_ensemble_2d",
             &BeamSampleSelection::get_sample_numbers_ensemble_2d,
             DOC_BeamSampleSelection(get_sample_numbers_ensemble_2d))


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
        .def("set_first_sample_number_ensemble",
             &BeamSampleSelection::set_first_sample_number_ensemble,
             py::arg("first_sample_number_ensemble"),
             DOC_BeamSampleSelection(set_first_sample_number_ensemble))
        .def("set_last_sample_number_ensemble",
             &BeamSampleSelection::set_last_sample_number_ensemble,
             py::arg("last_sample_number_ensemble"),
             DOC_BeamSampleSelection(set_last_sample_number_ensemble))

        .def("get_sample_step_ensemble",
             &BeamSampleSelection::get_sample_step_ensemble,
             DOC_BeamSampleSelection(get_sample_step_ensemble))
        .def("get_first_sample_number_ensemble",
             &BeamSampleSelection::get_first_sample_number_ensemble,
             DOC_BeamSampleSelection(get_first_sample_number_ensemble))
        .def("get_last_sample_number_ensemble",
             &BeamSampleSelection::get_last_sample_number_ensemble,
             DOC_BeamSampleSelection(get_last_sample_number_ensemble))
        .def("get_number_of_samples_ensemble",
             &BeamSampleSelection::get_number_of_samples_ensemble,
             DOC_BeamSampleSelection(get_number_of_samples_ensemble))

        // --- convenient data access ---
        .def("get_first_sample_number_per_beam",
             &BeamSampleSelection::get_first_sample_number_per_beam,
             py::return_value_policy::reference_internal,
             DOC_BeamSampleSelection(get_first_sample_number_per_beam))
        .def("get_last_sample_number_per_beam",
             &BeamSampleSelection::get_last_sample_number_per_beam,
             py::return_value_policy::reference_internal,
             DOC_BeamSampleSelection(get_last_sample_number_per_beam))

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