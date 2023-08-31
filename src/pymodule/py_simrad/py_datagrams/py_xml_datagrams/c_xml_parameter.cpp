// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0



#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "module.hpp"
#include <themachinethatgoesping/echosounders/simrad/datagrams/xml_datagrams/xml_parameter.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_datagrams {
namespace py_datagrams_xml {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simrad;
using datagrams::xml_datagrams::XML_Parameter;

void init_c_xml_parameter(pybind11::module& m)
{
    py::class_<XML_Parameter>(
        m,
        "XML_Parameter",
        DOC(themachinethatgoesping, echosounders, simrad, datagrams, xml_datagrams, XML_Parameter))
        .def(py::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 xml_datagrams,
                 XML_Parameter,
                 XML_Parameter))

        // ----- attributes -----
        .def_readwrite("Channels",
                       &XML_Parameter::Channels,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Parameter,
                           Channels))

        // ----- methods -----
        .def("parsed_completely",
             &XML_Parameter::parsed_completely,
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 xml_datagrams,
                 XML_Parameter,
                 parsed_completely))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(XML_Parameter)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(XML_Parameter)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(XML_Parameter)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}