// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/kmallsensordatagram.hpp>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::KMALLSensorDatagram;

#define DOC_KMALLSensorDatagram(ARG)                                                               \
    DOC(themachinethatgoesping, echosounders, kmall, datagrams, KMALLSensorDatagram, ARG)

void init_c_kmallsensordatagram(nanobind::module_& m)
{
    nb::class_<KMALLSensorDatagram, datagrams::KMALLDatagram>(
        m,
        "KMALLSensorDatagram",
        DOC(themachinethatgoesping, echosounders, kmall, datagrams, KMALLSensorDatagram))

        // --- convenient data access ---
        .def("get_bytes_content",
             &KMALLSensorDatagram::get_bytes_content,
             DOC_KMALLSensorDatagram(get_bytes_content))
        .def("get_sensor_system",
             &KMALLSensorDatagram::get_sensor_system,
             DOC_KMALLSensorDatagram(get_sensor_system))
        .def("get_sensor_status",
             &KMALLSensorDatagram::get_sensor_status,
             DOC_KMALLSensorDatagram(get_sensor_status))
        .def("get_padding", &KMALLSensorDatagram::get_padding, DOC_KMALLSensorDatagram(get_padding))
        .def("set_bytes_content",
             &KMALLSensorDatagram::set_bytes_content,
             DOC_KMALLSensorDatagram(set_bytes_content),
             nb::arg("value"))
        .def("set_sensor_system",
             &KMALLSensorDatagram::set_sensor_system,
             DOC_KMALLSensorDatagram(set_sensor_system),
             nb::arg("value"))
        .def("set_sensor_status",
             &KMALLSensorDatagram::set_sensor_status,
             DOC_KMALLSensorDatagram(set_sensor_status),
             nb::arg("value"))
        .def("set_padding",
             &KMALLSensorDatagram::set_padding,
             DOC_KMALLSensorDatagram(set_padding),
             nb::arg("value"))

        // ----- operators -----
        .def("__eq__",
             &KMALLSensorDatagram::operator==,
             DOC_KMALLSensorDatagram(operator_eq),
             nb::arg("other"));
}
}
}
}
}
}