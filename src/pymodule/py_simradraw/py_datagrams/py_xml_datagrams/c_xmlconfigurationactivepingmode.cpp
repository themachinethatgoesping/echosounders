// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "module.hpp"
#include <themachinethatgoesping/echosounders/simradraw/datagrams/xml_datagrams/xmlconfigurationactivepingmode.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_datagrams {
namespace py_datagrams_xml {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simradraw;
using datagrams::xml_datagrams::XMLConfigurationActivePingMode;

void init_c_XMLConfigurationActivePingMode(pybind11::module& m)
{
    py::class_<XMLConfigurationActivePingMode>(m,
                                               "XMLConfigurationActivePingMode",
                                               DOC(themachinethatgoesping,
                                                   echosounders,
                                                   simradraw,
                                                   datagrams,
                                                   xml_datagrams,
                                                   XMLConfigurationActivePingMode))
        .def(py::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 simradraw,
                 datagrams,
                 xml_datagrams,
                 XMLConfigurationActivePingMode,
                 XMLConfigurationActivePingMode))

        // ----- attributes -----
        .def_readwrite("Mode",
                       &XMLConfigurationActivePingMode::Mode,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationActivePingMode,
                           Mode))

        .def_readwrite("unknown_children",
                       &XMLConfigurationActivePingMode::unknown_children,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationActivePingMode,
                           unknown_children))
        .def_readwrite("unknown_attributes",
                       &XMLConfigurationActivePingMode::unknown_attributes,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XMLConfigurationActivePingMode,
                           unknown_attributes))

        // ----- methods -----
        .def("parsed_completely",
             &XMLConfigurationActivePingMode::parsed_completely,
             DOC(themachinethatgoesping,
                 echosounders,
                 simradraw,
                 datagrams,
                 xml_datagrams,
                 XMLConfigurationActivePingMode,
                 parsed_completely))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(XMLConfigurationActivePingMode)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(XMLConfigurationActivePingMode)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(XMLConfigurationActivePingMode)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}