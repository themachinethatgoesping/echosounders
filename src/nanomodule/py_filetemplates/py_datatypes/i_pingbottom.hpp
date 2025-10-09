// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>
#include <nanobind/stl/variant.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/pytensor_nanobind.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datatypes/i_pingbottom.hpp"
#include "i_pingcommon.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datatypes {
namespace py_i_pingbottom {

#define DOC_I_PingBottom(ARG)                                                                     \
    DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_PingBottom, ARG)

namespace pingtools = themachinethatgoesping::echosounders::pingtools;

template<typename T_BaseClass, typename T_PyClass>
void I_PingBottom_add_interface(T_PyClass& cls)
{
    namespace nb = nanobind;

    py_i_pingcommon::I_PingCommon_add_interface<T_BaseClass>(cls);

    cls.def("has_tx_signal_parameters",
            &T_BaseClass::has_tx_signal_parameters,
            DOC_I_PingBottom(has_tx_signal_parameters));
    cls.def("has_number_of_tx_sectors",
            &T_BaseClass::has_number_of_tx_sectors,
            DOC_I_PingBottom(has_number_of_tx_sectors));
    cls.def("has_beam_numbers_per_tx_sector",
            &T_BaseClass::has_beam_numbers_per_tx_sector,
            DOC_I_PingBottom(has_beam_numbers_per_tx_sector));
    cls.def("has_beam_selection_all",
            &T_BaseClass::has_beam_selection_all,
            DOC_I_PingBottom(has_beam_selection_all));
    cls.def("has_number_of_beams",
            &T_BaseClass::has_number_of_beams,
            DOC_I_PingBottom(has_number_of_beams));
    cls.def("has_tx_sector_per_beam",
            &T_BaseClass::has_tx_sector_per_beam,
            DOC_I_PingBottom(has_tx_sector_per_beam));

    cls.def("get_tx_signal_parameters",
            &T_BaseClass::get_tx_signal_parameters,
            DOC_I_PingBottom(get_tx_signal_parameters));
    cls.def("get_number_of_tx_sectors",
            &T_BaseClass::get_number_of_tx_sectors,
            DOC_I_PingBottom(get_number_of_tx_sectors));

    cls.def("get_tx_sector_per_beam",
            nb::overload_cast<>(&T_BaseClass::get_tx_sector_per_beam),
            DOC_I_PingBottom(get_tx_sector_per_beam));
    cls.def("get_tx_sector_per_beam",
            nb::overload_cast<const pingtools::BeamSelection&>(&T_BaseClass::get_tx_sector_per_beam),
            DOC_I_PingBottom(get_tx_sector_per_beam),
            nb::arg("beam_selection"));

    cls.def("get_beam_numbers_per_tx_sector",
            nb::overload_cast<>(&T_BaseClass::get_beam_numbers_per_tx_sector),
            DOC_I_PingBottom(get_beam_numbers_per_tx_sector));
    cls.def("get_beam_numbers_per_tx_sector",
            nb::overload_cast<const pingtools::BeamSelection&>(&T_BaseClass::get_beam_numbers_per_tx_sector),
            DOC_I_PingBottom(get_beam_numbers_per_tx_sector),
            nb::arg("beam_selection"));

    cls.def("get_beam_selection_all",
            nb::overload_cast<>(&T_BaseClass::get_beam_selection_all),
            DOC_I_PingBottom(get_beam_selection_all));
    cls.def("get_number_of_beams",
            &T_BaseClass::get_number_of_beams,
            DOC_I_PingBottom(get_number_of_beams));

    cls.def("get_beam_crosstrack_angles",
            nb::overload_cast<>(&T_BaseClass::get_beam_crosstrack_angles),
            DOC_I_PingBottom(get_beam_crosstrack_angles));
    cls.def("get_beam_crosstrack_angles",
            nb::overload_cast<const pingtools::BeamSelection&>(&T_BaseClass::get_beam_crosstrack_angles),
            DOC_I_PingBottom(get_beam_crosstrack_angles),
            nb::arg("beam_selection"));

    cls.def("has_beam_crosstrack_angles",
            nb::overload_cast<>(&T_BaseClass::has_beam_crosstrack_angles, nb::const_),
            DOC_I_PingBottom(has_beam_crosstrack_angles));
    cls.def("has_xyz",
            nb::overload_cast<>(&T_BaseClass::has_xyz, nb::const_),
            DOC_I_PingBottom(has_xyz));
    cls.def("has_two_way_travel_times",
            nb::overload_cast<>(&T_BaseClass::has_two_way_travel_times, nb::const_),
            DOC_I_PingBottom(has_two_way_travel_times));

    cls.def("get_xyz",
            nb::overload_cast<>(&T_BaseClass::get_xyz),
            DOC_I_PingBottom(get_xyz));
    cls.def("get_xyz",
            nb::overload_cast<const pingtools::BeamSelection&>(&T_BaseClass::get_xyz),
            DOC_I_PingBottom(get_xyz_2),
            nb::arg("beam_selection"));

    cls.def("get_bottom_z",
            nb::overload_cast<>(&T_BaseClass::get_bottom_z),
            DOC_I_PingBottom(get_bottom_z));
    cls.def("get_bottom_z",
            nb::overload_cast<const pingtools::BeamSelection&>(&T_BaseClass::get_bottom_z),
            DOC_I_PingBottom(get_bottom_z_2),
            nb::arg("beam_selection"));

    cls.def("get_two_way_travel_times",
            nb::overload_cast<>(&T_BaseClass::get_two_way_travel_times),
            DOC_I_PingBottom(get_two_way_travel_times));
    cls.def("get_two_way_travel_times",
            nb::overload_cast<const pingtools::BeamSelection&>(&T_BaseClass::get_two_way_travel_times),
            DOC_I_PingBottom(get_two_way_travel_times),
            nb::arg("beam_selection"));
}

}
}
}
}
}
}
