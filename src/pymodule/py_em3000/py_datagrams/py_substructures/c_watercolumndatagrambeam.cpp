// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

// xtensor python includes
#include <xtensor-python/pyarray.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // implicit conversion xtensor <-> numpy

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../../themachinethatgoesping/echosounders/em3000/datagrams/substructures/watercolumndatagrambeam.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_em3000 {
namespace py_datagrams {
namespace py_substructures {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::em3000;
using datagrams::substructures::WaterColumnDatagramBeam;

#define DOC_WaterColumnDatagramBeam(ARG)                                                           \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        em3000,                                                                                    \
        datagrams,                                                                                 \
        substructures,                                                                             \
        WaterColumnDatagramBeam,                                                                   \
        ARG)

void init_c_watercolumndatagrambeam(pybind11::module& m)
{

    py::class_<WaterColumnDatagramBeam>(m,
                                        "WaterColumnDatagramBeam",
                                        DOC(themachinethatgoesping,
                                            echosounders,
                                            em3000,
                                            datagrams,
                                            substructures,
                                            WaterColumnDatagramBeam))
        .def(py::init<>(), DOC_WaterColumnDatagramBeam(WaterColumnDatagramBeam))
        // --- convenient data access ---
        .def("set_beam_pointing_angle",
             &WaterColumnDatagramBeam::set_beam_pointing_angle,
             DOC_WaterColumnDatagramBeam(beam_pointing_angle))
        .def("get_beam_pointing_angle",
             &WaterColumnDatagramBeam::get_beam_pointing_angle,
             DOC_WaterColumnDatagramBeam(beam_pointing_angle))
        .def("set_start_range_sample_number",
             &WaterColumnDatagramBeam::set_start_range_sample_number,
             DOC_WaterColumnDatagramBeam(start_range_sample_number))
        .def("get_start_range_sample_number",
             &WaterColumnDatagramBeam::get_start_range_sample_number,
             DOC_WaterColumnDatagramBeam(start_range_sample_number))
        .def("set_number_of_samples",
             &WaterColumnDatagramBeam::set_number_of_samples,
             DOC_WaterColumnDatagramBeam(number_of_samples))
        .def("get_number_of_samples",
             &WaterColumnDatagramBeam::get_number_of_samples,
             DOC_WaterColumnDatagramBeam(number_of_samples))
        .def("set_detected_range_in_samples",
             &WaterColumnDatagramBeam::set_detected_range_in_samples,
             DOC_WaterColumnDatagramBeam(detected_range_in_samples))
        .def("get_detected_range_in_samples",
             &WaterColumnDatagramBeam::get_detected_range_in_samples,
             DOC_WaterColumnDatagramBeam(detected_range_in_samples))
        .def("set_transmit_sector_number",
             &WaterColumnDatagramBeam::set_transmit_sector_number,
             DOC_WaterColumnDatagramBeam(transmit_sector_number))
        .def("get_transmit_sector_number",
             &WaterColumnDatagramBeam::get_transmit_sector_number,
             DOC_WaterColumnDatagramBeam(transmit_sector_number))
        .def("set_beam_number",
             &WaterColumnDatagramBeam::set_beam_number,
             DOC_WaterColumnDatagramBeam(beam_number))
        .def("get_beam_number",
             &WaterColumnDatagramBeam::get_beam_number,
             DOC_WaterColumnDatagramBeam(beam_number))

        // --- datastructure access ---
        .def("get_samples",
             &WaterColumnDatagramBeam::get_samples,
             DOC_WaterColumnDatagramBeam(samples),
             py::return_value_policy::reference_internal)
        .def("set_samples",
             &WaterColumnDatagramBeam::set_samples,
             DOC_WaterColumnDatagramBeam(samples))
        .def("samples",
             &WaterColumnDatagramBeam::samples,
             DOC_WaterColumnDatagramBeam(samples),
             py::return_value_policy::reference_internal)

        // --- processed member access ---
        .def("get_beam_pointing_angle_in_degrees",
             &WaterColumnDatagramBeam::get_beam_pointing_angle_in_degrees,
             DOC_WaterColumnDatagramBeam(get_beam_pointing_angle_in_degrees))


        // ----- operators -----
        .def("__eq__",
             &WaterColumnDatagramBeam::operator==,
             DOC_WaterColumnDatagramBeam(operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(WaterColumnDatagramBeam)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(WaterColumnDatagramBeam)
        // end LinearInterpolator
        __PYCLASS_DEFAULT_BINARY__(WaterColumnDatagramBeam)
        
        ;
}
}
}
}
}
}
}