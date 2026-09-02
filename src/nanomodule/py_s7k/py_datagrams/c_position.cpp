// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/datetime.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams/position.hpp>

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

void init_c_position(nb::module_& m)
{
    nb::class_<Position, S7KDatagram>(m, "Position", DOC(themachinethatgoesping, echosounders, s7k, datagrams, Position))
        .def(nb::init<>(), DOC_C(Position, Position))
        .def("get_datum", &Position::get_datum, DOC_C(Position, get_datum))
        .def("set_datum", &Position::set_datum, DOC_C(Position, set_datum), nb::arg("val"))
        .def("get_latency", &Position::get_latency, DOC_C(Position, get_latency))
        .def("set_latency", &Position::set_latency, DOC_C(Position, set_latency), nb::arg("val"))
        .def("get_latitude_northing", &Position::get_latitude_northing, DOC_C(Position, get_latitude_northing))
        .def("set_latitude_northing", &Position::set_latitude_northing, DOC_C(Position, set_latitude_northing), nb::arg("val"))
        .def("get_longitude_easting", &Position::get_longitude_easting, DOC_C(Position, get_longitude_easting))
        .def("set_longitude_easting", &Position::set_longitude_easting, DOC_C(Position, set_longitude_easting), nb::arg("val"))
        .def("get_height", &Position::get_height, DOC_C(Position, get_height))
        .def("set_height", &Position::set_height, DOC_C(Position, set_height), nb::arg("val"))
        .def("get_position_type", &Position::get_position_type, DOC_C(Position, get_position_type))
        .def("set_position_type", &Position::set_position_type, DOC_C(Position, set_position_type), nb::arg("val"))
        .def("get_utm_zone", &Position::get_utm_zone, DOC_C(Position, get_utm_zone))
        .def("set_utm_zone", &Position::set_utm_zone, DOC_C(Position, set_utm_zone), nb::arg("val"))
        .def("get_quality", &Position::get_quality, DOC_C(Position, get_quality))
        .def("set_quality", &Position::set_quality, DOC_C(Position, set_quality), nb::arg("val"))
        .def("get_position_method", &Position::get_position_method, DOC_C(Position, get_position_method))
        .def("set_position_method", &Position::set_position_method, DOC_C(Position, set_position_method), nb::arg("val"))
        .def("__eq__", &Position::operator==, nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(Position)
        __PYCLASS_DEFAULT_BINARY__(Position)
        __PYCLASS_DEFAULT_PRINTING__(Position);
}

} // namespace py_datagrams
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
