// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/complex.h>
#include <pybind11/iostream.h>
#include <pybind11/stl.h>
//#define FORCE_IMPORT_ARRAY
#include <xtensor-python/pyarray.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // Numpy bindings

#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>

#include "../../../themachinethatgoesping/echosounders/simrad/datagrams/FIL1.hpp"
#include "../../docstrings.hpp"
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

void init_c_FIL1(pybind11::module& m)
{

    py::class_<FIL1, datagrams::SimradDatagram>(
        m, "FIL1", DOC(themachinethatgoesping, echosounders, simrad, datagrams, FIL1))
        .def(py::init<>(), DOC(themachinethatgoesping, echosounders, simrad, datagrams, FIL1, FIL1))
        // --- convenient data access ---
        .def_property("stage",
                      &FIL1::get_stage,
                      &FIL1::set_stage,
                      DOC(themachinethatgoesping, echosounders, simrad, datagrams, FIL1, Stage))
        .def_property("channel_id",
                      &FIL1::get_channel_id,
                      &FIL1::set_channel_id,
                      DOC(themachinethatgoesping, echosounders, simrad, datagrams, FIL1, ChannelID))
        .def_property(
            "no_of_coefficients",
            &FIL1::get_no_of_coefficients,
            &FIL1::set_no_of_coefficients,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, FIL1, NoOfCoefficients))
        .def_property(
            "decimation_factor",
            &FIL1::get_decimation_factor,
            &FIL1::set_decimation_factor,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, FIL1, DecimationFactor))
        .def_property(
            "coefficients",
            &FIL1::get_coefficients,
            &FIL1::set_coefficients,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, FIL1, Coefficients))

        // --- raw data access ---
        .def_readwrite("_raw_Stage",
                       &FIL1::_Stage,
                       DOC(themachinethatgoesping, echosounders, simrad, datagrams, FIL1, Stage))
        .def_readwrite("_raw_Spare_1",
                       &FIL1::_Spare_1,
                       DOC(themachinethatgoesping, echosounders, simrad, datagrams, FIL1, Spare_1))
        .def_readwrite("_raw_Spare_2",
                       &FIL1::_Spare_2,
                       DOC(themachinethatgoesping, echosounders, simrad, datagrams, FIL1, Spare_2))
        .def_readwrite(
            "_raw_ChannelID",
            &FIL1::_ChannelID,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, FIL1, ChannelID))
        .def_readwrite(
            "_raw_NoOfCoefficients",
            &FIL1::_NoOfCoefficients,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, FIL1, NoOfCoefficients))
        .def_readwrite(
            "_raw_DecimationFactor",
            &FIL1::_DecimationFactor,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, FIL1, DecimationFactor))
        .def_readwrite(
            "_raw_Coefficients",
            &FIL1::_Coefficients,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, FIL1, Coefficients))

        // ----- operators -----
        .def("__eq__",
             &FIL1::operator==,
             DOC(themachinethatgoesping, echosounders, simrad, datagrams, FIL1, operator_eq),
             py::arg("other"))
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