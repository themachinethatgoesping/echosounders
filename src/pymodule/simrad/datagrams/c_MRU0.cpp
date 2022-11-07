// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelpers.hpp>

#include "../../../themachinethatgoesping/echosounders/simrad/datagrams/MRU0.hpp"
#include "../../docstrings.hpp"
#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simrad;
using datagrams::MRU0;
using datagrams::SimradDatagram;

void init_c_MRU0(pybind11::module& m)
{
    py::class_<MRU0, datagrams::SimradDatagram>(
        m, "MRU0", DOC(themachinethatgoesping, echosounders, simrad, datagrams, MRU0))
        .def(py::init<>(), DOC(themachinethatgoesping, echosounders, simrad, datagrams, MRU0, MRU0))
        // --- convenient data access ---
        .def_property("heave",
                      &MRU0::get_heave,
                      &MRU0::set_heave,
                      DOC(themachinethatgoesping, echosounders, simrad, datagrams, MRU0, Heave))
        .def_property("roll",
                      &MRU0::get_roll,
                      &MRU0::set_roll,
                      DOC(themachinethatgoesping, echosounders, simrad, datagrams, MRU0, Roll))
        .def_property("pitch",
                      &MRU0::get_pitch,
                      &MRU0::set_pitch,
                      DOC(themachinethatgoesping, echosounders, simrad, datagrams, MRU0, Pitch))
        .def_property("heading",
                      &MRU0::get_heading,
                      &MRU0::set_heading,
                      DOC(themachinethatgoesping, echosounders, simrad, datagrams, MRU0, Heading))

        // --- raw data access ---
        .def_readwrite("_raw_Heave",
                       &MRU0::_Heave,
                       DOC(themachinethatgoesping, echosounders, simrad, datagrams, MRU0, Heave))
        .def_readwrite("_raw_Roll",
                       &MRU0::_Roll,
                       DOC(themachinethatgoesping, echosounders, simrad, datagrams, MRU0, Roll))
        .def_readwrite("_raw_Pitch",
                       &MRU0::_Pitch,
                       DOC(themachinethatgoesping, echosounders, simrad, datagrams, MRU0, Pitch))
        .def_readwrite("_raw_Heading",
                       &MRU0::_Heading,
                       DOC(themachinethatgoesping, echosounders, simrad, datagrams, MRU0, Heading))

        // ----- operators -----
        .def("__eq__",
             &MRU0::operator==,
             DOC(themachinethatgoesping, echosounders, simrad, datagrams, MRU0, operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(MRU0)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(MRU0)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(MRU0)
        // end LinearInterpolator
        ;
}
}
}
}
}
}