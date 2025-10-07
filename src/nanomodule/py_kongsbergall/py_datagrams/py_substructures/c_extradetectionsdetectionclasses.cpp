// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "../../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/substructures/extradetectionsdetectionclasses.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {
namespace py_substructures {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::substructures::ExtraDetectionsDetectionClasses;

#define DOC_ExtraDetectionsDetectionClasses(ARG)                                                   \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kongsbergall,                                                                                    \
        datagrams,                                                                                 \
        substructures,                                                                             \
        ExtraDetectionsDetectionClasses,                                                           \
        ARG)

void init_c_extradetectionsdetectionclasses(nanobind::module_& m)
{

     nb::class_<ExtraDetectionsDetectionClasses>(m,
                                                "ExtraDetectionsDetectionClasses",
                                                DOC(themachinethatgoesping,
                                                    echosounders,
                                                    kongsbergall,
                                                    datagrams,
                                                    substructures,
                                                    ExtraDetectionsDetectionClasses))
     .def(nb::init<>(), DOC_ExtraDetectionsDetectionClasses(ExtraDetectionsDetectionClasses))
        // --- convenient data access ---
        .def("set_start_depth",
             &ExtraDetectionsDetectionClasses::set_start_depth,
             DOC_ExtraDetectionsDetectionClasses(start_depth))
        .def("get_start_depth",
             &ExtraDetectionsDetectionClasses::get_start_depth,
             DOC_ExtraDetectionsDetectionClasses(start_depth))
        .def("set_stop_depth",
             &ExtraDetectionsDetectionClasses::set_stop_depth,
             DOC_ExtraDetectionsDetectionClasses(stop_depth))
        .def("get_stop_depth",
             &ExtraDetectionsDetectionClasses::get_stop_depth,
             DOC_ExtraDetectionsDetectionClasses(stop_depth))
        .def("set_qf_threshold_100",
             &ExtraDetectionsDetectionClasses::set_qf_threshold_100,
             DOC_ExtraDetectionsDetectionClasses(qf_threshold_100))
        .def("get_qf_threshold_100",
             &ExtraDetectionsDetectionClasses::get_qf_threshold_100,
             DOC_ExtraDetectionsDetectionClasses(qf_threshold_100))
        .def("set_bs_threshold",
             &ExtraDetectionsDetectionClasses::set_bs_threshold,
             DOC_ExtraDetectionsDetectionClasses(bs_threshold))
        .def("get_bs_threshold",
             &ExtraDetectionsDetectionClasses::get_bs_threshold,
             DOC_ExtraDetectionsDetectionClasses(bs_threshold))
        .def("set_snr_threshold",
             &ExtraDetectionsDetectionClasses::set_snr_threshold,
             DOC_ExtraDetectionsDetectionClasses(snr_threshold))
        .def("get_snr_threshold",
             &ExtraDetectionsDetectionClasses::get_snr_threshold,
             DOC_ExtraDetectionsDetectionClasses(snr_threshold))
        .def("set_alarm_threshold",
             &ExtraDetectionsDetectionClasses::set_alarm_threshold,
             DOC_ExtraDetectionsDetectionClasses(alarm_threshold))
        .def("get_alarm_threshold",
             &ExtraDetectionsDetectionClasses::get_alarm_threshold,
             DOC_ExtraDetectionsDetectionClasses(alarm_threshold))
        .def("set_number_of_extra_detections",
             &ExtraDetectionsDetectionClasses::set_number_of_extra_detections,
             DOC_ExtraDetectionsDetectionClasses(number_of_extra_detections))
        .def("get_number_of_extra_detections",
             &ExtraDetectionsDetectionClasses::get_number_of_extra_detections,
             DOC_ExtraDetectionsDetectionClasses(number_of_extra_detections))
        .def("set_show_class",
             &ExtraDetectionsDetectionClasses::set_show_class,
             DOC_ExtraDetectionsDetectionClasses(show_class))
        .def("get_show_class",
             &ExtraDetectionsDetectionClasses::get_show_class,
             DOC_ExtraDetectionsDetectionClasses(show_class))
        .def("set_alarm_flag_1",
             &ExtraDetectionsDetectionClasses::set_alarm_flag_1,
             DOC_ExtraDetectionsDetectionClasses(alarm_flag_1))
        .def("get_alarm_flag_1",
             &ExtraDetectionsDetectionClasses::get_alarm_flag_1,
             DOC_ExtraDetectionsDetectionClasses(alarm_flag_1))

        // --- processed member access ---
        .def("get_qf_threshold",
             &ExtraDetectionsDetectionClasses::get_qf_threshold,
             DOC_ExtraDetectionsDetectionClasses(get_qf_threshold))

        // ----- operators -----
        .def("__eq__",
             &ExtraDetectionsDetectionClasses::operator==,
             DOC_ExtraDetectionsDetectionClasses(operator_eq),
             nb::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(ExtraDetectionsDetectionClasses)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(ExtraDetectionsDetectionClasses)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}