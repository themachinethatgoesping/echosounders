// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/simradraw/datagrams/NME0.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simradraw;
using datagrams::NME0;
using datagrams::SimradRawDatagram;

#define DOC_NME0(arg) DOC(themachinethatgoesping, echosounders, simradraw, datagrams, NME0, arg)

void init_c_NME0(pybind11::module& m)
{
    py::class_<NME0, datagrams::SimradRawDatagram>(
        m, "NME0", DOC(themachinethatgoesping, echosounders, simradraw, datagrams, NME0))
        .def(py::init<>(), DOC_NME0(NME0))

        // --- convenient data access ---
        .def("get_nmea_base", &NME0::get_nmea_base, DOC_NME0(nmea_base))
        .def("set_nmea_base", &NME0::set_nmea_base, DOC_NME0(nmea_base))

        // --- processed data access ---
        .def("get_sentence", &NME0::get_sentence, DOC_NME0(get_sentence))
        .def("get_sender_id", &NME0::get_sender_id, DOC_NME0(get_sender_id))
        .def("get_sentence_type", &NME0::get_sentence_type, DOC_NME0(get_sentence_type))
        .def("get_sentence_id", &NME0::get_sentence_id, DOC_NME0(get_sentence_id))

        .def("get_field", &NME0::get_field, DOC_NME0(get_field))
        .def("get_field_as_floattype",
             &NME0::get_field_as_floattype<double>,
             DOC_NME0(get_field_as_floattype))
        .def("get_field_as_int", &NME0::get_field_as_int, DOC_NME0(get_field_as_int))

        // --- nmea functions ---
        .def("parse_fields", &NME0::parse_fields, DOC_NME0(parse_fields))
        .def("decode", &NME0::decode, DOC_NME0(decode))

        // ----- operators -----
        .def("__eq__", &NME0::operator==, DOC_NME0(operator_eq), py::arg("other"))
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