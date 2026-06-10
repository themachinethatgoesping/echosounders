// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <xtensor-python/nanobind/pytensor.hpp>

#include "../../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/substructures/attitudedatagramattitudescontainer.hpp"

#include "../module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {
namespace py_substructures {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::substructures::AttitudeDatagramAttitudesContainer;

void init_c_attitudedatagramattitudescontainer(nanobind::module_& m)
{
    nb::class_<AttitudeDatagramAttitudesContainer>(
        m,
        "AttitudeDatagramAttitudesContainer",
        "Container for AttitudeDatagramAttitude with vectorized tensor access")
        .def(nb::init<>())

        .def_prop_rw("attitudes",
                     &AttitudeDatagramAttitudesContainer::attitudes,
                     &AttitudeDatagramAttitudesContainer::set_attitudes,
                     nb::rv_policy::reference_internal)
        .def("get_attitudes", &AttitudeDatagramAttitudesContainer::get_attitudes)
        .def("set_attitudes",
             &AttitudeDatagramAttitudesContainer::set_attitudes,
             nb::arg("attitudes"))

        .def("get_time_tensor",
             &AttitudeDatagramAttitudesContainer::get_time_tensor,
             nb::arg("indices") = std::vector<uint32_t>{})
        .def("get_sensor_status_tensor",
             &AttitudeDatagramAttitudesContainer::get_sensor_status_tensor,
             nb::arg("indices") = std::vector<uint32_t>{})
        .def("get_roll_tensor",
             &AttitudeDatagramAttitudesContainer::get_roll_tensor,
             nb::arg("indices") = std::vector<uint32_t>{})
        .def("get_pitch_tensor",
             &AttitudeDatagramAttitudesContainer::get_pitch_tensor,
             nb::arg("indices") = std::vector<uint32_t>{})
        .def("get_heave_tensor",
             &AttitudeDatagramAttitudesContainer::get_heave_tensor,
             nb::arg("indices") = std::vector<uint32_t>{})
        .def("get_heading_tensor",
             &AttitudeDatagramAttitudesContainer::get_heading_tensor,
             nb::arg("indices") = std::vector<uint32_t>{})

        .def("get_time_in_seconds_tensor",
             &AttitudeDatagramAttitudesContainer::get_time_in_seconds_tensor,
             nb::arg("indices") = std::vector<uint32_t>{})
        .def("get_roll_in_degrees_tensor",
             &AttitudeDatagramAttitudesContainer::get_roll_in_degrees_tensor,
             nb::arg("indices") = std::vector<uint32_t>{})
        .def("get_pitch_in_degrees_tensor",
             &AttitudeDatagramAttitudesContainer::get_pitch_in_degrees_tensor,
             nb::arg("indices") = std::vector<uint32_t>{})
        .def("get_heave_in_meters_tensor",
             &AttitudeDatagramAttitudesContainer::get_heave_in_meters_tensor,
             nb::arg("indices") = std::vector<uint32_t>{})
        .def("get_heading_in_degrees_tensor",
             &AttitudeDatagramAttitudesContainer::get_heading_in_degrees_tensor,
             nb::arg("indices") = std::vector<uint32_t>{})

        .def("get_number_of_attitudes",
             &AttitudeDatagramAttitudesContainer::get_number_of_attitudes)

        .def("__eq__",
             &AttitudeDatagramAttitudesContainer::operator==,
             nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(AttitudeDatagramAttitudesContainer)
            __PYCLASS_DEFAULT_PRINTING__(AttitudeDatagramAttitudesContainer)
                ;
}

}
}
}
}
}
}
