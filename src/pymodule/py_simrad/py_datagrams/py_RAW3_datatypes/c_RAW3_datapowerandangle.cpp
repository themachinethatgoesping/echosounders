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

#include <themachinethatgoesping/echosounders/simrad/datagrams/RAW3_datatypes/RAW3_datatypes.hpp>
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
#define DOC_RAW3_DataPowerAndAngle(NAME)                                                           \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        simrad,                                                                                    \
        datagrams,                                                                                 \
        RAW3_datatypes,                                                                            \
        RAW3_DataPowerAndAngle,                                                                    \
        NAME)

void init_c_raw3_datapowerandangle(pybind11::module& m)
{
    py::class_<RAW3_DataPowerAndAngle, i_RAW3_Data>(m,
                                                    "RAW3_DataPowerAndAngle",
                                                    DOC(themachinethatgoesping,
                                                        echosounders,
                                                        simrad,
                                                        datagrams,
                                                        RAW3_datatypes,
                                                        RAW3_DataPowerAndAngle))
        .def(py::init<>(), DOC_RAW3_DataPowerAndAngle(RAW3_DataPowerAndAngle))
        .def(py::init<xt::xtensor<simrad_short, 1>, xt::xtensor<uint8_t, 2>>(),
             DOC_RAW3_DataPowerAndAngle(RAW3_DataPowerAndAngle_2),
             py::arg("power"),
             py::arg("angle"))
        .def("__eq__", &RAW3_DataPowerAndAngle::operator==, py::arg("other"))

        .def("get_power",
             &RAW3_DataPowerAndAngle::get_power,
             DOC_RAW3_DataPowerAndAngle(get_power),
             py::arg("dB") = false)
        .def("get_angle", &RAW3_DataPowerAndAngle::get_angle, DOC_RAW3_DataPowerAndAngle(get_angle))

        // ----- properties -----
        .def_readwrite("power", &RAW3_DataPowerAndAngle::_power, DOC_RAW3_DataPowerAndAngle(power))
        .def_readwrite("angle", &RAW3_DataPowerAndAngle::_angle, DOC_RAW3_DataPowerAndAngle(angle))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(RAW3_DataPowerAndAngle)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(RAW3_DataPowerAndAngle)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(RAW3_DataPowerAndAngle)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}