// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/simradraw/datagrams/simradrawunknown.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simradraw;
using datagrams::SimradRawUnknown;

#define DOC_SimradRawUnknown(arg)                                                                     \
    DOC(themachinethatgoesping, echosounders, simradraw, datagrams, SimradRawUnknown, arg)

void init_c_simradrawunknown(pybind11::module& m)
{
    py::classh<SimradRawUnknown, datagrams::SimradRawDatagram>(
        m,
        "SimradRawUnknown",
        DOC(themachinethatgoesping, echosounders, simradraw, datagrams, SimradRawUnknown))
        .def(py::init<>(), DOC_SimradRawUnknown(SimradRawUnknown))
        // --- convenient data access ---
        .def(
            "get_raw_content",
            [](const SimradRawUnknown& self) { return py::bytes(self.get_raw_content()); },
            DOC_SimradRawUnknown(raw_content))
        .def(
            "set_raw_content",
            [](SimradRawUnknown& self, const py::bytes& value) { self.set_raw_content(value); },
            DOC_SimradRawUnknown(raw_content))

        // ----- operators -----
        .def("__eq__", &SimradRawUnknown::operator==, DOC_SimradRawUnknown(operator_eq), py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(SimradRawUnknown)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(SimradRawUnknown)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(SimradRawUnknown)
        // end LinearInterpolator
        ;
}
}
}
}
}
}