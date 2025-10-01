// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <nanobind/nanobind.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datainterfaces/i_pingdatainterface.hpp"
#include "i_datagraminterface.hpp"
#include "i_filedatainterface.hpp"
#include "i_pingdatainterfaceperfile.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datainterfaces {
namespace py_i_pingdatainterface {

#define DOC_PingDataInterface(ARG)                                                                 \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        filetemplates,                                                                             \
        datainterfaces,                                                                            \
        I_PingDataInterface,                                                                       \
        ARG)

template<typename T_BaseClass, typename T_PyClass>
void PingDataInterface_add_interface(T_PyClass& cls)
{
    namespace nb = nanobind;

    py_i_filedatainterface::FileDataInterface_add_interface<T_BaseClass>(cls);

    cls.def("configuration_data_interface",
            &T_BaseClass::configuration_data_interface,
            DOC_PingDataInterface(configuration_data_interface));
    cls.def("navigation_data_interface",
            &T_BaseClass::navigation_data_interface,
            DOC_PingDataInterface(navigation_data_interface));
    cls.def("environment_data_interface",
            &T_BaseClass::environment_data_interface,
            DOC_PingDataInterface(environment_data_interface));
    cls.def("get_channel_ids",
            nb::overload_cast<>(&T_BaseClass::get_channel_ids, nb::const_),
            DOC_PingDataInterface(get_channel_ids));
    cls.def("get_pings",
            nb::overload_cast<>(&T_BaseClass::get_pings, nb::const_),
            DOC_PingDataInterface(get_pings));
    cls.def("get_pings",
            nb::overload_cast<const std::string&>(&T_BaseClass::get_pings, nb::const_),
            DOC_PingDataInterface(get_pings),
            nb::arg("channel_id"));
}

}
}
}
}
}
}