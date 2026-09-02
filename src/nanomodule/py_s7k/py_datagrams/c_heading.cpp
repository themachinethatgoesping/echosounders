// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/datetime.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams/heading.hpp>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_datagrams {
namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::s7k;
using namespace themachinethatgoesping::echosounders::s7k::datagrams;

#define DOC_C(CLASS, ARG) DOC(themachinethatgoesping, echosounders, s7k, datagrams, CLASS, ARG)

void init_c_heading(nb::module_& m)
{
    nb::class_<Heading, S7KDatagram>(m, "Heading", DOC(themachinethatgoesping, echosounders, s7k, datagrams, Heading))
        .def(nb::init<>(), DOC_C(Heading, Heading))
        .def("get_heading", &Heading::get_heading, DOC_C(Heading, get_heading))
        .def("set_heading", &Heading::set_heading, DOC_C(Heading, set_heading), nb::arg("val"))
        .def("__eq__", &Heading::operator==, nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(Heading)
        __PYCLASS_DEFAULT_BINARY__(Heading)
        __PYCLASS_DEFAULT_PRINTING__(Heading);
}

} // namespace py_datagrams
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
