// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/iopruntime.hpp>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::IOpRuntime;

#define DOC_IOpRuntime(ARG)                                                                \
    DOC(themachinethatgoesping, echosounders, kmall, datagrams, IOpRuntime, ARG)

void init_c_iopruntime(nanobind::module_& m)
{
    nb::class_<IOpRuntime, datagrams::KMALLDatagram>(
        m,
        "IOpRuntime",
        DOC(themachinethatgoesping, echosounders, kmall, datagrams, IOpRuntime))
        .def(nb::init<>(), DOC_IOpRuntime(IOpRuntime))

        // --- convenient data access ---
        .def("get_bytes_content",
             &IOpRuntime::get_bytes_content,
             DOC_IOpRuntime(get_bytes_content))
        .def("get_info", &IOpRuntime::get_info, DOC_IOpRuntime(get_info))
        .def("get_status", &IOpRuntime::get_status, DOC_IOpRuntime(get_status))
        .def("get_runtime_txt",
             &IOpRuntime::get_runtime_txt,
             DOC_IOpRuntime(get_runtime_txt))
        .def("set_info",
             &IOpRuntime::set_info,
             DOC_IOpRuntime(set_info),
             nb::arg("info"))
        .def("set_status",
             &IOpRuntime::set_status,
             DOC_IOpRuntime(set_status),
             nb::arg("status"))
        .def("set_runtime_txt",
             &IOpRuntime::set_runtime_txt,
             DOC_IOpRuntime(set_runtime_txt),
             nb::arg("runtime_txt"))

        .def("get_bytes_datagram_check",
             &IOpRuntime::get_bytes_datagram_check,
             DOC_IOpRuntime(get_bytes_datagram_check))

        // ----- operators -----
        .def("__eq__",
             &IOpRuntime::operator==,
             DOC_IOpRuntime(operator_eq),
             nb::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(IOpRuntime)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(IOpRuntime)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(IOpRuntime)
        // end LinearInterpolator
        ;
}
}
}
}
}
}