// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/simrad/datagrams/simradunknown.hpp"
#include "../../docstrings.hpp"
#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simrad;
using datagrams::SimradUnknown;

void init_c_simradunknown(pybind11::module& m)
{
    py::class_<SimradUnknown, datagrams::SimradDatagram>(
        m,
        "SimradUnknown",
        DOC(themachinethatgoesping, echosounders, simrad, datagrams, SimradUnknown))
        .def(py::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 SimradUnknown,
                 SimradUnknown))
        // --- convenient data access ---
        .def_property(
            "raw_content",
            [](const SimradUnknown& self) { return py::bytes(self.raw_content); },
            [](SimradUnknown& self, const py::bytes& value) { self.raw_content = value; },
            DOC(themachinethatgoesping,
                echosounders,
                simrad,
                datagrams,
                SimradUnknown,
                raw_content))

        // ----- operators -----
        .def("__eq__",
             &SimradUnknown::operator==,
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 SimradUnknown,
                 operator_eq),
             py::arg("other"))
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