// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "module.hpp"
#include <themachinethatgoesping/echosounders/simradraw/datagrams/xml_datagrams/channelconfiguration.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_datagrams {
namespace py_datagrams_xml {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simradraw;
using namespace datagrams::xml_datagrams;

void init_c_channelconfiguration(pybind11::module& m)
{
    py::classh<ChannelConfiguration>(m,
                                     "ChannelConfiguration",
                                     DOC(themachinethatgoesping,
                                         echosounders,
                                         simradraw,
                                         datagrams,
                                         xml_datagrams,
                                         ChannelConfiguration))
        .def(py::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 simradraw,
                 datagrams,
                 xml_datagrams,
                 ChannelConfiguration,
                 ChannelConfiguration))
        .def(py::init<std::string,
                      XML_Configuration_Transceiver_Channel,
                      XML_Configuration_Transceiver,
                      XML_Configuration_Transducer>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 simradraw,
                 datagrams,
                 xml_datagrams,
                 ChannelConfiguration,
                 ChannelConfiguration),
             py::arg("ChannelID"),
             py::arg("Channel"),
             py::arg("Transceiver"),
             py::arg("Transducer"))

        // ----- accessors -----
        .def_property_readonly("ChannelID",
                               &ChannelConfiguration::get_channel_id,
                               DOC(themachinethatgoesping,
                                   echosounders,
                                   simradraw,
                                   datagrams,
                                   xml_datagrams,
                                   ChannelConfiguration,
                                   get_channel_id))
        .def_property_readonly("sensor_offsets",
                               &ChannelConfiguration::get_sensor_offsets,
                               DOC(themachinethatgoesping,
                                   echosounders,
                                   simradraw,
                                   datagrams,
                                   xml_datagrams,
                                   ChannelConfiguration,
                                   get_sensor_offsets))
        .def_property_readonly("Channel",
                               &ChannelConfiguration::get_channel_struct,
                               DOC(themachinethatgoesping,
                                   echosounders,
                                   simradraw,
                                   datagrams,
                                   xml_datagrams,
                                   ChannelConfiguration,
                                   get_channel_struct))
        .def_property_readonly("Transceiver",
                               &ChannelConfiguration::get_transceiver_struct,
                               DOC(themachinethatgoesping,
                                   echosounders,
                                   simradraw,
                                   datagrams,
                                   xml_datagrams,
                                   ChannelConfiguration,
                                   get_transceiver_struct))
        .def_property_readonly("Transducer",
                               &ChannelConfiguration::get_transducer_offsets_struct,
                               DOC(themachinethatgoesping,
                                   echosounders,
                                   simradraw,
                                   datagrams,
                                   xml_datagrams,
                                   ChannelConfiguration,
                                   get_transducer_offsets_struct))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(ChannelConfiguration)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(ChannelConfiguration)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(ChannelConfiguration)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}