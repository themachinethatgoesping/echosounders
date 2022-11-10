// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../../themachinethatgoesping/echosounders/simrad/datagrams/xml_datagrams/xml_sensor.hpp"
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
using datagrams::xml_datagrams::XML_Sensor;

void init_c_xml_sensor(pybind11::module& m)
{
    py::class_<XML_Sensor>(
        m,
        "XML_Sensor",
        DOC(themachinethatgoesping, echosounders, simrad, datagrams, xml_datagrams, XML_Sensor))
        .def(py::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 xml_datagrams,
                 XML_Sensor,
                 XML_Sensor))

        // ----- attributes -----
        .def_readwrite("IsManual",
                       &XML_Sensor::IsManual,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Sensor,
                           IsManual))
        .def_readwrite("ManualValue",
                       &XML_Sensor::ManualValue,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Sensor,
                           ManualValue))
        .def_readwrite("Type",
                       &XML_Sensor::Type,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Sensor,
                           Type))

        .def_readwrite("unknown_children",
                       &XML_Sensor::unknown_children,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Sensor,
                           unknown_children))
        .def_readwrite("unknown_attributes",
                       &XML_Sensor::unknown_attributes,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Sensor,
                           unknown_attributes))

        // ----- methods -----
        .def("parsed_completely",
             &XML_Sensor::parsed_completely,
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 xml_datagrams,
                 XML_Sensor,
                 parsed_completely))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(XML_Sensor)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(XML_Sensor)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(XML_Sensor)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}