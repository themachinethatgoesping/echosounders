// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>

#include "../../../themachinethatgoesping/echosounders/simrad/datagrams/ek60_datagram.hpp"
#include "../../docstrings.hpp"
#include "module.hpp"

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simrad;
using datagrams::EK60_Datagram;

void init_c_ek60_datagram(pybind11::module& m)
{
        py::class_<EK60_Datagram>(
        m,
        "EK60_Datagram",
        DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK60_Datagram))
        .def(py::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 EK60_Datagram,
                 EK60_Datagram))
        // --- convenient data access ---
        .def_property("length",
                      &EK60_Datagram::get_length,
                      &EK60_Datagram::set_length,
                      DOC(themachinethatgoesping,
                          echosounders,
                          simrad,
                          datagrams,
                          EK60_Datagram,
                          get_length))
        .def_property("timestamp",
                      &EK60_Datagram::get_timestamp,
                      &EK60_Datagram::set_timestamp,
                      DOC(themachinethatgoesping,
                          echosounders,
                          simrad,
                          datagrams,
                          EK60_Datagram,
                          get_timestamp))
        .def_property("datagram_type",
                      &EK60_Datagram::get_datagram_type,
                      &EK60_Datagram::set_datagram_type,
                      DOC(themachinethatgoesping,
                          echosounders,
                          simrad,
                          datagrams,
                          EK60_Datagram,
                          get_datagram_type))

        

        // --- raw data access ---
        .def_readwrite(
            "_raw_Length",
            &EK60_Datagram::_Length,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK60_Datagram, Length))
        .def_readwrite("_raw_DatagramType",
                       &EK60_Datagram::_DatagramType,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           EK60_Datagram,
                           DatagramType))
        .def_readwrite("_raw_LowDateTime",
                       &EK60_Datagram::_LowDateTime,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           EK60_Datagram,
                           LowDateTime))
        .def_readwrite("_raw_HighDateTime",
                       &EK60_Datagram::_HighDateTime,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           EK60_Datagram,
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
             &EK60_Datagram::operator==,
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 EK60_Datagram,
                 operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        //default copy functions 
        __PYCLASS_DEFAULT_COPY__(EK60_Datagram)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(EK60_Datagram)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(EK60_Datagram)
        // end LinearInterpolator
        ;
}
