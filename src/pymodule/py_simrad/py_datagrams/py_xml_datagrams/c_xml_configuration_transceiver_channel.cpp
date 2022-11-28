// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../docstrings.hpp"
#include "module.hpp"
#include <themachinethatgoesping/echosounders/simrad/datagrams/xml_datagrams/xml_configuration_transceiver_channel.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_datagrams {
namespace py_datagrams_xml {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simrad;
using datagrams::xml_datagrams::XML_Configuration_Transceiver_Channel;

#define LOCAL_CLASS_DOC_PREFIX                                                                     \
    themachinethatgoesping, echosounders, simrad, datagrams, xml_datagrams,                        \
        XML_Configuration_Transceiver_Channel

void init_c_xml_configuration_transceiver_channel(pybind11::module& m)
{
    py::class_<XML_Configuration_Transceiver_Channel>(
        m, "XML_Configuration_Transceiver_Channel", DOC(LOCAL_CLASS_DOC_PREFIX))
        .def(py::init<>(), DOC(LOCAL_CLASS_DOC_PREFIX, XML_Configuration_Transceiver_Channel))

        // ----- children -----
        .def_readwrite("Transducer",
                       &XML_Configuration_Transceiver_Channel::Transducer,
                       DOC(LOCAL_CLASS_DOC_PREFIX, Transducer))

        // ----- attributes -----
        .def_readwrite("ChannelID",
                       &XML_Configuration_Transceiver_Channel::ChannelID,
                       DOC(LOCAL_CLASS_DOC_PREFIX, ChannelID))
        .def_readwrite("LogicalChannelID",
                       &XML_Configuration_Transceiver_Channel::LogicalChannelID,
                       DOC(LOCAL_CLASS_DOC_PREFIX, LogicalChannelID))
        .def_readwrite("ChannelIdShort",
                       &XML_Configuration_Transceiver_Channel::ChannelIdShort,
                       DOC(LOCAL_CLASS_DOC_PREFIX, ChannelIdShort))
        .def_readwrite("PulseLength",
                       &XML_Configuration_Transceiver_Channel::PulseLength,
                       DOC(LOCAL_CLASS_DOC_PREFIX, PulseLength))
        .def_readwrite("PulseDuration",
                       &XML_Configuration_Transceiver_Channel::PulseDuration,
                       DOC(LOCAL_CLASS_DOC_PREFIX, PulseDuration))
        .def_readwrite("PulseDurationFM",
                       &XML_Configuration_Transceiver_Channel::PulseDurationFM,
                       DOC(LOCAL_CLASS_DOC_PREFIX, PulseDurationFM))
        .def_readwrite("SampleInterval",
                       &XML_Configuration_Transceiver_Channel::SampleInterval,
                       DOC(LOCAL_CLASS_DOC_PREFIX, SampleInterval))
        .def_readwrite("MaxTxPowerTransceiver",
                       &XML_Configuration_Transceiver_Channel::MaxTxPowerTransceiver,
                       DOC(LOCAL_CLASS_DOC_PREFIX, MaxTxPowerTransceiver))
        .def_readwrite("HWChannelConfiguration",
                       &XML_Configuration_Transceiver_Channel::HWChannelConfiguration,
                       DOC(LOCAL_CLASS_DOC_PREFIX, HWChannelConfiguration))
        .def_readwrite("ChannelNumber",
                       &XML_Configuration_Transceiver_Channel::ChannelNumber,
                       DOC(LOCAL_CLASS_DOC_PREFIX, ChannelNumber))

        .def_readwrite("unknown_children",
                       &XML_Configuration_Transceiver_Channel::unknown_children,
                       DOC(LOCAL_CLASS_DOC_PREFIX, unknown_children))
        .def_readwrite("unknown_attributes",
                       &XML_Configuration_Transceiver_Channel::unknown_attributes,
                       DOC(LOCAL_CLASS_DOC_PREFIX, unknown_attributes))

        // ----- methods -----
        .def("parsed_completely",
             &XML_Configuration_Transceiver_Channel::parsed_completely,
             DOC(LOCAL_CLASS_DOC_PREFIX, parsed_completely))

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