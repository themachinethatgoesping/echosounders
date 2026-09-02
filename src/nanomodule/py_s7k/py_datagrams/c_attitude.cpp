// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <xtensor-python/nanobind/pytensor.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams/attitude.hpp>

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

void init_c_attitude(nb::module_& m)
{
    nb::class_<Attitude, S7KDatagram>(
        m, "Attitude", DOC(themachinethatgoesping, echosounders, s7k, datagrams, Attitude))
        .def(nb::init<>(), DOC_C(Attitude, Attitude))
        .def("get_number_of_samples", &Attitude::get_number_of_samples, DOC_C(Attitude, get_number_of_samples))
        .def("get_delta_time", &Attitude::get_delta_time, DOC_C(Attitude, get_delta_time))
        .def("get_roll", &Attitude::get_roll, DOC_C(Attitude, get_roll))
        .def("get_pitch", &Attitude::get_pitch, DOC_C(Attitude, get_pitch))
        .def("get_heave", &Attitude::get_heave, DOC_C(Attitude, get_heave))
        .def("get_heading", &Attitude::get_heading, DOC_C(Attitude, get_heading))
        .def("__eq__", &Attitude::operator==, nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(Attitude)
        __PYCLASS_DEFAULT_BINARY__(Attitude)
        __PYCLASS_DEFAULT_PRINTING__(Attitude);
}

} // namespace py_datagrams
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
