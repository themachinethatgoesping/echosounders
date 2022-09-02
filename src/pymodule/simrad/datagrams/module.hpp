// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0
#pragma once

#include <pybind11/pybind11.h>
namespace themachinethatgoesping {
namespace echosounders {
namespace pymodule {
namespace py_simrad {
namespace py_datagrams {

// -- initialize module --
void init_m_simrad_datagrams(pybind11::module& m);

}
}
}
}
}