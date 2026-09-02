// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/variant.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <xtensor-python/nanobind/pytensor.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams/substructs/snippetdataamplitudes.hpp>

#include "../module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::s7k;
using datagrams::substructs::SnippetDataAmplitudes;

#define DOC_SnippetDataAmplitudes(ARG)                                                             \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        s7k,                                                                                       \
        datagrams,                                                                                 \
        substructs,                                                                                \
        SnippetDataAmplitudes,                                                                     \
        ARG)

void init_c_snippetdataamplitudes(nanobind::module_& m)
{
    nb::class_<SnippetDataAmplitudes>(
        m, "SnippetDataAmplitudes", DOC_SnippetDataAmplitudes(SnippetDataAmplitudes))
        .def(nb::init<>(), DOC_SnippetDataAmplitudes(SnippetDataAmplitudes))

        // ----- meta data access -----
        .def("get_samples_are_32bit",
             &SnippetDataAmplitudes::get_samples_are_32bit,
             DOC_SnippetDataAmplitudes(get_samples_are_32bit))
        .def("get_number_of_beams",
             &SnippetDataAmplitudes::get_number_of_beams,
             DOC_SnippetDataAmplitudes(get_number_of_beams))
        .def("get_total_number_of_samples",
             &SnippetDataAmplitudes::get_total_number_of_samples,
             DOC_SnippetDataAmplitudes(get_total_number_of_samples))
        .def("get_samples_are_skipped",
             &SnippetDataAmplitudes::get_samples_are_skipped,
             DOC_SnippetDataAmplitudes(get_samples_are_skipped))
        .def("get_sample_position",
             &SnippetDataAmplitudes::get_sample_position,
             DOC_SnippetDataAmplitudes(get_sample_position))

        // ----- raw sample access -----
        .def("get_samples",
             &SnippetDataAmplitudes::get_samples,
             DOC_SnippetDataAmplitudes(get_samples))
        .def("get_beam_offsets",
             &SnippetDataAmplitudes::get_beam_offsets,
             DOC_SnippetDataAmplitudes(get_beam_offsets))

        // ----- per-beam / processed access -----
        .def("get_beam",
             &SnippetDataAmplitudes::get_beam,
             DOC_SnippetDataAmplitudes(get_beam),
             nb::arg("beam_index"))
        .def("get_beams",
             &SnippetDataAmplitudes::get_beams,
             "intensity samples of all beams as a list of arrays (one per beam, as float)")
        .def("get_beam_in_db",
             &SnippetDataAmplitudes::get_beam_in_db,
             DOC_SnippetDataAmplitudes(get_beam_in_db),
             nb::arg("beam_index"),
             nb::arg("db_offset") = 0.f)
        .def("get_beams_in_db",
             &SnippetDataAmplitudes::get_beams_in_db,
             "intensity samples of all beams in relative dB (20*log10(amplitude) + db_offset), one "
             "array per beam",
             nb::arg("db_offset") = 0.f)

        // ----- setters -----
        .def("set_samples",
             &SnippetDataAmplitudes::set_samples,
             DOC_SnippetDataAmplitudes(set_samples),
             nb::arg("samples"))
        .def("set_beam_offsets",
             &SnippetDataAmplitudes::set_beam_offsets,
             DOC_SnippetDataAmplitudes(set_beam_offsets),
             nb::arg("beam_offsets"))

        .def("__eq__",
             &SnippetDataAmplitudes::operator==,
             DOC_SnippetDataAmplitudes(operator_eq),
             nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(SnippetDataAmplitudes)
        __PYCLASS_DEFAULT_PRINTING__(SnippetDataAmplitudes);
}

} // namespace py_datagrams
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
