// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "module.hpp"
#include <themachinethatgoesping/echosounders/simradraw/datagrams/xml_datagrams/xml_sensor.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_datagrams {
namespace py_datagrams_xml {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::simradraw;
using datagrams::xml_datagrams::XML_Sensor;

void init_c_xml_sensor(nanobind::module_& m)
{
    nb::class_<XML_Sensor>(
        m,
        "XML_Sensor",
        DOC(themachinethatgoesping, echosounders, simradraw, datagrams, xml_datagrams, XML_Sensor))
        .def(nb::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 simradraw,
                 datagrams,
                 xml_datagrams,
                 XML_Sensor,
                 XML_Sensor))

        // ----- attributes -----
        .def_rw("IsManual",
                       &XML_Sensor::IsManual,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Sensor,
                           IsManual))
        .def_rw("ManualValue",
                       &XML_Sensor::ManualValue,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Sensor,
                           ManualValue))
        .def_rw("Type",
                       &XML_Sensor::Type,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Sensor,
                           Type))

        .def_rw("unknown_children",
                       &XML_Sensor::unknown_children,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Sensor,
                           unknown_children))
        .def_rw("unknown_attributes",
                       &XML_Sensor::unknown_attributes,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Sensor,
                           unknown_attributes))

        // ----- methods -----
        .def("parsed_completely",
             &XML_Sensor::parsed_completely,
             DOC(themachinethatgoesping,
                 echosounders,
                 simradraw,
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