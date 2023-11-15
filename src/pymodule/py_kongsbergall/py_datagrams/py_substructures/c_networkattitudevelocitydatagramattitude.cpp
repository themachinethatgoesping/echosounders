// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/substructures/networkattitudevelocitydatagramattitude.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {
namespace py_substructures {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::substructures::NetworkAttitudeVelocityDatagramAttitude;

#define DOC_NetworkAttitudeVelocityDatagramAttitude(ARG)                                           \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kongsbergall,                                                                                    \
        datagrams,                                                                                 \
        substructures,                                                                             \
        NetworkAttitudeVelocityDatagramAttitude,                                                   \
        ARG)

void init_c_networkattitudevelocitydatagramattitude(pybind11::module& m)
{

    py::class_<NetworkAttitudeVelocityDatagramAttitude>(
        m,
        "NetworkAttitudeVelocityDatagramAttitude",
        DOC(themachinethatgoesping,
            echosounders,
            kongsbergall,
            datagrams,
            substructures,
            NetworkAttitudeVelocityDatagramAttitude))
        .def(py::init<>(),
             DOC_NetworkAttitudeVelocityDatagramAttitude(NetworkAttitudeVelocityDatagramAttitude))
        // --- convenient data access ---
        .def("set_time",
             &NetworkAttitudeVelocityDatagramAttitude::set_time,
             DOC_NetworkAttitudeVelocityDatagramAttitude(time))
        .def("get_time",
             &NetworkAttitudeVelocityDatagramAttitude::get_time,
             DOC_NetworkAttitudeVelocityDatagramAttitude(time))
        .def("set_roll",
             &NetworkAttitudeVelocityDatagramAttitude::set_roll,
             DOC_NetworkAttitudeVelocityDatagramAttitude(roll))
        .def("get_roll",
             &NetworkAttitudeVelocityDatagramAttitude::get_roll,
             DOC_NetworkAttitudeVelocityDatagramAttitude(roll))
        .def("set_pitch",
             &NetworkAttitudeVelocityDatagramAttitude::set_pitch,
             DOC_NetworkAttitudeVelocityDatagramAttitude(pitch))
        .def("get_pitch",
             &NetworkAttitudeVelocityDatagramAttitude::get_pitch,
             DOC_NetworkAttitudeVelocityDatagramAttitude(pitch))
        .def("set_heave",
             &NetworkAttitudeVelocityDatagramAttitude::set_heave,
             DOC_NetworkAttitudeVelocityDatagramAttitude(heave))
        .def("get_heave",
             &NetworkAttitudeVelocityDatagramAttitude::get_heave,
             DOC_NetworkAttitudeVelocityDatagramAttitude(heave))
        .def("set_heading",
             &NetworkAttitudeVelocityDatagramAttitude::set_heading,
             DOC_NetworkAttitudeVelocityDatagramAttitude(heading))
        .def("get_heading",
             &NetworkAttitudeVelocityDatagramAttitude::get_heading,
             DOC_NetworkAttitudeVelocityDatagramAttitude(heading))
        .def("set_number_of_bytes_in_input_datagram",
             &NetworkAttitudeVelocityDatagramAttitude::set_number_of_bytes_in_input_datagram,
             DOC_NetworkAttitudeVelocityDatagramAttitude(number_of_bytes_in_input_datagram))
        .def("get_number_of_bytes_in_input_datagram",
             &NetworkAttitudeVelocityDatagramAttitude::get_number_of_bytes_in_input_datagram,
             DOC_NetworkAttitudeVelocityDatagramAttitude(number_of_bytes_in_input_datagram))
        .def("set_input_datagram",
             &NetworkAttitudeVelocityDatagramAttitude::set_input_datagram,
             DOC_NetworkAttitudeVelocityDatagramAttitude(input_datagram))
        .def(
            "get_input_datagram",
            [](const NetworkAttitudeVelocityDatagramAttitude& self) {
                return py::bytes(self.get_input_datagram()); // Return the data without transcoding
            },
            DOC_NetworkAttitudeVelocityDatagramAttitude(input_datagram))

        // --- processed member access ---
        .def("get_time_in_seconds",
             &NetworkAttitudeVelocityDatagramAttitude::get_time_in_seconds,
             DOC_NetworkAttitudeVelocityDatagramAttitude(get_time_in_seconds))
        .def("get_roll_in_degrees",
             &NetworkAttitudeVelocityDatagramAttitude::get_roll_in_degrees,
             DOC_NetworkAttitudeVelocityDatagramAttitude(get_roll_in_degrees))
        .def("get_pitch_in_degrees",
             &NetworkAttitudeVelocityDatagramAttitude::get_pitch_in_degrees,
             DOC_NetworkAttitudeVelocityDatagramAttitude(get_pitch_in_degrees))
        .def("get_heave_in_meters",
             &NetworkAttitudeVelocityDatagramAttitude::get_heave_in_meters,
             DOC_NetworkAttitudeVelocityDatagramAttitude(get_heave_in_meters))
        .def("get_heading_in_degrees",
             &NetworkAttitudeVelocityDatagramAttitude::get_heading_in_degrees,
             DOC_NetworkAttitudeVelocityDatagramAttitude(get_heading_in_degrees))

        // ----- operators -----
        .def("__eq__",
             &NetworkAttitudeVelocityDatagramAttitude::operator==,
             DOC_NetworkAttitudeVelocityDatagramAttitude(operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(NetworkAttitudeVelocityDatagramAttitude)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(NetworkAttitudeVelocityDatagramAttitude)
        // default binary conversion functions
        __PYCLASS_DEFAULT_BINARY__(NetworkAttitudeVelocityDatagramAttitude)
        // end
        ;
}
}
}
}
}
}
}