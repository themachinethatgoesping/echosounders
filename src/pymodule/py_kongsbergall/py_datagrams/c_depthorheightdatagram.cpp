// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>
#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/depthorheightdatagram.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::DepthOrHeightDatagram;

#define DOC_DepthOrHeightDatagram(ARG)                                                             \
    DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, DepthOrHeightDatagram, ARG)

void init_c_depthorheightdatagram(pybind11::module& m)
{
    py::class_<DepthOrHeightDatagram, datagrams::KongsbergAllDatagram>(
        m,
        "DepthOrHeightDatagram",
        DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, DepthOrHeightDatagram))
        .def(py::init<>(), DOC_DepthOrHeightDatagram(DepthOrHeightDatagram))

        // --- convenient data access ---
        .def("set_height_counter",
             &DepthOrHeightDatagram::set_height_counter,
             DOC_DepthOrHeightDatagram(height_counter))
        .def("get_height_counter",
             &DepthOrHeightDatagram::get_height_counter,
             DOC_DepthOrHeightDatagram(height_counter))
        .def("set_system_serial_number",
             &DepthOrHeightDatagram::set_system_serial_number,
             DOC_DepthOrHeightDatagram(system_serial_number))
        .def("get_system_serial_number",
             &DepthOrHeightDatagram::get_system_serial_number,
             DOC_DepthOrHeightDatagram(system_serial_number))
        .def("set_height", &DepthOrHeightDatagram::set_height, DOC_DepthOrHeightDatagram(height))
        .def("get_height", &DepthOrHeightDatagram::get_height, DOC_DepthOrHeightDatagram(height))
        .def("set_height_type",
             &DepthOrHeightDatagram::set_height_type,
             DOC_DepthOrHeightDatagram(height_type))
        .def("get_height_type",
             &DepthOrHeightDatagram::get_height_type,
             DOC_DepthOrHeightDatagram(height_type))

        // --- processed member access ---
        .def("get_height_in_meters",
             &DepthOrHeightDatagram::get_height_in_meters,
             DOC_DepthOrHeightDatagram(get_height_in_meters))
        .def("get_height_type_explained",
             &DepthOrHeightDatagram::get_height_type_explained,
             DOC_DepthOrHeightDatagram(get_height_type_explained))

        // --- checksum access ---
        .def("get_etx", &DepthOrHeightDatagram::get_etx, DOC_DepthOrHeightDatagram(etx))
        .def("set_etx", &DepthOrHeightDatagram::set_etx, DOC_DepthOrHeightDatagram(etx))
        .def("get_checksum",
             &DepthOrHeightDatagram::get_checksum,
             DOC_DepthOrHeightDatagram(checksum))
        .def("set_checksum",
             &DepthOrHeightDatagram::set_checksum,
             DOC_DepthOrHeightDatagram(checksum))

        // ----- operators -----
        .def("__eq__",
             &DepthOrHeightDatagram::operator==,
             DOC_DepthOrHeightDatagram(operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(DepthOrHeightDatagram)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(DepthOrHeightDatagram)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(DepthOrHeightDatagram)
        // end LinearInterpolator
        ;
}
}
}
}
}
}