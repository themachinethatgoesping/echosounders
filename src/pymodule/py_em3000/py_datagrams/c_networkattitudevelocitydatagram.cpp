// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>
#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/em3000/datagrams/networkattitudevelocitydatagram.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_em3000 {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::em3000;
using datagrams::NetworkAttitudeVelocityDatagram;

#define DOC_NetworkAttitudeVelocityDatagram(ARG)                                                   \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        em3000,                                                                                    \
        datagrams,                                                                                 \
        NetworkAttitudeVelocityDatagram,                                                           \
        ARG)

void init_c_networkattitudevelocitydatagram(pybind11::module& m)
{
    py::class_<NetworkAttitudeVelocityDatagram, datagrams::EM3000Datagram>(
        m,
        "NetworkAttitudeVelocityDatagram",
        DOC(themachinethatgoesping,
            echosounders,
            em3000,
            datagrams,
            NetworkAttitudeVelocityDatagram))
        .def(py::init<>(), DOC_NetworkAttitudeVelocityDatagram(NetworkAttitudeVelocityDatagram))

        // --- convenient data access ---
        .def("set_network_attitude_counter",
             &NetworkAttitudeVelocityDatagram::set_network_attitude_counter,
             DOC_NetworkAttitudeVelocityDatagram(network_attitude_counter))
        .def("get_network_attitude_counter",
             &NetworkAttitudeVelocityDatagram::get_network_attitude_counter,
             DOC_NetworkAttitudeVelocityDatagram(network_attitude_counter))
        .def("set_system_serial_number",
             &NetworkAttitudeVelocityDatagram::set_system_serial_number,
             DOC_NetworkAttitudeVelocityDatagram(system_serial_number))
        .def("get_system_serial_number",
             &NetworkAttitudeVelocityDatagram::get_system_serial_number,
             DOC_NetworkAttitudeVelocityDatagram(system_serial_number))
        .def("set_number_of_entries",
             &NetworkAttitudeVelocityDatagram::set_number_of_entries,
             DOC_NetworkAttitudeVelocityDatagram(number_of_entries))
        .def("get_number_of_entries",
             &NetworkAttitudeVelocityDatagram::get_number_of_entries,
             DOC_NetworkAttitudeVelocityDatagram(number_of_entries))
        .def("set_sensor_system_descriptor",
             &NetworkAttitudeVelocityDatagram::set_sensor_system_descriptor,
             DOC_NetworkAttitudeVelocityDatagram(sensor_system_descriptor))
        .def("get_sensor_system_descriptor",
             &NetworkAttitudeVelocityDatagram::get_sensor_system_descriptor,
             DOC_NetworkAttitudeVelocityDatagram(sensor_system_descriptor))

        // --- data structure access ---
        .def("get_attitudes",
             &NetworkAttitudeVelocityDatagram::get_attitudes,
             DOC_NetworkAttitudeVelocityDatagram(attitudes),
             py::return_value_policy::reference_internal)
        .def("set_attitudes",
             &NetworkAttitudeVelocityDatagram::set_attitudes,
             DOC_NetworkAttitudeVelocityDatagram(attitudes))
        .def("attitudes",
             &NetworkAttitudeVelocityDatagram::attitudes,
             DOC_NetworkAttitudeVelocityDatagram(attitudes),
             py::return_value_policy::reference_internal)

        // --- processed member access ---
        .def("get_attitude_velocity_sensor_number",
             &NetworkAttitudeVelocityDatagram::get_attitude_velocity_sensor_number,
             DOC_NetworkAttitudeVelocityDatagram(get_attitude_velocity_sensor_number))
        .def("get_velocity_sensor_is_active",
             &NetworkAttitudeVelocityDatagram::get_velocity_sensor_is_active,
             DOC_NetworkAttitudeVelocityDatagram(get_velocity_sensor_is_active))
        .def("get_heading_sensor_is_active",
             &NetworkAttitudeVelocityDatagram::get_heading_sensor_is_active,
             DOC_NetworkAttitudeVelocityDatagram(get_heading_sensor_is_active))
        .def("get_roll_sensor_is_active",
             &NetworkAttitudeVelocityDatagram::get_roll_sensor_is_active,
             DOC_NetworkAttitudeVelocityDatagram(get_roll_sensor_is_active))
        .def("get_pitch_sensor_is_active",
             &NetworkAttitudeVelocityDatagram::get_pitch_sensor_is_active,
             DOC_NetworkAttitudeVelocityDatagram(get_pitch_sensor_is_active))
        .def("get_heave_sensor_is_active",
             &NetworkAttitudeVelocityDatagram::get_heave_sensor_is_active,
             DOC_NetworkAttitudeVelocityDatagram(get_heave_sensor_is_active))
        .def("get_function_is_used",
             &NetworkAttitudeVelocityDatagram::get_function_is_used,
             DOC_NetworkAttitudeVelocityDatagram(get_function_is_used))

        // --- checksum access ---
        .def("get_etx",
             &NetworkAttitudeVelocityDatagram::get_etx,
             DOC_NetworkAttitudeVelocityDatagram(etx))
        .def("set_etx",
             &NetworkAttitudeVelocityDatagram::set_etx,
             DOC_NetworkAttitudeVelocityDatagram(etx))
        .def("get_checksum",
             &NetworkAttitudeVelocityDatagram::get_checksum,
             DOC_NetworkAttitudeVelocityDatagram(checksum))
        .def("set_checksum",
             &NetworkAttitudeVelocityDatagram::set_checksum,
             DOC_NetworkAttitudeVelocityDatagram(checksum))
        .def("get_spare",
             &NetworkAttitudeVelocityDatagram::get_spare,
             DOC_NetworkAttitudeVelocityDatagram(spare))
        .def("set_spare",
             &NetworkAttitudeVelocityDatagram::set_spare,
             DOC_NetworkAttitudeVelocityDatagram(spare))
        .def("get_spare_align",
             &NetworkAttitudeVelocityDatagram::get_spare_align,
             DOC_NetworkAttitudeVelocityDatagram(spare_align))
        .def("set_spare_align",
             &NetworkAttitudeVelocityDatagram::set_spare_align,
             DOC_NetworkAttitudeVelocityDatagram(spare_align))

        // ----- operators -----
        .def("__eq__",
             &NetworkAttitudeVelocityDatagram::operator==,
             DOC_NetworkAttitudeVelocityDatagram(operator_eq),
             py::arg("other"))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(NetworkAttitudeVelocityDatagram)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(NetworkAttitudeVelocityDatagram)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(NetworkAttitudeVelocityDatagram)
        // end LinearInterpolator
        ;
}
}
}
}
}
}