// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../themachinethatgoesping/echosounders/fileinterfaces/i_configurationdatainterface.hpp"
#include "i_datagraminterface.hpp"
#include "i_filedatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_fileinterfaces {
namespace py_i_ConfigurationDataInterface {

template<typename T_BaseClass, typename T_PyClass>
void ConfigurationDataCollection_add_interface(T_PyClass& cls)
{
    namespace py = pybind11;

    py_i_FileDataInterface::FileDataCollection_add_interface<T_BaseClass>(cls);

    cls.def("read_sensor_configuration",
            &T_BaseClass::read_sensor_configuration,
            DOC(themachinethatgoesping,
                echosounders,
                fileinterfaces,
                I_ConfigurationDataCollection,
                read_sensor_configuration));

    cls.def("get_sensor_configuration",
            &T_BaseClass::get_sensor_configuration,
            DOC(themachinethatgoesping,
                echosounders,
                fileinterfaces,
                I_ConfigurationDataCollection,
                get_sensor_configuration));
    cls.def("set_sensor_configuration",
            &T_BaseClass::set_sensor_configuration,
            DOC(themachinethatgoesping,
                echosounders,
                fileinterfaces,
                I_ConfigurationDataCollection,
                set_sensor_configuration),
            py::arg("sensor_configuration"));
}

template<typename T_BaseClass, typename T_PyClass>
void ConfigurationDataInterface_add_interface(T_PyClass& cls)
{
    namespace py = pybind11;

    py_i_FileDataInterface::FileDataInterface_add_interface<T_BaseClass>(cls);

    cls.def("get_sensor_configuration",
            &T_BaseClass::get_sensor_configuration,
            DOC(themachinethatgoesping,
                echosounders,
                fileinterfaces,
                I_ConfigurationDataInterface,
                get_sensor_configuration),
            py::arg("index"));
}

}
}
}
}
}