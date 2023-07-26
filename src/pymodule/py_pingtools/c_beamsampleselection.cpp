// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/pytypes.h>
#include <pybind11/stl.h>

#include "../../themachinethatgoesping/echosounders/pingtools/beamsampleselection.hpp"
#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_pingtools {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::pingtools;

#define DOC_BeamSampleSelection(arg)                                                                \
    DOC(themachinethatgoesping, echosounders, pingtools, BeamSampleSelection, arg)

void init_c_beamsampleselection(pybind11::module& m)
{
    py::class_<BeamSampleSelection>(
        m,
        "BeamSampleSelection",
        DOC(themachinethatgoesping, echosounders, pingtools, BeamSampleSelection))
        .def(py::init<>(), DOC_BeamSampleSelection(BeamSampleSelection))

        // --- convenient data access ---
        
        // ----- operators -----
        .def("__eq__",
             &BeamSampleSelection::operator==,
             DOC_BeamSampleSelection(operator_eq),
             py::arg("other"))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(BeamSampleSelection)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(BeamSampleSelection)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(BeamSampleSelection);
}

}
}
}
}