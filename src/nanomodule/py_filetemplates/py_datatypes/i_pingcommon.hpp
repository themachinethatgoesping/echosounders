// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>
#include <nanobind/stl/variant.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datatypes/i_pingcommon.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datatypes {
namespace py_i_pingcommon {

#define DOC_I_PingCommon(ARG)                                                                     \
    DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_PingCommon, ARG)

template<typename T_BaseClass, typename T_PyClass>
void I_PingCommon_add_interface(T_PyClass& cls)
{
    namespace nb = nanobind;

    cls.def("feature_string",
            &T_BaseClass::feature_string,
            DOC_I_PingCommon(feature_string),
            nb::arg("available") = true,
            nb::arg("prefix")    = std::string(""));
    cls.def("feature_groups_string",
            &T_BaseClass::feature_groups_string,
            DOC_I_PingCommon(feature_groups_string),
            nb::arg("available") = true,
            nb::arg("prefix")    = std::string(""));
    cls.def("has_any_of_features",
            &T_BaseClass::has_any_of_features,
            DOC_I_PingCommon(has_any_of_features),
            nb::arg("feature_names"));
    cls.def("has_all_of_features",
            &T_BaseClass::has_all_of_features,
            DOC_I_PingCommon(has_all_of_features),
            nb::arg("feature_names"));
    cls.def("has_features", &T_BaseClass::has_features, DOC_I_PingCommon(has_features));
    cls.def("has_primary_features",
            &T_BaseClass::has_primary_features,
            DOC_I_PingCommon(has_primary_features));
    cls.def("registered_features",
            &T_BaseClass::registered_features,
            DOC_I_PingCommon(registered_features));
    cls.def("primary_features",
            &T_BaseClass::primary_features,
            DOC_I_PingCommon(primary_features));
    cls.def("has_feature",
            &T_BaseClass::has_feature,
            DOC_I_PingCommon(has_feature),
            nb::arg("feature_name"));
    cls.def("available_features",
            &T_BaseClass::available_features,
            DOC_I_PingCommon(available_features),
            nb::arg("available_available") = true);
    cls.def("possible_features",
            &T_BaseClass::possible_features,
            DOC_I_PingCommon(possible_features));
    cls.def("available_feature_groups",
            &T_BaseClass::available_feature_groups,
            DOC_I_PingCommon(available_feature_groups),
            nb::arg("available") = true);
    cls.def("possible_feature_groups",
            &T_BaseClass::possible_feature_groups,
            DOC_I_PingCommon(possible_feature_groups));

    cls.def("load",
            &T_BaseClass::load,
            DOC_I_PingCommon(load),
            nb::arg("force") = false);
    cls.def("release", &T_BaseClass::release, DOC_I_PingCommon(release));
    cls.def("loaded", &T_BaseClass::loaded, DOC_I_PingCommon(loaded));

    cls __PYCLASS_DEFAULT_COPY__(T_BaseClass)
        __PYCLASS_DEFAULT_PRINTING__(T_BaseClass);
}

}
}
}
}
}
}
