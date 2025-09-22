// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/pytypes.h>
#include <pybind11/stl.h>

#include "../../themachinethatgoesping/echosounders/pingtools/pingsampleselector.hpp"
#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_pingtools {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::pingtools;

#define DOC_PingSampleSelector(arg)                                                                \
    DOC(themachinethatgoesping, echosounders, pingtools, PingSampleSelector, arg)

void init_c_pingsampleselector(pybind11::module& m)
{
    py::classh<PingSampleSelector>(
        m,
        "PingSampleSelector",
        DOC(themachinethatgoesping, echosounders, pingtools, PingSampleSelector))
        .def(py::init<>(), DOC_PingSampleSelector(PingSampleSelector))

        // --- main interface ---
        .def("apply_selection",
             py::overload_cast<filetemplates::datatypes::I_PingWatercolumn&>(
                 &PingSampleSelector::apply_selection),
             DOC_PingSampleSelector(apply_selection),
             py::arg("ping_watercolumn"))
        .def("apply_selection",
             py::overload_cast<filetemplates::datatypes::I_PingBottom&>(
                 &PingSampleSelector::apply_selection),
             DOC_PingSampleSelector(apply_selection),
             py::arg("ping_bottom"))

        // --- convenient data access ---
        .def("get_min_beam_number",
             &PingSampleSelector::get_min_beam_number,
             DOC_PingSampleSelector(min_beam_number))
        .def("get_max_beam_number",
             &PingSampleSelector::get_max_beam_number,
             DOC_PingSampleSelector(max_beam_number))
        .def("get_min_sample_number",
             &PingSampleSelector::get_min_sample_number,
             DOC_PingSampleSelector(min_sample_number))
        .def("get_max_sample_number",
             &PingSampleSelector::get_max_sample_number,
             DOC_PingSampleSelector(max_sample_number))
        .def("get_min_beam_angle",
             &PingSampleSelector::get_min_beam_angle,
             DOC_PingSampleSelector(min_beam_angle))
        .def("get_max_beam_angle",
             &PingSampleSelector::get_max_beam_angle,
             DOC_PingSampleSelector(max_beam_angle))
        .def("get_min_sample_range",
             &PingSampleSelector::get_min_sample_range,
             DOC_PingSampleSelector(min_sample_range))
        .def("get_max_sample_range",
             &PingSampleSelector::get_max_sample_range,
             DOC_PingSampleSelector(max_sample_range))
        .def("get_transmit_sectors",
             &PingSampleSelector::get_transmit_sectors,
             DOC_PingSampleSelector(transmit_sectors))
        .def("get_transmit_sector_min_beam_angle",
             &PingSampleSelector::get_transmit_sector_min_beam_angle,
             DOC_PingSampleSelector(transmit_sector_min_beam_angle))
        .def("get_transmit_sector_max_beam_angle",
             &PingSampleSelector::get_transmit_sector_max_beam_angle,
             DOC_PingSampleSelector(transmit_sector_max_beam_angle))
        .def("get_beam_step", &PingSampleSelector::get_beam_step, DOC_PingSampleSelector(beam_step))
        .def("get_sample_step",
             &PingSampleSelector::get_sample_step,
             DOC_PingSampleSelector(sample_step))
        .def("get_min_minslant_range_percent",
             &PingSampleSelector::get_min_minslant_range_percent,
             DOC_PingSampleSelector(get_min_minslant_range_percent))
        .def("get_max_minslant_range_percent",
             &PingSampleSelector::get_max_minslant_range_percent,
             DOC_PingSampleSelector(get_max_minslant_range_percent))
        .def("get_min_bottom_range_percent",
             &PingSampleSelector::get_min_bottom_range_percent,
             DOC_PingSampleSelector(get_min_bottom_range_percent))
        .def("get_max_bottom_range_percent",
             &PingSampleSelector::get_max_bottom_range_percent,
             DOC_PingSampleSelector(get_max_bottom_range_percent))

        // ----- clear range filters -----
        .def("clear_beam_number_range",
             &PingSampleSelector::clear_beam_number_range,
             DOC_PingSampleSelector(clear_beam_number_range))
        .def("clear_sample_number_range",
             &PingSampleSelector::clear_sample_number_range,
             DOC_PingSampleSelector(clear_sample_number_range))
        .def("clear_beam_angle_range",
             &PingSampleSelector::clear_beam_angle_range,
             DOC_PingSampleSelector(clear_beam_angle_range))
        .def("clear_sample_range_range",
             &PingSampleSelector::clear_sample_range_range,
             DOC_PingSampleSelector(clear_sample_range_range))
        .def("clear_transmit_sectors",
             &PingSampleSelector::clear_transmit_sectors,
             DOC_PingSampleSelector(clear_transmit_sectors))
        .def("clear_transmit_sector_beam_angle_range",
             &PingSampleSelector::clear_transmit_sector_beam_angle_range,
             DOC_PingSampleSelector(clear_transmit_sector_beam_angle_range))
        .def("clear_beam_step",
             &PingSampleSelector::clear_beam_step,
             DOC_PingSampleSelector(clear_beam_step))
        .def("clear_sample_step",
             &PingSampleSelector::clear_sample_step,
             DOC_PingSampleSelector(clear_sample_step))
        .def("clear_minslant_range",
             &PingSampleSelector::clear_minslant_range,
             DOC_PingSampleSelector(clear_minslant_range))
        .def("clear_bottom_range",
             &PingSampleSelector::clear_bottom_range,
             DOC_PingSampleSelector(clear_bottom_range))
        .def("clear", &PingSampleSelector::clear, DOC_PingSampleSelector(clear))

        // ----- selectors -----
        .def("select_beam_range_by_numbers",
             &PingSampleSelector::select_beam_range_by_numbers,
             DOC_PingSampleSelector(select_beam_range_by_numbers),
             py::arg("min_beam_number") = std::nullopt,
             py::arg("max_beam_number") = std::nullopt,
             py::arg("beam_step")       = std::nullopt)
        .def("select_sample_range_by_numbers",
             &PingSampleSelector::select_sample_range_by_numbers,
             DOC_PingSampleSelector(select_sample_range_by_numbers),
             py::arg("min_sample_number") = std::nullopt,
             py::arg("max_sample_number") = std::nullopt,
             py::arg("sample_step")       = std::nullopt)
        .def("select_beam_range_by_angles",
             &PingSampleSelector::select_beam_range_by_angles,
             DOC_PingSampleSelector(select_beam_range_by_angles),
             py::arg("min_beam_angle") = std::nullopt,
             py::arg("max_beam_angle") = std::nullopt,
             py::arg("beam_step")      = std::nullopt)
        .def("select_sample_range_by_ranges",
             &PingSampleSelector::select_sample_range_by_ranges,
             DOC_PingSampleSelector(select_sample_range_by_ranges),
             py::arg("min_sample_range") = std::nullopt,
             py::arg("max_sample_range") = std::nullopt,
             py::arg("sample_step")      = std::nullopt)
        .def("select_transmit_sectors",
             &PingSampleSelector::select_transmit_sectors,
             DOC_PingSampleSelector(select_transmit_sectors),
             py::arg("transmit_sectors") = std::nullopt)
        .def("select_transmit_sectors_by_beam_angles",
             &PingSampleSelector::select_transmit_sectors_by_beam_angles,
             DOC_PingSampleSelector(select_transmit_sectors_by_beam_angles),
             py::arg("transmit_sector_min_beam_angle") = std::nullopt,
             py::arg("transmit_sector_max_beam_angle") = std::nullopt)
        .def("select_min_minslant_range_percent",
             &PingSampleSelector::select_min_minslant_range_percent,
             DOC_PingSampleSelector(select_min_minslant_range_percent),
             py::arg("min_minslant_range_percent") = std::nullopt)
        .def("select_max_minslant_range_percent",
             &PingSampleSelector::select_max_minslant_range_percent,
             DOC_PingSampleSelector(select_max_minslant_range_percent),
             py::arg("max_minslant_range_percent") = std::nullopt)
        .def("select_minslant_range_percent",
             &PingSampleSelector::select_minslant_range_percent,
             DOC_PingSampleSelector(select_minslant_range_percent),
             py::arg("min_minslant_range_percent") = std::nullopt,
             py::arg("max_minslant_range_percent") = std::nullopt)
        .def("select_min_bottom_range_percent",
             &PingSampleSelector::select_min_bottom_range_percent,
             DOC_PingSampleSelector(select_min_bottom_range_percent),
             py::arg("min_bottom_range_percent") = std::nullopt)
        .def("select_max_bottom_range_percent",
             &PingSampleSelector::select_max_bottom_range_percent,
             DOC_PingSampleSelector(select_max_bottom_range_percent),
             py::arg("max_bottom_range_percent") = std::nullopt)
        .def("select_bottom_range_percent",
             &PingSampleSelector::select_bottom_range_percent,
             DOC_PingSampleSelector(select_bottom_range_percent),
             py::arg("min_bottom_range_percent") = std::nullopt,
             py::arg("max_bottom_range_percent") = std::nullopt)

        .def("set_sample_step",
             &PingSampleSelector::set_sample_step,
             DOC_PingSampleSelector(set_sample_step),
             py::arg("sample_step"))
        .def("set_beam_step",
             &PingSampleSelector::set_beam_step,
             DOC_PingSampleSelector(set_beam_step),
             py::arg("beam_step"))

        // ----- operators -----
        .def("__eq__",
             &PingSampleSelector::operator==,
             DOC_PingSampleSelector(operator_eq),
             py::arg("other"))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(PingSampleSelector)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(PingSampleSelector)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(PingSampleSelector);
}

}
}
}
}