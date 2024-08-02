// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>
#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/xyzdatagram.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::XYZDatagram;

#define DOC_XYZDatagram(ARG)                                                                       \
    DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, XYZDatagram, ARG)

void init_c_xyzdatagram(pybind11::module& m)
{
    py::class_<XYZDatagram, datagrams::KongsbergAllDatagram>(
        m, "XYZDatagram", DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, XYZDatagram))
        .def(py::init<>(), DOC_XYZDatagram(XYZDatagram))

        // --- convenience functions ---
        .def("get_xyz",
             py::overload_cast<>(&XYZDatagram::get_xyz, py::const_),
             DOC_XYZDatagram(get_xyz))
        .def("get_xyz",
             py::overload_cast<const std::vector<uint32_t>&>(&XYZDatagram::get_xyz, py::const_),
             DOC_XYZDatagram(get_xyz_2),
             py::arg("beam_numbers"))

        // --- convenient data access ---
        .def("set_ping_counter", &XYZDatagram::set_ping_counter, DOC_XYZDatagram(ping_counter))
        .def("get_ping_counter", &XYZDatagram::get_ping_counter, DOC_XYZDatagram(ping_counter))
        .def("set_system_serial_number",
             &XYZDatagram::set_system_serial_number,
             DOC_XYZDatagram(system_serial_number))
        .def("get_system_serial_number",
             &XYZDatagram::get_system_serial_number,
             DOC_XYZDatagram(system_serial_number))
        .def("set_heading", &XYZDatagram::set_heading, DOC_XYZDatagram(heading))
        .def("get_heading", &XYZDatagram::get_heading, DOC_XYZDatagram(heading))
        .def("set_sound_speed", &XYZDatagram::set_sound_speed, DOC_XYZDatagram(sound_speed))
        .def("get_sound_speed", &XYZDatagram::get_sound_speed, DOC_XYZDatagram(sound_speed))
        .def("set_transmit_transducer_depth",
             &XYZDatagram::set_transmit_transducer_depth,
             DOC_XYZDatagram(transmit_transducer_depth))
        .def("get_transmit_transducer_depth",
             &XYZDatagram::get_transmit_transducer_depth,
             DOC_XYZDatagram(transmit_transducer_depth))
        .def("set_number_of_beams",
             &XYZDatagram::set_number_of_beams,
             DOC_XYZDatagram(number_of_beams))
        .def("get_number_of_beams",
             &XYZDatagram::get_number_of_beams,
             DOC_XYZDatagram(number_of_beams))
        .def("set_number_of_valid_detections",
             &XYZDatagram::set_number_of_valid_detections,
             DOC_XYZDatagram(number_of_valid_detections))
        .def("get_number_of_valid_detections",
             &XYZDatagram::get_number_of_valid_detections,
             DOC_XYZDatagram(number_of_valid_detections))
        .def("set_sampling_frequency",
             &XYZDatagram::set_sampling_frequency,
             DOC_XYZDatagram(sampling_frequency))
        .def("get_sampling_frequency",
             &XYZDatagram::get_sampling_frequency,
             DOC_XYZDatagram(sampling_frequency))
        .def("set_scanning_info", &XYZDatagram::set_scanning_info, DOC_XYZDatagram(scanning_info))
        .def("get_scanning_info", &XYZDatagram::get_scanning_info, DOC_XYZDatagram(scanning_info))

        // --- data structure access ---
        .def("get_beams",
             &XYZDatagram::get_beams,
             DOC_XYZDatagram(beams),
             py::return_value_policy::reference_internal)
        .def("set_beams", &XYZDatagram::set_beams, DOC_XYZDatagram(beams))
        .def("beams",
             &XYZDatagram::beams,
             DOC_XYZDatagram(beams),
             py::return_value_policy::reference_internal)

        // --- processed member access ---
        .def("get_heading_in_degrees",
             &XYZDatagram::get_heading_in_degrees,
             DOC_XYZDatagram(get_heading_in_degrees))
        .def("get_sound_speed_in_m_per_s",
             &XYZDatagram::get_sound_speed_in_m_per_s,
             DOC_XYZDatagram(get_sound_speed_in_m_per_s))

        // --- checksum access ---
        .def("get_spare_byte", &XYZDatagram::get_spare_byte, DOC_XYZDatagram(spare_byte))
        .def("set_spare_byte", &XYZDatagram::set_spare_byte, DOC_XYZDatagram(spare_byte))
        .def("get_spare_bytes", &XYZDatagram::get_spare_bytes, DOC_XYZDatagram(spare_bytes))
        .def("set_spare_bytes", &XYZDatagram::set_spare_bytes, DOC_XYZDatagram(spare_bytes))
        .def("get_etx", &XYZDatagram::get_etx, DOC_XYZDatagram(etx))
        .def("set_etx", &XYZDatagram::set_etx, DOC_XYZDatagram(etx))
        .def("get_checksum", &XYZDatagram::get_checksum, DOC_XYZDatagram(checksum))
        .def("set_checksum", &XYZDatagram::set_checksum, DOC_XYZDatagram(checksum))

        // ----- operators -----
        .def("__eq__", &XYZDatagram::operator==, DOC_XYZDatagram(operator_eq), py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(XYZDatagram)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(XYZDatagram)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(XYZDatagram)
        // end LinearInterpolator
        ;
}
}
}
}
}
}