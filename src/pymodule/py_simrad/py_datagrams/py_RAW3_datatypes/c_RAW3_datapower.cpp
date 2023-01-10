// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

// xtensor python includes
#include <xtensor-python/pyarray.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // implicit conversion xtensor <-> numpy

#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "../../../docstrings.hpp"
#include "module.hpp"
#include <themachinethatgoesping/echosounders/simrad/datagrams/RAW3_datatypes/RAW3_datatypes.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_datagrams {
namespace py_raw3_datatypes {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simrad;
using namespace datagrams::RAW3_datatypes;

// --- helper defines ---
#define DOC_RAW3_DataPower(NAME)                                                                   \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        simrad,                                                                                    \
        datagrams,                                                                                 \
        RAW3_datatypes,                                                                            \
        RAW3_DataPower,                                                                            \
        NAME)

void init_c_raw3_datapower(pybind11::module& m)
{
    py::class_<RAW3_DataPower, i_RAW3_Data>(m,
                                            "RAW3_DataPower",
                                            DOC(themachinethatgoesping,
                                                echosounders,
                                                simrad,
                                                datagrams,
                                                RAW3_datatypes,
                                                RAW3_DataPower))
        .def(py::init<>(), DOC_RAW3_DataPower(RAW3_DataPower))
        .def(py::init<xt::xtensor<simrad_short, 1>>(),
             DOC_RAW3_DataPower(RAW3_DataPower_2),
             py::arg("power_and_angle"))
        .def("__eq__", &RAW3_DataPower::operator==, py::arg("other"))

        .def("get_power",
             &RAW3_DataPower::get_power,
             DOC_RAW3_DataPower(get_power),
             py::arg("dB") = false)

        // ----- properties -----
        .def_readwrite("power", &RAW3_DataPower::_power, DOC_RAW3_DataPower(power))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(RAW3_DataPower)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(RAW3_DataPower)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(RAW3_DataPower)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}