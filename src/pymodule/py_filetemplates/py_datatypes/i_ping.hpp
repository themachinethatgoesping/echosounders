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

#define DOC_I_Ping(ARG)                                                                            \
    DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_Ping, ARG)

template<typename T_BaseClass, typename T_PyClass>
void add_ping_data_interface(T_PyClass& cls)
{
    namespace py = pybind11;

    cls.def("get_number_of_samples",
            &T_BaseClass::get_number_of_samples,
            DOC_I_Ping(get_number_of_samples));

    // --- multi transducer configuration ---
    cls.def("get_transducer_ids", &T_BaseClass::get_transducer_ids, DOC_I_Ping(get_transducer_ids));
    cls.def("get_transducer_ids_as_string",
            &T_BaseClass::get_transducer_ids_as_string,
            DOC_I_Ping(get_transducer_ids_as_string));
    cls.def("get_transducer_id", &T_BaseClass::get_transducer_id, DOC_I_Ping(get_transducer_id));
    cls.def("select_transducer_id",
            &T_BaseClass::select_transducer_id,
            DOC_I_Ping(select_transducer_id),
            py::arg("transducer_id"));

    // --- ping info access ---
    cls.def("get_file_nr", &T_BaseClass::get_file_nr, DOC_I_Ping(get_file_nr));
    cls.def("get_file_path", &T_BaseClass::get_file_path, DOC_I_Ping(get_file_path));

    // --- variable access ---

    cls.def("get_timestamp", &T_BaseClass::get_timestamp, DOC_I_Ping(timestamp));
    cls.def(
        "set_timestamp", &T_BaseClass::set_timestamp, DOC_I_Ping(timestamp), py::arg("timestamp"));
    cls.def("get_channel_id", &T_BaseClass::get_channel_id, DOC_I_Ping(channel_id));
    cls.def("set_channel_id",
            &T_BaseClass::set_channel_id,
            DOC_I_Ping(channel_id),
            py::arg("channel_id"));

    cls.def("get_geolocation",
            py::overload_cast<>(&T_BaseClass::get_geolocation),
            DOC_I_Ping(geolocations));
    cls.def("get_geolocation",
            py::overload_cast<const std::string&>(&T_BaseClass::get_geolocation),
            DOC_I_Ping(geolocations),
            py::arg("transducer_id"));
    cls.def("set_geolocation",
            py::overload_cast<navigation::datastructures::GeoLocationLatLon>(
                &T_BaseClass::set_geolocation),
            DOC_I_Ping(geolocations),
            py::arg("geolocation_latlon"));
    cls.def("set_geolocation",
            py::overload_cast<const std::string&, navigation::datastructures::GeoLocationLatLon>(
                &T_BaseClass::set_geolocation),
            DOC_I_Ping(geolocations),
            py::arg("transducer_id"),
            py::arg("geolocation_latlon"));

    // --- ping interface (Documentation states that these functions are not implemented) ---
    cls.def("get_angle", &T_BaseClass::get_angle, DOC_I_Ping(get_angle));
    cls.def("get_sv", &T_BaseClass::get_sv, DOC_I_Ping(get_sv), py::arg("dB") = false);
    cls.def("get_sv_stacked",
            &T_BaseClass::get_sv_stacked,
            DOC_I_Ping(get_sv_stacked),
            py::arg("dB") = false);

    // --- ping interface (functions that indicate ping features ---
    cls.def("has_angle", &T_BaseClass::has_angle, DOC_I_Ping(has_angle));
    cls.def("has_sv", &T_BaseClass::has_sv, DOC_I_Ping(has_sv));
    cls.def("feature_string",
            &T_BaseClass::feature_string,
            DOC_I_Ping(feature_string),
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