// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/datetime.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams/s7kdatagram.hpp>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_datagrams {
namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::s7k;
using datagrams::S7KDatagram;

#define DOC_S7KDatagram(arg) DOC(themachinethatgoesping, echosounders, s7k, datagrams, S7KDatagram, arg)

void init_c_s7kdatagram(nanobind::module_& m)
{
    nb::class_<S7KDatagram>(
        m, "S7KDatagram", DOC(themachinethatgoesping, echosounders, s7k, datagrams, S7KDatagram))
        .def(nb::init<>(), DOC_S7KDatagram(S7KDatagram))
        // --- convenient data access ---
        .def("get_protocol_version", &S7KDatagram::get_protocol_version, DOC_S7KDatagram(get_protocol_version))
        .def("get_offset", &S7KDatagram::get_offset, DOC_S7KDatagram(get_offset))
        .def("get_sync_pattern", &S7KDatagram::get_sync_pattern, DOC_S7KDatagram(get_sync_pattern))
        .def("get_size", &S7KDatagram::get_size, DOC_S7KDatagram(get_size))
        .def("get_optional_data_offset", &S7KDatagram::get_optional_data_offset, DOC_S7KDatagram(get_optional_data_offset))
        .def("get_optional_data_identifier", &S7KDatagram::get_optional_data_identifier, DOC_S7KDatagram(get_optional_data_identifier))
        .def("get_year", &S7KDatagram::get_year, DOC_S7KDatagram(get_year))
        .def("get_day", &S7KDatagram::get_day, DOC_S7KDatagram(get_day))
        .def("get_seconds", &S7KDatagram::get_seconds, DOC_S7KDatagram(get_seconds))
        .def("get_hours", &S7KDatagram::get_hours, DOC_S7KDatagram(get_hours))
        .def("get_minutes", &S7KDatagram::get_minutes, DOC_S7KDatagram(get_minutes))
        .def("get_record_version", &S7KDatagram::get_record_version, DOC_S7KDatagram(get_record_version))
        .def("get_record_type_identifier", &S7KDatagram::get_record_type_identifier, DOC_S7KDatagram(get_record_type_identifier))
        .def("get_device_identifier", &S7KDatagram::get_device_identifier, DOC_S7KDatagram(get_device_identifier))
        .def("get_system_enumerator", &S7KDatagram::get_system_enumerator, DOC_S7KDatagram(get_system_enumerator))
        .def("get_flags", &S7KDatagram::get_flags, DOC_S7KDatagram(get_flags))

        // --- convenient processed data access ---
        .def("get_datagram_identifier", &S7KDatagram::get_datagram_identifier, DOC_S7KDatagram(get_datagram_identifier))
        .def("compute_size_content", &S7KDatagram::compute_size_content, DOC_S7KDatagram(compute_size_content))
        .def("is_valid", &S7KDatagram::is_valid, DOC_S7KDatagram(is_valid))
        .def("get_checksum_valid", &S7KDatagram::get_checksum_valid, DOC_S7KDatagram(get_checksum_valid))
        .def("get_timestamp", &S7KDatagram::get_timestamp, DOC_S7KDatagram(get_timestamp))
        .def(
            "get_datetime",
            [](const S7KDatagram& self, double timezone_offset_hours) {
                return tools::nanobind_helper::unixtime_to_datetime(self.get_timestamp(),
                                                                    timezone_offset_hours);
            },
            nb::arg("timezone_offset_hours") = 0.,
            "Return the timestamp as datetime object")
        .def("get_date_string",
             &S7KDatagram::get_date_string,
             DOC_S7KDatagram(get_date_string),
             nb::arg("fractional_seconds_digits") = 2,
             nb::arg("format")                    = "%z__%d-%m-%Y__%H:%M:%S")

        // ----- operators -----
        .def("__eq__",
             &S7KDatagram::operator==,
             DOC(themachinethatgoesping, echosounders, s7k, datagrams, S7KDatagram, operator_eq),
             nb::arg("other"))
        // ----- nanobind macros -----
        __PYCLASS_DEFAULT_COPY__(S7KDatagram)
        __PYCLASS_DEFAULT_BINARY__(S7KDatagram)
        __PYCLASS_DEFAULT_PRINTING__(S7KDatagram)
        ;
}

} // namespace py_datagrams
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
