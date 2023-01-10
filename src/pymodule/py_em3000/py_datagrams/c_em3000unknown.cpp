// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/em3000/datagrams/em3000unknown.hpp"
#include "../../docstrings.hpp"
#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_em3000 {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::em3000;
using datagrams::EM3000Unknown;

void init_c_em3000unknown(pybind11::module& m)
{
    py::class_<EM3000Unknown, datagrams::EM3000Datagram>(
        m,
        "EM3000Unknown",
        DOC(themachinethatgoesping, echosounders, em3000, datagrams, EM3000Unknown))
        .def(py::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 em3000,
                 datagrams,
                 EM3000Unknown,
                 EM3000Unknown))
        // --- convenient data access ---
        .def("get_raw_content",
             &EM3000Unknown::get_raw_content,
             DOC(themachinethatgoesping,
                 echosounders,
                 em3000,
                 datagrams,
                 EM3000Unknown,
                 raw_content))
        .def("set_raw_content",
             &EM3000Unknown::set_raw_content,
             DOC(themachinethatgoesping,
                 echosounders,
                 em3000,
                 datagrams,
                 EM3000Unknown,
                 raw_content))
        .def("get_etx",
             &EM3000Unknown::get_etx,
             DOC(themachinethatgoesping, echosounders, em3000, datagrams, EM3000Unknown, etx))
        .def("set_etx",
             &EM3000Unknown::set_etx,
             DOC(themachinethatgoesping, echosounders, em3000, datagrams, EM3000Unknown, etx))
        .def("get_checksum",
             &EM3000Unknown::get_checksum,
             DOC(themachinethatgoesping, echosounders, em3000, datagrams, EM3000Unknown, checksum))
        .def("set_checksum",
             &EM3000Unknown::set_checksum,
             DOC(themachinethatgoesping, echosounders, em3000, datagrams, EM3000Unknown, checksum))

        // ----- checksum -----
        // .def("compute_checksum",
        //      &EM3000Unknown::compute_checksum,
        //      DOC(themachinethatgoesping,
        //          echosounders,
        //          em3000,
        //          datagrams,
        //          EM3000Unknown,
        //          compute_checksum))
        // .def("verify_checksum",
        //      &EM3000Unknown::verify_checksum,
        //      DOC(themachinethatgoesping,
        //          echosounders,
        //          em3000,
        //          datagrams,
        //          EM3000Unknown,
        //          verify_checksum))

        // ----- operators -----
        .def("__eq__",
             &EM3000Unknown::operator==,
             DOC(themachinethatgoesping,
                 echosounders,
                 em3000,
                 datagrams,
                 EM3000Unknown,
                 operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(EM3000Unknown)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(EM3000Unknown)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(EM3000Unknown)
        // end LinearInterpolator
        ;
}
}
}
}
}
}