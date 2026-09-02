// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <xtensor-python/nanobind/pytensor.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams/substructs/rawdetectionbeamcontainer.hpp>

#include "../module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::s7k;
using datagrams::substructs::RawDetectionBeamContainer;

#define DOC_RawDetectionBeamContainer(ARG)                                                         \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        s7k,                                                                                       \
        datagrams,                                                                                 \
        substructs,                                                                                \
        RawDetectionBeamContainer,                                                                 \
        ARG)

void init_c_rawdetectionbeamcontainer(nanobind::module_& m)
{
    nb::class_<RawDetectionBeamContainer>(
        m, "RawDetectionBeamContainer", DOC_RawDetectionBeamContainer(RawDetectionBeamContainer))
        .def(nb::init<>(), DOC_RawDetectionBeamContainer(RawDetectionBeamContainer))

        .def_prop_rw("beams",
                     &RawDetectionBeamContainer::beams,
                     &RawDetectionBeamContainer::set_beams,
                     DOC_RawDetectionBeamContainer(beams),
                     nb::rv_policy::reference_internal)

        .def("get_beam_descriptor_tensor",
             &RawDetectionBeamContainer::get_beam_descriptor_tensor,
             DOC_RawDetectionBeamContainer(get_beam_descriptor_tensor))
        .def("get_detection_point_tensor",
             &RawDetectionBeamContainer::get_detection_point_tensor,
             DOC_RawDetectionBeamContainer(get_detection_point_tensor))
        .def("get_rx_angle_tensor",
             &RawDetectionBeamContainer::get_rx_angle_tensor,
             DOC_RawDetectionBeamContainer(get_rx_angle_tensor))
        .def("get_flags_tensor",
             &RawDetectionBeamContainer::get_flags_tensor,
             DOC_RawDetectionBeamContainer(get_flags_tensor))
        .def("get_quality_tensor",
             &RawDetectionBeamContainer::get_quality_tensor,
             DOC_RawDetectionBeamContainer(get_quality_tensor))
        .def("get_uncertainty_tensor",
             &RawDetectionBeamContainer::get_uncertainty_tensor,
             DOC_RawDetectionBeamContainer(get_uncertainty_tensor))
        .def("get_signal_strength_tensor",
             &RawDetectionBeamContainer::get_signal_strength_tensor,
             DOC_RawDetectionBeamContainer(get_signal_strength_tensor))
        .def("get_min_limit_tensor",
             &RawDetectionBeamContainer::get_min_limit_tensor,
             DOC_RawDetectionBeamContainer(get_min_limit_tensor))
        .def("get_max_limit_tensor",
             &RawDetectionBeamContainer::get_max_limit_tensor,
             DOC_RawDetectionBeamContainer(get_max_limit_tensor))

        .def("get_number_of_beams",
             &RawDetectionBeamContainer::get_number_of_beams,
             DOC_RawDetectionBeamContainer(get_number_of_beams))

        .def("__eq__",
             &RawDetectionBeamContainer::operator==,
             DOC_RawDetectionBeamContainer(operator_eq),
             nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(RawDetectionBeamContainer)
        __PYCLASS_DEFAULT_PRINTING__(RawDetectionBeamContainer);
}

} // namespace py_datagrams
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
