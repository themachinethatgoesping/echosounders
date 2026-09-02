// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <xtensor-python/nanobind/pytensor.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams/rawdetection.hpp>

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

void init_c_rawdetection(nb::module_& m)
{
    nb::class_<RawDetection, S7KDatagram>(
        m, "RawDetection", DOC(themachinethatgoesping, echosounders, s7k, datagrams, RawDetection))
        .def(nb::init<>(), DOC_C(RawDetection, RawDetection))
        .def("get_serial_number", &RawDetection::get_serial_number, DOC_C(RawDetection, Content, serial_number))
        .def("get_ping_number", &RawDetection::get_ping_number, DOC_C(RawDetection, Content, ping_number))
        .def("get_multi_ping", &RawDetection::get_multi_ping, DOC_C(RawDetection, Content, multi_ping))
        .def("get_number_beams", &RawDetection::get_number_beams, DOC_C(RawDetection, Content, number_beams))
        .def("get_data_field_size", &RawDetection::get_data_field_size, DOC_C(RawDetection, Content, data_field_size))
        .def("get_detection_algorithm", &RawDetection::get_detection_algorithm, DOC_C(RawDetection, Content, detection_algorithm))
        .def("get_flags", &RawDetection::get_flags, DOC_C(RawDetection, Content, flags))
        .def("get_sampling_rate", &RawDetection::get_sampling_rate, DOC_C(RawDetection, Content, sampling_rate))
        .def("get_tx_angle", &RawDetection::get_tx_angle, DOC_C(RawDetection, Content, tx_angle))
        .def("get_applied_roll", &RawDetection::get_applied_roll, DOC_C(RawDetection, Content, applied_roll))
        .def("get_beam_descriptor", &RawDetection::get_beam_descriptor, DOC_C(RawDetection, get_beam_descriptor))
        .def("get_detection_point", &RawDetection::get_detection_point, DOC_C(RawDetection, get_detection_point))
        .def("get_rx_angle", &RawDetection::get_rx_angle, DOC_C(RawDetection, get_rx_angle))
        .def("get_beam_flags", &RawDetection::get_beam_flags, DOC_C(RawDetection, get_beam_flags))
        .def("get_quality", &RawDetection::get_quality, DOC_C(RawDetection, get_quality))
        .def("get_uncertainty", &RawDetection::get_uncertainty, DOC_C(RawDetection, get_uncertainty))
        .def("get_signal_strength", &RawDetection::get_signal_strength, DOC_C(RawDetection, get_signal_strength))
        .def("get_min_limit", &RawDetection::get_min_limit, DOC_C(RawDetection, get_min_limit))
        .def("get_max_limit", &RawDetection::get_max_limit, DOC_C(RawDetection, get_max_limit))
        .def("__eq__", &RawDetection::operator==, nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(RawDetection)
        __PYCLASS_DEFAULT_BINARY__(RawDetection)
        __PYCLASS_DEFAULT_PRINTING__(RawDetection);
}

} // namespace py_datagrams
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
