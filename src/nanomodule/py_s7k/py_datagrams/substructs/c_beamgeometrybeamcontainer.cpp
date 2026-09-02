// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <xtensor-python/nanobind/pytensor.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams/substructs/beamgeometrybeamcontainer.hpp>

#include "../module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::s7k;
using datagrams::substructs::BeamGeometryBeamContainer;

#define DOC_BeamGeometryBeamContainer(ARG)                                                         \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        s7k,                                                                                       \
        datagrams,                                                                                 \
        substructs,                                                                                \
        BeamGeometryBeamContainer,                                                                 \
        ARG)

void init_c_beamgeometrybeamcontainer(nanobind::module_& m)
{
    nb::class_<BeamGeometryBeamContainer>(
        m, "BeamGeometryBeamContainer", DOC_BeamGeometryBeamContainer(BeamGeometryBeamContainer))
        .def(nb::init<>(), DOC_BeamGeometryBeamContainer(BeamGeometryBeamContainer))

        .def("get_beam_vertical_angle",
             &BeamGeometryBeamContainer::get_beam_vertical_angle,
             DOC_BeamGeometryBeamContainer(get_beam_vertical_angle))
        .def("set_beam_vertical_angle",
             &BeamGeometryBeamContainer::set_beam_vertical_angle,
             DOC_BeamGeometryBeamContainer(set_beam_vertical_angle),
             nb::arg("val"))
        .def("get_beam_horizontal_angle",
             &BeamGeometryBeamContainer::get_beam_horizontal_angle,
             DOC_BeamGeometryBeamContainer(get_beam_horizontal_angle))
        .def("set_beam_horizontal_angle",
             &BeamGeometryBeamContainer::set_beam_horizontal_angle,
             DOC_BeamGeometryBeamContainer(set_beam_horizontal_angle),
             nb::arg("val"))
        .def("get_beamwidth_vertical",
             &BeamGeometryBeamContainer::get_beamwidth_vertical,
             DOC_BeamGeometryBeamContainer(get_beamwidth_vertical))
        .def("set_beamwidth_vertical",
             &BeamGeometryBeamContainer::set_beamwidth_vertical,
             DOC_BeamGeometryBeamContainer(set_beamwidth_vertical),
             nb::arg("val"))
        .def("get_beamwidth_horizontal",
             &BeamGeometryBeamContainer::get_beamwidth_horizontal,
             DOC_BeamGeometryBeamContainer(get_beamwidth_horizontal))
        .def("set_beamwidth_horizontal",
             &BeamGeometryBeamContainer::set_beamwidth_horizontal,
             DOC_BeamGeometryBeamContainer(set_beamwidth_horizontal),
             nb::arg("val"))
        .def("get_tx_delay",
             &BeamGeometryBeamContainer::get_tx_delay,
             DOC_BeamGeometryBeamContainer(get_tx_delay))
        .def("set_tx_delay",
             &BeamGeometryBeamContainer::set_tx_delay,
             DOC_BeamGeometryBeamContainer(set_tx_delay),
             nb::arg("val"))
        .def("get_has_tx_delay",
             &BeamGeometryBeamContainer::get_has_tx_delay,
             DOC_BeamGeometryBeamContainer(get_has_tx_delay))
        .def("set_has_tx_delay",
             &BeamGeometryBeamContainer::set_has_tx_delay,
             DOC_BeamGeometryBeamContainer(set_has_tx_delay),
             nb::arg("val"))

        .def("get_beam",
             &BeamGeometryBeamContainer::get_beam,
             DOC_BeamGeometryBeamContainer(get_beam),
             nb::arg("beam_index"))
        .def("get_number_of_beams",
             &BeamGeometryBeamContainer::get_number_of_beams,
             DOC_BeamGeometryBeamContainer(get_number_of_beams))

        .def("__eq__",
             &BeamGeometryBeamContainer::operator==,
             DOC_BeamGeometryBeamContainer(operator_eq),
             nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(BeamGeometryBeamContainer)
        __PYCLASS_DEFAULT_PRINTING__(BeamGeometryBeamContainer);
}

} // namespace py_datagrams
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
