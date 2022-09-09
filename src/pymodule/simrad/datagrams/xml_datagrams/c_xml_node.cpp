// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>

#include "../../../../themachinethatgoesping/echosounders/simrad/datagrams/xml_datagrams/xml_node.hpp"
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
using datagrams::xml_datagrams::XML_Node;

void init_c_xml_datagram(pybind11::module& m)
{
    py::class_<XML_Node>(
        m,
        "XML_Node",
        DOC(themachinethatgoesping, echosounders, simrad, datagrams, xml_datagrams, XML_Node))
        .def(py::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 xml_datagrams,
                 XML_Node,
                 XML_Node))
        .def("get_children",
             &XML_Node::get_children,
             py::return_value_policy::reference_internal,
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 xml_datagrams,
                 XML_Node,
                 get_children))
        .def("get_attributes",
             &XML_Node::get_attributes,
             py::return_value_policy::reference_internal,
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 xml_datagrams,
                 XML_Node,
                 get_attributes))
        //    .def(py::init<std::string>(),
        //         DOC(themachinethatgoesping, echosounders, simrad, datagrams, xml_datagrams,
        //         XML_Node, XML_Datagram_2), py::arg("xml_content"))

        //    // ----- operators -----
        //    .def("__eq__",
        //         &XML_Node::operator==,
        //         DOC(themachinethatgoesping, echosounders, simrad, datagrams, xml_datagrams,
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