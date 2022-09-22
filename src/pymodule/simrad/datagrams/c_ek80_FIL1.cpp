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

#include "../../../themachinethatgoesping/echosounders/simrad/datagrams/ek80_FIL1.hpp"
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
using datagrams::EK80_FIL1;

void init_c_ek80_FIL1(pybind11::module& m)
{

    py::class_<EK80_FIL1, datagrams::EK60_Datagram>(
        m, "EK80_FIL1", DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK80_FIL1))
        .def(py::init<>(),
             DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK80_FIL1, EK80_FIL1))
        // --- convenient data access ---
        .def_property(
            "stage",
            &EK80_FIL1::get_stage,
            &EK80_FIL1::set_stage,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK80_FIL1, Stage))
        .def_property(
            "channel_id",
            &EK80_FIL1::get_channel_id,
            &EK80_FIL1::set_channel_id,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK80_FIL1, ChannelID))
        .def_property("no_of_coefficients",
                      &EK80_FIL1::get_no_of_coefficients,
                      &EK80_FIL1::set_no_of_coefficients,
                      DOC(themachinethatgoesping,
                          echosounders,
                          simrad,
                          datagrams,
                          EK80_FIL1,
                          NoOfCoefficients))
        .def_property("decimation_factor",
                      &EK80_FIL1::get_decimation_factor,
                      &EK80_FIL1::set_decimation_factor,
                      DOC(themachinethatgoesping,
                          echosounders,
                          simrad,
                          datagrams,
                          EK80_FIL1,
                          DecimationFactor))
        .def_property(
            "coefficients",
            &EK80_FIL1::get_coefficients,
            &EK80_FIL1::set_coefficients,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK80_FIL1, Coefficients))

        // --- raw data access ---
        .def_readwrite(
            "_raw_Stage",
            &EK80_FIL1::_Stage,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK80_FIL1, Stage))
        .def_readwrite(
            "_raw_Spare_1",
            &EK80_FIL1::_Spare_1,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK80_FIL1, Spare_1))
        .def_readwrite(
            "_raw_Spare_2",
            &EK80_FIL1::_Spare_2,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK80_FIL1, Spare_2))
        .def_readwrite(
            "_raw_ChannelID",
            &EK80_FIL1::_ChannelID,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK80_FIL1, ChannelID))
        .def_readwrite("_raw_NoOfCoefficients",
                       &EK80_FIL1::_NoOfCoefficients,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           EK80_FIL1,
                           NoOfCoefficients))
        .def_readwrite("_raw_DecimationFactor",
                       &EK80_FIL1::_DecimationFactor,
                       DOC(themachinethatgoesping,
                           echosounders,
                           simrad,
                           datagrams,
                           EK80_FIL1,
                           DecimationFactor))
        .def_readwrite(
            "_raw_Coefficients",
            &EK80_FIL1::_Coefficients,
            DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK80_FIL1, Coefficients))

        // ----- operators -----
        .def("__eq__",
             &EK80_FIL1::operator==,
             DOC(themachinethatgoesping, echosounders, simrad, datagrams, EK80_FIL1, operator_eq),
             py::arg("other"))
        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(EK80_FIL1)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(EK80_FIL1)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(EK80_FIL1)
        // end LinearInterpolator
        ;
}
}
}
}
}
}