// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/bind_vector.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams/substructs/attitudesample.hpp>

#include "../module.hpp"

NB_MAKE_OPAQUE(
    std::vector<themachinethatgoesping::echosounders::s7k::datagrams::substructs::AttitudeSample>);

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::s7k;
using datagrams::substructs::AttitudeSample;

#define DOC_AttitudeSample(ARG)                                                                    \
    DOC(themachinethatgoesping, echosounders, s7k, datagrams, substructs, AttitudeSample, ARG)

void init_c_attitudesample(nanobind::module_& m)
{
    nb::class_<AttitudeSample>(m, "AttitudeSample", DOC_AttitudeSample(AttitudeSample))
        .def(nb::init<>(), DOC_AttitudeSample(AttitudeSample))
        .def("get_delta_time", &AttitudeSample::get_delta_time, DOC_AttitudeSample(get_delta_time))
        .def("set_delta_time",
             &AttitudeSample::set_delta_time,
             DOC_AttitudeSample(set_delta_time),
             nb::arg("val"))
        .def("get_roll", &AttitudeSample::get_roll, DOC_AttitudeSample(get_roll))
        .def("set_roll", &AttitudeSample::set_roll, DOC_AttitudeSample(set_roll), nb::arg("val"))
        .def("get_pitch", &AttitudeSample::get_pitch, DOC_AttitudeSample(get_pitch))
        .def("set_pitch", &AttitudeSample::set_pitch, DOC_AttitudeSample(set_pitch), nb::arg("val"))
        .def("get_heave", &AttitudeSample::get_heave, DOC_AttitudeSample(get_heave))
        .def("set_heave", &AttitudeSample::set_heave, DOC_AttitudeSample(set_heave), nb::arg("val"))
        .def("get_heading", &AttitudeSample::get_heading, DOC_AttitudeSample(get_heading))
        .def("set_heading",
             &AttitudeSample::set_heading,
             DOC_AttitudeSample(set_heading),
             nb::arg("val"))
        .def("__eq__",
             &AttitudeSample::operator==,
             DOC_AttitudeSample(operator_eq),
             nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(AttitudeSample)
        __PYCLASS_DEFAULT_PRINTING__(AttitudeSample);

    nb::bind_vector<std::vector<AttitudeSample>>(m, "AttitudeSamples_vector");
}

} // namespace py_datagrams
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
