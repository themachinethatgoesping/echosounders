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
#define DOC_RAW3_DataSkipped(NAME)                                                                 \
    DOC(themachinethatgoesping,                                                                    \
        echosounders,                                                                              \
        simrad,                                                                                    \
        datagrams,                                                                                 \
        RAW3_datatypes,                                                                            \
        RAW3_DataSkipped,                                                                          \
        NAME)

void init_c_raw3_dataskipped(pybind11::module& m)
{
    py::class_<RAW3_DataSkipped, i_RAW3_Data>(m,
                                              "RAW3_DataSkipped",
                                              DOC(themachinethatgoesping,
                                                  echosounders,
                                                  simrad,
                                                  datagrams,
                                                  RAW3_datatypes,
                                                  RAW3_DataSkipped))
        .def(py::init<>(), DOC_RAW3_DataSkipped(RAW3_DataSkipped))
        .def("__eq__", &RAW3_DataSkipped::operator==, py::arg("other"))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(RAW3_DataSkipped)
        // default binary functions
        // __PYCLASS_DEFAULT_BINARY__(RAW3_DataSkipped)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(RAW3_DataSkipped)
        // end LinearInterpolator
        ;
}
}
}
}
}
}
}