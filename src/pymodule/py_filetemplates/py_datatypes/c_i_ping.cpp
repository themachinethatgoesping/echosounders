// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>
#include <xtensor-python/pytensor.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>
#include <themachinethatgoesping/tools_pybind/datetime.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datatypes/i_ping.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datatypes {

#define DOC_I_Ping(ARG)                                                                            \
    DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_Ping, ARG)

void init_c_i_ping(pybind11::module& m)
{
    namespace py = pybind11;
    using namespace themachinethatgoesping::echosounders::filetemplates::datatypes;

    auto cls =
        py::class_<I_Ping, I_PingCommon, std::shared_ptr<I_Ping>>(
            m,
            "I_Ping",
            DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_Ping))
            .def(py::init<>(), DOC_I_Ping(I_Ping))

            // ----- ping interface -----
            // define init

            // --- variable access ---
            .def("has_timestamp", &I_Ping::has_timestamp, DOC_I_Ping(has_timestamp))
            .def("get_timestamp", &I_Ping::get_timestamp, DOC_I_Ping(timestamp))
            .def("set_timestamp",
                 &I_Ping::set_timestamp,
                 DOC_I_Ping(timestamp),
                 py::arg("timestamp"))
            .def(
                "get_datetime",
                [](const I_Ping& self, double timezone_offset_hours) {
                    return tools::pybind_helper::unixtime_to_datetime(self.get_timestamp(),
                                                                      timezone_offset_hours);
                },
                py::arg("timezone_offset_hours") = 0.,
                "Return the timestamp as datetime object")
            .def(
                "set_datetime",
                [](I_Ping& self, const pybind11::handle& datetime) {
                    self.set_timestamp(tools::pybind_helper::datetime_to_unixtime(datetime));
                },
                py::arg("datetime"),
                "Set the timestamp using a datetime object")

            .def("has_channel_id", &I_Ping::has_channel_id, DOC_I_Ping(has_channel_id))
            .def("get_channel_id", &I_Ping::get_channel_id, DOC_I_Ping(channel_id))
            .def("set_channel_id",
                 &I_Ping::set_channel_id,
                 DOC_I_Ping(channel_id),
                 py::arg("channel_id"))

            .def("has_sensor_configuration",
                 &I_Ping::has_sensor_configuration,
                 DOC_I_Ping(has_sensor_configuration))
            .def("get_sensor_configuration",
                 &I_Ping::get_sensor_configuration,
                 DOC_I_Ping(sensor_configuration),
                 py::return_value_policy::reference_internal)
            .def("set_sensor_configuration",
                 &I_Ping::set_sensor_configuration,
                 DOC_I_Ping(sensor_configuration),
                 py::arg("sensor_configuration"))
            .def("has_sensor_data_latlon",
                 &I_Ping::has_sensor_data_latlon,
                 DOC_I_Ping(has_sensor_data_latlon))
            .def("get_sensor_data_latlon",
                 &I_Ping::get_sensor_data_latlon,
                 DOC_I_Ping(sensor_data_latlon),
                 py::return_value_policy::reference_internal)
            .def("set_sensor_data_latlon",
                 &I_Ping::set_sensor_data_latlon,
                 DOC_I_Ping(sensor_data_latlon),
                 py::arg("sensor_data_latlon"))
            .def("has_geolocation", &I_Ping::has_geolocation, DOC_I_Ping(has_geolocation))
            .def("get_geolocation",
                 py::overload_cast<const std::string&>(&I_Ping::get_geolocation, py::const_),
                 DOC_I_Ping(get_geolocation),
                 py::arg("target_id") = "Transducer")
            .def("set_geolocation",
                 &I_Ping::set_geolocation,
                 DOC_I_Ping(set_geolocation),
                 py::arg("geolocation"))

            // .def("set_geolocation",
            //      py::overload_cast<navigation::datastructures::GeolocationLatLon>(
            //          &I_Ping::set_geolocation),
            //      DOC_I_Ping(get_geolocation),
            //      py::arg("geolocation_latlon"))

            // --- ping interface (Documentation states that these functions are not implemented)
            // ---

            .def_property_readonly(
                "bottom", py::overload_cast<>(&I_Ping::bottom), DOC_I_Ping(bottom))
            .def_property_readonly(
                "watercolumn", py::overload_cast<>(&I_Ping::watercolumn), DOC_I_Ping(watercolumn))

            // --- ping interface (functions that indicate ping features ---
            .def("has_bottom", &I_Ping::has_bottom, DOC_I_Ping(has_bottom))
            .def("has_watercolumn", &I_Ping::has_watercolumn, DOC_I_Ping(has_watercolumn))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(I_Ping)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(I_Ping);
}

}
}
}
}
}