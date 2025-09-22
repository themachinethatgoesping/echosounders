// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "module.hpp"
#include <themachinethatgoesping/echosounders/simradraw/datagrams/xml_datagrams/xml_configuration_transceiver.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_datagrams {
namespace py_datagrams_xml {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simradraw;
using datagrams::xml_datagrams::XML_Configuration_Transceiver;

#define DOC_XML_Configuration_Transceiver(arg)                                                     \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        simradraw,                                                                                 \
        datagrams,                                                                                 \
        xml_datagrams,                                                                             \
        XML_Configuration_Transceiver,                                                             \
        arg)

void init_c_xml_configuration_transceiver(pybind11::module& m)
{
    py::classh<XML_Configuration_Transceiver>(m,
                                              "XML_Configuration_Transceiver",
                                              DOC(themachinethatgoesping,
                                                  echosounders,
                                                  simradraw,
                                                  datagrams,
                                                  xml_datagrams,
                                                  XML_Configuration_Transceiver))
        .def(py::init<>(), DOC_XML_Configuration_Transceiver(XML_Configuration_Transceiver))

        // ----- convenience functions -----

        .def("get_transceiver_channel",
             &XML_Configuration_Transceiver::get_channel,
             DOC_XML_Configuration_Transceiver(get_channel),
             py::arg("channel_id"))

        // ----- children -----
        .def_readwrite("Channels",
                       &XML_Configuration_Transceiver::Channels,
                       DOC_XML_Configuration_Transceiver(Channels))

        // ----- attributes -----
        .def_readwrite("TransceiverName",
                       &XML_Configuration_Transceiver::TransceiverName,
                       DOC_XML_Configuration_Transceiver(TransceiverName))
        .def_readwrite("TransceiverType",
                       &XML_Configuration_Transceiver::TransceiverType,
                       DOC_XML_Configuration_Transceiver(TransceiverType))
        .def_readwrite("MarketSegment",
                       &XML_Configuration_Transceiver::MarketSegment,
                       DOC_XML_Configuration_Transceiver(MarketSegment))
        .def_readwrite("EthernetAddress",
                       &XML_Configuration_Transceiver::EthernetAddress,
                       DOC_XML_Configuration_Transceiver(EthernetAddress))
        .def_readwrite("IPAddress",
                       &XML_Configuration_Transceiver::IPAddress,
                       DOC_XML_Configuration_Transceiver(IPAddress))
        .def_readwrite("TransceiverSoftwareVersion",
                       &XML_Configuration_Transceiver::TransceiverSoftwareVersion,
                       DOC_XML_Configuration_Transceiver(TransceiverSoftwareVersion))
        .def_readwrite("Version",
                       &XML_Configuration_Transceiver::Version,
                       DOC_XML_Configuration_Transceiver(Version))
        .def_readwrite("Impedance",
                       &XML_Configuration_Transceiver::Impedance,
                       DOC_XML_Configuration_Transceiver(Impedance))
        .def_readwrite("RxSampleFrequency",
                       &XML_Configuration_Transceiver::RxSampleFrequency,
                       DOC_XML_Configuration_Transceiver(RxSampleFrequency))
        .def_readwrite("SerialNumber",
                       &XML_Configuration_Transceiver::SerialNumber,
                       DOC_XML_Configuration_Transceiver(SerialNumber))
        .def_readwrite("TransceiverNumber",
                       &XML_Configuration_Transceiver::TransceiverNumber,
                       DOC_XML_Configuration_Transceiver(TransceiverNumber))
        .def_readwrite("Multiplexing",
                       &XML_Configuration_Transceiver::Multiplexing,
                       DOC_XML_Configuration_Transceiver(Multiplexing))

        .def_readwrite("unknown_children",
                       &XML_Configuration_Transceiver::unknown_children,
                       DOC_XML_Configuration_Transceiver(unknown_children))
        .def_readwrite("unknown_attributes",
                       &XML_Configuration_Transceiver::unknown_attributes,
                       DOC_XML_Configuration_Transceiver(unknown_attributes))

        // ----- methods -----
        .def("parsed_completely",
             &XML_Configuration_Transceiver::parsed_completely,
             DOC_XML_Configuration_Transceiver(parsed_completely))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(XML_Configuration_Transceiver)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(XML_Configuration_Transceiver)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(XML_Configuration_Transceiver)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}