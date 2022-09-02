// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>

#include "../../../themachinethatgoesping/echosounders/simrad/datagrams/ek80_MRU0.hpp"
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
using datagrams::EK80_MRU0;

void init_c_ek80_MRU0(pybind11::module& m)
{
        py::class_<EK80_MRU0, datagrams::EK60_Datagram>(
        m,
        "EK80_MRU0",
        DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK80_MRU0))
        .def(py::init<>(),
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 EK80_MRU0,
                 EK80_MRU0))
        // --- convenient data access ---
        
        // --- raw data access ---
        .def_readwrite(
            "_raw_Heave",
            &EK80_MRU0::_Heave,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK80_MRU0, Heave))
        .def_readwrite(
            "_raw_Roll",
            &EK80_MRU0::_Roll,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK80_MRU0, Roll))
        .def_readwrite(
            "_raw_Pitch",
            &EK80_MRU0::_Pitch,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK80_MRU0, Pitch))
        .def_readwrite(
            "_raw_Heading",
            &EK80_MRU0::_Heading,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK80_MRU0, Heading))
        
        // ----- operators -----
        .def("__eq__",
             &EK80_MRU0::operator==,
             DOC(themachinethatgoesping,
                 echosounders,
                 simrad,
                 datagrams,
                 EK80_MRU0,
                 operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        //default copy functions 
        __PYCLASS_DEFAULT_COPY__(EK80_MRU0)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(EK80_MRU0)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(EK80_MRU0)
        // end LinearInterpolator
        ;
}
}
}
}
}
}