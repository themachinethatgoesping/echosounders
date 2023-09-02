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

#include "module.hpp"
#include <themachinethatgoesping/echosounders/simrad/datagrams/raw3datatypes/raw3datatypes.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_datagrams {
namespace py_raw3_datatypes {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::simrad;
using namespace datagrams::raw3datatypes;

// --- helper defines ---
#define DOC_RAW3DataSkipped(NAME)                                                                  \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        simrad,                                                                                    \
        datagrams,                                                                                 \
        raw3datatypes,                                                                             \
        RAW3DataSkipped,                                                                           \
        NAME)

void init_c_raw3dataskipped(pybind11::module& m)
{
    py::class_<RAW3DataSkipped, i_RAW3Data>(m,
                                            "RAW3DataSkipped",
                                            DOC(themachinethatgoesping,
                                                echosounders,
                                                simrad,
                                                datagrams,
                                                raw3datatypes,
                                                RAW3DataSkipped))
        .def(py::init<>(), DOC_RAW3DataSkipped(RAW3DataSkipped))
        .def("__eq__", &RAW3DataSkipped::operator==, py::arg("other"))

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