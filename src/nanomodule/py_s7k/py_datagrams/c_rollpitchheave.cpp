// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/datetime.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams/rollpitchheave.hpp>

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

void init_c_rollpitchheave(nb::module_& m)
{
    nb::class_<RollPitchHeave, S7KDatagram>(m, "RollPitchHeave", DOC(themachinethatgoesping, echosounders, s7k, datagrams, RollPitchHeave))
        .def(nb::init<>(), DOC_C(RollPitchHeave, RollPitchHeave))
        .def("get_roll", &RollPitchHeave::get_roll, DOC_C(RollPitchHeave, get_roll))
        .def("set_roll", &RollPitchHeave::set_roll, DOC_C(RollPitchHeave, set_roll), nb::arg("val"))
        .def("get_pitch", &RollPitchHeave::get_pitch, DOC_C(RollPitchHeave, get_pitch))
        .def("set_pitch", &RollPitchHeave::set_pitch, DOC_C(RollPitchHeave, set_pitch), nb::arg("val"))
        .def("get_heave", &RollPitchHeave::get_heave, DOC_C(RollPitchHeave, get_heave))
        .def("set_heave", &RollPitchHeave::set_heave, DOC_C(RollPitchHeave, set_heave), nb::arg("val"))
        .def("__eq__", &RollPitchHeave::operator==, nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(RollPitchHeave)
        __PYCLASS_DEFAULT_BINARY__(RollPitchHeave)
        __PYCLASS_DEFAULT_PRINTING__(RollPitchHeave);
}

} // namespace py_datagrams
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
