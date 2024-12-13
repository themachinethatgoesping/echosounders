// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datainterfaces/i_pingdatainterface.hpp"
#include "i_datagraminterface.hpp"
#include "i_filedatainterface.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datainterfaces {
namespace py_i_pingdatainterface {

#define DOC_PingDataInterfacePerFile(ARG)                                                          \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        filetemplates,                                                                             \
        datainterfaces,                                                                            \
        I_PingDataInterfacePerFile,                                                                \
        ARG)

template<typename T_BaseClass, typename T_PyClass>
void PingDataInterfacePerFile_add_interface(T_PyClass& cls)
{
    namespace py = pybind11;

    py_i_filedatainterface::FileDataInterfacePerFile_add_interface<T_BaseClass>(cls);

    cls.def("configuration_data_interface",
            &T_BaseClass::configuration_data_interface,
            DOC_PingDataInterfacePerFile(configuration_data_interface));
    cls.def("configuration_data_interface_for_file",
            &T_BaseClass::configuration_data_interface_for_file,
            DOC_PingDataInterfacePerFile(configuration_data_interface_for_file));
    cls.def("navigation_data_interface",
            &T_BaseClass::navigation_data_interface,
            DOC_PingDataInterfacePerFile(navigation_data_interface));
    cls.def("environment_data_interface",
            &T_BaseClass::environment_data_interface,
            DOC_PingDataInterfacePerFile(environment_data_interface));
    cls.def("read_pings",
            &T_BaseClass::read_pings,
            DOC_PingDataInterfacePerFile(read_pings),
            py::arg("index_paths") = std::unordered_map<std::string,std::string> ());
}

}
}
}
}
}
}
