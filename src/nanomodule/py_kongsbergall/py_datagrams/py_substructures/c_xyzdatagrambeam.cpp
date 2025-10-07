// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "../../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/substructures/xyzdatagrambeam.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {
namespace py_substructures {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::substructures::XYZDatagramBeam;

#define DOC_XYZDatagramBeam(ARG)                                                                   \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kongsbergall,                                                                                    \
        datagrams,                                                                                 \
        substructures,                                                                             \
        XYZDatagramBeam,                                                                           \
        ARG)

void init_c_xyzdatagrambeam(nanobind::module_& m)
{

     nb::class_<XYZDatagramBeam>(m,
                                "XYZDatagramBeam",
                                DOC(themachinethatgoesping,
                                    echosounders,
                                    kongsbergall,
                                    datagrams,
                                    substructures,
                                    XYZDatagramBeam))
     .def(nb::init<>(), DOC_XYZDatagramBeam(XYZDatagramBeam))
        // --- convenient data access ---
        .def("set_depth", &XYZDatagramBeam::set_depth, DOC_XYZDatagramBeam(depth))
        .def("get_depth", &XYZDatagramBeam::get_depth, DOC_XYZDatagramBeam(depth))
        .def("set_acrosstrack_distance",
             &XYZDatagramBeam::set_acrosstrack_distance,
             DOC_XYZDatagramBeam(acrosstrack_distance))
        .def("get_acrosstrack_distance",
             &XYZDatagramBeam::get_acrosstrack_distance,
             DOC_XYZDatagramBeam(acrosstrack_distance))
        .def("set_alongtrack_distance",
             &XYZDatagramBeam::set_alongtrack_distance,
             DOC_XYZDatagramBeam(alongtrack_distance))
        .def("get_alongtrack_distance",
             &XYZDatagramBeam::get_alongtrack_distance,
             DOC_XYZDatagramBeam(alongtrack_distance))
        .def("set_detection_window_length",
             &XYZDatagramBeam::set_detection_window_length,
             DOC_XYZDatagramBeam(detection_window_length))
        .def("get_detection_window_length",
             &XYZDatagramBeam::get_detection_window_length,
             DOC_XYZDatagramBeam(detection_window_length))
        .def("set_quality_factor",
             &XYZDatagramBeam::set_quality_factor,
             DOC_XYZDatagramBeam(quality_factor))
        .def("get_quality_factor",
             &XYZDatagramBeam::get_quality_factor,
             DOC_XYZDatagramBeam(quality_factor))
        .def("set_beam_incidence_angle_adjustment",
             &XYZDatagramBeam::set_beam_incidence_angle_adjustment,
             DOC_XYZDatagramBeam(beam_incidence_angle_adjustment))
        .def("get_beam_incidence_angle_adjustment",
             &XYZDatagramBeam::get_beam_incidence_angle_adjustment,
             DOC_XYZDatagramBeam(beam_incidence_angle_adjustment))
        .def("set_detection_info",
             &XYZDatagramBeam::set_detection_info,
             DOC_XYZDatagramBeam(detection_info))
        .def("get_detection_info",
             &XYZDatagramBeam::get_detection_info,
             DOC_XYZDatagramBeam(detection_info))
        .def("set_realtime_cleaning_information",
             &XYZDatagramBeam::set_realtime_cleaning_information,
             DOC_XYZDatagramBeam(realtime_cleaning_information))
        .def("get_realtime_cleaning_information",
             &XYZDatagramBeam::get_realtime_cleaning_information,
             DOC_XYZDatagramBeam(realtime_cleaning_information))
        .def("set_reflectivity",
             &XYZDatagramBeam::set_reflectivity,
             DOC_XYZDatagramBeam(reflectivity))
        .def("get_reflectivity",
             &XYZDatagramBeam::get_reflectivity,
             DOC_XYZDatagramBeam(reflectivity))

        // --- processed member access ---
        .def("get_backscatter",
             &XYZDatagramBeam::get_backscatter,
             DOC_XYZDatagramBeam(get_backscatter))
        .def("get_detection_is_valid",
             &XYZDatagramBeam::get_detection_is_valid,
             DOC_XYZDatagramBeam(get_detection_is_valid))
        .def("get_detection_type",
             &XYZDatagramBeam::get_detection_type,
             DOC_XYZDatagramBeam(get_detection_type))
        .def("get_backscatter_is_compensated",
             &XYZDatagramBeam::get_backscatter_is_compensated,
             DOC_XYZDatagramBeam(get_backscatter_is_compensated))
        .def("get_beam_incidence_angle_adjustment_in_degrees",
             &XYZDatagramBeam::get_beam_incidence_angle_adjustment_in_degrees,
             DOC_XYZDatagramBeam(get_beam_incidence_angle_adjustment_in_degrees))

        // ----- operators -----
        .def("__eq__",
             &XYZDatagramBeam::operator==,
             DOC_XYZDatagramBeam(operator_eq),
             nb::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(XYZDatagramBeam)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(XYZDatagramBeam)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}