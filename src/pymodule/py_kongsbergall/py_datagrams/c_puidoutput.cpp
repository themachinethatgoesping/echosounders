// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>


#include "../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/puidoutput.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::PUIDOutput;

#define DOC_PUIDOutput(ARG)                                                                        \
    DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, PUIDOutput, ARG)

void init_c_puidoutput(pybind11::module& m)
{
    py::classh<PUIDOutput, datagrams::KongsbergAllDatagram>(
        m, "PUIDOutput", DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, PUIDOutput))
        .def(py::init<>(), DOC_PUIDOutput(PUIDOutput))

        // --- convenient data access ---
        .def("set_byte_order_flag",
             &PUIDOutput::set_byte_order_flag,
             DOC_PUIDOutput(byte_order_flag))
        .def("get_byte_order_flag",
             &PUIDOutput::get_byte_order_flag,
             DOC_PUIDOutput(byte_order_flag))
        .def("set_system_serial_number",
             &PUIDOutput::set_system_serial_number,
             DOC_PUIDOutput(system_serial_number))
        .def("get_system_serial_number",
             &PUIDOutput::get_system_serial_number,
             DOC_PUIDOutput(system_serial_number))
        .def("set_udp_port_no_1", &PUIDOutput::set_udp_port_no_1, DOC_PUIDOutput(udp_port_no_1))
        .def("get_udp_port_no_1", &PUIDOutput::get_udp_port_no_1, DOC_PUIDOutput(udp_port_no_1))
        .def("set_udp_port_no_2", &PUIDOutput::set_udp_port_no_2, DOC_PUIDOutput(udp_port_no_2))
        .def("get_udp_port_no_2", &PUIDOutput::get_udp_port_no_2, DOC_PUIDOutput(udp_port_no_2))
        .def("set_udp_port_no_3", &PUIDOutput::set_udp_port_no_3, DOC_PUIDOutput(udp_port_no_3))
        .def("get_udp_port_no_3", &PUIDOutput::get_udp_port_no_3, DOC_PUIDOutput(udp_port_no_3))
        .def("set_udp_port_no_4", &PUIDOutput::set_udp_port_no_4, DOC_PUIDOutput(udp_port_no_4))
        .def("get_udp_port_no_4", &PUIDOutput::get_udp_port_no_4, DOC_PUIDOutput(udp_port_no_4))
        .def("set_system_descriptor",
             &PUIDOutput::set_system_descriptor,
             DOC_PUIDOutput(system_descriptor))
        .def("get_system_descriptor",
             &PUIDOutput::get_system_descriptor,
             DOC_PUIDOutput(system_descriptor))
        .def("set_pu_software_version",
             &PUIDOutput::set_pu_software_version,
             DOC_PUIDOutput(pu_software_version))
        .def("get_pu_software_version",
             &PUIDOutput::get_pu_software_version,
             DOC_PUIDOutput(pu_software_version))
        .def("set_bsp_software_date",
             &PUIDOutput::set_bsp_software_date,
             DOC_PUIDOutput(bsp_software_date))
        .def("get_bsp_software_date",
             &PUIDOutput::get_bsp_software_date,
             DOC_PUIDOutput(bsp_software_date))
        .def("set_sonar_transceiver_1_software_version",
             &PUIDOutput::set_sonar_transceiver_1_software_version,
             DOC_PUIDOutput(sonar_transceiver_1_software_version))
        .def("get_sonar_transceiver_1_software_version",
             &PUIDOutput::get_sonar_transceiver_1_software_version,
             DOC_PUIDOutput(sonar_transceiver_1_software_version))
        .def("set_sonar_transceiver_2_software_version",
             &PUIDOutput::set_sonar_transceiver_2_software_version,
             DOC_PUIDOutput(sonar_transceiver_2_software_version))
        .def("get_sonar_transceiver_2_software_version",
             &PUIDOutput::get_sonar_transceiver_2_software_version,
             DOC_PUIDOutput(sonar_transceiver_2_software_version))
        .def("set_host_ip_address",
             &PUIDOutput::set_host_ip_address,
             DOC_PUIDOutput(host_ip_address))
        .def("get_host_ip_address",
             &PUIDOutput::get_host_ip_address,
             DOC_PUIDOutput(host_ip_address))
        .def("set_tx_opening_angle",
             &PUIDOutput::set_tx_opening_angle,
             DOC_PUIDOutput(tx_opening_angle))
        .def("get_tx_opening_angle",
             &PUIDOutput::get_tx_opening_angle,
             DOC_PUIDOutput(tx_opening_angle))
        .def("set_rx_opening_angle",
             &PUIDOutput::set_rx_opening_angle,
             DOC_PUIDOutput(rx_opening_angle))
        .def("get_rx_opening_angle",
             &PUIDOutput::get_rx_opening_angle,
             DOC_PUIDOutput(rx_opening_angle))
        .def("set_spare", &PUIDOutput::set_spare, DOC_PUIDOutput(spare))
        .def("get_spare", &PUIDOutput::get_spare, DOC_PUIDOutput(spare))

        // --- processed member access ---
        .def("get_host_ip_address_as_string",
             &PUIDOutput::get_host_ip_address_as_string,
             DOC_PUIDOutput(get_host_ip_address_as_string))
        .def("get_cpu_configuration",
             &PUIDOutput::get_cpu_configuration,
             DOC_PUIDOutput(get_cpu_configuration))
        .def("get_has_dual_head", &PUIDOutput::get_has_dual_head, DOC_PUIDOutput(get_has_dual_head))
        .def("get_has_dual_swath",
             &PUIDOutput::get_has_dual_swath,
             DOC_PUIDOutput(get_has_dual_swath))
        .def("get_has_bsp67B", &PUIDOutput::get_has_bsp67B, DOC_PUIDOutput(get_has_bsp67B))
        .def("get_has_cbmf", &PUIDOutput::get_has_cbmf, DOC_PUIDOutput(get_has_cbmf))
        .def("get_has_ptp_support",
             &PUIDOutput::get_has_ptp_support,
             DOC_PUIDOutput(get_has_ptp_support))
        .def("get_has_deep_water_sonar_head",
             &PUIDOutput::get_has_deep_water_sonar_head,
             DOC_PUIDOutput(get_has_deep_water_sonar_head))
        .def("get_has_shallow_water_sonar_head",
             &PUIDOutput::get_has_shallow_water_sonar_head,
             DOC_PUIDOutput(get_has_shallow_water_sonar_head))
        .def("get_has_extra_detections_support",
             &PUIDOutput::get_has_extra_detections_support,
             DOC_PUIDOutput(get_has_extra_detections_support))
        .def("get_has_rs422_support",
             &PUIDOutput::get_has_rs422_support,
             DOC_PUIDOutput(get_has_rs422_support))
        .def("get_which_em2040", &PUIDOutput::get_which_em2040, DOC_PUIDOutput(get_which_em2040))
        .def("get_which_em710", &PUIDOutput::get_which_em710, DOC_PUIDOutput(get_which_em710))
        .def("get_which_old_sounder",
             &PUIDOutput::get_which_old_sounder,
             DOC_PUIDOutput(get_which_old_sounder))

        // --- checksum access ---
        .def("get_etx", &PUIDOutput::get_etx, DOC_PUIDOutput(etx))
        .def("set_etx", &PUIDOutput::set_etx, DOC_PUIDOutput(etx))
        .def("get_checksum", &PUIDOutput::get_checksum, DOC_PUIDOutput(checksum))
        .def("set_checksum", &PUIDOutput::set_checksum, DOC_PUIDOutput(checksum))

        // ----- operators -----
        .def("__eq__", &PUIDOutput::operator==, DOC_PUIDOutput(operator_eq), py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(PUIDOutput)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(PUIDOutput)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(PUIDOutput)
        // end LinearInterpolator
        ;
}
}
}
}
}
}