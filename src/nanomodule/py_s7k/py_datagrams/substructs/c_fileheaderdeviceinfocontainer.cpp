// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <xtensor-python/nanobind/pytensor.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams/substructs/fileheaderdeviceinfocontainer.hpp>

#include "../module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::s7k;
using datagrams::substructs::FileHeaderDeviceInfoContainer;

#define DOC_FileHeaderDeviceInfoContainer(ARG)                                                     \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        s7k,                                                                                       \
        datagrams,                                                                                 \
        substructs,                                                                                \
        FileHeaderDeviceInfoContainer,                                                             \
        ARG)

void init_c_fileheaderdeviceinfocontainer(nanobind::module_& m)
{
    nb::class_<FileHeaderDeviceInfoContainer>(m,
                                              "FileHeaderDeviceInfoContainer",
                                              DOC_FileHeaderDeviceInfoContainer(
                                                  FileHeaderDeviceInfoContainer))
        .def(nb::init<>(), DOC_FileHeaderDeviceInfoContainer(FileHeaderDeviceInfoContainer))

        .def_prop_rw("devices",
                     &FileHeaderDeviceInfoContainer::devices,
                     &FileHeaderDeviceInfoContainer::set_devices,
                     DOC_FileHeaderDeviceInfoContainer(devices),
                     nb::rv_policy::reference_internal)

        .def("get_device_identifier_tensor",
             &FileHeaderDeviceInfoContainer::get_device_identifier_tensor,
             DOC_FileHeaderDeviceInfoContainer(get_device_identifier_tensor))
        .def("get_system_enumerator_tensor",
             &FileHeaderDeviceInfoContainer::get_system_enumerator_tensor,
             DOC_FileHeaderDeviceInfoContainer(get_system_enumerator_tensor))

        .def("get_number_of_devices",
             &FileHeaderDeviceInfoContainer::get_number_of_devices,
             DOC_FileHeaderDeviceInfoContainer(get_number_of_devices))

        .def("__eq__",
             &FileHeaderDeviceInfoContainer::operator==,
             DOC_FileHeaderDeviceInfoContainer(operator_eq),
             nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(FileHeaderDeviceInfoContainer)
        __PYCLASS_DEFAULT_PRINTING__(FileHeaderDeviceInfoContainer);
}

} // namespace py_datagrams
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
