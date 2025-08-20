// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>


#include "../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/attitudedatagram.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::AttitudeDatagram;

#define DOC_AttitudeDatagram(ARG)                                                                  \
    DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, AttitudeDatagram, ARG)

void init_c_attitudedatagram(pybind11::module& m)
{
    py::class_<AttitudeDatagram, datagrams::KongsbergAllDatagram>(
        m,
        "AttitudeDatagram",
        DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, AttitudeDatagram))
        .def(py::init<>(), DOC_AttitudeDatagram(AttitudeDatagram))

        // --- convenient data access ---
        .def("set_attitude_counter",
             &AttitudeDatagram::set_attitude_counter,
             DOC_AttitudeDatagram(attitude_counter))
        .def("get_attitude_counter",
             &AttitudeDatagram::get_attitude_counter,
             DOC_AttitudeDatagram(attitude_counter))
        .def("set_system_serial_number",
             &AttitudeDatagram::set_system_serial_number,
             DOC_AttitudeDatagram(system_serial_number))
        .def("get_system_serial_number",
             &AttitudeDatagram::get_system_serial_number,
             DOC_AttitudeDatagram(system_serial_number))
        .def("set_number_of_entries",
             &AttitudeDatagram::set_number_of_entries,
             DOC_AttitudeDatagram(number_of_entries))
        .def("get_number_of_entries",
             &AttitudeDatagram::get_number_of_entries,
             DOC_AttitudeDatagram(number_of_entries))
        .def("set_sensor_system_descriptor",
             &AttitudeDatagram::set_sensor_system_descriptor,
             DOC_AttitudeDatagram(sensor_system_descriptor))
        .def("get_sensor_system_descriptor",
             &AttitudeDatagram::get_sensor_system_descriptor,
             DOC_AttitudeDatagram(sensor_system_descriptor))

        // --- data structure access ---
        .def("get_attitudes",
             &AttitudeDatagram::get_attitudes,
             DOC_AttitudeDatagram(attitudes),
             py::return_value_policy::reference_internal)
        .def("set_attitudes", &AttitudeDatagram::set_attitudes, DOC_AttitudeDatagram(attitudes))
        .def("attitudes",
             &AttitudeDatagram::attitudes,
             DOC_AttitudeDatagram(attitudes),
             py::return_value_policy::reference_internal)

        // --- processed member access ---
        .def("get_attitude_sensor_number",
             &AttitudeDatagram::get_attitude_sensor_number,
             DOC_AttitudeDatagram(get_attitude_sensor_number))
        .def("get_heading_sensor_is_active",
             &AttitudeDatagram::get_heading_sensor_is_active,
             DOC_AttitudeDatagram(get_heading_sensor_is_active))
        .def("get_roll_sensor_is_active",
             &AttitudeDatagram::get_roll_sensor_is_active,
             DOC_AttitudeDatagram(get_roll_sensor_is_active))
        .def("get_pitch_sensor_is_active",
             &AttitudeDatagram::get_pitch_sensor_is_active,
             DOC_AttitudeDatagram(get_pitch_sensor_is_active))
        .def("get_heave_sensor_is_active",
             &AttitudeDatagram::get_heave_sensor_is_active,
             DOC_AttitudeDatagram(get_heave_sensor_is_active))

        // --- checksum access ---
        .def("get_etx", &AttitudeDatagram::get_etx, DOC_AttitudeDatagram(etx))
        .def("set_etx", &AttitudeDatagram::set_etx, DOC_AttitudeDatagram(etx))
        .def("get_checksum", &AttitudeDatagram::get_checksum, DOC_AttitudeDatagram(checksum))
        .def("set_checksum", &AttitudeDatagram::set_checksum, DOC_AttitudeDatagram(checksum))

        // ----- operators -----
        .def("__eq__",
             &AttitudeDatagram::operator==,
             DOC_AttitudeDatagram(operator_eq),
             py::arg("other"))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(AttitudeDatagram)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(AttitudeDatagram)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(AttitudeDatagram)
        // end LinearInterpolator
        ;
}
}
}
}
}
}