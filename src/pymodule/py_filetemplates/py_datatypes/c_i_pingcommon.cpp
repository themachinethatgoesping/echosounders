// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>
#include <xtensor-python/pyarray.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datatypes/i_pingcommon.hpp"
//

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datatypes {

#define DOC_I_PingCommon(ARG)                                                                      \
    DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_PingCommon, ARG)

void init_c_i_pingcommon(pybind11::module& m)
{
    namespace py = pybind11;
    using namespace themachinethatgoesping::echosounders::filetemplates::datatypes;

    auto cls =
        py::class_<I_PingCommon, std::shared_ptr<I_PingCommon>>(
            m,
            "I_PingCommon",
            DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_PingCommon))

            .def("feature_string",
                 &I_PingCommon::feature_string,
                 DOC_I_PingCommon(feature_string),
                 py::arg("available") = true)
            .def("has_features", &I_PingCommon::has_features, DOC_I_PingCommon(has_features))
            .def("registered_features",
                 &I_PingCommon::registered_features,
                 DOC_I_PingCommon(registered_features))
            .def("has_feature",
                 &I_PingCommon::has_feature,
                 DOC_I_PingCommon(has_feature),
                 py::arg("feature_name"))
            .def("load", &I_PingCommon::load, DOC_I_PingCommon(load), py::arg("force") = false)
            .def("release", &I_PingCommon::release, DOC_I_PingCommon(release))
            .def("loaded", &I_PingCommon::loaded, DOC_I_PingCommon(loaded))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(I_PingCommon)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(I_PingCommon);
}

}
}
}
}
}