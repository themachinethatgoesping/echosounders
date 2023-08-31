// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0



#include <pybind11/complex.h>
#include <pybind11/iostream.h>
#include <pybind11/stl.h>
#include <xtensor-python/pyarray.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../themachinethatgoesping/echosounders/simrad/datagrams/FIL1.hpp"

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_datagrams {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simrad;
using datagrams::FIL1;
using datagrams::SimradDatagram;

#define DOC_FIL1(arg) DOC(themachinethatgoesping, echosounders, simrad, datagrams, FIL1, arg)

void init_c_FIL1(pybind11::module& m)
{

    py::class_<FIL1, datagrams::SimradDatagram>(
        m, "FIL1", DOC(themachinethatgoesping, echosounders, simrad, datagrams, FIL1))
        .def(py::init<>(), DOC_FIL1(FIL1))

        // --- convenient data access ---
        .def("get_stage", &FIL1::get_stage, DOC_FIL1(stage))
        .def("set_stage", &FIL1::set_stage, DOC_FIL1(stage))
        .def("get_channel_id", &FIL1::get_channel_id, DOC_FIL1(channel_id))
        .def("set_channel_id", &FIL1::set_channel_id, DOC_FIL1(channel_id))
        .def("get_no_of_coefficients", &FIL1::get_no_of_coefficients, DOC_FIL1(no_of_coefficients))
        .def("set_no_of_coefficients", &FIL1::set_no_of_coefficients, DOC_FIL1(no_of_coefficients))
        .def("get_decimation_factor", &FIL1::get_decimation_factor, DOC_FIL1(decimation_factor))
        .def("set_decimation_factor", &FIL1::set_decimation_factor, DOC_FIL1(decimation_factor))
        .def("get_coefficients", &FIL1::get_coefficients, DOC_FIL1(coefficients))
        .def("set_coefficients", &FIL1::set_coefficients, DOC_FIL1(coefficients))

        // ----- operators -----
        .def("__eq__", &FIL1::operator==, DOC_FIL1(operator_eq), py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(FIL1)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(FIL1)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(FIL1)
        // end LinearInterpolator
        ;
}
}
}
}
}
}