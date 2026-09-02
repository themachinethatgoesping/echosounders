// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams/substructs/beamgeometrybeam.hpp>

#include "../module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::s7k;
using datagrams::substructs::BeamGeometryBeam;

#define DOC_BeamGeometryBeam(ARG)                                                                  \
    DOC(themachinethatgoesping, echosounders, s7k, datagrams, substructs, BeamGeometryBeam, ARG)

void init_c_beamgeometrybeam(nanobind::module_& m)
{
    nb::class_<BeamGeometryBeam>(m, "BeamGeometryBeam", DOC_BeamGeometryBeam(BeamGeometryBeam))
        .def(nb::init<>(), DOC_BeamGeometryBeam(BeamGeometryBeam))
        .def("get_beam_vertical_angle",
             &BeamGeometryBeam::get_beam_vertical_angle,
             DOC_BeamGeometryBeam(get_beam_vertical_angle))
        .def("set_beam_vertical_angle",
             &BeamGeometryBeam::set_beam_vertical_angle,
             DOC_BeamGeometryBeam(set_beam_vertical_angle),
             nb::arg("val"))
        .def("get_beam_horizontal_angle",
             &BeamGeometryBeam::get_beam_horizontal_angle,
             DOC_BeamGeometryBeam(get_beam_horizontal_angle))
        .def("set_beam_horizontal_angle",
             &BeamGeometryBeam::set_beam_horizontal_angle,
             DOC_BeamGeometryBeam(set_beam_horizontal_angle),
             nb::arg("val"))
        .def("get_beamwidth_vertical",
             &BeamGeometryBeam::get_beamwidth_vertical,
             DOC_BeamGeometryBeam(get_beamwidth_vertical))
        .def("set_beamwidth_vertical",
             &BeamGeometryBeam::set_beamwidth_vertical,
             DOC_BeamGeometryBeam(set_beamwidth_vertical),
             nb::arg("val"))
        .def("get_beamwidth_horizontal",
             &BeamGeometryBeam::get_beamwidth_horizontal,
             DOC_BeamGeometryBeam(get_beamwidth_horizontal))
        .def("set_beamwidth_horizontal",
             &BeamGeometryBeam::set_beamwidth_horizontal,
             DOC_BeamGeometryBeam(set_beamwidth_horizontal),
             nb::arg("val"))
        .def("get_tx_delay", &BeamGeometryBeam::get_tx_delay, DOC_BeamGeometryBeam(get_tx_delay))
        .def("set_tx_delay",
             &BeamGeometryBeam::set_tx_delay,
             DOC_BeamGeometryBeam(set_tx_delay),
             nb::arg("val"))
        .def("get_has_tx_delay",
             &BeamGeometryBeam::get_has_tx_delay,
             DOC_BeamGeometryBeam(get_has_tx_delay))
        .def("set_has_tx_delay",
             &BeamGeometryBeam::set_has_tx_delay,
             DOC_BeamGeometryBeam(set_has_tx_delay),
             nb::arg("val"))
        .def("__eq__",
             &BeamGeometryBeam::operator==,
             DOC_BeamGeometryBeam(operator_eq),
             nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(BeamGeometryBeam)
        __PYCLASS_DEFAULT_PRINTING__(BeamGeometryBeam);
}

} // namespace py_datagrams
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
