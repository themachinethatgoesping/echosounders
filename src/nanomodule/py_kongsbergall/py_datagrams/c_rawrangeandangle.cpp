// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>


#include "../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/rawrangeandangle.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::RawRangeAndAngle;

#define DOC_RawRangeAndAngle(ARG)                                                                  \
    DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, RawRangeAndAngle, ARG)

void init_c_rawrangeandangle(nanobind::module_& m)
{
     nb::class_<RawRangeAndAngle, datagrams::KongsbergAllDatagram>(
        m,
        "RawRangeAndAngle",
        DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, RawRangeAndAngle))
     .def(nb::init<>(), DOC_RawRangeAndAngle(RawRangeAndAngle))
        
        // --- convenience functions ---
        .def("get_two_way_travel_times",
             nb::overload_cast<>(&RawRangeAndAngle::get_two_way_travel_times, nb::const_),
             DOC_RawRangeAndAngle(get_two_way_travel_times))
          .def("get_two_way_travel_times",
                nb::overload_cast<const std::vector<uint32_t>&>(
                     &RawRangeAndAngle::get_two_way_travel_times, nb::const_),
             DOC_RawRangeAndAngle(get_two_way_travel_times_2),
                nb::arg("beam_numbers"))
        .def("get_beam_crosstrack_angles",
             nb::overload_cast<>(&RawRangeAndAngle::get_beam_crosstrack_angles, nb::const_),
             DOC_RawRangeAndAngle(get_beam_crosstrack_angles))
          .def("get_beam_crosstrack_angles",
                nb::overload_cast<const std::vector<uint32_t>&>(
                     &RawRangeAndAngle::get_beam_crosstrack_angles, nb::const_),
             DOC_RawRangeAndAngle(get_beam_crosstrack_angles_2),
                nb::arg("beam_numbers"))

        // --- convenient data access ---
        .def("set_ping_counter",
             &RawRangeAndAngle::set_ping_counter,
             DOC_RawRangeAndAngle(ping_counter))
        .def("get_ping_counter",
             &RawRangeAndAngle::get_ping_counter,
             DOC_RawRangeAndAngle(ping_counter))
        .def("set_system_serial_number",
             &RawRangeAndAngle::set_system_serial_number,
             DOC_RawRangeAndAngle(system_serial_number))
        .def("get_system_serial_number",
             &RawRangeAndAngle::get_system_serial_number,
             DOC_RawRangeAndAngle(system_serial_number))
        .def("set_sound_speed_at_transducer",
             &RawRangeAndAngle::set_sound_speed_at_transducer,
             DOC_RawRangeAndAngle(sound_speed_at_transducer))
        .def("get_sound_speed_at_transducer",
             &RawRangeAndAngle::get_sound_speed_at_transducer,
             DOC_RawRangeAndAngle(sound_speed_at_transducer))
        .def("set_number_of_transmit_sectors",
             &RawRangeAndAngle::set_number_of_transmit_sectors,
             DOC_RawRangeAndAngle(number_of_transmit_sectors))
        .def("get_number_of_transmit_sectors",
             &RawRangeAndAngle::get_number_of_transmit_sectors,
             DOC_RawRangeAndAngle(number_of_transmit_sectors))
        .def("set_number_of_receiver_beams",
             &RawRangeAndAngle::set_number_of_receiver_beams,
             DOC_RawRangeAndAngle(number_of_receiver_beams))
        .def("get_number_of_receiver_beams",
             &RawRangeAndAngle::get_number_of_receiver_beams,
             DOC_RawRangeAndAngle(number_of_receiver_beams))
        .def("set_number_of_valid_detections",
             &RawRangeAndAngle::set_number_of_valid_detections,
             DOC_RawRangeAndAngle(number_of_valid_detections))
        .def("get_number_of_valid_detections",
             &RawRangeAndAngle::get_number_of_valid_detections,
             DOC_RawRangeAndAngle(number_of_valid_detections))
        .def("set_sampling_frequency",
             &RawRangeAndAngle::set_sampling_frequency,
             DOC_RawRangeAndAngle(sampling_frequency))
        .def("get_sampling_frequency",
             &RawRangeAndAngle::get_sampling_frequency,
             DOC_RawRangeAndAngle(sampling_frequency))
        .def("set_d_scale", &RawRangeAndAngle::set_d_scale, DOC_RawRangeAndAngle(d_scale))
        .def("get_d_scale", &RawRangeAndAngle::get_d_scale, DOC_RawRangeAndAngle(d_scale))

        // substructures access
        .def("set_transmit_sectors",
             &RawRangeAndAngle::set_transmit_sectors,
             DOC_RawRangeAndAngle(transmit_sectors),
             nb::rv_policy::reference_internal)
        .def("get_transmit_sectors",
             &RawRangeAndAngle::get_transmit_sectors,
             DOC_RawRangeAndAngle(transmit_sectors))
        .def("transmit_sectors",
             &RawRangeAndAngle::transmit_sectors,
             DOC_RawRangeAndAngle(transmit_sectors_2),
             nb::rv_policy::reference_internal)
        .def("set_beams",
             &RawRangeAndAngle::set_beams,
             DOC_RawRangeAndAngle(beams),
             nb::rv_policy::reference_internal)
        .def("get_beams", &RawRangeAndAngle::get_beams, DOC_RawRangeAndAngle(beams))
        .def("beams",
             &RawRangeAndAngle::beams,
             DOC_RawRangeAndAngle(beams_2),
             nb::rv_policy::reference_internal)

        // --- processed member access ---
        .def("get_sound_speed_at_transducer_in_m_per_s",
             &RawRangeAndAngle::get_sound_speed_at_transducer_in_m_per_s,
             DOC_RawRangeAndAngle(get_sound_speed_at_transducer_in_m_per_s))

        // --- checksum access ---
        .def("get_etx", &RawRangeAndAngle::get_etx, DOC_RawRangeAndAngle(etx))
        .def("set_etx", &RawRangeAndAngle::set_etx, DOC_RawRangeAndAngle(etx))
        .def("get_checksum", &RawRangeAndAngle::get_checksum, DOC_RawRangeAndAngle(checksum))
        .def("set_checksum", &RawRangeAndAngle::set_checksum, DOC_RawRangeAndAngle(checksum))

        // ----- operators -----
        .def("__eq__",
             &RawRangeAndAngle::operator==,
             DOC_RawRangeAndAngle(operator_eq),
             nb::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(RawRangeAndAngle)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(RawRangeAndAngle)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(RawRangeAndAngle)
        // end LinearInterpolator
        ;
}
}
}
}
}
}