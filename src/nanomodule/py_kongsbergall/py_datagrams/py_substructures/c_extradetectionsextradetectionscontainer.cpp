// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <xtensor-python/nanobind/pytensor.hpp>

#include "../../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/substructures/extradetectionsextradetectionscontainer.hpp"

#include "../module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {
namespace py_substructures {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::substructures::ExtraDetectionsExtraDetectionsContainer;

#define DOC_EDEDC(ARG)                                                                             \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kongsbergall,                                                                              \
        datagrams,                                                                                 \
        substructures,                                                                             \
        ExtraDetectionsExtraDetectionsContainer,                                                   \
        ARG)

#define DEF_TENSOR(NAME)                                                                           \
    .def("get_" #NAME "_tensor",                                                                   \
         &ExtraDetectionsExtraDetectionsContainer::get_##NAME##_tensor,                            \
         DOC_EDEDC(get_##NAME##_tensor),                                                           \
         nb::arg("indices") = std::vector<uint32_t>{})

void init_c_extradetectionsextradetectionscontainer(nanobind::module_& m)
{
    nb::class_<ExtraDetectionsExtraDetectionsContainer>(
        m,
        "ExtraDetectionsExtraDetectionsContainer",
        DOC_EDEDC(ExtraDetectionsExtraDetectionsContainer))
        .def(nb::init<>(), DOC_EDEDC(ExtraDetectionsExtraDetectionsContainer))

        .def_prop_rw("extra_detections",
                     &ExtraDetectionsExtraDetectionsContainer::extra_detections,
                     &ExtraDetectionsExtraDetectionsContainer::set_extra_detections,
                     DOC_EDEDC(extra_detections),
                     nb::rv_policy::reference_internal)
        .def("get_extra_detections",
             &ExtraDetectionsExtraDetectionsContainer::get_extra_detections,
             DOC_EDEDC(get_extra_detections))
        .def("set_extra_detections",
             &ExtraDetectionsExtraDetectionsContainer::set_extra_detections,
             DOC_EDEDC(set_extra_detections),
             nb::arg("extra_detections"))

        // ----- raw fields -----
        DEF_TENSOR(depth)
        DEF_TENSOR(across)
        DEF_TENSOR(along)
        DEF_TENSOR(delta_latitude)
        DEF_TENSOR(delta_longitude)
        DEF_TENSOR(beam_crosstrack_angle)
        DEF_TENSOR(applied_pointing_angle_correction)
        DEF_TENSOR(two_way_travel_time)
        DEF_TENSOR(applied_two_way_travel_time_corrections)
        DEF_TENSOR(backscatter)
        DEF_TENSOR(beam_incidence_angle_adjustment)
        DEF_TENSOR(detection_info)
        DEF_TENSOR(spare)
        DEF_TENSOR(tx_sector_number)
        DEF_TENSOR(detection_window_length)
        DEF_TENSOR(quality_factor_old)
        DEF_TENSOR(real_time_cleaning_info)
        DEF_TENSOR(range_factor)
        DEF_TENSOR(detection_class_number)
        DEF_TENSOR(confidence_level)
        DEF_TENSOR(qf_10)
        DEF_TENSOR(water_column_beam_number)
        DEF_TENSOR(beam_angle_across)
        DEF_TENSOR(detected_range)
        DEF_TENSOR(number_of_raw_amplitude_samples)

        // ----- processed -----
        DEF_TENSOR(qf_threshold)
        DEF_TENSOR(backscatter_in_db)
        DEF_TENSOR(detection_is_valid)
        DEF_TENSOR(detection_type)
        DEF_TENSOR(backscatter_is_compensated)

        // ----- size -----
        .def("get_number_of_extra_detections",
             &ExtraDetectionsExtraDetectionsContainer::get_number_of_extra_detections,
             DOC_EDEDC(get_number_of_extra_detections))

        // ----- operators -----
        .def("__eq__",
             &ExtraDetectionsExtraDetectionsContainer::operator==,
             DOC_EDEDC(operator_eq),
             nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(ExtraDetectionsExtraDetectionsContainer)
        __PYCLASS_DEFAULT_PRINTING__(ExtraDetectionsExtraDetectionsContainer)
        ;
}

#undef DEF_TENSOR

}
}
}
}
}
}
