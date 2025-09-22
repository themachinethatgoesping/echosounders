// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "module.hpp"
#include <themachinethatgoesping/echosounders/simradraw/datagrams/xml_datagrams/xml_configuration.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_datagrams {
namespace py_datagrams_xml {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simradraw;
using datagrams::xml_datagrams::XML_Configuration;

void init_c_xml_configuration(pybind11::module& m)
{
    py::classh<XML_Configuration>(m,
                                  "XML_Configuration",
                                  DOC(themachinethatgoesping,
                                      echosounders,
                                      simradraw,
                                      datagrams,
                                      xml_datagrams,
                                      XML_Configuration))
        .def(py::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 simradraw,
                 datagrams,
                 xml_datagrams,
                 XML_Configuration,
                 XML_Configuration))

        // ----- children (derived) -----
        .def_readwrite("ChannelConfigurations",
                       &XML_Configuration::ChannelConfigurations,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration,
                           ChannelConfigurations))
        .def_readwrite("SensorConfigurations",
                       &XML_Configuration::SensorConfigurations,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration,
                           SensorConfigurations))

        // ----- methods -----
        .def("get_transceiver",
             &XML_Configuration::get_transceiver,
             DOC(themachinethatgoesping,
                 echosounders,
                 simradraw,
                 datagrams,
                 xml_datagrams,
                 XML_Configuration,
                 get_transceiver),
             py::arg("channel_id"))

        .def("get_transceivers",
             &XML_Configuration::get_transceivers,
             DOC(themachinethatgoesping,
                 echosounders,
                 simradraw,
                 datagrams,
                 xml_datagrams,
                 XML_Configuration,
                 get_transceivers))

        .def("get_transceiver_channel",
             &XML_Configuration::get_transceiver_channel,
             DOC(themachinethatgoesping,
                 echosounders,
                 simradraw,
                 datagrams,
                 xml_datagrams,
                 XML_Configuration,
                 get_transceiver_channel),
             py::arg("channel_id"))

        .def("get_transceiver_channels",
             &XML_Configuration::get_transceiver_channels,
             DOC(themachinethatgoesping,
                 echosounders,
                 simradraw,
                 datagrams,
                 xml_datagrams,
                 XML_Configuration,
                 get_transceiver_channels))

        .def("get_sensor_configuration",
             &XML_Configuration::get_sensor_configuration,
             DOC(themachinethatgoesping,
                 echosounders,
                 simradraw,
                 datagrams,
                 xml_datagrams,
                 XML_Configuration,
                 get_sensor_configuration))

        .def("get_prioritized_sensor",
             &XML_Configuration::get_prioritized_sensor,
             DOC(themachinethatgoesping,
                 echosounders,
                 simradraw,
                 datagrams,
                 xml_datagrams,
                 XML_Configuration,
                 get_prioritized_sensor),
             py::arg("prio_values"))
        .def("get_sensors_sorted_by_priority",
             &XML_Configuration::get_sensors_sorted_by_priority,
             DOC(themachinethatgoesping,
                 echosounders,
                 simradraw,
                 datagrams,
                 xml_datagrams,
                 XML_Configuration,
                 get_prioritized_sensor),
             py::arg("prio_values"))

        // ----- children -----
        .def_readwrite("ConfiguredSensors",
                       &XML_Configuration::ConfiguredSensors,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration,
                           ConfiguredSensors))
        .def_readwrite("Transducers",
                       &XML_Configuration::Transducers,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration,
                           Transducers))
        .def_readwrite("Transceivers",
                       &XML_Configuration::Transceivers,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration,
                           Transceivers))
        .def_readwrite("ActivePingMode",
                       &XML_Configuration::ActivePingMode,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration,
                           ActivePingMode))

        // ----- attributes (Header) -----
        .def_readwrite("FileFormatVersion",
                       &XML_Configuration::FileFormatVersion,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration,
                           FileFormatVersion))
        .def_readwrite("Version",
                       &XML_Configuration::Version,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration,
                           Version))
        .def_readwrite("TimeBias",
                       &XML_Configuration::TimeBias,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration,
                           TimeBias))
        .def_readwrite("ApplicationName",
                       &XML_Configuration::ApplicationName,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration,
                           ApplicationName))
        .def_readwrite("Copyright",
                       &XML_Configuration::Copyright,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simradraw,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration,
                           Copyright))

        // ----- methods -----
        .def("parsed_completely",
             &XML_Configuration::parsed_completely,
             DOC(themachinethatgoesping,
                 echosounders,
                 simradraw,
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