// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>
#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/pustatusoutput.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::PUStatusOutput;

#define DOC_PUStatusOutput(ARG)                                                                    \
    DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, PUStatusOutput, ARG)

void init_c_pustatusoutput(pybind11::module& m)
{
    py::class_<PUStatusOutput, datagrams::KongsbergAllDatagram>(
        m,
        "PUStatusOutput",
        DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, PUStatusOutput))
        .def(py::init<>(), DOC_PUStatusOutput(PUStatusOutput))

        // --- convenient data access ---
        .def("set_status_datagram_counter",
             &PUStatusOutput::set_status_datagram_counter,
             DOC_PUStatusOutput(status_datagram_counter))
        .def("get_status_datagram_counter",
             &PUStatusOutput::get_status_datagram_counter,
             DOC_PUStatusOutput(status_datagram_counter))
        .def("set_system_serial_number",
             &PUStatusOutput::set_system_serial_number,
             DOC_PUStatusOutput(system_serial_number))
        .def("get_system_serial_number",
             &PUStatusOutput::get_system_serial_number,
             DOC_PUStatusOutput(system_serial_number))
        .def("set_ping_rate", &PUStatusOutput::set_ping_rate, DOC_PUStatusOutput(ping_rate))
        .def("get_ping_rate", &PUStatusOutput::get_ping_rate, DOC_PUStatusOutput(ping_rate))
        .def(
            "set_ping_counter", &PUStatusOutput::set_ping_counter, DOC_PUStatusOutput(ping_counter))
        .def(
            "get_ping_counter", &PUStatusOutput::get_ping_counter, DOC_PUStatusOutput(ping_counter))
        .def("set_distance_between_swath",
             &PUStatusOutput::set_distance_between_swath,
             DOC_PUStatusOutput(distance_between_swath))
        .def("get_distance_between_swath",
             &PUStatusOutput::get_distance_between_swath,
             DOC_PUStatusOutput(distance_between_swath))
        .def("set_sensor_input_status_udp_port_2",
             &PUStatusOutput::set_sensor_input_status_udp_port_2,
             DOC_PUStatusOutput(sensor_input_status_udp_port_2))
        .def("get_sensor_input_status_udp_port_2",
             &PUStatusOutput::get_sensor_input_status_udp_port_2,
             DOC_PUStatusOutput(sensor_input_status_udp_port_2))
        .def("set_sensor_input_status_serial_port_1",
             &PUStatusOutput::set_sensor_input_status_serial_port_1,
             DOC_PUStatusOutput(sensor_input_status_serial_port_1))
        .def("get_sensor_input_status_serial_port_1",
             &PUStatusOutput::get_sensor_input_status_serial_port_1,
             DOC_PUStatusOutput(sensor_input_status_serial_port_1))
        .def("set_sensor_input_status_serial_port_2",
             &PUStatusOutput::set_sensor_input_status_serial_port_2,
             DOC_PUStatusOutput(sensor_input_status_serial_port_2))
        .def("get_sensor_input_status_serial_port_2",
             &PUStatusOutput::get_sensor_input_status_serial_port_2,
             DOC_PUStatusOutput(sensor_input_status_serial_port_2))
        .def("set_sensor_input_status_serial_port_3",
             &PUStatusOutput::set_sensor_input_status_serial_port_3,
             DOC_PUStatusOutput(sensor_input_status_serial_port_3))
        .def("get_sensor_input_status_serial_port_3",
             &PUStatusOutput::get_sensor_input_status_serial_port_3,
             DOC_PUStatusOutput(sensor_input_status_serial_port_3))
        .def("set_sensor_input_status_serial_port_4",
             &PUStatusOutput::set_sensor_input_status_serial_port_4,
             DOC_PUStatusOutput(sensor_input_status_serial_port_4))
        .def("get_sensor_input_status_serial_port_4",
             &PUStatusOutput::get_sensor_input_status_serial_port_4,
             DOC_PUStatusOutput(sensor_input_status_serial_port_4))
        .def("set_pps_status", &PUStatusOutput::set_pps_status, DOC_PUStatusOutput(pps_status))
        .def("get_pps_status", &PUStatusOutput::get_pps_status, DOC_PUStatusOutput(pps_status))
        .def("set_position_status",
             &PUStatusOutput::set_position_status,
             DOC_PUStatusOutput(position_status))
        .def("get_position_status",
             &PUStatusOutput::get_position_status,
             DOC_PUStatusOutput(position_status))
        .def("set_attitude_status",
             &PUStatusOutput::set_attitude_status,
             DOC_PUStatusOutput(attitude_status))
        .def("get_attitude_status",
             &PUStatusOutput::get_attitude_status,
             DOC_PUStatusOutput(attitude_status))
        .def(
            "set_clock_status", &PUStatusOutput::set_clock_status, DOC_PUStatusOutput(clock_status))
        .def(
            "get_clock_status", &PUStatusOutput::get_clock_status, DOC_PUStatusOutput(clock_status))
        .def("set_heading_status",
             &PUStatusOutput::set_heading_status,
             DOC_PUStatusOutput(heading_status))
        .def("get_heading_status",
             &PUStatusOutput::get_heading_status,
             DOC_PUStatusOutput(heading_status))
        .def("set_pu_status", &PUStatusOutput::set_pu_status, DOC_PUStatusOutput(pu_status))
        .def("get_pu_status", &PUStatusOutput::get_pu_status, DOC_PUStatusOutput(pu_status))
        .def("set_last_received_heading",
             &PUStatusOutput::set_last_received_heading,
             DOC_PUStatusOutput(last_received_heading))
        .def("get_last_received_heading",
             &PUStatusOutput::get_last_received_heading,
             DOC_PUStatusOutput(last_received_heading))
        .def("set_last_received_roll",
             &PUStatusOutput::set_last_received_roll,
             DOC_PUStatusOutput(last_received_roll))
        .def("get_last_received_roll",
             &PUStatusOutput::get_last_received_roll,
             DOC_PUStatusOutput(last_received_roll))
        .def("set_last_received_pitch",
             &PUStatusOutput::set_last_received_pitch,
             DOC_PUStatusOutput(last_received_pitch))
        .def("get_last_received_pitch",
             &PUStatusOutput::get_last_received_pitch,
             DOC_PUStatusOutput(last_received_pitch))
        .def("set_last_received_heave_at_sonar_head",
             &PUStatusOutput::set_last_received_heave_at_sonar_head,
             DOC_PUStatusOutput(last_received_heave_at_sonar_head))
        .def("get_last_received_heave_at_sonar_head",
             &PUStatusOutput::get_last_received_heave_at_sonar_head,
             DOC_PUStatusOutput(last_received_heave_at_sonar_head))
        .def("set_sound_speed_at_transducer",
             &PUStatusOutput::set_sound_speed_at_transducer,
             DOC_PUStatusOutput(sound_speed_at_transducer))
        .def("get_sound_speed_at_transducer",
             &PUStatusOutput::get_sound_speed_at_transducer,
             DOC_PUStatusOutput(sound_speed_at_transducer))
        .def("set_last_received_depth",
             &PUStatusOutput::set_last_received_depth,
             DOC_PUStatusOutput(last_received_depth))
        .def("get_last_received_depth",
             &PUStatusOutput::get_last_received_depth,
             DOC_PUStatusOutput(last_received_depth))
        .def("set_along_ship_velocity",
             &PUStatusOutput::set_along_ship_velocity,
             DOC_PUStatusOutput(along_ship_velocity))
        .def("get_along_ship_velocity",
             &PUStatusOutput::get_along_ship_velocity,
             DOC_PUStatusOutput(along_ship_velocity))
        .def("set_attitude_velocity_sensor_status",
             &PUStatusOutput::set_attitude_velocity_sensor_status,
             DOC_PUStatusOutput(attitude_velocity_sensor_status))
        .def("get_attitude_velocity_sensor_status",
             &PUStatusOutput::get_attitude_velocity_sensor_status,
             DOC_PUStatusOutput(attitude_velocity_sensor_status))
        .def("set_mammal_protection_ramp",
             &PUStatusOutput::set_mammal_protection_ramp,
             DOC_PUStatusOutput(mammal_protection_ramp))
        .def("get_mammal_protection_ramp",
             &PUStatusOutput::get_mammal_protection_ramp,
             DOC_PUStatusOutput(mammal_protection_ramp))
        .def("set_backscatter_at_oblique_angle",
             &PUStatusOutput::set_backscatter_at_oblique_angle,
             DOC_PUStatusOutput(backscatter_at_oblique_angle))
        .def("get_backscatter_at_oblique_angle",
             &PUStatusOutput::get_backscatter_at_oblique_angle,
             DOC_PUStatusOutput(backscatter_at_oblique_angle))
        .def("set_backscatter_at_normal_incidence",
             &PUStatusOutput::set_backscatter_at_normal_incidence,
             DOC_PUStatusOutput(backscatter_at_normal_incidence))
        .def("get_backscatter_at_normal_incidence",
             &PUStatusOutput::get_backscatter_at_normal_incidence,
             DOC_PUStatusOutput(backscatter_at_normal_incidence))
        .def("set_fixed_gain", &PUStatusOutput::set_fixed_gain, DOC_PUStatusOutput(fixed_gain))
        .def("get_fixed_gain", &PUStatusOutput::get_fixed_gain, DOC_PUStatusOutput(fixed_gain))
        .def("set_depth_to_normal_incidence",
             &PUStatusOutput::set_depth_to_normal_incidence,
             DOC_PUStatusOutput(depth_to_normal_incidence))
        .def("get_depth_to_normal_incidence",
             &PUStatusOutput::get_depth_to_normal_incidence,
             DOC_PUStatusOutput(depth_to_normal_incidence))
        .def("set_range_to_normal_incidence",
             &PUStatusOutput::set_range_to_normal_incidence,
             DOC_PUStatusOutput(range_to_normal_incidence))
        .def("get_range_to_normal_incidence",
             &PUStatusOutput::get_range_to_normal_incidence,
             DOC_PUStatusOutput(range_to_normal_incidence))
        .def("set_port_coverage",
             &PUStatusOutput::set_port_coverage,
             DOC_PUStatusOutput(port_coverage))
        .def("get_port_coverage",
             &PUStatusOutput::get_port_coverage,
             DOC_PUStatusOutput(port_coverage))
        .def("set_starboard_coverage",
             &PUStatusOutput::set_starboard_coverage,
             DOC_PUStatusOutput(starboard_coverage))
        .def("get_starboard_coverage",
             &PUStatusOutput::get_starboard_coverage,
             DOC_PUStatusOutput(starboard_coverage))
        .def("set_sound_speed_at_transducer_from_profile",
             &PUStatusOutput::set_sound_speed_at_transducer_from_profile,
             DOC_PUStatusOutput(sound_speed_at_transducer_from_profile))
        .def("get_sound_speed_at_transducer_from_profile",
             &PUStatusOutput::get_sound_speed_at_transducer_from_profile,
             DOC_PUStatusOutput(sound_speed_at_transducer_from_profile))
        .def("set_yaw_stabilization_angle",
             &PUStatusOutput::set_yaw_stabilization_angle,
             DOC_PUStatusOutput(yaw_stabilization_angle))
        .def("get_yaw_stabilization_angle",
             &PUStatusOutput::get_yaw_stabilization_angle,
             DOC_PUStatusOutput(yaw_stabilization_angle))
        .def("set_across_ship_velocity",
             &PUStatusOutput::set_across_ship_velocity,
             DOC_PUStatusOutput(across_ship_velocity))
        .def("get_across_ship_velocity",
             &PUStatusOutput::get_across_ship_velocity,
             DOC_PUStatusOutput(across_ship_velocity))
        .def("set_downward_velocity",
             &PUStatusOutput::set_downward_velocity,
             DOC_PUStatusOutput(downward_velocity))
        .def("get_downward_velocity",
             &PUStatusOutput::get_downward_velocity,
             DOC_PUStatusOutput(downward_velocity))
        .def("set_em2040_cpu_temperature",
             &PUStatusOutput::set_em2040_cpu_temperature,
             DOC_PUStatusOutput(em2040_cpu_temperature))
        .def("get_em2040_cpu_temperature",
             &PUStatusOutput::get_em2040_cpu_temperature,
             DOC_PUStatusOutput(em2040_cpu_temperature))

        // --- processed member access ---
        .def("get_ping_rate_hertz",
             &PUStatusOutput::get_ping_rate_hertz,
             DOC_PUStatusOutput(get_ping_rate_hertz))
        .def("get_distance_between_swath_in_percent",
             &PUStatusOutput::get_distance_between_swath_in_percent,
             DOC_PUStatusOutput(get_distance_between_swath_in_percent))
        .def("get_last_received_heading_in_degrees",
             &PUStatusOutput::get_last_received_heading_in_degrees,
             DOC_PUStatusOutput(get_last_received_heading_in_degrees))
        .def("get_last_received_roll_in_degrees",
             &PUStatusOutput::get_last_received_roll_in_degrees,
             DOC_PUStatusOutput(get_last_received_roll_in_degrees))
        .def("get_last_received_pitch_in_degrees",
             &PUStatusOutput::get_last_received_pitch_in_degrees,
             DOC_PUStatusOutput(get_last_received_pitch_in_degrees))
        .def("get_sound_speed_at_transducer_in_meters_per_second",
             &PUStatusOutput::get_sound_speed_at_transducer_in_meters_per_second,
             DOC_PUStatusOutput(get_sound_speed_at_transducer_in_meters_per_second))
        .def("get_last_received_depth_in_meters",
             &PUStatusOutput::get_last_received_depth_in_meters,
             DOC_PUStatusOutput(get_last_received_depth_in_meters))
        .def("get_along_ship_velocity_in_meters_per_second",
             &PUStatusOutput::get_along_ship_velocity_in_meters_per_second,
             DOC_PUStatusOutput(get_along_ship_velocity_in_meters_per_second))
        .def("get_sound_speed_at_transducer_from_profile_in_meters_per_second",
             &PUStatusOutput::get_sound_speed_at_transducer_from_profile_in_meters_per_second,
             DOC_PUStatusOutput(get_sound_speed_at_transducer_from_profile_in_meters_per_second))
        .def("get_yaw_stabilization_angle_in_degrees",
             &PUStatusOutput::get_yaw_stabilization_angle_in_degrees,
             DOC_PUStatusOutput(get_yaw_stabilization_angle_in_degrees))
        .def("get_across_ship_velocity_in_meters_per_second",
             &PUStatusOutput::get_across_ship_velocity_in_meters_per_second,
             DOC_PUStatusOutput(get_across_ship_velocity_in_meters_per_second))
        .def("get_downward_velocity_in_meters_per_second",
             &PUStatusOutput::get_downward_velocity_in_meters_per_second,
             DOC_PUStatusOutput(get_downward_velocity_in_meters_per_second))

        // --- checksum access ---
        .def("get_etx", &PUStatusOutput::get_etx, DOC_PUStatusOutput(etx))
        .def("set_etx", &PUStatusOutput::set_etx, DOC_PUStatusOutput(etx))
        .def("get_checksum", &PUStatusOutput::get_checksum, DOC_PUStatusOutput(checksum))
        .def("set_checksum", &PUStatusOutput::set_checksum, DOC_PUStatusOutput(checksum))

        // ----- operators -----
        .def("__eq__",
             &PUStatusOutput::operator==,
             DOC_PUStatusOutput(operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(PUStatusOutput)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(PUStatusOutput)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(PUStatusOutput)
        // end LinearInterpolator
        ;
}
}
}
}
}
}