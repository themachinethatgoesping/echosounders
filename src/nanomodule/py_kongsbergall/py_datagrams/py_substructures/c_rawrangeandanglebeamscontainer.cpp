// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <xtensor-python/nanobind/pytensor.hpp>

#include "../../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/substructures/rawrangeandanglebeamscontainer.hpp"

#include "../module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {
namespace py_substructures {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::substructures::RawRangeAndAngleBeamsContainer;

#define DOC_RawRangeAndAngleBeamsContainer(ARG)                                                    \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kongsbergall,                                                                              \
        datagrams,                                                                                 \
        substructures,                                                                             \
        RawRangeAndAngleBeamsContainer,                                                            \
        ARG)

void init_c_rawrangeandanglebeamscontainer(nanobind::module_& m)
{
    nb::class_<RawRangeAndAngleBeamsContainer>(
        m,
        "RawRangeAndAngleBeamsContainer",
        DOC_RawRangeAndAngleBeamsContainer(RawRangeAndAngleBeamsContainer))
        .def(nb::init<>(), DOC_RawRangeAndAngleBeamsContainer(RawRangeAndAngleBeamsContainer))

        .def_prop_rw("beams",
                     &RawRangeAndAngleBeamsContainer::beams,
                     &RawRangeAndAngleBeamsContainer::set_beams,
                     DOC_RawRangeAndAngleBeamsContainer(beams),
                     nb::rv_policy::reference_internal)
        .def("get_beams",
             &RawRangeAndAngleBeamsContainer::get_beams,
             DOC_RawRangeAndAngleBeamsContainer(get_beams))
        .def("set_beams",
             &RawRangeAndAngleBeamsContainer::set_beams,
             DOC_RawRangeAndAngleBeamsContainer(set_beams),
             nb::arg("beams"))

        // ----- raw fields -----
        .def("get_beam_crosstrack_angle_tensor",
             &RawRangeAndAngleBeamsContainer::get_beam_crosstrack_angle_tensor,
             DOC_RawRangeAndAngleBeamsContainer(get_beam_crosstrack_angle_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_transmit_sector_number_tensor",
             &RawRangeAndAngleBeamsContainer::get_transmit_sector_number_tensor,
             DOC_RawRangeAndAngleBeamsContainer(get_transmit_sector_number_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_detection_info_tensor",
             &RawRangeAndAngleBeamsContainer::get_detection_info_tensor,
             DOC_RawRangeAndAngleBeamsContainer(get_detection_info_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_detection_window_length_in_samples_tensor",
             &RawRangeAndAngleBeamsContainer::get_detection_window_length_in_samples_tensor,
             DOC_RawRangeAndAngleBeamsContainer(get_detection_window_length_in_samples_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_quality_factor_tensor",
             &RawRangeAndAngleBeamsContainer::get_quality_factor_tensor,
             DOC_RawRangeAndAngleBeamsContainer(get_quality_factor_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_d_corr_tensor",
             &RawRangeAndAngleBeamsContainer::get_d_corr_tensor,
             DOC_RawRangeAndAngleBeamsContainer(get_d_corr_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_two_way_travel_time_tensor",
             &RawRangeAndAngleBeamsContainer::get_two_way_travel_time_tensor,
             DOC_RawRangeAndAngleBeamsContainer(get_two_way_travel_time_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_reflectivity_tensor",
             &RawRangeAndAngleBeamsContainer::get_reflectivity_tensor,
             DOC_RawRangeAndAngleBeamsContainer(get_reflectivity_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_realtime_cleaning_info_tensor",
             &RawRangeAndAngleBeamsContainer::get_realtime_cleaning_info_tensor,
             DOC_RawRangeAndAngleBeamsContainer(get_realtime_cleaning_info_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_spare_tensor",
             &RawRangeAndAngleBeamsContainer::get_spare_tensor,
             DOC_RawRangeAndAngleBeamsContainer(get_spare_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})

        // ----- processed -----
        .def("get_beam_crosstrack_angle_in_degrees_tensor",
             &RawRangeAndAngleBeamsContainer::get_beam_crosstrack_angle_in_degrees_tensor,
             DOC_RawRangeAndAngleBeamsContainer(get_beam_crosstrack_angle_in_degrees_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_reflectivity_in_db_tensor",
             &RawRangeAndAngleBeamsContainer::get_reflectivity_in_db_tensor,
             DOC_RawRangeAndAngleBeamsContainer(get_reflectivity_in_db_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_detection_is_valid_tensor",
             &RawRangeAndAngleBeamsContainer::get_detection_is_valid_tensor,
             DOC_RawRangeAndAngleBeamsContainer(get_detection_is_valid_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_detection_type_tensor",
             &RawRangeAndAngleBeamsContainer::get_detection_type_tensor,
             DOC_RawRangeAndAngleBeamsContainer(get_detection_type_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_backscatter_is_compensated_tensor",
             &RawRangeAndAngleBeamsContainer::get_backscatter_is_compensated_tensor,
             DOC_RawRangeAndAngleBeamsContainer(get_backscatter_is_compensated_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})

        // ----- size -----
        .def("get_number_of_beams",
             &RawRangeAndAngleBeamsContainer::get_number_of_beams,
             DOC_RawRangeAndAngleBeamsContainer(get_number_of_beams))

        // ----- operators -----
        .def("__eq__",
             &RawRangeAndAngleBeamsContainer::operator==,
             DOC_RawRangeAndAngleBeamsContainer(operator_eq),
             nb::arg("other"))
        // ----- pybind macros -----
        __PYCLASS_DEFAULT_COPY__(RawRangeAndAngleBeamsContainer)
        __PYCLASS_DEFAULT_PRINTING__(RawRangeAndAngleBeamsContainer)
        ;
}

}
}
}
}
}
}
