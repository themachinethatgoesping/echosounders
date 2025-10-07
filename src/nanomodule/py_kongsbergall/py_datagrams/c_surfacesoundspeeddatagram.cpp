// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/pytensor_nanobind.hpp>
#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>


#include "../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/surfacesoundspeeddatagram.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::SurfaceSoundSpeedDatagram;

#define DOC_SurfaceSoundSpeedDatagram(ARG)                                                         \
    DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, SurfaceSoundSpeedDatagram, ARG)

void init_c_surfacesoundspeeddatagram(nanobind::module_& m)
{
     nb::class_<SurfaceSoundSpeedDatagram, datagrams::KongsbergAllDatagram>(
        m,
        "SurfaceSoundSpeedDatagram",
        DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, SurfaceSoundSpeedDatagram))
     .def(nb::init<>(), DOC_SurfaceSoundSpeedDatagram(SurfaceSoundSpeedDatagram))
        // --- convenient data access ---
        .def("set_sound_speed_counter",
             &SurfaceSoundSpeedDatagram::set_sound_speed_counter,
             DOC_SurfaceSoundSpeedDatagram(sound_speed_counter))
        .def("get_sound_speed_counter",
             &SurfaceSoundSpeedDatagram::get_sound_speed_counter,
             DOC_SurfaceSoundSpeedDatagram(sound_speed_counter))
        .def("set_system_serial_number",
             &SurfaceSoundSpeedDatagram::set_system_serial_number,
             DOC_SurfaceSoundSpeedDatagram(system_serial_number))
        .def("get_system_serial_number",
             &SurfaceSoundSpeedDatagram::get_system_serial_number,
             DOC_SurfaceSoundSpeedDatagram(system_serial_number))
        .def("set_number_of_entries",
             &SurfaceSoundSpeedDatagram::set_number_of_entries,
             DOC_SurfaceSoundSpeedDatagram(number_of_entries))
        .def("get_number_of_entries",
             &SurfaceSoundSpeedDatagram::get_number_of_entries,
             DOC_SurfaceSoundSpeedDatagram(spare))
        .def("set_spare",
             &SurfaceSoundSpeedDatagram::set_spare,
             DOC_SurfaceSoundSpeedDatagram(spare))
        .def("get_spare",
             &SurfaceSoundSpeedDatagram::get_spare,
             DOC_SurfaceSoundSpeedDatagram(spare))

        // --- data structure access ---
        .def("get_times_and_sound_speeds",
             &SurfaceSoundSpeedDatagram::get_times_and_sound_speeds,
             DOC_SurfaceSoundSpeedDatagram(times_and_sound_speeds),
             nb::rv_policy::reference_internal)
        .def("set_times_and_sound_speeds",
             &SurfaceSoundSpeedDatagram::set_times_and_sound_speeds,
             DOC_SurfaceSoundSpeedDatagram(times_and_sound_speeds))
        .def("times_and_sound_speeds",
             &SurfaceSoundSpeedDatagram::times_and_sound_speeds,
             DOC_SurfaceSoundSpeedDatagram(times_and_sound_speeds),
             nb::rv_policy::reference_internal)

        // --- processed member access ---
        .def("get_sound_speed_timestamps",
             &SurfaceSoundSpeedDatagram::get_sound_speed_timestamps,
             DOC_SurfaceSoundSpeedDatagram(get_sound_speed_timestamps))
        .def("get_sound_speeds_in_meters_per_second",
             &SurfaceSoundSpeedDatagram::get_sound_speeds_in_meters_per_second,
             DOC_SurfaceSoundSpeedDatagram(get_sound_speeds_in_meters_per_second))

        // --- checksum access ---
        .def("get_etx", &SurfaceSoundSpeedDatagram::get_etx, DOC_SurfaceSoundSpeedDatagram(etx))
        .def("set_etx", &SurfaceSoundSpeedDatagram::set_etx, DOC_SurfaceSoundSpeedDatagram(etx))
        .def("get_checksum",
             &SurfaceSoundSpeedDatagram::get_checksum,
             DOC_SurfaceSoundSpeedDatagram(checksum))
        .def("set_checksum",
             &SurfaceSoundSpeedDatagram::set_checksum,
             DOC_SurfaceSoundSpeedDatagram(checksum))

        // ----- operators -----
        .def("__eq__",
             &SurfaceSoundSpeedDatagram::operator==,
             DOC_SurfaceSoundSpeedDatagram(operator_eq),
             nb::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(SurfaceSoundSpeedDatagram)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(SurfaceSoundSpeedDatagram)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(SurfaceSoundSpeedDatagram)
        // end LinearInterpolator
        ;
}
}
}
}
}
}