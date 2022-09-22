// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>

#include "../../../../themachinethatgoesping/echosounders/simrad/datagrams/xml_datagrams/xml_configuration_activepingmode.hpp"
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
using datagrams::xml_datagrams::XML_Configuration_ActivePingMode;

void init_c_xml_configuration_activepingmode(pybind11::module& m)
{
    py::class_<XML_Configuration_ActivePingMode>(m,
                                                 "XML_Configuration_ActivePingMode",
                                                 DOC(themachinethatgoesping,
                                                     echosounders,
                                                     simrad,
                                                     datagrams,
                                                     xml_datagrams,
                                                     XML_Configuration_ActivePingMode))
        .def(py::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 xml_datagrams,
                 XML_Configuration_ActivePingMode,
                 XML_Configuration_ActivePingMode))

        // ----- attributes -----
        .def_readwrite("Mode",
                       &XML_Configuration_ActivePingMode::Mode,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_ActivePingMode,
                           Mode))

        .def_readwrite("unknown_children",
                       &XML_Configuration_ActivePingMode::unknown_children,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_ActivePingMode,
                           unknown_children))
        .def_readwrite("unknown_attributes",
                       &XML_Configuration_ActivePingMode::unknown_attributes,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_ActivePingMode,
                           unknown_attributes))

        // ----- methods -----
        .def("parsed_completely",
             &XML_Configuration_ActivePingMode::parsed_completely,
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 xml_datagrams,
                 XML_Configuration_ActivePingMode,
                 parsed_completely))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(XML_Configuration_ActivePingMode)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(XML_Configuration_ActivePingMode)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(XML_Configuration_ActivePingMode)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}