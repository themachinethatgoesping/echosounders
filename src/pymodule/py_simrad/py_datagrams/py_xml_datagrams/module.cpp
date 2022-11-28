// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/stl.h>

#include <sstream>
#include <tuple>
#include <vector>

#include "../../../../themachinethatgoesping/echosounders/simrad/datagrams/xml_datagrams/xml_configuration_transceiver_channel_transducer.hpp"
#include "../../../docstrings.hpp"
#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include "module.hpp"

#include <pybind11/pybind11.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_datagrams {
namespace py_datagrams_xml {

// -- submodule declarations --
void init_c_xml_datagram(pybind11::module& m);               // c_SimradDatagram.cpp
void init_c_xml_parameter_channel(pybind11::module& m);      // c_xml_parameter_channel.cpp
void init_c_xml_parameter(pybind11::module& m);              // c_xml_parameter.cpp
void init_c_xml_initialparameter(pybind11::module& m);       // c_xml_initialparameter.cpp
void init_c_xml_pingsequence_ping(pybind11::module& m);      // c_xml_pingsequence_ping.cpp
void init_c_xml_pingsequence(pybind11::module& m);           // c_xml_pingsequence.cpp
void init_c_xml_environment(pybind11::module& m);            // c_xml_environment.cpp
void init_c_xml_environment_transducer(pybind11::module& m); // c_xml_environment_transducer.cpp
void init_c_xml_sensor(pybind11::module& m);                 // c_xml_sensor.cpp
void init_c_xml_sensor_transducer(pybind11::module& m);      // c_xml_sensor_transducer.cpp
void init_c_xml_configuration_sensor_telegramvalue(
    pybind11::module& m); // c_xml_configuration_sensor_telegramvalue.cpp
void init_c_xml_configuration_sensor_telegram(
    pybind11::module& m); // c_xml_configuration_sensor_telegram.cpp
void init_c_xml_configuration_sensor(pybind11::module& m);     // c_xml_configuration_sensor.cpp
void init_c_xml_configuration(pybind11::module& m);            // c_xml_configuration.cpp
void init_c_xml_configuration_transducer(pybind11::module& m); // c_xml_configuration_transducer.cpp
void init_c_xml_configuration_activepingmode(
    pybind11::module& m); // c_xml_configuration_activepingmode.cpp
void init_c_xml_configuration_transceiver(
    pybind11::module& m); // c_xml_configuration_transceiver.cpp
void init_c_xml_configuration_transceiver_channel(
    pybind11::module& m); // c_xml_configuration_transceiver_channel.cpp
void init_c_xml_configuration_transceiver_channel_transducer(
    pybind11::module& m); // c_xml_configuration_transceiver_channel_transducer.cpp
void init_c_xml_configuration_transceiver_channel_frequencypar(
    pybind11::module& m); // c_xml_configuration_transceiver_channel_frequencypar.cpp
void init_c_channelconfiguration(pybind11::module& m); // c_channelconfiguration.cpp

using simrad::datagrams::xml_datagrams::t_BeamType;

// -- create submodule --
void init_m_datagrams_xml(pybind11::module& m)
{
    // module description
    auto subm =
        m.def_submodule("XML0_datagrams", "Simrad EK80 XML datagram classes (subtypes of XML0)");

#define DOC_ENUM_BEAMTYPE(ENUM_VALUE)                                                              \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        simrad,                                                                                    \
        datagrams,                                                                                 \
        xml_datagrams,                                                                             \
        t_BeamType,                                                                                \
        ENUM_VALUE)

    auto pyenum_BeamType =
        pybind11::enum_<t_BeamType>(
            subm,
            "t_BeamType",
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, xml_datagrams, t_BeamType))
            .value("BeamTypeSingle", t_BeamType::BeamTypeSingle, DOC_ENUM_BEAMTYPE(BeamTypeSingle))
            .value("BeamTypeSplit", t_BeamType::BeamTypeSplit, DOC_ENUM_BEAMTYPE(BeamTypeSplit))
            .value("BeamTypeRef", t_BeamType::BeamTypeRef, DOC_ENUM_BEAMTYPE(BeamTypeRef))
            .value("BeamTypeRefB", t_BeamType::BeamTypeRefB, DOC_ENUM_BEAMTYPE(BeamTypeRefB))
            .value("BeamTypeSplit3", t_BeamType::BeamTypeSplit3, DOC_ENUM_BEAMTYPE(BeamTypeSplit3))
            .value("BeamTypeSplit2", t_BeamType::BeamTypeSplit2, DOC_ENUM_BEAMTYPE(BeamTypeSplit2))
            .value(
                "BeamTypeSplit3C", t_BeamType::BeamTypeSplit3C, DOC_ENUM_BEAMTYPE(BeamTypeSplit3C))
            .value("BeamTypeSplit3CN",
                   t_BeamType::BeamTypeSplit3CN,
                   DOC_ENUM_BEAMTYPE(BeamTypeSplit3CN))
            .value("BeamTypeSplit3CW",
                   t_BeamType::BeamTypeSplit3CW,
                   DOC_ENUM_BEAMTYPE(BeamTypeSplit3CW))
            .export_values()
        // pybind enum helper
        //
        ;

    tools::pybind_helper::add_string_to_enum_conversion<t_BeamType>(pyenum_BeamType);

    // simrad classes
    init_c_xml_datagram(subm);
    init_c_xml_parameter_channel(subm);
    init_c_xml_parameter(subm);
    init_c_xml_initialparameter(subm);
    init_c_xml_pingsequence_ping(subm);
    init_c_xml_pingsequence(subm);
    init_c_xml_environment_transducer(subm);
    init_c_xml_environment(subm);
    init_c_xml_sensor(subm);

    // configuration datagrams
    init_c_xml_configuration_sensor_telegramvalue(subm);
    init_c_xml_configuration_sensor_telegram(subm);
    init_c_xml_configuration_sensor(subm);
    init_c_xml_configuration_transducer(subm);
    init_c_xml_configuration_activepingmode(subm);
    init_c_xml_configuration_transceiver_channel_frequencypar(subm);
    init_c_xml_configuration_transceiver_channel_transducer(subm);
    init_c_xml_configuration_transceiver_channel(subm);
    init_c_xml_configuration_transceiver(subm);

    // derived datagrams
    init_c_channelconfiguration(subm);

    init_c_xml_configuration(subm);
}

}
}
}
}
}
}
