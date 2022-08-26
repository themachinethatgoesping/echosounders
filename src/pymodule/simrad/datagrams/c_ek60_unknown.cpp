// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>

#include "../../../themachinethatgoesping/echosounders/simrad/datagrams/ek60_unknown.hpp"
#include "../../docstrings.hpp"
#include "module.hpp"

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simrad;
using datagrams::EK60_Unknown;

void init_c_ek60_unknown(pybind11::module& m)
{
        py::class_<EK60_Unknown, datagrams::EK60_Datagram>(
        m,
        "EK60_Unknown",
        DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK60_Unknown))
        .def(py::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 EK60_Unknown,
                 EK60_Unknown))
        // --- convenient data access ---
        .def_property(
            "raw_content",
            [](const EK60_Unknown& self) { return py::bytes(self.raw_content); },
            [](EK60_Unknown& self, const py::bytes& value) { self.raw_content = value; },
            DOC(themachinethatgoesping,
                echosounders,
                simrad,
                datagrams,
                EK60_Unknown,
                raw_content))
        
        // ----- operators -----
        .def("__eq__",
             &EK60_Unknown::operator==,
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 EK60_Unknown,
                 operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        //default copy functions 
        __PYCLASS_DEFAULT_COPY__(EK60_Unknown)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(EK60_Unknown)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(EK60_Unknown)
        // end LinearInterpolator
        ;
}
