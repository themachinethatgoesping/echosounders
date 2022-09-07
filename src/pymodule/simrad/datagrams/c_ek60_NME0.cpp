// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>

#include "../../../themachinethatgoesping/echosounders/simrad/datagrams/ek60_NME0.hpp"
#include "../../docstrings.hpp"
#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simrad;
using datagrams::EK60_Datagram;
using datagrams::EK60_NME0;

void init_c_EK60_NME0(pybind11::module& m)
{
    py::class_<EK60_NME0, datagrams::EK60_Datagram>(
        m, "EK60_NME0", DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK60_NME0))
        .def(py::init<>(),
             DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK60_NME0, EK60_NME0))
        // --- convenient data access ---
        .def_property_readonly(
            "sender",
            &EK60_NME0::get_sender_id,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK60_NME0, get_sender_id))
        .def_property_readonly(
            "type",
            &EK60_NME0::get_sentence_type,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK60_NME0, get_sentence_type))
        .def_property_readonly(
            "name",
            &EK60_NME0::get_sentence_id,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK60_NME0, get_sentence_id))

        .def("field", &EK60_NME0::get_field, DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK60_NME0, get_field))
        .def("field_double", &EK60_NME0::get_field_as_double, DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK60_NME0, get_field_as_double))
        .def("field_int", &EK60_NME0::get_field_as_int, DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK60_NME0, get_field_as_int))
        .def("parse_fields", &EK60_NME0::parse_fields, DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK60_NME0, parse_fields))
        .def("get_nmea_structure", &EK60_NME0::get_nmea_structure, DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK60_NME0, get_nmea_structure))

        // --- raw data access ---
        .def_property_readonly(
            "_raw_sentence",
            &EK60_NME0::get_sentence,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK60_NME0, get_sentence))

        // ----- operators -----
        .def("__eq__",
             &EK60_NME0::operator==,
             DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK60_NME0, operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(EK60_NME0)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(EK60_NME0)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(EK60_NME0)
        // end LinearInterpolator
        ;
}
}
}
}
}
}