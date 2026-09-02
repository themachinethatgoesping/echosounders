// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/bind_vector.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams/substructs/snippetdatabeam.hpp>

#include "../module.hpp"

NB_MAKE_OPAQUE(
    std::vector<themachinethatgoesping::echosounders::s7k::datagrams::substructs::SnippetDataBeam>);

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::s7k;
using datagrams::substructs::SnippetDataBeam;

#define DOC_SnippetDataBeam(ARG)                                                                   \
    DOC(themachinethatgoesping, echosounders, s7k, datagrams, substructs, SnippetDataBeam, ARG)

void init_c_snippetdatabeam(nanobind::module_& m)
{
    nb::class_<SnippetDataBeam>(m, "SnippetDataBeam", DOC_SnippetDataBeam(SnippetDataBeam))
        .def(nb::init<>(), DOC_SnippetDataBeam(SnippetDataBeam))
        .def("get_beam_descriptor",
             &SnippetDataBeam::get_beam_descriptor,
             DOC_SnippetDataBeam(get_beam_descriptor))
        .def("set_beam_descriptor",
             &SnippetDataBeam::set_beam_descriptor,
             DOC_SnippetDataBeam(set_beam_descriptor),
             nb::arg("val"))
        .def("get_snippet_start",
             &SnippetDataBeam::get_snippet_start,
             DOC_SnippetDataBeam(get_snippet_start))
        .def("set_snippet_start",
             &SnippetDataBeam::set_snippet_start,
             DOC_SnippetDataBeam(set_snippet_start),
             nb::arg("val"))
        .def("get_detection_sample",
             &SnippetDataBeam::get_detection_sample,
             DOC_SnippetDataBeam(get_detection_sample))
        .def("set_detection_sample",
             &SnippetDataBeam::set_detection_sample,
             DOC_SnippetDataBeam(set_detection_sample),
             nb::arg("val"))
        .def("get_snippet_end",
             &SnippetDataBeam::get_snippet_end,
             DOC_SnippetDataBeam(get_snippet_end))
        .def("set_snippet_end",
             &SnippetDataBeam::set_snippet_end,
             DOC_SnippetDataBeam(set_snippet_end),
             nb::arg("val"))
        .def("get_number_of_samples",
             &SnippetDataBeam::get_number_of_samples,
             DOC_SnippetDataBeam(get_number_of_samples))
        .def("__eq__",
             &SnippetDataBeam::operator==,
             DOC_SnippetDataBeam(operator_eq),
             nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(SnippetDataBeam)
        __PYCLASS_DEFAULT_PRINTING__(SnippetDataBeam);

    nb::bind_vector<std::vector<SnippetDataBeam>>(m, "SnippetDataBeams_vector");
}

} // namespace py_datagrams
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
