// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>

#include "../../../themachinethatgoesping/echosounders/simrad/datagrams/NME0.hpp"
#include "../../docstrings.hpp"
#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simrad;
using datagrams::NME0;
using datagrams::SimradDatagram;

void init_c_NME0(pybind11::module& m)
{
    py::class_<NME0, datagrams::SimradDatagram>(
        m, "NME0", DOC(themachinethatgoesping, echosounders, simrad, datagrams, NME0))
        .def(py::init<>(), DOC(themachinethatgoesping, echosounders, simrad, datagrams, NME0, NME0))
        // --- convenient data access ---
        .def_property_readonly(
            "sender",
            &NME0::get_sender_id,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, NME0, get_sender_id))
        .def_property_readonly(
            "type",
            &NME0::get_sentence_type,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, NME0, get_sentence_type))
        .def_property_readonly(
            "name",
            &NME0::get_sentence_id,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, NME0, get_sentence_id))

        .def("field",
             &NME0::get_field,
             DOC(themachinethatgoesping, echosounders, simrad, datagrams, NME0, get_field))
        .def(
            "field_double",
            &NME0::get_field_as_double,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, NME0, get_field_as_double))
        .def("field_int",
             &NME0::get_field_as_int,
             DOC(themachinethatgoesping, echosounders, simrad, datagrams, NME0, get_field_as_int))
        .def("parse_fields",
             &NME0::parse_fields,
             DOC(themachinethatgoesping, echosounders, simrad, datagrams, NME0, parse_fields))
        .def("decode",
             &NME0::decode,
             DOC(themachinethatgoesping, echosounders, simrad, datagrams, NME0, decode))

        // --- raw data access ---
        .def_property_readonly(
            "_raw_sentence",
            &NME0::get_sentence,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, NME0, get_sentence))

        // ----- operators -----
        .def("__eq__",
             &NME0::operator==,
             DOC(themachinethatgoesping, echosounders, simrad, datagrams, NME0, operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(NME0)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(NME0)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(NME0)
        // end LinearInterpolator
        ;
}
}
}
}
}
}