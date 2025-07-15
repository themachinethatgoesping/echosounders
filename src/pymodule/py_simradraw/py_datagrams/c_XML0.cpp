// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/simradraw/datagrams/XML0.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simradraw;
using datagrams::SimradRawDatagram;
using datagrams::XML0;

#define DOC_XML0(arg) DOC(themachinethatgoesping, echosounders, simradraw, datagrams, XML0, arg)

void init_c_XML0(pybind11::module& m)
{
    py::class_<XML0, datagrams::SimradRawDatagram>(
        m, "XML0", DOC(themachinethatgoesping, echosounders, simradraw, datagrams, XML0))
        .def(py::init<>(), DOC_XML0(XML0))
        // --- convenient data access ---
        .def("set_xml_content",
             &XML0::set_xml_content,
             DOC_XML0(set_xml_content),
             py::arg("xml_content"))
        .def("get_xml_content", &XML0::get_xml_content, DOC_XML0(get_xml_content))
        .def("get_xml_datagram_type",
             &XML0::get_xml_datagram_type,
             DOC(themachinethatgoesping,
                 echosounders,
                 simradraw,
                 datagrams,
                 XML0,
                 get_xml_datagram_type))

        .def("raw", &XML0::raw, DOC_XML0(raw))

        .def("decode", &XML0::decode, DOC_XML0(decode))
        // --- convenient data access ---
        .def("get_xml_datagram_type",
             &XML0::get_xml_datagram_type,
             DOC(themachinethatgoesping,
                 echosounders,
                 simradraw,
                 datagrams,
                 XML0,
                 get_xml_datagram_type))

        // xml testing
        .def("test_xml",
             &XML0::test_xml,
             py::call_guard<py::scoped_ostream_redirect, py::scoped_ostream_redirect>(),
             DOC_XML0(test_xml))

        // --- raw data access ---
        .def("get_raw_xml_content", &XML0::get_xml_content, DOC_XML0(get_xml_content))
        .def("set_raw_xml_content", &XML0::set_xml_content, DOC_XML0(set_xml_content))

        // ----- operators -----
        .def("__eq__", &XML0::operator==, DOC_XML0(operator_eq), py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(XML0)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(XML0)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(XML0)
        // end LinearInterpolator
        ;
}
}
}
}
}
}