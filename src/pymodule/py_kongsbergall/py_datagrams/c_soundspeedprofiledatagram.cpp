// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

// xtensor python includes
#include <xtensor-python/pytensor.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // implicit conversion xtensor <-> numpy

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>
#include <themachinethatgoesping/tools_pybind/enumhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/soundspeedprofiledatagram.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::SoundSpeedProfileDatagram;

#define DOC_SoundSpeedProfileDatagram(ARG)                                                         \
    DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, SoundSpeedProfileDatagram, ARG)

void init_c_soundspeedprofiledatagram(pybind11::module& m)
{
    py::class_<SoundSpeedProfileDatagram, datagrams::KongsbergAllDatagram>(
        m,
        "SoundSpeedProfileDatagram",
        DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, SoundSpeedProfileDatagram))
        .def(py::init<>(), DOC_SoundSpeedProfileDatagram(SoundSpeedProfileDatagram))
        // --- convenient data access ---
        .def("set_profile_counter",
             &SoundSpeedProfileDatagram::set_profile_counter,
             DOC_SoundSpeedProfileDatagram(profile_counter))
        .def("get_profile_counter",
             &SoundSpeedProfileDatagram::get_profile_counter,
             DOC_SoundSpeedProfileDatagram(profile_counter))
        .def("set_system_serial_number",
             &SoundSpeedProfileDatagram::set_system_serial_number,
             DOC_SoundSpeedProfileDatagram(system_serial_number))
        .def("get_system_serial_number",
             &SoundSpeedProfileDatagram::get_system_serial_number,
             DOC_SoundSpeedProfileDatagram(system_serial_number))
        .def("set_profile_date",
             &SoundSpeedProfileDatagram::set_profile_date,
             DOC_SoundSpeedProfileDatagram(profile_date))
        .def("get_profile_date",
             &SoundSpeedProfileDatagram::get_profile_date,
             DOC_SoundSpeedProfileDatagram(profile_date))
        .def("set_profile_time_since_midnight",
             &SoundSpeedProfileDatagram::set_profile_time_since_midnight,
             DOC_SoundSpeedProfileDatagram(profile_time_since_midnight))
        .def("get_profile_time_since_midnight",
             &SoundSpeedProfileDatagram::get_profile_time_since_midnight,
             DOC_SoundSpeedProfileDatagram(profile_time_since_midnight))
        .def("set_number_of_entries",
             &SoundSpeedProfileDatagram::set_number_of_entries,
             DOC_SoundSpeedProfileDatagram(number_of_entries))
        .def("get_number_of_entries",
             &SoundSpeedProfileDatagram::get_number_of_entries,
             DOC_SoundSpeedProfileDatagram(spare))
        .def("set_depth_resolution",
             &SoundSpeedProfileDatagram::set_depth_resolution,
             DOC_SoundSpeedProfileDatagram(depth_resolution))
        .def("get_depth_resolution",
             &SoundSpeedProfileDatagram::get_depth_resolution,
             DOC_SoundSpeedProfileDatagram(depth_resolution))
        .def("set_spare",
             &SoundSpeedProfileDatagram::set_spare,
             DOC_SoundSpeedProfileDatagram(spare))
        .def("get_spare",
             &SoundSpeedProfileDatagram::get_spare,
             DOC_SoundSpeedProfileDatagram(spare))

        // --- data structure access ---
        .def("get_depths_and_sound_speeds",
             &SoundSpeedProfileDatagram::get_depths_and_sound_speeds,
             DOC_SoundSpeedProfileDatagram(depths_and_sound_speeds),
             py::return_value_policy::reference_internal)
        .def("set_depths_and_sound_speeds",
             &SoundSpeedProfileDatagram::set_depths_and_sound_speeds,
             DOC_SoundSpeedProfileDatagram(depths_and_sound_speeds))
        .def("depths_and_sound_speeds",
             &SoundSpeedProfileDatagram::depths_and_sound_speeds,
             DOC_SoundSpeedProfileDatagram(depths_and_sound_speeds),
             py::return_value_policy::reference_internal)

        // --- processed member access ---
        .def("get_depth_resolution_in_meters",
             &SoundSpeedProfileDatagram::get_depth_resolution_in_meters,
             DOC_SoundSpeedProfileDatagram(get_depth_resolution_in_meters))
        .def("get_depths_in_meters",
             &SoundSpeedProfileDatagram::get_depths_in_meters,
             DOC_SoundSpeedProfileDatagram(get_depths_in_meters))
        .def("get_sound_speeds_in_meters_per_second",
             &SoundSpeedProfileDatagram::get_sound_speeds_in_meters_per_second,
             DOC_SoundSpeedProfileDatagram(get_sound_speeds_in_meters_per_second))
        .def("get_profile_timestamp",
             &SoundSpeedProfileDatagram::get_profile_timestamp,
             DOC_SoundSpeedProfileDatagram(get_profile_timestamp))
        .def("get_profile_date_string",
             &SoundSpeedProfileDatagram::get_profile_date_string,
             DOC_SoundSpeedProfileDatagram(get_profile_date_string))

        // --- checksum access ---
        .def("get_etx", &SoundSpeedProfileDatagram::get_etx, DOC_SoundSpeedProfileDatagram(etx))
        .def("set_etx", &SoundSpeedProfileDatagram::set_etx, DOC_SoundSpeedProfileDatagram(etx))
        .def("get_checksum",
             &SoundSpeedProfileDatagram::get_checksum,
             DOC_SoundSpeedProfileDatagram(checksum))
        .def("set_checksum",
             &SoundSpeedProfileDatagram::set_checksum,
             DOC_SoundSpeedProfileDatagram(checksum))

        // ----- operators -----
        .def("__eq__",
             &SoundSpeedProfileDatagram::operator==,
             DOC_SoundSpeedProfileDatagram(operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(SoundSpeedProfileDatagram)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(SoundSpeedProfileDatagram)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(SoundSpeedProfileDatagram)
        // end LinearInterpolator
        ;
}
}
}
}
}
}