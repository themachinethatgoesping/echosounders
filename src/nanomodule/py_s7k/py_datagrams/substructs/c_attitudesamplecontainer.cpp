// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <xtensor-python/nanobind/pytensor.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams/substructs/attitudesamplecontainer.hpp>

#include "../module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::s7k;
using datagrams::substructs::AttitudeSampleContainer;

#define DOC_AttitudeSampleContainer(ARG)                                                           \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        s7k,                                                                                       \
        datagrams,                                                                                 \
        substructs,                                                                                \
        AttitudeSampleContainer,                                                                   \
        ARG)

void init_c_attitudesamplecontainer(nanobind::module_& m)
{
    nb::class_<AttitudeSampleContainer>(
        m, "AttitudeSampleContainer", DOC_AttitudeSampleContainer(AttitudeSampleContainer))
        .def(nb::init<>(), DOC_AttitudeSampleContainer(AttitudeSampleContainer))

        .def_prop_rw("samples",
                     &AttitudeSampleContainer::samples,
                     &AttitudeSampleContainer::set_samples,
                     DOC_AttitudeSampleContainer(samples),
                     nb::rv_policy::reference_internal)

        .def("get_delta_time_tensor",
             &AttitudeSampleContainer::get_delta_time_tensor,
             DOC_AttitudeSampleContainer(get_delta_time_tensor))
        .def("get_roll_tensor",
             &AttitudeSampleContainer::get_roll_tensor,
             DOC_AttitudeSampleContainer(get_roll_tensor))
        .def("get_pitch_tensor",
             &AttitudeSampleContainer::get_pitch_tensor,
             DOC_AttitudeSampleContainer(get_pitch_tensor))
        .def("get_heave_tensor",
             &AttitudeSampleContainer::get_heave_tensor,
             DOC_AttitudeSampleContainer(get_heave_tensor))
        .def("get_heading_tensor",
             &AttitudeSampleContainer::get_heading_tensor,
             DOC_AttitudeSampleContainer(get_heading_tensor))

        .def("get_number_of_samples",
             &AttitudeSampleContainer::get_number_of_samples,
             DOC_AttitudeSampleContainer(get_number_of_samples))

        .def("__eq__",
             &AttitudeSampleContainer::operator==,
             DOC_AttitudeSampleContainer(operator_eq),
             nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(AttitudeSampleContainer)
        __PYCLASS_DEFAULT_PRINTING__(AttitudeSampleContainer);
}

} // namespace py_datagrams
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
