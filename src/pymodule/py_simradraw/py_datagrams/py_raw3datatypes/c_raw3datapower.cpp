// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

// xtensor python includes
#include <xtensor-python/pytensor.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // implicit conversion xtensor <-> numpy

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "module.hpp"
#include <themachinethatgoesping/echosounders/simradraw/datagrams/raw3datatypes/raw3datatypes.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_datagrams {
namespace py_raw3_datatypes {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simradraw;
using namespace datagrams::raw3datatypes;

// --- helper defines ---
#define DOC_RAW3DataPower(NAME)                                                                    \
    DOC(themachinethatgoesping, echosounders, simradraw, datagrams, raw3datatypes, RAW3DataPower, NAME)

void init_c_raw3datapower(pybind11::module& m)
{
    py::classh<RAW3DataPower, i_RAW3Data>(
        m,
        "RAW3DataPower",
        DOC(themachinethatgoesping, echosounders, simradraw, datagrams, raw3datatypes, RAW3DataPower))
        .def(py::init<>(), DOC_RAW3DataPower(RAW3DataPower))
        .def(py::init<xt::xtensor<simradraw_short, 1>>(),
             DOC_RAW3DataPower(RAW3DataPower_2),
             py::arg("power_and_angle"))
        .def("__eq__", &RAW3DataPower::operator==, py::arg("other"))

        .def("get_power",
             &RAW3DataPower::get_power,
             DOC_RAW3DataPower(get_power),
             py::arg("dB") = false)

        // ----- properties -----
        .def_readwrite("power", &RAW3DataPower::_power, DOC_RAW3DataPower(power))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(RAW3DataPower)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(RAW3DataPower)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(RAW3DataPower)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}