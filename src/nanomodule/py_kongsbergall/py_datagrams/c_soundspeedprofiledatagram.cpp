// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/pytensor_nanobind.hpp>
#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>


#include "../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/soundspeedprofiledatagram.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::SoundSpeedProfileDatagram;

#define DOC_SoundSpeedProfileDatagram(ARG)                                                         \
    DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, SoundSpeedProfileDatagram, ARG)

void init_c_soundspeedprofiledatagram(nanobind::module_& m)
{
     nb::class_<SoundSpeedProfileDatagram, datagrams::KongsbergAllDatagram>(
        m,
        "SoundSpeedProfileDatagram",
        DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, SoundSpeedProfileDatagram))
     .def(nb::init<>(), DOC_SoundSpeedProfileDatagram(SoundSpeedProfileDatagram))
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
             nb::rv_policy::reference_internal)
        .def("set_depths_and_sound_speeds",
             &SoundSpeedProfileDatagram::set_depths_and_sound_speeds,
             DOC_SoundSpeedProfileDatagram(depths_and_sound_speeds))
        .def("depths_and_sound_speeds",
             &SoundSpeedProfileDatagram::depths_and_sound_speeds,
             DOC_SoundSpeedProfileDatagram(depths_and_sound_speeds),
             nb::rv_policy::reference_internal)

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
             nb::arg("other"))
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