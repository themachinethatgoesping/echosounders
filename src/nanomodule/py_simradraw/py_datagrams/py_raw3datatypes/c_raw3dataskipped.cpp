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
#define DOC_RAW3DataSkipped(NAME)                                                                  \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        simradraw,                                                                                    \
        datagrams,                                                                                 \
        raw3datatypes,                                                                             \
        RAW3DataSkipped,                                                                           \
        NAME)

void init_c_raw3dataskipped(nanobind::module_& m)
{
    nb::class_<RAW3DataSkipped, i_RAW3Data>(m,
                                            "RAW3DataSkipped",
                                            DOC(themachinethatgoesping,
                                                echosounders,
                                                simradraw,
                                                datagrams,
                                                raw3datatypes,
                                                RAW3DataSkipped))
        .def(nb::init<>(), DOC_RAW3DataSkipped(RAW3DataSkipped))
        .def("__eq__", &RAW3DataSkipped::operator==, nb::arg("other"))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(RAW3DataSkipped)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(RAW3DataSkipped)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(RAW3DataSkipped)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}