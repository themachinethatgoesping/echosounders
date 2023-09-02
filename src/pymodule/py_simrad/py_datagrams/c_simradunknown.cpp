// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/simrad/datagrams/simradunknown.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simrad;
using datagrams::SimradUnknown;

#define DOC_SimradUnknown(arg)                                                                     \
    DOC(themachinethatgoesping, echosounders, simrad, datagrams, SimradUnknown, arg)

void init_c_simradunknown(pybind11::module& m)
{
    py::class_<SimradUnknown, datagrams::SimradDatagram>(
        m,
        "SimradUnknown",
        DOC(themachinethatgoesping, echosounders, simrad, datagrams, SimradUnknown))
        .def(py::init<>(), DOC_SimradUnknown(SimradUnknown))
        // --- convenient data access ---
        .def(
            "get_raw_content",
            [](const SimradUnknown& self) { return py::bytes(self.get_raw_content()); },
            DOC_SimradUnknown(raw_content))
        .def(
            "set_raw_content",
            [](SimradUnknown& self, const py::bytes& value) { self.set_raw_content(value); },
            DOC_SimradUnknown(raw_content))

        // ----- operators -----
        .def("__eq__", &SimradUnknown::operator==, DOC_SimradUnknown(operator_eq), py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(SimradUnknown)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(SimradUnknown)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(SimradUnknown)
        // end LinearInterpolator
        ;
}
}
}
}
}
}