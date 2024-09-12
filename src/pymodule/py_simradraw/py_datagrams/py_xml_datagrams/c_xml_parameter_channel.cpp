// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "module.hpp"
#include <themachinethatgoesping/echosounders/simradraw/datagrams/xml_datagrams/xml_parameter_channel.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_datagrams {
namespace py_datagrams_xml {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simradraw;
using datagrams::xml_datagrams::XML_Parameter_Channel;

#define DOC_XML_Parameter_Channel(ARG)                                                             \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        simradraw,                                                                                 \
        datagrams,                                                                                 \
        xml_datagrams,                                                                             \
        XML_Parameter_Channel,                                                                     \
        ARG)

void init_c_xml_parameter_channel(pybind11::module& m)
{
    py::class_<XML_Parameter_Channel>(m,
                                      "XML_Parameter_Channel",
                                      DOC(themachinethatgoesping,
                                          echosounders,
                                          simradraw,
                                          datagrams,
                                          xml_datagrams,
                                          XML_Parameter_Channel))
        .def(py::init<>(), DOC_XML_Parameter_Channel(XML_Parameter_Channel))

        // ----- attributes -----
        .def_readwrite(
            "ChannelID", &XML_Parameter_Channel::ChannelID, DOC_XML_Parameter_Channel(ChannelID))
        .def_readwrite("ChannelMode",
                       &XML_Parameter_Channel::ChannelMode,
                       DOC_XML_Parameter_Channel(ChannelMode))
        .def_readwrite(
            "PulseForm", &XML_Parameter_Channel::PulseForm, DOC_XML_Parameter_Channel(PulseForm))
        .def_readwrite("FrequencyStart",
                       &XML_Parameter_Channel::FrequencyStart,
                       DOC_XML_Parameter_Channel(FrequencyStart))
        .def_readwrite("FrequencyEnd",
                       &XML_Parameter_Channel::FrequencyEnd,
                       DOC_XML_Parameter_Channel(FrequencyEnd))
        .def_readwrite(
            "BandWidth", &XML_Parameter_Channel::BandWidth, DOC_XML_Parameter_Channel(BandWidth))
        .def_readwrite(
            "Frequency", &XML_Parameter_Channel::Frequency, DOC_XML_Parameter_Channel(Frequency))
        .def_readwrite("PulseDuration",
                       &XML_Parameter_Channel::PulseDuration,
                       DOC_XML_Parameter_Channel(PulseDuration))
        .def_readwrite("PulseLength",
                       &XML_Parameter_Channel::PulseLength,
                       DOC_XML_Parameter_Channel(PulseLength))
        .def_readwrite("SampleInterval",
                       &XML_Parameter_Channel::SampleInterval,
                       DOC_XML_Parameter_Channel(SampleInterval))
        .def_readwrite("TransducerDepth",
                       &XML_Parameter_Channel::TransducerDepth,
                       DOC_XML_Parameter_Channel(TransducerDepth))
        .def_readwrite("TransmitPower",
                       &XML_Parameter_Channel::TransmitPower,
                       DOC_XML_Parameter_Channel(TransmitPower))
        .def_readwrite("Slope", &XML_Parameter_Channel::Slope, DOC_XML_Parameter_Channel(Slope))
        .def_readwrite("SoundVelocity",
                       &XML_Parameter_Channel::SoundVelocity,
                       DOC_XML_Parameter_Channel(SoundVelocity))
        .def_readwrite("unknown_children",
                       &XML_Parameter_Channel::unknown_children,
                       DOC_XML_Parameter_Channel(unknown_children))
        .def_readwrite("unknown_attributes",
                       &XML_Parameter_Channel::unknown_attributes,
                       DOC_XML_Parameter_Channel(unknown_attributes))

        // ----- methods -----
        .def("get_pulse_duration",
             &XML_Parameter_Channel::get_pulse_duration,
             DOC_XML_Parameter_Channel(get_pulse_duration))
        .def("get_pulse_form_is_cw",
             &XML_Parameter_Channel::get_pulse_form_is_cw,
             DOC_XML_Parameter_Channel(get_pulse_form_is_cw))
        .def("get_pulse_form_is_fm",
             &XML_Parameter_Channel::get_pulse_form_is_fm,
             DOC_XML_Parameter_Channel(get_pulse_form_is_fm))
        .def("get_tx_signal_parameters",
             &XML_Parameter_Channel::get_tx_signal_parameters,
             DOC_XML_Parameter_Channel(get_tx_signal_parameters))
        .def("parsed_completely",
             &XML_Parameter_Channel::parsed_completely,
             DOC_XML_Parameter_Channel(parsed_completely))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(XML_Parameter_Channel)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(XML_Parameter_Channel)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(XML_Parameter_Channel)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}