// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <xtensor-python/nanobind/pytensor.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams/fileheader.hpp>

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

void init_c_fileheader(nb::module_& m)
{
    nb::class_<FileHeader, S7KDatagram>(
        m, "FileHeader", DOC(themachinethatgoesping, echosounders, s7k, datagrams, FileHeader))
        .def(nb::init<>(), DOC_C(FileHeader, FileHeader))
        .def("get_version", &FileHeader::get_version, DOC_C(FileHeader, Content, version))
        .def("get_record_data_size", &FileHeader::get_record_data_size, DOC_C(FileHeader, Content, record_data_size))
        .def("get_number_devices", &FileHeader::get_number_devices, DOC_C(FileHeader, Content, number_devices))
        .def("get_recording_name", &FileHeader::get_recording_name, DOC_C(FileHeader, get_recording_name))
        .def("get_recording_version", &FileHeader::get_recording_version, DOC_C(FileHeader, get_recording_version))
        .def("get_user_defined_name", &FileHeader::get_user_defined_name, DOC_C(FileHeader, get_user_defined_name))
        .def("get_notes", &FileHeader::get_notes, DOC_C(FileHeader, get_notes))
        .def_prop_rw("devices",
                     &FileHeader::devices,
                     &FileHeader::set_devices,
                     DOC_C(FileHeader, devices),
                     nb::rv_policy::reference_internal)
        .def("__eq__", &FileHeader::operator==, nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(FileHeader)
        __PYCLASS_DEFAULT_BINARY__(FileHeader)
        __PYCLASS_DEFAULT_PRINTING__(FileHeader);
}

} // namespace py_datagrams
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
