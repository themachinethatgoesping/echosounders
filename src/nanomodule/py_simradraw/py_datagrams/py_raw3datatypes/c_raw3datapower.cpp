// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

// xtensor python includes
#include <themachinethatgoesping/tools_nanobind/pytensor_nanobind.hpp> // Numpy bindings

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>

#include "module.hpp"
#include <themachinethatgoesping/echosounders/simradraw/datagrams/raw3datatypes/raw3datatypes.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simradraw {
namespace py_datagrams {
namespace py_raw3_datatypes {

namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::simradraw;
using namespace datagrams::raw3datatypes;

// --- helper defines ---
#define DOC_RAW3DataPower(NAME)                                                                    \
    DOC(themachinethatgoesping, echosounders, simradraw, datagrams, raw3datatypes, RAW3DataPower, NAME)

void init_c_raw3datapower(nanobind::module_& m)
{
    nb::class_<RAW3DataPower, i_RAW3Data>(
        m,
        "RAW3DataPower",
        DOC(themachinethatgoesping, echosounders, simradraw, datagrams, raw3datatypes, RAW3DataPower))
        .def(nb::init<>(), DOC_RAW3DataPower(RAW3DataPower))
        .def(nb::init<xt::xtensor<simradraw_short, 1>>(),
             DOC_RAW3DataPower(RAW3DataPower_2),
             nb::arg("power_and_angle"))
        .def("__eq__", &RAW3DataPower::operator==, nb::arg("other"))

        .def("get_power",
             &RAW3DataPower::get_power,
             DOC_RAW3DataPower(get_power),
             nb::arg("dB") = false)

        // ----- properties -----
        .def_rw("power", &RAW3DataPower::_power, DOC_RAW3DataPower(power))

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