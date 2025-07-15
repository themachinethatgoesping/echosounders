// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "module.hpp"
#include <themachinethatgoesping/echosounders/simradraw/datagrams/xml_datagrams/xml_configuration_sensor_telegram.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_datagrams {
namespace py_datagrams_xml {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simradraw;
using datagrams::xml_datagrams::XML_Configuration_Sensor_Telegram;

void init_c_xml_configuration_sensor_telegram(pybind11::module& m)
{
    py::class_<XML_Configuration_Sensor_Telegram>(m,
                                                  "XML_Configuration_Sensor_Telegram",
                                                  DOC(themachinethatgoesping,
                                                      echosounders,
                                                      simradraw,
                                                      datagrams,
                                                      xml_datagrams,
                                                      XML_Configuration_Sensor_Telegram))
        .def(py::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 simradraw,
                 datagrams,
                 xml_datagrams,
                 XML_Configuration_Sensor_Telegram,
                 XML_Configuration_Sensor_Telegram))

        // ----- children -----
        .def_readwrite("Values",
                       &XML_Configuration_Sensor_Telegram::Values,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Sensor_Telegram,
                           Values))

        // ----- attributes -----
        .def_readwrite("Enabled",
                       &XML_Configuration_Sensor_Telegram::Enabled,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Sensor_Telegram,
                           Enabled))
        .def_readwrite("SubscriptionPath",
                       &XML_Configuration_Sensor_Telegram::SubscriptionPath,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Sensor_Telegram,
                           SubscriptionPath))
        .def_readwrite("Type",
                       &XML_Configuration_Sensor_Telegram::Type,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Sensor_Telegram,
                           Type))
        .def_readwrite("Name",
                       &XML_Configuration_Sensor_Telegram::Name,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Sensor_Telegram,
                           Name))

        .def_readwrite("unknown_children",
                       &XML_Configuration_Sensor_Telegram::unknown_children,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Sensor_Telegram,
                           unknown_children))
        .def_readwrite("unknown_attributes",
                       &XML_Configuration_Sensor_Telegram::unknown_attributes,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Sensor_Telegram,
                           unknown_attributes))

        // ----- methods -----
        .def("parsed_completely",
             &XML_Configuration_Sensor_Telegram::parsed_completely,
             DOC(themachinethatgoesping,
                 echosounders,
                 simradraw,
                 datagrams,
                 xml_datagrams,
                 XML_Configuration_Sensor_Telegram,
                 parsed_completely))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(XML_Configuration_Sensor_Telegram)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(XML_Configuration_Sensor_Telegram)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(XML_Configuration_Sensor_Telegram)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}