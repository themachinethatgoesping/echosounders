// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

// xtensor python includes
#include <xtensor-python/pyarray.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // implicit conversion xtensor <-> numpy

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>
#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/em3000/datagrams/installationparameters.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_em3000 {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::em3000;
using datagrams::InstallationParameters;

#define DOC_InstallationParameters(ARG)                                                            \
    DOC(themachinethatgoesping, echosounders, em3000, datagrams, InstallationParameters, ARG)

void init_c_installationparameter_enums(pybind11::module& m)
{
    // using datagrams::InstallationParameters::t_ActiveAttitudeSensor;

    auto pyenum_activerollpitchsensor =
        py::enum_<InstallationParameters::t_ActiveAttitudeSensor>(
            m,
            "InstallationParameters_t_ActiveAttitudeSensor",
            DOC_InstallationParameters(t_ActiveAttitudeSensor))
            .value("MotionSensor1", InstallationParameters::t_ActiveAttitudeSensor::MotionSensor1)
            .value("MotionSensor2", InstallationParameters::t_ActiveAttitudeSensor::MotionSensor2)
            .value("AttitudeVelocitySensor1",
                   InstallationParameters::t_ActiveAttitudeSensor::AttitudeVelocitySensor1)
            .value("AttitudeVelocitySensor2",
                   InstallationParameters::t_ActiveAttitudeSensor::AttitudeVelocitySensor2)
            .export_values()
        //
        ;

    auto pyenum_activeheadingsensor =
        py::enum_<InstallationParameters::t_ActiveHeadingSensor>(
            m,
            "InstallationParameters_t_ActiveHeadingSensor",
            DOC_InstallationParameters(t_ActiveHeadingSensor))
            .value("PositionSystem3",
                   InstallationParameters::t_ActiveHeadingSensor::PositionSystem3)
            .value("PositionSystem1",
                   InstallationParameters::t_ActiveHeadingSensor::PositionSystem1)
            .value("PositionSystem2",
                   InstallationParameters::t_ActiveHeadingSensor::PositionSystem2)
            .value("MotionSensor1", InstallationParameters::t_ActiveHeadingSensor::MotionSensor1)
            .value("MotionSensor2", InstallationParameters::t_ActiveHeadingSensor::MotionSensor2)
            .value("MultiCast1", InstallationParameters::t_ActiveHeadingSensor::MultiCast1)
            .value("MultiCast2", InstallationParameters::t_ActiveHeadingSensor::MultiCast2)
            .value("MultiCast3", InstallationParameters::t_ActiveHeadingSensor::MultiCast3)
            .value("AttitudeVelocitySensor1",
                   InstallationParameters::t_ActiveHeadingSensor::AttitudeVelocitySensor1)
            .value("AttitudeVelocitySensor2",
                   InstallationParameters::t_ActiveHeadingSensor::AttitudeVelocitySensor2)
            .export_values()
        //
        ;

    tools::pybind_helper::add_string_to_enum_conversion<
        InstallationParameters::t_ActiveAttitudeSensor>(pyenum_activerollpitchsensor);
    tools::pybind_helper::add_string_to_enum_conversion<
        InstallationParameters::t_ActiveHeadingSensor>(pyenum_activeheadingsensor);
}

void init_c_installationparameters(pybind11::module& m)
{
    init_c_installationparameter_enums(m);

    py::class_<InstallationParameters, datagrams::EM3000Datagram>(
        m,
        "InstallationParameters",
        DOC(themachinethatgoesping, echosounders, em3000, datagrams, InstallationParameters))
        .def(py::init<>(), DOC_InstallationParameters(InstallationParameters))
        // --- convenient data access ---
        .def("set_installation_parameters_counter",
             &InstallationParameters::set_installation_parameters_counter,
             DOC_InstallationParameters(installation_parameters_counter))
        .def("get_installation_parameters_counter",
             &InstallationParameters::get_installation_parameters_counter,
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
        .def("get_installation_parameters",
             &InstallationParameters::get_installation_parameters,
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
        .def("get_installation_parameters_parsed",
             &InstallationParameters::get_installation_parameters_parsed,
             DOC_InstallationParameters(get_installation_parameters_parsed),
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
             py::overload_cast<InstallationParameters::t_ActiveAttitudeSensor>(
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
        .def("get_active_roll_pitch_sensor",
             &InstallationParameters::get_active_roll_pitch_sensor,
             DOC_InstallationParameters(get_active_roll_pitch_sensor))
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
        .def("get_tx_serial_number",
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