// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "module.hpp"
#include <themachinethatgoesping/echosounders/simradraw/datagrams/xml_datagrams/xml_configuration_sensor_telegramvalue.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_datagrams {
namespace py_datagrams_xml {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::simradraw;
using datagrams::xml_datagrams::XML_Configuration_Sensor_TelegramValue;

void init_c_xml_configuration_sensor_telegramvalue(nanobind::module_& m)
{
    nb::class_<XML_Configuration_Sensor_TelegramValue>(m,
                                                       "XML_Configuration_Sensor_TelegramValue",
                                                       DOC(themachinethatgoesping,
                                                           echosounders,
                                                           simradraw,
                                                           datagrams,
                                                           xml_datagrams,
                                                           XML_Configuration_Sensor_TelegramValue))
        .def(nb::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 simradraw,
                 datagrams,
                 xml_datagrams,
                 XML_Configuration_Sensor_TelegramValue,
                 XML_Configuration_Sensor_TelegramValue))

        // ----- attributes -----
        .def_rw("Priority",
                       &XML_Configuration_Sensor_TelegramValue::Priority,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Sensor_TelegramValue,
                           Priority))
        .def_rw("Name",
                       &XML_Configuration_Sensor_TelegramValue::Name,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Sensor_TelegramValue,
                           Name))

        .def_rw("unknown_children",
                       &XML_Configuration_Sensor_TelegramValue::unknown_children,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Sensor_TelegramValue,
                           unknown_children))
        .def_rw("unknown_attributes",
                       &XML_Configuration_Sensor_TelegramValue::unknown_attributes,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Sensor_TelegramValue,
                           unknown_attributes))

        // ----- methods -----
        .def("parsed_completely",
             &XML_Configuration_Sensor_TelegramValue::parsed_completely,
             DOC(themachinethatgoesping,
                 echosounders,
                 simradraw,
                 datagrams,
                 xml_datagrams,
                 XML_Configuration_Sensor_TelegramValue,
                 parsed_completely))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(XML_Configuration_Sensor_TelegramValue)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(XML_Configuration_Sensor_TelegramValue)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(XML_Configuration_Sensor_TelegramValue)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}