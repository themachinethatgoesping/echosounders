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
#define DOC_RAW3DataPowerAndAngle(NAME)                                                            \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        simradraw,                                                                                    \
        datagrams,                                                                                 \
        raw3datatypes,                                                                             \
        RAW3DataPowerAndAngle,                                                                     \
        NAME)

void init_c_raw3datapowerandangle(pybind11::module& m)
{
    py::classh<RAW3DataPowerAndAngle, i_RAW3Data>(m,
                                                  "RAW3DataPowerAndAngle",
                                                  DOC(themachinethatgoesping,
                                                      echosounders,
                                                      simradraw,
                                                      datagrams,
                                                      raw3datatypes,
                                                      RAW3DataPowerAndAngle))
        .def(py::init<>(), DOC_RAW3DataPowerAndAngle(RAW3DataPowerAndAngle))
        .def(py::init<xt::xtensor<simradraw_short, 1>, xt::xtensor<uint8_t, 2>>(),
             DOC_RAW3DataPowerAndAngle(RAW3DataPowerAndAngle_2),
             py::arg("power"),
             py::arg("angle"))
        .def("__eq__", &RAW3DataPowerAndAngle::operator==, py::arg("other"))

        .def("get_power",
             &RAW3DataPowerAndAngle::get_power,
             DOC_RAW3DataPowerAndAngle(get_power),
             py::arg("dB") = false)
        .def("get_angle", &RAW3DataPowerAndAngle::get_angle, DOC_RAW3DataPowerAndAngle(get_angle))

        // ----- properties -----
        .def_readwrite("power", &RAW3DataPowerAndAngle::_power, DOC_RAW3DataPowerAndAngle(power))
        .def_readwrite("angle", &RAW3DataPowerAndAngle::_angle, DOC_RAW3DataPowerAndAngle(angle))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(RAW3DataPowerAndAngle)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(RAW3DataPowerAndAngle)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(RAW3DataPowerAndAngle)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}