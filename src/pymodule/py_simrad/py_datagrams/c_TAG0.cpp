// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/simrad/datagrams/TAG0.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simrad;
using datagrams::SimradDatagram;
using datagrams::TAG0;

void init_c_TAG0(pybind11::module& m)
{
    py::class_<TAG0, datagrams::SimradDatagram>(
        m, "TAG0", DOC(themachinethatgoesping, echosounders, simrad, datagrams, TAG0))
        .def(py::init<>(), DOC(themachinethatgoesping, echosounders, simrad, datagrams, TAG0, TAG0))
        // --- convenient data access ---
        .def_property("text",
                      &TAG0::get_text,
                      &TAG0::set_text,
                      DOC(themachinethatgoesping, echosounders, simrad, datagrams, TAG0, Text))

        // --- raw data access ---
        .def_readwrite("_raw_Text",
                       &TAG0::_Text,
                       DOC(themachinethatgoesping, echosounders, simrad, datagrams, TAG0, Text))

        // ----- operators -----
        .def("__eq__",
             &TAG0::operator==,
             DOC(themachinethatgoesping, echosounders, simrad, datagrams, TAG0, operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(TAG0)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(TAG0)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(TAG0)
        // end LinearInterpolator
        ;
}
}
}
}
}
}