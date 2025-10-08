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
#define DOC_RAW3DataPowerAndAngle(NAME)                                                            \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        simradraw,                                                                                    \
        datagrams,                                                                                 \
        raw3datatypes,                                                                             \
        RAW3DataPowerAndAngle,                                                                     \
        NAME)

void init_c_raw3datapowerandangle(nanobind::module_& m)
{
    nb::class_<RAW3DataPowerAndAngle, i_RAW3Data>(m,
                                                  "RAW3DataPowerAndAngle",
                                                  DOC(themachinethatgoesping,
                                                      echosounders,
                                                      simradraw,
                                                      datagrams,
                                                      raw3datatypes,
                                                      RAW3DataPowerAndAngle))
        .def(nb::init<>(), DOC_RAW3DataPowerAndAngle(RAW3DataPowerAndAngle))
        .def(nb::init<xt::xtensor<simradraw_short, 1>, xt::xtensor<uint8_t, 2>>(),
             DOC_RAW3DataPowerAndAngle(RAW3DataPowerAndAngle_2),
             nb::arg("power"),
             nb::arg("angle"))
        .def("__eq__", &RAW3DataPowerAndAngle::operator==, nb::arg("other"))

        .def("get_power",
             &RAW3DataPowerAndAngle::get_power,
             DOC_RAW3DataPowerAndAngle(get_power),
             nb::arg("dB") = false)
        .def("get_angle", &RAW3DataPowerAndAngle::get_angle, DOC_RAW3DataPowerAndAngle(get_angle))

        // ----- properties -----
        .def_rw("power", &RAW3DataPowerAndAngle::_power, DOC_RAW3DataPowerAndAngle(power))
        .def_rw("angle", &RAW3DataPowerAndAngle::_angle, DOC_RAW3DataPowerAndAngle(angle))

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