// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/simradraw/datagrams/MRU0.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simradraw;
using datagrams::MRU0;
using datagrams::SimradRawDatagram;

#define DOC_MRU0(arg) DOC(themachinethatgoesping, echosounders, simradraw, datagrams, MRU0, arg)

void init_c_MRU0(pybind11::module& m)
{
    py::class_<MRU0, datagrams::SimradRawDatagram>(
        m, "MRU0", DOC(themachinethatgoesping, echosounders, simradraw, datagrams, MRU0))
        .def(py::init<>(), DOC_MRU0(MRU0))

        // --- convenient data access ---
        .def("get_heave", &MRU0::get_heave, DOC_MRU0(heave))
        .def("set_heave", &MRU0::set_heave, DOC_MRU0(heave))
        .def("get_roll", &MRU0::get_roll, DOC_MRU0(roll))
        .def("set_roll", &MRU0::set_roll, DOC_MRU0(roll))
        .def("get_pitch", &MRU0::get_pitch, DOC_MRU0(pitch))
        .def("set_pitch", &MRU0::set_pitch, DOC_MRU0(pitch))
        .def("get_heading", &MRU0::get_heading, DOC_MRU0(heading))
        .def("set_heading", &MRU0::set_heading, DOC_MRU0(heading))

        // ----- operators -----
        .def("__eq__", &MRU0::operator==, DOC_MRU0(operator_eq), py::arg("other"))
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