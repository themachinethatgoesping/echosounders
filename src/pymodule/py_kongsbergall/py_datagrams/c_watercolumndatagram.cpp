// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <memory>
#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>


#include <xtensor-python/pytensor.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // Numpy bindings

#include "../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/watercolumndatagram.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::WatercolumnDatagram;

#define DOC_WatercolumnDatagram(ARG)                                                               \
    DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, WatercolumnDatagram, ARG)

void init_c_watercolumndatagram(pybind11::module& m)
{
    py::classh<WatercolumnDatagram, datagrams::KongsbergAllDatagram>(
        m,
        "WatercolumnDatagram",
        DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, WatercolumnDatagram))
        .def(py::init<>(), DOC_WatercolumnDatagram(WatercolumnDatagram))
        // --- processed data access ---
        .def("get_samples", &WatercolumnDatagram::get_samples, DOC_WatercolumnDatagram(get_samples))

        // --- convenient data access ---
        .def("set_ping_counter",
             &WatercolumnDatagram::set_ping_counter,
             DOC_WatercolumnDatagram(ping_counter))
        .def("get_ping_counter",
             &WatercolumnDatagram::get_ping_counter,
             DOC_WatercolumnDatagram(ping_counter))
        .def("set_system_serial_number",
             &WatercolumnDatagram::set_system_serial_number,
             DOC_WatercolumnDatagram(system_serial_number))
        .def("get_system_serial_number",
             &WatercolumnDatagram::get_system_serial_number,
             DOC_WatercolumnDatagram(system_serial_number))
        .def("set_number_of_datagrams",
             &WatercolumnDatagram::set_number_of_datagrams,
             DOC_WatercolumnDatagram(number_of_datagrams))
        .def("get_number_of_datagrams",
             &WatercolumnDatagram::get_number_of_datagrams,
             DOC_WatercolumnDatagram(number_of_datagrams))
        .def("set_datagram_number",
             &WatercolumnDatagram::set_datagram_number,
             DOC_WatercolumnDatagram(datagram_number))
        .def("get_datagram_number",
             &WatercolumnDatagram::get_datagram_number,
             DOC_WatercolumnDatagram(datagram_number))
        .def("set_number_of_transmit_sectors",
             &WatercolumnDatagram::set_number_of_transmit_sectors,
             DOC_WatercolumnDatagram(number_of_transmit_sectors))
        .def("get_number_of_transmit_sectors",
             &WatercolumnDatagram::get_number_of_transmit_sectors,
             DOC_WatercolumnDatagram(number_of_transmit_sectors))
        .def("set_total_no_of_receive_beams",
             &WatercolumnDatagram::set_total_no_of_receive_beams,
             DOC_WatercolumnDatagram(total_no_of_receive_beams))
        .def("get_total_no_of_receive_beams",
             &WatercolumnDatagram::get_total_no_of_receive_beams,
             DOC_WatercolumnDatagram(total_no_of_receive_beams))
        .def("set_number_of_beams_in_datagram",
             &WatercolumnDatagram::set_number_of_beams_in_datagram,
             DOC_WatercolumnDatagram(number_of_beams_in_datagram))
        .def("get_number_of_beams_in_datagram",
             &WatercolumnDatagram::get_number_of_beams_in_datagram,
             DOC_WatercolumnDatagram(number_of_beams_in_datagram))
        .def("set_sound_speed",
             &WatercolumnDatagram::set_sound_speed,
             DOC_WatercolumnDatagram(sound_speed))
        .def("get_sound_speed",
             &WatercolumnDatagram::get_sound_speed,
             DOC_WatercolumnDatagram(sound_speed))
        .def("set_sampling_frequency",
             &WatercolumnDatagram::set_sampling_frequency,
             DOC_WatercolumnDatagram(sampling_frequency))
        .def("get_sampling_frequency",
             &WatercolumnDatagram::get_sampling_frequency,
             DOC_WatercolumnDatagram(sampling_frequency))
        .def("set_tx_time_heave",
             &WatercolumnDatagram::set_tx_time_heave,
             DOC_WatercolumnDatagram(tx_time_heave))
        .def("get_tx_time_heave",
             &WatercolumnDatagram::get_tx_time_heave,
             DOC_WatercolumnDatagram(tx_time_heave))
        .def("set_tvg_function_applied",
             &WatercolumnDatagram::set_tvg_function_applied,
             DOC_WatercolumnDatagram(tvg_function_applied))
        .def("get_tvg_function_applied",
             &WatercolumnDatagram::get_tvg_function_applied,
             DOC_WatercolumnDatagram(get_tvg_function_applied))
        .def("set_tvg_offset_in_db",
             &WatercolumnDatagram::set_tvg_offset_in_db,
             DOC_WatercolumnDatagram(tvg_offset_in_db))
        .def("get_tvg_offset_in_db",
             &WatercolumnDatagram::get_tvg_offset_in_db,
             DOC_WatercolumnDatagram(tvg_offset_in_db))
        .def("set_scanning_info",
             &WatercolumnDatagram::set_scanning_info,
             DOC_WatercolumnDatagram(scanning_info))
        .def("get_scanning_info",
             &WatercolumnDatagram::get_scanning_info,
             DOC_WatercolumnDatagram(scanning_info))
        .def("set_spare", &WatercolumnDatagram::set_spare, DOC_WatercolumnDatagram(spare))
        .def("get_spare", &WatercolumnDatagram::get_spare, DOC_WatercolumnDatagram(spare))

        // --- data structure access ---
        .def("get_beams",
             &WatercolumnDatagram::get_beams,
             DOC_WatercolumnDatagram(beams),
             py::return_value_policy::reference_internal)
        .def("set_beams", &WatercolumnDatagram::set_beams, DOC_WatercolumnDatagram(beams))
        .def("beams",
             &WatercolumnDatagram::beams,
             DOC_WatercolumnDatagram(beams),
             py::return_value_policy::reference_internal)

        .def("get_transmit_sectors",
             &WatercolumnDatagram::get_transmit_sectors,
             DOC_WatercolumnDatagram(transmit_sectors),
             py::return_value_policy::reference_internal)
        .def("set_transmit_sectors",
             &WatercolumnDatagram::set_transmit_sectors,
             DOC_WatercolumnDatagram(transmit_sectors))
        .def("transmit_sectors",
             &WatercolumnDatagram::transmit_sectors,
             DOC_WatercolumnDatagram(transmit_sectors),
             py::return_value_policy::reference_internal)

        // --- processed member access ---
        .def("get_sound_speed_m_s",
             &WatercolumnDatagram::get_sound_speed_m_s,
             DOC_WatercolumnDatagram(get_sound_speed_m_s))
        .def("get_sampling_frequency_in_hz",
             &WatercolumnDatagram::get_sampling_frequency_in_hz,
             DOC_WatercolumnDatagram(get_sampling_frequency_in_hz))
        .def("get_tx_time_heave_in_m",
             &WatercolumnDatagram::get_tx_time_heave_in_m,
             DOC_WatercolumnDatagram(get_tx_time_heave_in_m))

        // --- checksum access ---
        .def("get_etx", &WatercolumnDatagram::get_etx, DOC_WatercolumnDatagram(etx))
        .def("set_etx", &WatercolumnDatagram::set_etx, DOC_WatercolumnDatagram(etx))
        .def("get_checksum", &WatercolumnDatagram::get_checksum, DOC_WatercolumnDatagram(checksum))
        .def("set_checksum", &WatercolumnDatagram::set_checksum, DOC_WatercolumnDatagram(checksum))

        // ----- operators -----
        .def("__eq__",
             &WatercolumnDatagram::operator==,
             DOC_WatercolumnDatagram(operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(WatercolumnDatagram)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(WatercolumnDatagram)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(WatercolumnDatagram)
        // end LinearInterpolator
        ;
}
}
}
}
}
}