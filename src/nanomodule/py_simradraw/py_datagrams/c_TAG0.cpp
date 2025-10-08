// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/simradraw/datagrams/TAG0.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::simradraw;
using datagrams::SimradRawDatagram;
using datagrams::TAG0;

#define DOC_TAG0(arg) DOC(themachinethatgoesping, echosounders, simradraw, datagrams, TAG0, arg)

void init_c_TAG0(nanobind::module_& m)
{
    nb::class_<TAG0, datagrams::SimradRawDatagram>(
        m, "TAG0", DOC(themachinethatgoesping, echosounders, simradraw, datagrams, TAG0))
        .def(nb::init<>(), DOC_TAG0(TAG0))

        // --- convenient data access ---
        .def("get_text", &TAG0::get_text, DOC_TAG0(text))
        .def("set_text", &TAG0::set_text, DOC_TAG0(text))

        // ----- operators -----
        .def("__eq__", &TAG0::operator==, DOC_TAG0(operator_eq), nb::arg("other"))
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