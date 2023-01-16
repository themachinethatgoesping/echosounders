// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>
#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/em3000/datagrams/clockdatagram.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_em3000 {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::em3000;
using datagrams::ClockDatagram;

#define DOC_ClockDatagram(ARG)                                                                     \
    DOC(themachinethatgoesping, echosounders, em3000, datagrams, ClockDatagram, ARG)

void init_c_clockdatagram(pybind11::module& m)
{
    py::class_<ClockDatagram, datagrams::EM3000Datagram>(
        m,
        "ClockDatagram",
        DOC(themachinethatgoesping, echosounders, em3000, datagrams, ClockDatagram))
        .def(py::init<>(), DOC_ClockDatagram(ClockDatagram))

        // --- convenient data access ---
        .def("set_clock_counter",
             &ClockDatagram::set_clock_counter,
             DOC_ClockDatagram(clock_counter))
        .def("get_clock_counter",
             &ClockDatagram::get_clock_counter,
             DOC_ClockDatagram(clock_counter))
        .def("set_system_serial_number",
             &ClockDatagram::set_system_serial_number,
             DOC_ClockDatagram(system_serial_number))
        .def("get_system_serial_number",
             &ClockDatagram::get_system_serial_number,
             DOC_ClockDatagram(system_serial_number))
        .def("set_date_external",
             &ClockDatagram::set_date_external,
             DOC_ClockDatagram(date_external))
        .def("get_date_external",
             &ClockDatagram::get_date_external,
             DOC_ClockDatagram(date_external))
        .def("set_time_since_midnight_external",
             &ClockDatagram::set_time_since_midnight_external,
             DOC_ClockDatagram(time_since_midnight_external))
        .def("get_time_since_midnight_external",
             &ClockDatagram::get_time_since_midnight_external,
             DOC_ClockDatagram(time_since_midnight_external))
        .def("set_pps_active", &ClockDatagram::set_pps_active, DOC_ClockDatagram(pps_active))
        .def("get_pps_active", &ClockDatagram::get_pps_active, DOC_ClockDatagram(pps_active))

        // --- processed member access ---
        .def("get_timestamp_external",
             &ClockDatagram::get_timestamp_external,
             DOC_ClockDatagram(get_timestamp_external))
        .def("get_timestamp_offset",
             &ClockDatagram::get_timestamp_offset,
             DOC_ClockDatagram(get_timestamp_offset))

        // --- checksum access ---
        .def("get_etx", &ClockDatagram::get_etx, DOC_ClockDatagram(etx))
        .def("set_etx", &ClockDatagram::set_etx, DOC_ClockDatagram(etx))
        .def("get_checksum", &ClockDatagram::get_checksum, DOC_ClockDatagram(checksum))
        .def("set_checksum", &ClockDatagram::set_checksum, DOC_ClockDatagram(checksum))

        // ----- operators -----
        .def("__eq__", &ClockDatagram::operator==, DOC_ClockDatagram(operator_eq), py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(ClockDatagram)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(ClockDatagram)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(ClockDatagram)
        // end LinearInterpolator
        ;
}
}
}
}
}
}