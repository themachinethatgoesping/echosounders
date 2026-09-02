// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams/s7kunknown.hpp>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_datagrams {
namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::s7k;
using datagrams::S7KDatagram;
using datagrams::S7KUnknown;

#define DOC_S7KUnknown(arg) DOC(themachinethatgoesping, echosounders, s7k, datagrams, S7KUnknown, arg)

void init_c_s7kunknown(nanobind::module_& m)
{
    nb::class_<S7KUnknown, S7KDatagram>(
        m, "S7KUnknown", DOC(themachinethatgoesping, echosounders, s7k, datagrams, S7KUnknown))
        .def(nb::init<>(), DOC_S7KUnknown(S7KUnknown))
        // --- convenient data access ---
        .def("get_raw_content", &S7KUnknown::get_raw_content, DOC_S7KUnknown(raw_content))
        .def("set_raw_content",
             &S7KUnknown::set_raw_content,
             DOC_S7KUnknown(raw_content),
             nb::arg("value"))

        // ----- operators -----
        .def("__eq__",
             &S7KUnknown::operator==,
             DOC(themachinethatgoesping, echosounders, s7k, datagrams, S7KUnknown, operator_eq),
             nb::arg("other"))
        // ----- nanobind macros -----
        __PYCLASS_DEFAULT_COPY__(S7KUnknown)
        __PYCLASS_DEFAULT_BINARY__(S7KUnknown)
        __PYCLASS_DEFAULT_PRINTING__(S7KUnknown)
        ;
}

} // namespace py_datagrams
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
