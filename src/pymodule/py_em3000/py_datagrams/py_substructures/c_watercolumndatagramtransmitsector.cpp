// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../../themachinethatgoesping/echosounders/em3000/datagrams/substructures/watercolumndatagramtransmitsector.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_em3000 {
namespace py_datagrams {
namespace py_substructures {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::em3000;
using datagrams::substructures::WaterColumnDatagramTransmitSector;

#define DOC_WaterColumnDatagramTransmitSector(ARG)                                                 \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        em3000,                                                                                    \
        datagrams,                                                                                 \
        substructures,                                                                             \
        WaterColumnDatagramTransmitSector,                                                         \
        ARG)

void init_c_watercolumndatagramtransmitsector(pybind11::module& m)
{

    py::class_<WaterColumnDatagramTransmitSector>(m,
                                                  "WaterColumnDatagramTransmitSector",
                                                  DOC(themachinethatgoesping,
                                                      echosounders,
                                                      em3000,
                                                      datagrams,
                                                      substructures,
                                                      WaterColumnDatagramTransmitSector))
        .def(py::init<>(), DOC_WaterColumnDatagramTransmitSector(WaterColumnDatagramTransmitSector))
        // --- convenient data access ---
        .def("set_tilt_angle",
             &WaterColumnDatagramTransmitSector::set_tilt_angle,
             DOC_WaterColumnDatagramTransmitSector(tilt_angle))
        .def("get_tilt_angle",
             &WaterColumnDatagramTransmitSector::get_tilt_angle,
             DOC_WaterColumnDatagramTransmitSector(tilt_angle))
        .def("set_center_frequency",
             &WaterColumnDatagramTransmitSector::set_center_frequency,
             DOC_WaterColumnDatagramTransmitSector(center_frequency))
        .def("get_center_frequency",
             &WaterColumnDatagramTransmitSector::get_center_frequency,
             DOC_WaterColumnDatagramTransmitSector(center_frequency))
        .def("set_transmit_sector_number",
             &WaterColumnDatagramTransmitSector::set_transmit_sector_number,
             DOC_WaterColumnDatagramTransmitSector(transmit_sector_number))
        .def("get_transmit_sector_number",
             &WaterColumnDatagramTransmitSector::get_transmit_sector_number,
             DOC_WaterColumnDatagramTransmitSector(transmit_sector_number))
        .def("set_spare",
             &WaterColumnDatagramTransmitSector::set_spare,
             DOC_WaterColumnDatagramTransmitSector(spare))
        .def("get_spare",
             &WaterColumnDatagramTransmitSector::get_spare,
             DOC_WaterColumnDatagramTransmitSector(spare))

        // --- processed member access ---
        .def("get_tilt_angle_in_degrees",
             &WaterColumnDatagramTransmitSector::get_tilt_angle_in_degrees,
             DOC_WaterColumnDatagramTransmitSector(get_tilt_angle_in_degrees))
        .def("get_center_frequency_in_hz",
             &WaterColumnDatagramTransmitSector::get_center_frequency_in_hz,
             DOC_WaterColumnDatagramTransmitSector(get_center_frequency_in_hz))

        // ----- operators -----
        .def("__eq__",
             &WaterColumnDatagramTransmitSector::operator==,
             DOC_WaterColumnDatagramTransmitSector(operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(WaterColumnDatagramTransmitSector)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(WaterColumnDatagramTransmitSector)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}