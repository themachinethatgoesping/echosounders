// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/substructures/rawrangeandanglebeam.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {
namespace py_substructures {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::substructures::RawRangeAndAngleBeam;

#define DOC_RawRangeAndAngleBeam(ARG)                                                              \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kongsbergall,                                                                                    \
        datagrams,                                                                                 \
        substructures,                                                                             \
        RawRangeAndAngleBeam,                                                                      \
        ARG)

void init_c_rawrangeandanglebeam(pybind11::module& m)
{

    py::class_<RawRangeAndAngleBeam>(m,
                                     "RawRangeAndAngleBeam",
                                     DOC(themachinethatgoesping,
                                         echosounders,
                                         kongsbergall,
                                         datagrams,
                                         substructures,
                                         RawRangeAndAngleBeam))
        .def(py::init<>(), DOC_RawRangeAndAngleBeam(RawRangeAndAngleBeam))

        // --- convenient data access ---
        .def("set_beam_crosstrack_angle",
             &RawRangeAndAngleBeam::set_beam_crosstrack_angle,
             DOC_RawRangeAndAngleBeam(beam_crosstrack_angle))
        .def("get_beam_crosstrack_angle",
             &RawRangeAndAngleBeam::get_beam_crosstrack_angle,
             DOC_RawRangeAndAngleBeam(beam_crosstrack_angle))
        .def("set_transmit_sector_number",
             &RawRangeAndAngleBeam::set_transmit_sector_number,
             DOC_RawRangeAndAngleBeam(transmit_sector_number))
        .def("get_transmit_sector_number",
             &RawRangeAndAngleBeam::get_transmit_sector_number,
             DOC_RawRangeAndAngleBeam(transmit_sector_number))
        .def("set_detection_info",
             &RawRangeAndAngleBeam::set_detection_info,
             DOC_RawRangeAndAngleBeam(detection_info))
        .def("get_detection_info",
             &RawRangeAndAngleBeam::get_detection_info,
             DOC_RawRangeAndAngleBeam(detection_info))
        .def("set_detection_window_length_in_samples",
             &RawRangeAndAngleBeam::set_detection_window_length_in_samples,
             DOC_RawRangeAndAngleBeam(detection_window_length_in_samples))
        .def("get_detection_window_length_in_samples",
             &RawRangeAndAngleBeam::get_detection_window_length_in_samples,
             DOC_RawRangeAndAngleBeam(detection_window_length_in_samples))
        .def("set_quality_factor",
             &RawRangeAndAngleBeam::set_quality_factor,
             DOC_RawRangeAndAngleBeam(quality_factor))
        .def("get_quality_factor",
             &RawRangeAndAngleBeam::get_quality_factor,
             DOC_RawRangeAndAngleBeam(quality_factor))
        .def("set_d_corr", &RawRangeAndAngleBeam::set_d_corr, DOC_RawRangeAndAngleBeam(d_corr))
        .def("get_d_corr", &RawRangeAndAngleBeam::get_d_corr, DOC_RawRangeAndAngleBeam(d_corr))
        .def("set_two_way_travel_time",
             &RawRangeAndAngleBeam::set_two_way_travel_time,
             DOC_RawRangeAndAngleBeam(two_way_travel_time))
        .def("get_two_way_travel_time",
             &RawRangeAndAngleBeam::get_two_way_travel_time,
             DOC_RawRangeAndAngleBeam(two_way_travel_time))
        .def("set_reflectivity",
             &RawRangeAndAngleBeam::set_reflectivity,
             DOC_RawRangeAndAngleBeam(reflectivity))
        .def("get_reflectivity",
             &RawRangeAndAngleBeam::get_reflectivity,
             DOC_RawRangeAndAngleBeam(reflectivity))
        .def("set_realtime_cleaning_info",
             &RawRangeAndAngleBeam::set_realtime_cleaning_info,
             DOC_RawRangeAndAngleBeam(realtime_cleaning_info))
        .def("get_realtime_cleaning_info",
             &RawRangeAndAngleBeam::get_realtime_cleaning_info,
             DOC_RawRangeAndAngleBeam(realtime_cleaning_info))
        .def("set_spare", &RawRangeAndAngleBeam::set_spare, DOC_RawRangeAndAngleBeam(spare))
        .def("get_spare", &RawRangeAndAngleBeam::get_spare, DOC_RawRangeAndAngleBeam(spare))

        // --- processed member access ---
        .def("get_beam_crosstrack_angle_in_degrees",
             &RawRangeAndAngleBeam::get_beam_crosstrack_angle_in_degrees,
             DOC_RawRangeAndAngleBeam(get_beam_crosstrack_angle_in_degrees))
        .def("get_reflectivity_in_db",
             &RawRangeAndAngleBeam::get_reflectivity_in_db,
             DOC_RawRangeAndAngleBeam(get_reflectivity_in_db))
        .def("get_detection_is_valid",
             &RawRangeAndAngleBeam::get_detection_is_valid,
             DOC_RawRangeAndAngleBeam(get_detection_is_valid))
        .def("get_detection_type",
             &RawRangeAndAngleBeam::get_detection_type,
             DOC_RawRangeAndAngleBeam(get_detection_type))

        // ----- operators -----
        .def("__eq__",
             &RawRangeAndAngleBeam::operator==,
             DOC_RawRangeAndAngleBeam(operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(RawRangeAndAngleBeam)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(RawRangeAndAngleBeam)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}