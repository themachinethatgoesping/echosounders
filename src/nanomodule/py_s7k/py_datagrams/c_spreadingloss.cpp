// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/datetime.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams/spreadingloss.hpp>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_datagrams {
namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::s7k;
using namespace themachinethatgoesping::echosounders::s7k::datagrams;

#define DOC_C(CLASS, ...) DOC(themachinethatgoesping, echosounders, s7k, datagrams, CLASS, __VA_ARGS__)

void init_c_spreadingloss(nb::module_& m)
{
    nb::class_<SpreadingLoss, S7KDatagram>(m, "SpreadingLoss", DOC(themachinethatgoesping, echosounders, s7k, datagrams, SpreadingLoss))
        .def(nb::init<>(), DOC_C(SpreadingLoss, SpreadingLoss))
        .def("get_spreading_loss", &SpreadingLoss::get_spreading_loss, DOC_C(SpreadingLoss, Content, spreading_loss))
        .def("set_spreading_loss", &SpreadingLoss::set_spreading_loss, DOC_C(SpreadingLoss, Content, spreading_loss), nb::arg("val"))
        .def("__eq__", &SpreadingLoss::operator==, nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(SpreadingLoss)
        __PYCLASS_DEFAULT_BINARY__(SpreadingLoss)
        __PYCLASS_DEFAULT_PRINTING__(SpreadingLoss);
}

} // namespace py_datagrams
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
