// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/map.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "module.hpp"
#include <themachinethatgoesping/echosounders/simradraw/datagrams/xml_datagrams/xml_initialparameter.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_datagrams {
namespace py_datagrams_xml {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::simradraw;
using datagrams::xml_datagrams::XML_InitialParameter;

void init_c_xml_initialparameter(nanobind::module_& m)
{
    nb::class_<XML_InitialParameter>(m,
                                     "XML_InitialParameter",
                                     DOC(themachinethatgoesping,
                                         echosounders,
                                         simradraw,
                                         datagrams,
                                         xml_datagrams,
                                         XML_InitialParameter))
        .def(nb::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 simradraw,
                 datagrams,
                 xml_datagrams,
                 XML_InitialParameter,
                 XML_InitialParameter))

        // ----- attributes -----
        .def_rw("Channels",
                       &XML_InitialParameter::Channels,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_InitialParameter,
                           Channels))

        // ----- methods -----
        .def("parsed_completely",
             &XML_InitialParameter::parsed_completely,
             DOC(themachinethatgoesping,
                 echosounders,
                 simradraw,
                 datagrams,
                 xml_datagrams,
                 XML_InitialParameter,
                 parsed_completely))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(XML_InitialParameter)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(XML_InitialParameter)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(XML_InitialParameter)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}