// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
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
#define DOC_RAW3DataAngle(NAME)                                                                    \
    DOC(themachinethatgoesping, echosounders, simradraw, datagrams, raw3datatypes, RAW3DataAngle, NAME)

void init_c_raw3dataangle(pybind11::module& m)
{
    py::class_<RAW3DataAngle, i_RAW3Data>(
        m,
        "RAW3DataAngle",
        DOC(themachinethatgoesping, echosounders, simradraw, datagrams, raw3datatypes, RAW3DataAngle))
        .def(py::init<>(), DOC_RAW3DataAngle(RAW3DataAngle))
        .def(py::init<xt::xtensor<uint8_t, 2>>(),
             DOC_RAW3DataAngle(RAW3DataAngle_2),
             py::arg("angle"))
        .def("__eq__", &RAW3DataAngle::operator==, py::arg("other"))

        .def("get_angle", &RAW3DataAngle::get_angle, DOC_RAW3DataAngle(get_angle))

        // ----- properties -----
        .def_readwrite("angle", &RAW3DataAngle::_angle, DOC_RAW3DataAngle(angle))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(RAW3DataAngle)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(RAW3DataAngle)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(RAW3DataAngle)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}