// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
#pragma once

#include <pybind11/pybind11.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {

namespace py_simradraw {

// -- initialize module --
void init_m_simradraw(pybind11::module& m);

}
}
}
}