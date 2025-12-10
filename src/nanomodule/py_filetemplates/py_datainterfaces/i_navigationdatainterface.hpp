// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/unordered_map.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

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
    namespace nb = nanobind;
    using namespace themachinethatgoesping::tools::progressbars;

    py_i_filedatainterface::FileDataInterface_add_interface<T_BaseClass>(cls);

    cls.def("configuration_data_interface",
            &T_BaseClass::configuration_data_interface,
            DOC_I_NavigationDataInterface(configuration_data_interface));
    cls.def("get_navigation_interpolator_keys",
            &T_BaseClass::get_navigation_interpolator_keys,
            DOC_I_NavigationDataInterface(get_navigation_interpolator_keys));
    cls.def("set_navigation_interpolators",
            &T_BaseClass::set_navigation_interpolators,
            DOC_I_NavigationDataInterface(set_navigation_interpolators),
            nb::arg("navigation_interpolators"));
    cls.def("has_navigation_interpolator",
            &T_BaseClass::has_navigation_interpolator,
            DOC_I_NavigationDataInterface(has_navigation_interpolator),
            nb::arg("sensor_configuration_hash"));
    cls.def("get_navigation_interpolator",
            &T_BaseClass::get_navigation_interpolator,
            DOC_I_NavigationDataInterface(get_navigation_interpolator),
            nb::arg("sensor_configuration"));
    cls.def("set_navigation_interpolator",
            &T_BaseClass::set_navigation_interpolator,
            DOC_I_NavigationDataInterface(set_navigation_interpolator),
            nb::arg("sensor_configuration_hash"),
            nb::arg("navigation_interpolator"));
    cls.def("get_channel_ids",
            nb::overload_cast<>(&T_BaseClass::get_channel_ids, nb::const_),
            DOC_I_NavigationDataInterface(get_channel_ids));
    cls.def("get_channel_ids",
            nb::overload_cast<uint64_t>(&T_BaseClass::get_channel_ids, nb::const_),
            DOC_I_NavigationDataInterface(get_channel_ids_2),
            nb::arg("sensor_configuration_hash"));
    cls.def("get_navigation_data",
            &T_BaseClass::get_navigation_data,
            DOC_I_NavigationDataInterface(get_navigation_data),
            nb::arg("downsample_interval_sec") = 1.0,
            nb::arg("max_gap_sec") = -1.0);
}

}
}
}
}
}
}