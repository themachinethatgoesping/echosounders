// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/datetime.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams/matchfilter.hpp>

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

void init_c_matchfilter(nb::module_& m)
{
    nb::class_<MatchFilter, S7KDatagram>(m, "MatchFilter", DOC(themachinethatgoesping, echosounders, s7k, datagrams, MatchFilter))
        .def(nb::init<>(), DOC_C(MatchFilter, MatchFilter))
        .def("get_serial_number", &MatchFilter::get_serial_number, DOC_C(MatchFilter, Content, serial_number))
        .def("set_serial_number", &MatchFilter::set_serial_number, DOC_C(MatchFilter, Content, serial_number), nb::arg("val"))
        .def("get_ping_number", &MatchFilter::get_ping_number, DOC_C(MatchFilter, Content, ping_number))
        .def("set_ping_number", &MatchFilter::set_ping_number, DOC_C(MatchFilter, Content, ping_number), nb::arg("val"))
        .def("get_operation", &MatchFilter::get_operation, DOC_C(MatchFilter, Content, operation))
        .def("set_operation", &MatchFilter::set_operation, DOC_C(MatchFilter, Content, operation), nb::arg("val"))
        .def("get_start_frequency", &MatchFilter::get_start_frequency, DOC_C(MatchFilter, Content, start_frequency))
        .def("set_start_frequency", &MatchFilter::set_start_frequency, DOC_C(MatchFilter, Content, start_frequency), nb::arg("val"))
        .def("get_end_frequency", &MatchFilter::get_end_frequency, DOC_C(MatchFilter, Content, end_frequency))
        .def("set_end_frequency", &MatchFilter::set_end_frequency, DOC_C(MatchFilter, Content, end_frequency), nb::arg("val"))
        .def("get_window_type", &MatchFilter::get_window_type, DOC_C(MatchFilter, Content, window_type))
        .def("set_window_type", &MatchFilter::set_window_type, DOC_C(MatchFilter, Content, window_type), nb::arg("val"))
        .def("get_shading", &MatchFilter::get_shading, DOC_C(MatchFilter, Content, shading))
        .def("set_shading", &MatchFilter::set_shading, DOC_C(MatchFilter, Content, shading), nb::arg("val"))
        .def("get_effective_pulse_width", &MatchFilter::get_effective_pulse_width, DOC_C(MatchFilter, Content, effective_pulse_width))
        .def("set_effective_pulse_width", &MatchFilter::set_effective_pulse_width, DOC_C(MatchFilter, Content, effective_pulse_width), nb::arg("val"))
        .def("__eq__", &MatchFilter::operator==, nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(MatchFilter)
        __PYCLASS_DEFAULT_BINARY__(MatchFilter)
        __PYCLASS_DEFAULT_PRINTING__(MatchFilter);
}

} // namespace py_datagrams
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
