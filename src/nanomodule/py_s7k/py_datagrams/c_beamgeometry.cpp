// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <xtensor-python/nanobind/pytensor.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams/beamgeometry.hpp>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_datagrams {
namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::s7k;
using namespace themachinethatgoesping::echosounders::s7k::datagrams;

#define DOC_C(CLASS, ...) DOC(themachinethatgoesping, echosounders, s7k, datagrams, CLASS, __VA_ARGS__)

void init_c_beamgeometry(nb::module_& m)
{
    nb::class_<BeamGeometry, S7KDatagram>(
        m, "BeamGeometry", DOC(themachinethatgoesping, echosounders, s7k, datagrams, BeamGeometry))
        .def(nb::init<>(), DOC_C(BeamGeometry, BeamGeometry))
        .def("get_serial_number", &BeamGeometry::get_serial_number, DOC_C(BeamGeometry, Content, serial_number))
        .def("set_serial_number", &BeamGeometry::set_serial_number, DOC_C(BeamGeometry, Content, serial_number), nb::arg("val"))
        .def("get_number_beams", &BeamGeometry::get_number_beams, DOC_C(BeamGeometry, Content, number_beams))
        .def("set_number_beams", &BeamGeometry::set_number_beams, DOC_C(BeamGeometry, Content, number_beams), nb::arg("val"))
        .def_prop_rw("beams",
                     &BeamGeometry::beams,
                     &BeamGeometry::set_beams,
                     DOC_C(BeamGeometry, beams),
                     nb::rv_policy::reference_internal)
        .def("__eq__", &BeamGeometry::operator==, nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(BeamGeometry)
        __PYCLASS_DEFAULT_BINARY__(BeamGeometry)
        __PYCLASS_DEFAULT_PRINTING__(BeamGeometry);
}

} // namespace py_datagrams
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
