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
using datagrams::substructures::WatercolumnDatagramTransmitSector;

#define DOC_WatercolumnDatagramTransmitSector(ARG)                                                 \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        em3000,                                                                                    \
        datagrams,                                                                                 \
        substructures,                                                                             \
        WatercolumnDatagramTransmitSector,                                                         \
        ARG)

void init_c_watercolumndatagramtransmitsector(pybind11::module& m)
{

    py::class_<WatercolumnDatagramTransmitSector>(m,
                                                  "WatercolumnDatagramTransmitSector",
                                                  DOC(themachinethatgoesping,
                                                      echosounders,
                                                      em3000,
                                                      datagrams,
                                                      substructures,
                                                      WatercolumnDatagramTransmitSector))
        .def(py::init<>(), DOC_WatercolumnDatagramTransmitSector(WatercolumnDatagramTransmitSector))
        // --- convenient data access ---
        .def("set_tilt_angle",
             &WatercolumnDatagramTransmitSector::set_tilt_angle,
             DOC_WatercolumnDatagramTransmitSector(tilt_angle))
        .def("get_tilt_angle",
             &WatercolumnDatagramTransmitSector::get_tilt_angle,
             DOC_WatercolumnDatagramTransmitSector(tilt_angle))
        .def("set_center_frequency",
             &WatercolumnDatagramTransmitSector::set_center_frequency,
             DOC_WatercolumnDatagramTransmitSector(center_frequency))
        .def("get_center_frequency",
             &WatercolumnDatagramTransmitSector::get_center_frequency,
             DOC_WatercolumnDatagramTransmitSector(center_frequency))
        .def("set_transmit_sector_number",
             &WatercolumnDatagramTransmitSector::set_transmit_sector_number,
             DOC_WatercolumnDatagramTransmitSector(transmit_sector_number))
        .def("get_transmit_sector_number",
             &WatercolumnDatagramTransmitSector::get_transmit_sector_number,
             DOC_WatercolumnDatagramTransmitSector(transmit_sector_number))
        .def("set_spare",
             &WatercolumnDatagramTransmitSector::set_spare,
             DOC_WatercolumnDatagramTransmitSector(spare))
        .def("get_spare",
             &WatercolumnDatagramTransmitSector::get_spare,
             DOC_WatercolumnDatagramTransmitSector(spare))

        // --- processed member access ---
        .def("get_tilt_angle_in_degrees",
             &WatercolumnDatagramTransmitSector::get_tilt_angle_in_degrees,
             DOC_WatercolumnDatagramTransmitSector(get_tilt_angle_in_degrees))
        .def("get_center_frequency_in_hz",
             &WatercolumnDatagramTransmitSector::get_center_frequency_in_hz,
             DOC_WatercolumnDatagramTransmitSector(get_center_frequency_in_hz))

        // ----- operators -----
        .def("__eq__",
             &WatercolumnDatagramTransmitSector::operator==,
             DOC_WatercolumnDatagramTransmitSector(operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(WatercolumnDatagramTransmitSector)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(WatercolumnDatagramTransmitSector)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}