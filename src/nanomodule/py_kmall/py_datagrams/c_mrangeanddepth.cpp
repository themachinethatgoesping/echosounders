// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/bind_vector.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/datetime.hpp>

#include <themachinethatgoesping/echosounders/kmall/datagrams/mrangeanddepth.hpp>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kmall {
namespace py_datagrams {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::kmall;
using datagrams::MRangeAndDepth;

#define DOC_MRangeAndDepth(ARG)                                                                    \
    DOC(themachinethatgoesping, echosounders, kmall, datagrams, MRangeAndDepth, ARG)

void init_c_mrangeanddepth(nanobind::module_& m)
{
    nb::class_<MRangeAndDepth, datagrams::KMALLMultibeamDatagram>(
        m,
        "MRangeAndDepth",
        DOC(themachinethatgoesping, echosounders, kmall, datagrams, MRangeAndDepth))
        .def(nb::init<>(), DOC_MRangeAndDepth(MRangeAndDepth))

        // --- convenient data access ---
        .def_prop_rw("ping_info",
                     &MRangeAndDepth::ping_info,
                     &MRangeAndDepth::set_ping_info,
                     DOC_MRangeAndDepth(ping_info),
                     nb::rv_policy::reference_internal)
        .def_prop_rw("rx_info",
                     &MRangeAndDepth::rx_info,
                     &MRangeAndDepth::set_rx_info,
                     DOC_MRangeAndDepth(rx_info),
                     nb::rv_policy::reference_internal)

        // ----- sectors etc. -----
        .def_prop_rw("tx_sectors",
                     &MRangeAndDepth::tx_sectors,
                     &MRangeAndDepth::set_tx_sectors,
                     DOC_MRangeAndDepth(tx_sectors),
                     nb::rv_policy::reference_internal)

        // ----- processed -----

        // ----- operators -----
        .def("__eq__",
             &MRangeAndDepth::operator==,
             DOC_MRangeAndDepth(operator_eq),
             nb::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(MRangeAndDepth)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(MRangeAndDepth)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(MRangeAndDepth)
        // end LinearInterpolator
        ;
}
}
}
}
}
}