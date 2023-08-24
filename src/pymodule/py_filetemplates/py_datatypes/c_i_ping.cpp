// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>
#include <xtensor-python/pyarray.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

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

            // ----- ping interface -----
            .def("get_number_of_beams",
                 py::overload_cast<>(&I_Ping::get_number_of_beams, py::const_),
                 DOC_I_Ping(get_number_of_beams))
            .def("get_number_of_beams",
                 py::overload_cast<const std::string&>(&I_Ping::get_number_of_beams, py::const_),
                 DOC_I_Ping(get_number_of_beams_2),
                 py::arg("transducer_id"))
            .def("get_number_of_beams",
                 py::overload_cast<const pingtools::PingSampleSelection&>(
                     &I_Ping::get_number_of_beams, py::const_),
                 DOC_I_Ping(get_number_of_beams_3),
                 py::arg("selection"))

            .def("get_beam_pointing_angles",
                 py::overload_cast<>(&I_Ping::get_beam_pointing_angles, py::const_),
                 DOC_I_Ping(get_beam_pointing_angles))
            .def("get_beam_pointing_angles",
                 py::overload_cast<const std::string&>(&I_Ping::get_beam_pointing_angles,
                                                       py::const_),
                 py::arg("transducer_id"),
                 DOC_I_Ping(get_beam_pointing_angles_2))
            .def("get_beam_pointing_angles",
                 py::overload_cast<const pingtools::PingSampleSelection&>(
                     &I_Ping::get_beam_pointing_angles, py::const_),
                 py::arg("selection"),
                 DOC_I_Ping(get_beam_pointing_angles_3))

            .def("get_number_of_samples_per_beam",
                 py::overload_cast<>(&I_Ping::get_number_of_samples_per_beam, py::const_),
                 DOC_I_Ping(get_number_of_samples_per_beam))
            .def("get_number_of_samples_per_beam",
                 py::overload_cast<const std::string&>(&I_Ping::get_number_of_samples_per_beam,
                                                       py::const_),
                 py::arg("transducer_id"),
                 DOC_I_Ping(get_number_of_samples_per_beam_2))
            .def("get_number_of_samples_per_beam",
                 py::overload_cast<const pingtools::PingSampleSelection&>(
                     &I_Ping::get_number_of_samples_per_beam, py::const_),
                 py::arg("selection"),
                 DOC_I_Ping(get_number_of_samples_per_beam_2))
            .def("get_number_of_samples_per_beam",
                 py::overload_cast<const pingtools::PingSampleSelection&>(
                     &I_Ping::get_number_of_samples_per_beam, py::const_),
                 py::arg("selection"),
                 DOC_I_Ping(get_number_of_samples_per_beam_2))

            // --- ping info access ---
            .def("get_file_nr", &I_Ping::get_file_nr, DOC_I_Ping(get_file_nr))
            .def("get_file_path", &I_Ping::get_file_path, DOC_I_Ping(get_file_path))

            // --- variable access ---
            .def("get_timestamp", &I_Ping::get_timestamp, DOC_I_Ping(timestamp))
            .def("set_timestamp",
                 &I_Ping::set_timestamp,
                 DOC_I_Ping(timestamp),
                 py::arg("timestamp"))
            .def("get_channel_id", &I_Ping::get_channel_id, DOC_I_Ping(channel_id))
            .def("set_channel_id",
                 &I_Ping::set_channel_id,
                 DOC_I_Ping(channel_id),
                 py::arg("channel_id"))

            .def("get_geolocation",
                 py::overload_cast<>(&I_Ping::get_geolocation, py::const_),
                 DOC_I_Ping(geolocations))
            .def("get_geolocation",
                 py::overload_cast<const std::string&>(&I_Ping::get_geolocation, py::const_),
                 DOC_I_Ping(geolocations),
                 py::arg("transducer_id"))
            .def("set_geolocation",
                 py::overload_cast<navigation::datastructures::GeoLocationLatLon>(
                     &I_Ping::set_geolocation),
                 DOC_I_Ping(geolocations),
                 py::arg("geolocation_latlon"))
            .def("set_geolocation",
                 py::overload_cast<const std::string&,
                                   navigation::datastructures::GeoLocationLatLon>(
                     &I_Ping::set_geolocation),
                 DOC_I_Ping(geolocations),
                 py::arg("transducer_id"),
                 py::arg("geolocation_latlon"))

            // --- ping interface (Documentation states that these functions are not implemented)
            // ---
            .def("get_angle", &I_Ping::get_angle, DOC_I_Ping(get_angle))
            .def("get_sv",
                 py::overload_cast<bool>(&I_Ping::get_sv, py::const_),
                 DOC_I_Ping(get_sv),
                 py::arg("dB") = false)
            .def("get_sv",
                 py::overload_cast<const std::string&, bool>(&I_Ping::get_sv, py::const_),
                 DOC_I_Ping(get_sv_2),
                 py::arg("transducer_id"),
                 py::arg("dB") = false)
            .def("get_sv",
                 py::overload_cast<const pingtools::PingSampleSelection&, bool>(&I_Ping::get_sv,
                                                                                py::const_),
                 DOC_I_Ping(get_sv_3),
                 py::arg("selection"),
                 py::arg("dB") = false)
            .def("get_sv_stacked",
                 &I_Ping::get_sv_stacked,
                 DOC_I_Ping(get_sv_stacked),
                 py::arg("dB") = false)

            .def_property_readonly(
                "bottom", py::overload_cast<>(&I_Ping::bottom), DOC_I_Ping(bottom))

            // --- ping interface (functions that indicate ping features ---
            .def("has_angle", &I_Ping::has_angle, DOC_I_Ping(has_angle))
            .def("has_sv", &I_Ping::has_sv, DOC_I_Ping(has_sv))

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