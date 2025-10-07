// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/pytensor_nanobind.hpp>
#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "../../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/substructures/sampleamplitudesstructure.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {
namespace py_substructures {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::substructures::SampleAmplitudesStructure;

#define DOC_SampleAmplitudesStructure(ARG)                                                         \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        kongsbergall,                                                                              \
        datagrams,                                                                                 \
        substructures,                                                                             \
        SampleAmplitudesStructure,                                                                 \
        ARG)

template<typename t_sample>
void init_c_sampleamplitudesstructure_per_sample_type(std::string_view name, nanobind::module_& m)
{
     nb::class_<SampleAmplitudesStructure<t_sample>>(m,
                                                    name.data(),
                                                    DOC(themachinethatgoesping,
                                                        echosounders,
                                                        kongsbergall,
                                                        datagrams,
                                                        substructures,
                                                        SampleAmplitudesStructure))
     .def(nb::init<>(), DOC_SampleAmplitudesStructure(SampleAmplitudesStructure))
        // --- convenient data access ---
        .def("set_sample_amplitudes",
             &SampleAmplitudesStructure<t_sample>::set_sample_amplitudes,
             DOC_SampleAmplitudesStructure(sample_amplitudes))
        .def("get_sample_amplitudes",
             &SampleAmplitudesStructure<t_sample>::get_sample_amplitudes,
             DOC_SampleAmplitudesStructure(sample_amplitudes),
             nb::rv_policy::reference_internal)
        .def("set_start_index_per_beam",
             &SampleAmplitudesStructure<t_sample>::set_start_index_per_beam,
             DOC_SampleAmplitudesStructure(start_index_per_beam))
        .def("get_start_index_per_beam",
             &SampleAmplitudesStructure<t_sample>::get_start_index_per_beam,
             DOC_SampleAmplitudesStructure(start_index_per_beam),
             nb::rv_policy::reference_internal)
        .def("set_samples_per_beam",
             &SampleAmplitudesStructure<t_sample>::set_samples_per_beam,
             DOC_SampleAmplitudesStructure(samples_per_beam))
        .def("get_samples_per_beam",
             &SampleAmplitudesStructure<t_sample>::get_samples_per_beam,
             DOC_SampleAmplitudesStructure(samples_per_beam),
             nb::rv_policy::reference_internal)

        // ----- convenient getters -----
        .def("get_sample_amplitudes_in_db",
             &SampleAmplitudesStructure<t_sample>::get_sample_amplitudes_in_db,
             DOC_SampleAmplitudesStructure(get_sample_amplitudes_in_db))
        .def("get_beam",
             &SampleAmplitudesStructure<t_sample>::get_beam,
             DOC_SampleAmplitudesStructure(get_beam))
        .def("get_beam_in_db",
             &SampleAmplitudesStructure<t_sample>::get_beam_in_db,
             DOC_SampleAmplitudesStructure(get_beam_in_db))
        .def("get_sample_amplitudes_per_beam",
             &SampleAmplitudesStructure<t_sample>::get_sample_amplitudes_per_beam,
             DOC_SampleAmplitudesStructure(get_sample_amplitudes_per_beam),
             nb::arg("mp_cores") = 1)
        .def("get_sample_amplitudes_per_beam_in_db",
             &SampleAmplitudesStructure<t_sample>::get_sample_amplitudes_per_beam_in_db,
             DOC_SampleAmplitudesStructure(get_sample_amplitudes_per_beam_in_db),
             nb::arg("mp_cores") = 1)

        // ----- container functions -----
        .def("size",
             nb::overload_cast<>(&SampleAmplitudesStructure<t_sample>::size, nb::const_),
             DOC_SampleAmplitudesStructure(size))
        .def("size",
             nb::overload_cast<size_t>(&SampleAmplitudesStructure<t_sample>::size, nb::const_),
             DOC_SampleAmplitudesStructure(size_2),
             nb::arg("beam_index"))

        // ----- operators -----
        .def("__eq__",
             &SampleAmplitudesStructure<t_sample>::operator==,
             DOC_SampleAmplitudesStructure(operator_eq),
             nb::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(SampleAmplitudesStructure<t_sample>)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(SampleAmplitudesStructure<t_sample>)
        // default binary function
        ;
}

void init_c_sampleamplitudesstructure(nanobind::module_& m)

{
    init_c_sampleamplitudesstructure_per_sample_type<int16_t>("SampleAmplitudesStructure_int16_t",
                                                              m);
}

} // namespace py_substructures
} // namespace py_datagrams
} // namespace py_kongsbergall
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping