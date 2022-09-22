// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>

#include "../../../../themachinethatgoesping/echosounders/simrad/datagrams/xml_datagrams/xml_configuration_transceiver_channel.hpp"
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
using datagrams::xml_datagrams::XML_Configuration_Transceiver_Channel;

void init_c_xml_configuration_transceiver_channel(pybind11::module& m)
{
    py::class_<XML_Configuration_Transceiver_Channel>(m,
                                                      "XML_Configuration_Transceiver_Channel",
                                                      DOC(themachinethatgoesping,
                                                          echosounders,
                                                          simrad,
                                                          datagrams,
                                                          xml_datagrams,
                                                          XML_Configuration_Transceiver_Channel))
        .def(py::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 xml_datagrams,
                 XML_Configuration_Transceiver_Channel,
                 XML_Configuration_Transceiver_Channel))

        // ----- children -----
        .def_readwrite("Transducer",
                       &XML_Configuration_Transceiver_Channel::Transducer,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel,
                           Transducer))

        // ----- attributes -----
        .def_readwrite("ChannelID",
                       &XML_Configuration_Transceiver_Channel::ChannelID,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel,
                           ChannelID))
        .def_readwrite("LogicalChannelID",
                       &XML_Configuration_Transceiver_Channel::LogicalChannelID,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel,
                           LogicalChannelID))
        .def_readwrite("ChannelIdShort",
                       &XML_Configuration_Transceiver_Channel::ChannelIdShort,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel,
                           ChannelIdShort))
        .def_readwrite("PulseDuration",
                       &XML_Configuration_Transceiver_Channel::PulseDuration,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel,
                           PulseDuration))
        .def_readwrite("PulseDurationFM",
                       &XML_Configuration_Transceiver_Channel::PulseDurationFM,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel,
                           PulseDurationFM))
        .def_readwrite("MaxTxPowerTransceiver",
                       &XML_Configuration_Transceiver_Channel::MaxTxPowerTransceiver,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel,
                           MaxTxPowerTransceiver))
        .def_readwrite("HWChannelConfiguration",
                       &XML_Configuration_Transceiver_Channel::HWChannelConfiguration,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel,
                           HWChannelConfiguration))

        .def_readwrite("unknown_children",
                       &XML_Configuration_Transceiver_Channel::unknown_children,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel,
                           unknown_children))
        .def_readwrite("unknown_attributes",
                       &XML_Configuration_Transceiver_Channel::unknown_attributes,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           xml_datagrams,
                           XML_Configuration_Transceiver_Channel,
                           unknown_attributes))

        // ----- methods -----
        .def("parsed_completely",
             &XML_Configuration_Transceiver_Channel::parsed_completely,
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 xml_datagrams,
                 XML_Configuration_Transceiver_Channel,
                 parsed_completely))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(XML_Configuration_Transceiver_Channel)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(XML_Configuration_Transceiver_Channel)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(XML_Configuration_Transceiver_Channel)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}