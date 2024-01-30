// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datainterfaces/i_navigationdatainterface.hpp"
#include "i_datagraminterface.hpp"
#include "i_filedatainterface.hpp"
#include "i_navigationdatainterfaceperfile.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datainterfaces {
namespace py_i_navigationdatainterface {

#define DOC_I_NavigationDataInterface(ARG)                                                         \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        filetemplates,                                                                             \
        datainterfaces,                                                                            \
        I_NavigationDataInterface,                                                                 \
        ARG)

template<typename T_BaseClass, typename T_PyClass>
void NavigationDataInterface_add_interface(T_PyClass& cls)
{
    namespace py = pybind11;
    using namespace themachinethatgoesping::tools::progressbars;

    py_i_filedatainterface::FileDataInterface_add_interface<T_BaseClass>(cls);

    cls.def("configuration_data_interface",
            &T_BaseClass::configuration_data_interface,
            DOC_I_NavigationDataInterface(configuration_data_interface));
    cls.def("get_navigation_interpolators",
            &T_BaseClass::get_navigation_interpolators,
            DOC_I_NavigationDataInterface(get_navigation_interpolators));
    cls.def("get_navigation_interpolator",
            &T_BaseClass::get_navigation_interpolator,
            DOC_I_NavigationDataInterface(get_navigation_interpolator),
            py::arg("sensor_configuration"));
    cls.def("get_geolocation",
            &T_BaseClass::get_geolocation,
            DOC_I_NavigationDataInterface(get_geolocation),
            py::arg("sensor_configuration"),
            py::arg("channel_id"),
            py::arg("timestamp"));
    cls.def("get_sensor_data",
            &T_BaseClass::get_sensor_data,
            DOC_I_NavigationDataInterface(get_sensor_data),
            py::arg("sensor_configuration"),
            py::arg("timestamp"));
    cls.def("channel_ids",
            py::overload_cast<>(&T_BaseClass::channel_ids, py::const_),
            DOC_I_NavigationDataInterface(channel_ids));
    cls.def("channel_ids",
            py::overload_cast<const navigation::SensorConfiguration&>(&T_BaseClass::channel_ids,
                                                                      py::const_),
            DOC_I_NavigationDataInterface(channel_ids_2),
            py::arg("sensor_configuration"));

    cls.def("init_from_file_or_cache",
            (void(T_BaseClass::*)(
                const std::unordered_map<std::string, navigation::NavigationInterpolatorLatLon>&,
                bool,
                bool))(&T_BaseClass::init_from_file_or_cache),
            py::call_guard<py::scoped_ostream_redirect>(),
            DOC_I_NavigationDataInterface(init_from_file_or_cache),
            py::arg("cache")         = {},
            py::arg("force")         = false,
            py::arg("show_progress") = true);
    cls.def("init_from_file_or_cache",
            (void(T_BaseClass::*)(
                const std::unordered_map<std::string, navigation::NavigationInterpolatorLatLon>&,
                bool,
                I_ProgressBar&,
                bool))(&T_BaseClass::init_from_file_or_cache),
            py::call_guard<py::scoped_ostream_redirect>(),
            DOC_I_NavigationDataInterface(init_from_file_or_cache_2),
            py::arg("cache"),
            py::arg("force"),
            py::arg("progress_bar"),
            py::arg("external_progress_tick") = false);

    cls.def("get_navigation_cache",
            py::overload_cast<bool>(&T_BaseClass::get_navigation_cache),
            py::call_guard<py::scoped_ostream_redirect>(),
            DOC_I_NavigationDataInterface(get_navigation_cache),
            py::arg("show_progress") = true);
    cls.def("get_navigation_cache",
            py::overload_cast<I_ProgressBar&, bool>(&T_BaseClass::get_navigation_cache),
            py::call_guard<py::scoped_ostream_redirect>(),
            DOC_I_NavigationDataInterface(get_navigation_cache),
            py::arg("progress_bar"),
            py::arg("external_progress_tick") = false);
}

}
}
}
}
}
}