// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/eigen.h>
#include <pybind11/iostream.h>
#include <pybind11/stl.h>

// xtensor python includes
#include <xtensor-python/pyarray.hpp>                  // Numpy bindings
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
#define DOC_RAW3DataComplexFloat32(NAME)                                                           \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        simradraw,                                                                                 \
        datagrams,                                                                                 \
        raw3datatypes,                                                                             \
        RAW3DataComplexFloat32,                                                                    \
        NAME)

void init_c_raw3datacomplexfloat32(pybind11::module& m)
{
    py::class_<RAW3DataComplexFloat32, i_RAW3Data>(m,
                                                   "RAW3DataComplexFloat32",
                                                   DOC(themachinethatgoesping,
                                                       echosounders,
                                                       simradraw,
                                                       datagrams,
                                                       raw3datatypes,
                                                       RAW3DataComplexFloat32))
        .def(py::init<>(), DOC_RAW3DataComplexFloat32(RAW3DataComplexFloat32))
        .def(py::init<xt::xtensor<simradraw_float, 3>>(),
             DOC_RAW3DataComplexFloat32(RAW3DataComplexFloat32_2),
             py::arg("complex_samples"))
        .def("__eq__", &RAW3DataComplexFloat32::operator==, py::arg("other"))

        .def("get_power",
             &RAW3DataComplexFloat32::get_power,
             DOC_RAW3DataComplexFloat32(get_power),
             py::arg("dB") = false)
        .def("get_angle", &RAW3DataComplexFloat32::get_angle, DOC_RAW3DataComplexFloat32(get_angle))

        .def("get_power1",
             &RAW3DataComplexFloat32::get_power1,
             DOC_RAW3DataComplexFloat32(get_power1),
             py::arg("dB") = false)

        // ----- properties -----
        .def_readwrite("complex_samples",
                       &RAW3DataComplexFloat32::_complex_samples,
                       DOC_RAW3DataComplexFloat32(complex_samples))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(RAW3DataComplexFloat32)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(RAW3DataComplexFloat32)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(RAW3DataComplexFloat32)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}