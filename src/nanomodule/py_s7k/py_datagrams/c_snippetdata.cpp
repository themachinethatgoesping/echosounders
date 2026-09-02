// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <xtensor-python/nanobind/pytensor.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams/snippetdata.hpp>

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

void init_c_snippetdata(nb::module_& m)
{
    nb::class_<SnippetData, S7KDatagram>(
        m, "SnippetData", DOC(themachinethatgoesping, echosounders, s7k, datagrams, SnippetData))
        .def(nb::init<>(), DOC_C(SnippetData, SnippetData))
        .def("get_serial_number", &SnippetData::get_serial_number, DOC_C(SnippetData, Content, serial_number))
        .def("set_serial_number", &SnippetData::set_serial_number, DOC_C(SnippetData, Content, serial_number), nb::arg("val"))
        .def("get_ping_number", &SnippetData::get_ping_number, DOC_C(SnippetData, Content, ping_number))
        .def("set_ping_number", &SnippetData::set_ping_number, DOC_C(SnippetData, Content, ping_number), nb::arg("val"))
        .def("get_multi_ping", &SnippetData::get_multi_ping, DOC_C(SnippetData, Content, multi_ping))
        .def("set_multi_ping", &SnippetData::set_multi_ping, DOC_C(SnippetData, Content, multi_ping), nb::arg("val"))
        .def("get_number_beams", &SnippetData::get_number_beams, DOC_C(SnippetData, Content, number_beams))
        .def("set_number_beams", &SnippetData::set_number_beams, DOC_C(SnippetData, Content, number_beams), nb::arg("val"))
        .def("get_error_flag", &SnippetData::get_error_flag, DOC_C(SnippetData, Content, error_flag))
        .def("set_error_flag", &SnippetData::set_error_flag, DOC_C(SnippetData, Content, error_flag), nb::arg("val"))
        .def("get_control_flags", &SnippetData::get_control_flags, DOC_C(SnippetData, Content, control_flags))
        .def("set_control_flags", &SnippetData::set_control_flags, DOC_C(SnippetData, Content, control_flags), nb::arg("val"))
        .def("get_flags", &SnippetData::get_flags, DOC_C(SnippetData, Content, flags))
        .def("set_flags", &SnippetData::set_flags, DOC_C(SnippetData, Content, flags), nb::arg("val"))
        .def("get_samples_are_32bit", &SnippetData::get_samples_are_32bit, DOC_C(SnippetData, get_samples_are_32bit))
        .def_prop_rw("beams",
                     &SnippetData::beams,
                     &SnippetData::set_beams,
                     DOC_C(SnippetData, beams),
                     nb::rv_policy::reference_internal)
        .def_prop_rw("amplitudes",
                     &SnippetData::amplitudes,
                     &SnippetData::set_amplitudes,
                     DOC_C(SnippetData, amplitudes),
                     nb::rv_policy::reference_internal)
        .def("__eq__", &SnippetData::operator==, nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(SnippetData)
        __PYCLASS_DEFAULT_BINARY__(SnippetData)
        __PYCLASS_DEFAULT_PRINTING__(SnippetData);
}

} // namespace py_datagrams
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
