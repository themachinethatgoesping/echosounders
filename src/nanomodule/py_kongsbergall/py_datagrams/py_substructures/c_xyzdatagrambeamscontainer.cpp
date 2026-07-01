// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <xtensor-python/nanobind/pytensor.hpp>

#include "../../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/substructures/xyzdatagrambeamscontainer.hpp"

#include "../module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {
namespace py_substructures {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::substructures::XYZDatagramBeamsContainer;

#define DOC_XYZDatagramBeamsContainer(ARG)                                                         \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kongsbergall,                                                                              \
        datagrams,                                                                                 \
        substructures,                                                                             \
        XYZDatagramBeamsContainer,                                                                 \
        ARG)

void init_c_xyzdatagrambeamscontainer(nanobind::module_& m)
{
    nb::class_<XYZDatagramBeamsContainer>(
        m,
        "XYZDatagramBeamsContainer",
        DOC_XYZDatagramBeamsContainer(XYZDatagramBeamsContainer))
        .def(nb::init<>(), DOC_XYZDatagramBeamsContainer(XYZDatagramBeamsContainer))

        .def_prop_rw("beams",
                     &XYZDatagramBeamsContainer::beams,
                     &XYZDatagramBeamsContainer::set_beams,
                     DOC_XYZDatagramBeamsContainer(beams),
                     nb::rv_policy::reference_internal)
        .def("get_beams",
             &XYZDatagramBeamsContainer::get_beams,
             DOC_XYZDatagramBeamsContainer(get_beams))
        .def("set_beams",
             &XYZDatagramBeamsContainer::set_beams,
             DOC_XYZDatagramBeamsContainer(set_beams),
             nb::arg("beams"))

        .def("get_depth_tensor",
             &XYZDatagramBeamsContainer::get_depth_tensor,
             DOC_XYZDatagramBeamsContainer(get_depth_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_acrosstrack_distance_tensor",
             &XYZDatagramBeamsContainer::get_acrosstrack_distance_tensor,
             DOC_XYZDatagramBeamsContainer(get_acrosstrack_distance_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_alongtrack_distance_tensor",
             &XYZDatagramBeamsContainer::get_alongtrack_distance_tensor,
             DOC_XYZDatagramBeamsContainer(get_alongtrack_distance_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_detection_window_length_tensor",
             &XYZDatagramBeamsContainer::get_detection_window_length_tensor,
             DOC_XYZDatagramBeamsContainer(get_detection_window_length_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_quality_factor_tensor",
             &XYZDatagramBeamsContainer::get_quality_factor_tensor,
             DOC_XYZDatagramBeamsContainer(get_quality_factor_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_beam_incidence_angle_adjustment_tensor",
             &XYZDatagramBeamsContainer::get_beam_incidence_angle_adjustment_tensor,
             DOC_XYZDatagramBeamsContainer(get_beam_incidence_angle_adjustment_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_detection_info_tensor",
             &XYZDatagramBeamsContainer::get_detection_info_tensor,
             DOC_XYZDatagramBeamsContainer(get_detection_info_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_realtime_cleaning_information_tensor",
             &XYZDatagramBeamsContainer::get_realtime_cleaning_information_tensor,
             DOC_XYZDatagramBeamsContainer(get_realtime_cleaning_information_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_reflectivity_tensor",
             &XYZDatagramBeamsContainer::get_reflectivity_tensor,
             DOC_XYZDatagramBeamsContainer(get_reflectivity_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})

        .def("get_backscatter_tensor",
             &XYZDatagramBeamsContainer::get_backscatter_tensor,
             DOC_XYZDatagramBeamsContainer(get_backscatter_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_beam_incidence_angle_adjustment_in_degrees_tensor",
             &XYZDatagramBeamsContainer::get_beam_incidence_angle_adjustment_in_degrees_tensor,
             DOC_XYZDatagramBeamsContainer(get_beam_incidence_angle_adjustment_in_degrees_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_detection_is_valid_tensor",
             &XYZDatagramBeamsContainer::get_detection_is_valid_tensor,
             DOC_XYZDatagramBeamsContainer(get_detection_is_valid_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_detection_type_tensor",
             &XYZDatagramBeamsContainer::get_detection_type_tensor,
             DOC_XYZDatagramBeamsContainer(get_detection_type_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})
        .def("get_backscatter_is_compensated_tensor",
             &XYZDatagramBeamsContainer::get_backscatter_is_compensated_tensor,
             DOC_XYZDatagramBeamsContainer(get_backscatter_is_compensated_tensor),
             nb::arg("beam_numbers") = std::vector<uint32_t>{})

        .def("get_number_of_beams",
             &XYZDatagramBeamsContainer::get_number_of_beams,
             DOC_XYZDatagramBeamsContainer(get_number_of_beams))
        .def("get_xyz",
             nb::overload_cast<>(&XYZDatagramBeamsContainer::get_xyz, nb::const_),
             DOC_XYZDatagramBeamsContainer(get_xyz))
        .def("get_xyz",
             nb::overload_cast<const std::vector<uint32_t>&>(&XYZDatagramBeamsContainer::get_xyz,
                                                             nb::const_),
             DOC_XYZDatagramBeamsContainer(get_xyz_2),
             nb::arg("beam_numbers"))

        .def("__eq__",
             &XYZDatagramBeamsContainer::operator==,
             DOC_XYZDatagramBeamsContainer(operator_eq),
             nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(XYZDatagramBeamsContainer)
        __PYCLASS_DEFAULT_PRINTING__(XYZDatagramBeamsContainer)
        ;
}

}
}
}
}
}
}