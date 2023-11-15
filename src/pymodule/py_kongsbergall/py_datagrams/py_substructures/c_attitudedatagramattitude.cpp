// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/substructures/attitudedatagramattitude.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {
namespace py_substructures {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::substructures::AttitudeDatagramAttitude;

#define DOC_AttitudeDatagramAttitude(ARG)                                                          \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kongsbergall,                                                                                    \
        datagrams,                                                                                 \
        substructures,                                                                             \
        AttitudeDatagramAttitude,                                                                  \
        ARG)

void init_c_attitudedatagramattitude(pybind11::module& m)
{

    py::class_<AttitudeDatagramAttitude>(m,
                                         "AttitudeDatagramAttitude",
                                         DOC(themachinethatgoesping,
                                             echosounders,
                                             kongsbergall,
                                             datagrams,
                                             substructures,
                                             AttitudeDatagramAttitude))
        .def(py::init<>(), DOC_AttitudeDatagramAttitude(AttitudeDatagramAttitude))
        // --- convenient data access ---
        .def("set_time", &AttitudeDatagramAttitude::set_time, DOC_AttitudeDatagramAttitude(time))
        .def("get_time", &AttitudeDatagramAttitude::get_time, DOC_AttitudeDatagramAttitude(time))
        .def("set_sensor_status",
             &AttitudeDatagramAttitude::set_sensor_status,
             DOC_AttitudeDatagramAttitude(sensor_status))
        .def("get_sensor_status",
             &AttitudeDatagramAttitude::get_sensor_status,
             DOC_AttitudeDatagramAttitude(sensor_status))
        .def("set_roll", &AttitudeDatagramAttitude::set_roll, DOC_AttitudeDatagramAttitude(roll))
        .def("get_roll", &AttitudeDatagramAttitude::get_roll, DOC_AttitudeDatagramAttitude(roll))
        .def("set_pitch", &AttitudeDatagramAttitude::set_pitch, DOC_AttitudeDatagramAttitude(pitch))
        .def("get_pitch", &AttitudeDatagramAttitude::get_pitch, DOC_AttitudeDatagramAttitude(pitch))
        .def("set_heave", &AttitudeDatagramAttitude::set_heave, DOC_AttitudeDatagramAttitude(heave))
        .def("get_heave", &AttitudeDatagramAttitude::get_heave, DOC_AttitudeDatagramAttitude(heave))
        .def("set_heading",
             &AttitudeDatagramAttitude::set_heading,
             DOC_AttitudeDatagramAttitude(heading))
        .def("get_heading",
             &AttitudeDatagramAttitude::get_heading,
             DOC_AttitudeDatagramAttitude(heading))

        // --- processed member access ---
        .def("get_time_in_seconds",
             &AttitudeDatagramAttitude::get_time_in_seconds,
             DOC_AttitudeDatagramAttitude(get_time_in_seconds))
        .def("get_roll_in_degrees",
             &AttitudeDatagramAttitude::get_roll_in_degrees,
             DOC_AttitudeDatagramAttitude(get_roll_in_degrees))
        .def("get_pitch_in_degrees",
             &AttitudeDatagramAttitude::get_pitch_in_degrees,
             DOC_AttitudeDatagramAttitude(get_pitch_in_degrees))
        .def("get_heave_in_meters",
             &AttitudeDatagramAttitude::get_heave_in_meters,
             DOC_AttitudeDatagramAttitude(get_heave_in_meters))
        .def("get_heading_in_degrees",
             &AttitudeDatagramAttitude::get_heading_in_degrees,
             DOC_AttitudeDatagramAttitude(get_heading_in_degrees))

        // ----- operators -----
        .def("__eq__",
             &AttitudeDatagramAttitude::operator==,
             DOC_AttitudeDatagramAttitude(operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(AttitudeDatagramAttitude)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(AttitudeDatagramAttitude)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}