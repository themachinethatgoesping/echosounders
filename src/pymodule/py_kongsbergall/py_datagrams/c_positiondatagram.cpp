// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>
#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/positiondatagram.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::PositionDatagram;

#define DOC_PositionDatagram(ARG)                                                                  \
    DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, PositionDatagram, ARG)

void init_c_positiondatagram(pybind11::module& m)
{
    py::class_<PositionDatagram, datagrams::KongsbergAllDatagram>(
        m,
        "PositionDatagram",
        DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, PositionDatagram))
        .def(py::init<>(), DOC_PositionDatagram(PositionDatagram))

        // --- convenient data access ---
        .def("set_position_counter",
             &PositionDatagram::set_position_counter,
             DOC_PositionDatagram(position_counter))
        .def("get_position_counter",
             &PositionDatagram::get_position_counter,
             DOC_PositionDatagram(position_counter))
        .def("set_system_serial_number",
             &PositionDatagram::set_system_serial_number,
             DOC_PositionDatagram(system_serial_number))
        .def("get_system_serial_number",
             &PositionDatagram::get_system_serial_number,
             DOC_PositionDatagram(system_serial_number))
        .def("set_latitude", &PositionDatagram::set_latitude, DOC_PositionDatagram(latitude))
        .def("get_latitude", &PositionDatagram::get_latitude, DOC_PositionDatagram(latitude))
        .def("set_longitude", &PositionDatagram::set_longitude, DOC_PositionDatagram(longitude))
        .def("get_longitude", &PositionDatagram::get_longitude, DOC_PositionDatagram(longitude))
        .def("set_position_fix_quality",
             &PositionDatagram::set_position_fix_quality,
             DOC_PositionDatagram(position_fix_quality))
        .def("get_position_fix_quality",
             &PositionDatagram::get_position_fix_quality,
             DOC_PositionDatagram(position_fix_quality))
        .def("set_speed", &PositionDatagram::set_speed, DOC_PositionDatagram(speed))
        .def("get_speed", &PositionDatagram::get_speed, DOC_PositionDatagram(speed))
        .def("set_course", &PositionDatagram::set_course, DOC_PositionDatagram(course))
        .def("get_course", &PositionDatagram::get_course, DOC_PositionDatagram(course))
        .def("set_heading", &PositionDatagram::set_heading, DOC_PositionDatagram(heading))
        .def("get_heading", &PositionDatagram::get_heading, DOC_PositionDatagram(heading))
        .def("set_position_system_descriptor",
             &PositionDatagram::set_position_system_descriptor,
             DOC_PositionDatagram(position_system_descriptor))
        .def("get_position_system_descriptor",
             &PositionDatagram::get_position_system_descriptor,
             DOC_PositionDatagram(position_system_descriptor))
        .def("set_size_of_input_datagram",
             &PositionDatagram::set_size_of_input_datagram,
             DOC_PositionDatagram(size_of_input_datagram))
        .def("get_size_of_input_datagram",
             &PositionDatagram::get_size_of_input_datagram,
             DOC_PositionDatagram(size_of_input_datagram))
        .def("set_input_datagram",
             &PositionDatagram::set_input_datagram,
             DOC_PositionDatagram(set_input_datagram))
        .def("get_input_datagram",
             &PositionDatagram::get_input_datagram,
             DOC_PositionDatagram(get_input_datagram))

        // --- processed member access ---
        .def("get_latitude_in_degrees",
             &PositionDatagram::get_latitude_in_degrees,
             DOC_PositionDatagram(get_latitude_in_degrees))
        .def("get_longitude_in_degrees",
             &PositionDatagram::get_longitude_in_degrees,
             DOC_PositionDatagram(get_longitude_in_degrees))
        .def("get_position_fix_quality_in_meters",
             &PositionDatagram::get_position_fix_quality_in_meters,
             DOC_PositionDatagram(get_position_fix_quality_in_meters))
        .def("get_speed_in_meters_per_second",
             &PositionDatagram::get_speed_in_meters_per_second,
             DOC_PositionDatagram(get_speed_in_meters_per_second))
        .def("get_course_in_degrees",
             &PositionDatagram::get_course_in_degrees,
             DOC_PositionDatagram(get_course_in_degrees))
        .def("get_heading_in_degrees",
             &PositionDatagram::get_heading_in_degrees,
             DOC_PositionDatagram(get_heading_in_degrees))
        .def("get_position_system_number",
             &PositionDatagram::get_position_system_number,
             DOC_PositionDatagram(get_position_system_number))
        .def("get_position_system_SIMRAD90_flag",
             &PositionDatagram::get_position_system_SIMRAD90_flag,
             DOC_PositionDatagram(get_position_system_SIMRAD90_flag))
        .def("get_position_system_system_time_has_been_used",
             &PositionDatagram::get_position_system_system_time_has_been_used,
             DOC_PositionDatagram(get_position_system_system_time_has_been_used))

        // --- checksum access ---
        .def("set_spare", &PositionDatagram::set_spare, DOC_PositionDatagram(spare))
        .def("get_spare", &PositionDatagram::get_spare, DOC_PositionDatagram(spare))
        .def("get_etx", &PositionDatagram::get_etx, DOC_PositionDatagram(etx))
        .def("set_etx", &PositionDatagram::set_etx, DOC_PositionDatagram(etx))
        .def("get_checksum", &PositionDatagram::get_checksum, DOC_PositionDatagram(checksum))
        .def("set_checksum", &PositionDatagram::set_checksum, DOC_PositionDatagram(checksum))

        // ----- operators -----
        .def("__eq__",
             &PositionDatagram::operator==,
             DOC_PositionDatagram(operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(PositionDatagram)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(PositionDatagram)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(PositionDatagram)
        // end LinearInterpolator
        ;
}
}
}
}
}
}