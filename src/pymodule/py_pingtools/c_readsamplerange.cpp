// SPDX-FileCopyrightText: 2022 - 2023 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/iostream.h>
#include <pybind11/pytypes.h>
#include <pybind11/stl.h>

#include "../../themachinethatgoesping/echosounders/pingtools/readsamplerange.hpp"
#include <themachinethatgoesping/tools_pybind/classhelper.hpp>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_pingtools {

namespace py = pybind11;
using namespace themachinethatgoesping::echosounders::pingtools;

#define DOC_ReadSampleRange(arg)                                                                   \
    DOC(themachinethatgoesping, echosounders, pingtools, ReadSampleRange, arg)

void init_c_readsamplerange(pybind11::module& m)
{
    py::class_<ReadSampleRange>(
        m, "ReadSampleRange", DOC(themachinethatgoesping, echosounders, pingtools, ReadSampleRange))
        .def(py::init<uint16_t, uint16_t, uint16_t, uint16_t>(),
             DOC_ReadSampleRange(ReadSampleRange),
             py::arg("first_sample_to_read"),
             py::arg("number_of_samples_to_read"),
             py::arg("first_read_sample_offset"),
             py::arg("last_read_sample_offset"))

        // --- data access ---
        .def("get_first_sample_to_read",
             &ReadSampleRange::get_first_sample_to_read,
             DOC_ReadSampleRange(get_first_sample_to_read))
        .def("get_number_of_samples_to_read",
             &ReadSampleRange::get_number_of_samples_to_read,
             DOC_ReadSampleRange(get_number_of_samples_to_read))
        .def("get_first_read_sample_offset",
             &ReadSampleRange::get_first_read_sample_offset,
             DOC_ReadSampleRange(get_first_read_sample_offset))
        .def("get_last_read_sample_offset",
             &ReadSampleRange::get_last_read_sample_offset,
             DOC_ReadSampleRange(get_last_read_sample_offset))

        // ----- operators -----
        .def("__eq__",
             &ReadSampleRange::operator==,
             DOC_ReadSampleRange(operator_eq),
             py::arg("other"))

        // ----- pybind macros -----
        // default copy functions
        __PYCLASS_DEFAULT_COPY__(ReadSampleRange)
        // default binary functions
        __PYCLASS_DEFAULT_BINARY__(ReadSampleRange)
        // default printing functions
        __PYCLASS_DEFAULT_PRINTING__(ReadSampleRange);
}

}
}
}
}