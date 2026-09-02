// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <themachinethatgoesping/tools_nanobind/classhelper.hpp>
#include <themachinethatgoesping/tools_nanobind/datetime.hpp>

#include <themachinethatgoesping/echosounders/s7k/datagrams/absorptionloss.hpp>

#include "module.hpp"

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_s7k {
namespace py_datagrams {
namespace nb = nanobind;
using namespace themachinethatgoesping::echosounders::s7k;
using namespace themachinethatgoesping::echosounders::s7k::datagrams;

#define DOC_C(CLASS, ARG) DOC(themachinethatgoesping, echosounders, s7k, datagrams, CLASS, ARG)

void init_c_absorptionloss(nb::module_& m)
{
    nb::class_<AbsorptionLoss, S7KDatagram>(m, "AbsorptionLoss", DOC(themachinethatgoesping, echosounders, s7k, datagrams, AbsorptionLoss))
        .def(nb::init<>(), DOC_C(AbsorptionLoss, AbsorptionLoss))
        .def("get_absorption_loss", &AbsorptionLoss::get_absorption_loss, DOC_C(AbsorptionLoss, get_absorption_loss))
        .def("set_absorption_loss", &AbsorptionLoss::set_absorption_loss, DOC_C(AbsorptionLoss, set_absorption_loss), nb::arg("val"))
        .def("__eq__", &AbsorptionLoss::operator==, nb::arg("other"))
        __PYCLASS_DEFAULT_COPY__(AbsorptionLoss)
        __PYCLASS_DEFAULT_BINARY__(AbsorptionLoss)
        __PYCLASS_DEFAULT_PRINTING__(AbsorptionLoss);
}

} // namespace py_datagrams
} // namespace py_s7k
} // namespace pymodule
} // namespace echosounders
} // namespace themachinethatgoesping
