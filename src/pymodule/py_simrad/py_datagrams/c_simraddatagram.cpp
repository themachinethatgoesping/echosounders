// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/simrad/datagrams/simraddatagram.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_datagrams {
namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simrad;
using datagrams::SimradDatagram;

#define DOC_SimradDatagram(arg)                                                                    \
    DOC(themachinethatgoesping, echosounders, simrad, datagrams, SimradDatagram, arg)

void init_c_SimradDatagram(pybind11::module& m)
{
    py::class_<SimradDatagram>(
        m,
        "SimradDatagram",
        DOC(themachinethatgoesping, echosounders, simrad, datagrams, SimradDatagram))
        .def(py::init<>(), DOC_SimradDatagram(SimradDatagram))

        // --- convenient data access ---
        .def("get_length", &SimradDatagram::get_length, DOC_SimradDatagram(length))
        .def("set_length", &SimradDatagram::set_length, DOC_SimradDatagram(length))
        .def("get_datagram_type", &SimradDatagram::get_datagram_type, DOC_SimradDatagram(datagram_type))
        .def("set_datagram_type", &SimradDatagram::set_datagram_type, DOC_SimradDatagram(datagram_type))
        .def("get_low_date_time", &SimradDatagram::get_low_date_time, DOC_SimradDatagram(low_date_time))
        .def("set_low_date_time", &SimradDatagram::set_low_date_time, DOC_SimradDatagram(low_date_time))
        .def("get_high_date_time", &SimradDatagram::get_high_date_time, DOC_SimradDatagram(high_date_time))
        .def("set_high_date_time", &SimradDatagram::set_high_date_time, DOC_SimradDatagram(high_date_time))

        // --- processed data access
        .def("get_timestamp", &SimradDatagram::get_timestamp, DOC_SimradDatagram(get_timestamp))
        .def("set_timestamp", &SimradDatagram::set_timestamp, DOC_SimradDatagram(set_timestamp))
        .def("get_datagram_identifier", &SimradDatagram::get_datagram_identifier, DOC_SimradDatagram(get_datagram_identifier))
        .def("set_datagram_identifier", &SimradDatagram::set_datagram_identifier, DOC_SimradDatagram(set_datagram_identifier))
        .def("get_date_string", &SimradDatagram::get_date_string, DOC_SimradDatagram(get_date_string))

        // ----- operators -----
        .def("__eq__",
             &SimradDatagram::operator==,
             DOC_SimradDatagram(operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(SimradDatagram)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(SimradDatagram)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(SimradDatagram)
        // end LinearInterpolator
        ;
}

}
}
}
}
}