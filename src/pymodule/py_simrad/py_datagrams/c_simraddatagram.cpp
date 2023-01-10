// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/simrad/datagrams/simraddatagram.hpp"
#include "../../docstrings.hpp"
#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_datagrams {
namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simrad;
using datagrams::SimradDatagram;

void init_c_SimradDatagram(pybind11::module& m)
{
    py::class_<SimradDatagram>(
        m,
        "SimradDatagram",
        DOC(themachinethatgoesping, echosounders, simrad, datagrams, SimradDatagram))
        .def(py::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 SimradDatagram,
                 SimradDatagram))
        // --- convenient data access ---
        .def_property("length",
                      &SimradDatagram::get_length,
                      &SimradDatagram::set_length,
                      DOC(themachinethatgoesping,
                          echosounders,
                          simrad,
                          datagrams,
                          SimradDatagram,
                          get_length))
        .def_property("timestamp",
                      &SimradDatagram::get_timestamp,
                      &SimradDatagram::set_timestamp,
                      DOC(themachinethatgoesping,
                          echosounders,
                          simrad,
                          datagrams,
                          SimradDatagram,
                          get_timestamp))
        .def_property("datagram_type",
                      &SimradDatagram::get_datagram_identifier,
                      &SimradDatagram::set_datagram_identifier,
                      DOC(themachinethatgoesping,
                          echosounders,
                          simrad,
                          datagrams,
                          SimradDatagram,
                          get_datagram_identifier))
        .def("get_date_string",
             &SimradDatagram::get_date_string,
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 SimradDatagram,
                 get_date_string),
             py::arg("fractional_seconds_digits") = 2,
             py::arg("format")                    = "%z__%d-%m-%Y__%H:%M:%S")

        // --- raw data access ---
        .def_readwrite(
            "_raw_Length",
            &SimradDatagram::_Length,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, SimradDatagram, Length))
        .def_readwrite("_raw_DatagramType",
                       &SimradDatagram::_DatagramType,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           SimradDatagram,
                           DatagramType))
        .def_readwrite("_raw_LowDateTime",
                       &SimradDatagram::_LowDateTime,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           SimradDatagram,
                           LowDateTime))
        .def_readwrite("_raw_HighDateTime",
                       &SimradDatagram::_HighDateTime,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           SimradDatagram,
                           HighDateTime))
        // .def("__call__",
        //      py::overload_cast<double>(&LinearInterpolator::operator()),
        //      DOC(themachinethatgoesping, tools, vectorinterpolators, I_Interpolator,
        //      operator_call), py::arg("target_x"))
        // .def("__call__",
        //      py::overload_cast<const std::vector<double>&>(&LinearInterpolator::operator()),
        //      DOC(themachinethatgoesping,
        //          tools,
        //          vectorinterpolators,
        //          I_Interpolator,
        //          operator_call_2),
        //      py::arg("targets_x"))
        // ----- operators -----
        .def("__eq__",
             &SimradDatagram::operator==,
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 SimradDatagram,
                 operator_eq),
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