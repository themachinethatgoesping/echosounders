// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/bind_vector.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams/substructs/compressedwatercolumnbeam.hpp>

#include "../module.hpp"

NB_MAKE_OPAQUE(std::vector<
               themachinethatgoesping::echosounders::s7k::datagrams::substructs::CompressedWaterColumnBeam>);

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::s7k;
using datagrams::substructs::CompressedWaterColumnBeam;

#define DOC_CompressedWaterColumnBeam(ARG)                                                         \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        s7k,                                                                                       \
        datagrams,                                                                                 \
        substructs,                                                                                \
        CompressedWaterColumnBeam,                                                                 \
        ARG)

void init_c_compressedwatercolumnbeam(nanobind::module_& m)
{
    nb::class_<CompressedWaterColumnBeam>(
        m, "CompressedWaterColumnBeam", DOC_CompressedWaterColumnBeam(CompressedWaterColumnBeam))
        .def(nb::init<>(), DOC_CompressedWaterColumnBeam(CompressedWaterColumnBeam))
        .def("get_beam_number",
             &CompressedWaterColumnBeam::get_beam_number,
             DOC_CompressedWaterColumnBeam(get_beam_number))
        .def("set_beam_number",
             &CompressedWaterColumnBeam::set_beam_number,
             DOC_CompressedWaterColumnBeam(set_beam_number),
             nb::arg("val"))
        .def("get_segment_number",
             &CompressedWaterColumnBeam::get_segment_number,
             DOC_CompressedWaterColumnBeam(get_segment_number))
        .def("set_segment_number",
             &CompressedWaterColumnBeam::set_segment_number,
             DOC_CompressedWaterColumnBeam(set_segment_number),
             nb::arg("val"))
        .def("get_sample_count",
             &CompressedWaterColumnBeam::get_sample_count,
             DOC_CompressedWaterColumnBeam(get_sample_count))
        .def("set_sample_count",
             &CompressedWaterColumnBeam::set_sample_count,
             DOC_CompressedWaterColumnBeam(set_sample_count),
             nb::arg("val"))
        .def(
            "get_raw_samples",
            [](const CompressedWaterColumnBeam& self) {
                const std::string& raw = self.get_raw_samples();
                return nb::bytes(raw.data(), raw.size());
            },
            DOC_CompressedWaterColumnBeam(get_raw_samples))
        .def(
            "set_raw_samples",
            [](CompressedWaterColumnBeam& self, nb::bytes raw_samples) {
                self.set_raw_samples(std::string(raw_samples.c_str(), raw_samples.size()));
            },
            DOC_CompressedWaterColumnBeam(set_raw_samples),
            nb::arg("raw_samples"))
        .def("__eq__",
             &CompressedWaterColumnBeam::operator==,
             DOC_CompressedWaterColumnBeam(operator_eq),
             nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(CompressedWaterColumnBeam)
        __PYCLASS_DEFAULT_PRINTING__(CompressedWaterColumnBeam);

    nb::bind_vector<std::vector<CompressedWaterColumnBeam>>(m,
                                                            "CompressedWaterColumnBeams_vector");
}

} // namespace py_datagrams
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
