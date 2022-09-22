// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>

#include "../../../themachinethatgoesping/echosounders/simrad/datagrams/ek60_TAG0.hpp"
#include "../../docstrings.hpp"
#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simrad;
using datagrams::EK60_Datagram;
using datagrams::EK60_TAG0;

void init_c_EK60_TAG0(pybind11::module& m)
{
    py::class_<EK60_TAG0, datagrams::EK60_Datagram>(
        m, "EK60_TAG0", DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK60_TAG0))
        .def(py::init<>(),
             DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK60_TAG0, EK60_TAG0))
        // --- convenient data access ---
        .def_property("text",
                      &EK60_TAG0::get_text,
                      &EK60_TAG0::set_text,
                      DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK60_TAG0, Text))

        // --- raw data access ---
        .def_readwrite(
            "_raw_Text",
            &EK60_TAG0::_Text,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK60_TAG0, Text))

        // ----- operators -----
        .def("__eq__",
             &EK60_TAG0::operator==,
             DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK60_TAG0, operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(EK60_TAG0)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(EK60_TAG0)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(EK60_TAG0)
        // end LinearInterpolator
        ;
}
}
}
}
}
}