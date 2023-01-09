// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>
#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/em3000/datagrams/xyzdatagram.hpp"
#include "../../docstrings.hpp"
#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_em3000 {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::em3000;
using datagrams::XYZBeam;
using datagrams::XYZDatagram;

#define DOC_t_DetectionType(ARG)                                                                   \
    DOC(themachinethatgoesping, echosounders, em3000, datagrams, XYZBeam, t_DetectionType, ARG)
#define DOC_XYZBeam(ARG) DOC(themachinethatgoesping, echosounders, em3000, datagrams, XYZBeam, ARG)
#define DOC_XYZDatagram(ARG)                                                                       \
    DOC(themachinethatgoesping, echosounders, em3000, datagrams, XYZDatagram, ARG)

void init_c_xyzdatagram(pybind11::module& m)
{
    auto tmp_enum =
        py::enum_<XYZBeam::t_DetectionType>(
            m, "XYZBeam_t_DetectionType", DOC_XYZBeam(t_DetectionType))
            // Multibeam data
            .value("AmplitudeDetect",
                   XYZBeam::t_DetectionType::AmplitudeDetect,
                   DOC_t_DetectionType(AmplitudeDetect))
            .value("PhaseDetect",
                   XYZBeam::t_DetectionType::PhaseDetect,
                   DOC_t_DetectionType(PhaseDetect))
            .value("InvalidNormalDetection",
                   XYZBeam::t_DetectionType::InvalidNormalDetection,
                   DOC_t_DetectionType(InvalidNormalDetection))
            .value("Interpolated",
                   XYZBeam::t_DetectionType::Interpolated,
                   DOC_t_DetectionType(Interpolated))
            .value("Estimated", XYZBeam::t_DetectionType::Estimated, DOC_t_DetectionType(Estimated))
            .value("Rejected", XYZBeam::t_DetectionType::Rejected, DOC_t_DetectionType(Rejected))
            .value("NoDetection",
                   XYZBeam::t_DetectionType::NoDetection,
                   DOC_t_DetectionType(NoDetection))
            .value("Invalid", XYZBeam::t_DetectionType::Invalid, DOC_t_DetectionType(Invalid))
            .export_values()

        //
        ;

    tools::pybind_helper::add_string_to_enum_conversion<XYZBeam::t_DetectionType>(tmp_enum);

    py::class_<XYZBeam>(
        m, "XYZBeam", DOC(themachinethatgoesping, echosounders, em3000, datagrams, XYZBeam))
        .def(py::init<>(), DOC_XYZBeam(XYZBeam))
        // --- convenient data access ---
        .def("set_depth", &XYZBeam::set_depth, DOC_XYZBeam(depth))
        .def("get_depth", &XYZBeam::get_depth, DOC_XYZBeam(depth))
        .def("set_acrosstrack_distance",
             &XYZBeam::set_acrosstrack_distance,
             DOC_XYZBeam(acrosstrack_distance))
        .def("get_acrosstrack_distance",
             &XYZBeam::get_acrosstrack_distance,
             DOC_XYZBeam(acrosstrack_distance))
        .def("set_alongtrack_distance",
             &XYZBeam::set_alongtrack_distance,
             DOC_XYZBeam(alongtrack_distance))
        .def("get_alongtrack_distance",
             &XYZBeam::get_alongtrack_distance,
             DOC_XYZBeam(alongtrack_distance))
        .def("set_detection_window_length",
             &XYZBeam::set_detection_window_length,
             DOC_XYZBeam(detection_window_length))
        .def("get_detection_window_length",
             &XYZBeam::get_detection_window_length,
             DOC_XYZBeam(detection_window_length))
        .def("set_quality_factor", &XYZBeam::set_quality_factor, DOC_XYZBeam(quality_factor))
        .def("get_quality_factor", &XYZBeam::get_quality_factor, DOC_XYZBeam(quality_factor))
        .def("set_beam_incidence_angle_adjustment",
             &XYZBeam::set_beam_incidence_angle_adjustment,
             DOC_XYZBeam(beam_incidence_angle_adjustment))
        .def("get_beam_incidence_angle_adjustment",
             &XYZBeam::get_beam_incidence_angle_adjustment,
             DOC_XYZBeam(beam_incidence_angle_adjustment))
        .def("set_detection_information",
             &XYZBeam::set_detection_information,
             DOC_XYZBeam(detection_information))
        .def("get_detection_information",
             &XYZBeam::get_detection_information,
             DOC_XYZBeam(detection_information))
        .def("set_realtime_cleaning_information",
             &XYZBeam::set_realtime_cleaning_information,
             DOC_XYZBeam(realtime_cleaning_information))
        .def("get_realtime_cleaning_information",
             &XYZBeam::get_realtime_cleaning_information,
             DOC_XYZBeam(realtime_cleaning_information))
        .def("set_reflectivity", &XYZBeam::set_reflectivity, DOC_XYZBeam(reflectivity))
        .def("get_reflectivity", &XYZBeam::get_reflectivity, DOC_XYZBeam(reflectivity))

        // --- processed member access ---
        .def("get_backscatter", &XYZBeam::get_backscatter, DOC_XYZBeam(get_backscatter))
        .def("get_detection_type", &XYZBeam::get_detection_type, DOC_XYZBeam(get_detection_type))
        .def("get_backscatter_is_compensated",
             &XYZBeam::get_backscatter_is_compensated,
             DOC_XYZBeam(get_backscatter_is_compensated))
        .def("get_beam_incidence_angle_adjustment_in_degrees",
             &XYZBeam::get_beam_incidence_angle_adjustment_in_degrees,
             DOC_XYZBeam(get_beam_incidence_angle_adjustment_in_degrees))

        // ----- operators -----
        .def("__eq__", &XYZBeam::operator==, DOC_XYZBeam(operator_eq), py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(XYZBeam)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(XYZBeam)
        // end LinearInterpolator
        ;

    py::class_<XYZDatagram, datagrams::EM3000Datagram>(
        m, "XYZDatagram", DOC(themachinethatgoesping, echosounders, em3000, datagrams, XYZDatagram))
        .def(py::init<>(), DOC_XYZDatagram(XYZDatagram))
        // --- convenient data access ---
        .def("set_ping_counter", &XYZDatagram::set_ping_counter, DOC_XYZDatagram(ping_counter))
        .def("get_ping_counter", &XYZDatagram::get_ping_counter, DOC_XYZDatagram(ping_counter))
        .def("set_system_serial_number",
             &XYZDatagram::set_system_serial_number,
             DOC_XYZDatagram(system_serial_number))
        .def("get_system_serial_number",
             &XYZDatagram::get_system_serial_number,
             DOC_XYZDatagram(system_serial_number))
        .def("set_heading_of_vessel",
             &XYZDatagram::set_heading_of_vessel,
             DOC_XYZDatagram(heading_of_vessel))
        .def("get_heading_of_vessel",
             &XYZDatagram::get_heading_of_vessel,
             DOC_XYZDatagram(heading_of_vessel))
        .def("set_sound_speed", &XYZDatagram::set_sound_speed, DOC_XYZDatagram(sound_speed))
        .def("get_sound_speed", &XYZDatagram::get_sound_speed, DOC_XYZDatagram(sound_speed))
        .def("set_transmit_transducer_depth",
             &XYZDatagram::set_transmit_transducer_depth,
             DOC_XYZDatagram(transmit_transducer_depth))
        .def("get_transmit_transducer_depth",
             &XYZDatagram::get_transmit_transducer_depth,
             DOC_XYZDatagram(transmit_transducer_depth))
        .def("set_number_of_beams",
             &XYZDatagram::set_number_of_beams,
             DOC_XYZDatagram(number_of_beams))
        .def("get_number_of_beams",
             &XYZDatagram::get_number_of_beams,
             DOC_XYZDatagram(number_of_beams))
        .def("set_number_of_valid_detections",
             &XYZDatagram::set_number_of_valid_detections,
             DOC_XYZDatagram(number_of_valid_detections))
        .def("get_number_of_valid_detections",
             &XYZDatagram::get_number_of_valid_detections,
             DOC_XYZDatagram(number_of_valid_detections))
        .def("set_sampling_frequency",
             &XYZDatagram::set_sampling_frequency,
             DOC_XYZDatagram(sampling_frequency))
        .def("get_sampling_frequency",
             &XYZDatagram::get_sampling_frequency,
             DOC_XYZDatagram(sampling_frequency))
        .def("set_scanning_info", &XYZDatagram::set_scanning_info, DOC_XYZDatagram(scanning_info))
        .def("get_scanning_info", &XYZDatagram::get_scanning_info, DOC_XYZDatagram(scanning_info))
        .def("get_beams", &XYZDatagram::get_beams, DOC_XYZDatagram(beams))
        .def("set_beams", &XYZDatagram::set_beams, DOC_XYZDatagram(beams))
        .def("beams", &XYZDatagram::beams, DOC_XYZDatagram(beams))

        // --- processed member access ---
        .def("get_heading_of_vessel_in_degrees", &XYZDatagram::get_heading_of_vessel_in_degrees, DOC_XYZDatagram(get_heading_of_vessel_in_degrees))
        .def("get_sound_speed_in_meters_per_seconds", &XYZDatagram::get_sound_speed_in_meters_per_seconds, DOC_XYZDatagram(get_sound_speed_in_meters_per_seconds))

        // --- checksum access ---
        .def("get_etx", &XYZDatagram::get_etx, DOC_XYZDatagram(etx))
        .def("set_etx", &XYZDatagram::set_etx, DOC_XYZDatagram(etx))
        .def("get_checksum", &XYZDatagram::get_checksum, DOC_XYZDatagram(checksum))
        .def("set_checksum", &XYZDatagram::set_checksum, DOC_XYZDatagram(checksum))

        // ----- operators -----
        .def("__eq__", &XYZDatagram::operator==, DOC_XYZDatagram(operator_eq), py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(XYZDatagram)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(XYZDatagram)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(XYZDatagram)
        // end LinearInterpolator
        ;
}
}
}
}
}
}