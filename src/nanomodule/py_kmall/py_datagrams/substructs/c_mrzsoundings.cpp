// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/bind_vector.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/substructs/mrzsoundings.hpp>

#include "../module.hpp"

NB_MAKE_OPAQUE(
    std::vector<themachinethatgoesping::echosounders::kmall::datagrams::substructs::MRZSoundings>);

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::substructs::MRZSoundings;

#define DOC_MRZSoundings(ARG)                                                                      \
    DOC(themachinethatgoesping, echosounders, kmall, datagrams, substructs, MRZSoundings, ARG)

void init_c_mrzsoundings(nanobind::module_& m)
{
    nb::class_<MRZSoundings>(m, "MRZSoundings", DOC_MRZSoundings(MRZSoundings))
        .def(nb::init<>(), DOC_MRZSoundings(MRZSoundings))
        .def("get_sounding_index",
             &MRZSoundings::get_sounding_index,
             DOC_MRZSoundings(get_sounding_index))
        .def("set_sounding_index",
             &MRZSoundings::set_sounding_index,
             DOC_MRZSoundings(set_sounding_index),
             nb::arg("val"))
        .def("get_tx_sector_number",
             &MRZSoundings::get_tx_sector_number,
             DOC_MRZSoundings(get_tx_sector_number))
        .def("set_tx_sector_number",
             &MRZSoundings::set_tx_sector_number,
             DOC_MRZSoundings(set_tx_sector_number),
             nb::arg("val"))
        .def("get_detection_type",
             &MRZSoundings::get_detection_type,
             DOC_MRZSoundings(get_detection_type))
        .def("set_detection_type",
             &MRZSoundings::set_detection_type,
             DOC_MRZSoundings(set_detection_type),
             nb::arg("val"))
        .def("get_detection_method",
             &MRZSoundings::get_detection_method,
             DOC_MRZSoundings(get_detection_method))
        .def("set_detection_method",
             &MRZSoundings::set_detection_method,
             DOC_MRZSoundings(set_detection_method),
             nb::arg("val"))
        .def("get_rejection_info_1",
             &MRZSoundings::get_rejection_info_1,
             DOC_MRZSoundings(get_rejection_info_1))
        .def("set_rejection_info_1",
             &MRZSoundings::set_rejection_info_1,
             DOC_MRZSoundings(set_rejection_info_1),
             nb::arg("val"))
        .def("get_rejection_info_2",
             &MRZSoundings::get_rejection_info_2,
             DOC_MRZSoundings(get_rejection_info_2))
        .def("set_rejection_info_2",
             &MRZSoundings::set_rejection_info_2,
             DOC_MRZSoundings(set_rejection_info_2),
             nb::arg("val"))
        .def("get_post_processing_info",
             &MRZSoundings::get_post_processing_info,
             DOC_MRZSoundings(get_post_processing_info))
        .def("set_post_processing_info",
             &MRZSoundings::set_post_processing_info,
             DOC_MRZSoundings(set_post_processing_info),
             nb::arg("val"))
        .def("get_detection_class",
             &MRZSoundings::get_detection_class,
             DOC_MRZSoundings(get_detection_class))
        .def("set_detection_class",
             &MRZSoundings::set_detection_class,
             DOC_MRZSoundings(set_detection_class),
             nb::arg("val"))
        .def("get_detection_confidence_level",
             &MRZSoundings::get_detection_confidence_level,
             DOC_MRZSoundings(get_detection_confidence_level))
        .def("set_detection_confidence_level",
             &MRZSoundings::set_detection_confidence_level,
             DOC_MRZSoundings(set_detection_confidence_level),
             nb::arg("val"))
        .def("get_padding", &MRZSoundings::get_padding, DOC_MRZSoundings(get_padding))
        .def("set_padding",
             &MRZSoundings::set_padding,
             DOC_MRZSoundings(set_padding),
             nb::arg("val"))
        .def(
            "get_range_factor", &MRZSoundings::get_range_factor, DOC_MRZSoundings(get_range_factor))
        .def("set_range_factor",
             &MRZSoundings::set_range_factor,
             DOC_MRZSoundings(set_range_factor),
             nb::arg("val"))
        .def("get_quality_factor",
             &MRZSoundings::get_quality_factor,
             DOC_MRZSoundings(get_quality_factor))
        .def("set_quality_factor",
             &MRZSoundings::set_quality_factor,
             DOC_MRZSoundings(set_quality_factor),
             nb::arg("val"))
        .def("get_detection_uncertainty_ver_m",
             &MRZSoundings::get_detection_uncertainty_ver_m,
             DOC_MRZSoundings(get_detection_uncertainty_ver_m))
        .def("set_detection_uncertainty_ver_m",
             &MRZSoundings::set_detection_uncertainty_ver_m,
             DOC_MRZSoundings(set_detection_uncertainty_ver_m),
             nb::arg("val"))
        .def("get_detection_uncertainty_hor_m",
             &MRZSoundings::get_detection_uncertainty_hor_m,
             DOC_MRZSoundings(get_detection_uncertainty_hor_m))
        .def("set_detection_uncertainty_hor_m",
             &MRZSoundings::set_detection_uncertainty_hor_m,
             DOC_MRZSoundings(set_detection_uncertainty_hor_m),
             nb::arg("val"))
        .def("get_detection_window_length_sec",
             &MRZSoundings::get_detection_window_length_sec,
             DOC_MRZSoundings(get_detection_window_length_sec))
        .def("set_detection_window_length_sec",
             &MRZSoundings::set_detection_window_length_sec,
             DOC_MRZSoundings(set_detection_window_length_sec),
             nb::arg("val"))
        .def("get_echo_length_sec",
             &MRZSoundings::get_echo_length_sec,
             DOC_MRZSoundings(get_echo_length_sec))
        .def("set_echo_length_sec",
             &MRZSoundings::set_echo_length_sec,
             DOC_MRZSoundings(set_echo_length_sec),
             nb::arg("val"))
        .def("get_wc_beam_number",
             &MRZSoundings::get_wc_beam_number,
             DOC_MRZSoundings(get_wc_beam_number))
        .def("set_wc_beam_number",
             &MRZSoundings::set_wc_beam_number,
             DOC_MRZSoundings(set_wc_beam_number),
             nb::arg("val"))
        .def("get_wc_range_samples",
             &MRZSoundings::get_wc_range_samples,
             DOC_MRZSoundings(get_wc_range_samples))
        .def("set_wc_range_samples",
             &MRZSoundings::set_wc_range_samples,
             DOC_MRZSoundings(set_wc_range_samples),
             nb::arg("val"))
        .def("get_wc_nom_beam_angle_across_deg",
             &MRZSoundings::get_wc_nom_beam_angle_across_deg,
             DOC_MRZSoundings(get_wc_nom_beam_angle_across_deg))
        .def("set_wc_nom_beam_angle_across_deg",
             &MRZSoundings::set_wc_nom_beam_angle_across_deg,
             DOC_MRZSoundings(set_wc_nom_beam_angle_across_deg),
             nb::arg("val"))
        .def("get_mean_abs_coeff_db_per_km",
             &MRZSoundings::get_mean_abs_coeff_db_per_km,
             DOC_MRZSoundings(get_mean_abs_coeff_db_per_km))
        .def("set_mean_abs_coeff_db_per_km",
             &MRZSoundings::set_mean_abs_coeff_db_per_km,
             DOC_MRZSoundings(set_mean_abs_coeff_db_per_km),
             nb::arg("val"))
        .def("get_reflectivity_1_db",
             &MRZSoundings::get_reflectivity_1_db,
             DOC_MRZSoundings(get_reflectivity_1_db))
        .def("set_reflectivity_1_db",
             &MRZSoundings::set_reflectivity_1_db,
             DOC_MRZSoundings(set_reflectivity_1_db),
             nb::arg("val"))
        .def("get_reflectivity_2_db",
             &MRZSoundings::get_reflectivity_2_db,
             DOC_MRZSoundings(get_reflectivity_2_db))
        .def("set_reflectivity_2_db",
             &MRZSoundings::set_reflectivity_2_db,
             DOC_MRZSoundings(set_reflectivity_2_db),
             nb::arg("val"))
        .def("get_receiver_sensitivity_applied_db",
             &MRZSoundings::get_receiver_sensitivity_applied_db,
             DOC_MRZSoundings(get_receiver_sensitivity_applied_db))
        .def("set_receiver_sensitivity_applied_db",
             &MRZSoundings::set_receiver_sensitivity_applied_db,
             DOC_MRZSoundings(set_receiver_sensitivity_applied_db),
             nb::arg("val"))
        .def("get_source_level_applied_db",
             &MRZSoundings::get_source_level_applied_db,
             DOC_MRZSoundings(get_source_level_applied_db))
        .def("set_source_level_applied_db",
             &MRZSoundings::set_source_level_applied_db,
             DOC_MRZSoundings(set_source_level_applied_db),
             nb::arg("val"))
        .def("get_bs_calibration_db",
             &MRZSoundings::get_bs_calibration_db,
             DOC_MRZSoundings(get_bs_calibration_db))
        .def("set_bs_calibration_db",
             &MRZSoundings::set_bs_calibration_db,
             DOC_MRZSoundings(set_bs_calibration_db),
             nb::arg("val"))
        .def("get_tvg_db", &MRZSoundings::get_tvg_db, DOC_MRZSoundings(get_tvg_db))
        .def("set_tvg_db", &MRZSoundings::set_tvg_db, DOC_MRZSoundings(set_tvg_db), nb::arg("val"))
        .def("get_beam_angle_re_rx_deg",
             &MRZSoundings::get_beam_angle_re_rx_deg,
             DOC_MRZSoundings(get_beam_angle_re_rx_deg))
        .def("set_beam_angle_re_rx_deg",
             &MRZSoundings::set_beam_angle_re_rx_deg,
             DOC_MRZSoundings(set_beam_angle_re_rx_deg),
             nb::arg("val"))
        .def("get_beam_angle_correction_deg",
             &MRZSoundings::get_beam_angle_correction_deg,
             DOC_MRZSoundings(get_beam_angle_correction_deg))
        .def("set_beam_angle_correction_deg",
             &MRZSoundings::set_beam_angle_correction_deg,
             DOC_MRZSoundings(set_beam_angle_correction_deg),
             nb::arg("val"))
        .def("get_two_way_travel_time_sec",
             &MRZSoundings::get_two_way_travel_time_sec,
             DOC_MRZSoundings(get_two_way_travel_time_sec))
        .def("set_two_way_travel_time_sec",
             &MRZSoundings::set_two_way_travel_time_sec,
             DOC_MRZSoundings(set_two_way_travel_time_sec),
             nb::arg("val"))
        .def("get_two_way_travel_time_correction_sec",
             &MRZSoundings::get_two_way_travel_time_correction_sec,
             DOC_MRZSoundings(get_two_way_travel_time_correction_sec))
        .def("set_two_way_travel_time_correction_sec",
             &MRZSoundings::set_two_way_travel_time_correction_sec,
             DOC_MRZSoundings(set_two_way_travel_time_correction_sec),
             nb::arg("val"))
        .def("get_delta_latitude_deg",
             &MRZSoundings::get_delta_latitude_deg,
             DOC_MRZSoundings(get_delta_latitude_deg))
        .def("set_delta_latitude_deg",
             &MRZSoundings::set_delta_latitude_deg,
             DOC_MRZSoundings(set_delta_latitude_deg),
             nb::arg("val"))
        .def("get_delta_longitude_deg",
             &MRZSoundings::get_delta_longitude_deg,
             DOC_MRZSoundings(get_delta_longitude_deg))
        .def("set_delta_longitude_deg",
             &MRZSoundings::set_delta_longitude_deg,
             DOC_MRZSoundings(set_delta_longitude_deg),
             nb::arg("val"))
        .def("get_z_re_ref_point_m",
             &MRZSoundings::get_z_re_ref_point_m,
             DOC_MRZSoundings(get_z_re_ref_point_m))
        .def("set_z_re_ref_point_m",
             &MRZSoundings::set_z_re_ref_point_m,
             DOC_MRZSoundings(set_z_re_ref_point_m),
             nb::arg("val"))
        .def("get_y_re_ref_point_m",
             &MRZSoundings::get_y_re_ref_point_m,
             DOC_MRZSoundings(get_y_re_ref_point_m))
        .def("set_y_re_ref_point_m",
             &MRZSoundings::set_y_re_ref_point_m,
             DOC_MRZSoundings(set_y_re_ref_point_m),
             nb::arg("val"))
        .def("get_x_re_ref_point_m",
             &MRZSoundings::get_x_re_ref_point_m,
             DOC_MRZSoundings(get_x_re_ref_point_m))
        .def("set_x_re_ref_point_m",
             &MRZSoundings::set_x_re_ref_point_m,
             DOC_MRZSoundings(set_x_re_ref_point_m),
             nb::arg("val"))
        .def("get_beam_inc_angle_adj_deg",
             &MRZSoundings::get_beam_inc_angle_adj_deg,
             DOC_MRZSoundings(get_beam_inc_angle_adj_deg))
        .def("set_beam_inc_angle_adj_deg",
             &MRZSoundings::set_beam_inc_angle_adj_deg,
             DOC_MRZSoundings(set_beam_inc_angle_adj_deg),
             nb::arg("val"))
        .def("get_real_time_clean_info",
             &MRZSoundings::get_real_time_clean_info,
             DOC_MRZSoundings(get_real_time_clean_info))
        .def("set_real_time_clean_info",
             &MRZSoundings::set_real_time_clean_info,
             DOC_MRZSoundings(set_real_time_clean_info),
             nb::arg("val"))
        .def("get_si_start_range_samples",
             &MRZSoundings::get_si_start_range_samples,
             DOC_MRZSoundings(get_si_start_range_samples))
        .def("set_si_start_range_samples",
             &MRZSoundings::set_si_start_range_samples,
             DOC_MRZSoundings(set_si_start_range_samples),
             nb::arg("val"))
        .def("get_si_centre_sample",
             &MRZSoundings::get_si_centre_sample,
             DOC_MRZSoundings(get_si_centre_sample))
        .def("set_si_centre_sample",
             &MRZSoundings::set_si_centre_sample,
             DOC_MRZSoundings(set_si_centre_sample),
             nb::arg("val"))
        .def("get_si_num_samples",
             &MRZSoundings::get_si_num_samples,
             DOC_MRZSoundings(get_si_num_samples))
        .def("set_si_num_samples",
             &MRZSoundings::set_si_num_samples,
             DOC_MRZSoundings(set_si_num_samples),
             nb::arg("val"))

        // ----- operators -----
        .def("__eq__", &MRZSoundings::operator==, DOC_MRZSoundings(operator_eq), nb::arg("other"))
        // ----- pybind macros -----
        // copy
        __PYCLASS_DEFAULT_COPY__(MRZSoundings)
        // print
        __PYCLASS_DEFAULT_PRINTING__(MRZSoundings)
        // end
        ;

    nb::bind_vector<std::vector<MRZSoundings>>(m, "MRZSoundingsVector");
}

}
}
}
}
}
