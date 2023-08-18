// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <memory>
#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>
#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include <xtensor-python/pyarray.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // Numpy bindings

#include "../../../themachinethatgoesping/echosounders/em3000/datagrams/watercolumndatagram.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_em3000 {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::em3000;
using datagrams::WaterColumnDatagram;

#define DOC_WaterColumnDatagram(ARG)                                                               \
    DOC(themachinethatgoesping, echosounders, em3000, datagrams, WaterColumnDatagram, ARG)

void init_c_watercolumndatagram(pybind11::module& m)
{
    py::class_<WaterColumnDatagram,
               datagrams::EM3000Datagram>(
        m,
        "WaterColumnDatagram",
        DOC(themachinethatgoesping, echosounders, em3000, datagrams, WaterColumnDatagram))
        .def(py::init<>(), DOC_WaterColumnDatagram(WaterColumnDatagram))
        // --- processed data access ---
        .def("get_samples", &WaterColumnDatagram::get_samples, DOC_WaterColumnDatagram(get_samples))

        // --- convenient data access ---
        .def("set_ping_counter",
             &WaterColumnDatagram::set_ping_counter,
             DOC_WaterColumnDatagram(ping_counter))
        .def("get_ping_counter",
             &WaterColumnDatagram::get_ping_counter,
             DOC_WaterColumnDatagram(ping_counter))
        .def("set_system_serial_number",
             &WaterColumnDatagram::set_system_serial_number,
             DOC_WaterColumnDatagram(system_serial_number))
        .def("get_system_serial_number",
             &WaterColumnDatagram::get_system_serial_number,
             DOC_WaterColumnDatagram(system_serial_number))
        .def("set_number_of_datagrams",
             &WaterColumnDatagram::set_number_of_datagrams,
             DOC_WaterColumnDatagram(number_of_datagrams))
        .def("get_number_of_datagrams",
             &WaterColumnDatagram::get_number_of_datagrams,
             DOC_WaterColumnDatagram(number_of_datagrams))
        .def("set_datagram_number",
             &WaterColumnDatagram::set_datagram_number,
             DOC_WaterColumnDatagram(datagram_number))
        .def("get_datagram_number",
             &WaterColumnDatagram::get_datagram_number,
             DOC_WaterColumnDatagram(datagram_number))
        .def("set_number_of_transmit_sectors",
             &WaterColumnDatagram::set_number_of_transmit_sectors,
             DOC_WaterColumnDatagram(number_of_transmit_sectors))
        .def("get_number_of_transmit_sectors",
             &WaterColumnDatagram::get_number_of_transmit_sectors,
             DOC_WaterColumnDatagram(number_of_transmit_sectors))
        .def("set_total_no_of_receive_beams",
             &WaterColumnDatagram::set_total_no_of_receive_beams,
             DOC_WaterColumnDatagram(total_no_of_receive_beams))
        .def("get_total_no_of_receive_beams",
             &WaterColumnDatagram::get_total_no_of_receive_beams,
             DOC_WaterColumnDatagram(total_no_of_receive_beams))
        .def("set_number_of_beams_in_datagram",
             &WaterColumnDatagram::set_number_of_beams_in_datagram,
             DOC_WaterColumnDatagram(number_of_beams_in_datagram))
        .def("get_number_of_beams_in_datagram",
             &WaterColumnDatagram::get_number_of_beams_in_datagram,
             DOC_WaterColumnDatagram(number_of_beams_in_datagram))
        .def("set_sound_speed",
             &WaterColumnDatagram::set_sound_speed,
             DOC_WaterColumnDatagram(sound_speed))
        .def("get_sound_speed",
             &WaterColumnDatagram::get_sound_speed,
             DOC_WaterColumnDatagram(sound_speed))
        .def("set_sampling_frequency",
             &WaterColumnDatagram::set_sampling_frequency,
             DOC_WaterColumnDatagram(sampling_frequency))
        .def("get_sampling_frequency",
             &WaterColumnDatagram::get_sampling_frequency,
             DOC_WaterColumnDatagram(sampling_frequency))
        .def("set_tx_time_heave",
             &WaterColumnDatagram::set_tx_time_heave,
             DOC_WaterColumnDatagram(tx_time_heave))
        .def("get_tx_time_heave",
             &WaterColumnDatagram::get_tx_time_heave,
             DOC_WaterColumnDatagram(tx_time_heave))
        .def("set_tvg_function_applied",
             &WaterColumnDatagram::set_tvg_function_applied,
             DOC_WaterColumnDatagram(tvg_function_applied))
        .def("get_tvg_function_applied",
             &WaterColumnDatagram::get_tvg_function_applied,
             DOC_WaterColumnDatagram(tvg_function_applied))
        .def("set_tvg_offset_in_db",
             &WaterColumnDatagram::set_tvg_offset_in_db,
             DOC_WaterColumnDatagram(tvg_offset_in_db))
        .def("get_tvg_offset_in_db",
             &WaterColumnDatagram::get_tvg_offset_in_db,
             DOC_WaterColumnDatagram(tvg_offset_in_db))
        .def("set_scanning_info",
             &WaterColumnDatagram::set_scanning_info,
             DOC_WaterColumnDatagram(scanning_info))
        .def("get_scanning_info",
             &WaterColumnDatagram::get_scanning_info,
             DOC_WaterColumnDatagram(scanning_info))
        .def("set_spare", &WaterColumnDatagram::set_spare, DOC_WaterColumnDatagram(spare))
        .def("get_spare", &WaterColumnDatagram::get_spare, DOC_WaterColumnDatagram(spare))

        // --- data structure access ---
        .def("get_beams",
             &WaterColumnDatagram::get_beams,
             DOC_WaterColumnDatagram(beams),
             py::return_value_policy::reference_internal)
        .def("set_beams", &WaterColumnDatagram::set_beams, DOC_WaterColumnDatagram(beams))
        .def("beams",
             &WaterColumnDatagram::beams,
             DOC_WaterColumnDatagram(beams),
             py::return_value_policy::reference_internal)

        .def("get_transmit_sectors",
             &WaterColumnDatagram::get_transmit_sectors,
             DOC_WaterColumnDatagram(transmit_sectors),
             py::return_value_policy::reference_internal)
        .def("set_transmit_sectors",
             &WaterColumnDatagram::set_transmit_sectors,
             DOC_WaterColumnDatagram(transmit_sectors))
        .def("transmit_sectors",
             &WaterColumnDatagram::transmit_sectors,
             DOC_WaterColumnDatagram(transmit_sectors),
             py::return_value_policy::reference_internal)

        // --- processed member access ---
        .def("get_sound_speed_m_s",
             &WaterColumnDatagram::get_sound_speed_m_s,
             DOC_WaterColumnDatagram(get_sound_speed_m_s))
        .def("get_sampling_frequency_in_hz",
             &WaterColumnDatagram::get_sampling_frequency_in_hz,
             DOC_WaterColumnDatagram(get_sampling_frequency_in_hz))
        .def("get_tx_time_heave_in_m",
             &WaterColumnDatagram::get_tx_time_heave_in_m,
             DOC_WaterColumnDatagram(get_tx_time_heave_in_m))

        // --- checksum access ---
        .def("get_etx", &WaterColumnDatagram::get_etx, DOC_WaterColumnDatagram(etx))
        .def("set_etx", &WaterColumnDatagram::set_etx, DOC_WaterColumnDatagram(etx))
        .def("get_checksum", &WaterColumnDatagram::get_checksum, DOC_WaterColumnDatagram(checksum))
        .def("set_checksum", &WaterColumnDatagram::set_checksum, DOC_WaterColumnDatagram(checksum))

        // ----- operators -----
        .def("__eq__",
             &WaterColumnDatagram::operator==,
             DOC_WaterColumnDatagram(operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(WaterColumnDatagram)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(WaterColumnDatagram)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(WaterColumnDatagram)
        // end LinearInterpolator
        ;
}
}
}
}
}
}