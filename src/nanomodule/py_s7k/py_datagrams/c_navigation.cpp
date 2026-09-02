// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/datetime.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams/navigation.hpp>

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

void init_c_navigation(nb::module_& m)
{
    nb::class_<Navigation, S7KDatagram>(m, "Navigation", DOC(themachinethatgoesping, echosounders, s7k, datagrams, Navigation))
        .def(nb::init<>(), DOC_C(Navigation, Navigation))
        .def("get_vertical_reference", &Navigation::get_vertical_reference, DOC_C(Navigation, Content, vertical_reference))
        .def("set_vertical_reference", &Navigation::set_vertical_reference, DOC_C(Navigation, Content, vertical_reference), nb::arg("val"))
        .def("get_latitude", &Navigation::get_latitude, DOC_C(Navigation, Content, latitude))
        .def("set_latitude", &Navigation::set_latitude, DOC_C(Navigation, Content, latitude), nb::arg("val"))
        .def("get_longitude", &Navigation::get_longitude, DOC_C(Navigation, Content, longitude))
        .def("set_longitude", &Navigation::set_longitude, DOC_C(Navigation, Content, longitude), nb::arg("val"))
        .def("get_position_accuracy", &Navigation::get_position_accuracy, DOC_C(Navigation, Content, position_accuracy))
        .def("set_position_accuracy", &Navigation::set_position_accuracy, DOC_C(Navigation, Content, position_accuracy), nb::arg("val"))
        .def("get_height", &Navigation::get_height, DOC_C(Navigation, Content, height))
        .def("set_height", &Navigation::set_height, DOC_C(Navigation, Content, height), nb::arg("val"))
        .def("get_height_accuracy", &Navigation::get_height_accuracy, DOC_C(Navigation, Content, height_accuracy))
        .def("set_height_accuracy", &Navigation::set_height_accuracy, DOC_C(Navigation, Content, height_accuracy), nb::arg("val"))
        .def("get_speed", &Navigation::get_speed, DOC_C(Navigation, Content, speed))
        .def("set_speed", &Navigation::set_speed, DOC_C(Navigation, Content, speed), nb::arg("val"))
        .def("get_course", &Navigation::get_course, DOC_C(Navigation, Content, course))
        .def("set_course", &Navigation::set_course, DOC_C(Navigation, Content, course), nb::arg("val"))
        .def("get_heading", &Navigation::get_heading, DOC_C(Navigation, Content, heading))
        .def("set_heading", &Navigation::set_heading, DOC_C(Navigation, Content, heading), nb::arg("val"))
        .def("__eq__", &Navigation::operator==, nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(Navigation)
        __PYCLASS_DEFAULT_BINARY__(Navigation)
        __PYCLASS_DEFAULT_PRINTING__(Navigation);
}

} // namespace py_datagrams
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
