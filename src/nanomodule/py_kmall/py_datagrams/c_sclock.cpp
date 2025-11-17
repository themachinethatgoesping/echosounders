// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/datetime.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/sclock.hpp>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::SClock;

#define DOC_SClock(ARG) DOC(themachinethatgoesping, echosounders, kmall, datagrams, SClock, ARG)

void init_c_sclock(nanobind::module_& m)
{
    nb::class_<SClock, datagrams::KMALLSensorDatagram>(
        m, "SClock", DOC(themachinethatgoesping, echosounders, kmall, datagrams, SClock))
        .def(nb::init<>(), DOC_SClock(SClock))

        // --- convenient data access ---
        .def("get_offset_sec", &SClock::get_offset_sec, DOC_SClock(get_offset_sec))
        .def("get_clock_dev_pu_microsec",
             &SClock::get_clock_dev_pu_microsec,
             DOC_SClock(get_clock_dev_pu_microsec))
        .def(
            "get_clock_data_from_sensor",
            [](const SClock& self) {
                const auto& data = self.get_clock_data_from_sensor();
                return nb::bytes(data.data(), data.size());
            },
            DOC_SClock(get_clock_data_from_sensor))
        .def("get_clock_data_from_sensor_str",
             &SClock::get_clock_data_from_sensor,
             DOC_SClock(get_clock_data_from_sensor))
        .def("get_bytes_datagram_check",
             &SClock::get_bytes_datagram_check,
             DOC_SClock(get_bytes_datagram_check))
        .def("set_offset_sec",
             &SClock::set_offset_sec,
             DOC_SClock(set_offset_sec),
             nb::arg("offset_sec"))
        .def("set_clock_dev_pu_microsec",
             &SClock::set_clock_dev_pu_microsec,
             DOC_SClock(set_clock_dev_pu_microsec),
             nb::arg("clock_dev_pu_microsec"))
        .def("set_clock_data_from_sensor",
             &SClock::set_clock_data_from_sensor,
             DOC_SClock(set_clock_data_from_sensor),
             nb::arg("pos_data"))
        .def("set_bytes_datagram_check",
             &SClock::set_bytes_datagram_check,
             DOC_SClock(set_bytes_datagram_check),
             nb::arg("val"))

        // ----- processed -----

        // ----- operators -----
        .def("__eq__", &SClock::operator==, DOC_SClock(operator_eq), nb::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(SClock)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(SClock)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(SClock)
        // end LinearInterpolator
        ;
}
}
}
}
}
}