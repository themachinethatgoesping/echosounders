// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>

#include "../../../../themachinethatgoesping/echosounders/simrad/datagrams/xml_datagrams/xml_configuration.hpp"
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
using datagrams::xml_datagrams::XML_Configuration;

void init_c_xml_configuration(pybind11::module& m)
{
    py::class_<XML_Configuration>(m,
                                      "XML_Configuration",
                                      DOC(themachinethatgoesping,
                                          echosounders,
                                          simrad,
                                          datagrams,
                                          xml_datagrams,
                                          XML_Configuration))
        .def(py::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 xml_datagrams,
                 XML_Configuration,
                 XML_Configuration))

        // ----- children -----
        .def_readwrite("ConfiguredSensors",
                       &XML_Configuration::ConfiguredSensors,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration,
                           ConfiguredSensors))
        .def_readwrite("Transducers",
                       &XML_Configuration::Transducers,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration,
                           Transducers))
        .def_readwrite("Transceivers",
                       &XML_Configuration::Transceivers,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration,
                           Transceivers))
        .def_readwrite("ActivePingMode",
                       &XML_Configuration::ActivePingMode,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration,
                           ActivePingMode))


        // ----- attributes (Header) -----
        .def_readwrite("FileFormatVersion",
                       &XML_Configuration::FileFormatVersion,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration,
                           FileFormatVersion))
        .def_readwrite("Version",
                       &XML_Configuration::Version,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration,
                           Version))
        .def_readwrite("TimeBias",
                       &XML_Configuration::TimeBias,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration,
                           TimeBias))
        .def_readwrite("ApplicationName",
                       &XML_Configuration::ApplicationName,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration,
                           ApplicationName))
        .def_readwrite("Copyright",
                       &XML_Configuration::Copyright,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration,
                           Copyright))
        

        // ----- methods -----
        .def("parsed_completely",
             &XML_Configuration::parsed_completely,
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 xml_datagrams,
                 XML_Configuration,
                 parsed_completely))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(XML_Configuration)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(XML_Configuration)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(XML_Configuration)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}