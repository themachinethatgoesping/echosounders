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
namespace py_raw3_datatypes {

// -- initialize module --
void init_m_RAW3_datatypes(pybind11::module& m);

}
}
}
}
}
}