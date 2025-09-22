// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>


#include "../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/singlebeamechosounderdepth.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::SingleBeamEchoSounderDepth;

#define DOC_SingleBeamEchoSounderDepth(ARG)                                                        \
    DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, SingleBeamEchoSounderDepth, ARG)

void init_c_singlebeamechosounderdepth(pybind11::module& m)
{
    py::classh<SingleBeamEchoSounderDepth, datagrams::KongsbergAllDatagram>(
        m,
        "SingleBeamEchoSounderDepth",
        DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, SingleBeamEchoSounderDepth))
        .def(py::init<>(), DOC_SingleBeamEchoSounderDepth(SingleBeamEchoSounderDepth))

        // --- convenient data access ---
        .def("set_echo_sounder_counter",
             &SingleBeamEchoSounderDepth::set_echo_sounder_counter,
             DOC_SingleBeamEchoSounderDepth(echo_sounder_counter))
        .def("get_echo_sounder_counter",
             &SingleBeamEchoSounderDepth::get_echo_sounder_counter,
             DOC_SingleBeamEchoSounderDepth(echo_sounder_counter))
        .def("set_system_serial_number",
             &SingleBeamEchoSounderDepth::set_system_serial_number,
             DOC_SingleBeamEchoSounderDepth(system_serial_number))
        .def("get_system_serial_number",
             &SingleBeamEchoSounderDepth::get_system_serial_number,
             DOC_SingleBeamEchoSounderDepth(system_serial_number))
        .def("set_input_date",
             &SingleBeamEchoSounderDepth::set_input_date,
             DOC_SingleBeamEchoSounderDepth(input_date))
        .def("get_input_date",
             &SingleBeamEchoSounderDepth::get_input_date,
             DOC_SingleBeamEchoSounderDepth(input_date))
        .def("set_input_time_since_midnight",
             &SingleBeamEchoSounderDepth::set_input_time_since_midnight,
             DOC_SingleBeamEchoSounderDepth(input_time_since_midnight))
        .def("get_input_time_since_midnight",
             &SingleBeamEchoSounderDepth::get_input_time_since_midnight,
             DOC_SingleBeamEchoSounderDepth(input_time_since_midnight))
        .def("set_echo_sounder_depth",
             &SingleBeamEchoSounderDepth::set_echo_sounder_depth,
             DOC_SingleBeamEchoSounderDepth(echo_sounder_depth))
        .def("get_echo_sounder_depth",
             &SingleBeamEchoSounderDepth::get_echo_sounder_depth,
             DOC_SingleBeamEchoSounderDepth(echo_sounder_depth))
        .def("set_source_identifier",
             &SingleBeamEchoSounderDepth::set_source_identifier,
             DOC_SingleBeamEchoSounderDepth(source_identifier))
        .def("get_source_identifier",
             &SingleBeamEchoSounderDepth::get_source_identifier,
             DOC_SingleBeamEchoSounderDepth(source_identifier))

        // --- processed member access ---
        .def("get_input_timestamp",
             &SingleBeamEchoSounderDepth::get_input_timestamp,
             DOC_SingleBeamEchoSounderDepth(get_input_timestamp))
        .def("get_input_date_string",
             &SingleBeamEchoSounderDepth::get_input_date_string,
             DOC_SingleBeamEchoSounderDepth(get_input_date_string))
        .def("get_echo_sounder_depth_in_meters",
             &SingleBeamEchoSounderDepth::get_echo_sounder_depth_in_meters,
             DOC_SingleBeamEchoSounderDepth(get_echo_sounder_depth_in_meters))

        // --- checksum access ---
        .def("get_etx", &SingleBeamEchoSounderDepth::get_etx, DOC_SingleBeamEchoSounderDepth(etx))
        .def("set_etx", &SingleBeamEchoSounderDepth::set_etx, DOC_SingleBeamEchoSounderDepth(etx))
        .def("get_checksum",
             &SingleBeamEchoSounderDepth::get_checksum,
             DOC_SingleBeamEchoSounderDepth(checksum))
        .def("set_checksum",
             &SingleBeamEchoSounderDepth::set_checksum,
             DOC_SingleBeamEchoSounderDepth(checksum))

        // ----- operators -----
        .def("__eq__",
             &SingleBeamEchoSounderDepth::operator==,
             DOC_SingleBeamEchoSounderDepth(operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(SingleBeamEchoSounderDepth)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(SingleBeamEchoSounderDepth)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(SingleBeamEchoSounderDepth)
        // end LinearInterpolator
        ;
}
}
}
}
}
}