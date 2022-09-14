// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>

#include "../../../themachinethatgoesping/echosounders/simrad/datagrams/ek80_XML0.hpp"
#include "../../docstrings.hpp"
#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simrad;
using datagrams::EK60_Datagram;
using datagrams::EK80_XML0;

void init_c_ek80_XML0(pybind11::module& m)
{
    py::class_<EK80_XML0, datagrams::EK60_Datagram>(
        m, "EK80_XML0", DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK80_XML0))
        .def(py::init<>(),
             DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK80_XML0, EK80_XML0))
        // --- convenient data access ---
        .def(
            "set_xml_content",
            &EK80_XML0::set_xml_content,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK80_XML0, set_xml_content),
            py::arg("xml_content"))
        .def(
            "get_xml_content",
            &EK80_XML0::get_xml_content,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK80_XML0, get_xml_content))
        .def(
            "get_xml_datagram_type",
            &EK80_XML0::get_xml_datagram_type,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK80_XML0, get_xml_datagram_type))

        .def("raw",
             &EK80_XML0::raw,
             DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK80_XML0, raw))

        .def("decode",
             &EK80_XML0::decode,
             DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK80_XML0, decode))
        // --- convenient data access ---
        .def(
            "get_xml_datagram_type",
            &EK80_XML0::get_xml_datagram_type,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK80_XML0, get_xml_datagram_type))

        // xml testing
        .def("test_xml",
             &EK80_XML0::test_xml,
             py::call_guard<py::scoped_ostream_redirect, py::scoped_ostream_redirect>(),
             DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK80_XML0, test_xml))

        // --- raw data access ---
        .def_property(
            "_raw_xml_content",
            &EK80_XML0::get_xml_content,
            &EK80_XML0::set_xml_content,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK80_XML0, xml_content))

        // --- raw data access ---
        .def_property(
            "_raw_xml_content",
            &EK80_XML0::get_xml_content,
            &EK80_XML0::set_xml_content,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK80_XML0, get_xml_content))

        // ----- operators -----
        .def("__eq__",
             &EK80_XML0::operator==,
             DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK80_XML0, operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(EK80_XML0)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(EK80_XML0)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(EK80_XML0)
        // end LinearInterpolator
        ;
}
}
}
}
}
}