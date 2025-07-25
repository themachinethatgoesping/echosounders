// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/pytypes.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>
#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/runtimeparameters.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::RuntimeParameters;

#define DOC_RuntimeParameters(ARG)                                                                 \
    DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, RuntimeParameters, ARG)

void init_c_runtimeparameters(pybind11::module& m)
{
    py::class_<RuntimeParameters, datagrams::KongsbergAllDatagram>(
        m,
        "RuntimeParameters",
        DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, RuntimeParameters))
        .def(py::init<>(), DOC_RuntimeParameters(RuntimeParameters))

        // --- convenient data access ---
        .def("set_ping_counter",
             &RuntimeParameters::set_ping_counter,
             DOC_RuntimeParameters(ping_counter))
        .def("get_ping_counter",
             &RuntimeParameters::get_ping_counter,
             DOC_RuntimeParameters(ping_counter))
        .def("set_system_serial_number",
             &RuntimeParameters::set_system_serial_number,
             DOC_RuntimeParameters(system_serial_number))
        .def("get_system_serial_number",
             &RuntimeParameters::get_system_serial_number,
             DOC_RuntimeParameters(system_serial_number))
        .def("set_operator_station_status",
             &RuntimeParameters::set_operator_station_status,
             DOC_RuntimeParameters(operator_station_status))
        .def("get_operator_station_status",
             &RuntimeParameters::get_operator_station_status,
             DOC_RuntimeParameters(operator_station_status))
        .def("set_processing_unit_status",
             &RuntimeParameters::set_processing_unit_status,
             DOC_RuntimeParameters(processing_unit_status))
        .def("get_processing_unit_status",
             &RuntimeParameters::get_processing_unit_status,
             DOC_RuntimeParameters(processing_unit_status))
        .def(
            "set_bsp_status", &RuntimeParameters::set_bsp_status, DOC_RuntimeParameters(bsp_status))
        .def(
            "get_bsp_status", &RuntimeParameters::get_bsp_status, DOC_RuntimeParameters(bsp_status))
        .def("set_sonar_head_or_transceiver_status",
             &RuntimeParameters::set_sonar_head_or_transceiver_status,
             DOC_RuntimeParameters(sonar_head_or_transceiver_status))
        .def("get_sonar_head_or_transceiver_status",
             &RuntimeParameters::get_sonar_head_or_transceiver_status,
             DOC_RuntimeParameters(sonar_head_or_transceiver_status))
        .def("set_mode", &RuntimeParameters::set_mode, DOC_RuntimeParameters(mode))
        .def("get_mode", &RuntimeParameters::get_mode, DOC_RuntimeParameters(mode))
        .def("set_filter_identifier",
             &RuntimeParameters::set_filter_identifier,
             DOC_RuntimeParameters(filter_identifier))
        .def("get_filter_identifier",
             &RuntimeParameters::get_filter_identifier,
             DOC_RuntimeParameters(filter_identifier))
        .def("set_minimum_depth",
             &RuntimeParameters::set_minimum_depth,
             DOC_RuntimeParameters(minimum_depth))
        .def("get_minimum_depth",
             &RuntimeParameters::get_minimum_depth,
             DOC_RuntimeParameters(minimum_depth))
        .def("set_maximum_depth",
             &RuntimeParameters::set_maximum_depth,
             DOC_RuntimeParameters(maximum_depth))
        .def("get_maximum_depth",
             &RuntimeParameters::get_maximum_depth,
             DOC_RuntimeParameters(maximum_depth))
        .def("set_absorption_coefficient",
             &RuntimeParameters::set_absorption_coefficient,
             DOC_RuntimeParameters(absorption_coefficient))
        .def("get_absorption_coefficient",
             &RuntimeParameters::get_absorption_coefficient,
             DOC_RuntimeParameters(absorption_coefficient))
        .def("set_transmit_pulse_length",
             &RuntimeParameters::set_transmit_pulse_length,
             DOC_RuntimeParameters(transmit_pulse_length))
        .def("get_transmit_pulse_length",
             &RuntimeParameters::get_transmit_pulse_length,
             DOC_RuntimeParameters(transmit_pulse_length))
        .def("set_transmit_beamwidth",
             &RuntimeParameters::set_transmit_beamwidth,
             DOC_RuntimeParameters(transmit_beamwidth))
        .def("get_transmit_beamwidth",
             &RuntimeParameters::get_transmit_beamwidth,
             DOC_RuntimeParameters(transmit_beamwidth))
        .def("set_transmit_power_relative_maximum",
             &RuntimeParameters::set_transmit_power_relative_maximum,
             DOC_RuntimeParameters(transmit_power_relative_maximum))
        .def("get_transmit_power_relative_maximum",
             &RuntimeParameters::get_transmit_power_relative_maximum,
             DOC_RuntimeParameters(transmit_power_relative_maximum))
        .def("set_receive_beamwidth_degree",
             &RuntimeParameters::set_receive_beamwidth_degree,
             DOC_RuntimeParameters(receive_beamwidth_degree))
        .def("get_receive_beamwidth_degree",
             &RuntimeParameters::get_receive_beamwidth_degree,
             DOC_RuntimeParameters(receive_beamwidth_degree))
        .def("set_receive_bandwidth_50hz",
             &RuntimeParameters::set_receive_bandwidth_50hz,
             DOC_RuntimeParameters(receive_bandwidth_50hz))
        .def("get_receive_bandwidth_50hz",
             &RuntimeParameters::get_receive_bandwidth_50hz,
             DOC_RuntimeParameters(receive_bandwidth_50hz))
        .def("set_mode2_or_receiver_fixed_gain_setting",
             &RuntimeParameters::set_mode2_or_receiver_fixed_gain_setting,
             DOC_RuntimeParameters(mode2_or_receiver_fixed_gain_setting))
        .def("get_mode2_or_receiver_fixed_gain_setting",
             &RuntimeParameters::get_mode2_or_receiver_fixed_gain_setting,
             DOC_RuntimeParameters(mode2_or_receiver_fixed_gain_setting))
        .def("set_tvg_law_crossover_angle",
             &RuntimeParameters::set_tvg_law_crossover_angle,
             DOC_RuntimeParameters(tvg_law_crossover_angle))
        .def("get_tvg_law_crossover_angle",
             &RuntimeParameters::get_tvg_law_crossover_angle,
             DOC_RuntimeParameters(tvg_law_crossover_angle))
        .def("set_source_of_sound_speed_at_transducer",
             &RuntimeParameters::set_source_of_sound_speed_at_transducer,
             DOC_RuntimeParameters(source_of_sound_speed_at_transducer))
        .def("get_source_of_sound_speed_at_transducer",
             &RuntimeParameters::get_source_of_sound_speed_at_transducer,
             DOC_RuntimeParameters(source_of_sound_speed_at_transducer))
        .def("set_maximum_port_swath_width",
             &RuntimeParameters::set_maximum_port_swath_width,
             DOC_RuntimeParameters(maximum_port_swath_width))
        .def("get_maximum_port_swath_width",
             &RuntimeParameters::get_maximum_port_swath_width,
             DOC_RuntimeParameters(maximum_port_swath_width))
        .def("set_beam_spacing",
             &RuntimeParameters::set_beam_spacing,
             DOC_RuntimeParameters(beam_spacing))
        .def("get_beam_spacing",
             &RuntimeParameters::get_beam_spacing,
             DOC_RuntimeParameters(beam_spacing))
        .def("set_maximum_port_coverage",
             &RuntimeParameters::set_maximum_port_coverage,
             DOC_RuntimeParameters(maximum_port_coverage))
        .def("get_maximum_port_coverage",
             &RuntimeParameters::get_maximum_port_coverage,
             DOC_RuntimeParameters(maximum_port_coverage))
        .def("set_yaw_and_pitch_stabilization_mode",
             &RuntimeParameters::set_yaw_and_pitch_stabilization_mode,
             DOC_RuntimeParameters(yaw_and_pitch_stabilization_mode))
        .def("get_yaw_and_pitch_stabilization_mode",
             &RuntimeParameters::get_yaw_and_pitch_stabilization_mode,
             DOC_RuntimeParameters(yaw_and_pitch_stabilization_mode))
        .def("set_maximum_starboard_coverage",
             &RuntimeParameters::set_maximum_starboard_coverage,
             DOC_RuntimeParameters(maximum_starboard_coverage))
        .def("get_maximum_starboard_coverage",
             &RuntimeParameters::get_maximum_starboard_coverage,
             DOC_RuntimeParameters(maximum_starboard_coverage))
        .def("set_maximum_starboard_swath_width",
             &RuntimeParameters::set_maximum_starboard_swath_width,
             DOC_RuntimeParameters(maximum_starboard_swath_width))
        .def("get_maximum_starboard_swath_width",
             &RuntimeParameters::get_maximum_starboard_swath_width,
             DOC_RuntimeParameters(maximum_starboard_swath_width))
        .def("set_transmit_along_tilt",
             &RuntimeParameters::set_transmit_along_tilt,
             DOC_RuntimeParameters(transmit_along_tilt))
        .def("get_transmit_along_tilt",
             &RuntimeParameters::get_transmit_along_tilt,
             DOC_RuntimeParameters(transmit_along_tilt))
        .def("set_filter_identifier2",
             &RuntimeParameters::set_filter_identifier2,
             DOC_RuntimeParameters(filter_identifier2))
        .def("get_filter_identifier2",
             &RuntimeParameters::get_filter_identifier2,
             DOC_RuntimeParameters(filter_identifier2))

        // --- processed member access ---
        .def("get_absorption_coefficient_in_db_per_meter",
             &RuntimeParameters::get_absorption_coefficient_in_db_per_meter,
             DOC_RuntimeParameters(get_absorption_coefficient_in_db_per_meter))
        .def("get_transmit_pulse_length_in_seconds",
             &RuntimeParameters::get_transmit_pulse_length_in_seconds,
             DOC_RuntimeParameters(get_transmit_pulse_length_in_seconds))
        .def("get_transmit_beamwidth_in_degrees",
             &RuntimeParameters::get_transmit_beamwidth_in_degrees,
             DOC_RuntimeParameters(get_transmit_beamwidth_in_degrees))
        .def("get_receive_beamwidth_in_degrees",
             &RuntimeParameters::get_receive_beamwidth_in_degrees,
             DOC_RuntimeParameters(get_receive_beamwidth_in_degrees))
        .def("get_receive_bandwidth_in_hertz",
             &RuntimeParameters::get_receive_bandwidth_in_hertz,
             DOC_RuntimeParameters(get_receive_bandwidth_in_hertz))
        .def("get_transmit_along_tilt_in_degrees",
             &RuntimeParameters::get_transmit_along_tilt_in_degrees,
             DOC_RuntimeParameters(get_transmit_along_tilt_in_degrees))

        // mode
        .def("get_mode_as_ping_mode",
             &RuntimeParameters::get_mode_as_ping_mode,
             DOC_RuntimeParameters(get_mode_as_ping_mode),
             py::arg("unhandled_message") = std::nullopt)
        .def("get_mode_as_tx_pulse_form",
             &RuntimeParameters::get_mode_as_tx_pulse_form,
             DOC_RuntimeParameters(get_mode_as_tx_pulse_form),
             py::arg("unhandled_message") = std::nullopt)
        .def("get_mode_as_dual_swath_mode",
             &RuntimeParameters::get_mode_as_dual_swath_mode,
             DOC_RuntimeParameters(get_mode_as_dual_swath_mode),
             py::arg("unhandled_message") = std::nullopt)

        // mode2
        .def("get_mode2_as_rx_or_sonar_head_use",
             &RuntimeParameters::get_mode2_as_rx_or_sonar_head_use,
             DOC_RuntimeParameters(get_mode2_as_rx_or_sonar_head_use),
             py::arg("unhandled_message") = std::nullopt)
        .def("get_mode2_as_pulselength",
             &RuntimeParameters::get_mode2_as_pulselength,
             DOC_RuntimeParameters(get_mode2_as_pulselength),
             py::arg("unhandled_message") = std::nullopt)
        .def("get_mode2_as_receive_fixed_gain_setting_dB",
             &RuntimeParameters::get_mode2_as_receive_fixed_gain_setting_dB,
             DOC_RuntimeParameters(get_mode2_as_receive_fixed_gain_setting_dB),
             py::arg("unhandled_value") = std::nullopt)

        // filter_identifier
        .def("get_filter_identifier_as_spike_filter",
             &RuntimeParameters::get_filter_identifier_as_spike_filter,
             DOC_RuntimeParameters(get_filter_identifier_as_spike_filter))
        .def("get_filter_identifier_as_slope_filter",
             &RuntimeParameters::get_filter_identifier_as_slope_filter,
             DOC_RuntimeParameters(get_filter_identifier_as_slope_filter))
        .def("get_filter_identifier_as_range_gates_size",
             &RuntimeParameters::get_filter_identifier_as_range_gates_size,
             DOC_RuntimeParameters(get_filter_identifier_as_range_gates_size),
             py::arg("unhandled_message") = std::nullopt)
        .def("get_filter_identifier_as_aeration_filter",
             &RuntimeParameters::get_filter_identifier_as_aeration_filter,
             DOC_RuntimeParameters(get_filter_identifier_as_aeration_filter))
        .def("get_filter_identifier_as_interference_filter",
             &RuntimeParameters::get_filter_identifier_as_interference_filter,
             DOC_RuntimeParameters(get_filter_identifier_as_interference_filter))

        // filter_identifier2
        .def("get_filter_identifier2_as_penetration_filter",
             &RuntimeParameters::get_filter_identifier2_as_penetration_filter,
             DOC_RuntimeParameters(get_filter_identifier2_as_penetration_filter))
        .def("get_filter_identifier2_as_detect_mode",
             &RuntimeParameters::get_filter_identifier2_as_detect_mode,
             DOC_RuntimeParameters(get_filter_identifier2_as_detect_mode))
        .def("get_filter_identifier2_as_phase_ramp",
             &RuntimeParameters::get_filter_identifier2_as_phase_ramp,
             DOC_RuntimeParameters(get_filter_identifier2_as_phase_ramp),
             py::arg("unhandled_message") = std::nullopt)
        .def("get_filter_identifier2_as_special_tvg",
             &RuntimeParameters::get_filter_identifier2_as_special_tvg,
             DOC_RuntimeParameters(get_filter_identifier2_as_special_tvg))
        .def("get_filter_identifier2_as_special_amp_detect",
             &RuntimeParameters::get_filter_identifier2_as_special_amp_detect,
             DOC_RuntimeParameters(get_filter_identifier2_as_special_amp_detect))

        // _source_of_sound_speed_at_transducer
        .def("get_source_of_sound_speed_at_transducer_as_string",
             &RuntimeParameters::get_source_of_sound_speed_at_transducer_as_string,
             DOC_RuntimeParameters(get_source_of_sound_speed_at_transducer_as_string),
             py::arg("unhandled_message") = std::nullopt)
        .def("get_sonar_mode_enabled",
             &RuntimeParameters::get_sonar_mode_enabled,
             DOC_RuntimeParameters(get_sonar_mode_enabled))
        .def("get_sonar_mode_enabled",
             &RuntimeParameters::get_sonar_mode_enabled,
             DOC_RuntimeParameters(get_sonar_mode_enabled))
        .def("get_passive_mode_enabled",
             &RuntimeParameters::get_passive_mode_enabled,
             DOC_RuntimeParameters(get_passive_mode_enabled))
        .def("get_3d_scanning_enabled",
             &RuntimeParameters::get_3d_scanning_enabled,
             DOC_RuntimeParameters(get_3d_scanning_enabled))

        // beam_spacing
        .def("get_beam_spacing_as_string",
             &RuntimeParameters::get_beam_spacing_as_string,
             DOC_RuntimeParameters(get_beam_spacing_as_string),
             py::arg("unhandled_message") = std::nullopt)

        // yaw and pitch stabilization
        .def("get_yaw_and_pitch_stabilization_mode_as_yaw_stabilization",
             &RuntimeParameters::get_yaw_and_pitch_stabilization_mode_as_yaw_stabilization,
             DOC_RuntimeParameters(get_yaw_and_pitch_stabilization_mode_as_yaw_stabilization))
        .def("get_yaw_and_pitch_stabilization_mode_as_heading_filter",
             &RuntimeParameters::get_yaw_and_pitch_stabilization_mode_as_heading_filter,
             DOC_RuntimeParameters(get_yaw_and_pitch_stabilization_mode_as_heading_filter),
             py::arg("unhandled_message") = std::nullopt)
        .def("get_yaw_and_pitch_stabilization_mode_as_pitch_stibilization",
             &RuntimeParameters::get_yaw_and_pitch_stabilization_mode_as_pitch_stibilization,
             DOC_RuntimeParameters(get_yaw_and_pitch_stabilization_mode_as_pitch_stibilization))

        // --- mode2 ---

        // --- checksum access ---
        .def("get_etx", &RuntimeParameters::get_etx, DOC_RuntimeParameters(etx))
        .def("set_etx", &RuntimeParameters::set_etx, DOC_RuntimeParameters(etx))
        .def("get_checksum", &RuntimeParameters::get_checksum, DOC_RuntimeParameters(checksum))
        .def("set_checksum", &RuntimeParameters::set_checksum, DOC_RuntimeParameters(checksum))

        // ----- operators -----
        .def("__eq__",
             &RuntimeParameters::operator==,
             DOC_RuntimeParameters(operator_eq),
             py::arg("other"))

        .def("hash_content_only",
             &RuntimeParameters::hash_content_only,
             DOC_RuntimeParameters(hash_content_only))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(RuntimeParameters)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(RuntimeParameters)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(RuntimeParameters)
        // end LinearInterpolator
        ;
}
}
}
}
}
}