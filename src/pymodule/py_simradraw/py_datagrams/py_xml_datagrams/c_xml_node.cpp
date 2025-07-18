// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "module.hpp"
#include <themachinethatgoesping/echosounders/simradraw/datagrams/xml_datagrams/xml_node.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_datagrams {
namespace py_datagrams_xml {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simradraw;
using datagrams::xml_datagrams::XML_Node;

void init_c_xml_datagram(pybind11::module& m)
{
    py::class_<XML_Node>(
        m,
        "XML_Node",
        DOC(themachinethatgoesping, echosounders, simradraw, datagrams, xml_datagrams, XML_Node))
        .def(py::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 simradraw,
                 datagrams,
                 xml_datagrams,
                 XML_Node,
                 XML_Node))
        .def(
            "name",
            [](const XML_Node& self) { return self.name(); },
            py::return_value_policy::reference_internal,
            DOC(themachinethatgoesping,
                echosounders,
                simradraw,
                datagrams,
                xml_datagrams,
                XML_Node,
                name))
        .def(
            "children",
            [](const XML_Node& self) { return self.children(); },
            py::return_value_policy::reference_internal,
            DOC(themachinethatgoesping,
                echosounders,
                simradraw,
                datagrams,
                xml_datagrams,
                XML_Node,
                children))
        .def(
            "children",
            [](const XML_Node& self, const std::string& key) { return self.children(key); },
            py::return_value_policy::reference_internal,
            DOC(themachinethatgoesping,
                echosounders,
                simradraw,
                datagrams,
                xml_datagrams,
                XML_Node,
                children_2),
            py::arg("key"))
        .def("first_child",
             &XML_Node::first_child,
             py::return_value_policy::reference_internal,
             DOC(themachinethatgoesping,
                 echosounders,
                 simradraw,
                 datagrams,
                 xml_datagrams,
                 XML_Node,
                 first_child))
        .def(
            "attributes",
            [](const XML_Node& self) { return self.attributes(); },
            py::return_value_policy::reference_internal,
            DOC(themachinethatgoesping,
                echosounders,
                simradraw,
                datagrams,
                xml_datagrams,
                XML_Node,
                attributes))
        .def(
            "attributes",
            [](const XML_Node& self, const std::string& key) { return self.attributes(key); },
            py::return_value_policy::reference_internal,
            DOC(themachinethatgoesping,
                echosounders,
                simradraw,
                datagrams,
                xml_datagrams,
                XML_Node,
                attributes_2),
            py::arg("key"))
        //    .def(py::init<std::string>(),
        //         DOC(themachinethatgoesping, echosounders, simradraw, datagrams, xml_datagrams,
        //         XML_Node, XML_Datagram_2), py::arg("xml_content"))

        //    // ----- operators -----
        //    .def("__eq__",
        //         &XML_Node::operator==,
        //         DOC(themachinethatgoesping, echosounders, simradraw, datagrams, xml_datagrams,
        //         XML_Node, operator_eq), py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(XML_Node)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(XML_Node)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(XML_Node)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}