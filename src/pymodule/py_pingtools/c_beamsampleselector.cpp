// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/pytypes.h>
#include <pybind11/stl.h>

#include "../../themachinethatgoesping/echosounders/pingtools/beamsampleselector.hpp"
#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_pingtools {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::pingtools;

#define DOC_BeamSampleSelector(arg)                                                                \
    DOC(themachinethatgoesping, echosounders, pingtools, BeamSampleSelector, arg)

void init_c_beamsampleselector(pybind11::module& m)
{
    py::class_<BeamSampleSelector>(
        m,
        "BeamSampleSelector",
        DOC(themachinethatgoesping, echosounders, pingtools, BeamSampleSelector))
        .def(py::init<>(), DOC_BeamSampleSelector(BeamSampleSelector))

        // --- convenient data access ---
        .def("get_min_beam_number",
             &BeamSampleSelector::get_min_beam_number,
             DOC_BeamSampleSelector(min_beam_number))
        .def("get_max_beam_number",
             &BeamSampleSelector::get_max_beam_number,
             DOC_BeamSampleSelector(max_beam_number))
        .def("get_min_sample_number",
             &BeamSampleSelector::get_min_sample_number,
             DOC_BeamSampleSelector(min_sample_number))
        .def("get_max_sample_number",
             &BeamSampleSelector::get_max_sample_number,
             DOC_BeamSampleSelector(max_sample_number))
        .def("get_min_beam_angle",
             &BeamSampleSelector::get_min_beam_angle,
             DOC_BeamSampleSelector(min_beam_angle))
        .def("get_max_beam_angle",
             &BeamSampleSelector::get_max_beam_angle,
             DOC_BeamSampleSelector(max_beam_angle))
        .def("get_min_sample_range",
             &BeamSampleSelector::get_min_sample_range,
             DOC_BeamSampleSelector(min_sample_range))
        .def("get_max_sample_range",
             &BeamSampleSelector::get_max_sample_range,
             DOC_BeamSampleSelector(max_sample_range))
        .def("get_beam_step", &BeamSampleSelector::get_beam_step, DOC_BeamSampleSelector(beam_step))
        .def("get_sample_step",
             &BeamSampleSelector::get_sample_step,
             DOC_BeamSampleSelector(sample_step))

        // ----- clear range filters -----
        .def("clear_beam_number_range",
             &BeamSampleSelector::clear_beam_number_range,
             DOC_BeamSampleSelector(clear_beam_number_range))
        .def("clear_sample_number_range",
             &BeamSampleSelector::clear_sample_number_range,
             DOC_BeamSampleSelector(clear_sample_number_range))
        .def("clear_beam_angle_range",
             &BeamSampleSelector::clear_beam_angle_range,
             DOC_BeamSampleSelector(clear_beam_angle_range))
        .def("clear_sample_range_range",
             &BeamSampleSelector::clear_sample_range_range,
             DOC_BeamSampleSelector(clear_sample_range_range))
        .def("clear_beam_step",
             &BeamSampleSelector::clear_beam_step,
             DOC_BeamSampleSelector(clear_beam_step))
        .def("clear_sample_step",
             &BeamSampleSelector::clear_sample_step,
             DOC_BeamSampleSelector(clear_sample_step))
        .def("clear", &BeamSampleSelector::clear, DOC_BeamSampleSelector(clear))

        // ----- selectors -----
        .def("select_beam_range_by_numbers",
             &BeamSampleSelector::select_beam_range_by_numbers,
             DOC_BeamSampleSelector(select_beam_range_by_numbers),
             py::arg("min_beam_number"),
             py::arg("max_beam_number"),
             py::arg("beam_step") = std::nullopt)
        .def("select_sample_range_by_numbers",
             &BeamSampleSelector::select_sample_range_by_numbers,
             DOC_BeamSampleSelector(select_sample_range_by_numbers),
             py::arg("min_sample_number"),
             py::arg("max_sample_number"),
             py::arg("sample_step") = std::nullopt)
        .def("select_beam_range_by_angles",
             &BeamSampleSelector::select_beam_range_by_angles,
             DOC_BeamSampleSelector(select_beam_range_by_angles),
             py::arg("min_beam_angle"),
             py::arg("max_beam_angle"),
             py::arg("beam_step") = std::nullopt)
        .def("select_sample_range_by_ranges",
             &BeamSampleSelector::select_sample_range_by_ranges,
             DOC_BeamSampleSelector(select_sample_range_by_ranges),
             py::arg("min_sample_range"),
             py::arg("max_sample_range"),
             py::arg("sample_step") = std::nullopt)
        .def("set_sample_step",
             &BeamSampleSelector::set_sample_step,
             DOC_BeamSampleSelector(set_sample_step),
             py::arg("sample_step"))
        .def("set_beam_step",
             &BeamSampleSelector::set_beam_step,
             DOC_BeamSampleSelector(set_beam_step),
             py::arg("beam_step"))

        // ----- operators -----
        .def("__eq__",
             &BeamSampleSelector::operator==,
             DOC_BeamSampleSelector(operator_eq),
             py::arg("other"))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(BeamSampleSelector)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(BeamSampleSelector)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(BeamSampleSelector);
}

}
}
}
}