// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "module.hpp"
#include <themachinethatgoesping/echosounders/simradraw/datagrams/xml_datagrams/xml_configuration_transceiver_channel.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_datagrams {
namespace py_datagrams_xml {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::simradraw;
using datagrams::xml_datagrams::XML_Configuration_Transceiver_Channel;

#define LOCAL_CLASS_DOC_PREFIX                                                                     \
    themachinethatgoesping, echosounders, simradraw, datagrams, xml_datagrams,                     \
        XML_Configuration_Transceiver_Channel

void init_c_xml_configuration_transceiver_channel(nanobind::module_& m)
{
    nb::class_<XML_Configuration_Transceiver_Channel>(
        m, "XML_Configuration_Transceiver_Channel", DOC(LOCAL_CLASS_DOC_PREFIX))
        .def(nb::init<>(), DOC(LOCAL_CLASS_DOC_PREFIX, XML_Configuration_Transceiver_Channel))

        // ----- functions -----
        .def("get_pulse_durations",
             &XML_Configuration_Transceiver_Channel::get_pulse_durations,
             nb::arg("fm"),
             DOC(LOCAL_CLASS_DOC_PREFIX, get_pulse_durations))

        // ----- children -----
        .def_rw("Transducer",
                       &XML_Configuration_Transceiver_Channel::Transducer,
                       DOC(LOCAL_CLASS_DOC_PREFIX, Transducer))

        // ----- attributes -----
        .def_rw("ChannelID",
                       &XML_Configuration_Transceiver_Channel::ChannelID,
                       DOC(LOCAL_CLASS_DOC_PREFIX, ChannelID))
        .def_rw("LogicalChannelID",
                       &XML_Configuration_Transceiver_Channel::LogicalChannelID,
                       DOC(LOCAL_CLASS_DOC_PREFIX, LogicalChannelID))
        .def_rw("ChannelIdShort",
                       &XML_Configuration_Transceiver_Channel::ChannelIdShort,
                       DOC(LOCAL_CLASS_DOC_PREFIX, ChannelIdShort))
        .def_rw("PulseLength",
                       &XML_Configuration_Transceiver_Channel::PulseLength,
                       DOC(LOCAL_CLASS_DOC_PREFIX, PulseLength))
        .def_rw("PulseDuration",
                       &XML_Configuration_Transceiver_Channel::PulseDuration,
                       DOC(LOCAL_CLASS_DOC_PREFIX, PulseDuration))
        .def_rw("PulseDurationFM",
                       &XML_Configuration_Transceiver_Channel::PulseDurationFM,
                       DOC(LOCAL_CLASS_DOC_PREFIX, PulseDurationFM))
        .def_rw("SampleInterval",
                       &XML_Configuration_Transceiver_Channel::SampleInterval,
                       DOC(LOCAL_CLASS_DOC_PREFIX, SampleInterval))
        .def_rw("MaxTxPowerTransceiver",
                       &XML_Configuration_Transceiver_Channel::MaxTxPowerTransceiver,
                       DOC(LOCAL_CLASS_DOC_PREFIX, MaxTxPowerTransceiver))
        .def_rw("HWChannelConfiguration",
                       &XML_Configuration_Transceiver_Channel::HWChannelConfiguration,
                       DOC(LOCAL_CLASS_DOC_PREFIX, HWChannelConfiguration))
        .def_rw("ChannelNumber",
                       &XML_Configuration_Transceiver_Channel::ChannelNumber,
                       DOC(LOCAL_CLASS_DOC_PREFIX, ChannelNumber))

        .def_rw("unknown_children",
                       &XML_Configuration_Transceiver_Channel::unknown_children,
                       DOC(LOCAL_CLASS_DOC_PREFIX, unknown_children))
        .def_rw("unknown_attributes",
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