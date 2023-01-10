// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/em3000/datagrams/em3000datagram.hpp"
#include "../../docstrings.hpp"
#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_em3000 {
namespace py_datagrams {
namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::em3000;
using datagrams::EM3000Datagram;

void init_c_em3000datagram(pybind11::module& m)
{
    py::class_<EM3000Datagram>(
        m,
        "EM3000Datagram",
        DOC(themachinethatgoesping, echosounders, em3000, datagrams, EM3000Datagram))
        .def(py::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 em3000,
                 datagrams,
                 EM3000Datagram,
                 EM3000Datagram))
        // --- convenient data access ---
        .def("get_bytes",
             &EM3000Datagram::get_bytes,
             DOC(themachinethatgoesping, echosounders, em3000, datagrams, EM3000Datagram, bytes))
        .def("set_bytes",
             &EM3000Datagram::set_bytes,
             DOC(themachinethatgoesping, echosounders, em3000, datagrams, EM3000Datagram, bytes))
        .def("get_stx",
             &EM3000Datagram::get_stx,
             DOC(themachinethatgoesping, echosounders, em3000, datagrams, EM3000Datagram, stx))
        .def("set_stx",
             &EM3000Datagram::set_stx,
             DOC(themachinethatgoesping, echosounders, em3000, datagrams, EM3000Datagram, stx))
        .def("get_datagram_identifier",
             &EM3000Datagram::get_datagram_identifier,
             DOC(themachinethatgoesping,
                 echosounders,
                 em3000,
                 datagrams,
                 EM3000Datagram,
                 datagram_identifier))
        .def("set_datagram_identifier",
             &EM3000Datagram::set_datagram_identifier,
             DOC(themachinethatgoesping,
                 echosounders,
                 em3000,
                 datagrams,
                 EM3000Datagram,
                 datagram_identifier))
        .def("get_model_number",
             &EM3000Datagram::get_model_number,
             DOC(themachinethatgoesping,
                 echosounders,
                 em3000,
                 datagrams,
                 EM3000Datagram,
                 model_number))
        .def("set_model_number",
             &EM3000Datagram::set_model_number,
             DOC(themachinethatgoesping,
                 echosounders,
                 em3000,
                 datagrams,
                 EM3000Datagram,
                 model_number))
        .def("get_date",
             &EM3000Datagram::get_date,
             DOC(themachinethatgoesping, echosounders, em3000, datagrams, EM3000Datagram, date))
        .def("set_date",
             &EM3000Datagram::set_date,
             DOC(themachinethatgoesping, echosounders, em3000, datagrams, EM3000Datagram, date))
        .def("get_time_since_midnight",
             &EM3000Datagram::get_time_since_midnight,
             DOC(themachinethatgoesping,
                 echosounders,
                 em3000,
                 datagrams,
                 EM3000Datagram,
                 time_since_midnight))
        .def("set_time_since_midnight",
             &EM3000Datagram::set_time_since_midnight,
             DOC(themachinethatgoesping,
                 echosounders,
                 em3000,
                 datagrams,
                 EM3000Datagram,
                 time_since_midnight))

        // --- convenient processed data access ---
        .def("get_timestamp",
             &EM3000Datagram::get_timestamp,
             DOC(themachinethatgoesping,
                 echosounders,
                 em3000,
                 datagrams,
                 EM3000Datagram,
                 get_timestamp))

        .def("get_date_string",
             &EM3000Datagram::get_date_string,
             DOC(themachinethatgoesping,
                 echosounders,
                 em3000,
                 datagrams,
                 EM3000Datagram,
                 get_date_string),
             py::arg("fractional_seconds_digits") = 2,
             py::arg("format")                    = "%z__%d-%m-%Y__%H:%M:%S")

        // ----- operators -----
        .def("__eq__",
             &EM3000Datagram::operator==,
             DOC(themachinethatgoesping,
                 echosounders,
                 em3000,
                 datagrams,
                 EM3000Datagram,
                 operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(EM3000Datagram)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(EM3000Datagram)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(EM3000Datagram)
        // end LinearInterpolator
        ;
}

}
}
}
}
}