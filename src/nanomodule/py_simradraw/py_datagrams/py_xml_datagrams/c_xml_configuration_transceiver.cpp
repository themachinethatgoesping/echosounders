// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "module.hpp"
#include <themachinethatgoesping/echosounders/simradraw/datagrams/xml_datagrams/xml_configuration_transceiver.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_datagrams {
namespace py_datagrams_xml {

namespace nb = nanobind;
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

void init_c_xml_configuration_transceiver(nanobind::module_& m)
{
    nb::class_<XML_Configuration_Transceiver>(m,
                                              "XML_Configuration_Transceiver",
                                              DOC(themachinethatgoesping,
                                                  echosounders,
                                                  simradraw,
                                                  datagrams,
                                                  xml_datagrams,
                                                  XML_Configuration_Transceiver))
        .def(nb::init<>(), DOC_XML_Configuration_Transceiver(XML_Configuration_Transceiver))

        // ----- convenience functions -----

        .def("get_transceiver_channel",
             &XML_Configuration_Transceiver::get_channel,
             DOC_XML_Configuration_Transceiver(get_channel),
             nb::arg("channel_id"))

        // ----- children -----
        .def_rw("Channels",
                       &XML_Configuration_Transceiver::Channels,
                       DOC_XML_Configuration_Transceiver(Channels))

        // ----- attributes -----
        .def_rw("TransceiverName",
                       &XML_Configuration_Transceiver::TransceiverName,
                       DOC_XML_Configuration_Transceiver(TransceiverName))
        .def_rw("TransceiverType",
                       &XML_Configuration_Transceiver::TransceiverType,
                       DOC_XML_Configuration_Transceiver(TransceiverType))
        .def_rw("MarketSegment",
                       &XML_Configuration_Transceiver::MarketSegment,
                       DOC_XML_Configuration_Transceiver(MarketSegment))
        .def_rw("EthernetAddress",
                       &XML_Configuration_Transceiver::EthernetAddress,
                       DOC_XML_Configuration_Transceiver(EthernetAddress))
        .def_rw("IPAddress",
                       &XML_Configuration_Transceiver::IPAddress,
                       DOC_XML_Configuration_Transceiver(IPAddress))
        .def_rw("TransceiverSoftwareVersion",
                       &XML_Configuration_Transceiver::TransceiverSoftwareVersion,
                       DOC_XML_Configuration_Transceiver(TransceiverSoftwareVersion))
        .def_rw("Version",
                       &XML_Configuration_Transceiver::Version,
                       DOC_XML_Configuration_Transceiver(Version))
        .def_rw("Impedance",
                       &XML_Configuration_Transceiver::Impedance,
                       DOC_XML_Configuration_Transceiver(Impedance))
        .def_rw("RxSampleFrequency",
                       &XML_Configuration_Transceiver::RxSampleFrequency,
                       DOC_XML_Configuration_Transceiver(RxSampleFrequency))
        .def_rw("SerialNumber",
                       &XML_Configuration_Transceiver::SerialNumber,
                       DOC_XML_Configuration_Transceiver(SerialNumber))
        .def_rw("TransceiverNumber",
                       &XML_Configuration_Transceiver::TransceiverNumber,
                       DOC_XML_Configuration_Transceiver(TransceiverNumber))
        .def_rw("Multiplexing",
                       &XML_Configuration_Transceiver::Multiplexing,
                       DOC_XML_Configuration_Transceiver(Multiplexing))

        .def_rw("unknown_children",
                       &XML_Configuration_Transceiver::unknown_children,
                       DOC_XML_Configuration_Transceiver(unknown_children))
        .def_rw("unknown_attributes",
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