// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>

#include "../../../../themachinethatgoesping/echosounders/simrad/datagrams/xml_datagrams/xml_configuration_sensor.hpp"
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
using datagrams::xml_datagrams::XML_Configuration_Sensor;

void init_c_xml_configuration_sensor(pybind11::module& m)
{
    py::class_<XML_Configuration_Sensor>(m,
                                      "XML_Configuration_Sensor",
                                      DOC(themachinethatgoesping,
                                          echosounders,
                                          simrad,
                                          datagrams,
                                          xml_datagrams,
                                          XML_Configuration_Sensor))
        .def(py::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 xml_datagrams,
                 XML_Configuration_Sensor,
                 XML_Configuration_Sensor))

        // ----- children -----
        .def_readwrite("Telegrams",
                       &XML_Configuration_Sensor::Telegrams,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Sensor,
                           Telegrams))


        // ----- attributes -----
        .def_readwrite("Timeout",
                       &XML_Configuration_Sensor::Timeout,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Sensor,
                           Timeout))
        .def_readwrite("Unique",
                       &XML_Configuration_Sensor::Unique,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Sensor,
                           Unique))
        .def_readwrite("AngleZ",
                       &XML_Configuration_Sensor::AngleZ,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Sensor,
                           AngleZ))
        .def_readwrite("AngleY",
                       &XML_Configuration_Sensor::AngleY,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Sensor,
                           AngleY))
        .def_readwrite("AngleX",
                          &XML_Configuration_Sensor::AngleX,
                          DOC(themachinethatgoesping,
                            echosounders,
                            simrad,
                            datagrams,
                            xml_datagrams,
                            XML_Configuration_Sensor,
                            AngleX))
        .def_readwrite("X",
                          &XML_Configuration_Sensor::X,
                          DOC(themachinethatgoesping,
                            echosounders,
                            simrad,
                            datagrams,
                            xml_datagrams,
                            XML_Configuration_Sensor,
                            X))
        .def_readwrite("Y",
                            &XML_Configuration_Sensor::Y,
                            DOC(themachinethatgoesping,
                                echosounders,
                                simrad,
                                datagrams,
                                xml_datagrams,
                                XML_Configuration_Sensor,
                                Y))
        .def_readwrite("Z",
                            &XML_Configuration_Sensor::Z,
                            DOC(themachinethatgoesping,
                                echosounders,
                                simrad,
                                datagrams,
                                xml_datagrams,
                                XML_Configuration_Sensor,
                                Z))
        .def_readwrite("Port",
                            &XML_Configuration_Sensor::Port,
                            DOC(themachinethatgoesping,
                                echosounders,
                                simrad,
                                datagrams,
                                xml_datagrams,
                                XML_Configuration_Sensor,
                                Port))
        .def_readwrite("Type",
                            &XML_Configuration_Sensor::Type,
                            DOC(themachinethatgoesping,
                                echosounders,
                                simrad,
                                datagrams,
                                xml_datagrams,
                                XML_Configuration_Sensor,
                                Type))
        .def_readwrite("Name",
                            &XML_Configuration_Sensor::Name,
                            DOC(themachinethatgoesping,
                                echosounders,
                                simrad,
                                datagrams,
                                xml_datagrams,
                                XML_Configuration_Sensor,
                                Name))
        .def_readwrite("TalkerID",
                            &XML_Configuration_Sensor::TalkerID,
                            DOC(themachinethatgoesping,
                                echosounders,
                                simrad,
                                datagrams,
                                xml_datagrams,
                                XML_Configuration_Sensor,
                                TalkerID))
        
        .def_readwrite("unknown_children",
                       &XML_Configuration_Sensor::unknown_children,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Sensor,
                           unknown_children))
        .def_readwrite("unknown_attributes",
                       &XML_Configuration_Sensor::unknown_attributes,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Sensor,
                           unknown_attributes))

        // ----- methods -----
        .def("parsed_completely",
             &XML_Configuration_Sensor::parsed_completely,
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 xml_datagrams,
                 XML_Configuration_Sensor,
                 parsed_completely))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(XML_Configuration_Sensor)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(XML_Configuration_Sensor)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(XML_Configuration_Sensor)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}