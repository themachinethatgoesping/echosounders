// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/bind_vector.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams/substructs/rawdetectionbeam.hpp>

#include "../module.hpp"

NB_MAKE_OPAQUE(
    std::vector<themachinethatgoesping::echosounders::s7k::datagrams::substructs::RawDetectionBeam>);

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::s7k;
using datagrams::substructs::RawDetectionBeam;

#define DOC_RawDetectionBeam(ARG)                                                                  \
    DOC(themachinethatgoesping, echosounders, s7k, datagrams, substructs, RawDetectionBeam, ARG)

void init_c_rawdetectionbeam(nanobind::module_& m)
{
    nb::class_<RawDetectionBeam>(m, "RawDetectionBeam", DOC_RawDetectionBeam(RawDetectionBeam))
        .def(nb::init<>(), DOC_RawDetectionBeam(RawDetectionBeam))
        .def("get_beam_descriptor",
             &RawDetectionBeam::get_beam_descriptor,
             DOC_RawDetectionBeam(get_beam_descriptor))
        .def("set_beam_descriptor",
             &RawDetectionBeam::set_beam_descriptor,
             DOC_RawDetectionBeam(set_beam_descriptor),
             nb::arg("val"))
        .def("get_detection_point",
             &RawDetectionBeam::get_detection_point,
             DOC_RawDetectionBeam(get_detection_point))
        .def("set_detection_point",
             &RawDetectionBeam::set_detection_point,
             DOC_RawDetectionBeam(set_detection_point),
             nb::arg("val"))
        .def("get_rx_angle", &RawDetectionBeam::get_rx_angle, DOC_RawDetectionBeam(get_rx_angle))
        .def("set_rx_angle",
             &RawDetectionBeam::set_rx_angle,
             DOC_RawDetectionBeam(set_rx_angle),
             nb::arg("val"))
        .def("get_flags", &RawDetectionBeam::get_flags, DOC_RawDetectionBeam(get_flags))
        .def("set_flags",
             &RawDetectionBeam::set_flags,
             DOC_RawDetectionBeam(set_flags),
             nb::arg("val"))
        .def("get_quality", &RawDetectionBeam::get_quality, DOC_RawDetectionBeam(get_quality))
        .def("set_quality",
             &RawDetectionBeam::set_quality,
             DOC_RawDetectionBeam(set_quality),
             nb::arg("val"))
        .def("get_uncertainty",
             &RawDetectionBeam::get_uncertainty,
             DOC_RawDetectionBeam(get_uncertainty))
        .def("set_uncertainty",
             &RawDetectionBeam::set_uncertainty,
             DOC_RawDetectionBeam(set_uncertainty),
             nb::arg("val"))
        .def("get_signal_strength",
             &RawDetectionBeam::get_signal_strength,
             DOC_RawDetectionBeam(get_signal_strength))
        .def("set_signal_strength",
             &RawDetectionBeam::set_signal_strength,
             DOC_RawDetectionBeam(set_signal_strength),
             nb::arg("val"))
        .def("get_min_limit", &RawDetectionBeam::get_min_limit, DOC_RawDetectionBeam(get_min_limit))
        .def("set_min_limit",
             &RawDetectionBeam::set_min_limit,
             DOC_RawDetectionBeam(set_min_limit),
             nb::arg("val"))
        .def("get_max_limit", &RawDetectionBeam::get_max_limit, DOC_RawDetectionBeam(get_max_limit))
        .def("set_max_limit",
             &RawDetectionBeam::set_max_limit,
             DOC_RawDetectionBeam(set_max_limit),
             nb::arg("val"))
        .def("__eq__",
             &RawDetectionBeam::operator==,
             DOC_RawDetectionBeam(operator_eq),
             nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(RawDetectionBeam)
        __PYCLASS_DEFAULT_PRINTING__(RawDetectionBeam);

    nb::bind_vector<std::vector<RawDetectionBeam>>(m, "RawDetectionBeams_vector");
}

} // namespace py_datagrams
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
