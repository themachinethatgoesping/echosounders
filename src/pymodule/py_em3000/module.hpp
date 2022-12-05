// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
#pragma once

#include <pybind11/pybind11.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {

namespace py_em3000 {

// -- initialize module --
void init_m_em3000(pybind11::module& m);

}
}
}
}