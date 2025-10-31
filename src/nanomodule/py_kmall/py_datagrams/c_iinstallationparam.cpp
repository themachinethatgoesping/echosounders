// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/iinstallationparam.hpp>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::IInstallationParam;

#define DOC_IInstallationParam(ARG)                                                                \
    DOC(themachinethatgoesping, echosounders, kmall, datagrams, IInstallationParam, ARG)

void init_c_iinstallationparam(nanobind::module_& m)
{
    nb::class_<IInstallationParam, datagrams::KMALLDatagram>(
        m,
        "IInstallationParam",
        DOC(themachinethatgoesping, echosounders, kmall, datagrams, IInstallationParam))
        .def(nb::init<>(), DOC_IInstallationParam(IInstallationParam))

        // --- convenient data access ---
        .def("get_bytes_content",
             &IInstallationParam::get_bytes_content,
             DOC_IInstallationParam(get_bytes_content))
        .def("get_info", &IInstallationParam::get_info, DOC_IInstallationParam(get_info))
        .def("get_status", &IInstallationParam::get_status, DOC_IInstallationParam(get_status))
        .def("get_install_txt",
             &IInstallationParam::get_install_txt,
             DOC_IInstallationParam(get_install_txt))
        .def("set_info",
             &IInstallationParam::set_info,
             DOC_IInstallationParam(set_info),
             nb::arg("info"))
        .def("set_status",
             &IInstallationParam::set_status,
             DOC_IInstallationParam(set_status),
             nb::arg("status"))
        .def("set_install_txt",
             &IInstallationParam::set_install_txt,
             DOC_IInstallationParam(set_install_txt),
             nb::arg("install_txt"))

        .def("get_bytes_datagram_check",
             &IInstallationParam::get_bytes_datagram_check,
             DOC_IInstallationParam(get_bytes_datagram_check))

        // ----- operators -----
        .def("__eq__",
             &IInstallationParam::operator==,
             DOC_IInstallationParam(operator_eq),
             nb::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(IInstallationParam)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(IInstallationParam)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(IInstallationParam)
        // end LinearInterpolator
        ;
}
}
}
}
}
}