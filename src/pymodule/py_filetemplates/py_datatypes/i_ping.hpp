// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datatypes/i_ping.hpp"
//#include "../docstrings.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datatypes {
namespace py_i_ping {

template<typename T_BaseClass, typename T_PyClass>
void add_ping_data_interface(T_PyClass& cls)
{
    namespace py = pybind11;

    cls.def_property_readonly(
        "geolocation",
        &T_BaseClass::geolocation,
        DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_Ping, geolocation));
    cls.def("set_geolocation",
            &T_BaseClass::set_geolocation,
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                datatypes,
                I_Ping,
                set_geolocation),
            py::arg("geolocation_latlon"));

    cls.def("get_number_of_samples",
            &T_BaseClass::get_number_of_samples,
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                datatypes,
                I_Ping,
                get_number_of_samples));
    cls.def("load_data",
            &T_BaseClass::load_data,
            DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_Ping, load_data));
    cls.def(
        "release_data",
        &T_BaseClass::release_data,
        DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_Ping, release_data));

    // --- variable access ---
    cls.def_property_readonly("get_channel_id",
            &T_BaseClass::get_channel_id,
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates, datatypes, I_Ping,
                get_channel_id),
            py::return_value_policy::reference_internal);
    cls.def("set_channel_id",
            &T_BaseClass::set_channel_id,
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates, datatypes, I_Ping,
                set_channel_id),
                py::arg("channel_id"));

    cls.def("get_timestamp",
            &T_BaseClass::get_timestamp,
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates, datatypes, I_Ping,
                get_timestamp),
            py::return_value_policy::reference_internal);
    cls.def("set_timestamp",
            &T_BaseClass::set_timestamp,
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates, datatypes, I_Ping,
                set_timestamp),
                py::arg("timestamp"));
}

}
}
}
}
}
}