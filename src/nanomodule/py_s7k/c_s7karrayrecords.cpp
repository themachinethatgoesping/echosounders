// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <xtensor-python/nanobind/pytensor.hpp>

#include "../../themachinethatgoesping/echosounders/s7k/datagrams/rawdetection.hpp"
#include "../../themachinethatgoesping/echosounders/s7k/datagrams/snippet.hpp"
#include "../../themachinethatgoesping/echosounders/s7k/datagrams/compressedwatercolumn.hpp"
#include "../../themachinethatgoesping/echosounders/s7k/datagrams/beamgeometry.hpp"
#include "../../themachinethatgoesping/echosounders/s7k/datagrams/attitude.hpp"
#include "../../themachinethatgoesping/echosounders/s7k/datagrams/fileheader.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::s7k;
using namespace themachinethatgoesping::echosounders::s7k::datagrams;

#define DOC_C(CLASS, ARG) DOC(themachinethatgoesping, echosounders, s7k, datagrams, CLASS, ARG)

void init_c_rawdetection(nb::module_& m)
{
    nb::class_<RawDetection, S7KDatagram>(
        m, "RawDetection", DOC(themachinethatgoesping, echosounders, s7k, datagrams, RawDetection))
        .def(nb::init<>(), DOC_C(RawDetection, RawDetection))
        .def("get_serial_number", &RawDetection::get_serial_number, DOC_C(RawDetection, get_serial_number))
        .def("get_ping_number", &RawDetection::get_ping_number, DOC_C(RawDetection, get_ping_number))
        .def("get_multi_ping", &RawDetection::get_multi_ping, DOC_C(RawDetection, get_multi_ping))
        .def("get_number_beams", &RawDetection::get_number_beams, DOC_C(RawDetection, get_number_beams))
        .def("get_data_field_size", &RawDetection::get_data_field_size, DOC_C(RawDetection, get_data_field_size))
        .def("get_detection_algorithm", &RawDetection::get_detection_algorithm, DOC_C(RawDetection, get_detection_algorithm))
        .def("get_flags", &RawDetection::get_flags, DOC_C(RawDetection, get_flags))
        .def("get_sampling_rate", &RawDetection::get_sampling_rate, DOC_C(RawDetection, get_sampling_rate))
        .def("get_tx_angle", &RawDetection::get_tx_angle, DOC_C(RawDetection, get_tx_angle))
        .def("get_applied_roll", &RawDetection::get_applied_roll, DOC_C(RawDetection, get_applied_roll))
        .def("get_beam_descriptor", &RawDetection::get_beam_descriptor, DOC_C(RawDetection, get_beam_descriptor))
        .def("get_detection_point", &RawDetection::get_detection_point, DOC_C(RawDetection, get_detection_point))
        .def("get_rx_angle", &RawDetection::get_rx_angle, DOC_C(RawDetection, get_rx_angle))
        .def("get_beam_flags", &RawDetection::get_beam_flags, DOC_C(RawDetection, get_beam_flags))
        .def("get_quality", &RawDetection::get_quality, DOC_C(RawDetection, get_quality))
        .def("get_uncertainty", &RawDetection::get_uncertainty, DOC_C(RawDetection, get_uncertainty))
        .def("get_signal_strength", &RawDetection::get_signal_strength, DOC_C(RawDetection, get_signal_strength))
        .def("get_min_limit", &RawDetection::get_min_limit, DOC_C(RawDetection, get_min_limit))
        .def("get_max_limit", &RawDetection::get_max_limit, DOC_C(RawDetection, get_max_limit))
        .def("__eq__", &RawDetection::operator==, nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(RawDetection)
        __PYCLASS_DEFAULT_BINARY__(RawDetection)
        __PYCLASS_DEFAULT_PRINTING__(RawDetection);
}

void init_c_snippet(nb::module_& m)
{
    nb::class_<Snippet, S7KDatagram>(
        m, "Snippet", DOC(themachinethatgoesping, echosounders, s7k, datagrams, Snippet))
        .def(nb::init<>(), DOC_C(Snippet, Snippet))
        .def("get_serial_number", &Snippet::get_serial_number, DOC_C(Snippet, get_serial_number))
        .def("get_ping_number", &Snippet::get_ping_number, DOC_C(Snippet, get_ping_number))
        .def("get_multi_ping", &Snippet::get_multi_ping, DOC_C(Snippet, get_multi_ping))
        .def("get_number_beams", &Snippet::get_number_beams, DOC_C(Snippet, get_number_beams))
        .def("get_error_flag", &Snippet::get_error_flag, DOC_C(Snippet, get_error_flag))
        .def("get_control_flags", &Snippet::get_control_flags, DOC_C(Snippet, get_control_flags))
        .def("get_flags", &Snippet::get_flags, DOC_C(Snippet, get_flags))
        .def("get_samples_are_32bit", &Snippet::get_samples_are_32bit, DOC_C(Snippet, get_samples_are_32bit))
        .def("get_beam_descriptor", &Snippet::get_beam_descriptor, DOC_C(Snippet, get_beam_descriptor))
        .def("get_snippet_start", &Snippet::get_snippet_start, DOC_C(Snippet, get_snippet_start))
        .def("get_detection_sample", &Snippet::get_detection_sample, DOC_C(Snippet, get_detection_sample))
        .def("get_snippet_end", &Snippet::get_snippet_end, DOC_C(Snippet, get_snippet_end))
        .def("get_amplitudes", &Snippet::get_amplitudes, "intensity snippet arrays (one per beam)")
        .def("get_beam_amplitudes", &Snippet::get_beam_amplitudes, nb::arg("beam_index"), "intensity snippet of a single beam")
        .def("__eq__", &Snippet::operator==, nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(Snippet)
        __PYCLASS_DEFAULT_BINARY__(Snippet)
        __PYCLASS_DEFAULT_PRINTING__(Snippet);
}

void init_c_compressedwatercolumn(nb::module_& m)
{
    nb::class_<CompressedWaterColumn, S7KDatagram>(
        m,
        "CompressedWaterColumn",
        DOC(themachinethatgoesping, echosounders, s7k, datagrams, CompressedWaterColumn))
        .def(nb::init<>(), DOC_C(CompressedWaterColumn, CompressedWaterColumn))
        .def("get_serial_number", &CompressedWaterColumn::get_serial_number, DOC_C(CompressedWaterColumn, get_serial_number))
        .def("get_ping_number", &CompressedWaterColumn::get_ping_number, DOC_C(CompressedWaterColumn, get_ping_number))
        .def("get_multi_ping", &CompressedWaterColumn::get_multi_ping, DOC_C(CompressedWaterColumn, get_multi_ping))
        .def("get_number_beams", &CompressedWaterColumn::get_number_beams, DOC_C(CompressedWaterColumn, get_number_beams))
        .def("get_samples", &CompressedWaterColumn::get_samples, DOC_C(CompressedWaterColumn, get_samples))
        .def("get_compressed_samples", &CompressedWaterColumn::get_compressed_samples, DOC_C(CompressedWaterColumn, get_compressed_samples))
        .def("get_flags", &CompressedWaterColumn::get_flags, DOC_C(CompressedWaterColumn, get_flags))
        .def("get_first_sample", &CompressedWaterColumn::get_first_sample, DOC_C(CompressedWaterColumn, get_first_sample))
        .def("get_sample_rate", &CompressedWaterColumn::get_sample_rate, DOC_C(CompressedWaterColumn, get_sample_rate))
        .def("get_compression_factor", &CompressedWaterColumn::get_compression_factor, DOC_C(CompressedWaterColumn, get_compression_factor))
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

void init_c_beamgeometry(nb::module_& m)
{
    nb::class_<BeamGeometry, S7KDatagram>(
        m, "BeamGeometry", DOC(themachinethatgoesping, echosounders, s7k, datagrams, BeamGeometry))
        .def(nb::init<>(), DOC_C(BeamGeometry, BeamGeometry))
        .def("get_serial_number", &BeamGeometry::get_serial_number, DOC_C(BeamGeometry, get_serial_number))
        .def("get_number_beams", &BeamGeometry::get_number_beams, DOC_C(BeamGeometry, get_number_beams))
        .def("get_beam_vertical_angle", &BeamGeometry::get_beam_vertical_angle, DOC_C(BeamGeometry, get_beam_vertical_angle))
        .def("get_beam_horizontal_angle", &BeamGeometry::get_beam_horizontal_angle, DOC_C(BeamGeometry, get_beam_horizontal_angle))
        .def("get_beamwidth_vertical", &BeamGeometry::get_beamwidth_vertical, DOC_C(BeamGeometry, get_beamwidth_vertical))
        .def("get_beamwidth_horizontal", &BeamGeometry::get_beamwidth_horizontal, DOC_C(BeamGeometry, get_beamwidth_horizontal))
        .def("get_has_tx_delay", &BeamGeometry::get_has_tx_delay, DOC_C(BeamGeometry, get_has_tx_delay))
        .def("get_tx_delay", &BeamGeometry::get_tx_delay, DOC_C(BeamGeometry, get_tx_delay))
        .def("__eq__", &BeamGeometry::operator==, nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(BeamGeometry)
        __PYCLASS_DEFAULT_BINARY__(BeamGeometry)
        __PYCLASS_DEFAULT_PRINTING__(BeamGeometry);
}

void init_c_attitude(nb::module_& m)
{
    nb::class_<Attitude, S7KDatagram>(
        m, "Attitude", DOC(themachinethatgoesping, echosounders, s7k, datagrams, Attitude))
        .def(nb::init<>(), DOC_C(Attitude, Attitude))
        .def("get_number_of_samples", &Attitude::get_number_of_samples, DOC_C(Attitude, get_number_of_samples))
        .def("get_delta_time", &Attitude::get_delta_time, DOC_C(Attitude, get_delta_time))
        .def("get_roll", &Attitude::get_roll, DOC_C(Attitude, get_roll))
        .def("get_pitch", &Attitude::get_pitch, DOC_C(Attitude, get_pitch))
        .def("get_heave", &Attitude::get_heave, DOC_C(Attitude, get_heave))
        .def("get_heading", &Attitude::get_heading, DOC_C(Attitude, get_heading))
        .def("__eq__", &Attitude::operator==, nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(Attitude)
        __PYCLASS_DEFAULT_BINARY__(Attitude)
        __PYCLASS_DEFAULT_PRINTING__(Attitude);
}

void init_c_fileheader(nb::module_& m)
{
    nb::class_<FileHeader, S7KDatagram>(
        m, "FileHeader", DOC(themachinethatgoesping, echosounders, s7k, datagrams, FileHeader))
        .def(nb::init<>(), DOC_C(FileHeader, FileHeader))
        .def("get_version", &FileHeader::get_version, DOC_C(FileHeader, get_version))
        .def("get_record_data_size", &FileHeader::get_record_data_size, DOC_C(FileHeader, get_record_data_size))
        .def("get_number_devices", &FileHeader::get_number_devices, DOC_C(FileHeader, get_number_devices))
        .def("get_recording_name", &FileHeader::get_recording_name, DOC_C(FileHeader, get_recording_name))
        .def("get_recording_version", &FileHeader::get_recording_version, DOC_C(FileHeader, get_recording_version))
        .def("get_user_defined_name", &FileHeader::get_user_defined_name, DOC_C(FileHeader, get_user_defined_name))
        .def("get_notes", &FileHeader::get_notes, DOC_C(FileHeader, get_notes))
        .def("get_device_identifier", &FileHeader::get_device_identifier, DOC_C(FileHeader, get_device_identifier))
        .def("get_system_enumerator", &FileHeader::get_system_enumerator, DOC_C(FileHeader, get_system_enumerator))
        .def("__eq__", &FileHeader::operator==, nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(FileHeader)
        __PYCLASS_DEFAULT_BINARY__(FileHeader)
        __PYCLASS_DEFAULT_PRINTING__(FileHeader);
}

void init_c_s7karrayrecords(nb::module_& m)
{
    init_c_rawdetection(m);
    init_c_snippet(m);
    init_c_compressedwatercolumn(m);
    init_c_beamgeometry(m);
    init_c_attitude(m);
    init_c_fileheader(m);
}

}
}
}
}
