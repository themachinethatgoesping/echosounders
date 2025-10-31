// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/kmallunknown.hpp>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::KMALLUnknown;

#define DOC_KMALLUnknown(arg)                                                                      \
    DOC(themachinethatgoesping, echosounders, kmall, datagrams, KMALLUnknown, arg)

void init_c_kmallunknown(nanobind::module_& m)
{
    nb::class_<KMALLUnknown, datagrams::KMALLDatagram>(
        m,
        "KMALLUnknown",
        DOC(themachinethatgoesping, echosounders, kmall, datagrams, KMALLUnknown))
        .def(nb::init<>(), DOC_KMALLUnknown(KMALLUnknown))
        // --- convenient data access ---
        .def(
            "get_raw_content",
            [](const KMALLUnknown& self) {
                return nb::bytes(self.get_raw_content().data(), self.get_raw_content().size());
            },
            DOC_KMALLUnknown(raw_content))
        .def("set_raw_content", &KMALLUnknown::set_raw_content, DOC_KMALLUnknown(raw_content))

        .def("get_bytes_datagram_check",
             &KMALLUnknown::get_bytes_datagram_check,
             DOC_KMALLUnknown(get_bytes_datagram_check))

        // ----- operators -----
        .def("__eq__", &KMALLUnknown::operator==, DOC_KMALLUnknown(operator_eq), nb::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(KMALLUnknown)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(KMALLUnknown)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(KMALLUnknown)
        // end LinearInterpolator
        ;
}
}
}
}
}
}