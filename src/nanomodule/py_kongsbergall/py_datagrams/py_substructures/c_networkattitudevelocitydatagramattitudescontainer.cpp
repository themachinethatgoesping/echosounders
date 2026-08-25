// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <xtensor-python/nanobind/pytensor.hpp>

#include "../../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/substructures/networkattitudevelocitydatagramattitudescontainer.hpp"

#include "../module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {
namespace py_substructures {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::substructures::NetworkAttitudeVelocityDatagramAttitudesContainer;

void init_c_networkattitudevelocitydatagramattitudescontainer(nanobind::module_& m)
{
    nb::class_<NetworkAttitudeVelocityDatagramAttitudesContainer>(
        m,
        "NetworkAttitudeVelocityDatagramAttitudesContainer",
        "Container for NetworkAttitudeVelocityDatagramAttitude with vectorized tensor access")
        .def(nb::init<>())

        .def_prop_rw("attitudes",
                     &NetworkAttitudeVelocityDatagramAttitudesContainer::attitudes,
                     &NetworkAttitudeVelocityDatagramAttitudesContainer::set_attitudes,
                     nb::rv_policy::reference_internal)
        .def("get_attitudes", &NetworkAttitudeVelocityDatagramAttitudesContainer::get_attitudes)
        .def("set_attitudes",
             &NetworkAttitudeVelocityDatagramAttitudesContainer::set_attitudes,
             nb::arg("attitudes"))
        .def("get_indices_sorted_by_time",
             &NetworkAttitudeVelocityDatagramAttitudesContainer::get_indices_sorted_by_time,
             nb::arg("indices") = std::vector<uint32_t>{})

        .def("get_time_tensor",
             &NetworkAttitudeVelocityDatagramAttitudesContainer::get_time_tensor,
             nb::arg("indices") = std::vector<uint32_t>{})
        .def("get_roll_tensor",
             &NetworkAttitudeVelocityDatagramAttitudesContainer::get_roll_tensor,
             nb::arg("indices") = std::vector<uint32_t>{})
        .def("get_pitch_tensor",
             &NetworkAttitudeVelocityDatagramAttitudesContainer::get_pitch_tensor,
             nb::arg("indices") = std::vector<uint32_t>{})
        .def("get_heave_tensor",
             &NetworkAttitudeVelocityDatagramAttitudesContainer::get_heave_tensor,
             nb::arg("indices") = std::vector<uint32_t>{})
        .def("get_heading_tensor",
             &NetworkAttitudeVelocityDatagramAttitudesContainer::get_heading_tensor,
             nb::arg("indices") = std::vector<uint32_t>{})
        .def("get_number_of_bytes_in_input_datagram_tensor",
             &NetworkAttitudeVelocityDatagramAttitudesContainer::
                 get_number_of_bytes_in_input_datagram_tensor,
             nb::arg("indices") = std::vector<uint32_t>{})

        .def("get_time_in_seconds_tensor",
             &NetworkAttitudeVelocityDatagramAttitudesContainer::get_time_in_seconds_tensor,
             nb::arg("indices") = std::vector<uint32_t>{})
        .def("get_roll_in_degrees_tensor",
             &NetworkAttitudeVelocityDatagramAttitudesContainer::get_roll_in_degrees_tensor,
             nb::arg("indices") = std::vector<uint32_t>{})
        .def("get_pitch_in_degrees_tensor",
             &NetworkAttitudeVelocityDatagramAttitudesContainer::get_pitch_in_degrees_tensor,
             nb::arg("indices") = std::vector<uint32_t>{})
        .def("get_heave_in_meters_tensor",
             &NetworkAttitudeVelocityDatagramAttitudesContainer::get_heave_in_meters_tensor,
             nb::arg("indices") = std::vector<uint32_t>{})
        .def("get_heading_in_degrees_tensor",
             &NetworkAttitudeVelocityDatagramAttitudesContainer::get_heading_in_degrees_tensor,
             nb::arg("indices") = std::vector<uint32_t>{})

        .def("get_number_of_attitudes",
             &NetworkAttitudeVelocityDatagramAttitudesContainer::get_number_of_attitudes)

        .def("__eq__",
             &NetworkAttitudeVelocityDatagramAttitudesContainer::operator==,
             nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(NetworkAttitudeVelocityDatagramAttitudesContainer)
            __PYCLASS_DEFAULT_PRINTING__(NetworkAttitudeVelocityDatagramAttitudesContainer)
                ;
}

}
}
}
}
}
}
