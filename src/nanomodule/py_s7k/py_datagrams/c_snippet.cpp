// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <xtensor-python/nanobind/pytensor.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams/snippet.hpp>

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

void init_c_snippet(nb::module_& m)
{
    nb::class_<Snippet, S7KDatagram>(
        m, "Snippet", DOC(themachinethatgoesping, echosounders, s7k, datagrams, Snippet))
        .def(nb::init<>(), DOC_C(Snippet, Snippet))
        .def("get_serial_number", &Snippet::get_serial_number, DOC_C(Snippet, get_serial_number))
        .def("get_ping_number", &Snippet::get_ping_number, DOC_C(Snippet, get_ping_number))
        .def("get_multi_ping", &Snippet::get_multi_ping, DOC_C(Snippet, get_multi_ping))
        .def("get_number_beams", &Snippet::get_number_beams, DOC_C(Snippet, get_number_beams))
        .def("get_error_flag", &Snippet::get_error_flag, DOC_C(Snippet, get_error_flag))
        .def("get_control_flags", &Snippet::get_control_flags, DOC_C(Snippet, get_control_flags))
        .def("get_flags", &Snippet::get_flags, DOC_C(Snippet, get_flags))
        .def("get_samples_are_32bit", &Snippet::get_samples_are_32bit, DOC_C(Snippet, get_samples_are_32bit))
        .def("get_beam_descriptor", &Snippet::get_beam_descriptor, DOC_C(Snippet, get_beam_descriptor))
        .def("get_snippet_start", &Snippet::get_snippet_start, DOC_C(Snippet, get_snippet_start))
        .def("get_detection_sample", &Snippet::get_detection_sample, DOC_C(Snippet, get_detection_sample))
        .def("get_snippet_end", &Snippet::get_snippet_end, DOC_C(Snippet, get_snippet_end))
        .def("get_amplitudes", &Snippet::get_amplitudes, "intensity snippet arrays (one per beam)")
        .def("get_beam_amplitudes", &Snippet::get_beam_amplitudes, nb::arg("beam_index"), "intensity snippet of a single beam")
        .def("__eq__", &Snippet::operator==, nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(Snippet)
        __PYCLASS_DEFAULT_BINARY__(Snippet)
        __PYCLASS_DEFAULT_PRINTING__(Snippet);
}

} // namespace py_datagrams
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
