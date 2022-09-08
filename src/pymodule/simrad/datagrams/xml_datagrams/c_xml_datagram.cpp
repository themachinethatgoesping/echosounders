// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>

#include "../../../../themachinethatgoesping/echosounders/simrad/datagrams/xml_datagrams/xml_datagram.hpp"
#include "../../../docstrings.hpp"
#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_datagrams {
namespace py_datagrams_xml {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simrad;
using datagrams::xml_datagrams::XML_Datagram;

void init_c_xml_datagram(pybind11::module& m)
{
    py::class_<XML_Datagram>(
        m, "XML_Datagram", DOC(themachinethatgoesping, echosounders, simrad, datagrams, xml_datagrams, XML_Datagram))
        .def(py::init<>(),
             DOC(themachinethatgoesping, echosounders, simrad, datagrams, xml_datagrams, XML_Datagram, XML_Datagram))
        .def(py::init<std::string>(),
             DOC(themachinethatgoesping, echosounders, simrad, datagrams, xml_datagrams, XML_Datagram, XML_Datagram_2),
             py::arg("xml_content"))
        // --- convenient data access ---
        .def(
            "get_xml_datagram_type",
            &XML_Datagram::get_xml_datagram_type,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, xml_datagrams, XML_Datagram, get_xml_datagram_type))

        // xml testing
        .def("test_xml",
             &XML_Datagram::test_xml,
             py::call_guard<py::scoped_ostream_redirect, py::scoped_estream_redirect>(),
             DOC(themachinethatgoesping, echosounders, simrad, datagrams, xml_datagrams, XML_Datagram, test_xml))

        // --- raw data access ---
        .def_property(
            "_raw_xml_content",
            &XML_Datagram::get_xml_content,
            &XML_Datagram::set_xml_content,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, xml_datagrams, XML_Datagram, xml_content))

        // ----- operators -----
        .def("__eq__",
             &XML_Datagram::operator==,
             DOC(themachinethatgoesping, echosounders, simrad, datagrams, xml_datagrams, XML_Datagram, operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(XML_Datagram)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(XML_Datagram)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(XML_Datagram)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}