// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

// xtensor python includes
#include <xtensor-python/pytensor.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // implicit conversion xtensor <-> numpy

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>
#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/installationparameters.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::InstallationParameters;

#define DOC_InstallationParameters(ARG)                                                            \
    DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, InstallationParameters, ARG)

void init_c_installationparameters(pybind11::module& m)
{
    py::class_<InstallationParameters, datagrams::KongsbergAllDatagram>(
        m,
        "InstallationParameters",
        DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, InstallationParameters))
        .def(py::init<>(), DOC_InstallationParameters(InstallationParameters))
        // --- convenient data access ---
        .def("set_installation_parameters_counter",
             &InstallationParameters::set_installation_parameters_counter,
             DOC_InstallationParameters(installation_parameters_counter))
        .def("read_installation_parameters_counter",
             &InstallationParameters::read_installation_parameters_counter,
             DOC_InstallationParameters(installation_parameters_counter))
        .def("set_system_serial_number",
             &InstallationParameters::set_system_serial_number,
             DOC_InstallationParameters(system_serial_number))
        .def("get_system_serial_number",
             &InstallationParameters::get_system_serial_number,
             DOC_InstallationParameters(system_serial_number))
        .def("set_secondary_system_serial_number",
             &InstallationParameters::set_secondary_system_serial_number,
             DOC_InstallationParameters(secondary_system_serial_number))
        .def("get_secondary_system_serial_number",
             &InstallationParameters::get_secondary_system_serial_number,
             DOC_InstallationParameters(secondary_system_serial_number))

        // --- data structure access ---
        .def("read_installation_parameters",
             &InstallationParameters::read_installation_parameters,
             DOC_InstallationParameters(installation_parameters),
             py::return_value_policy::reference_internal)
        .def("set_installation_parameters",
             &InstallationParameters::set_installation_parameters,
             DOC_InstallationParameters(installation_parameters))
        //    .def("installation_parameters",
        //         &InstallationParameters::installation_parameters,
        //         DOC_InstallationParameters(installation_parameters),
        //         py::return_value_policy::reference_internal)

        // --- processed member access ---
        .def("read_installation_parameters_parsed",
             &InstallationParameters::read_installation_parameters_parsed,
             DOC_InstallationParameters(read_installation_parameters_parsed),
             py::return_value_policy::reference_internal)

        // --- public data members ---
        .def("reparse_installation_parameters",
             &InstallationParameters::reparse_installation_parameters,
             DOC_InstallationParameters(reparse_installation_parameters))
        .def_static("merge",
                    &InstallationParameters::merge,
                    DOC_InstallationParameters(merge),
                    py::arg("datagram_1"),
                    py::arg("datagram_2"))

        // --- processed access of installation parameters ---
        .def("get_compass_offsets",
             &InstallationParameters::get_compass_offsets,
             DOC_InstallationParameters(get_compass_offsets))
        .def("get_depth_sensor_offsets",
             &InstallationParameters::get_depth_sensor_offsets,
             DOC_InstallationParameters(get_depth_sensor_offsets))
        .def("get_attitude_sensor_offsets",
             py::overload_cast<t_KongsbergAllActiveSensor>(
                 &InstallationParameters::get_attitude_sensor_offsets, py::const_),
             DOC_InstallationParameters(get_attitude_sensor_offsets),
             py::arg("sensor_number"))
        .def("get_attitude_sensor_offsets",
             py::overload_cast<uint8_t>(&InstallationParameters::get_attitude_sensor_offsets,
                                        py::const_),
             DOC_InstallationParameters(get_attitude_sensor_offsets),
             py::arg("sensor"))
        .def("get_position_system_offsets",
             &InstallationParameters::get_position_system_offsets,
             DOC_InstallationParameters(get_position_system_offsets),
             py::arg("position_system_number"))
        .def("get_transducer_offsets",
             &InstallationParameters::get_transducer_offsets,
             DOC_InstallationParameters(get_transducer_offsets),
             py::arg("transducer_number"),
             py::arg("transducer_name") = "")
        .def("get_active_pitch_roll_sensor",
             &InstallationParameters::get_active_pitch_roll_sensor,
             DOC_InstallationParameters(get_active_pitch_roll_sensor))
        .def("get_active_position_system_number",
             &InstallationParameters::get_active_position_system_number,
             DOC_InstallationParameters(get_active_position_system_number))
        .def("get_active_attitude_velocity_sensor",
             &InstallationParameters::get_active_attitude_velocity_sensor,
             DOC_InstallationParameters(get_active_attitude_velocity_sensor))
        .def("get_active_heave_sensor",
             &InstallationParameters::get_active_heave_sensor,
             DOC_InstallationParameters(get_active_heave_sensor))
        .def("get_active_heading_sensor",
             &InstallationParameters::get_active_heading_sensor,
             DOC_InstallationParameters(get_active_heading_sensor))

        .def("get_sensor_offsets",
             &InstallationParameters::get_sensor_offsets,
             DOC_InstallationParameters(get_sensor_offsets),
             py::arg("sensor_name"),
             py::arg("sensor_prefix"),
             py::arg("has_xyz") = true,
             py::arg("has_ypr") = true)

        // ----- high level access to installation parameters -----
        .def("get_water_line_vertical_location_in_meters",
             &InstallationParameters::get_water_line_vertical_location_in_meters,
             DOC_InstallationParameters(get_water_line_vertical_location_in_meters))
        .def("get_system_main_head_serial_number",
             &InstallationParameters::get_system_main_head_serial_number,
             DOC_InstallationParameters(get_system_main_head_serial_number))
        .def("get_tx_serial_number",
             &InstallationParameters::get_tx_serial_number,
             DOC_InstallationParameters(get_tx_serial_number))
        .def("get_tx2_serial_number",
             &InstallationParameters::get_tx2_serial_number,
             DOC_InstallationParameters(get_tx2_serial_number))
        .def("get_rx1_serial_number",
             &InstallationParameters::get_rx1_serial_number,
             DOC_InstallationParameters(get_rx1_serial_number))
        .def("get_rx2_serial_number",
             &InstallationParameters::get_rx2_serial_number,
             DOC_InstallationParameters(get_rx2_serial_number))
        .def("get_system_transducer_configuration",
             &InstallationParameters::get_system_transducer_configuration,
             DOC_InstallationParameters(get_system_transducer_configuration))
        .def("get_tx_array_size",
             &InstallationParameters::get_tx_array_size,
             DOC_InstallationParameters(get_tx_array_size))
        .def("get_rx_array_size",
             &InstallationParameters::get_rx_array_size,
             DOC_InstallationParameters(get_rx_array_size))

        // --- flags ---
        .def("build_channel_id",
             &InstallationParameters::build_channel_id,
             DOC_InstallationParameters(build_channel_id))
        .def("is_dual_rx",
             &InstallationParameters::is_dual_rx,
             DOC_InstallationParameters(is_dual_rx))

        // --- checksum access ---
        .def("get_etx", &InstallationParameters::get_etx, DOC_InstallationParameters(etx))
        .def("set_etx", &InstallationParameters::set_etx, DOC_InstallationParameters(etx))
        .def("get_checksum",
             &InstallationParameters::get_checksum,
             DOC_InstallationParameters(checksum))
        .def("set_checksum",
             &InstallationParameters::set_checksum,
             DOC_InstallationParameters(checksum))

        // ----- operators -----
        .def("__eq__",
             &InstallationParameters::operator==,
             DOC_InstallationParameters(operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(InstallationParameters)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(InstallationParameters)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(InstallationParameters)
        // end LinearInterpolator
        ;
}
}
}
}
}
}