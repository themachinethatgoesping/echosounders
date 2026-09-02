// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <xtensor-python/nanobind/pytensor.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams/substructs/snippetdatabeamcontainer.hpp>

#include "../module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::s7k;
using datagrams::substructs::SnippetDataBeamContainer;

#define DOC_SnippetDataBeamContainer(ARG)                                                          \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        s7k,                                                                                       \
        datagrams,                                                                                 \
        substructs,                                                                                \
        SnippetDataBeamContainer,                                                                  \
        ARG)

void init_c_snippetdatabeamcontainer(nanobind::module_& m)
{
    nb::class_<SnippetDataBeamContainer>(
        m, "SnippetDataBeamContainer", DOC_SnippetDataBeamContainer(SnippetDataBeamContainer))
        .def(nb::init<>(), DOC_SnippetDataBeamContainer(SnippetDataBeamContainer))

        .def_prop_rw("beams",
                     &SnippetDataBeamContainer::beams,
                     &SnippetDataBeamContainer::set_beams,
                     DOC_SnippetDataBeamContainer(beams),
                     nb::rv_policy::reference_internal)

        .def("get_beam_descriptor_tensor",
             &SnippetDataBeamContainer::get_beam_descriptor_tensor,
             DOC_SnippetDataBeamContainer(get_beam_descriptor_tensor))
        .def("get_snippet_start_tensor",
             &SnippetDataBeamContainer::get_snippet_start_tensor,
             DOC_SnippetDataBeamContainer(get_snippet_start_tensor))
        .def("get_detection_sample_tensor",
             &SnippetDataBeamContainer::get_detection_sample_tensor,
             DOC_SnippetDataBeamContainer(get_detection_sample_tensor))
        .def("get_snippet_end_tensor",
             &SnippetDataBeamContainer::get_snippet_end_tensor,
             DOC_SnippetDataBeamContainer(get_snippet_end_tensor))
        .def("get_number_of_samples_tensor",
             &SnippetDataBeamContainer::get_number_of_samples_tensor,
             DOC_SnippetDataBeamContainer(get_number_of_samples_tensor))

        .def("get_number_of_beams",
             &SnippetDataBeamContainer::get_number_of_beams,
             DOC_SnippetDataBeamContainer(get_number_of_beams))
        .def("get_total_number_of_samples",
             &SnippetDataBeamContainer::get_total_number_of_samples,
             DOC_SnippetDataBeamContainer(get_total_number_of_samples))

        .def("__eq__",
             &SnippetDataBeamContainer::operator==,
             DOC_SnippetDataBeamContainer(operator_eq),
             nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(SnippetDataBeamContainer)
        __PYCLASS_DEFAULT_PRINTING__(SnippetDataBeamContainer);
}

} // namespace py_datagrams
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
