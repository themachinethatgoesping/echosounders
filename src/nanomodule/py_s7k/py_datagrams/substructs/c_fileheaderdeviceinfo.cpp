// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/bind_vector.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams/substructs/fileheaderdeviceinfo.hpp>

#include "../module.hpp"

NB_MAKE_OPAQUE(std::vector<
               themachinethatgoesping::echosounders::s7k::datagrams::substructs::FileHeaderDeviceInfo>);

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::s7k;
using datagrams::substructs::FileHeaderDeviceInfo;

#define DOC_FileHeaderDeviceInfo(ARG)                                                              \
    DOC(themachinethatgoesping, echosounders, s7k, datagrams, substructs, FileHeaderDeviceInfo, ARG)

void init_c_fileheaderdeviceinfo(nanobind::module_& m)
{
    nb::class_<FileHeaderDeviceInfo>(
        m, "FileHeaderDeviceInfo", DOC_FileHeaderDeviceInfo(FileHeaderDeviceInfo))
        .def(nb::init<>(), DOC_FileHeaderDeviceInfo(FileHeaderDeviceInfo))
        .def("get_device_identifier",
             &FileHeaderDeviceInfo::get_device_identifier,
             DOC_FileHeaderDeviceInfo(get_device_identifier))
        .def("set_device_identifier",
             &FileHeaderDeviceInfo::set_device_identifier,
             DOC_FileHeaderDeviceInfo(set_device_identifier),
             nb::arg("val"))
        .def("get_system_enumerator",
             &FileHeaderDeviceInfo::get_system_enumerator,
             DOC_FileHeaderDeviceInfo(get_system_enumerator))
        .def("set_system_enumerator",
             &FileHeaderDeviceInfo::set_system_enumerator,
             DOC_FileHeaderDeviceInfo(set_system_enumerator),
             nb::arg("val"))
        .def("__eq__",
             &FileHeaderDeviceInfo::operator==,
             DOC_FileHeaderDeviceInfo(operator_eq),
             nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(FileHeaderDeviceInfo)
        __PYCLASS_DEFAULT_PRINTING__(FileHeaderDeviceInfo);

    nb::bind_vector<std::vector<FileHeaderDeviceInfo>>(m, "FileHeaderDeviceInfos_vector");
}

} // namespace py_datagrams
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
