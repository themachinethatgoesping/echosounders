// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/simradraw/datagrams/simradrawunknown.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::simradraw;
using datagrams::SimradRawUnknown;

#define DOC_SimradRawUnknown(arg)                                                                     \
    DOC(themachinethatgoesping, echosounders, simradraw, datagrams, SimradRawUnknown, arg)

void init_c_simradrawunknown(nanobind::module_& m)
{
    nb::class_<SimradRawUnknown, datagrams::SimradRawDatagram>(
        m,
        "SimradRawUnknown",
        DOC(themachinethatgoesping, echosounders, simradraw, datagrams, SimradRawUnknown))
        .def(nb::init<>(), DOC_SimradRawUnknown(SimradRawUnknown))
        // --- convenient data access ---
       .def("get_raw_content",
           [](const SimradRawUnknown& self) { return self.get_raw_content(); },
           DOC_SimradRawUnknown(raw_content))
       .def("set_raw_content",
           [](SimradRawUnknown& self, std::string value) { self.set_raw_content(std::move(value)); },
           DOC_SimradRawUnknown(raw_content),
           nb::arg("raw_content"))

        // ----- operators -----
        .def("__eq__", &SimradRawUnknown::operator==, DOC_SimradRawUnknown(operator_eq), nb::arg("other"))
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