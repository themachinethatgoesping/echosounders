// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/substructs/mrzrxinfo.hpp>

#include "../module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::substructs::MRZRxInfo;

#define DOC_MRZRxInfo(ARG)                                                                           \
    DOC(themachinethatgoesping, echosounders, kmall, datagrams, substructs, MRZRxInfo, ARG)

void init_c_mrzrxinfo(nanobind::module_& m)
{
    nb::class_<MRZRxInfo>(m, "MRZRxInfo", DOC_MRZRxInfo(MRZRxInfo))
        .def(nb::init<>(), DOC_MRZRxInfo(MRZRxInfo))
        .def("get_bytes_content",
             &MRZRxInfo::get_bytes_content,
             DOC_MRZRxInfo(get_bytes_content))
        .def("set_bytes_content",
             &MRZRxInfo::set_bytes_content,
             DOC_MRZRxInfo(set_bytes_content),
             nb::arg("val"))
        .def("get_number_of_soundings_max_main",
             &MRZRxInfo::get_number_of_soundings_max_main,
             DOC_MRZRxInfo(get_number_of_soundings_max_main))
        .def("set_number_of_soundings_max_main",
             &MRZRxInfo::set_number_of_soundings_max_main,
             DOC_MRZRxInfo(set_number_of_soundings_max_main),
             nb::arg("val"))
        .def("get_number_of_soundings_valid_main",
             &MRZRxInfo::get_number_of_soundings_valid_main,
             DOC_MRZRxInfo(get_number_of_soundings_valid_main))
        .def("set_number_of_soundings_valid_main",
             &MRZRxInfo::set_number_of_soundings_valid_main,
             DOC_MRZRxInfo(set_number_of_soundings_valid_main),
             nb::arg("val"))
        .def("get_number_of_bytes_per_sounding",
             &MRZRxInfo::get_number_of_bytes_per_sounding,
             DOC_MRZRxInfo(get_number_of_bytes_per_sounding))
        .def("set_number_of_bytes_per_sounding",
             &MRZRxInfo::set_number_of_bytes_per_sounding,
             DOC_MRZRxInfo(set_number_of_bytes_per_sounding),
             nb::arg("val"))
        .def("get_wc_sample_rate",
             &MRZRxInfo::get_wc_sample_rate,
             DOC_MRZRxInfo(get_wc_sample_rate))
        .def("set_wc_sample_rate",
             &MRZRxInfo::set_wc_sample_rate,
             DOC_MRZRxInfo(set_wc_sample_rate),
             nb::arg("val"))
        .def("get_seabed_image_sample_rate",
             &MRZRxInfo::get_seabed_image_sample_rate,
             DOC_MRZRxInfo(get_seabed_image_sample_rate))
        .def("set_seabed_image_sample_rate",
             &MRZRxInfo::set_seabed_image_sample_rate,
             DOC_MRZRxInfo(set_seabed_image_sample_rate),
             nb::arg("val"))
        .def("get_bs_normal_db",
             &MRZRxInfo::get_bs_normal_db,
             DOC_MRZRxInfo(get_bs_normal_db))
        .def("set_bs_normal_db",
             &MRZRxInfo::set_bs_normal_db,
             DOC_MRZRxInfo(set_bs_normal_db),
             nb::arg("val"))
        .def("get_bs_oblique_db",
             &MRZRxInfo::get_bs_oblique_db,
             DOC_MRZRxInfo(get_bs_oblique_db))
        .def("set_bs_oblique_db",
             &MRZRxInfo::set_bs_oblique_db,
             DOC_MRZRxInfo(set_bs_oblique_db),
             nb::arg("val"))
        .def("get_extra_detection_alarm_flag",
             &MRZRxInfo::get_extra_detection_alarm_flag,
             DOC_MRZRxInfo(get_extra_detection_alarm_flag))
        .def("set_extra_detection_alarm_flag",
             &MRZRxInfo::set_extra_detection_alarm_flag,
             DOC_MRZRxInfo(set_extra_detection_alarm_flag),
             nb::arg("val"))
        .def("get_number_of_extra_detections",
             &MRZRxInfo::get_number_of_extra_detections,
             DOC_MRZRxInfo(get_number_of_extra_detections))
        .def("set_number_of_extra_detections",
             &MRZRxInfo::set_number_of_extra_detections,
             DOC_MRZRxInfo(set_number_of_extra_detections),
             nb::arg("val"))
        .def("get_number_of_extra_detection_classes",
             &MRZRxInfo::get_number_of_extra_detection_classes,
             DOC_MRZRxInfo(get_number_of_extra_detection_classes))
        .def("set_number_of_extra_detection_classes",
             &MRZRxInfo::set_number_of_extra_detection_classes,
             DOC_MRZRxInfo(set_number_of_extra_detection_classes),
             nb::arg("val"))
        .def("get_number_of_bytes_per_class",
             &MRZRxInfo::get_number_of_bytes_per_class,
             DOC_MRZRxInfo(get_number_of_bytes_per_class))
        .def("set_number_of_bytes_per_class",
             &MRZRxInfo::set_number_of_bytes_per_class,
             DOC_MRZRxInfo(set_number_of_bytes_per_class),
             nb::arg("val"))

        // ----- operators -----
        .def("__eq__",
             &MRZRxInfo::operator==,
             DOC_MRZRxInfo(operator_eq),
             nb::arg("other"))
        // ----- pybind macros -----
        __PYCLASS_DEFAULT_COPY__(MRZRxInfo)
        __PYCLASS_DEFAULT_PRINTING__(MRZRxInfo)
        ;
}

}
}
}
}
}
