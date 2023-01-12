// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datatypes/i_ping.hpp"
//

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

    cls.def("get_number_of_samples",
            &T_BaseClass::get_number_of_samples,
            DOC(themachinethatgoesping,
                echosounders,
                filetemplates,
                datatypes,
                I_Ping,
                get_number_of_samples));

    // --- variable access ---
    cls.def_property_readonly(
        "get_channel_id",
        &T_BaseClass::get_channel_id,
        DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_Ping, channel_id),
        py::return_value_policy::reference_internal);
    cls.def("set_channel_id",
            &T_BaseClass::set_channel_id,
            DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_Ping, channel_id),
            py::arg("channel_id"));

    cls.def("get_timestamp",
            &T_BaseClass::get_timestamp,
            DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_Ping, timestamp),
            py::return_value_policy::reference_internal);
    cls.def("set_timestamp",
            &T_BaseClass::set_timestamp,
            DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_Ping, timestamp),
            py::arg("timestamp"));
    cls.def(
        "get_geolocation",
        &T_BaseClass::get_geolocation,
        DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_Ping, geolocation));
    cls.def(
        "set_geolocation",
        &T_BaseClass::set_geolocation,
        DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_Ping, geolocation),
        py::arg("geolocation_latlon"));
    cls.def(
        "get_file_nr",
        &T_BaseClass::get_file_nr,
        DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_Ping, get_file_nr));
    cls.def(
        "get_file_path",
        &T_BaseClass::get_file_path,
        DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_Ping, get_file_path));

    // --- ping interface (Documentation states that these functions are not implemented) ---
    cls.def("get_angle",
            &T_BaseClass::get_angle,
            DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_Ping, get_angle));
    cls.def("get_sv",
            &T_BaseClass::get_sv,
            DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_Ping, get_sv),
            py::arg("dB") = false);
    cls.def(
        "get_sv_stacked",
        &T_BaseClass::get_sv_stacked,
        DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_Ping, get_sv_stacked),
        py::arg("dB") = false);

    // --- ping interface (functions that indicate ping features ---
    cls.def("has_angle",
            &T_BaseClass::has_angle,
            DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_Ping, has_angle));
    cls.def("has_sv",
            &T_BaseClass::has_sv,
            DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_Ping, has_sv));
    cls.def(
        "feature_string",
        &T_BaseClass::feature_string,
        DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_Ping, feature_string),
        py::arg("has_features") = true);

    // ----- pybind macros -----
    // default copy functions
    cls __PYCLASS_DEFAULT_COPY__(T_BaseClass);
    // default printing functions
    cls __PYCLASS_DEFAULT_PRINTING__(T_BaseClass);
}

}
}
}
}
}
}