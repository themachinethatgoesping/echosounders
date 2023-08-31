// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once



#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datainterfaces/i_environmentdatainterface.hpp"
#include "i_datagraminterface.hpp"
#include "i_environmentdatainterfaceperfile.hpp"
#include "i_filedatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datainterfaces {
namespace py_i_environmentdatainterface {

template<typename T_BaseClass, typename T_PyClass>
void EnvironmentDataInterface_add_interface(T_PyClass& cls)
{
    namespace py = pybind11;

    py_i_filedatainterface::FileDataInterface_add_interface<T_BaseClass>(cls);

    cls.def("configuration_data_interface",
            &T_BaseClass::configuration_data_interface,
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                datainterfaces,
                I_EnvironmentDataInterface,
                configuration_data_interface));
    cls.def("navigation_data_interface",
            &T_BaseClass::navigation_data_interface,
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                datainterfaces,
                I_EnvironmentDataInterface,
                navigation_data_interface));
}

}
}
}
}
}
}