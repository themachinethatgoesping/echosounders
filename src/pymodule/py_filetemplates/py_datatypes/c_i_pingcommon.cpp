// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>
#include <xtensor-python/pyarray.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>
#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

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

    auto pyenum_pingfeature =
        py::enum_<t_pingfeature>(
            m,
            "t_pingfeature",
            DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, t_pingfeature))
            .value("timestamp", t_pingfeature::timestamp)
            .value("datetime", t_pingfeature::datetime)
            .value("channel_id", t_pingfeature::channel_id)
            .value("sensor_configuration", t_pingfeature::sensor_configuration)
            .value("sensor_data_latlon", t_pingfeature::sensor_data_latlon)
            .value("geolocation", t_pingfeature::geolocation)
            .value("bottom", t_pingfeature::bottom)
            .value("watercolumn", t_pingfeature::watercolumn)
            .value("tx_signal_parameters", t_pingfeature::tx_signal_parameters)
            .value("number_of_tx_sectors", t_pingfeature::number_of_tx_sectors)
            .value("beam_crosstrack_angles", t_pingfeature::beam_crosstrack_angles)
            .value("two_way_travel_times", t_pingfeature::two_way_travel_times)
            .value("xyz", t_pingfeature::xyz)
            .value("amplitudes", t_pingfeature::amplitudes)
            .value("av", t_pingfeature::av)
            .value("bottom_range_sample", t_pingfeature::bottom_range_sample)
            .export_values();

 tools::pybind_helper::add_string_to_enum_conversion<t_pingfeature>(pyenum_pingfeature);

    auto cls =
        py::class_<I_PingCommon, std::shared_ptr<I_PingCommon>>(
            m,
            "I_PingCommon",
            DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_PingCommon))

            .def("feature_string",
                 &I_PingCommon::feature_string,
                 DOC_I_PingCommon(feature_string),
                 py::arg("available") = true)
            .def("has_any_of_features",
                 &I_PingCommon::has_any_of_features,
                 DOC_I_PingCommon(has_any_of_features),
                 py::arg("feature_names"))
            .def("has_all_of_features",
                 &I_PingCommon::has_all_of_features,
                 DOC_I_PingCommon(has_all_of_features),
                 py::arg("feature_names"))
            .def("has_features", &I_PingCommon::has_features, DOC_I_PingCommon(has_features))
            .def("has_primary_features",
                 &I_PingCommon::has_primary_features,
                 DOC_I_PingCommon(has_primary_features))
            .def("registered_features",
                 &I_PingCommon::registered_features,
                 DOC_I_PingCommon(registered_features))
            .def("primary_features", &I_PingCommon::primary_features, DOC_I_PingCommon(primary_features))
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