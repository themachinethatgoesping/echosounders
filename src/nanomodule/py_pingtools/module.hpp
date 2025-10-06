// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
#pragma once

#include <nanobind/nanobind.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {

namespace py_pingtools {

// -- initialize module --
void init_m_pingtools(nanobind::module_& m);

}
}
}
}