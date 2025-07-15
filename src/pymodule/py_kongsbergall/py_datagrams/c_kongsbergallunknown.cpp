// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/kongsbergall/datagrams/kongsbergallunknown.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_kongsbergall {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::kongsbergall;
using datagrams::KongsbergAllUnknown;

void init_c_kongsbergallunknown(pybind11::module& m)
{
    py::class_<KongsbergAllUnknown, datagrams::KongsbergAllDatagram>(
        m,
        "KongsbergAllUnknown",
        DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, KongsbergAllUnknown))
        .def(py::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 kongsbergall,
                 datagrams,
                 KongsbergAllUnknown,
                 KongsbergAllUnknown))
        // --- convenient data access ---
        .def("get_raw_content",
             &KongsbergAllUnknown::get_raw_content,
             DOC(themachinethatgoesping,
                 echosounders,
                 kongsbergall,
                 datagrams,
                 KongsbergAllUnknown,
                 raw_content),
             py::return_value_policy::reference_internal)
        .def("set_raw_content",
             &KongsbergAllUnknown::set_raw_content,
             DOC(themachinethatgoesping,
                 echosounders,
                 kongsbergall,
                 datagrams,
                 KongsbergAllUnknown,
                 raw_content))
        .def("get_etx",
             &KongsbergAllUnknown::get_etx,
             DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, KongsbergAllUnknown, etx))
        .def("set_etx",
             &KongsbergAllUnknown::set_etx,
             DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, KongsbergAllUnknown, etx))
        .def("get_checksum",
             &KongsbergAllUnknown::get_checksum,
             DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, KongsbergAllUnknown, checksum))
        .def("set_checksum",
             &KongsbergAllUnknown::set_checksum,
             DOC(themachinethatgoesping, echosounders, kongsbergall, datagrams, KongsbergAllUnknown, checksum))

        // ----- checksum -----
        // .def("compute_checksum",
        //      &KongsbergAllUnknown::compute_checksum,
        //      DOC(themachinethatgoesping,
        //          echosounders,
        //          kongsbergall,
        //          datagrams,
        //          KongsbergAllUnknown,
        //          compute_checksum))
        // .def("verify_checksum",
        //      &KongsbergAllUnknown::verify_checksum,
        //      DOC(themachinethatgoesping,
        //          echosounders,
        //          kongsbergall,
        //          datagrams,
        //          KongsbergAllUnknown,
        //          verify_checksum))

        // ----- operators -----
        .def("__eq__",
             &KongsbergAllUnknown::operator==,
             DOC(themachinethatgoesping,
                 echosounders,
                 kongsbergall,
                 datagrams,
                 KongsbergAllUnknown,
                 operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(KongsbergAllUnknown)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(KongsbergAllUnknown)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(KongsbergAllUnknown)
        // end LinearInterpolator
        ;
}
}
}
}
}
}