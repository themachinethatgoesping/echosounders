// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <nanobind/nanobind.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datainterfaces/i_configurationdatainterface.hpp"
#include "i_datagraminterface.hpp"
#include "i_filedatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datainterfaces {
namespace py_i_configurationdatainterface {

template<typename T_BaseClass, typename T_PyClass>
void ConfigurationDataInterfacePerFile_add_interface(T_PyClass& cls)
{
    namespace nb = nanobind;

    py_i_filedatainterface::FileDataInterfacePerFile_add_interface<T_BaseClass>(cls);

    cls.def("read_sensor_configuration",
            &T_BaseClass::read_sensor_configuration,
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                datainterfaces,
                I_ConfigurationDataInterfacePerFile,
                read_sensor_configuration));

    cls.def("get_sensor_configuration",
            &T_BaseClass::get_sensor_configuration,
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                datainterfaces,
                I_ConfigurationDataInterfacePerFile,
                get_sensor_configuration));
    cls.def("set_sensor_configuration",
            &T_BaseClass::set_sensor_configuration,
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                datainterfaces,
                I_ConfigurationDataInterfacePerFile,
                set_sensor_configuration),
            nb::arg("sensor_configuration"));
}

}
}
}
}
}
}