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
        .def("get_ping_number", &CompressedWaterColumn::get_ping_number, DOC_C(CompressedWaterColumn, Content, ping_number))
        .def("get_multi_ping", &CompressedWaterColumn::get_multi_ping, DOC_C(CompressedWaterColumn, Content, multi_ping))
        .def("get_number_beams", &CompressedWaterColumn::get_number_beams, DOC_C(CompressedWaterColumn, Content, number_beams))
        .def("get_samples", &CompressedWaterColumn::get_samples, DOC_C(CompressedWaterColumn, Content, samples))
        .def("get_compressed_samples", &CompressedWaterColumn::get_compressed_samples, DOC_C(CompressedWaterColumn, Content, compressed_samples))
        .def("get_flags", &CompressedWaterColumn::get_flags, DOC_C(CompressedWaterColumn, Content, flags))
        .def("get_first_sample", &CompressedWaterColumn::get_first_sample, DOC_C(CompressedWaterColumn, Content, first_sample))
        .def("get_sample_rate", &CompressedWaterColumn::get_sample_rate, DOC_C(CompressedWaterColumn, Content, sample_rate))
        .def("get_compression_factor", &CompressedWaterColumn::get_compression_factor, DOC_C(CompressedWaterColumn, Content, compression_factor))
        .def("get_has_phase", &CompressedWaterColumn::get_has_phase, DOC_C(CompressedWaterColumn, get_has_phase))
        .def("get_magnitude_is_db", &CompressedWaterColumn::get_magnitude_is_db, DOC_C(CompressedWaterColumn, get_magnitude_is_db))
        .def("get_magnitude_bytes", &CompressedWaterColumn::get_magnitude_bytes, DOC_C(CompressedWaterColumn, get_magnitude_bytes))
        .def("get_beam_number", &CompressedWaterColumn::get_beam_number, DOC_C(CompressedWaterColumn, get_beam_number))
        .def("get_segment_number", &CompressedWaterColumn::get_segment_number, DOC_C(CompressedWaterColumn, get_segment_number))
        .def("get_sample_count", &CompressedWaterColumn::get_sample_count, DOC_C(CompressedWaterColumn, get_sample_count))
        .def("get_magnitude", &CompressedWaterColumn::get_magnitude, "magnitude arrays, one per beam (dB if get_magnitude_is_db(), else raw)")
        .def("get_phase", &CompressedWaterColumn::get_phase, "phase arrays in radians, one per beam (empty if magnitude-only)")
        .def("get_beam_magnitude", &CompressedWaterColumn::get_beam_magnitude, nb::arg("beam_index"), "magnitude array of a single beam")
        .def("get_beam_phase", &CompressedWaterColumn::get_beam_phase, nb::arg("beam_index"), "phase array (radians) of a single beam")
        .def("get_magnitude_in_db", &CompressedWaterColumn::get_magnitude_in_db, "magnitude in dB, one array per beam (already-dB values returned unchanged, else 20*log10(mag/65535); 0 -> -inf)")
        .def("get_phase_in_degrees", &CompressedWaterColumn::get_phase_in_degrees, "phase in degrees, one array per beam (empty if magnitude-only)")
        .def("get_beam_magnitude_in_db", &CompressedWaterColumn::get_beam_magnitude_in_db, nb::arg("beam_index"), "magnitude of a single beam in dB (see get_magnitude_in_db)")
        .def("get_beam_phase_in_degrees", &CompressedWaterColumn::get_beam_phase_in_degrees, nb::arg("beam_index"), "phase of a single beam in degrees")
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
