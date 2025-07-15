// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/substructures/rawrangeandangletransmitsector.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {
namespace py_substructures {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::substructures::RawRangeAndAngleTransmitSector;

#define DOC_RawRangeAndAngleTransmitSector(ARG)                                                    \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kongsbergall,                                                                                    \
        datagrams,                                                                                 \
        substructures,                                                                             \
        RawRangeAndAngleTransmitSector,                                                            \
        ARG)

void init_c_rawrangeandangletransmitsector(pybind11::module& m)
{

    py::class_<RawRangeAndAngleTransmitSector>(m,
                                               "RawRangeAndAngleTransmitSector",
                                               DOC(themachinethatgoesping,
                                                   echosounders,
                                                   kongsbergall,
                                                   datagrams,
                                                   substructures,
                                                   RawRangeAndAngleTransmitSector))
        .def(py::init<>(), DOC_RawRangeAndAngleTransmitSector(RawRangeAndAngleTransmitSector))
        // --- convenient data access ---
        .def("set_tilt_angle",
             &RawRangeAndAngleTransmitSector::set_tilt_angle,
             DOC_RawRangeAndAngleTransmitSector(tilt_angle))
        .def("get_tilt_angle",
             &RawRangeAndAngleTransmitSector::get_tilt_angle,
             DOC_RawRangeAndAngleTransmitSector(tilt_angle))
        .def("set_focus_range",
             &RawRangeAndAngleTransmitSector::set_focus_range,
             DOC_RawRangeAndAngleTransmitSector(focus_range))
        .def("get_focus_range",
             &RawRangeAndAngleTransmitSector::get_focus_range,
             DOC_RawRangeAndAngleTransmitSector(focus_range))
        .def("set_signal_length",
             &RawRangeAndAngleTransmitSector::set_signal_length,
             DOC_RawRangeAndAngleTransmitSector(signal_length))
        .def("get_signal_length",
             &RawRangeAndAngleTransmitSector::get_signal_length,
             DOC_RawRangeAndAngleTransmitSector(signal_length))
        .def("set_sector_transmit_delay",
             &RawRangeAndAngleTransmitSector::set_sector_transmit_delay,
             DOC_RawRangeAndAngleTransmitSector(sector_transmit_delay))
        .def("get_sector_transmit_delay",
             &RawRangeAndAngleTransmitSector::get_sector_transmit_delay,
             DOC_RawRangeAndAngleTransmitSector(sector_transmit_delay))
        .def("set_center_frequency",
             &RawRangeAndAngleTransmitSector::set_center_frequency,
             DOC_RawRangeAndAngleTransmitSector(center_frequency))
        .def("get_center_frequency",
             &RawRangeAndAngleTransmitSector::get_center_frequency,
             DOC_RawRangeAndAngleTransmitSector(center_frequency))
        .def("set_mean_absorption_coefficient",
             &RawRangeAndAngleTransmitSector::set_mean_absorption_coefficient,
             DOC_RawRangeAndAngleTransmitSector(mean_absorption_coefficient))
        .def("get_mean_absorption_coefficient",
             &RawRangeAndAngleTransmitSector::get_mean_absorption_coefficient,
             DOC_RawRangeAndAngleTransmitSector(mean_absorption_coefficient))
        .def("set_signal_waveform_identifier",
             &RawRangeAndAngleTransmitSector::set_signal_waveform_identifier,
             DOC_RawRangeAndAngleTransmitSector(signal_waveform_identifier))
        .def("get_signal_waveform_identifier",
             &RawRangeAndAngleTransmitSector::get_signal_waveform_identifier,
             DOC_RawRangeAndAngleTransmitSector(signal_waveform_identifier))
        .def("set_transmit_sector_number",
             &RawRangeAndAngleTransmitSector::set_transmit_sector_number,
             DOC_RawRangeAndAngleTransmitSector(transmit_sector_number))
        .def("get_transmit_sector_number",
             &RawRangeAndAngleTransmitSector::get_transmit_sector_number,
             DOC_RawRangeAndAngleTransmitSector(transmit_sector_number))
        .def("set_signal_bandwidth",
             &RawRangeAndAngleTransmitSector::set_signal_bandwidth,
             DOC_RawRangeAndAngleTransmitSector(signal_bandwidth))
        .def("get_signal_bandwidth",
             &RawRangeAndAngleTransmitSector::get_signal_bandwidth,
             DOC_RawRangeAndAngleTransmitSector(signal_bandwidth))             
             

        // --- processed member access ---
        .def("get_tilt_angle_in_degrees",
             &RawRangeAndAngleTransmitSector::get_tilt_angle_in_degrees,
             DOC_RawRangeAndAngleTransmitSector(get_tilt_angle_in_degrees))
        .def("get_focus_range_in_m",
             &RawRangeAndAngleTransmitSector::get_focus_range_in_m,
             DOC_RawRangeAndAngleTransmitSector(get_focus_range_in_m))
        .def("get_mean_absorption_coefficient_in_dB_per_m",
             &RawRangeAndAngleTransmitSector::get_mean_absorption_coefficient_in_dB_per_m,
             DOC_RawRangeAndAngleTransmitSector(get_mean_absorption_coefficient_in_dB_per_m))
        .def("get_tx_signal_type",
             &RawRangeAndAngleTransmitSector::get_tx_signal_type,
             DOC_RawRangeAndAngleTransmitSector(get_tx_signal_type))

        // ----- operators -----
        .def("__eq__",
             &RawRangeAndAngleTransmitSector::operator==,
             DOC_RawRangeAndAngleTransmitSector(operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(RawRangeAndAngleTransmitSector)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(RawRangeAndAngleTransmitSector)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}