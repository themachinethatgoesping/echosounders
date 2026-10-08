// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <nanobind/nanobind.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datainterfaces/i_configurationdatainterface.hpp"
#include "i_configurationdatainterfaceperfile.hpp"
#include "i_datagraminterface.hpp"
#include "i_filedatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datainterfaces {
namespace py_i_configurationdatainterface {

template<typename T_BaseClass, typename T_PyClass>
void ConfigurationDataInterface_add_interface(T_PyClass& cls)
{
    namespace nb = nanobind;

    py_i_filedatainterface::FileDataInterface_add_interface<T_BaseClass>(cls);

    cls.def("get_sensor_configuration",
            &T_BaseClass::get_sensor_configuration,
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                datainterfaces,
                I_ConfigurationDataInterface,
                get_sensor_configuration),
            nb::arg("index"));
   
}

}
}
}
}
}
}