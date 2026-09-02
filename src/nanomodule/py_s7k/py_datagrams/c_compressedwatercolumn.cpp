// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <xtensor-python/nanobind/pytensor.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams/compressedwatercolumn.hpp>

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

void init_c_compressedwatercolumn(nb::module_& m)
{
    nb::class_<CompressedWaterColumn, S7KDatagram>(
        m,
        "CompressedWaterColumn",
        DOC(themachinethatgoesping, echosounders, s7k, datagrams, CompressedWaterColumn))
        .def(nb::init<>(), DOC_C(CompressedWaterColumn, CompressedWaterColumn))
        .def("get_serial_number", &CompressedWaterColumn::get_serial_number, DOC_C(CompressedWaterColumn, Content, serial_number))
        .def("set_serial_number", &CompressedWaterColumn::set_serial_number, DOC_C(CompressedWaterColumn, Content, serial_number), nb::arg("val"))
        .def("get_ping_number", &CompressedWaterColumn::get_ping_number, DOC_C(CompressedWaterColumn, Content, ping_number))
        .def("set_ping_number", &CompressedWaterColumn::set_ping_number, DOC_C(CompressedWaterColumn, Content, ping_number), nb::arg("val"))
        .def("get_multi_ping", &CompressedWaterColumn::get_multi_ping, DOC_C(CompressedWaterColumn, Content, multi_ping))
        .def("set_multi_ping", &CompressedWaterColumn::set_multi_ping, DOC_C(CompressedWaterColumn, Content, multi_ping), nb::arg("val"))
        .def("get_number_beams", &CompressedWaterColumn::get_number_beams, DOC_C(CompressedWaterColumn, Content, number_beams))
        .def("set_number_beams", &CompressedWaterColumn::set_number_beams, DOC_C(CompressedWaterColumn, Content, number_beams), nb::arg("val"))
        .def("get_samples", &CompressedWaterColumn::get_samples, DOC_C(CompressedWaterColumn, Content, samples))
        .def("set_samples", &CompressedWaterColumn::set_samples, DOC_C(CompressedWaterColumn, Content, samples), nb::arg("val"))
        .def("get_compressed_samples", &CompressedWaterColumn::get_compressed_samples, DOC_C(CompressedWaterColumn, Content, compressed_samples))
        .def("set_compressed_samples", &CompressedWaterColumn::set_compressed_samples, DOC_C(CompressedWaterColumn, Content, compressed_samples), nb::arg("val"))
        .def("get_flags", &CompressedWaterColumn::get_flags, DOC_C(CompressedWaterColumn, Content, flags))
        .def("set_flags", &CompressedWaterColumn::set_flags, DOC_C(CompressedWaterColumn, Content, flags), nb::arg("val"))
        .def("get_first_sample", &CompressedWaterColumn::get_first_sample, DOC_C(CompressedWaterColumn, Content, first_sample))
        .def("set_first_sample", &CompressedWaterColumn::set_first_sample, DOC_C(CompressedWaterColumn, Content, first_sample), nb::arg("val"))
        .def("get_sample_rate", &CompressedWaterColumn::get_sample_rate, DOC_C(CompressedWaterColumn, Content, sample_rate))
        .def("set_sample_rate", &CompressedWaterColumn::set_sample_rate, DOC_C(CompressedWaterColumn, Content, sample_rate), nb::arg("val"))
        .def("get_compression_factor", &CompressedWaterColumn::get_compression_factor, DOC_C(CompressedWaterColumn, Content, compression_factor))
        .def("set_compression_factor", &CompressedWaterColumn::set_compression_factor, DOC_C(CompressedWaterColumn, Content, compression_factor), nb::arg("val"))
        .def("get_has_phase", &CompressedWaterColumn::get_has_phase, DOC_C(CompressedWaterColumn, get_has_phase))
        .def("get_magnitude_is_db", &CompressedWaterColumn::get_magnitude_is_db, DOC_C(CompressedWaterColumn, get_magnitude_is_db))
        .def("get_magnitude_bytes", &CompressedWaterColumn::get_magnitude_bytes, DOC_C(CompressedWaterColumn, get_magnitude_bytes))
        .def_prop_rw("beams",
                     &CompressedWaterColumn::beams,
                     &CompressedWaterColumn::set_beams,
                     DOC_C(CompressedWaterColumn, beams),
                     nb::rv_policy::reference_internal)
        .def("__eq__", &CompressedWaterColumn::operator==, nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(CompressedWaterColumn)
        __PYCLASS_DEFAULT_BINARY__(CompressedWaterColumn)
        __PYCLASS_DEFAULT_PRINTING__(CompressedWaterColumn);
}

} // namespace py_datagrams
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
