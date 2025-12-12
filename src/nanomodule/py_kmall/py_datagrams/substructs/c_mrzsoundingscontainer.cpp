// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/pytensor_nanobind.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/substructs/mrzsoundingscontainer.hpp>

#include "../module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::substructs::MRZSoundings;
using datagrams::substructs::MRZSoundingsContainer;

#define DOC_MRZSoundingsContainer(ARG)                                                             \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kmall,                                                                                     \
        datagrams,                                                                                 \
        substructs,                                                                                \
        MRZSoundingsContainer,                                                                     \
        ARG)

void init_c_mrzsoundingscontainer(nanobind::module_& m)
{
    nb::class_<MRZSoundingsContainer>(
        m, "MRZSoundingsContainer", DOC_MRZSoundingsContainer(MRZSoundingsContainer))
        .def(nb::init<>(), DOC_MRZSoundingsContainer(MRZSoundingsContainer))

        .def_prop_rw("soundings",
                     &MRZSoundingsContainer::soundings,
                     &MRZSoundingsContainer::set_soundings,
                     DOC_MRZSoundingsContainer(soundings),
                     nb::rv_policy::reference_internal)

        .def("get_sounding_index_tensor",
             &MRZSoundingsContainer::get_sounding_index_tensor,
             DOC_MRZSoundingsContainer(get_sounding_index_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_tx_sector_number_tensor",
             &MRZSoundingsContainer::get_tx_sector_number_tensor,
             DOC_MRZSoundingsContainer(get_tx_sector_number_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_detection_type_tensor",
             &MRZSoundingsContainer::get_detection_type_tensor,
             DOC_MRZSoundingsContainer(get_detection_type_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_detection_method_tensor",
             &MRZSoundingsContainer::get_detection_method_tensor,
             DOC_MRZSoundingsContainer(get_detection_method_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_rejection_info_1_tensor",
             &MRZSoundingsContainer::get_rejection_info_1_tensor,
             DOC_MRZSoundingsContainer(get_rejection_info_1_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_rejection_info_2_tensor",
             &MRZSoundingsContainer::get_rejection_info_2_tensor,
             DOC_MRZSoundingsContainer(get_rejection_info_2_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_post_processing_info_tensor",
             &MRZSoundingsContainer::get_post_processing_info_tensor,
             DOC_MRZSoundingsContainer(get_post_processing_info_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_detection_class_tensor",
             &MRZSoundingsContainer::get_detection_class_tensor,
             DOC_MRZSoundingsContainer(get_detection_class_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_detection_confidence_level_tensor",
             &MRZSoundingsContainer::get_detection_confidence_level_tensor,
             DOC_MRZSoundingsContainer(get_detection_confidence_level_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_padding_tensor",
             &MRZSoundingsContainer::get_padding_tensor,
             DOC_MRZSoundingsContainer(get_padding_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_range_factor_tensor",
             &MRZSoundingsContainer::get_range_factor_tensor,
             DOC_MRZSoundingsContainer(get_range_factor_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_quality_factor_tensor",
             &MRZSoundingsContainer::get_quality_factor_tensor,
             DOC_MRZSoundingsContainer(get_quality_factor_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_detection_uncertainty_ver_m_tensor",
             &MRZSoundingsContainer::get_detection_uncertainty_ver_m_tensor,
             DOC_MRZSoundingsContainer(get_detection_uncertainty_ver_m_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_detection_uncertainty_hor_m_tensor",
             &MRZSoundingsContainer::get_detection_uncertainty_hor_m_tensor,
             DOC_MRZSoundingsContainer(get_detection_uncertainty_hor_m_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_detection_window_length_sec_tensor",
             &MRZSoundingsContainer::get_detection_window_length_sec_tensor,
             DOC_MRZSoundingsContainer(get_detection_window_length_sec_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_echo_length_sec_tensor",
             &MRZSoundingsContainer::get_echo_length_sec_tensor,
             DOC_MRZSoundingsContainer(get_echo_length_sec_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_wc_beam_number_tensor",
             &MRZSoundingsContainer::get_wc_beam_number_tensor,
             DOC_MRZSoundingsContainer(get_wc_beam_number_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_wc_range_samples_tensor",
             &MRZSoundingsContainer::get_wc_range_samples_tensor,
             DOC_MRZSoundingsContainer(get_wc_range_samples_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_wc_nom_beam_angle_across_deg_tensor",
             &MRZSoundingsContainer::get_wc_nom_beam_angle_across_deg_tensor,
             DOC_MRZSoundingsContainer(get_wc_nom_beam_angle_across_deg_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_mean_abs_coeff_db_per_km_tensor",
             &MRZSoundingsContainer::get_mean_abs_coeff_db_per_km_tensor,
             DOC_MRZSoundingsContainer(get_mean_abs_coeff_db_per_km_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_reflectivity_1_db_tensor",
             &MRZSoundingsContainer::get_reflectivity_1_db_tensor,
             DOC_MRZSoundingsContainer(get_reflectivity_1_db_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_reflectivity_2_db_tensor",
             &MRZSoundingsContainer::get_reflectivity_2_db_tensor,
             DOC_MRZSoundingsContainer(get_reflectivity_2_db_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_receiver_sensitivity_applied_db_tensor",
             &MRZSoundingsContainer::get_receiver_sensitivity_applied_db_tensor,
             DOC_MRZSoundingsContainer(get_receiver_sensitivity_applied_db_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_source_level_applied_db_tensor",
             &MRZSoundingsContainer::get_source_level_applied_db_tensor,
             DOC_MRZSoundingsContainer(get_source_level_applied_db_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_bs_calibration_db_tensor",
             &MRZSoundingsContainer::get_bs_calibration_db_tensor,
             DOC_MRZSoundingsContainer(get_bs_calibration_db_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_tvg_db_tensor",
             &MRZSoundingsContainer::get_tvg_db_tensor,
             DOC_MRZSoundingsContainer(get_tvg_db_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_beam_angle_re_rx_deg_tensor",
             &MRZSoundingsContainer::get_beam_angle_re_rx_deg_tensor,
             DOC_MRZSoundingsContainer(get_beam_angle_re_rx_deg_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_beam_angle_correction_deg_tensor",
             &MRZSoundingsContainer::get_beam_angle_correction_deg_tensor,
             DOC_MRZSoundingsContainer(get_beam_angle_correction_deg_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_two_way_travel_time_sec_tensor",
             &MRZSoundingsContainer::get_two_way_travel_time_sec_tensor,
             DOC_MRZSoundingsContainer(get_two_way_travel_time_sec_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_two_way_travel_time_correction_sec_tensor",
             &MRZSoundingsContainer::get_two_way_travel_time_correction_sec_tensor,
             DOC_MRZSoundingsContainer(get_two_way_travel_time_correction_sec_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_delta_latitude_deg_tensor",
             &MRZSoundingsContainer::get_delta_latitude_deg_tensor,
             DOC_MRZSoundingsContainer(get_delta_latitude_deg_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_delta_longitude_deg_tensor",
             &MRZSoundingsContainer::get_delta_longitude_deg_tensor,
             DOC_MRZSoundingsContainer(get_delta_longitude_deg_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_z_re_ref_point_m_tensor",
             &MRZSoundingsContainer::get_z_re_ref_point_m_tensor,
             DOC_MRZSoundingsContainer(get_z_re_ref_point_m_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_y_re_ref_point_m_tensor",
             &MRZSoundingsContainer::get_y_re_ref_point_m_tensor,
             DOC_MRZSoundingsContainer(get_y_re_ref_point_m_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_x_re_ref_point_m_tensor",
             &MRZSoundingsContainer::get_x_re_ref_point_m_tensor,
             DOC_MRZSoundingsContainer(get_x_re_ref_point_m_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_beam_inc_angle_adj_deg_tensor",
             &MRZSoundingsContainer::get_beam_inc_angle_adj_deg_tensor,
             DOC_MRZSoundingsContainer(get_beam_inc_angle_adj_deg_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_real_time_clean_info_tensor",
             &MRZSoundingsContainer::get_real_time_clean_info_tensor,
             DOC_MRZSoundingsContainer(get_real_time_clean_info_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_si_start_range_samples_tensor",
             &MRZSoundingsContainer::get_si_start_range_samples_tensor,
             DOC_MRZSoundingsContainer(get_si_start_range_samples_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_si_centre_sample_tensor",
             &MRZSoundingsContainer::get_si_centre_sample_tensor,
             DOC_MRZSoundingsContainer(get_si_centre_sample_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_si_num_samples_tensor",
             &MRZSoundingsContainer::get_si_num_samples_tensor,
             DOC_MRZSoundingsContainer(get_si_num_samples_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})

        // ----- processed -----
        .def("get_number_of_soundings",
             &MRZSoundingsContainer::get_number_of_soundings,
             DOC_MRZSoundingsContainer(get_number_of_soundings))
        .def("get_number_of_seabed_image_samples",
             &MRZSoundingsContainer::get_number_of_seabed_image_samples,
             DOC_MRZSoundingsContainer(get_number_of_seabed_image_samples))
        .def("get_seabed_image_sounding_index_tensor",
             &MRZSoundingsContainer::get_seabed_image_sounding_index_tensor,
             DOC_MRZSoundingsContainer(get_seabed_image_sounding_index_tensor))
        .def("get_mean_absorption_db_per_m_per_sector",
             &MRZSoundingsContainer::get_mean_absorption_db_per_m_per_sector,
             DOC_MRZSoundingsContainer(get_mean_absorption_db_per_m_per_sector),
             nb::arg("number_of_tx_sectors"))
        .def("get_xyz",
             nb::overload_cast<>(&MRZSoundingsContainer::get_xyz, nb::const_),
             DOC_MRZSoundingsContainer(get_xyz))
        .def("get_xyz",
             nb::overload_cast<const std::vector<uint32_t>&>(&MRZSoundingsContainer::get_xyz,
                                                             nb::const_),
             DOC_MRZSoundingsContainer(get_xyz_2),
             nb::arg("beam_numbers"))

        // ----- operators -----
        .def("__eq__",
             &MRZSoundingsContainer::operator==,
             DOC_MRZSoundingsContainer(operator_eq),
             nb::arg("other"))
        // ----- pybind macros -----
        // copy
        __PYCLASS_DEFAULT_COPY__(MRZSoundingsContainer)
        // print
        __PYCLASS_DEFAULT_PRINTING__(MRZSoundingsContainer)
        // end
        ;
}

}
}
}
}
}
