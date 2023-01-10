// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>
#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include "../../../../themachinethatgoesping/echosounders/em3000/datagrams/substructures/xyzdatagrambeam.hpp"

#include "../../../docstrings_moreargs.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_em3000 {
namespace py_datagrams {
namespace py_substructures {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::em3000;
using datagrams::substructures::XYZDatagramBeam;

#define DOC_t_DetectionType(ARG)                                                                   \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        em3000,                                                                                    \
        datagrams,                                                                                 \
        substructures,                                                                             \
        XYZDatagramBeam,                                                                           \
        t_DetectionType,                                                                           \
        ARG)

#define DOC_XYZDatagramBeam(ARG)                                                                   \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        em3000,                                                                                    \
        datagrams,                                                                                 \
        substructures,                                                                             \
        XYZDatagramBeam,                                                                           \
        ARG)

void init_c_xyzdatagrambeam(pybind11::module& m)
{
    auto tmp_enum = py::enum_<XYZDatagramBeam::t_DetectionType>(
                        m, "XYZDatagramBeam_t_DetectionType", DOC_XYZDatagramBeam(t_DetectionType))
                        // Multibeam data
                        .value("AmplitudeDetect",
                               XYZDatagramBeam::t_DetectionType::AmplitudeDetect,
                               DOC_t_DetectionType(AmplitudeDetect))
                        .value("PhaseDetect",
                               XYZDatagramBeam::t_DetectionType::PhaseDetect,
                               DOC_t_DetectionType(PhaseDetect))
                        .value("InvalidNormalDetection",
                               XYZDatagramBeam::t_DetectionType::InvalidNormalDetection,
                               DOC_t_DetectionType(InvalidNormalDetection))
                        .value("Interpolated",
                               XYZDatagramBeam::t_DetectionType::Interpolated,
                               DOC_t_DetectionType(Interpolated))
                        .value("Estimated",
                               XYZDatagramBeam::t_DetectionType::Estimated,
                               DOC_t_DetectionType(Estimated))
                        .value("Rejected",
                               XYZDatagramBeam::t_DetectionType::Rejected,
                               DOC_t_DetectionType(Rejected))
                        .value("NoDetection",
                               XYZDatagramBeam::t_DetectionType::NoDetection,
                               DOC_t_DetectionType(NoDetection))
                        .value("Invalid",
                               XYZDatagramBeam::t_DetectionType::Invalid,
                               DOC_t_DetectionType(Invalid))
                        .export_values()

        //
        ;

    tools::pybind_helper::add_string_to_enum_conversion<XYZDatagramBeam::t_DetectionType>(tmp_enum);

    py::class_<XYZDatagramBeam>(m,
                                "XYZDatagramBeam",
                                DOC(themachinethatgoesping,
                                    echosounders,
                                    em3000,
                                    datagrams,
                                    substructures,
                                    XYZDatagramBeam))
        .def(py::init<>(), DOC_XYZDatagramBeam(XYZDatagramBeam))
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
        .def("set_detection_information",
             &XYZDatagramBeam::set_detection_information,
             DOC_XYZDatagramBeam(detection_information))
        .def("get_detection_information",
             &XYZDatagramBeam::get_detection_information,
             DOC_XYZDatagramBeam(detection_information))
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
             py::arg("other"))
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