// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/pytensor_nanobind.hpp>
#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "../../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/substructures/watercolumndatagrambeam.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {
namespace py_substructures {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::substructures::WatercolumnDatagramBeam;

#define DOC_WatercolumnDatagramBeam(ARG)                                                           \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kongsbergall,                                                                                    \
        datagrams,                                                                                 \
        substructures,                                                                             \
        WatercolumnDatagramBeam,                                                                   \
        ARG)

void init_c_watercolumndatagrambeam(nanobind::module_& m)
{

     nb::class_<WatercolumnDatagramBeam>(m,
                                        "WatercolumnDatagramBeam",
                                        DOC(themachinethatgoesping,
                                            echosounders,
                                            kongsbergall,
                                            datagrams,
                                            substructures,
                                            WatercolumnDatagramBeam))
     .def(nb::init<>(), DOC_WatercolumnDatagramBeam(WatercolumnDatagramBeam))
        // --- convenient data access ---
        .def("set_beam_crosstrack_angle",
             &WatercolumnDatagramBeam::set_beam_crosstrack_angle,
             DOC_WatercolumnDatagramBeam(beam_crosstrack_angle))
        .def("get_beam_crosstrack_angle",
             &WatercolumnDatagramBeam::get_beam_crosstrack_angle,
             DOC_WatercolumnDatagramBeam(beam_crosstrack_angle))
        .def("set_start_range_sample_number",
             &WatercolumnDatagramBeam::set_start_range_sample_number,
             DOC_WatercolumnDatagramBeam(start_range_sample_number))
        .def("get_start_range_sample_number",
             &WatercolumnDatagramBeam::get_start_range_sample_number,
             DOC_WatercolumnDatagramBeam(start_range_sample_number))
        .def("set_number_of_samples",
             &WatercolumnDatagramBeam::set_number_of_samples,
             DOC_WatercolumnDatagramBeam(number_of_samples))
        .def("get_number_of_samples",
             &WatercolumnDatagramBeam::get_number_of_samples,
             DOC_WatercolumnDatagramBeam(number_of_samples))
        .def("set_detected_range_in_samples",
             &WatercolumnDatagramBeam::set_detected_range_in_samples,
             DOC_WatercolumnDatagramBeam(detected_range_in_samples))
        .def("get_detected_range_in_samples",
             &WatercolumnDatagramBeam::get_detected_range_in_samples,
             DOC_WatercolumnDatagramBeam(detected_range_in_samples))
        .def("set_transmit_sector_number",
             &WatercolumnDatagramBeam::set_transmit_sector_number,
             DOC_WatercolumnDatagramBeam(transmit_sector_number))
        .def("get_transmit_sector_number",
             &WatercolumnDatagramBeam::get_transmit_sector_number,
             DOC_WatercolumnDatagramBeam(transmit_sector_number))
        .def("set_beam_number",
             &WatercolumnDatagramBeam::set_beam_number,
             DOC_WatercolumnDatagramBeam(beam_number))
        .def("get_beam_number",
             &WatercolumnDatagramBeam::get_beam_number,
             DOC_WatercolumnDatagramBeam(beam_number))

        // --- data structure access ---
        .def("get_samples_are_skipped",
             &WatercolumnDatagramBeam::get_samples_are_skipped,
             DOC_WatercolumnDatagramBeam(samples_are_skipped),
             nb::rv_policy::reference_internal)
        .def("get_samples",
             &WatercolumnDatagramBeam::get_samples,
             DOC_WatercolumnDatagramBeam(samples),
             nb::rv_policy::reference_internal)
        .def("set_samples",
             &WatercolumnDatagramBeam::set_samples,
             DOC_WatercolumnDatagramBeam(samples))
        .def("samples",
             &WatercolumnDatagramBeam::samples,
             DOC_WatercolumnDatagramBeam(samples),
             nb::rv_policy::reference_internal)

        // --- processed member access ---
        .def("get_beam_crosstrack_angle_in_degrees",
             &WatercolumnDatagramBeam::get_beam_crosstrack_angle_in_degrees,
             DOC_WatercolumnDatagramBeam(get_beam_crosstrack_angle_in_degrees))
        .def("get_samples_in_db",
             &WatercolumnDatagramBeam::get_samples_in_db,
             DOC_WatercolumnDatagramBeam(get_samples_in_db))

        // ----- operators -----
        .def("__eq__",
             &WatercolumnDatagramBeam::operator==,
             DOC_WatercolumnDatagramBeam(operator_eq),
             nb::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(WatercolumnDatagramBeam)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(WatercolumnDatagramBeam)
        // end LinearInterpolator
        __PYCLASS_DEFAULT_BINARY__(WatercolumnDatagramBeam)

        ;
}
}
}
}
}
}
}