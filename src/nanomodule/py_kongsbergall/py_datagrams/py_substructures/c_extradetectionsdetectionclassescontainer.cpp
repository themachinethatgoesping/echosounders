// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <xtensor-python/nanobind/pytensor.hpp>

#include "../../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/substructures/extradetectionsdetectionclassescontainer.hpp"

#include "../module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {
namespace py_substructures {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::substructures::ExtraDetectionsDetectionClassesContainer;

#define DOC_EDDCC(ARG)                                                                             \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kongsbergall,                                                                              \
        datagrams,                                                                                 \
        substructures,                                                                             \
        ExtraDetectionsDetectionClassesContainer,                                                  \
        ARG)

void init_c_extradetectionsdetectionclassescontainer(nanobind::module_& m)
{
    nb::class_<ExtraDetectionsDetectionClassesContainer>(
        m,
        "ExtraDetectionsDetectionClassesContainer",
        DOC_EDDCC(ExtraDetectionsDetectionClassesContainer))
        .def(nb::init<>(), DOC_EDDCC(ExtraDetectionsDetectionClassesContainer))

        .def_prop_rw("detection_classes",
                     &ExtraDetectionsDetectionClassesContainer::detection_classes,
                     &ExtraDetectionsDetectionClassesContainer::set_detection_classes,
                     DOC_EDDCC(detection_classes),
                     nb::rv_policy::reference_internal)
        .def("get_detection_classes",
             &ExtraDetectionsDetectionClassesContainer::get_detection_classes,
             DOC_EDDCC(get_detection_classes))
        .def("set_detection_classes",
             &ExtraDetectionsDetectionClassesContainer::set_detection_classes,
             DOC_EDDCC(set_detection_classes),
             nb::arg("detection_classes"))

        // ----- raw fields -----
        .def("get_start_depth_tensor",
             &ExtraDetectionsDetectionClassesContainer::get_start_depth_tensor,
             DOC_EDDCC(get_start_depth_tensor),
             nb::arg("indices") = std::vector<uint32_t>{})
        .def("get_stop_depth_tensor",
             &ExtraDetectionsDetectionClassesContainer::get_stop_depth_tensor,
             DOC_EDDCC(get_stop_depth_tensor),
             nb::arg("indices") = std::vector<uint32_t>{})
        .def("get_qf_threshold_100_tensor",
             &ExtraDetectionsDetectionClassesContainer::get_qf_threshold_100_tensor,
             DOC_EDDCC(get_qf_threshold_100_tensor),
             nb::arg("indices") = std::vector<uint32_t>{})
        .def("get_bs_threshold_tensor",
             &ExtraDetectionsDetectionClassesContainer::get_bs_threshold_tensor,
             DOC_EDDCC(get_bs_threshold_tensor),
             nb::arg("indices") = std::vector<uint32_t>{})
        .def("get_snr_threshold_tensor",
             &ExtraDetectionsDetectionClassesContainer::get_snr_threshold_tensor,
             DOC_EDDCC(get_snr_threshold_tensor),
             nb::arg("indices") = std::vector<uint32_t>{})
        .def("get_alarm_threshold_tensor",
             &ExtraDetectionsDetectionClassesContainer::get_alarm_threshold_tensor,
             DOC_EDDCC(get_alarm_threshold_tensor),
             nb::arg("indices") = std::vector<uint32_t>{})
        .def("get_number_of_extra_detections_tensor",
             &ExtraDetectionsDetectionClassesContainer::get_number_of_extra_detections_tensor,
             DOC_EDDCC(get_number_of_extra_detections_tensor),
             nb::arg("indices") = std::vector<uint32_t>{})
        .def("get_show_class_tensor",
             &ExtraDetectionsDetectionClassesContainer::get_show_class_tensor,
             DOC_EDDCC(get_show_class_tensor),
             nb::arg("indices") = std::vector<uint32_t>{})
        .def("get_alarm_flag_1_tensor",
             &ExtraDetectionsDetectionClassesContainer::get_alarm_flag_1_tensor,
             DOC_EDDCC(get_alarm_flag_1_tensor),
             nb::arg("indices") = std::vector<uint32_t>{})

        // ----- processed -----
        .def("get_qf_threshold_tensor",
             &ExtraDetectionsDetectionClassesContainer::get_qf_threshold_tensor,
             DOC_EDDCC(get_qf_threshold_tensor),
             nb::arg("indices") = std::vector<uint32_t>{})

        // ----- size -----
        .def("get_number_of_detection_classes",
             &ExtraDetectionsDetectionClassesContainer::get_number_of_detection_classes,
             DOC_EDDCC(get_number_of_detection_classes))

        // ----- operators -----
        .def("__eq__",
             &ExtraDetectionsDetectionClassesContainer::operator==,
             DOC_EDDCC(operator_eq),
             nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(ExtraDetectionsDetectionClassesContainer)
        __PYCLASS_DEFAULT_PRINTING__(ExtraDetectionsDetectionClassesContainer)
        ;
}

}
}
}
}
}
}
