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
        .def("set_serial_number", &RawDetection::set_serial_number, DOC_C(RawDetection, Content, serial_number), nb::arg("val"))
        .def("get_ping_number", &RawDetection::get_ping_number, DOC_C(RawDetection, Content, ping_number))
        .def("set_ping_number", &RawDetection::set_ping_number, DOC_C(RawDetection, Content, ping_number), nb::arg("val"))
        .def("get_multi_ping", &RawDetection::get_multi_ping, DOC_C(RawDetection, Content, multi_ping))
        .def("set_multi_ping", &RawDetection::set_multi_ping, DOC_C(RawDetection, Content, multi_ping), nb::arg("val"))
        .def("get_number_beams", &RawDetection::get_number_beams, DOC_C(RawDetection, Content, number_beams))
        .def("set_number_beams", &RawDetection::set_number_beams, DOC_C(RawDetection, Content, number_beams), nb::arg("val"))
        .def("get_data_field_size", &RawDetection::get_data_field_size, DOC_C(RawDetection, Content, data_field_size))
        .def("set_data_field_size", &RawDetection::set_data_field_size, DOC_C(RawDetection, Content, data_field_size), nb::arg("val"))
        .def("get_detection_algorithm", &RawDetection::get_detection_algorithm, DOC_C(RawDetection, Content, detection_algorithm))
        .def("set_detection_algorithm", &RawDetection::set_detection_algorithm, DOC_C(RawDetection, Content, detection_algorithm), nb::arg("val"))
        .def("get_flags", &RawDetection::get_flags, DOC_C(RawDetection, Content, flags))
        .def("set_flags", &RawDetection::set_flags, DOC_C(RawDetection, Content, flags), nb::arg("val"))
        .def("get_sampling_rate", &RawDetection::get_sampling_rate, DOC_C(RawDetection, Content, sampling_rate))
        .def("set_sampling_rate", &RawDetection::set_sampling_rate, DOC_C(RawDetection, Content, sampling_rate), nb::arg("val"))
        .def("get_tx_angle", &RawDetection::get_tx_angle, DOC_C(RawDetection, Content, tx_angle))
        .def("set_tx_angle", &RawDetection::set_tx_angle, DOC_C(RawDetection, Content, tx_angle), nb::arg("val"))
        .def("get_applied_roll", &RawDetection::get_applied_roll, DOC_C(RawDetection, Content, applied_roll))
        .def("set_applied_roll", &RawDetection::set_applied_roll, DOC_C(RawDetection, Content, applied_roll), nb::arg("val"))
        .def_prop_rw("beams",
                     &RawDetection::beams,
                     &RawDetection::set_beams,
                     DOC_C(RawDetection, beams),
                     nb::rv_policy::reference_internal)
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
