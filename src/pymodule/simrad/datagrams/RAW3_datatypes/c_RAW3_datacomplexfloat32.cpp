// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/stl.h>

// xtensor python includes
#include <xtensor-python/pyarray.hpp>                  // Numpy bindings
#include <xtensor-python/xtensor_type_caster_base.hpp> // implicit conversion xtensor <-> numpy

#include <themachinethatgoesping/tools/pybind11_helpers/classhelpers.hpp>

#include "../../../../themachinethatgoesping/echosounders/simrad/datagrams/RAW3_datatypes/RAW3_datatypes.hpp"
#include "../../../docstrings.hpp"
#include "module.hpp"

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
#define DOC_RAW3_DataComplexFloat32(NAME)                                                          \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        simrad,                                                                                    \
        datagrams,                                                                                 \
        RAW3_datatypes,                                                                            \
        RAW3_DataComplexFloat32,                                                                   \
        NAME)

void init_c_raw3_datacomplexfloat32(pybind11::module& m)
{
    py::class_<RAW3_DataComplexFloat32, i_RAW3_Data>(m,
                                                     "RAW3_DataComplexFloat32",
                                                     DOC(themachinethatgoesping,
                                                         echosounders,
                                                         simrad,
                                                         datagrams,
                                                         RAW3_datatypes,
                                                         RAW3_DataComplexFloat32))
        .def(py::init<>(), DOC_RAW3_DataComplexFloat32(RAW3_DataComplexFloat32))
        .def(py::init<xt::xtensor<ek60_float, 3>>(),
             DOC_RAW3_DataComplexFloat32(RAW3_DataComplexFloat32_2),
             py::arg("complex_samples"))
        .def("__eq__", &RAW3_DataComplexFloat32::operator==, py::arg("other"))

        .def("get_power",
             &RAW3_DataComplexFloat32::get_power,
             DOC_RAW3_DataComplexFloat32(get_power))
        .def("get_angle",
             &RAW3_DataComplexFloat32::get_angle,
             DOC_RAW3_DataComplexFloat32(get_angle))

        // ----- properties -----
        .def_readwrite("complex_samples",
                       &RAW3_DataComplexFloat32::_complex_samples,
                       DOC_RAW3_DataComplexFloat32(complex_samples))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(RAW3_DataComplexFloat32)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(RAW3_DataComplexFloat32)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(RAW3_DataComplexFloat32)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}