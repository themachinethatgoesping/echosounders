// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/datetime.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams/referencepoint.hpp>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_datagrams {
namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::s7k;
using namespace themachinethatgoesping::echosounders::s7k::datagrams;

#define DOC_C(CLASS, ...) DOC(themachinethatgoesping, echosounders, s7k, datagrams, CLASS, __VA_ARGS__)

void init_c_referencepoint(nb::module_& m)
{
    nb::class_<ReferencePoint, S7KDatagram>(m, "ReferencePoint", DOC(themachinethatgoesping, echosounders, s7k, datagrams, ReferencePoint))
        .def(nb::init<>(), DOC_C(ReferencePoint, ReferencePoint))
        .def("get_offset_x", &ReferencePoint::get_offset_x, DOC_C(ReferencePoint, Content, offset_x))
        .def("set_offset_x", &ReferencePoint::set_offset_x, DOC_C(ReferencePoint, Content, offset_x), nb::arg("val"))
        .def("get_offset_y", &ReferencePoint::get_offset_y, DOC_C(ReferencePoint, Content, offset_y))
        .def("set_offset_y", &ReferencePoint::set_offset_y, DOC_C(ReferencePoint, Content, offset_y), nb::arg("val"))
        .def("get_offset_z", &ReferencePoint::get_offset_z, DOC_C(ReferencePoint, Content, offset_z))
        .def("set_offset_z", &ReferencePoint::set_offset_z, DOC_C(ReferencePoint, Content, offset_z), nb::arg("val"))
        .def("get_water_z", &ReferencePoint::get_water_z, DOC_C(ReferencePoint, Content, water_z))
        .def("set_water_z", &ReferencePoint::set_water_z, DOC_C(ReferencePoint, Content, water_z), nb::arg("val"))
        .def("__eq__", &ReferencePoint::operator==, nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(ReferencePoint)
        __PYCLASS_DEFAULT_BINARY__(ReferencePoint)
        __PYCLASS_DEFAULT_PRINTING__(ReferencePoint);
}

} // namespace py_datagrams
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
