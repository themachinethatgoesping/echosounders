// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/stl.h>

#include <sstream>
#include <tuple>
#include <vector>

#include "../../../docstrings.hpp"
#include <themachinethatgoesping/tools/pybind11_helpers/enumhelpers.hpp>

#include "module.hpp"

#include <pybind11/pybind11.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_datagrams {
namespace py_datagrams_xml {

// -- submodule declarations --
void init_c_xml_datagram(pybind11::module& m);         // c_ek60_datagram.cpp
void init_c_xml_parameter_channel(pybind11::module& m); // c_xml_parameter_channel.cpp
void init_c_xml_initialparameter(pybind11::module& m); // c_xml_initialparameter.cpp
void init_c_xml_pingsequence(pybind11::module& m); // c_xml_pingsequence.cpp
void init_c_xml_environment(pybind11::module& m); // c_xml_environment.cpp
void init_c_xml_environment_transducer(pybind11::module& m); // c_xml_environment_transducer.cpp
void init_c_xml_sensor(pybind11::module& m); // c_xml_sensor.cpp
void init_c_xml_sensor_transducer(pybind11::module& m); // c_xml_sensor_transducer.cpp
void init_c_xml_configuration_sensor_telegramvalue(pybind11::module& m); // c_xml_configuration_sensor_telegramvalue.cpp
void init_c_xml_configuration_sensor_telegram(pybind11::module& m); // c_xml_configuration_sensor_telegram.cpp
void init_c_xml_configuration_sensor(pybind11::module& m); // c_xml_configuration_sensor.cpp
void init_c_xml_configuration(pybind11::module& m); // c_xml_configuration.cpp
void init_c_xml_configuration_transducer(pybind11::module& m); // c_xml_configuration_transducer.cpp
void init_c_xml_configuration_activepingmode(pybind11::module& m); // c_xml_configuration_activepingmode.cpp

// -- create submodule --
void init_m_simrad_datagrams_xml(pybind11::module& m)
{
    // module description
    auto subm =
        m.def_submodule("XML0_datagrams", "Simrad EK80 XML datagram classes (subtypes of XML0)");

    // simrad classes
    init_c_xml_datagram(subm);
    init_c_xml_parameter_channel(subm);
    init_c_xml_initialparameter(subm);
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

    init_c_xml_configuration(subm);
}

}
}
}
}
}
}
