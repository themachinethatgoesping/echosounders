// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../themachinethatgoesping/echosounders/fileinterfaces/i_pingdatainterface.hpp"
#include "i_datagraminterface.hpp"
#include "i_filedatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_fileinterfaces {
namespace py_i_PingDataInterface {

template<typename T_BaseClass, typename T_PyClass>
void PingPerFileDataInterface_add_interface(T_PyClass& cls)
{
    namespace py = pybind11;

    py_i_FileDataInterface::PerFileDataInterface_add_interface<T_BaseClass>(cls);

    cls.def("configuration_data_interface",
            &T_BaseClass::configuration_data_interface,
            DOC(themachinethatgoesping,
                echosounders,
                fileinterfaces,
                I_PingPerFileDataInterface,
                configuration_data_interface));
    cls.def("navigation_data_interface",
            &T_BaseClass::navigation_data_interface,
            DOC(themachinethatgoesping,
                echosounders,
                fileinterfaces,
                I_PingPerFileDataInterface,
                navigation_data_interface));
    cls.def("environment_data_interface",
            &T_BaseClass::environment_data_interface,
            DOC(themachinethatgoesping,
                echosounders,
                fileinterfaces,
                I_PingPerFileDataInterface,
                environment_data_interface));
}

template<typename T_BaseClass, typename T_PyClass>
void PingDataInterface_add_interface(T_PyClass& cls)
{
    namespace py = pybind11;

    py_i_FileDataInterface::FileDataInterface_add_interface<T_BaseClass>(cls);

    cls.def("configuration_data_interface",
            &T_BaseClass::configuration_data_interface,
            DOC(themachinethatgoesping,
                echosounders,
                fileinterfaces,
                I_PingDataInterface,
                configuration_data_interface));
    cls.def("navigation_data_interface",
            &T_BaseClass::navigation_data_interface,
            DOC(themachinethatgoesping,
                echosounders,
                fileinterfaces,
                I_PingDataInterface,
                navigation_data_interface));
    cls.def("environment_data_interface",
            &T_BaseClass::environment_data_interface,
            DOC(themachinethatgoesping,
                echosounders,
                fileinterfaces,
                I_PingDataInterface,
                environment_data_interface));
}

}
}
}
}
}