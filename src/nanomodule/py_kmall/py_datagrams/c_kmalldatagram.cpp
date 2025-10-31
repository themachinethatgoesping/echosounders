// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/datetime.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/kmalldatagram.hpp>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {
namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::KMALLDatagram;

#define DOC_KMALLDatagram(arg)                                                                     \
    DOC(themachinethatgoesping, echosounders, kmall, datagrams, KMALLDatagram, arg)

void init_c_kmalldatagram(nanobind::module_& m)
{
    nb::class_<KMALLDatagram>(
        m,
        "KMALLDatagram",
        DOC(themachinethatgoesping, echosounders, kmall, datagrams, KMALLDatagram))
        .def(nb::init<>(), DOC_KMALLDatagram(KMALLDatagram))
        // --- convenient data access ---
        .def("get_bytes_datagram",
             &KMALLDatagram::get_bytes_datagram,
             DOC_KMALLDatagram(get_bytes_datagram))
        .def("set_bytes_datagram",
             &KMALLDatagram::set_bytes_datagram,
             DOC_KMALLDatagram(set_bytes_datagram),
             nb::arg("bytes_datagram"))
        .def("get_datagram_version", &KMALLDatagram::get_datagram_version, DOC_KMALLDatagram(get_datagram_version))
        .def("set_datagram_version",
             &KMALLDatagram::set_datagram_version,
             DOC_KMALLDatagram(set_datagram_version),
             nb::arg("datagram_version"))
        .def("get_system_id", &KMALLDatagram::get_system_id, DOC_KMALLDatagram(get_system_id))
        .def("set_system_id",
             &KMALLDatagram::set_system_id,
             DOC_KMALLDatagram(set_system_id),
             nb::arg("system_id"))
        .def("get_echo_sounder_id",
             &KMALLDatagram::get_echo_sounder_id,
             DOC_KMALLDatagram(get_echo_sounder_id))
        .def("set_echo_sounder_id",
             &KMALLDatagram::set_echo_sounder_id,
             DOC_KMALLDatagram(set_echo_sounder_id),
             nb::arg("echo_sounder_id"))
        .def("get_time_sec", &KMALLDatagram::get_time_sec, DOC_KMALLDatagram(get_time_sec))
        .def("set_time_sec",
             &KMALLDatagram::set_time_sec,
             DOC_KMALLDatagram(set_time_sec),
             nb::arg("time_sec"))
        .def("get_time_nanosec",
             &KMALLDatagram::get_time_nanosec,
             DOC_KMALLDatagram(get_time_nanosec))
        .def("set_time_nanosec",
             &KMALLDatagram::set_time_nanosec,
             DOC_KMALLDatagram(set_time_nanosec),
             nb::arg("time_nanosec"))

        // --- convenient processed data access ---
        .def("set_datagram_identifier",
             &KMALLDatagram::set_datagram_identifier,
             DOC_KMALLDatagram(set_datagram_identifier),
             nb::arg("datagram_identifier"))
        .def("get_datagram_identifier",
             &KMALLDatagram::get_datagram_identifier,
             DOC_KMALLDatagram(get_datagram_identifier))
        .def("compute_size_content",
             &KMALLDatagram::compute_size_content,
             DOC_KMALLDatagram(compute_size_content))

        .def("get_timestamp", &KMALLDatagram::get_timestamp, DOC_KMALLDatagram(get_timestamp))

        .def(
            "get_datetime",
            [](const KMALLDatagram& self, double timezone_offset_hours) {
                return tools::nanobind_helper::unixtime_to_datetime(self.get_timestamp(),
                                                                    timezone_offset_hours);
            },
            nb::arg("timezone_offset_hours") = 0.,
            "Return the timestamp as datetime object")

        .def("get_date_string",
             &KMALLDatagram::get_date_string,
             DOC_KMALLDatagram(get_date_string),
             nb::arg("fractional_seconds_digits") = 2,
             nb::arg("format")                    = "%z__%d-%m-%Y__%H:%M:%S")

        // ----- operators -----
        .def(
            "__eq__",
            &KMALLDatagram::operator==,
            DOC(themachinethatgoesping, echosounders, kmall, datagrams, KMALLDatagram, operator_eq),
            nb::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(KMALLDatagram)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(KMALLDatagram)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(KMALLDatagram)
        // end LinearInterpolator
        ;
}

}
}
}
}
}