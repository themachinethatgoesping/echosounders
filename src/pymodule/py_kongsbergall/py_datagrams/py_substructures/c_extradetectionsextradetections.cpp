// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/substructures/extradetectionsextradetections.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {
namespace py_substructures {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::substructures::ExtraDetectionsExtraDetections;

#define DOC_ExtraDetectionsExtraDetections(ARG)                                                    \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kongsbergall,                                                                                    \
        datagrams,                                                                                 \
        substructures,                                                                             \
        ExtraDetectionsExtraDetections,                                                            \
        ARG)

void init_c_extradetectionsextradetections(pybind11::module& m)
{

    py::class_<ExtraDetectionsExtraDetections>(m,
                                               "ExtraDetectionsExtraDetections",
                                               DOC(themachinethatgoesping,
                                                   echosounders,
                                                   kongsbergall,
                                                   datagrams,
                                                   substructures,
                                                   ExtraDetectionsExtraDetections))
        .def(py::init<>(), DOC_ExtraDetectionsExtraDetections(ExtraDetectionsExtraDetections))
        // --- convenient data access ---
        .def("set_depth",
             &ExtraDetectionsExtraDetections::set_depth,
             DOC_ExtraDetectionsExtraDetections(depth))
        .def("get_depth",
             &ExtraDetectionsExtraDetections::get_depth,
             DOC_ExtraDetectionsExtraDetections(depth))
        .def("set_across",
             &ExtraDetectionsExtraDetections::set_across,
             DOC_ExtraDetectionsExtraDetections(across))
        .def("get_across",
             &ExtraDetectionsExtraDetections::get_across,
             DOC_ExtraDetectionsExtraDetections(across))
        .def("set_along",
             &ExtraDetectionsExtraDetections::set_along,
             DOC_ExtraDetectionsExtraDetections(along))
        .def("get_along",
             &ExtraDetectionsExtraDetections::get_along,
             DOC_ExtraDetectionsExtraDetections(along))
        .def("set_delta_latitude",
             &ExtraDetectionsExtraDetections::set_delta_latitude,
             DOC_ExtraDetectionsExtraDetections(delta_latitude))
        .def("get_delta_latitude",
             &ExtraDetectionsExtraDetections::get_delta_latitude,
             DOC_ExtraDetectionsExtraDetections(delta_latitude))
        .def("set_delta_longitude",
             &ExtraDetectionsExtraDetections::set_delta_longitude,
             DOC_ExtraDetectionsExtraDetections(delta_longitude))
        .def("get_delta_longitude",
             &ExtraDetectionsExtraDetections::get_delta_longitude,
             DOC_ExtraDetectionsExtraDetections(delta_longitude))
        .def("set_beam_crosstrack_angle",
             &ExtraDetectionsExtraDetections::set_beam_crosstrack_angle,
             DOC_ExtraDetectionsExtraDetections(beam_crosstrack_angle))
        .def("get_beam_crosstrack_angle",
             &ExtraDetectionsExtraDetections::get_beam_crosstrack_angle,
             DOC_ExtraDetectionsExtraDetections(beam_crosstrack_angle))
        .def("set_applied_pointing_angle_correction",
             &ExtraDetectionsExtraDetections::set_applied_pointing_angle_correction,
             DOC_ExtraDetectionsExtraDetections(applied_pointing_angle_correction))
        .def("get_applied_pointing_angle_correction",
             &ExtraDetectionsExtraDetections::get_applied_pointing_angle_correction,
             DOC_ExtraDetectionsExtraDetections(applied_pointing_angle_correction))
        .def("set_two_way_travel_time",
             &ExtraDetectionsExtraDetections::set_two_way_travel_time,
             DOC_ExtraDetectionsExtraDetections(two_way_travel_time))
        .def("get_two_way_travel_time",
             &ExtraDetectionsExtraDetections::get_two_way_travel_time,
             DOC_ExtraDetectionsExtraDetections(two_way_travel_time))
        .def("set_applied_two_way_travel_time_corrections",
             &ExtraDetectionsExtraDetections::set_applied_two_way_travel_time_corrections,
             DOC_ExtraDetectionsExtraDetections(applied_two_way_travel_time_corrections))
        .def("get_applied_two_way_travel_time_corrections",
             &ExtraDetectionsExtraDetections::get_applied_two_way_travel_time_corrections,
             DOC_ExtraDetectionsExtraDetections(applied_two_way_travel_time_corrections))
        .def("set_backscatter",
             &ExtraDetectionsExtraDetections::set_backscatter,
             DOC_ExtraDetectionsExtraDetections(backscatter))
        .def("get_backscatter",
             &ExtraDetectionsExtraDetections::get_backscatter,
             DOC_ExtraDetectionsExtraDetections(backscatter))
        .def("set_beam_incidence_angle_adjustment",
             &ExtraDetectionsExtraDetections::set_beam_incidence_angle_adjustment,
             DOC_ExtraDetectionsExtraDetections(beam_incidence_angle_adjustment))
        .def("get_beam_incidence_angle_adjustment",
             &ExtraDetectionsExtraDetections::get_beam_incidence_angle_adjustment,
             DOC_ExtraDetectionsExtraDetections(beam_incidence_angle_adjustment))
        .def("set_detection_info",
             &ExtraDetectionsExtraDetections::set_detection_info,
             DOC_ExtraDetectionsExtraDetections(detection_info))
        .def("get_detection_info",
             &ExtraDetectionsExtraDetections::get_detection_info,
             DOC_ExtraDetectionsExtraDetections(detection_info))
        .def("set_spare",
             &ExtraDetectionsExtraDetections::set_spare,
             DOC_ExtraDetectionsExtraDetections(spare))
        .def("get_spare",
             &ExtraDetectionsExtraDetections::get_spare,
             DOC_ExtraDetectionsExtraDetections(spare))
        .def("set_tx_sector_number",
             &ExtraDetectionsExtraDetections::set_tx_sector_number,
             DOC_ExtraDetectionsExtraDetections(tx_sector_number))
        .def("get_tx_sector_number",
             &ExtraDetectionsExtraDetections::get_tx_sector_number,
             DOC_ExtraDetectionsExtraDetections(tx_sector_number))
        .def("set_detection_window_length",
             &ExtraDetectionsExtraDetections::set_detection_window_length,
             DOC_ExtraDetectionsExtraDetections(detection_window_length))
        .def("get_detection_window_length",
             &ExtraDetectionsExtraDetections::get_detection_window_length,
             DOC_ExtraDetectionsExtraDetections(detection_window_length))
        .def("set_quality_factor_old",
             &ExtraDetectionsExtraDetections::set_quality_factor_old,
             DOC_ExtraDetectionsExtraDetections(quality_factor_old))
        .def("get_quality_factor_old",
             &ExtraDetectionsExtraDetections::get_quality_factor_old,
             DOC_ExtraDetectionsExtraDetections(quality_factor_old))
        .def("set_real_time_cleaning_info",
             &ExtraDetectionsExtraDetections::set_real_time_cleaning_info,
             DOC_ExtraDetectionsExtraDetections(real_time_cleaning_info))
        .def("get_real_time_cleaning_info",
             &ExtraDetectionsExtraDetections::get_real_time_cleaning_info,
             DOC_ExtraDetectionsExtraDetections(real_time_cleaning_info))
        .def("set_range_factor",
             &ExtraDetectionsExtraDetections::set_range_factor,
             DOC_ExtraDetectionsExtraDetections(range_factor))
        .def("get_range_factor",
             &ExtraDetectionsExtraDetections::get_range_factor,
             DOC_ExtraDetectionsExtraDetections(range_factor))
        .def("set_detection_class_number",
             &ExtraDetectionsExtraDetections::set_detection_class_number,
             DOC_ExtraDetectionsExtraDetections(detection_class_number))
        .def("get_detection_class_number",
             &ExtraDetectionsExtraDetections::get_detection_class_number,
             DOC_ExtraDetectionsExtraDetections(detection_class_number))
        .def("set_confidence_level",
             &ExtraDetectionsExtraDetections::set_confidence_level,
             DOC_ExtraDetectionsExtraDetections(confidence_level))
        .def("get_confidence_level",
             &ExtraDetectionsExtraDetections::get_confidence_level,
             DOC_ExtraDetectionsExtraDetections(confidence_level))
        .def("set_qf_10",
             &ExtraDetectionsExtraDetections::set_qf_10,
             DOC_ExtraDetectionsExtraDetections(qf_10))
        .def("get_qf_10",
             &ExtraDetectionsExtraDetections::get_qf_10,
             DOC_ExtraDetectionsExtraDetections(qf_10))
        .def("set_water_column_beam_number",
             &ExtraDetectionsExtraDetections::set_water_column_beam_number,
             DOC_ExtraDetectionsExtraDetections(water_column_beam_number))
        .def("get_water_column_beam_number",
             &ExtraDetectionsExtraDetections::get_water_column_beam_number,
             DOC_ExtraDetectionsExtraDetections(water_column_beam_number))
        .def("set_beam_angle_across",
             &ExtraDetectionsExtraDetections::set_beam_angle_across,
             DOC_ExtraDetectionsExtraDetections(beam_angle_across))
        .def("get_beam_angle_across",
             &ExtraDetectionsExtraDetections::get_beam_angle_across,
             DOC_ExtraDetectionsExtraDetections(beam_angle_across))
        .def("set_detected_range",
             &ExtraDetectionsExtraDetections::set_detected_range,
             DOC_ExtraDetectionsExtraDetections(detected_range))
        .def("get_detected_range",
             &ExtraDetectionsExtraDetections::get_detected_range,
             DOC_ExtraDetectionsExtraDetections(detected_range))
        .def("set_number_of_raw_amplitude_samples",
             &ExtraDetectionsExtraDetections::set_number_of_raw_amplitude_samples,
             DOC_ExtraDetectionsExtraDetections(number_of_raw_amplitude_samples))
        .def("get_number_of_raw_amplitude_samples",
             &ExtraDetectionsExtraDetections::get_number_of_raw_amplitude_samples,
             DOC_ExtraDetectionsExtraDetections(number_of_raw_amplitude_samples))

        // --- processed member access ---
        .def("get_qf_threshold",
             &ExtraDetectionsExtraDetections::get_qf_threshold,
             DOC_ExtraDetectionsExtraDetections(get_qf_threshold))
        .def("get_backscatter_in_db",
             &ExtraDetectionsExtraDetections::get_backscatter_in_db,
             DOC_ExtraDetectionsExtraDetections(get_backscatter_in_db))
        .def("get_detection_is_valid",
             &ExtraDetectionsExtraDetections::get_detection_is_valid,
             DOC_ExtraDetectionsExtraDetections(get_detection_is_valid))
        .def("get_detection_type",
             &ExtraDetectionsExtraDetections::get_detection_type,
             DOC_ExtraDetectionsExtraDetections(get_detection_type))
        .def("get_backscatter_is_compensated",
             &ExtraDetectionsExtraDetections::get_backscatter_is_compensated,
             DOC_ExtraDetectionsExtraDetections(get_backscatter_is_compensated))

        // ----- operators -----
        .def("__eq__",
             &ExtraDetectionsExtraDetections::operator==,
             DOC_ExtraDetectionsExtraDetections(operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(ExtraDetectionsExtraDetections)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(ExtraDetectionsExtraDetections)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}