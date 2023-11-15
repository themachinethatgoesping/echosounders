// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>
#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/extradetections.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::ExtraDetections;

#define DOC_ExtraDetections(ARG)                                                                   \
    DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, ExtraDetections, ARG)

void init_c_extradetections(pybind11::module& m)
{
    py::class_<ExtraDetections, datagrams::KongsbergAllDatagram>(
        m,
        "ExtraDetections",
        DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, ExtraDetections))
        .def(py::init<>(), DOC_ExtraDetections(ExtraDetections))
        // --- convenient data access ---
        .def("set_ping_counter",
             &ExtraDetections::set_ping_counter,
             DOC_ExtraDetections(ping_counter))
        .def("get_ping_counter",
             &ExtraDetections::get_ping_counter,
             DOC_ExtraDetections(ping_counter))
        .def("set_system_serial_number",
             &ExtraDetections::set_system_serial_number,
             DOC_ExtraDetections(system_serial_number))
        .def("get_system_serial_number",
             &ExtraDetections::get_system_serial_number,
             DOC_ExtraDetections(system_serial_number))
        .def("set_datagram_counter",
             &ExtraDetections::set_datagram_counter,
             DOC_ExtraDetections(datagram_counter))
        .def("get_datagram_counter",
             &ExtraDetections::get_datagram_counter,
             DOC_ExtraDetections(datagram_counter))
        .def("set_datagram_version_id",
             &ExtraDetections::set_datagram_version_id,
             DOC_ExtraDetections(datagram_version_id))
        .def("get_datagram_version_id",
             &ExtraDetections::get_datagram_version_id,
             DOC_ExtraDetections(datagram_version_id))
        .def("set_swath_counter",
             &ExtraDetections::set_swath_counter,
             DOC_ExtraDetections(swath_counter))
        .def("get_swath_counter",
             &ExtraDetections::get_swath_counter,
             DOC_ExtraDetections(swath_counter))
        .def("set_swath_index", &ExtraDetections::set_swath_index, DOC_ExtraDetections(swath_index))
        .def("get_swath_index", &ExtraDetections::get_swath_index, DOC_ExtraDetections(swath_index))
        .def("set_heading", &ExtraDetections::set_heading, DOC_ExtraDetections(heading))
        .def("get_heading", &ExtraDetections::get_heading, DOC_ExtraDetections(heading))
        .def("set_sound_speed", &ExtraDetections::set_sound_speed, DOC_ExtraDetections(sound_speed))
        .def("get_sound_speed", &ExtraDetections::get_sound_speed, DOC_ExtraDetections(sound_speed))
        .def("set_depth_of_reference_point",
             &ExtraDetections::set_depth_of_reference_point,
             DOC_ExtraDetections(depth_of_reference_point))
        .def("get_depth_of_reference_point",
             &ExtraDetections::get_depth_of_reference_point,
             DOC_ExtraDetections(depth_of_reference_point))
        .def("set_water_column_sample_rate",
             &ExtraDetections::set_water_column_sample_rate,
             DOC_ExtraDetections(water_column_sample_rate))
        .def("get_water_column_sample_rate",
             &ExtraDetections::get_water_column_sample_rate,
             DOC_ExtraDetections(water_column_sample_rate))
        .def("set_raw_amplitude_sample_rate",
             &ExtraDetections::set_raw_amplitude_sample_rate,
             DOC_ExtraDetections(raw_amplitude_sample_rate))
        .def("get_raw_amplitude_sample_rate",
             &ExtraDetections::get_raw_amplitude_sample_rate,
             DOC_ExtraDetections(raw_amplitude_sample_rate))
        .def("set_rx_transducer_index",
             &ExtraDetections::set_rx_transducer_index,
             DOC_ExtraDetections(rx_transducer_index))
        .def("get_rx_transducer_index",
             &ExtraDetections::get_rx_transducer_index,
             DOC_ExtraDetections(rx_transducer_index))
        .def("set_number_of_extra_detections",
             &ExtraDetections::set_number_of_extra_detections,
             DOC_ExtraDetections(number_of_extra_detections))
        .def("get_number_of_extra_detections",
             &ExtraDetections::get_number_of_extra_detections,
             DOC_ExtraDetections(number_of_extra_detections))
        .def("set_number_of_detection_classes",
             &ExtraDetections::set_number_of_detection_classes,
             DOC_ExtraDetections(number_of_detection_classes))
        .def("get_number_of_detection_classes",
             &ExtraDetections::get_number_of_detection_classes,
             DOC_ExtraDetections(number_of_detection_classes))
        .def("set_number_of_bytes_per_class",
             &ExtraDetections::set_number_of_bytes_per_class,
             DOC_ExtraDetections(number_of_bytes_per_class))
        .def("get_number_of_bytes_per_class",
             &ExtraDetections::get_number_of_bytes_per_class,
             DOC_ExtraDetections(number_of_bytes_per_class))
        .def("set_number_of_alarm_flags",
             &ExtraDetections::set_number_of_alarm_flags,
             DOC_ExtraDetections(number_of_alarm_flags))
        .def("get_number_of_alarm_flags",
             &ExtraDetections::get_number_of_alarm_flags,
             DOC_ExtraDetections(number_of_alarm_flags))
        .def("set_number_of_bytes_per_detection",
             &ExtraDetections::set_number_of_bytes_per_detection,
             DOC_ExtraDetections(number_of_bytes_per_detection))
        .def("get_number_of_bytes_per_detection",
             &ExtraDetections::get_number_of_bytes_per_detection,
             DOC_ExtraDetections(number_of_bytes_per_detection))

        // --- substructure member access ---
        .def("set_detection_classes",
             &ExtraDetections::set_detection_classes,
             DOC_ExtraDetections(detection_classes))
        .def("get_detection_classes",
             &ExtraDetections::get_detection_classes,
             DOC_ExtraDetections(detection_classes),
             py::return_value_policy::reference_internal)
        .def("detection_classes",
             &ExtraDetections::detection_classes,
             DOC_ExtraDetections(detection_classes_2),
             py::return_value_policy::reference_internal)
        .def("set_extra_detections",
             &ExtraDetections::set_extra_detections,
             DOC_ExtraDetections(extra_detections))
        .def("get_extra_detections",
             &ExtraDetections::get_extra_detections,
             DOC_ExtraDetections(extra_detections),
             py::return_value_policy::reference_internal)
        .def("extra_detections",
             &ExtraDetections::extra_detections,
             DOC_ExtraDetections(extra_detections_2),
             py::return_value_policy::reference_internal)
        .def("set_raw_amplitude_samples",
             &ExtraDetections::set_raw_amplitude_samples,
             DOC_ExtraDetections(raw_amplitude_samples))
        .def("get_raw_amplitude_samples",
             &ExtraDetections::get_raw_amplitude_samples,
             DOC_ExtraDetections(raw_amplitude_samples),
             py::return_value_policy::reference_internal)
        .def("raw_amplitude_samples",
             &ExtraDetections::raw_amplitude_samples,
             DOC_ExtraDetections(raw_amplitude_samples_2),
             py::return_value_policy::reference_internal)

        // --- processed member access ---
        .def("get_heading_in_degrees",
             &ExtraDetections::get_heading_in_degrees,
             DOC_ExtraDetections(get_heading_in_degrees))
        .def("get_sound_speed_in_m_per_s",
             &ExtraDetections::get_sound_speed_in_m_per_s,
             DOC_ExtraDetections(get_sound_speed_in_m_per_s))

        // --- checksum access ---
        .def("get_etx", &ExtraDetections::get_etx, DOC_ExtraDetections(etx))
        .def("set_etx", &ExtraDetections::set_etx, DOC_ExtraDetections(etx))
        .def("get_checksum", &ExtraDetections::get_checksum, DOC_ExtraDetections(checksum))
        .def("set_checksum", &ExtraDetections::set_checksum, DOC_ExtraDetections(checksum))

        // ----- operators -----
        .def("__eq__",
             &ExtraDetections::operator==,
             DOC_ExtraDetections(operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(ExtraDetections)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(ExtraDetections)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(ExtraDetections)
        // end LinearInterpolator
        ;
}
}
}
}
}
}