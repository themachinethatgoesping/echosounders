// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>
#include <xtensor-python/pyarray.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/filetemplates/datatypes/i_pingbottom.hpp"
//

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_filetemplates {
namespace py_datatypes {

#define DOC_I_PingBottom(ARG)                                                                      \
    DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_PingBottom, ARG)

void init_c_i_pingbottom(pybind11::module& m)
{
    namespace py = pybind11;
    using namespace themachinethatgoesping::echosounders::filetemplates::datatypes;

    auto cls =
        py::class_<I_PingBottom, I_PingCommon, std::shared_ptr<I_PingBottom>>(
            m,
            "I_PingBottom",
            DOC(themachinethatgoesping, echosounders, filetemplates, datatypes, I_PingBottom))

            // ----- sector information -----
            .def("get_tx_sector_per_beam",
                 py::overload_cast<>(&I_PingBottom::get_tx_sector_per_beam),
                 DOC_I_PingBottom(get_tx_sector_per_beam))
            .def("get_beam_numbers_per_tx_sector",
                 py::overload_cast<>(&I_PingBottom::get_beam_numbers_per_tx_sector),
                 DOC_I_PingBottom(get_beam_numbers_per_tx_sector))

            // ---- pingbottom interface ----
            .def("get_beam_selection_all",
                 py::overload_cast<>(&I_PingBottom::get_beam_selection_all),
                 DOC_I_PingBottom(get_beam_selection_all))

            .def("get_number_of_beams",
                 &I_PingBottom::get_number_of_beams,
                 DOC_I_PingBottom(get_number_of_beams))
            .def("get_beam_crosstrack_angles",
                 py::overload_cast<>(&I_PingBottom::get_beam_crosstrack_angles),
                 DOC_I_PingBottom(get_beam_crosstrack_angles))
            .def("get_beam_crosstrack_angles",
                 py::overload_cast<const pingtools::BeamSelection&>(
                     &I_PingBottom::get_beam_crosstrack_angles),
                 DOC_I_PingBottom(get_beam_crosstrack_angles),
                 py::arg("beam_selection"))

            // ----- features -----
            .def("has_beam_crosstrack_angles",
                 py::overload_cast<>(&I_PingBottom::has_beam_crosstrack_angles, py::const_),
                 DOC_I_PingBottom(has_beam_crosstrack_angles))
            .def("has_xyz",
                 py::overload_cast<>(&I_PingBottom::has_xyz, py::const_),
                 DOC_I_PingBottom(has_xyz))
            .def("has_two_way_travel_times",
                 py::overload_cast<>(&I_PingBottom::has_two_way_travel_times, py::const_),
                 DOC_I_PingBottom(has_two_way_travel_times))

            .def("get_xyz", py::overload_cast<>(&I_PingBottom::get_xyz), DOC_I_PingBottom(get_xyz))
            .def("get_xyz",
                 py::overload_cast<const pingtools::BeamSelection&>(&I_PingBottom::get_xyz),
                 DOC_I_PingBottom(get_xyz_2),
                 py::arg("beam_selection"))

            .def("get_two_way_travel_times",
                 py::overload_cast<>(&I_PingBottom::get_two_way_travel_times),
                 DOC_I_PingBottom(get_two_way_travel_times))
            .def("get_two_way_travel_times",
                 py::overload_cast<const pingtools::BeamSelection&>(
                     &I_PingBottom::get_two_way_travel_times),
                 DOC_I_PingBottom(get_two_way_travel_times),
                 py::arg("beam_selection"))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(I_PingBottom)
        // default printing functions
        // cls __PYCLASS_DEFAULT_PRINTING__(I_PingBottom);
        ;
}

}
}
}
}
}