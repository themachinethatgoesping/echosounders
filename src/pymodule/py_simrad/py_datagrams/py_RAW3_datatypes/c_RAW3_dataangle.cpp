// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
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
#define DOC_RAW3_DataAngle(NAME)                                                                   \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        simrad,                                                                                    \
        datagrams,                                                                                 \
        RAW3_datatypes,                                                                            \
        RAW3_DataAngle,                                                                            \
        NAME)

void init_c_raw3_dataangle(pybind11::module& m)
{
    py::class_<RAW3_DataAngle, i_RAW3_Data>(m,
                                            "RAW3_DataAngle",
                                            DOC(themachinethatgoesping,
                                                echosounders,
                                                simrad,
                                                datagrams,
                                                RAW3_datatypes,
                                                RAW3_DataAngle))
        .def(py::init<>(), DOC_RAW3_DataAngle(RAW3_DataAngle))
        .def(py::init<xt::xtensor<uint8_t, 2>>(),
             DOC_RAW3_DataAngle(RAW3_DataAngle_2),
             py::arg("angle"))
        .def("__eq__", &RAW3_DataAngle::operator==, py::arg("other"))

        .def("get_angle", &RAW3_DataAngle::get_angle, DOC_RAW3_DataAngle(get_angle))

        // ----- properties -----
        .def_readwrite("angle", &RAW3_DataAngle::_angle, DOC_RAW3_DataAngle(angle))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(RAW3_DataAngle)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(RAW3_DataAngle)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(RAW3_DataAngle)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}