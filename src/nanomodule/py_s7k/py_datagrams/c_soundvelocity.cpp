// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/datetime.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams/soundvelocity.hpp>

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

void init_c_soundvelocity(nb::module_& m)
{
    nb::class_<SoundVelocity, S7KDatagram>(m, "SoundVelocity", DOC(themachinethatgoesping, echosounders, s7k, datagrams, SoundVelocity))
        .def(nb::init<>(), DOC_C(SoundVelocity, SoundVelocity))
        .def("get_sound_velocity", &SoundVelocity::get_sound_velocity, DOC_C(SoundVelocity, get_sound_velocity))
        .def("set_sound_velocity", &SoundVelocity::set_sound_velocity, DOC_C(SoundVelocity, set_sound_velocity), nb::arg("val"))
        .def("__eq__", &SoundVelocity::operator==, nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(SoundVelocity)
        __PYCLASS_DEFAULT_BINARY__(SoundVelocity)
        __PYCLASS_DEFAULT_PRINTING__(SoundVelocity);
}

} // namespace py_datagrams
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
