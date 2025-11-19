// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/datetime.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/cheave.hpp>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::CHeave;

#define DOC_CHeave(ARG) DOC(themachinethatgoesping, echosounders, kmall, datagrams, CHeave, ARG)

void init_c_cheave(nanobind::module_& m)
{
    nb::class_<CHeave, datagrams::KMALLMultibeamDatagram>(
        m, "CHeave", DOC(themachinethatgoesping, echosounders, kmall, datagrams, CHeave))
        .def(nb::init<>(), DOC_CHeave(CHeave))

        // --- convenient data access ---
        .def("get_heave_m", &CHeave::get_heave_m, DOC_CHeave(get_heave_m))
        .def("get_bytes_datagram_check",
             &CHeave::get_bytes_datagram_check,
             DOC_CHeave(get_bytes_datagram_check))

        .def("set_heave_m", &CHeave::set_heave_m, DOC_CHeave(set_heave_m), nb::arg("heave_m"))
        .def("set_bytes_datagram_check",
             &CHeave::set_bytes_datagram_check,
             DOC_CHeave(set_bytes_datagram_check),
             nb::arg("val"))

        // ----- processed -----

        // ----- operators -----
        .def("__eq__", &CHeave::operator==, DOC_CHeave(operator_eq), nb::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(CHeave)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(CHeave)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(CHeave)
        // end LinearInterpolator
        ;
}
}
}
}
}
}